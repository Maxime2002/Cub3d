/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:45:09 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/05 19:14:58 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_cub_extension(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	while (i > 0 && (argv[i] == ' ' || argv[i] == '\t'))
		i--;
	if (i <= 4)
		return (1);
	if (argv[i - 1] != 'b' || argv[i - 2] != 'u' || argv[i - 3] != 'c'
		|| argv[i - 4] != '.')
		return (1);
	return (0);
}

t_info	*ft_parcing(int argc, char **argv)
{
	int		fd;
	t_info	*info;

	if (argc != 2)
		return (print_error_message_null(ERRCODE_NB_ARG));
	if (ft_check_cub_extension(argv[1]) == 1)
		return (print_error_message_null(ERRCODE_CUB));
	info = malloc(sizeof(t_info));
	if (!info)
		return (print_error_message_null(ERRCODE_MALLOC));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		free(info);
		return (print_error_message_null(ERRCODE_OPEN));
	}
	if (ft_init_map_and_arg(fd, info) == 1)
	{
		free(info);
		info = NULL;
	}
	close(fd);
	return (info);
}
