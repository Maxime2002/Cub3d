/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charg_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:31:24 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/07 14:54:42 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strdup_char(char *src, char c)
{
	int		i;
	char	*dest;

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

int	ft_verif_map(t_info *info)
{
	int	i;
	int	count_playeur;
	int	j;

	i = 0;
	count_playeur = 0;
	while (info->map[i])
	{
		j = -1;
		while (info->map[i][++j])
		{
			if (info->map[i][j] == 'N' || info->map[i][j] == 'S'
				|| info->map[i][j] == 'E' || info->map[i][j] == 'W')
				count_playeur++;
			else if (info->map[i][j] != ' ' && info->map[i][j] != '1'
				&& info->map[i][j] != '0' && info->map[i][j] != 'P')
				return (print_error_message(ERRCODE_CHAR_MAP));
		}
		i++;
	}
	if (count_playeur != 1)
		return (print_error_message(ERRCODE_PLAYEUR_MAP));
	return (ft_feasibility_check(info));
}

int	ft_charg_map(t_info *info, char *dest, int i)
{
	int	j;

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
	return (ft_verif_map(info));
}
