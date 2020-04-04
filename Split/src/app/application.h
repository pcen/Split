#ifndef APPLICATION_H
#define APPLICATION_H

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
	bool app_running;
};

#endif /* APPLICATION_H */
