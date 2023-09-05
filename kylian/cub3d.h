/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:02:01 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/05 14:07:34 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ==================== error ==================== */

# define ERRCODE_MALLOC 1
# define ERRMSG_MALLOC "ERROR :\nMalloc failed to allocate memory.\n"

/* ==================== include ==================== */

# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* ==================== structure ==================== */

/* ==================== function error ==================== */

int	print_error_message(int error_code);

/* ==================== function utils ==================== */

int	ft_strlen(char *src);

#endif