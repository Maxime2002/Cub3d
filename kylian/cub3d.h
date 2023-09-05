/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:02:01 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/05 19:18:58 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ==================== define ==================== */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 255
# endif

/* ==================== error ==================== */

# define ERRCODE_MALLOC 1
# define ERRMSG_MALLOC "Error\nMalloc failed to allocate memory.\n"
# define ERRCODE_NB_ARG 2
# define ERRMSG_NB_ARG "Error\nOnly 1 argument is expected.\n"
# define ERRCODE_OPEN 3
# define ERRMSG_OPEN "Error\nImpossible to open the file.\n"
# define ERRCODE_CUB 4
# define ERRMSG_CUB "Error\nThe file must end with a .cub.\n"
# define ERRCODE_READ 5
# define ERRMSG_READ "Error\nReading the file didn't work.\n"
# define ERRCODE_MAP_VOID 6
# define ERRMSG_MAP_VOID "Error\nthe map is empty\n"

/* ==================== include ==================== */

# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

/* ==================== structure ==================== */

typedef struct s_color
{
	int		r;
	int		g;
	int		b;

}			t_color;

typedef struct s_img
{
	int		w;
	int		h;

	void	*img;
}			t_img;

typedef struct s_info
{
	char	**map;
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;

	t_color	ceiling;
	t_color	ground;

}			t_info;

/* ==================== function parcing ==================== */

t_info		*ft_parcing(int argc, char **argv);
int			ft_init_map_and_arg(int fd, t_info *info);

/* ==================== function error ==================== */

int			print_error_message(int error_code);
void		*print_error_message_null(int error_code);

/* ==================== function utils ==================== */

int			ft_strlen(char *src);
char		*ft_strjoin_free_1(char *s1, char *s2);

/* ========= gnl function ========= */

char		*get_next_line(int fd);
char		*ft_join_modif(char *s1, char *s2);
void		ft_buf_cut(char *dest);
int			ft_chr(char *s);

#endif