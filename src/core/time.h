#pragma once

namespace Split
{
	class Time
	{
	public:
		static double now(void);
		static double nowMilli(void);
		static double nowMicro(void);
		static double nowNano(void);
	};

	class Timer
	{
	public:
		void start(void);
		void stop(void);

		double duration;

	private:
		double startTime;
	};

	class DeltaTime
	{
	public:
		DeltaTime();

		operator double();
		void update(void);

	private:
		unsigned long now, last;
		double dt;
	};

}
