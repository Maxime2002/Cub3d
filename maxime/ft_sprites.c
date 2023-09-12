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
	aff->info->sprit.addr = (int *)mlx_get_data_addr(aff->info->sprit.img,
			&aff->info->sprit.bpp,
			&aff->info->sprit.line_length, &aff->info->sprit.endian);
	aff->info->sprite.addr = (int *)mlx_get_data_addr(aff->info->sprite.img,
			&aff->info->sprite.bpp,
			&aff->info->sprite.line_length, &aff->info->sprite.endian);
	aff->info->sprites.addr = (int *)mlx_get_data_addr(aff->info->sprites.img,
			&aff->info->sprites.bpp,
			&aff->info->sprites.line_length, &aff->info->sprites.endian);
}

void	ft_init_sprites(t_aff *aff)
{
	aff->info->r.img = mlx_xpm_file_to_image(aff->info->mlx,
			"./asset/r.xpm", &aff->info->r.w, &aff->info->r.w);
	aff->info->s.img = mlx_xpm_file_to_image(aff->info->mlx,	
			"./asset/S.xpm", &aff->info->s.w, &aff->info->s.w);	
	aff->info->sp.img = mlx_xpm_file_to_image(aff->info->mlx,
			"./asset/Sp.xpm", &aff->info->sp.w, &aff->info->sp.w);
	aff->info->spr.img = mlx_xpm_file_to_image(aff->info->mlx,
			"./asset/Spr.xpm", &aff->info->spr.w, &aff->info->spr.w);	
	aff->info->spri.img = mlx_xpm_file_to_image(aff->info->mlx,
			"./asset/Spri.xpm", &aff->info->spri.w, &aff->info->spri.w);		
	aff->info->sprit.img = mlx_xpm_file_to_image(aff->info->mlx,
			"./asset/Sprit.xpm", &aff->info->sprit.w, &aff->info->sprit.w);		
	aff->info->sprite.img = mlx_xpm_file_to_image(aff->info->mlx,
			"./asset/Sprite.xpm", &aff->info->sprite.w, &aff->info->sprite.w);				
	aff->info->sprites.img = mlx_xpm_file_to_image(aff->info->mlx,
			"./asset/Sprites.xpm", &aff->info->sprites.w, &aff->info->sprites.w);
	ft_init_sprites2(aff);
}

/*
void	ft_sprites(t_aff *aff, int x, int y)
{
	if (aff->count <= 10000)
		ft_draw_texture(aff, x, y, &aff->info->r);
	if (aff->count > 10000 && aff->count <= 20000)
		ft_draw_texture(aff, x, y, &aff->info->s);
	if (aff->count > 20000 && aff->count <= 30000)
		ft_draw_texture(aff, x, y, &aff->info->sp);
	if (aff->count > 30000 && aff->count <= 40000)
		ft_draw_texture(aff, x, y, &aff->info->spr);
	if (aff->count > 40000 && aff->count <= 50000)
		ft_draw_texture(aff, x, y, &aff->info->spri);
	if (aff->count > 50000 && aff->count <= 60000)
		ft_draw_texture(aff, x, y, &aff->info->sprit);
	if (aff->count > 60000 && aff->count <= 70000)
		ft_draw_texture(aff, x, y, &aff->info->sprite);
	if (aff->count > 70000 && aff->count <= 80000)
		ft_draw_texture(aff, x, y, &aff->info->sprites);
	aff->count++;
	if (aff->count == 80001)
		aff->count = 0;
}*/
