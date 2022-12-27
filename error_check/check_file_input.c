/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:24:21 by njerasea          #+#    #+#             */
/*   Updated: 2022/12/27 15:58:10 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_checkber(char **av)
{
	int	indexcount;
	int	cmpres;

	indexcount = ft_strlen_mo(av[1], '\0') - 4;
	av[1] += indexcount;
	cmpres = ft_strcmp(av[1], ".ber");
	if (cmpres != 0)
	{
		ft_putstr("Error : The map isn't .ber\n");
		exit(0);
	}
	av[1] -= indexcount;
}

void	check_fileber(int ac, char **av)
{
	if (ac == 2)
		ft_checkber(av);
	else
	{
		ft_putstr("Error : ./solong ./maps/[yourmap]\n");
		exit(0);
	}
}
