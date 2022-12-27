/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:39:12 by phnamway          #+#    #+#             */
/*   Updated: 2022/12/27 15:58:58 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_na(t_mlx *pim)
{
	mlx_destroy_window(pim->mlx, pim->mlx_win);
	ft_free2d(pim->map);
	exit(0);
	return (0);
}

void	initenv(t_mlx *pim)
{
	pim->wall = NULL;
	pim->exit = NULL;
	pim->player = NULL;
	pim->cor = NULL;
	pim->back = NULL;
}

void	ft_put_img(t_mlx *pim, int row)
{
	pim->col = ft_strlen_mo(pim->map[1], '\n') * 64;
	pim->row = row * 64;
	pim->cw = 0;
	ft_findp2(pim);
	pim->cc = ft_countc(pim->map);
	initenv(pim);
	pim->mlx = mlx_init();
	pim->mlx_win = mlx_new_window(pim->mlx, pim->col, pim->row, "so_long");
	add_img(pim);
	ft_put_imgmap(pim);
	mlx_key_hook(pim->mlx_win, key_hook, pim);
	mlx_hook(pim->mlx_win, 17, 1L << 0, close_na, pim);
	mlx_loop(pim->mlx);
}

int	key_hook(int key_code, t_mlx *pim)
{
	int	npr;
	int	npc;

	npr = pim->pr;
	npc = pim->pc;
	if (key_code == 13 || key_code == 126)
		npr -= 1;
	else if (key_code == 1 || key_code == 125)
		npr += 1;
	else if (key_code == 0 || key_code == 123)
		npc -= 1;
	else if (key_code == 2 || key_code == 124)
		npc += 1;
	else if (key_code == 53)
	{
		ft_free2d(pim->map);
		exit(0);
	}
	check_walk_map(pim, npr, npc);
	return (0);
}

void	make_map(char **av)
{
	int		fd;
	int		row;
	t_mlx	pim;

	pim.mlx = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error : Map can't open\n");
		exit(0);
	}
	row = map_row(fd);
	pim.map = get_map(row, av);
	ft_put_img(&pim, row);
	ft_free2d(pim.map);
	close(fd);
}
