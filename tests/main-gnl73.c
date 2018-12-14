#include <string.h>
#include <stdio.h>
#include "get_next_line.h"

/*
** 4 lines via STDIN with 8 chars without Line Feed
*/

int				main(int argc, char **argv)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	int			errors;

	count_lines = 0;
	errors = 0;
	line = NULL;
	argc = 2;
		fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (count_lines == 0 && strcmp(line, "1234567") != 0)
			errors++;
		if (count_lines == 1 && strcmp(line, "abcdefg") != 0)
			errors++;
		if (count_lines == 2 && strcmp(line, "4567890") != 0)
			errors++;
		if (count_lines == 3 && strcmp(line, "defghijk") != 0)
			errors++;
		printf("%s\n",line);
		count_lines++;
		if (count_lines > 50)
			break ;
	}
	if (count_lines != 4)
		printf("-> must have returned '1' four times instead of %d time(s)\n", count_lines);
	if (errors > 0)
		printf("-> must have read \"1234567\", \"abcdefg\", \"4567890\" and \"defghijk\"\n");
	if (count_lines == 4 && errors == 0)
		printf("OK\n");
	return (0);
}
