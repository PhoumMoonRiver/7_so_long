/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:24:29 by njerasea          #+#    #+#             */
/*   Updated: 2022/12/18 09:32:18 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define BUFFER_SIZE 512

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <limits.h>
# include "mlx/mlx.h"
# include 				<stdio.h>

typedef struct t_characters
{
    int p;
    int e;
    int c;
}	t_env;

typedef struct t_keepnum
{
    int row;
    int column;
    int fd;
    int i;
    int j;
    int df;
    int countc;
    int kc;
    int maxcol;
    int e;
}   t_kn;

/*v This is so_long v*/
/*libft*/
void    ft_putstr(char *str);
void    ft_free2d(char **str);
int	ft_strcmp(char *s1, char *s2);
/*solong*/
void    check_fileber(int   ac, char **av);
void	ft_checkber(char **av);
void    check_map(char **av);
void    check_rectang(char **map);
void    check_wall(char **map); 
void    check_env(char **map);
void    check_path(char **map, int row);
void    ft_floodfill(char **map, t_kn *loc, int row, int r, int c);
char    **get_map(int row, char **av);
int map_row(int fd);

/*v This is get_next_line v*/
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char    *ft_readtojoid(int fd, char *keep);
char	*ft_strchr(char *s, int c);
char    *ft_keepline(char *keep, int lenline);
char    *ft_cutline(char *keep, int lenline);
char	*ft_strdup(char *s1, int len);
int ft_strlen_mo(char *str, char exp);

/*v This is ft_debug v*/
void    deprint(char *str);
void    deprint2d(char **str);

#endif