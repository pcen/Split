#include "pch.h"
#include "time.h"

namespace Split
{
	double Time::now(void)
	{
		std::chrono::time_point now = std::chrono::high_resolution_clock::now();
		return std::chrono::time_point_cast<std::chrono::seconds>(now).time_since_epoch().count();
	}

	double Time::nowMilli(void)
	{
		std::chrono::time_point now = std::chrono::high_resolution_clock::now();
		return std::chrono::time_point_cast<std::chrono::milliseconds>(now).time_since_epoch().count();
	}

	double Time::nowMicro(void)
	{
		std::chrono::time_point now = std::chrono::high_resolution_clock::now();
		return std::chrono::time_point_cast<std::chrono::microseconds>(now).time_since_epoch().count();
	}

	double Time::nowNano(void)
	{
		std::chrono::time_point now = std::chrono::high_resolution_clock::now();
		return std::chrono::time_point_cast<std::chrono::nanoseconds>(now).time_since_epoch().count();
	}

	void Timer::start(void)
	{
		startTime = Time::nowMicro();
	}

	void Timer::stop(void)
	{
		duration = (Time::nowMicro() - startTime) * 0.001;
	}

	DeltaTime::DeltaTime()
		: now{ 0 },
		last{ 0 },
		dt{ 0.0 }
	{
	
	}

	DeltaTime::operator double()
	{
		return dt;
	}

	// TODO: use Time class to calcualte delta time
	void DeltaTime::update(void)
	{
		last = now;
		now = (unsigned long)SDL_GetPerformanceCounter();
		dt = (double)((now - last) / (double)SDL_GetPerformanceFrequency());
	}

}
