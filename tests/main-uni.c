/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 09:04:05 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/11 16:23:11 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#define WHITE "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define BLUE "\x1B[34m"
#define YELLOW "\x1B[33m"

void	test01(void)
{
	int fd, fd2, fd3;
	int n;
	char *line;
	int file_size;

	/**************************************************************************/
	/*                                                                        */
	/*                           TEST_01_BIG_LINE                             */
	/*                                                                        */
	/**************************************************************************/
	system("mkdir -p tests");
	system("base64 < /dev/urandom | head -c 1000000 | tr -d '\n' | tr -d '\r'  > tests/01_test.txt");

	fd = open("tests/01_test.txt", O_RDONLY);
	fd2 = open("tests/01_test.txt.my", O_CREAT | O_RDWR | O_TRUNC, 0755);
	n = 0;
	while (get_next_line(fd, &line) == 1)
	{
		write(fd2, line, strlen(line));
		free(line);
		n++;
	}
	close(fd);
	close(fd2);

	system("diff tests/01_test.txt tests/01_test.txt.my > tests/01_test.txt.diff");
	fd3 = open("tests/01_test.txt.diff", O_RDONLY);
	file_size = read(fd3, NULL, 10);
	close (fd3);

	if (file_size == 0 && n == 1)
		printf("TEST_01_BIG_LINE" GREEN " [OK]\n" WHITE);
	else
	{
		if (n != 1)
		{
			printf("TEST_01_BIG_LINE" RED " [KO]\n" WHITE);
			printf(RED "Yours n - <%d>, ours - <%d>\n" WHITE, n, 1);
		}
		else
			printf("TEST_01_BIG_LINE" RED " DIFFS KO :(\n" WHITE);
	}
}

void	test02(void)
{
	int fd, fd2, fd3;
	int n;
	char *line;
	int file_size;

	/**************************************************************************/
	/*                                                                        */
	/*                           TEST_02_BIG_LINE                             */
	/*                                                                        */
	/**************************************************************************/

	system("mkdir -p tests");
	system("echo '\n\n'  > tests/02_test.txt");

	fd = open("tests/02_test.txt", O_RDONLY);
	fd2 = open("tests/02_test.txt.my", O_CREAT | O_RDWR | O_TRUNC, 0755);
	n = 0;
	while (get_next_line(fd, &line) == 1)
	{
		write(fd2, line, strlen(line));
		free(line);
		write(fd2, "\n", 1);
		n++;
	}
	close(fd);
	close(fd2);

	system("diff tests/02_test.txt tests/02_test.txt.my > tests/02_test.txt.diff");
	fd3 = open("tests/02_test.txt.diff", O_RDONLY);
	file_size = read(fd3, NULL, 10);
	close (fd3);

	if (file_size == 0 && n == 3)
		printf("TEST_02_LINE_BREAK" GREEN " [OK]\n" WHITE);
	else
	{
		if (n != 3)
		{
			printf("TEST_02_LINE_BREAK" RED " [KO]\n" WHITE);
			printf(RED "Yours n - <%d>, ours - <%d>\n" WHITE, n, 3);
		}
		else
			printf("TEST_02_LINE_BREAK" RED " DIFFS KO :(\n" WHITE);
	}
}

void	test03(void)
{
	int fd, fd2, fd3;
	int n;
	char *line;
	int file_size;

	/**************************************************************************/
	/*                                                                        */
	/*                         TEST_03_EMPTY_LINE                             */
	/*                                                                        */
	/**************************************************************************/

	system("mkdir -p tests");
	system(" > tests/03_test.txt");

	fd = open("tests/03_test.txt", O_RDONLY);
	fd2 = open("tests/03_test.txt.my", O_CREAT | O_RDWR | O_TRUNC, 0755);
	n = 0;
	while (get_next_line(fd, &line) == 1)
	{
		write(fd2, line, strlen(line));
		write(fd2, "\n", 1);
		n++;
	}
	close(fd);
	close(fd2);

	system("diff tests/03_test.txt tests/03_test.txt.my > tests/03_test.txt.diff");
	fd3 = open("tests/03_test.txt.diff", O_RDONLY);
	file_size = read(fd3, NULL, 10);
	close (fd3);

	if (file_size == 0 && n == 0)
		printf("TEST_03_EMPTY_FILE" GREEN " [OK]\n" WHITE);
	else
	{
		if (n != 0)
		{
			printf("TEST_03_EMPTY_FILE" RED " [KO]\n" WHITE);
			printf(RED "Yours n - <%d>, ours - <%d>\n" WHITE, n, 0);
		}
		else
			printf("TEST_03_EMPTY_FILE" RED " DIFFS KO :(\n" WHITE);
	}
}

