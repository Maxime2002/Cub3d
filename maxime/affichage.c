/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:12:09 by mlangloi          #+#    #+#             */
/*   Updated: 2023/09/11 18:12:10 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_texture(t_aff *aff, int x, int y, t_img *texture)
{
	y = aff->drawStart - 1;
	aff->t.step = 1.0 * aff->info->so.h / aff->lineHeight;
	aff->t.texx = (int)(aff->t.wallx * (double)texture->w);
	if (aff->side == 0 && aff->rayDirX > 0)
		aff->t.texx = texture->w - aff->t.texx - 1;
	if (aff->side == 1 && aff->rayDirY < 0)
		aff->t.texx = texture->w - aff->t.texx - 1;
	aff->t.texpos = (aff->drawStart - aff->h / 2
			+ aff->lineHeight / 2) * aff->t.step;
	while (++y <= aff->drawEnd)
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
		aff->t.wallx = aff->posY + aff->perpWallDist \
						* aff->rayDirY;
	else
		aff->t.wallx = aff->posX + aff->perpWallDist \
						* aff->rayDirX;
	aff->t.wallx -= floor((aff->t.wallx));
	if (aff->side == 0 && aff->rayDirX < 0)
		ft_draw_texture(aff, x, y, &aff->info->so);
	if (aff->side == 0 && aff->rayDirX >= 0)
		ft_draw_texture(aff, x, y, &aff->info->no);
	if (aff->side == 1 && aff->rayDirY < 0)
		ft_draw_texture(aff, x, y, &aff->info->ea);
	if (aff->side == 1 && aff->rayDirY >= 0)
		ft_draw_texture(aff, x, y, &aff->info->we);
}

int	ft_color_column(t_aff *aff, int x)
{
	int	j;
	int	i;

	j = -1;
	aff->drawEnd = aff->h - aff->drawStart;
	i = aff->drawEnd;
	while (++j < aff->drawStart)
		aff->addr[j * aff->line_length / 4
			+ x] = aff->c;
	if (j <= aff->drawEnd)
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
}
