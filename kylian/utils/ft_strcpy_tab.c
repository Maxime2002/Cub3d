/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:22:02 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/07 13:27:39 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char **ft_strcpy_tab(char **src)
{
	int i;
	char **dest;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char *) * i);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		i++;
		dest[i] = ft_strdup(src[i]);
		if (!dest[i])
		{
			while (--i >= 0)
				free(dest[i]);
			free(dest);
			return (NULL);
		}
	}
	return(dest);
}
