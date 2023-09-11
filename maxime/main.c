/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:56:48 by mlangloi          #+#    #+#             */
/*   Updated: 2023/09/11 19:40:15 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int ft_exit(t_aff *aff)
{
	mlx_destroy_image(aff->info->mlx, aff->img);
	if (aff->info->win)
	{
		mlx_clear_window(aff->info->mlx, aff->info->win);
		mlx_destroy_window(aff->info->mlx, aff->info->win);
	}
	ft_free_img(aff->info);
	ft_free_map(aff->info->map);
	mlx_destroy_display(aff->info->mlx);
	free(aff->info->mlx);
	free(aff->info);
	free(aff);
	exit(0);
	return (0);
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
	}
	
	if (touche == 65361)
	{
		double oldDirX = aff->dirX;
	      	aff->dirX = aff->dirX * cos((0.033 * 1.8) / 2) - aff->dirY * sin((0.033 * 1.8) / 2);
	      	aff->dirY = oldDirX * sin((0.033 * 1.8) / 2) + aff->dirY * cos((0.033 * 1.8) / 2);
		double oldPlaneX = aff->planX;
		aff->planX = aff->planX * cos((0.033 * 1.8) / 2) - aff->planY * sin((0.033 * 1.8) / 2);
		aff->planY = oldPlaneX * sin((0.033 * 1.8) / 2) + aff->planY * cos((0.033 * 1.8) / 2);
	}
	if (touche == 119)
	{
		if (aff->info->map[(int)(aff->posX + (aff->dirX * 0.1 * 2))][(int)aff->posY] != '1')
			aff->posX += aff->dirX * 0.1;
		if (aff->info->map[(int)(aff->posX)][(int)(aff->posY + (aff->dirY * 0.1 * 2))] != '1')
			aff->posY += aff->dirY * 0.1;
	}
	if (touche == 115)
	{
		if (aff->info->map[(int)(aff->posX - (aff->dirX * 0.1 * 2))][(int)(aff->posY)] != '1')
			aff->posX -= aff->dirX * 0.1;
		if (aff->info->map[(int)(aff->posX)][(int)(aff->posY - (aff->dirY * 0.1 * 2))] != '1')
			aff->posY -= aff->dirY * 0.1;
	}
	if (touche == 100)
	{	
		if (aff->info->map[(int)(aff->posX + aff->dirY * (0.1 * 2))][(int)aff->posY] != '1')
			aff->posX += aff->dirY * 0.1;
		if (aff->info->map[(int)aff->posX][(int)(aff->posY - aff->dirX * (0.1 * 2))] != '1')
			aff->posY -= aff->dirX * 0.1;
	}
	if (touche == 97)
	{
		if (aff->info->map[(int)(aff->posX - aff->dirY * (0.1 * 2))][(int)aff->posY] != '1')
			aff->posX -= aff->dirY * 0.1;
		if (aff->info->map[(int)aff->posX][(int)(aff->posY + aff->dirX * (0.1 * 2))] != '1')
			aff->posY += aff->dirX * 0.1;
	}
	if (touche == 65307)
		ft_exit(aff);
	return (0);
}

int main (int argc, char **argv)
{
	t_info*info;
	t_aff	*aff;
	
	info = NULL;
	aff = NULL;
	if (ft_start(argc, argv, &info, &aff) == 1)
		return (1);
	spawn_player(aff);
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "cub3d");
	if (!info->win)
		return (ft_exit(aff));
	mlx_key_hook(info->win, ft_controls, aff);
	ft_texture(aff);
	aff->addr = (int *)mlx_get_data_addr(aff->img, &aff->
			bpp, &aff->line_length, &aff->endian);
	mlx_loop_hook(info->mlx, (void *)ft_render, aff);
	mlx_hook(info->win, 17, 0, ft_exit, aff);
	mlx_loop(info->mlx);
	return (0);
}
