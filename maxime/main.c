/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:56:48 by mlangloi          #+#    #+#             */
/*   Updated: 2023/09/09 15:47:16 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"
#include<math.h>
#include<string.h>

float	absolute(float a)
{
	if (a < 0)
		a *= -1;
	return (a);
}

void	verLine(int x, int drawStart, int drawEnd, int color, void *mlx, void *win)
{
	int i = 0;
	while (i < drawStart)
	{
		mlx_pixel_put(mlx, win, x, i, 0x00000);
		i++;
	}
	while (drawStart < drawEnd)
	{
		mlx_pixel_put(mlx, win, x, drawStart, color);
		drawStart++;
	}
	while (drawEnd < 640)
	{
		mlx_pixel_put(mlx, win, x, drawEnd, 0x000000);
		drawEnd++;
	}
}

void	ft_render(t_aff *aff)
{
	for (int x = 0; x < (double)aff->w; x++)
	{
		aff->cameraX = 2.0f * (double)x / (double)aff->w - 1.0f;
		aff->rayDirX = aff->dirX + aff->planX * aff->cameraX;
		aff->rayDirY = aff->dirY + aff->planY * aff->cameraX;
		
		aff->mapX = (int)aff->posX;
		aff->mapY = (int)aff->posY;
		aff->hit = 0;
		
		if (aff->rayDirX == 0)
			aff->deltaDistX = 1e30;
		else
			aff->deltaDistX = absolute(1 / aff->rayDirX);
		if (aff->rayDirY == 0)
			aff->deltaDistY = 1e30;
		else
			aff->deltaDistY = absolute(1 / aff->rayDirY);
		
		
		
		
		
		
		
		
		
		
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
		if (aff->side == 0)
			aff->perpWallDist = (aff->sideDistX - aff->deltaDistX);
		else
			aff->perpWallDist = (aff->sideDistY - aff->deltaDistY);

		/*
		if (aff->side == 0)
			aff->perpWallDist = ((double)aff->mapX - \
				aff->posX + (1 - (double)aff->stepX) / 2) / aff->rayDirX;
		else
			aff->perpWallDist = ((double)aff->mapY - \
				aff->posY + (1 - (double)aff->stepY) / 2) / aff->rayDirY;
*/

		aff->lineHeight = (int)((double)aff->h / aff->perpWallDist);

		aff->drawStart = -aff->lineHeight / 2 + (double)aff->h / 2;
		if(aff->drawStart < 0)
			aff->drawStart = 0;
		aff->drawEnd = aff->lineHeight / 2 + (double)aff->h / 2;
		if(aff->drawEnd >= (double)aff->h)
			aff->drawEnd = (double)aff->h - 1;
			
			
			
			
		int color;
		color = 0xFFFFFF;


		verLine(x, aff->drawStart, aff->drawEnd, color, aff->info->mlx, aff->info->win);		
	}
			
		
}










