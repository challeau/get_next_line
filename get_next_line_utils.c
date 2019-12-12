/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 04:15:43 by challeau          #+#    #+#             */
/*   Updated: 2019/12/12 05:38:31 by challeau         ###   ########.fr       */
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

char	*ft_strdup(const char *src)
{
	int		i;
	char	*new;

	i = 0;
	printf("hello there\n");
	if (!src)
	{
		printf(">>>>>> i enter if\n");
		if (!(new = (char *)malloc(1)))
			return (NULL);
	}
	printf(">>>>>> im about to throw hands\n");
//	else
	if (src)
	{
		printf(">>>>>> i enter else\n");
		if (!(new = (char *)malloc(sizeof(char) * ft_strlen(src) + 1)))
			return (NULL);
		while (src[i])
		{
			printf("i go in here %d\n", i);
			new[i] = src[i];
			i++;
		}
	}
	printf("?????????? i no enter ?????\n");
	new[i] = '\0';
	return (new);
}
