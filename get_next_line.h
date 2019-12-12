/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 02:48:27 by challeau          #+#    #+#             */
/*   Updated: 2019/12/12 04:12:04 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# define TRUE 1
# define FALSE 0

typedef struct	s_var
{
	int		sz_rd;
	int		nl_pos;
	char	*str;
	char	*buff;
	char	*rest;
}				t_var;

int				get_next_line(int fd, char **line);
int				ft_strlen(const char *str);
void			ft_memdel(void **ptr);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strdup(const char *s);
#endif
