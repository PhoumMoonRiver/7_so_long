/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:02:21 by njerasea          #+#    #+#             */
/*   Updated: 2022/12/15 14:13:28 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

// int main(int ac, char **av)
// {
//     check_fileber(ac, av);
//     check_map(av);
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	mlx_loop(mlx);
// }

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	//t_data	img;
    void    *t_img;
    char	*relative_path ="img/1.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    t_img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
printf("Hello w=> [%d] h=>[%d]", img_width,img_height);
    mlx_put_image_to_window(mlx, mlx_win, t_img, 5, 5);
	mlx_loop(mlx);
}