/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 03:15:59 by challeau          #+#    #+#             */
/*   Updated: 2020/01/16 05:15:22 by challeau         ###   ########.fr       */
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
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_realloc(char *ori, int new_sz)
{
	int		ori_sz;
	char	*new;

	if (!ori)
	{
		if (!(new = (char *)malloc(sizeof(char) * (new_sz + 1))))
			return (NULL);
		while (--new_sz >= 0)
			new[new_sz] = '\0';
	}
	else
	{
		ori_sz = ft_strlen(ori);
		if (!(new = (char *)malloc(sizeof(char) * (ori_sz + new_sz + 1))))
			return (NULL);
		ft_strlcpy(new, ori, ori_sz + 1);
		ft_memdel((void **)ori);
	}
	return (new);
}

static int	ft_time_to_free(int ret, char *buff, char *str, char *rest)
{
	if (buff)
		ft_memdel((void **)buff);
	if (str)
		ft_memdel((void **)str);
	if (rest)
		ft_memdel((void **)rest);
	return (ret);
}

static char	*ft_sep_rest(char *str, char *rest, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	*line = ft_realloc(*line, i + 1);
	ft_strlcpy(*line, str, i + 1);
	if (i < ft_strlen(str))
		tmp = ft_strdup(str + i + 1);
	else
		tmp = ft_realloc(NULL, 1);
	str[i] = '\0';
	ft_memdel((void **)rest);
	return (tmp);
}

int			get_next_line(int fd, char **line)
{
	static t_var	v;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (ft_time_to_free(-1, v.buff, v.str, v.rest));
	*line = ft_strdup("");
	v.buff = ft_realloc(v.buff, BUFFER_SIZE + 1);
	if (!v.rest)
		v.rest = ft_strdup("");
	v.str = ft_strdup(v.rest);
	while (!ft_str_nl(v.str) && (v.sz_rd = read(fd, v.buff, BUFFER_SIZE)) > 0)
	{
		v.buff[v.sz_rd] = '\0';
		v.str = ft_realloc(v.str, BUFFER_SIZE + 1);
		ft_strcat(v.str, v.buff);
	}
	if (v.sz_rd < 0)
		return (ft_time_to_free(-1, v.buff, v.str, v.rest));
	/*if (*v.str)*/if (ft_str_nl(v.str))
	{
		v.rest = ft_sep_rest(v.str, v.rest, line);
		ft_memdel((void **)v.str);
		return (1);
	}
	v.rest = ft_sep_rest(v.str, v.rest, line);
	return (ft_time_to_free(0, v.buff, v.str, v.rest));	
}
