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

void	render(int premAff, float w, float h, float posX, float posY, float DirX, float DirY, float PlaneX, float PlaneY, void *img, int carte[5][5])
{
		premAff = 0;
		(void) premAff;
		float x = 0;
		float y = 0;
		while (x <= w)
		{
			float	camX = (2 * x / w) - 1;
			float	rayPosX = posX;
			float	rayPosY = posY;
			float	rayDirX = DirX + PlaneX * camX;
			float	rayDirY = DirY + PlaneY * camX;
			
			int	mapX = round(rayPosX);
			int	mapY = round(rayPosY);
			float	sideDistX;
			float	sideDistY;
			float	deltaDistX = sqrt(1 + (rayDirY * rayDirY)/(rayDirX * rayDirX));
			float	deltaDistY = sqrt(1 + (rayDirX * rayDirX)/(rayDirY * rayDirY));
			int	stepX;
			int	stepY;
			int	hit = 0;
			int	side;
			float	perpWallDist;
			
			if (rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (rayPosX - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
			}
			if (rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (rayPosY - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
			}
			while (hit == 0)
			{
				if (sideDistX < sideDistY)
				{
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				}
				else
				{
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
				
				if (carte[mapX][mapY] > 0)
					hit = 1;
			}
			if (side == 0)
				perpWallDist = fabs((mapX - rayPosX + (1 - stepX) /2) / rayDirX);
			else
				perpWallDist = fabs((mapY - rayPosY + (1 - stepY) /2) / rayDirY);
			
			float	hauteurLigne = fabs(round(h / perpWallDist));
			int	drawStart = round(-hauteurLigne / 2 + h / 2);
			int	drawEnd = round(hauteurLigne / 2 + h / 2);
			if (drawStart < 0)
				drawStart = 0;
			if (drawEnd >= h)
				drawEnd = h - 1;
			int bpp;
			int size_line;
			int endian;
			char *img_data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
			y = drawStart;
			while (y < drawEnd)
			{
				int color = 200;
				if (side == 1)
					color = 0;
				int pi = (y * 1600 + x) * 4;
				img_data[pi] = color;
				img_data[pi + 1] = color;
				img_data[pi + 2] = color;
				img_data[pi + 3] = color;
				y++;
			}
		}
}

void	draw_walls(void  *mlx, void  *win, void  *img)
{
	int premAff = 1;
	
	float	w = 1600;
	float	h = 900;
	float	posX = 2;
	float	posY = 2;
	float	DirX = -1;
	float	DirY = 0;
	float	PlaneX = 0;
	float	PlaneY = 1;
	
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
	

	
	
	render(premAff, w, h, posX, posY, DirX, DirY, PlaneX, PlaneY, &img, carte);
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
