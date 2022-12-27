/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:39:26 by phnamway          #+#    #+#             */
/*   Updated: 2022/12/27 15:59:01 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	add_img(t_mlx *pim)
{
	pim->wall = mlx_xpm_file_to_image(pim->mlx,
			"img/1.xpm", &pim->wid, &pim->hei);
	pim->exit = mlx_xpm_file_to_image(pim->mlx,
			"img/E.xpm", &pim->wid, &pim->hei);
	pim->player = mlx_xpm_file_to_image(pim->mlx,
			"img/P.xpm", &pim->wid, &pim->hei);
	pim->cor = mlx_xpm_file_to_image(pim->mlx,
			"img/C.xpm", &pim->wid, &pim->hei);
	pim->back = mlx_xpm_file_to_image(pim->mlx,
			"img/0.xpm", &pim->wid, &pim->hei);
}

void	ft_put_imgmap(t_mlx *pim)
{
	pim->i = 0;
	while (pim->map[pim->i])
	{
		pim->j = 0;
		while (pim->map[pim->i][pim->j] && pim->map[pim->i][pim->j] != '\n')
		{
			mlx_put_image_to_window(pim->mlx, pim->mlx_win,
				pim->back, pim->j * 64, pim->i * 64);
			if (pim->map[pim->i][pim->j] == '1')
				mlx_put_image_to_window(pim->mlx, pim->mlx_win,
					pim->wall, pim->j * 64, pim->i * 64);
			else if (pim->map[pim->i][pim->j] == 'E')
				mlx_put_image_to_window(pim->mlx, pim->mlx_win,
					pim->exit, pim->j * 64, pim->i * 64);
			else if (pim->map[pim->i][pim->j] == 'P')
				mlx_put_image_to_window(pim->mlx, pim->mlx_win,
					pim->player, pim->j * 64, pim->i * 64);
			else if (pim->map[pim->i][pim->j] == 'C')
				mlx_put_image_to_window(pim->mlx, pim->mlx_win,
					pim->cor, pim->j * 64, pim->i * 64);
			pim->j++;
		}
		pim->i++;
	}
}

void	ft_findp2(t_mlx *that)
{
	that->pr = 0;
	while (that->map[that->pr])
	{
		that->pc = 0;
		while (that->map[that->pr][that->pc] != '\n'
			&& that->map[that->pr][that->pc])
		{
			if (that->map[that->pr][that->pc] == 'P')
				return ;
			that->pc++;
		}
		that->pr++;
	}
}
