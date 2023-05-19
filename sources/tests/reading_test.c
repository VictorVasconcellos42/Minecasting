
#include "parse.h"

int main(int argc, char **argv)

{
	t_cube cube;
	
	int fd;
	fd = error_menu(argv, argc);
	get_file(fd, &cube);
}
