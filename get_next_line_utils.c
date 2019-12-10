/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 04:15:43 by challeau          #+#    #+#             */
/*   Updated: 2019/12/10 05:56:50 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_memdel(void **ptr)
{
	if (ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	ft_realloc(char **ori, int new_sz)
{
	int		ori_sz;
	char	*new;

	if (ori == NULL)
	{
		if (!(new = (char *)malloc(sizeof(char) * (new_sz + 1))))
			return ;
		while (new_sz >= 0)
			new[new_sz] = '\0';
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
	}
	ft_memdel((void **)ori);
	*ori = new;
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int i;

	i = 0;
	if (!src)
		return (0);
	if (size && dst)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strdup(char *s)
{
	int		len;
	char	*dest;

	len = ft_strlen(s);
	if (!(dest = (char*)malloc((len + 1) * sizeof(char))))
		return (0);
	dest[len] = '\0';
	while (len-- > 0)
		dest[len] = s[len];
	return (dest);
}
