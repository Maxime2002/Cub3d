/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:59:33 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/07 15:23:58 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void Print_map(char **dest)
{
	int i;
	int j;
	
	i = 0;
	while(dest[i])
	{
		j = -1;
		while(dest[i][++j])
			write(1, &dest[i][j], 1);
		write(1, "\n", 1);
		i++;
	}
}

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
	ft_free_img(info);
	//Print_map(info->map);
	/*
	printf("ground --------\nr: %d\ng: %d\nb: %d\n\n", info->ground.r, info->ground.g, info->ground.b);
	printf("celing --------\nr: %d\ng: %d\nb: %d\n\n", info->ceiling.r, info->ceiling.g ,info->ceiling.b);
	*/
	ft_free_map(info->map);
	mlx_destroy_display(info->mlx);
	free(info->mlx);
	free(info);
	(void) info;
	return (0);
}