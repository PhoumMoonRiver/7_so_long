/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:53:32 by njerasea          #+#    #+#             */
/*   Updated: 2022/12/18 09:26:56 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int map_row(int fd)
{
    t_kn this;
    char    *str;

    this.row = 0;
    str = get_next_line(fd);
    while(str)
    {
        this.row++;
        free(str);
        str = get_next_line(fd);
    }
    close(fd);
    return (this.row);
}

char    **get_map(int row, char **av)
{
    char    **map;
    t_kn this;

    this.i = 0;
    this.fd = open(av[1], O_RDONLY);
    if (this.fd < 0)
    {
        ft_putstr("Error : Map can't open\n");
        exit(0);
    }
    map = (char **)malloc(sizeof(char *) * (row + 1));
    if (!map)
        return (NULL);
    map[row] = NULL;
    while (1)
    {
        map[this.i] = get_next_line(this.fd);
        if (map[this.i] == NULL)
            break;
        this.i++;
    }
    close(this.fd);
    return (map);
}

void    check_map(char **av)
{
    int fd;
    int row;
    char    **map;

    fd = open(av[1], O_RDONLY);
    if (fd < 0)
    {
        ft_putstr("Error : Map can't open\n");
        exit(0);
    }
    row = map_row(fd);
    map = get_map(row, av);
    check_rectang(map);
    check_wall(map);
    check_env(map);
    check_path(map, row);
deprint2d(map);
}