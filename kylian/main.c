/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:59:33 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/06 20:38:54 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main (int argc, char **argv)
{
	t_info*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (print_error_message(ERRCODE_MALLOC));
	info->mlx = mlx_init();
	//erreur mlx non gerer encore
	if (ft_parsing(argc, argv, info) == 1)
	{
		mlx_destroy_display(info->mlx);
		free(info->mlx);
		free(info);
		return (1);
	}
	write(1, "e", 1);
	mlx_destroy_display(info->mlx);
	free(info->mlx);
	ft_free_img(info);
	ft_free_map(info);
	free (info);
	(void) info;
	return (0);
}