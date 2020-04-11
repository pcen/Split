#include "pch.h"
#include "time.h"
#include "GLFW/glfw3.h"

namespace Split
{

	Timer::Timer()
		: m_last_time{ 0.0 }, m_deltatime{ 0.0 }, m_birth_time{ glfwGetTime() } {}
	
	Timer::~Timer() {}

	void Timer::update_deltatime(void)
	{
		double current_time = glfwGetTime();
		m_deltatime = current_time - m_last_time;
		m_last_time = current_time;
	}

	double Timer::get_deltatime(void)
	{
		return m_deltatime;
	}

	double Timer::get_time(void)
	{
		return glfwGetTime();
	}

	double Timer::get_elapsed_time(void)
	{
		return get_time() - m_birth_time;
	}

	double Timer::to_milliseconds(double time)
	{
		return time * 1000.0;
	}

}
