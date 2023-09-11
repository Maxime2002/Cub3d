/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:41:25 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/11 14:45:46 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_start(int argc, char **argv, t_info **info, t_game **game)
{
	*info = malloc(sizeof(t_info));
	if (!*info)
		return (print_error_message(ERRCODE_MALLOC));
	*game = malloc(sizeof(t_game));
	if (!*game)
	{
		free(*info);
		return (print_error_message(ERRCODE_MALLOC));
	}
	(*info)->mlx = mlx_init();
	if (!(*info)->mlx)
	{
		free(*game);
		free(*info);
		return (print_error_message(ERRCODE_MLX));
	}
	if (ft_parsing(argc, argv, *info) == 1)
	{
		free(*game);
		mlx_destroy_display((*info)->mlx);
		free((*info)->mlx);
		free(*info);
		return (1);
	}
	return (0);
}

void ft_give_directions(t_game *game, char c)
{
	game->dirX = 0;
	game->dirY = 0;
	if (c == 'N')
		game->dirY = -1;
	else if (c == 'S')
		game->dirY = 1;
	else if (c == 'W')
		game->dirX = -1;
	else
		game->dirX = 1;
}

void ft_give_value(t_info *info, t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (info->map[i])
	{
		j = -1;
		while (info->map[i][++j])
			if (info->map[i][j] == 'N' || info->map[i][j] == 'S'
				|| info->map[i][j] == 'E' || info->map[i][j] == 'W')
				break ;
		if (info->map[i][j] != '\0')
			break ;
		i++;
	}
	game->info = info;
	game->posX = j + 0.5;
	game->posY = i + 0.5;
	return (ft_give_directions(game, info->map[i][j]));
}
