/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srafe <srafe@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:22:03 by srafe             #+#    #+#             */
/*   Updated: 2018/12/13 17:02:05 by srafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int			fd;
	int			fd2;
	char		*line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		printf("%d\n",fd);
		while (get_next_line(fd, &line) == 1)
		{
			printf("%s\n",line);
			free(line);
		}
		close(fd);
	}

	if (argc == 3)
	{
		// fd = open(argv[1], O_RDONLY);
		// fd2 = open(argv[2], O_RDONLY);
		// printf("%d\n",fd);
		// while (get_next_line(fd, &line) == 1)
		// {
		// 	printf("%s\n",line);
		// 	free(line);
		// }
		// printf("%d\n",fd2);
		// while (get_next_line(fd2, &line) == 1)
		// {
		// 	printf("%s\n",line);
		// 	free(line);
		// }
		// close(fd);
		// close(fd2);
		int i, j;
		i = j = 1;
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		while (i == 1 && j == 1)
		{
			i = get_next_line(fd, &line);
			printf("%s\n",line);
			free(line);

			j = get_next_line(fd2, &line);
			printf("%s\n",line);
			free(line);
		}
		close(fd);
		close(fd2);
	}


	return (0);
}
