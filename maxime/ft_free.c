/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:59:25 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/14 14:28:48 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_img_sprites(t_info *info)
{
	if (info->r.img != NULL)
		mlx_destroy_image(info->mlx, info->r.img);
	if (info->s.img != NULL)
		mlx_destroy_image(info->mlx, info->s.img);
	if (info->sp.img != NULL)
		mlx_destroy_image(info->mlx, info->sp.img);
	if (info->spr.img != NULL)
		mlx_destroy_image(info->mlx, info->spr.img);
	if (info->spri.img != NULL)
		mlx_destroy_image(info->mlx, info->spri.img);
}

int	ft_free_img(t_info *info)
{
	if (info->no.img != NULL)
		mlx_destroy_image(info->mlx, info->no.img);
	if (info->so.img != NULL)
		mlx_destroy_image(info->mlx, info->so.img);
	if (info->we.img != NULL)
		mlx_destroy_image(info->mlx, info->we.img);
	if (info->ea.img != NULL)
		mlx_destroy_image(info->mlx, info->ea.img);
	if (info->door.img != NULL)
		mlx_destroy_image(info->mlx, info->door.img);
	ft_free_img_sprites(info);
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
