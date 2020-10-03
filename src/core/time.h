#pragma once

namespace Split
{
	class Timer
	{
	public:
		void start(void);
		void stop(void);

		double duration;

	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> start_point;
	};
}
