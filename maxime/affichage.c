/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:12:09 by mlangloi          #+#    #+#             */
/*   Updated: 2023/09/12 15:12:14 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_texture(t_aff *aff, int x, int y, t_img *texture)
{
	y = aff->draw_start - 1;
	aff->t.step = 1.0 * aff->info->so.h / aff->line_height;
	aff->t.texx = (int)(aff->t.wallx * (double)texture->w);
	if (aff->side == 0 && aff->ray_dir_x > 0)
		aff->t.texx = texture->w - aff->t.texx - 1;
	if (aff->side == 1 && aff->ray_dir_y < 0)
		aff->t.texx = texture->w - aff->t.texx - 1;
	aff->t.texpos = (aff->draw_start - aff->h / 2
			+ aff->line_height / 2) * aff->t.step;
	while (++y <= aff->draw_end)
	{
		aff->t.texy = (int)aff->t.texpos
			& (texture->h - 1);
		aff->t.texpos += aff->t.step;
		if (y < aff->h && x < aff->w)
			aff->addr[y * aff->line_length / 4 + x]
				= texture->addr[aff->t.texy
				* texture->line_length
				/ 4 + aff->t.texx];
	}
}

void	ft_init_texture(t_aff *aff, int x, int y)
{
	if (aff->side == 0)
		aff->t.wallx = aff->pos_y + aff->perp_wall_dist
			* aff->ray_dir_y;
	else
		aff->t.wallx = aff->pos_x + aff->perp_wall_dist
			* aff->ray_dir_x;
	aff->t.wallx -= floor((aff->t.wallx));
	if (aff->let == 'P')
		ft_draw_texture(aff, x, y, &aff->info->door);
	/*if (aff->let == 'S')
		ft_sprites(aff, x, y);*/
	else if (aff->side == 0 && aff->ray_dir_x < 0)
		ft_draw_texture(aff, x, y, &aff->info->so);
	else if (aff->side == 0 && aff->ray_dir_x >= 0)
		ft_draw_texture(aff, x, y, &aff->info->no);
	else if (aff->side == 1 && aff->ray_dir_y < 0)
		ft_draw_texture(aff, x, y, &aff->info->ea);
	else if (aff->side == 1 && aff->ray_dir_y >= 0)
		ft_draw_texture(aff, x, y, &aff->info->we);
}

int	ft_color_column(t_aff *aff, int x)
{
	int	j;
	int	i;

	j = -1;
	aff->draw_end = aff->h - aff->draw_start;
	i = aff->draw_end;
	while (++j < aff->draw_start)
		aff->addr[j * aff->line_length / 4
			+ x] = aff->c;
	if (j <= aff->draw_end)
		ft_init_texture(aff, x, j);
	j = i;
	while (++j < aff->h)
		aff->addr[j * aff->line_length / 4
			+ x] = aff->f;
	return (0);
}

void	ft_texture(t_aff *aff)
{
	aff->info->no.addr = (int *)mlx_get_data_addr(aff->info->no.img,
			&aff->info->no.bpp,
			&aff->info->no.line_length, &aff->info->no.endian);
	aff->info->so.addr = (int *)mlx_get_data_addr(aff->info->so.img,
			&aff->info->so.bpp,
			&aff->info->so.line_length, &aff->info->so.endian);
	aff->info->we.addr = (int *)mlx_get_data_addr(aff->info->we.img,
			&aff->info->we.bpp,
			&aff->info->we.line_length, &aff->info->we.endian);
	aff->info->ea.addr = (int *)mlx_get_data_addr(aff->info->ea.img,
			&aff->info->ea.bpp,
			&aff->info->ea.line_length, &aff->info->ea.endian);
	aff->info->door.addr = (int *)mlx_get_data_addr(aff->info->door.img,
			&aff->info->door.bpp,
			&aff->info->door.line_length, &aff->info->door.endian);
	ft_init_sprites(aff);
}
