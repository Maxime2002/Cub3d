/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controls2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:45:43 by mlangloi          #+#    #+#             */
/*   Updated: 2023/09/14 14:50:57 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_door(t_aff *aff)
{
	int	res;

	res = 0;
	if (aff->info->map[(int)(aff->pos_x + (aff->dir_x
				* 0.5 * 2))][(int)aff->pos_y] == 'P' &&
					aff->info->map[(int)aff->pos_x][(int)aff->pos_y] == '0')
	{
		aff->info->map[(int)(aff->pos_x + (aff->dir_x
					* 0.5 * 2))][(int)aff->pos_y] = 'z';
		res = 1;
	}
	else if (aff->info->map[(int)(aff->pos_x)][(int)(aff->pos_y
			+ (aff->dir_y * 0.5 * 2))] == 'P' &&
				aff->info->map[(int)aff->pos_x][(int)aff->pos_y] == '0')
	{
		aff->info->map[(int)(aff->pos_x)][(int)(aff->pos_y
				+ (aff->dir_y * 0.5 * 2))] = 'z';
		res = 1;
	}
	return (res);
}

void	ft_door2(t_aff *aff)
{
	if (aff->info->map[(int)(aff->pos_x + (aff->dir_x
				* 0.5 * 2))][(int)aff->pos_y] == 'z' &&
					aff->info->map[(int)aff->pos_x][(int)aff->pos_y] == '0')
		aff->info->map[(int)(aff->pos_x + (aff->dir_x
					* 0.5 * 2))][(int)aff->pos_y] = 'P';
	else if (aff->info->map[(int)(aff->pos_x)][(int)(aff->pos_y
			+ (aff->dir_y * 0.5 * 2))] == 'z' &&
				aff->info->map[(int)aff->pos_x][(int)aff->pos_y] == '0')
		aff->info->map[(int)(aff->pos_x)][(int)(aff->pos_y
				+ (aff->dir_y * 0.5 * 2))] = 'P';
}

int	ft_controls(int key, t_aff *aff)
{
	if (key == 65363)
		ft_right(aff);
	if (key == 65361)
		ft_left(aff);
	ft_up_down(key, aff);
	ft_right_left(key, aff);
	if (key == 32)
	{
		if (ft_door(aff) == 0)
			ft_door2(aff);
	}
	if (key == 65307)
		ft_exit(aff);
	return (0);
}
