#include "pch.h"
#include "time.h"

namespace Split
{

	void Timer::start(void)
	{
		start_point = std::chrono::high_resolution_clock::now();
	}

	void Timer::stop(void)
	{
		auto end_point = std::chrono::high_resolution_clock::now();
		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_point).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count();
		duration = (end - start) * 0.001;
	}

}
