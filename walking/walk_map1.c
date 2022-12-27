/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_map1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:05:58 by njerasea          #+#    #+#             */
/*   Updated: 2022/12/27 15:59:10 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_printwalk(t_mlx *pim)
{
	ft_putstr("Walk Steps => ");
	ft_printint(pim->cw);
	write(1, "\n", 1);
}

void	check_walk_map_c0(t_mlx *pim, int npr, int npc)
{
	if (pim->map[npr][npc] == 'C' || pim->map[npr][npc] == '0')
	{
		if (pim->map[npr][npc] == 'C')
			pim->cc--;
		pim->map[npr][npc] = 'P';
		mlx_put_image_to_window(pim->mlx, pim->mlx_win,
			pim->back, pim->pc * 64, pim->pr * 64);
		if (pim->map[pim->pr][pim->pc] != 'E')
			pim->map[pim->pr][pim->pc] = '0';
		else
			mlx_put_image_to_window(pim->mlx, pim->mlx_win,
				pim->exit, pim->pc * 64, pim->pr * 64);
		mlx_put_image_to_window(pim->mlx, pim->mlx_win,
			pim->back, npc * 64, npr * 64);
		mlx_put_image_to_window(pim->mlx, pim->mlx_win,
			pim->player, npc * 64, npr * 64);
		pim->cw++;
		ft_printwalk(pim);
		pim->pr = npr;
		pim->pc = npc;
	}
}

void	check_walk_map_e(t_mlx *pim, int npr, int npc)
{
	if (pim->map[npr][npc] == 'E')
	{
		if (pim->cc == 0)
		{
			ft_free2d(pim->map);
			exit(0);
		}
		else
		{
			mlx_put_image_to_window(pim->mlx, pim->mlx_win,
				pim->back, npc * 64, npr * 64);
			mlx_put_image_to_window(pim->mlx, pim->mlx_win,
				pim->player, npc * 64, npr * 64);
			mlx_put_image_to_window(pim->mlx, pim->mlx_win,
				pim->back, pim->pc * 64, pim->pr * 64);
			pim->map[pim->pr][pim->pc] = '0';
			pim->cw++;
			ft_printwalk(pim);
			pim->pr = npr;
			pim->pc = npc;
		}
	}
}

void	check_walk_map(t_mlx *pim, int npr, int npc)
{
	if (pim->map[npr][npc] == '1')
		return ;
	check_walk_map_c0(pim, npr, npc);
	check_walk_map_e(pim, npr, npc);
}
