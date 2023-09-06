/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:56:48 by mlangloi          #+#    #+#             */
/*   Updated: 2023/09/05 13:56:49 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"
# include <math.h>


void	init_struct(t_ray *ray)
{
	ray->w = 1600;
	ray->h = 900;
	ray->posX = 2;
	ray->posY = 2;
	ray->DirX = 1;
	ray->DirY = 0;
	ray->PlaneX = 0;
	ray->PlaneY = 0.66;
	
	ray->x = 0;
	ray->rayPosX = ray->posX;
	ray->rayPosY = ray->posY;
			
	ray->mapX = (int)ray->rayPosX;
	ray->mapY = (int)ray->rayPosY;
	ray->hit = 0;
	
	ray->line_length = 900;
}


void		draw_vert_line(t_ray *ray, int y_start, int y_end)
{
	int color;

	color = 0xFF0000;
	while (y_start < y_end)
	{
		//printf("%d et %d\n", ray->x, y_start);
		mlx_pixel_put(ray->mlx, ray->win, ray->x, y_start, color);
		y_start++;
	}
}

void	render(t_ray *ray, int carte[5][5])
{
	while (ray->x <= ray->w)
	{
		ray->camX = (2 * ray->x / (double)ray->w) - 1;
		double rayDirX = ray->DirX + ray->PlaneX * ray->camX;
		double rayDirY = ray->DirY + ray->PlaneY * ray->camX;
		ray->mapX = ray->posX;
		ray->mapY = ray->posY;
		
		if (ray->DirX == 0)
			ray->deltaDistX = 1e30;
		else
			ray->deltaDistX = fabs(1 / rayDirX);
		if (ray->DirY == 0)
			ray->deltaDistY = 1e30;
		else
			ray->deltaDistY = fabs(1 / rayDirY);
		//printf("%f %f\n", rayon.distv2.x, rayon.distv2.y);
	
		if (rayDirX < 0)
		{
			ray->stepX = -1;
			ray->sideDistX = (ray->rayPosX - ray->mapX) * ray->deltaDistX;
		}
		else
		{
			ray->stepX = 1;
			ray->sideDistX = (ray->mapX + 1.0 - ray->rayPosX) * ray->deltaDistX;
		}
		if (rayDirY < 0)
		{
			ray->stepY = -1;
			ray->sideDistY = (ray->rayPosY - ray->mapY) * ray->deltaDistY;
		}
		else
		{
			ray->stepY = 1;
			ray->sideDistY = (ray->mapY + 1.0 - ray->rayPosY) * ray->deltaDistY;
		}
		ray->hit = 0;
		while (ray->hit == 0)
		{
			if (ray->sideDistX < ray->sideDistY)
			{
				ray->sideDistX += ray->deltaDistX;
				ray->mapX += ray->stepX;
				ray->side = 0;
			}
			else
			{
				ray->sideDistY += ray->deltaDistY;
				ray->mapY += ray->stepY;
				ray->side = 1;
			}
			if (carte[ray->mapX][ray->mapY] == 1)
				ray->hit = 1;
		}	
		if (ray->side == 0)
		{
			ray->perpWallDist = ray->sideDistX - ray->deltaDistX;
		}
		else
		{
			
			ray->perpWallDist = ray->sideDistY - ray->deltaDistY;
		}
		ray->hauteurLigne = (int)(ray->h / ray->perpWallDist);
		ray->drawStart = -ray->hauteurLigne / 2 + ray->h / 2;
		ray->drawEnd = ray->hauteurLigne / 2 + ray->h / 2;
		//printf("%d et %d\n", ray->drawStart, ray->drawEnd);
		draw_vert_line(ray, ray->drawStart, ray->drawEnd);

   		ray->x += 1.0;
	}
			
}

void	draw_walls(t_ray *ray)
{

	int carte[5][5];
	carte[0][0] = 1;
	carte[0][1] = 1;
	carte[0][2] = 1;
	carte[0][3] = 1;
	carte[0][4] = 1;
	
	carte[1][0] = 1;
	carte[1][1] = 0;
	carte[1][2] = 0;
	carte[1][3] = 0;
	carte[1][4] = 1;
	
	carte[2][0] = 1;
	carte[2][1] = 0;
	carte[2][2] = 0;
	carte[2][3] = 0;
	carte[2][4] = 1;
	
	carte[3][0] = 1;
	carte[3][1] = 0;
	carte[3][2] = 0;
	carte[3][3] = 0;
	carte[3][4] = 1;
	
	carte[4][0] = 1;
	carte[4][1] = 1;
	carte[4][2] = 1;
	carte[4][3] = 1;
	carte[4][4] = 1;
	
	

	
	
	render(ray, carte);
}


int	ft_controls(int touche, t_ray *ray)
{
	if (touche == 119 || touche == 65632)
	{
		ray->posX += 0.2;
		ray->x = 0;
		draw_walls(ray);
		printf("%f %f\n", ray->posX, ray->posY);
	}
	if (touche == 97 || touche == 65364)
	{
		ray->posY -= 0.2;
		ray->x = 0;
		draw_walls(ray);
		printf("%f %f\n", ray->posX, ray->posY);
	}
	if (touche == 115 || touche == 65361)
	{
		ray->posX -= 0.2;
		ray->x = 0;
		draw_walls(ray);
		printf("%f %f\n", ray->posX, ray->posY);
	}
	if (touche == 100 || touche == 65363)
	{
		ray->posY += 0.2;
		ray->x = 0;
		draw_walls(ray);
		printf("%f %f\n", ray->posX, ray->posY);
	}
	return (0);
}


int main (int ac, char **av)
{
	(void)ac;
	(void)av;
	void	*mlx;
	void	*win;
	
	
	t_ray *ray = malloc(sizeof(t_ray));
	init_struct(ray);
	
	
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1600, 900, "cub3d");
	ray->mlx = mlx;
	ray->win = win;
	
	draw_walls(ray);
	
	mlx_key_hook(win, ft_controls, ray);
	
	
	/*
	int bpp;
	int size_line;
	int endian;
	char *img_data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	
	
	
	for (int y = 0; y < 900; y++)
	{
		for (int x = 0; x < 1600; x++)
		{
			int pi = (x * 4) + (size_line * y);
			img_data[pi] = 200;
			img_data[pi + 1] = 10;
			img_data[pi + 2] = 75;
			img_data[pi + 3] = 0;
			
		}
	}
	
	*/
	
	
	
	mlx_loop(ray->mlx);
	return (0);
}