void	test04(void)
{
	int fd, fd2, fd3;
	int n;
	char *line;
	int file_size;

	/**************************************************************************/
	/*                                                                        */
	/*                           TEST_04_ONE_LINE                             */
	/*                                                                        */
	/**************************************************************************/

	system("mkdir -p tests");
	system("echo 'Tests by rgalyeon! Have a nice day :)'  > tests/04_test.txt");

	fd = open("tests/04_test.txt", O_RDONLY);
	fd2 = open("tests/04_test.txt.my", O_CREAT | O_RDWR | O_TRUNC, 0755);
	n = 0;
	while (get_next_line(fd, &line) == 1)
	{
		write(fd2, line, strlen(line));
		free(line);
		write(fd2, "\n", 1);
		n++;
	}
	close(fd);
	close(fd2);

	system("diff tests/04_test.txt tests/04_test.txt.my > tests/04_test.txt.diff");
	fd3 = open("tests/04_test.txt.diff", O_RDONLY);
	file_size = read(fd3, NULL, 10);
	close (fd3);

	if (file_size == 0 && n == 1)
		printf("TEST_04_ONE_LINE" GREEN " [OK]\n" WHITE);
	else
	{
		if (n != 1)
		{
			printf("TEST_04_ONE_LINE" RED " [KO]\n" WHITE);
			printf(RED "Yours n - <%d>, ours - <%d>\n" WHITE, n, 1);
		}
		else
			printf("TEST_04_ONE_LINE" RED " DIFFS KO :(\n" WHITE);
	}
}

void	test05(void)
{
	int fd, fd2, fd3;
	int n;
	char *line;
	ssize_t file_size;

	/**************************************************************************/
	/*                                                                        */
	/*                           TEST_05_8_LINES                              */
	/*                                                                        */
	/**************************************************************************/

	system("mkdir -p tests");
	system("echo 'Hi'  > tests/05_test.txt");
	system("echo 'It is second line'  >> tests/05_test.txt");
	system("echo 'It'  >> tests/05_test.txt");
	system("echo 'is'  >> tests/05_test.txt");
	system("echo 'easy'  >> tests/05_test.txt");
	system("echo 'test'  >> tests/05_test.txt");
	system("echo 'for'  >> tests/05_test.txt");
	system("echo 'you :) Good luck!'  >> tests/05_test.txt");

	fd = open("tests/05_test.txt", O_RDONLY);
	fd2 = open("tests/05_test.txt.my", O_CREAT | O_RDWR | O_TRUNC, 0755);
	n = 0;
	while (get_next_line(fd, &line) == 1)
	{
		write(fd2, line, strlen(line));
		free(line);
		write(fd2, "\n", 1);
		n++;
	}
	close(fd);
	close(fd2);

	system("diff tests/05_test.txt tests/05_test.txt.my > tests/05_test.txt.diff");
	fd3 = open("tests/05_test.txt.diff", O_RDONLY);
	file_size = read(fd3, NULL, 10);
	close (fd3);

	if (file_size == 0 && n == 8)
		printf("TEST_05_8_LINES" GREEN " [OK]\n" WHITE);
	else
	{
		if (n != 8)
		{
			printf("TEST_05_8_LINE" RED " [KO]\n" WHITE);
			printf(RED "Yours n - <%d>, ours - <%d>\n" WHITE, n, 8);
		}
		else
			printf("TEST_05_8_LINE" RED " DIFFS [KO] :(\n" WHITE);
	}
}

void	test06(void)
{
	int fd, fd2, fd3;
	int n;
	char *line;
	ssize_t file_size;

	/**************************************************************************/
	/*                                                                        */
	/*                       TEST_06_by_vlegros                               */
	/*                                                                        */
	/**************************************************************************/

	system("mkdir -p tests");
	system("echo ''  > tests/06_test.txt");
	system("echo 'test test' | tr -d '\n'  >> tests/06_test.txt");

	fd = open("tests/06_test.txt", O_RDONLY);
	fd2 = open("tests/06_test.txt.my", O_CREAT | O_RDWR | O_TRUNC, 0755);
	n = 0;
	while (get_next_line(fd, &line) == 1)
	{
		write(fd2, line, strlen(line));
		if (n == 0)
			write(fd2, "\n", 1);
		free(line);
		n++;
	}
	close(fd);
	close(fd2);

	system("diff tests/06_test.txt tests/06_test.txt.my > tests/06_test.txt.diff");
	fd3 = open("tests/06_test.txt.diff", O_RDONLY);
	file_size = read(fd3, NULL, 10);
	close (fd3);

	if (file_size == 0 && n == 2)
		printf("TEST_06_by_vlegros" GREEN " [OK]\n" WHITE);
	else
	{
		if (n != 2)
		{
			printf("TEST_06_by_vlegros" RED " [KO]\n" WHITE);
			printf(RED "Yours n - <%d>, ours - <%d>\n" WHITE, n, 2);
		}
		else
			printf("TEST_06_by_vlegros" RED " DIFFS [KO] :(\n" WHITE);
	}
}


int		main()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
}
