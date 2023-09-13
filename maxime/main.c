/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:56:48 by mlangloi          #+#    #+#             */
/*   Updated: 2023/09/12 14:24:33 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exit(t_aff *aff)
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

int	ft_mouse_move(int x, int y, t_aff *aff)
{
	if (x > WIDTH / 2)
	{
		ft_droite(aff);
	}
	else if (x < WIDTH / 2)
	{
		ft_gauche(aff);
	}
	x = WIDTH / 2;
	y = HEIGHT / 2;
	mlx_mouse_move(aff->info->mlx, aff->info->win, x, y);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	*info;
	t_aff	*aff;

	info = NULL;
	aff = NULL;
	if (ft_start(argc, argv, &info, &aff) == 1)
		return (1);
	spawn_player(aff);
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "cub3d");
	if (!info->win)
		return (ft_exit(aff));
	//mlx_mouse_hide(info->mlx, info->win);
	mlx_hook(info->win, 6, (1L << 6), ft_mouse_move, aff);
	mlx_hook(info->win, 2, 1, ft_controls, aff);
	aff->count = 0;
	ft_texture(aff);
	aff->addr = (int *)mlx_get_data_addr(aff->img, &aff->bpp,
			&aff->line_length, &aff->endian);
	mlx_loop_hook(info->mlx, (void *)ft_render, aff);
	mlx_hook(info->win, 17, 0, ft_exit, aff);
	mlx_loop(info->mlx);
	return (0);
}
