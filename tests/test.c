/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 03:23:10 by challeau          #+#    #+#             */
/*   Updated: 2019/12/14 01:22:03 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "../get_next_line.h"

void	test_fd(char **buffer, char const *filename, int fd)
{
	int	r = 1;

	if (fd == STDIN_FILENO)
		printf("Reading stdin...\n---\n");
	else
		printf("Reading %s...\n---\n", filename);

	while (r > 0)
	{
		r = get_next_line(fd, buffer);
		printf("%2d-%s\n", r, *buffer);
	}

	if (r >= 0)
		printf("%2d-%s\n---\n", r, *buffer);
	else
		printf("%2d#error\n---\n", r);
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
}

int		main(void)
{
	char		*buffer = NULL;
	int			i, fd;
	int			test_count;
	char const	*tests[100] = {
		"simple",
		"empty",
		"empty_one",
		"multi_in_one",
		"many_lines",
		"over_buffer",
		"63_line",
		"63_line_nl",
		"64_line",
		"64_line_nl",
		"65_line",
		"65_line_nl",
		"baudelaire.txt",
		"large_file.txt",
		"lorem_ipsum",
		//"tests/bible.txt",
		//"tests/war_and_peace.txt",
		//"tests/Mr. Justice Maxell by Edgar Wallace.txt",
		NULL
	};

	test_count = 0;
	while (tests[test_count])
		test_count++;
	printf("**********************\n* BUFFER_SIZE %6d *\n**********************\n", BUFFER_SIZE);
	i = 0;
	while (i < test_count)
	{
		fd = open(tests[i], O_RDONLY);
		test_fd(&buffer, tests[i++], fd);
		close(fd);
	}
	return (0);
}
