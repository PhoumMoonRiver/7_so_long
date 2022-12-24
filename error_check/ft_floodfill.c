/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:47:01 by njerasea          #+#    #+#             */
/*   Updated: 2022/12/18 09:23:52 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void    ft_floodfill(char **map, t_kn *loc, int row, int r, int c)
{
    if (r < 0 || c < 0 || r > row - 1 || c > loc->maxcol - 1)
        return ;
    if (map[r][c] == '1')
        return ;
    else if (map[r][c] == 'C')
        loc->kc++;
    else if (map[r][c] == 'E')
        loc->e = 1;
    map[r][c] = '1';

    ft_floodfill(map, loc, row, r + 1, c);
    ft_floodfill(map, loc, row, r - 1, c);
    ft_floodfill(map, loc, row, r, c + 1);
    ft_floodfill(map, loc, row, r, c - 1);
}
