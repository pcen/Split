#include "pch.h"
#include "log.h"

#define COMPILE_TIME_LOG_LEVEL spdlog::level::info

namespace Split
{

	log_ptr Log::m_core_log;
	log_ptr Log::m_app_log;

	void Log::init(void)
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		m_core_log = spdlog::stdout_color_mt("CORE");
		m_app_log = spdlog::stdout_color_mt("APP");
		m_core_log->set_level(COMPILE_TIME_LOG_LEVEL);
		m_app_log->set_level(COMPILE_TIME_LOG_LEVEL);
	}

	void Log::set_core_log_level(LOG_LEVEL level)
	{
		Log::core_log()->set_level(level);
	}

	void Log::set_app_log_level(LOG_LEVEL level)
	{
		Log::app_log()->set_level(level);
	}

	log_ptr& Log::core_log(void)
	{
		return Log::m_core_log;
	}

	log_ptr& Log::app_log(void)
	{
		return Log::m_app_log;
	}

}
