/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:02:21 by njerasea          #+#    #+#             */
/*   Updated: 2022/12/27 15:59:14 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	check_fileber(ac, av);
	check_map(av);
	make_map(av);
}

// int	main(int ac, char **av)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// (void)ac;
// (void)av;
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	mlx_loop(mlx);
// 	return(0);
// }
