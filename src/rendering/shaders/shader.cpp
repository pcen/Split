#include "pch.h"
#include "shader.h"
#include "utils/utils.h"
#include "core/log.h"

#include "glad/glad.h"


namespace Split
{

	Shader::Shader(std::string vertex_shader, std::string pixel_shader)
		: m_bound{ false }, m_id{ 0 }
	{
		create_program(vertex_shader, pixel_shader);
		populate_uniform_cache();
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_id);
	}

	void Shader::bind(void)
	{
		if (!m_bound) {
			glUseProgram(m_id);
			m_bound = true;
		}
	}

	void Shader::unbind(void)
	{
		if (m_bound) {
			glUseProgram(0);
			m_bound = false;
		}
	}

	unsigned int Shader::get_id(void)
	{
		return m_id;
	}

	bool Shader::is_bound(void)
	{
		return m_bound;
	}

	void Shader::set_uniform4f(const std::string& name, float v0, float v1, float v2, float v3)
	{
		glUniform4f(get_uniform(name), v0, v1, v2, v3);
	}

	void Shader::set_uniform4f(const std::string& name, glm::vec4& value)
	{
		set_uniform4f(name, value.x, value.y, value.z, value.w);
	}

	void Shader::set_uniform1f(const std::string& name, float value)
	{
		glUniform1f(get_uniform(name), value);
	}

	void Shader::set_uniform1i(const std::string& name, int value)
	{
		glUniform1i(get_uniform(name), value);
	}

	void Shader::set_uniform_mat4f(const std::string& name, glm::mat4& matrix)
	{
		glUniformMatrix4fv(get_uniform(name), 1, GL_FALSE, glm::value_ptr(matrix));
	}

	int Shader::get_uniform(const std::string& name)
	{
		if (m_uniforms.count(name))
			return m_uniforms[name];

		log_warn("Uniform \"{0}\" not found", name);
		return -1;
	}

	bool Shader::validate_shader(unsigned int shader)
	{
		int status, log_length;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
		if (status == GL_TRUE)
			return true;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_length);
		std::vector<char> log_message(log_length);
		glGetShaderInfoLog(shader, log_length, &log_length, log_message.data());
		std::string message(log_message.data(), (size_t)log_length - 1);
		log_error("Shader validation failed:\n\t{0}", message);
		return false;
	}

	bool Shader::validate_program(unsigned int program, unsigned int field)
	{
		int status, log_length;
		glGetProgramiv(program, field, &status);
		if (status == GL_TRUE)
			return true;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &log_length);
		std::vector<char> log_message(log_length);
		glGetProgramInfoLog(program, log_length, &log_length, log_message.data());
		std::string message(log_message.data(), (size_t)log_length - 1);
		log_error("Program validation failed:\n\t{0}", message);
		return false;
	}

	unsigned int Shader::compile_shader(const std::string& source, unsigned int kind)
	{
		const char* shader = source.c_str();
		unsigned int shader_id = glCreateShader(kind);
		glShaderSource(shader_id, 1, &shader, 0);
		glCompileShader(shader_id);
		if (validate_shader(shader_id))
			return shader_id;
		else
			return 0;
	}

	bool Shader::create_program(const std::string& vertex, const std::string& pixel)
	{
		bool status = true;
		m_id = glCreateProgram();

		std::string vertex_code = read_file(vertex);
		std::string pixel_code = read_file(pixel);

		unsigned int vertex_id = compile_shader(vertex_code, GL_VERTEX_SHADER);
		unsigned int pixel_id = compile_shader(pixel_code, GL_FRAGMENT_SHADER);
		glAttachShader(m_id, vertex_id);
		glAttachShader(m_id, pixel_id);

		glLinkProgram(m_id);
		if (!validate_program(m_id, GL_LINK_STATUS)) {
			log_error("Shader program link failed");
			status = false;
		}
		glValidateProgram(m_id);
		if (status && !validate_program(m_id, GL_VALIDATE_STATUS)) {
			log_error("Shader program validation failed");
			status = false;
		}

		glDeleteShader(vertex_id);
		glDeleteShader(pixel_id);
		
		return status;
	}

	void Shader::populate_uniform_cache(void)
	{
		std::vector<unsigned int> queries = { GL_NAME_LENGTH, GL_LOCATION };
		std::vector<int> results(queries.size());
		std::vector<char> name;

		int count;
		glGetProgramInterfaceiv(m_id, GL_UNIFORM, GL_ACTIVE_RESOURCES, &count);
		for (int i = 0; i < count; i++) {
			glGetProgramResourceiv(m_id, GL_UNIFORM, i, (GLsizei)queries.size(), &queries[0], (GLsizei)results.size(), NULL, &results[0]);
			name.resize(results[0]);
			glGetProgramResourceName(m_id, GL_UNIFORM, i, (GLsizei)name.size(), 0, (char*)&name[0]);
			std::string uniform_name((char*)&name[0], name.size() - 1);
			m_uniforms[uniform_name] = results[1];
		}
	}

	std::shared_ptr<Shader> create_shader(std::string vertex_shader, std::string pixel_shader)
	{
		return std::shared_ptr<Shader>(new Shader(vertex_shader, pixel_shader));
	}

}
