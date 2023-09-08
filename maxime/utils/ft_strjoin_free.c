/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:58:13 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/05 19:03:30 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strjoin_free_1(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest)
	{
		i = 0;
		while (s1 && s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
		j = -1;
		while (s2[++j])
			dest[i + j] = s2[j];
		dest[i + j] = '\0';
	}
	if (s1)
		free(s1);
	return (dest);
}
