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



int ft_exit(t_aff *aff)
{
	mlx_destroy_image(aff->info->mlx, aff->img);
	mlx_clear_window(aff->info->mlx, aff->info->win);
	mlx_destroy_window(aff->info->mlx, aff->info->win);
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
	if (touche == 100)
	{
		printf("test ; %c\n", aff->info->map[(int)aff->posX + (int)aff->dirY * (int)0.11][(int)aff->posY]);
		if (aff->info->map[(int)aff->posX + (int)aff->dirY * (int)0.11][(int)aff->posY] != '1')
			aff->posX += aff->dirY * 0.11;
		if (aff->info->map[(int)aff->posX][(int)aff->posY + (int)aff->dirX * (int)0.11] != '1')
			aff->posY -= aff->dirX * 0.11;
	}
	if (touche == 97)
	{
		printf("test ; %c\n", aff->info->map[(int)aff->posX + (int)aff->dirY * (int)0.11][(int)aff->posY]);
		if (aff->info->map[(int)aff->posX + (int)aff->dirY * (int)0.11][(int)aff->posY] != '1')
			aff->posX -= aff->dirY * 0.11;
		if (aff->info->map[(int)aff->posX][(int)aff->posY + (int)aff->dirX * (int)0.11] != '1')
			aff->posY += aff->dirX * 0.11;
	}
	if (touche == 119)
	{
		if (aff->info->map[(int)aff->posX + (int)aff->dirX * (int)0.11][(int)aff->posY] != '1')
			aff->posX += aff->dirX * 0.11;
		if (aff->info->map[(int)aff->posX][(int)aff->posY + (int)aff->dirY * (int)0.11] != '1')
			aff->posY += aff->dirY * 0.11;
	}
	if (touche == 115)
	{
		if (aff->info->map[(int)aff->posX - (int)aff->dirX * (int)0.11][(int)aff->posY] != '1')
			aff->posX -= aff->dirX * 0.11;
		if (aff->info->map[(int)aff->posX][(int)aff->posY - (int)aff->dirY * (int)0.11] != '1')
			aff->posY -= aff->dirY * 0.11;
	}
	if (touche == 65307)
		ft_exit(aff);
	return (0);
}



void	spawn_dir(t_aff *aff, char player)
{
	if (player == 'N')
	{
		aff->dirX = -1;
		aff->planY = 0.66;
	}
	if (player == 'S')
	{
		aff->dirX = 1;
		aff->planY = -0.66;
	}
	if (player == 'E')
	{
		aff->dirY = 1;
		aff->planX = 0.66;
	}
	if (player == 'W')
	{
		aff->dirY = -1;
		aff->planX = -0.66;
	}
}

void spawn_player(t_aff *aff)
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
	aff->posX += i;
	aff->posY += j;
	spawn_dir(aff, aff->info->map[i][j]);
	
}




void	ft_init_aff(t_aff *aff, t_info *info)
{
	aff->planX = 0;
	aff->planY = 0;
	aff->dirX = 0;
	aff->dirY = 0;
	aff->info = info;
	
	aff->posX = 0.5;
	aff->posY = 0.5;
	aff->w = WIDTH;
	aff->h = HEIGHT;
	
	aff->c = 0x000000;
	aff->f = 0x000000;
}



int main (int argc, char **argv)
{
	t_info*info;
	t_aff	*aff;
	
	info = malloc(sizeof(t_info));
	if (!info)
		return (print_error_message(ERRCODE_MALLOC));
	aff = malloc(sizeof(t_aff));
	if (!aff)
		return (print_error_message(ERRCODE_MALLOC));
	ft_init_aff(aff, info);
	info->mlx = mlx_init();
	//erreur mlx non gerer encore
	if (ft_parsing(argc, argv, info) == 1)
	{
		mlx_destroy_display(info->mlx);
		free(info->mlx);
		free(info);
		return (1);
	}
	//ft_free_img(info);
	
	
	
	spawn_player(aff);
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "cub3d");
	
	
	mlx_key_hook(info->win, ft_controls, aff);
	
	
	
	ft_texture(aff);
	aff->img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	aff->addr = (int *)mlx_get_data_addr(aff->img, &aff->
			bpp, &aff->line_length, &aff->endian);


	mlx_loop_hook(info->mlx, (void *)ft_render, aff);
	mlx_hook(info->win, 17, 0, ft_exit, aff);
	mlx_loop(info->mlx);
	return (0);
}



