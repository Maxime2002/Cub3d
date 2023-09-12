/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:30:01 by mlangloi          #+#    #+#             */
/*   Updated: 2023/09/12 15:18:59 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_render5(t_aff *aff)
{
	if (aff->ray_dir_x < 0)
	{
		aff->step_x = -1;
		aff->side_dist_x = (aff->pos_x - aff->map_x) * aff->delta_dist_x;
	}
	else
	{
		aff->step_x = 1;
		aff->side_dist_x = (aff->map_x + 1.0 - aff->pos_x) * aff->delta_dist_x;
	}
	if (aff->ray_dir_y < 0)
	{
		aff->step_y = -1;
		aff->side_dist_y = (aff->pos_y - aff->map_y) * aff->delta_dist_y;
	}
	else
	{
		aff->step_y = 1;
		aff->side_dist_y = (aff->map_y + 1.0 - aff->pos_y) * aff->delta_dist_y;
	}
}

void	ft_render2(t_aff *aff)
{
	if (aff->ray_dir_x == 0)
		aff->delta_dist_x = 1e30;
	else
		aff->delta_dist_x = absolute(1 / aff->ray_dir_x);
	if (aff->ray_dir_y == 0)
		aff->delta_dist_y = 1e30;
	else
		aff->delta_dist_y = absolute(1 / aff->ray_dir_y);
	ft_render5(aff);
}

void	ft_render3(t_aff *aff)
{
	while (aff->hit == 0)
	{
		if (aff->side_dist_x < aff->side_dist_y)
		{
			aff->side_dist_x += aff->delta_dist_x;
			aff->map_x += aff->step_x;
			aff->side = 0;
		}
		else
		{
			aff->side_dist_y += aff->delta_dist_y;
			aff->map_y += aff->step_y;
			aff->side = 1;
		}
		if (aff->info->map[aff->map_x][aff->map_y] == '1')
		{
<<<<<<< HEAD
			aff->hit = 1;
			aff->let = '1';
		}
		if (aff->info->map[aff->map_x][aff->map_y] == 'P')
		{
			aff->hit = 1;
			aff->let = 'P';
		}
		if (aff->info->map[aff->map_x][aff->map_y] == 'S')
		{
			aff->hit = 1;
			aff->let = 'S';
=======
			aff->hit = 1;
			aff->let = '1';
		}
		if (aff->info->map[aff->map_x][aff->map_y] == 'P')
		{
			aff->hit = 1;
			aff->let = 'P';
>>>>>>> 9239d653434ec16f8bfa6fe5328afa845ec1b6f6
		}
	}
}

void	ft_render4(t_aff *aff)
{
	if (aff->side == 0)
		aff->perp_wall_dist = (aff->side_dist_x - aff->delta_dist_x);
	else
		aff->perp_wall_dist = (aff->side_dist_y - aff->delta_dist_y);
	aff->line_height = (int)((double)aff->h / aff->perp_wall_dist);
	aff->draw_start = -aff->line_height / 2 + (double)aff->h / 2;
	if (aff->draw_start < 0)
		aff->draw_start = 0;
	aff->draw_end = aff->line_height / 2 + (double)aff->h / 2;
	if (aff->draw_end >= (double)aff->h)
		aff->draw_end = (double)aff->h - 1;
}

void	ft_render(t_aff *aff)
{
	int	x;

	x = 0;
	while (x < (double)aff->w)
	{
		aff->camera_x = 2.0f * (double)x / (double)aff->w - 1.0f;
		aff->ray_dir_x = aff->dir_x + aff->plan_x * aff->camera_x;
		aff->ray_dir_y = aff->dir_y + aff->plan_y * aff->camera_x;
		aff->map_x = (int)aff->pos_x;
		aff->map_y = (int)aff->pos_y;
		aff->hit = 0;
		aff->let = '0';
		ft_render2(aff);
		ft_render3(aff);
		ft_render4(aff);
		ft_color_column(aff, x);
		x++;
	}
	mlx_put_image_to_window(aff->info->mlx, aff->info->win, aff->img, 0, 0);
}
