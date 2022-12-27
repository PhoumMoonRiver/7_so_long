/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:24:35 by njerasea          #+#    #+#             */
/*   Updated: 2022/12/27 15:58:20 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_env1(t_kn *that, t_env *env, char **map)
{
	t_kn	this;

	this.j = 0;
	while (map[that->i][this.j] != '\n' && map[that->i][this.j] != '\0')
	{
		if (map[that->i][this.j] == 'P')
			env->p++;
		else if (map[that->i][this.j] == 'E')
			env->e++;
		else if (map[that->i][this.j] == 'C')
			env->c++;
		if (map[that->i][this.j] != '0' && map[that->i][this.j] != '1'
				&& map[that->i][this.j] != 'P' && map[that->i][this.j] != 'E'
				&& map[that->i][this.j] != 'C')
		{
			ft_putstr("Error : The map must contain E, C, P, 1, 0\n");
			ft_free2d(map);
			exit(0);
		}
		this.j++;
	}
}

void	check_env(char **map)
{
	t_env	env;
	t_kn	this;

	env.p = 0;
	env.e = 0;
	env.c = 0;
	this.i = 0;
	while (map[this.i])
	{
		check_env1(&this, &env, map);
		this.i++;
	}
	if (env.p != 1 || env.e != 1 || env.c <= 0)
	{
		ft_putstr("Error : The map must contain 1 E, least 1 C, 1 P\n");
		ft_free2d(map);
		exit(0);
	}
}
