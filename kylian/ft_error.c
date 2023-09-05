/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:05:50 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/05 19:17:16 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_error(char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		write(2, &src[i], 1);
}

int	print_error_message(int error_code)
{
	if (error_code == ERRCODE_MALLOC)
		ft_print_error(ERRMSG_MALLOC);
	else if (error_code == ERRCODE_NB_ARG)
		ft_print_error(ERRMSG_NB_ARG);
	else if (error_code == ERRCODE_OPEN)
		ft_print_error(ERRMSG_OPEN);
	else if (error_code == ERRCODE_CUB)
		ft_print_error(ERRMSG_CUB);
	else if (error_code == ERRCODE_READ)
		ft_print_error(ERRMSG_READ);
	else if (error_code == ERRCODE_MAP_VOID)
		ft_print_error(ERRMSG_MAP_VOID);
	return (1);
}

void	*print_error_message_null(int error_code)
{
	print_error_message(error_code);
	return (NULL);
}
