#ifndef LOG_H
#define LOG_H

#define CORE_LOG                    Split::Log::core_log()
#define APP_LOG                     Split::Log::app_log()

#define core_log_trace(...)         CORE_LOG->trace(__VA_ARGS__)
#define core_log_debug(...)         CORE_LOG->debug(__VA_ARGS__)
#define core_log_info(...)          CORE_LOG->info(__VA_ARGS__)
#define core_log_warn(...)          CORE_LOG->warn(__VA_ARGS__)
#define core_log_error(...)         CORE_LOG->error(__VA_ARGS__)
#define core_log_critical(...)      CORE_LOG->critical(__VA_ARGS__)

#define app_log_trace(...)          APP_LOG->trace(__VA_ARGS__)
#define app_log_debug(...)          APP_LOG->debug(__VA_ARGS__)
#define app_log_info(...)           APP_LOG->info(__VA_ARGS__)
#define app_log_warn(...)           APP_LOG->warn(__VA_ARGS__)
#define app_log_error(...)          APP_LOG->error(__VA_ARGS__)
#define app_log_critical(...)       APP_LOG->critical(__VA_ARGS__)

constexpr auto LOG_LEVEL_TRACE = 0;
constexpr auto LOG_LEVEL_DEBUG = 1;
constexpr auto LOG_LEVEL_INFO = 2;
constexpr auto LOG_LEVEL_WARN = 3;
constexpr auto LOG_LEVEL_ERROR = 4;
constexpr auto LOG_LEVEL_CRITICAL = 5;
constexpr auto LOG_LEVEL_OFF = 6;

typedef std::shared_ptr<spdlog::logger> log_ptr;
typedef spdlog::level::level_enum       LOG_LEVEL;

namespace Split
{

	class Log
	{
	public:
		static void init(void);

		void set_core_log_level(LOG_LEVEL level);
		void set_app_log_level(LOG_LEVEL level);

		static log_ptr& core_log(void);
		static log_ptr& app_log(void);

	private:
		static log_ptr m_core_log;
		static log_ptr m_app_log;
	};

}

#endif /* LOG_H */
