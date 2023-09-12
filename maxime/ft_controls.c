/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:58:36 by mlangloi          #+#    #+#             */
/*   Updated: 2023/09/12 15:12:16 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_droite(t_aff *aff)
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

void	ft_gauche(t_aff *aff)
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

void	ft_avancer_reculer(int touche, t_aff *aff)
{
	if (touche == 119)
	{
		if (aff->info->map[(int)(aff->pos_x + (aff->dir_x
					* 0.1 * 2))][(int)aff->pos_y] != '1')
			aff->pos_x += aff->dir_x * 0.1;
		if (aff->info->map[(int)(aff->pos_x)][(int)(aff->pos_y
				+ (aff->dir_y * 0.1 * 2))] != '1')
			aff->pos_y += aff->dir_y * 0.1;
	}
	if (touche == 115)
	{
		if (aff->info->map[(int)(aff->pos_x - (aff->dir_x
					* 0.1 * 2))][(int)(aff->pos_y)] != '1')
			aff->pos_x -= aff->dir_x * 0.1;
		if (aff->info->map[(int)(aff->pos_x)][(int)(aff->pos_y
				- (aff->dir_y * 0.1 * 2))] != '1')
			aff->pos_y -= aff->dir_y * 0.1;
	}
}

void	ft_droite_gauche(int touche, t_aff *aff)
{
	if (touche == 100)
	{
		if (aff->info->map[(int)(aff->pos_x + aff->dir_y * (0.1
					* 2))][(int)aff->pos_y] != '1')
			aff->pos_x += aff->dir_y * 0.1;
		if (aff->info->map[(int)aff->pos_x][(int)(aff->pos_y - aff->dir_x
			* (0.1 * 2))] != '1')
			aff->pos_y -= aff->dir_x * 0.1;
	}
	if (touche == 97)
	{
		if (aff->info->map[(int)(aff->pos_x - aff->dir_y
				* (0.1 * 2))][(int)aff->pos_y] != '1')
			aff->pos_x -= aff->dir_y * 0.1;
		if (aff->info->map[(int)aff->pos_x][(int)(aff->pos_y
			+ aff->dir_x * (0.1 * 2))] != '1')
			aff->pos_y += aff->dir_x * 0.1;
	}
}

int	ft_controls(int touche, t_aff *aff)
{
	if (touche == 65363)
		ft_droite(aff);
	if (touche == 65361)
		ft_gauche(aff);
	ft_avancer_reculer(touche, aff);
	ft_droite_gauche(touche, aff);
	if (touche == 65307)
		ft_exit(aff);
	return (0);
}
