#ifndef ROOT_H
#define ROOT_H

class Root
{
public:
	static void init(int argc, char* argv[]);

private:
	static void create_systems(void);
	static void init_systems(void);
	static void cleanup_systems(void);
};

#endif /* ROOT_H */
