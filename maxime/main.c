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
#include<math.h>
#include<string.h>

float	normalizeX(float x, float y)
{
	float length;
	length = sqrt(x *x +y * y);
	return (x / length);
}

float	normalizeY(float x, float y)
{
	float length;
	length = sqrt(x *x +y * y);
	return (y / length);
}

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
		if (aff->rayDirX == 0)
			aff->deltaDistX = 1e30;
		else
			aff->deltaDistX = absolute(1 / aff->rayDirX);
		if (aff->rayDirY == 0)
			aff->deltaDistY = 1e30;
		else
			aff->deltaDistY = absolute(1 / aff->rayDirY);
		aff->hit = 0;
		
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
			if (aff->worldMap[aff->mapX][aff->mapY] > 0)
				aff->hit = 1;
		} 
		if (aff->side == 0)
			aff->perpWallDist = (aff->sideDistX - aff->deltaDistX);
		else
			aff->perpWallDist = (aff->sideDistY - aff->deltaDistY);

		aff->lineHeight = (int)((double)aff->h / aff->perpWallDist);

		aff->drawStart = -aff->lineHeight / 2 + (double)aff->h / 2;
		if(aff->drawStart < 0)
			aff->drawStart = 0;
		aff->drawEnd = aff->lineHeight / 2 + (double)aff->h / 2;
		if(aff->drawEnd >= (double)aff->h)
			aff->drawEnd = (double)aff->h - 1;
			
		int color;
		switch(aff->worldMap[aff->mapX][aff->mapY])
		{
			case 1:  color = 0xFF0000;  break;
			case 2:  color = 0x43ff00;  break;
			case 3:  color = 0x001dff;   break;
			case 4:  color = 0xFFFF00;  break;
			default: color = 0xffe900; break;
		}

		     

		verLine(x, aff->drawStart, aff->drawEnd, color, aff->mlx, aff->win);		
	}
			
		
}

int	ft_controls(int touche, t_aff *aff)
{
	if (touche == 65361)
	{
		double oldDirX = aff->dirX;
	      	aff->dirX = aff->dirX * cos(-(0.033 * 1.8) / 2) - aff->dirY * sin(-(0.033 * 1.8) / 2);
	      	aff->dirY = oldDirX * sin(-(0.033 * 1.8) / 2) + aff->dirY * cos(-(0.033 * 1.8) / 2);
		double oldPlaneX = aff->planX;
		aff->planX = aff->planX * cos(-(0.033 * 1.8) / 2) - aff->planY * sin(-(0.033 * 1.8) / 2);
		aff->planY = oldPlaneX * sin(-(0.033 * 1.8) / 2) + aff->planY * cos(-(0.033 * 1.8) / 2);
		
		printf("%f %f\n", aff->posX, aff->posY);
	}
	
	if (touche == 65363)
	{
		double oldDirX = aff->dirX;
	      	aff->dirX = aff->dirX * cos((0.033 * 1.8) / 2) - aff->dirY * sin((0.033 * 1.8) / 2);
	      	aff->dirY = oldDirX * sin((0.033 * 1.8) / 2) + aff->dirY * cos((0.033 * 1.8) / 2);
		double oldPlaneX = aff->planX;
		aff->planX = aff->planX * cos((0.033 * 1.8) / 2) - aff->planY * sin((0.033 * 1.8) / 2);
		aff->planY = oldPlaneX * sin((0.033 * 1.8) / 2) + aff->planY * cos((0.033 * 1.8) / 2);
		
		printf("%f %f\n", aff->posX, aff->posY);
	}
	if (touche == 97)
	{
		aff->posY -= 0.2;
		//ft_render(aff);
		printf("%f %f\n", aff->posX, aff->posY);
	}
	if (touche == 100)
	{
		aff->posY += 0.2;
		//ft_render(aff);
		printf("%f %f\n", aff->posX, aff->posY);
	}
	if (touche == 119)
	{
		if (aff->worldMap[(int)aff->posX + (int)aff->dirX * (int)0.1][(int)aff->posY] == 0)
			aff->posX += aff->dirX * 0.1;
		if (aff->worldMap[(int)aff->posX][(int)aff->posY + (int)aff->dirY * (int)0.1] == 0)
			aff->posX += aff->dirX * 0.1;
		//ft_render(aff);
		printf("test %f %f\n", aff->posX, aff->posY);
	}
	if (touche == 115)
	{
		aff->posX -= 0.2;
		//ft_render(aff);
		printf("%f %f\n", aff->posX, aff->posY);
	}
	ft_render(aff);
	return (0);
}

int main (int ac, char **av)
{
	(void)ac;
	(void)av;
	void	*mlx;
	void	*win;
	
	
	t_aff	*aff;
	aff = malloc(sizeof(t_aff));
	
	
	int worldMap[8][8]=
	{
	  {1,1,1,1,1,1,1,1},
	  {1,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,1},
	  {1,0,0,2,2,2,2,1},
	  {1,0,0,0,0,0,0,1},
	  {1,1,2,3,4,1,1,1}
	};
	
	memcpy(aff->worldMap, worldMap, 8 * 8 * sizeof(int));
	
	aff->posX = 3.5;
	aff->posY = 3.5;
	aff->orientation = 0;
	aff->planX = 0;
	aff->planY = 1;
	aff->dirX = 1;
	aff->dirY = 0;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 480, "cub3d");
	mlx_key_hook(win, ft_controls, aff);
	aff->mlx = mlx;
	aff->win = win;
	aff->w = 640;
	aff->h = 480;
	
	
	
	
	ft_render(aff);
	
	mlx_loop(mlx);
	return (0);
}
