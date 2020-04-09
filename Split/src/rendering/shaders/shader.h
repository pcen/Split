#ifndef SHADER_H
#define SHADER_H

namespace Split
{

	class Shader
	{
	public:
		Shader(std::string vertex_shader, std::string pixel_shader);
		~Shader();

		void bind(void);
		void unbind(void);

		void set_uniform4f(const std::string& name, float v0, float v1, float v2, float v3);
		void set_uniform4f(const std::string& name, glm::vec4& value);
		void set_uniform1i(const std::string& name, int value);
		void set_uniform1f(const std::string& name, float value);
		void set_uniform_mat4f(const std::string& name, glm::mat4& matrix);

		unsigned int get_id(void);
		bool is_bound(void);

	private:
		unsigned int m_id;
		bool m_bound;

		int get_uniform(const std::string& name);

		bool create_program(const std::string& vertex, const std::string& pixel);
		unsigned int compile_shader(const std::string& source, unsigned int kind);
		
		void populate_uniform_cache(void);
		std::unordered_map<std::string, int> m_uniforms;

		bool validate_shader(unsigned int shader);
		bool validate_program(unsigned int program, unsigned int field);
	};

}


#endif /* SHADER_H */
