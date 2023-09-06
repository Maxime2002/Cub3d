/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charg_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:31:24 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/06 20:19:54 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char *ft_strdup_char(char *src, char c)
{
	int i;
	char *dest;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	dest = malloc(sizeof(char) * i + 1);
	if (dest)
	{
		i = 0;
		while (src[i] && src[i] != c)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

int	ft_charg_map(t_info *info, char *dest, int i)
{
	int j;

	while (dest[i] && dest[i] == '\n')
		i++;
	if (!dest[i])
		return (print_error_message(ERRCODE_MAP_VOID));
	info->map = malloc(sizeof(char *) * (ft_count_nb_char(dest + i, '\n') + 1));
	if (!info->map)
		return (print_error_message(ERRCODE_MALLOC));
	j = 0;
	while (dest[i])
	{
		info->map[j] = ft_strdup_char(dest + i, '\n');
		if (!info->map[j])
			return (print_error_message(ERRCODE_MALLOC));
		i += ft_strlen_char(dest + i, '\n');
		if (dest[i] == '\n')
			i++;
		j++;
	}
	info->map[j] = NULL;
	return (0);
}
