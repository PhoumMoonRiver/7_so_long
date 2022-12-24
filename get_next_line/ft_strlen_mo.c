/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_mo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:15:16 by njerasea          #+#    #+#             */
/*   Updated: 2022/12/16 13:08:03 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int ft_strlen_mo(char *str, char exp)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i] && str[i] != exp)
        i++;
    return (i);
}