int	ft_controls(int touche, t_aff *aff)
{
	if (touche == 65363)
	{
		double oldDirX = aff->dirX;
	      	aff->dirX = aff->dirX * cos(-(0.033 * 1.8) / 2) - aff->dirY * sin(-(0.033 * 1.8) / 2);
	      	aff->dirY = oldDirX * sin(-(0.033 * 1.8) / 2) + aff->dirY * cos(-(0.033 * 1.8) / 2);
		double oldPlaneX = aff->planX;
		aff->planX = aff->planX * cos(-(0.033 * 1.8) / 2) - aff->planY * sin(-(0.033 * 1.8) / 2);
		aff->planY = oldPlaneX * sin(-(0.033 * 1.8) / 2) + aff->planY * cos(-(0.033 * 1.8) / 2);
		
		printf("%f %f\n", aff->posX, aff->posY);
	}
	
	if (touche == 65361)
	{
		double oldDirX = aff->dirX;
	      	aff->dirX = aff->dirX * cos((0.033 * 1.8) / 2) - aff->dirY * sin((0.033 * 1.8) / 2);
	      	aff->dirY = oldDirX * sin((0.033 * 1.8) / 2) + aff->dirY * cos((0.033 * 1.8) / 2);
		double oldPlaneX = aff->planX;
		aff->planX = aff->planX * cos((0.033 * 1.8) / 2) - aff->planY * sin((0.033 * 1.8) / 2);
		aff->planY = oldPlaneX * sin((0.033 * 1.8) / 2) + aff->planY * cos((0.033 * 1.8) / 2);
		
		printf("%f %f\n", aff->posX, aff->posY);
	}
	if (touche == 100)
	{
		if (aff->worldMap[(int)aff->posX + (int)aff->dirY * (int)0.1][(int)aff->posY] == 0)
			aff->posX += aff->dirY * 0.1;
		if (aff->worldMap[(int)aff->posX][(int)aff->posY + (int)aff->dirX * (int)0.1] == 0)
			aff->posY -= aff->dirX * 0.1;
	}
	if (touche == 97)
	{
		if (aff->worldMap[(int)aff->posX + (int)aff->dirY * (int)0.1][(int)aff->posY] == 0)
			aff->posX -= aff->dirY * 0.1;
		if (aff->worldMap[(int)aff->posX][(int)aff->posY + (int)aff->dirX * (int)0.1] == 0)
			aff->posY += aff->dirX * 0.1;
	}
	if (touche == 119)
	{
		if (aff->worldMap[(int)aff->posX + (int)aff->dirX * (int)0.1][(int)aff->posY] == 0)
			aff->posX += aff->dirX * 0.1;
		if (aff->worldMap[(int)aff->posX][(int)aff->posY + (int)aff->dirY * (int)0.1] == 0)
			aff->posY += aff->dirY * 0.1;
	}
	if (touche == 115)
	{
		if (aff->worldMap[(int)aff->posX - (int)aff->dirX * (int)0.1][(int)aff->posY] == 0)
			aff->posX -= aff->dirX * 0.1;
		if (aff->worldMap[(int)aff->posX][(int)aff->posY - (int)aff->dirY * (int)0.1] == 0)
			aff->posY -= aff->dirY * 0.1;
		printf("tr%f %f\n", aff->posX, aff->posY);
	}
	return (0);
}

int ft_exit(t_aff *aff)
{
	mlx_clear_window(aff->info->mlx, aff->info->win);
	mlx_destroy_window(aff->info->mlx, aff->info->win);
	mlx_destroy_display(aff->info->mlx);
	return (0);
}

void spaw_playeur(t_aff *aff)
{
	int i;
	int j;

	i = 0;
	while (aff->info->map[i])
	{
		j = -1;
		while (aff->info->map[i][++j])
			if (aff->info->map[i][j] == 'N' || aff->info->map[i][j] == 'S'
				|| aff->info->map[i][j] == 'E' || aff->info->map[i][j] == 'W')
				break ;
		if (aff->info->map[i][j] != '\0')
			break ;
		i++;
	}
	aff->posX = i;
	aff->posY = j;
	if (aff->info->map[i][j] == 'N')
	{
		aff->dirX = -1;
		aff->planY = 0.66;
	}
	if (aff->info->map[i][j] == 'S')
	{
		aff->dirX = 1;
		aff->planY = -0.66;
	}
	if (aff->info->map[i][j] == 'E')
	{
		aff->dirY = 1;
		aff->planX = 0.66;
	}
	if (aff->info->map[i][j] == 'W')
	{
		aff->dirY = -1;
		aff->planX = -0.66;
	}
}

int main (int argc, char **argv)
{
	t_info*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (print_error_message(ERRCODE_MALLOC));
	info->mlx = mlx_init();
	//erreur mlx non gerer encore
	if (ft_parsing(argc, argv, info) == 1)
	{
		mlx_destroy_display(info->mlx);
		free(info->mlx);
		free(info);
		return (1);
	}
	ft_free_img(info);
	
	
	void	*win;
	
	t_aff	*aff;
	aff = malloc(sizeof(t_aff));
	

	aff->planX = 0;
	aff->planY = 0;
	aff->dirX = 0;
	aff->dirY = 0;
	aff->info = info;
	spaw_playeur(aff);
	aff->posX += 0.5;
	aff->posY += 0.5;

	win = mlx_new_window(info->mlx, 640, 480, "cub3d");
	mlx_key_hook(win, ft_controls, aff);
	info->mlx = info->mlx;
	info->win = win;
	aff->w = 640;
	aff->h = 480;
	
	
	
	
	mlx_loop_hook(info->mlx, (void *)ft_render, aff);
	mlx_hook(info->win, 17, 0, ft_exit, aff);
	mlx_loop(info->mlx);
	return (0);
}
