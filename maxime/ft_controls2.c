/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controls2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:45:43 by mlangloi          #+#    #+#             */
/*   Updated: 2023/09/12 18:45:44 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_porte(t_aff *aff)
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

void	ft_porte2(t_aff *aff)
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

int	ft_controls(int touche, t_aff *aff)
{
	if (touche == 65363)
		ft_droite(aff);
	if (touche == 65361)
		ft_gauche(aff);
	ft_avancer_reculer(touche, aff);
	ft_droite_gauche(touche, aff);
	if (touche == 32)
	{
		if (ft_porte(aff) == 0)
			ft_porte2(aff);
	}
	if (touche == 65307)
		ft_exit(aff);
	return (0);
}
