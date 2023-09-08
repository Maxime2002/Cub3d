/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charg_color_img.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:44:37 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/07 15:23:13 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_verif_color_number(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '-')
		return (print_error_message(ERRCODE_NB_NEG_COLOR));
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	if (line[i] && line[i] != ' ' && line[i] != ',')
		return (print_error_message(ERRCODE_COLOR_NO));
	if (ft_count_number(line) > 3)
		return (print_error_message(ERRCODE_NB_MAX_COLOR));
	return (0);
}

int	ft_verif_size_color(char *line, int i)
{
	int	color;

	if (!line[i])
	{
		free(line);
		return (print_error_message_val(ERRCODE_COLOR_NO, -1));
	}
	if (ft_verif_color_number(line + i) == 1)
	{
		free(line);
		return (-1);
	}
	color = ft_atoi(line + i);
	if (color > 255)
		return (print_error_message_val(ERRCODE_NB_MAX_COLOR, -1));
	return (color);
}

int	ft_skip_space_comma_space(char *line, int i)
{
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] == ' ')
		i++;
	if (line[i] == ',')
		i++;
	while (line[i] == ' ')
		i++;
	return (i);
}

int	ft_charg_color(t_color *color, char *line)
{
	int	i;

	i = 1;
	while (line[i] == ' ')
		i++;
	color->r = ft_verif_size_color(line, i);
	if (color->r == -1)
		return (1);
	i = ft_skip_space_comma_space(line, i);
	color->g = ft_verif_size_color(line, i);
	if (color->g == -1)
		return (1);
	i = ft_skip_space_comma_space(line, i);
	color->b = ft_verif_size_color(line, i);
	if (color->b == -1)
		return (1);
	free(line);
	return (0);
}

int	ft_charg_img(t_img *img, char *line, t_info *info)
{
	int	i;

	i = 2;
	while (line[i] == ' ')
		i++;
	img->img = mlx_xpm_file_to_image(info->mlx, line + i, &img->w, &img->h);
	free(line);
	if (!img->img)
		return (print_error_message(ERRCODE_XPM_FILE));
	return (0);
}
