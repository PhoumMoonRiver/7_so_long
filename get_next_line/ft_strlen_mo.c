/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_mo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:24:59 by njerasea          #+#    #+#             */
/*   Updated: 2022/12/27 15:58:31 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strlen_mo(char *str, char exp)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != exp)
		i++;
	return (i);
}
