/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:36:02 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/13 18:37:03 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_cub(t_aff *aff, int pos, int color)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		aff->addr[pos + i] = color;
		aff->addr[pos + i + WIDTH] = color;
		aff->addr[pos + i + (WIDTH * 2)] = color;
		aff->addr[pos + i + (WIDTH * 3)] = color;
		aff->addr[pos + i + (WIDTH * 4)] = color;
		i++;
	}
}

void	ft_affi_cub(t_aff *aff, int color, int reset)
{
	static int	i = 0;
	static int	j = 0;

	if (reset == 1)
	{
		i = 0;
		j = 0;
		return ;
	}
	ft_print_cub(aff, i + j, color);
	i += 5;
	if (i >= 55)
	{
		i = 0;
		j += 5 * WIDTH;
	}
}

void	ft_mini_map2(t_aff *aff, int x, int y)
{
	while (x < (int)aff->pos_y + 6)
	{
		if (x < 0)
			ft_affi_cub(aff, 0xFFFFFFF, 0);
		else if (x < (int)aff->pos_y + 6 && !aff->info->map[y][x])
		{
			while (x < (int)aff->pos_y + 6 && x++ > -99)
				ft_affi_cub(aff, 0xFFFFFF, 0);
		}
		else if (x < (int)aff->pos_y + 6 && aff->info->map[y][x] == '1')
			ft_affi_cub(aff, 0x000000, 0);
		else
			ft_affi_cub(aff, 0xFFFFFF, 0);
		x++;
	}
}

void	ft_finish_y(t_aff *aff, int y)
{
	int	j;

	while (y < (int)aff->pos_x + 6)
	{
		j = 0;
		while (j < 11)
		{
			ft_affi_cub(aff, 0xFFFFFF, 0);
			j++;
		}
		y++;
	}
	ft_print_cub(aff, (25 + (5 * (5 * WIDTH))), 0x800080);
	ft_affi_cub(aff, 0x000000, 1);
}

void	ft_mini_map(t_aff *aff)
{
	int	y;
	int	j;

	y = (int)aff->pos_x - 5;
	while (y < (int)aff->pos_x + 5)
	{
		j = 0;
		if (y < 0)
		{
			while (j < 11)
			{
				ft_affi_cub(aff, 0xFFFFFF, 0);
				j++;
			}
		}
		else if (!aff->info->map[y])
			return (ft_finish_y(aff, y));
		else
			ft_mini_map2(aff, (int)aff->pos_y - 5, y);
		y++;
	}
	ft_print_cub(aff, (25 + (5 * (5 * WIDTH))), 0x800080);
	ft_affi_cub(aff, 0x000000, 1);
}
