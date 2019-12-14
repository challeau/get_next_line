/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mlt_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:30:47 by challeau          #+#    #+#             */
/*   Updated: 2019/12/02 13:13:55 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

int main(int ac, char **av)
{
	(void)ac;
	int i = 0;
	int j = 0;
	int ret = 1;
	int ret1 = 1;
	int fd = open(av[1], O_RDONLY);
	int fd1 = open(av[2], O_RDONLY);
	char *line;

	while (ret != 0 && ret1 != 0)
	{
		if (ret > 0)
		{
			ret = get_next_line(fd, &line);
			if (ret != 0)
				printf("[%d][FILE 1][LINE %d]: %s\n", ret, i, line);
			else
				printf("[0][FILE 1][FINISHED]\n");
			i++;
			if (ret == -1)
			{
				printf("[-1][FILE 1][ERROR]\n");
				return (0);
			}
			free (line);
		}
		if (ret1 > 0)
		{
			ret1 = get_next_line(fd1, &line);
			if (ret1 != 0)
				printf("[%d][FILE 2][LINE %d]: %s\n", ret1, j, line);
			else
				printf("[0][FILE 2][FINISHED]\n");
			j++;
			if (ret1 == -1)
			{
				printf("[-1][FILE 2][ERROR]\n");
				return (0);
			}
			free (line);
		}
	}
	close(fd);
	close(fd1);
	return (0);
}
