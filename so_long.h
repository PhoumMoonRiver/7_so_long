/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:59:26 by njerasea          #+#    #+#             */
/*   Updated: 2023/02/02 15:44:49 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 512

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <limits.h>
# include "mlx/mlx.h"
# include <stdio.h>

typedef struct t_characters
{
	int	p;
	int	e;
	int	c;
}	t_env;

typedef struct t_keepnum
{
	int	row;
	int	column;
	int	fd;
	int	i;
	int	j;
	int	df;
	int	countc;
	int	kc;
	int	maxcol;
	int	e;
	int	rw;
}	t_kn;

typedef struct t_minilibx
{
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*wall;
	void	*exit;
	void	*player;
	void	*cor;
	void	*back;
	int		wid;
	int		row;
	int		col;
	int		hei;
	int		pr;
	int		pc;
	int		cc;
	int		i;
	int		j;
	int		cw;
}	t_mlx;

/*v This is so_long v*/
/*libft*/
void	ft_putstr(char *str);
void	ft_free2d(char **str);
void	ft_printint(int num);
int		ft_strcmp(char *s1, char *s2);

/*solong*/
void	check_fileber(int ac, char **av);
void	ft_checkber(char **av);
void	check_map(char **av);
void	check_rectang(char **map);
void	check_wall(char **map);
void	check_env(char **map);
void	check_path(char **map, int row);
void	ft_floodfill(char **map, t_kn *loc, int r, int c);
void	make_map(char **av);
void	ft_put_img(t_mlx *pim, int row);
void	ft_put_imgmap(t_mlx *pim);
void	ft_findp2(t_mlx *that);
void	check_walk_map(t_mlx *pim, int npr, int npc);
void	add_img(t_mlx *pim);
char	**get_map(int row, char **av);
int		close_na(t_mlx *pim);
int		map_row(int fd);
int		key_hook(int key_code, t_mlx *pim);
int		ft_countc(char **map);

/*v This is get_next_line v*/
void	*ft_calloc(size_t count, size_t size);
void	ft_printint(int num);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_readtojoid(int fd, char *keep);
char	*ft_strchr(char *s, int c);
char	*ft_keepline(char *keep, int lenline);
char	*ft_cutline(char *keep, int lenline);
char	*ft_strdup(char *s1, int len);
int		ft_strlen_mo(char *str, char exp);

/*v This is ft_debug v*/
void	deprint(char *str);
void	deprint2d(char **str);

#endif
