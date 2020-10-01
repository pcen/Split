#include "pch.h"
#include "log.h"

namespace Split
{

	log_ptr Log::m_log;

	void Log::init(void)
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		m_log = spdlog::stdout_color_mt("SPLIT");
		m_log->set_level(LogLevel::info);
	}

	void Log::set_level(LogLevel level)
	{
		Log::get()->set_level(level);
	}

	log_ptr& Log::get(void)
	{
		return Log::m_log;
	}

}
