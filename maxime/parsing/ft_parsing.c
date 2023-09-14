/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:32:15 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/14 14:08:45 by kyaubry          ###   ########.fr       */
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

int	ft_parsing(int argc, char **argv, t_info *info)
{
	int	fd;

	if (argc != 2)
		return (print_error_message(ERRCODE_NB_ARG));
	if (ft_check_cub_extension(argv[1]) == 1)
		return (print_error_message(ERRCODE_CUB));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (print_error_message(ERRCODE_OPEN));
	if (ft_init_map_and_arg(fd, info) == 1)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
