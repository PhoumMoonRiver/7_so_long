/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:24:43 by njerasea          #+#    #+#             */
/*   Updated: 2022/12/27 15:58:26 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_floodfill(char **map, t_kn *loc, int r, int c)
{
	if (r < 0 || c < 0 || r > loc->rw - 1 || c > loc->maxcol - 1)
		return ;
	if (map[r][c] == '1')
		return ;
	else if (map[r][c] == 'C')
		loc->kc++;
	else if (map[r][c] == 'E')
		loc->e = 1;
	map[r][c] = '1';
	ft_floodfill(map, loc, r + 1, c);
	ft_floodfill(map, loc, r - 1, c);
	ft_floodfill(map, loc, r, c + 1);
	ft_floodfill(map, loc, r, c - 1);
}
