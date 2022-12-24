/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:28:02 by njerasea          #+#    #+#             */
/*   Updated: 2022/12/18 09:29:26 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void    ft_findp(char **map, t_kn *that)
{
    that->row = 0;

    while (map[that->row])
    {
        that->column = 0;
        while (map[that->row][that->column] != '\n' && map[that->row][that->column])
        {
            if (map[that->row][that->column] == 'P')
                return ;
            that->column++;
        }
        that->row++;
    }
}
 
int ft_countc(char **map)
{
    int i;
    int j;
    int c;

    i = 0;
    c = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j] && map[i][j] != '\n')
        {
            if (map[i][j] == 'C')
                c++;
            j++;
        }
        i++;
    }
    return(c);
}

void    check_path(char **map, int row)
{
    t_kn    this;

    this.kc = 0;
    ft_findp(map, &this);
    this.countc = ft_countc(map) - 1;
    this.maxcol = ft_strlen_mo(map[0], '\n');
    ft_floodfill(map, &this, row, this.row, this.column);
    this.kc--;
    if (this.kc != this.countc || this.e != 1)
    {
        ft_putstr("Error : The map is invalid\n");
        ft_free2d(map);
        exit(0);
    }
}