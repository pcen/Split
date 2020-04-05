#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

int main(int argc, char* argv[])
{
	Split::Root* root = Split::Root::get_root();
	root->run(argc, argv);
	delete root;
	return 0;
}

#endif /* ENTRYPOINT_H */
