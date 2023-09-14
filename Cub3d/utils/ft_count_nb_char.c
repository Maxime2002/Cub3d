/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_nb_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:51:09 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/06 18:52:32 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_count_nb_char(char *dest, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (dest[i])
	{
		if (dest[i] == c)
			count++;
		i++;
	}
	return (count);
}
