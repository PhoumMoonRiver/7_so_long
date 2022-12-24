/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:50:23 by njerasea          #+#    #+#             */
/*   Updated: 2022/12/16 20:46:27 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

char    *ft_keepline(char *keep, int lenline)
{
    char    *line;

    if (!keep[lenline])
    {
        free(keep);
        return (NULL);
    }
    if (keep[lenline] == '\n')
		lenline += 1;
    if (ft_strlen_mo(keep, '\0') > lenline)
	    line = ft_strjoin(NULL, keep + lenline);
    else
    {
        free(keep);
        return (NULL);
    }
    free(keep);
	return (line);
}

char    *ft_cutline(char *keep, int lenline)
{
    char    *line;

    if (!keep[0])
        return (NULL);
    if (keep[lenline] == '\n')
        lenline += 1;
    line = ft_strdup(keep, lenline);
    return (line);
}

char    *ft_readtojoid(int fd, char *keep)
{
    char *readres;
    int readnum;

    readres = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!readres)
        return (NULL);
    readnum = 1;
    while (readnum > 0)
    {
        readnum = read(fd, readres, BUFFER_SIZE);
        if (readnum < 0)
        {
            free(readres);
            return (NULL);
        }
        readres[readnum] = '\0';
        keep = ft_strjoin(keep, readres);
        if (ft_strchr(keep, '\n'))
            break;
    }
    free(readres);
    return (keep);
}

char	*get_next_line(int fd)
{
    static char *keep;
    char    *line;
    int lenline;

    if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0 , 0) < 0)
        return (NULL);
    if (!keep)
        keep = ft_calloc(1 , 1);
    keep = ft_readtojoid(fd, keep);
    if (!keep)
        return (NULL);
    lenline = ft_strlen_mo(keep, '\n');
    line = ft_cutline(keep, lenline);
    keep = ft_keepline(keep, lenline);
    return (line);
}