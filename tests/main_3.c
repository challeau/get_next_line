#include "../2.0/get_next_line.h"

int main(int ac, char **av)
{
	(void)ac;
	char *line;
	int i = 1;
	int ret = 1;
	int fd;

//	while (420)
//	{
		fd = open(av[1], O_RDONLY);
		while(ret > 0)
		{
			ret = get_next_line(fd, &line);
			if (ret >= 0)
			{
				printf("[%d][LINE %d]: %s\n", ret, i, line);
				if (ret == 0)
					printf("[0][DONE]\n");
			}
			else
				printf("[-1][!!! ERROR !!!]\n");
			free(line);
			line = NULL;
			i++;
		}
		close(fd);
//	}
	return (0);
}
