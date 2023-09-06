/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:05:50 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/06 12:44:11 by kyaubry          ###   ########.fr       */
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
	else if (error_code == ERRCODE_XPM_FILE)
		ft_print_error(ERRMSG_XPM_FILE);
	else if (error_code == ERRCODE_NB_MAX_COLOR)
		ft_print_error(ERRMSG_NB_MAX_COLOR);
	else if (error_code == ERRCODE_NB_NEG_COLOR)
		ft_print_error(ERRMSG_NB_NEG_COLOR);
	else if (error_code == ERRCODE_COLOR_NO)
		ft_print_error(ERRMSG_COLOR_NO);
	return (1);
}

void	*print_error_message_null(int error_code)
{
	print_error_message(error_code);
	return (NULL);
}

int	print_error_message_val(int error_code, int code)
{
	print_error_message(error_code);
	return (code);
}
