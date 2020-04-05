#ifndef APPLICATION_H
#define APPLICATION_H

namespace Split
{

	class Application
	{
	public:
		Application();
		virtual ~Application();

		virtual bool running(void);
		virtual void init(void);
		virtual void launch(void);
		virtual void run(void);
	private:
		bool m_running;
	};

	/* client returns application
	 */
	Application* create_application(void);

}

#endif /* APPLICATION_H */
