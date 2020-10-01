#pragma once

#define LOG_HANDLE        Split::Log::get()

#define log_trace(...)    LOG_HANDLE->trace(__VA_ARGS__)
#define log_debug(...)    LOG_HANDLE->debug(__VA_ARGS__)
#define log_info(...)     LOG_HANDLE->info(__VA_ARGS__)
#define log_warn(...)     LOG_HANDLE->warn(__VA_ARGS__)
#define log_error(...)    LOG_HANDLE->error(__VA_ARGS__)
#define log_critical(...) LOG_HANDLE->critical(__VA_ARGS__)

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
