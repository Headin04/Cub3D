#include "Cub3d.h"

bool	check_must(char *str)
{
	int fd;

	fd = open(str, O_RDWR);
	if (fd == -1)
		return (perror("Fail to open the file: "));
}