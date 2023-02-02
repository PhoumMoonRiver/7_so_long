/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:24:32 by njerasea          #+#    #+#             */
/*   Updated: 2023/02/02 16:36:15 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_rectang(char **map)
{
	t_kn	this;

	this.i = ft_strlen_mo(map[0], '\n');
	if (this.i == 0)
	{
		ft_putstr("Error : The map must not empty\n");
		ft_free2d(map);
		exit(0);
	}
	this.df = 1;
	while (map[this.df] != NULL)
	{
		this.j = ft_strlen_mo(map[this.df], '\n');
		if (this.i != this.j)
		{
			ft_putstr("Error : The map must be rectangular\n");
			ft_free2d(map);
			exit(0);
		}
		this.df++;
	}
}

void	check_wall_fl(t_kn *that, char **map)
{
	that->j = 0;
	while (map[that->i][that->j] != '\n'
			&& map[that->i][that->j] != '\0')
	{
		if (map[that->i][that->j] != '1')
		{
			ft_putstr("Error : The map must be surrounded by wall\n");
			ft_free2d(map);
			exit(0);
		}
		that->j++;
	}
}

void	check_wall_between(t_kn *that, char **map)
{
	that->j = 0;
	while (map[that->i][that->j] != '\n')
	{
		if (map[that->i][0] != '1' || map[that->i][that->column] != '1')
		{
			ft_putstr("Error : The map must be surrounded by wall\n");
			ft_free2d(map);
			exit(0);
		}
		that->j++;
	}
}

void	check_wall(char **map)
{
	t_kn	this;

	this.i = 0;
	this.column = ft_strlen_mo(map[0], '\n') - 1;
	while (map[this.i])
	{
		if (this.i == 0 || map[this.i + 1] == NULL)
			check_wall_fl(&this, map);
		else
			check_wall_between(&this, map);
		this.i++;
	}
}
