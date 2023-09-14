/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_feasibility_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:55:04 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/09 15:38:24 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	replace_space(char **map, int i, int j)
{
	int	tmp;

	tmp = 0;
	if (map[i + 1] != NULL && (map[i + 1][j] == '0' || map[i + 1][j] == 'P'))
	{
		tmp++;
		map[i + 1][j] = '9';
	}
	if (i - 1 >= 0 && (map[i - 1][j] == '0' || map[i - 1][j] == 'P'))
	{
		tmp++;
		map[i - 1][j] = '9';
	}
	if (map[i][j + 1] == '0' || map[i][j + 1] == 'P')
	{
		tmp++;
		map[i][j + 1] = '9';
	}
	if (j - 1 >= 0 && (map[i][j - 1] == '0' || map[i][j - 1] == 'P'))
	{
		tmp++;
		map[i][j - 1] = '9';
	}
	return (tmp);
}

int	ft_verif_map_temp(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '9' && (i == 0 || j == 0 || map[i + 1] == NULL
					|| map[i][j + 1] == '\0' || map[i][j + 1] == ' ' || map[i
					+ 1][j] == ' ' || map[i][j - 1] == ' ' || map[i
					- 1][j] == ' '))
				return (print_error_message(ERRCODE_INVALID_MAP));
		}
		i++;
	}
	return (0);
}

int	ft_feasibility_check2(char **map, int i, int j)
{
	while (map[i])
	{
		if (map[i][j] == '9')
		{
			if (replace_space(map, i, j) != 0)
			{
				i = 0;
				j = 0;
			}
		}
		j++;
		if (map[i][j] == '\0')
		{
			i++;
			j = 0;
		}
	}
	i = ft_verif_map_temp(map);
	ft_free_map(map);
	return (i);
}

int	ft_feasibility_check(t_info *info)
{
	int		i;
	int		j;
	char	**temp;

	i = 0;
	while (info->map[i])
	{
		j = -1;
		while (info->map[i][++j])
			if (info->map[i][j] == 'N' || info->map[i][j] == 'S'
				|| info->map[i][j] == 'E' || info->map[i][j] == 'W')
				break ;
		if (info->map[i][j] != '\0')
			break ;
		i++;
	}
	if (i == 0 || j == 0 || info->map[i] == NULL || info->map[i + 1] == NULL
		|| info->map[i][j + 1] == '\0')
		return (print_error_message(ERRCODE_INVALID_MAP));
	temp = ft_strcpy_tab(info->map);
	if (!temp)
		return (print_error_message(ERRCODE_MALLOC));
	temp[i][j] = '9';
	return (ft_feasibility_check2(temp, i, j));
}
