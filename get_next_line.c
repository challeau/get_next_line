/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 04:06:30 by challeau          #+#    #+#             */
/*   Updated: 2019/12/10 06:34:57 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_str_nl(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

static void	ft_realloc(int fresh, char **ori, int new_sz)
{
	int		ori_sz;
	char	*new;

	if (fresh == true)
	{
		if (!(new = (char *)malloc(sizeof(char) * (new_sz + 1))))
			return ;
		while (--new_sz >= 0)
		{
			new[new_sz] = '\0';
			new_sz--;
		}
	}
	else
	{
		ori_sz = ft_strlen(*ori);
		if (!(new = (char *)malloc(sizeof(char) * (ori_sz + new_sz + 1))))
		{
			ft_memdel((void **)ori);
			return ;
		}
		ft_strlcpy(new, *ori, ori_sz + 1);
		ft_memdel((void **)ori);
	}
	*ori = new;
}

static void	ft_sep_rest(int nl_pos, char **str, char **rest, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	ft_realloc(true, &tmp, ft_strlen(*str) - nl_pos);
	*str += nl_pos;
	printf("hello\n");
	while (*str[i])
	{
		tmp[i] = *str[i];
		i++;
	}
	printf("hello\n");
	tmp[i] = '\0';
	ft_memdel((void **)rest);
	*rest = tmp;
	*str[nl_pos] = '\0';
	*line = ft_strdup(*str);
}

static int	ft_ret(int ret, char **str, char **rest)
{
	ft_memdel((void **)str);
	ft_memdel((void **)rest);
	return (ret);
}

int			get_next_line(int fd, char **line)
{
	static t_var	v;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	ft_realloc(true,  &v.buff, BUFFER_SIZE + 1);
	ft_realloc(true,  line, 1);
	if (!v.str && !v.rest)
		v.rest = ft_strdup("");
	v.str = ft_strdup(v.rest);
	while (((v.nl_pos = ft_str_nl(v.str)) == 0 &&
		(v.sz_rd = read(fd, v.buff, BUFFER_SIZE)) > 0))
	{
		v.buff[v.sz_rd] = '\0';
		ft_realloc(false, &v.str, BUFFER_SIZE);
		ft_strcat(v.str, v.buff);
	}
	if (v.sz_rd < 0)
		return (ft_ret(-1, &v.str, &v.rest));
	ft_sep_rest(v.nl_pos, &v.str, &v.rest, line);
	ft_memdel((void **)&v.buff);
	if (ft_str_nl(v.str) == 0)
		if (v.sz_rd == 0 || (v.sz_rd < BUFFER_SIZE && v.str[0] == '\0'))
			return (ft_ret(0, &v.str, &v.rest));
	return (1);
}
