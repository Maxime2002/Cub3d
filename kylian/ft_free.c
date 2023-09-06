/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:59:25 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/06 18:59:27 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_free_img(t_info *info)
{
	if (info->no.img)
		mlx_destroy_image(info->mlx, info->no.img);
	if (info->so.img)
		mlx_destroy_image(info->mlx, info->so.img);
	if (info->we.img)
		mlx_destroy_image(info->mlx, info->we.img);
	if (info->ea.img)
		mlx_destroy_image(info->mlx, info->ea.img);
	return (1);
}

int ft_free_map(t_info *info)
{
	int i;

	i = -1;
	if (!info->map)
		return (1);
	while (!info->map[++i])
		free(info->map[i]);
	free(info->map);
	return (1);
}
