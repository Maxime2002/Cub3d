/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:59:33 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/11 14:41:57 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	Print_map(char **dest)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
	{
		j = -1;
		while (dest[i][++j])
			write(1, &dest[i][j], 1);
		write(1, "\n", 1);
		i++;
	}
}

int ft_exit(t_game *game)
{
	mlx_clear_window(game->info->mlx, game->info->win);
	mlx_destroy_window(game->info->mlx, game->info->win);
	ft_free_img(game->info);
	ft_free_map(game->info->map);
	mlx_destroy_display(game->info->mlx);
	free(game->info->mlx);
	free(game->info);
	free(game);
	exit(0);
	return (0);
}

int ft_render(t_game *game)
{
	(void) game;
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	*info;
	t_game	*game;

	info = NULL;
	game = NULL;
	if (ft_start(argc, argv, &info, &game) == 1)
		return (1);
	ft_give_value(info, game);
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "Cub3d");
	if (info->win)
	{
		mlx_hook(info->win, 17, 0, ft_exit, game);
		mlx_loop_hook(info->mlx, ft_render, game);
		mlx_loop(info->mlx);
	}
	ft_free_img(info);
	ft_free_map(info->map);
	mlx_destroy_display(info->mlx);
	free(info->mlx);
	free(game);
	free(info);
	return (0);
}
