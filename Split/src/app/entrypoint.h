#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

int main(int argc, char* argv[])
{
	Split::Root::get_root()->run(argc, argv);
	delete Split::Root::get_root();
	return 0;
}

#endif /* ENTRYPOINT_H */
