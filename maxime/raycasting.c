/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:30:01 by mlangloi          #+#    #+#             */
/*   Updated: 2023/09/11 16:30:02 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_render5(t_aff *aff)
{
	if (aff->rayDirX < 0)
	{
		aff->stepX = -1;
		aff->sideDistX = (aff->posX - aff->mapX) * aff->deltaDistX;
	}
	else
	{
		aff->stepX = 1;
		aff->sideDistX = (aff->mapX + 1.0 - aff->posX) * aff->deltaDistX;
	}
	if (aff->rayDirY < 0)
	{
		aff->stepY = -1;
		aff->sideDistY = (aff->posY - aff->mapY) * aff->deltaDistY;
	}
	else
	{
		aff->stepY = 1;
		aff->sideDistY = (aff->mapY + 1.0 - aff->posY) * aff->deltaDistY;
	}
}

void	ft_render2(t_aff *aff)
{
	if (aff->rayDirX == 0)
		aff->deltaDistX = 1e30;
	else
		aff->deltaDistX = absolute(1 / aff->rayDirX);
	if (aff->rayDirY == 0)
		aff->deltaDistY = 1e30;
	else
		aff->deltaDistY = absolute(1 / aff->rayDirY);
	ft_render5(aff);
}

void	ft_render3(t_aff *aff)
{
	while (aff->hit == 0)
	{
		if (aff->sideDistX < aff->sideDistY)
		{
			aff->sideDistX += aff->deltaDistX;
			aff->mapX += aff->stepX;
			aff->side = 0;
		}
		else
		{
			aff->sideDistY += aff->deltaDistY;
			aff->mapY += aff->stepY;
			aff->side = 1;
		}
		if (aff->info->map[aff->mapX][aff->mapY] == '1')
			aff->hit = 1;
	}
}

void	ft_render4(t_aff *aff)
{
	if (aff->side == 0)
		aff->perpWallDist = (aff->sideDistX - aff->deltaDistX);
	else
		aff->perpWallDist = (aff->sideDistY - aff->deltaDistY);
	aff->lineHeight = (int)((double)aff->h / aff->perpWallDist);
	aff->drawStart = -aff->lineHeight / 2 + (double)aff->h / 2;
	if (aff->drawStart < 0)
		aff->drawStart = 0;
	aff->drawEnd = aff->lineHeight / 2 + (double)aff->h / 2;
	if (aff->drawEnd >= (double)aff->h)
		aff->drawEnd = (double)aff->h - 1;
}

void	ft_render(t_aff *aff)
{
	int	x;

	x = 0;
	while (x < (double)aff->w)
	{
		aff->cameraX = 2.0f * (double)x / (double)aff->w - 1.0f;
		aff->rayDirX = aff->dirX + aff->planX * aff->cameraX;
		aff->rayDirY = aff->dirY + aff->planY * aff->cameraX;
		aff->mapX = (int)aff->posX;
		aff->mapY = (int)aff->posY;
		aff->hit = 0;
		ft_render2(aff);
		ft_render3(aff);
		ft_render4(aff);
		ft_color_column(aff, x);
		x++;
	}
	mlx_put_image_to_window(aff->info->mlx, aff->info->win, aff->img, 0, 0);
}
