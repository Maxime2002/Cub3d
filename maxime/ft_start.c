/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:36:55 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/11 19:54:38 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int		ft_init_aff(t_aff *aff, t_info *info)
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

	aff->c = (0 << 24 | info->ceiling.r << 16 | info->ceiling.g << 8 | info->ceiling.b);
	//printf("ccccccc: %d\n", aff->c);
	aff->f = (0 << 24 | info->ground.r << 16 | info->ground.g << 8 | info->ground.b);
	//printf("fffffff: %d\n", aff->f);
	aff->img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	if (!aff->img)
	{
		ft_free_img(aff->info);
		ft_free_map(aff->info->map);
		mlx_destroy_display(aff->info->mlx);
		free(aff->info->mlx);
		free(aff->info);
		free(aff);
		return(print_error_message(ERRCODE_NEW_IMAGE));
	}
	return (0);
}

int ft_start(int argc, char **argv, t_info **info, t_aff **aff)
{
	*info = malloc(sizeof(t_info));
	if (!*info)
		return (print_error_message(ERRCODE_MALLOC));
	*aff = malloc(sizeof(t_aff));
	if (!*aff)
	{
		free(*info);
		return (print_error_message(ERRCODE_MALLOC));
	}
	(*info)->mlx = mlx_init();
	if (!(*info)->mlx)
	{
		free(*aff);
		free(*info);
		return (print_error_message(ERRCODE_MLX));
	}
	if (ft_parsing(argc, argv, *info) == 1)
	{
		free(*aff);
		mlx_destroy_display((*info)->mlx);
		free((*info)->mlx);
		free(*info);
		return (1);
	}
	return (ft_init_aff(*aff, *info));
}
