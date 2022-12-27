/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:23:59 by njerasea          #+#    #+#             */
/*   Updated: 2022/12/27 15:58:06 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	deprint(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("This is deprint ===> [%c]\n", str[i]);
		i++;
	}
}

void	deprint2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i + 1] == NULL)
			printf("%s\n", str[i]);
		else
			printf("%s", str[i]);
		i++;
	}
	printf("\n");
}
