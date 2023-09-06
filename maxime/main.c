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
	ray->DirX = -1;
	ray->DirY = 0;
	ray->PlaneX = 0;
	ray->PlaneY = 1;
	
	ray->x = 0;
	ray->camX = (2 * ray->x / ray->w) - 1;
	ray->rayPosX = ray->posX;
	ray->rayPosY = ray->posY;
	ray->rayDirX = ray->DirX + ray->PlaneX * ray->camX;
	ray->rayDirY = ray->DirY + ray->PlaneY * ray->camX;
			
	ray->mapX = round(ray->rayPosX);
	ray->mapY = round(ray->rayPosY);
	ray->deltaDistX = sqrt(1 + (ray->rayDirY * ray->rayDirY)/(ray->rayDirX * ray->rayDirX));
	ray->deltaDistY = sqrt(1 + (ray->rayDirX * ray->rayDirX)/(ray->rayDirY * ray->rayDirY));
	ray->hit = 0;
	
	ray->line_length = 900;
}


void	render(t_ray *ray, int carte[5][5], void *img)
{
	(void)img;
	while (ray->x <= ray->w)
	{
		if (ray->rayDirX < 0)
		{
			ray->stepX = -1;
			ray->sideDistX = (ray->rayPosX - ray->mapX) * ray->deltaDistX;
		}
		else
		{
			ray->stepX = 1;
			ray->sideDistX = (ray->mapX + 1.0 - ray->rayPosX) * ray->deltaDistX;
		}
		if (ray->rayDirY < 0)
		{
			ray->stepY = -1;
			ray->sideDistY = (ray->rayPosY - ray->mapY) * ray->deltaDistY;
		}
		else
		{
			ray->stepY = 1;
			ray->sideDistY = (ray->mapY + 1.0 - ray->rayPosY) * ray->deltaDistY;
		}
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
			if (carte[ray->mapX][ray->mapY] > 0)
				ray->hit = 1;
		}	
		if (ray->side == 0)
		{
			ray->perpWallDist = ((double)ray->mapX - ray->rayPosX + (1 - (double)ray->stepX) /2) / ray->rayDirX;
		}
		else
		{
			ray->perpWallDist = ((double)ray->mapY - ray->rayPosY + (1 - (double)ray->stepY) /2) / ray->rayDirY;
		}
		ray->hauteurLigne = (int)(ray->h / ray->perpWallDist);
		ray->drawStart = -ray->hauteurLigne / 2 + ray->h / 2;
		ray->drawEnd = ray->hauteurLigne / 2 + ray->h / 2;
		if (ray->drawStart < 0)
			ray->drawStart = 0;
		if (ray->drawEnd >= ray->h || ray->drawEnd < 0)
			ray->drawEnd = ray->h - 1;
	
	/*
		int j;
		int i;

		j = -1;
		ray->drawEnd = ray->h - ray->drawStart;
		i = ray->drawEnd;
		while (++j < ray->drawStart)
			ray->addr[j * ray->line_length / 4 + ray->x] = -1;
		//if (j <= ray->drawEnd)
			//ft_texture(ray, ray->x, j);
		j = i;
		while (++j < ray->h)
			ray->addr[j * ray->line_length / 4 + ray->x] = -1;
			
		*/
		
		int x = ray->x;
		int color = 255;
		for (int y = ray->drawStart; y <= ray->drawEnd; y++)
		{
			int pixel_index = y * ray->line_length / 4 + x;
		printf("%d\n", pixel_index);
			ray->addr[pixel_index] = color;
		}
			
			
			
			
			
			
			
			
			
	/*			
			int bpp;
			int size_line;
			int endian;
			char *image_data = mlx_get_data_addr(&img, &bpp, &size_line, &endian);	
			
			
				
			    for (int y = drawStart; y <= drawEnd; y++)
   				{
      
       			int color = (carte[ray.mapX][ray.mapY] == 0) ? 0xFF0000 : 0xFFFFFF; 
       			 
       			 if (ray.side == 0)
				{
					ray.perpWallDist = fabs((ray.mapX - ray.rayPosX + (1 - ray.stepX) /2) / ray.rayDirX);
					ray.mapX += ray.stepX;
				}
				else
				{
					ray.perpWallDist = fabs((ray.mapY - ray.rayPosY + (1 - ray.stepY) /2) / ray.rayDirY);
					ray.mapY = ray.stepY;
				}

       
       			int pixel_index = (y * size_line) + (ray.x * (bpp / 8));
				printf("pixel_index = %d, bpp = %d\n", pixel_index, bpp);
       
       			 image_data[pixel_index] = (color >> 16) & 0xFF; 
       			image_data[pixel_index + 1] = (color >> 8) & 0xFF; 
        			image_data[pixel_index + 2] = color & 0xFF;
   			}*/
   		ray->x += 1.0;
	}
			
}

void	draw_walls(void  *mlx, void  *win, void  *img)
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
	
	t_ray *ray = malloc(sizeof(t_ray));
	init_struct(ray);
	
	int bpp;
	int size_line;
	int endian;
	char *image_data = mlx_get_data_addr(&img, &bpp, &size_line, &endian);	
	ray->addr = (char *)image_data;
	
	
	render(ray, carte, &img);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
}



int main (int ac, char **av)
{
	(void)ac;
	(void)av;
	void	*mlx;
	void	*win;
	void	*img;
	
	
	
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1600, 900, "cub3d");
	img = mlx_new_image(mlx, 1600, 900);
	
	draw_walls(&mlx, &win, &img);
	
	
	
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
	
	
	
	mlx_loop(mlx);
	(void)win;
	return (0);
}
