/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:23:27 by njerasea          #+#    #+#             */
/*   Updated: 2022/12/27 15:58:36 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;
	int		len;

	if (!s2)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen_mo(s1, '\0');
	new = malloc(sizeof(char) * (len + ft_strlen_mo(s2, '\0') + 1));
	if (!new)
		return (NULL);
	while (len--)
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}

char	*ft_strchr(char *s, int c)
{
	char	exp;

	exp = (char)c;
	while (*s && exp != *s)
		s++;
	if (exp == *s)
		return ((char *)s);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	size_t	t;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	t = count * size;
	s = malloc(t);
	if (!s)
		return (NULL);
	while (t--)
		*s = '\0';
	return (s);
}

char	*ft_strdup(char *s1, int len)
{
	char	*dup;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	while (s1[i] && i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
