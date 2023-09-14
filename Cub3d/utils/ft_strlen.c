/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:06:54 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/06 11:33:15 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src && src[i])
		i++;
	return (i);
}

int	ft_strlen_char(char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	return (i);
}
