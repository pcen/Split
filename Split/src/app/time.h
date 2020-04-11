#ifndef TIME_H
#define TIME_H

namespace Split
{

	class Timer
	{
	public:
		Timer();
		~Timer();

		void update_deltatime(void);
		double get_deltatime(void);
		double get_time(void);
		double get_elapsed_time(void);
		double to_milliseconds(double time);

	private:
		double m_deltatime;
		double m_last_time;
		double m_birth_time;
	};

}

#endif /* TIME_H */
