
#include "parse.h"

int main(int argc, char **argv)

{
	t_cube cube;

	if (argc == 2)
	{
		int fd = error_menu(argv, argc);
		get_file(fd, &cube);
	}
}
