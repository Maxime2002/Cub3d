/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:58:36 by mlangloi          #+#    #+#             */
/*   Updated: 2023/09/12 14:58:37 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_droite(t_aff *aff)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = aff->dirX;
	old_plane_x = aff->planX;
	aff->dirX = aff->dirX * cos(-(0.033 * 1.8) / 2) - aff->dirY
		* sin(-(0.033 * 1.8) / 2);
	aff->dirY = old_dir_x * sin(-(0.033 * 1.8) / 2) + aff->dirY
		* cos(-(0.033 * 1.8) / 2);
	aff->planX = aff->planX * cos(-(0.033 * 1.8) / 2) - aff->planY
		* sin(-(0.033 * 1.8) / 2);
	aff->planY = old_plane_x * sin(-(0.033 * 1.8) / 2) + aff->planY
		* cos(-(0.033 * 1.8) / 2);
}

void	ft_gauche(t_aff *aff)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = aff->dirX;
	old_plane_x = aff->planX;
	aff->dirX = aff->dirX * cos((0.033 * 1.8) / 2) - aff->dirY
		* sin((0.033 * 1.8) / 2);
	aff->dirY = old_dir_x * sin((0.033 * 1.8) / 2) + aff->dirY
		* cos((0.033 * 1.8) / 2);
	aff->planX = aff->planX * cos((0.033 * 1.8) / 2) - aff->planY
		* sin((0.033 * 1.8) / 2);
	aff->planY = old_plane_x * sin((0.033 * 1.8) / 2) + aff->planY
		* cos((0.033 * 1.8) / 2);
}

void	ft_avancer_reculer(int touche, t_aff *aff)
{
	if (touche == 119)
	{
		if (aff->info->map[(int)(aff->posX + (aff->dirX
					* 0.1 * 2))][(int)aff->posY] != '1')
			aff->posX += aff->dirX * 0.1;
		if (aff->info->map[(int)(aff->posX)][(int)(aff->posY
				+ (aff->dirY * 0.1 * 2))] != '1')
			aff->posY += aff->dirY * 0.1;
	}
	if (touche == 115)
	{
		if (aff->info->map[(int)(aff->posX - (aff->dirX
					* 0.1 * 2))][(int)(aff->posY)] != '1')
			aff->posX -= aff->dirX * 0.1;
		if (aff->info->map[(int)(aff->posX)][(int)(aff->posY
				- (aff->dirY * 0.1 * 2))] != '1')
			aff->posY -= aff->dirY * 0.1;
	}
}

void	ft_droite_gauche(int touche, t_aff *aff)
{
	if (touche == 100)
	{
		if (aff->info->map[(int)(aff->posX + aff->dirY * (0.1
					* 2))][(int)aff->posY] != '1')
			aff->posX += aff->dirY * 0.1;
		if (aff->info->map[(int)aff->posX][(int)(aff->posY - aff->dirX
			* (0.1 * 2))] != '1')
			aff->posY -= aff->dirX * 0.1;
	}
	if (touche == 97)
	{
		if (aff->info->map[(int)(aff->posX - aff->dirY
				* (0.1 * 2))][(int)aff->posY] != '1')
			aff->posX -= aff->dirY * 0.1;
		if (aff->info->map[(int)aff->posX][(int)(aff->posY
			+ aff->dirX * (0.1 * 2))] != '1')
			aff->posY += aff->dirX * 0.1;
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
