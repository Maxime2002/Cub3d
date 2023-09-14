/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:58:36 by mlangloi          #+#    #+#             */
/*   Updated: 2023/09/14 14:50:57 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_right(t_aff *aff)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = aff->dir_x;
	old_plane_x = aff->plan_x;
	aff->dir_x = aff->dir_x * cos(-(0.033 * 1.8) / 2) - aff->dir_y
		* sin(-(0.033 * 1.8) / 2);
	aff->dir_y = old_dir_x * sin(-(0.033 * 1.8) / 2) + aff->dir_y
		* cos(-(0.033 * 1.8) / 2);
	aff->plan_x = aff->plan_x * cos(-(0.033 * 1.8) / 2) - aff->plan_y
		* sin(-(0.033 * 1.8) / 2);
	aff->plan_y = old_plane_x * sin(-(0.033 * 1.8) / 2) + aff->plan_y
		* cos(-(0.033 * 1.8) / 2);
}

void	ft_left(t_aff *aff)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = aff->dir_x;
	old_plane_x = aff->plan_x;
	aff->dir_x = aff->dir_x * cos((0.033 * 1.8) / 2) - aff->dir_y
		* sin((0.033 * 1.8) / 2);
	aff->dir_y = old_dir_x * sin((0.033 * 1.8) / 2) + aff->dir_y
		* cos((0.033 * 1.8) / 2);
	aff->plan_x = aff->plan_x * cos((0.033 * 1.8) / 2) - aff->plan_y
		* sin((0.033 * 1.8) / 2);
	aff->plan_y = old_plane_x * sin((0.033 * 1.8) / 2) + aff->plan_y
		* cos((0.033 * 1.8) / 2);
}

void	ft_down(t_aff *aff)
{
	if (aff->info->map[(int)(aff->pos_x - (aff->dir_x
				* 0.1 * 2))][(int)(aff->pos_y)] == '0' ||
			aff->info->map[(int)(aff->pos_x - (aff->dir_x
			* 0.1 * 2))][(int)(aff->pos_y)] == 'z')
		aff->pos_x -= aff->dir_x * 0.1;
	if (aff->info->map[(int)(aff->pos_x)][(int)(aff->pos_y
			- (aff->dir_y * 0.1 * 2))] == '0' ||
		aff->info->map[(int)(aff->pos_x)][(int)(aff->pos_y
			- (aff->dir_y * 0.1 * 2))] == 'z')
		aff->pos_y -= aff->dir_y * 0.1;
}

void	ft_up_down(int key, t_aff *aff)
{
	if (key == 119)
	{
		if (aff->info->map[(int)(aff->pos_x + (aff->dir_x
					* 0.1 * 2))][(int)aff->pos_y] == '0' ||
		aff->info->map[(int)(aff->pos_x + (aff->dir_x
					* 0.1 * 2))][(int)aff->pos_y] == 'z')
			aff->pos_x += aff->dir_x * 0.1;
		if (aff->info->map[(int)(aff->pos_x)][(int)(aff->pos_y
				+ (aff->dir_y * 0.1 * 2))] == '0' ||
			aff->info->map[(int)(aff->pos_x)][(int)(aff->pos_y
				+ (aff->dir_y * 0.1 * 2))] == 'z')
			aff->pos_y += aff->dir_y * 0.1;
	}
	if (key == 115)
	{
		ft_down(aff);
	}
}

void	ft_right_left(int key, t_aff *aff)
{
	if (key == 100)
	{
		if (aff->info->map[(int)(aff->pos_x + aff->dir_y * (0.1
					* 2))][(int)aff->pos_y] == '0' ||
				aff->info->map[(int)(aff->pos_x + aff->dir_y * (0.1
					* 2))][(int)aff->pos_y] == 'z')
			aff->pos_x += aff->dir_y * 0.1;
		if (aff->info->map[(int)aff->pos_x][(int)(aff->pos_y - aff->dir_x
			* (0.1 * 2))] == '0' || aff->info->map[(int)aff->pos_x]
				[(int)(aff->pos_y - aff->dir_x * (0.1 * 2))] == 'z')
			aff->pos_y -= aff->dir_x * 0.1;
	}
	if (key == 97)
	{
		if (aff->info->map[(int)(aff->pos_x - aff->dir_y
				* (0.1 * 2))][(int)aff->pos_y] == '0' ||
				aff->info->map[(int)(aff->pos_x - aff->dir_y
				* (0.1 * 2))][(int)aff->pos_y] == 'z')
			aff->pos_x -= aff->dir_y * 0.1;
		if (aff->info->map[(int)aff->pos_x][(int)(aff->pos_y
			+ aff->dir_x * (0.1 * 2))] == '0' || aff->info->map[(int)aff->pos_x]
				[(int)(aff->pos_y + aff->dir_x * (0.1 * 2))] == 'z')
			aff->pos_y += aff->dir_x * 0.1;
	}
}
