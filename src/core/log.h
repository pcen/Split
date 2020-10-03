#pragma once

#define log_trace(...)    Split::Log::get()->trace(__VA_ARGS__)
#define log_debug(...)    Split::Log::get()->debug(__VA_ARGS__)
#define log_info(...)     Split::Log::get()->info(__VA_ARGS__)
#define log_warn(...)     Split::Log::get()->warn(__VA_ARGS__)
#define log_error(...)    Split::Log::get()->error(__VA_ARGS__)
#define log_critical(...) Split::Log::get()->critical(__VA_ARGS__)

typedef std::shared_ptr<spdlog::logger> log_ptr;
using LogLevel = spdlog::level::level_enum;

namespace Split
{

	class Log
	{
	public:
		static void init(void);

		void set_level(LogLevel level);
		static log_ptr& get(void);

	private:
		static log_ptr m_log;
	};

}
