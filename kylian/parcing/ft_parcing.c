/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:45:09 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/05 14:52:19 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_info *ft_parcing(int argc, char **argv)
{
	if (argc != 2)
		return (print_error_message_void(ERRCODE_NB_ARG));
	(void) argv;
	return (NULL);
}