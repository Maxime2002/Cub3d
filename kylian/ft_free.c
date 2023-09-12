/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:59:25 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/12 15:50:17 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_free_img(t_info *info)
{
	if (info->door.img != NULL)
		mlx_destroy_image(info->mlx, info->door.img);
	if (info->no.img != NULL)
		mlx_destroy_image(info->mlx, info->no.img);
	if (info->so.img != NULL)
		mlx_destroy_image(info->mlx, info->so.img);
	if (info->we.img != NULL)
		mlx_destroy_image(info->mlx, info->we.img);
	if (info->ea.img != NULL)
		mlx_destroy_image(info->mlx, info->ea.img);
	return (1);
}

int	ft_free_map(char **map)
{
	int	i;

	i = -1;
	if (!map)
		return (1);
	while (map[++i])
		free(map[i]);
	free(map);
	return (1);
}
