/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:02:01 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/05 14:37:24 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ==================== error ==================== */

# define ERRCODE_MALLOC 1
# define ERRMSG_MALLOC "Error\nMalloc failed to allocate memory.\n"

/* ==================== include ==================== */

# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* ==================== structure ==================== */

typedef struct s_ceiling
{
	int		r;
	int		g;
	int		b;

}			t_ceiling;

typedef struct s_ground
{
	int		r;
	int		g;
	int		b;

}			t_ground;

typedef struct s_info
{
	char	**map;
	void	*no;
	void	*so;
	void	*we;
	void	*ea;

	struct s_ceiling ceiling;
	struct s_ground ground;

}			t_info;

s_info ft_parcing(int argc, char **argv);

/* ==================== function error ==================== */

int			print_error_message(int error_code);

/* ==================== function utils ==================== */

int			ft_strlen(char *src);

#endif