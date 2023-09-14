/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:16:22 by mlangloi          #+#    #+#             */
/*   Updated: 2023/09/12 20:16:24 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_lettre(t_aff *aff)
{
	if (aff->info->map[aff->map_x][aff->map_y] == '1')
	{
		aff->hit = 1;
		aff->let = '1';
	}
	if (aff->info->map[aff->map_x][aff->map_y] == 'P')
	{
		aff->hit = 1;
		aff->let = 'P';
	}
	if (aff->info->map[aff->map_x][aff->map_y] == 'X')
	{
		aff->hit = 1;
		aff->let = 'X';
	}
}

void	ft_init_sprites2(t_aff *aff)
{
	aff->info->r.addr = (int *)mlx_get_data_addr(aff->info->r.img,
			&aff->info->r.bpp,
			&aff->info->r.line_length, &aff->info->r.endian);
	aff->info->s.addr = (int *)mlx_get_data_addr(aff->info->s.img,
			&aff->info->s.bpp,
			&aff->info->s.line_length, &aff->info->s.endian);
	aff->info->sp.addr = (int *)mlx_get_data_addr(aff->info->sp.img,
			&aff->info->sp.bpp,
			&aff->info->sp.line_length, &aff->info->sp.endian);
	aff->info->spr.addr = (int *)mlx_get_data_addr(aff->info->spr.img,
			&aff->info->spr.bpp,
			&aff->info->spr.line_length, &aff->info->spr.endian);
	aff->info->spri.addr = (int *)mlx_get_data_addr(aff->info->spri.img,
			&aff->info->spri.bpp,
			&aff->info->spri.line_length, &aff->info->spri.endian);
}

void	ft_init_sprites(t_aff *aff)
{
	aff->info->r.img = mlx_xpm_file_to_image(aff->info->mlx,
			"./asset/r.xpm", &aff->info->r.w, &aff->info->r.h);
	aff->info->s.img = mlx_xpm_file_to_image(aff->info->mlx,
			"./asset/S.xpm", &aff->info->s.w, &aff->info->s.h);
	aff->info->sp.img = mlx_xpm_file_to_image(aff->info->mlx,
			"./asset/Sp.xpm", &aff->info->sp.w, &aff->info->sp.h);
	aff->info->spr.img = mlx_xpm_file_to_image(aff->info->mlx,
			"./asset/Spr.xpm", &aff->info->spr.w, &aff->info->spr.h);
	aff->info->spri.img = mlx_xpm_file_to_image(aff->info->mlx,
			"./asset/Spri.xpm", &aff->info->spri.w, &aff->info->spri.h);
	ft_init_sprites2(aff);
}

void	ft_sprites(t_aff *aff, int x, int y)
{
	if (aff->count <= 1000)
		ft_draw_texture(aff, x, y, &aff->info->r);
	if (aff->count > 1000 && aff->count <= 2000)
		ft_draw_texture(aff, x, y, &aff->info->s);
	if (aff->count > 2000 && aff->count <= 3000)
		ft_draw_texture(aff, x, y, &aff->info->sp);
	if (aff->count > 3000 && aff->count <= 4000)
		ft_draw_texture(aff, x, y, &aff->info->spr);
	if (aff->count > 4000 && aff->count <= 5000)
		ft_draw_texture(aff, x, y, &aff->info->spri);
}
