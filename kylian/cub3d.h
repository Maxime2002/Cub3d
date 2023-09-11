/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:02:01 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/11 14:42:47 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ==================== define ==================== */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 255
# endif

# define WIDTH 1366
# define HEIGHT 768

/* ==================== error ==================== */

# define ERRCODE_ERR 0
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
# define ERRMSG_MAP_VOID "Error\nThe map is missing in the file.\n"
# define ERRCODE_XPM_FILE 7
# define ERRMSG_XPM_FILE "Error\nImage loading to fail.\n"
# define ERRCODE_NB_MAX_COLOR 8
# define ERRMSG_NB_MAX_COLOR "Error\nThe color is greater than 255.\n"
# define ERRCODE_NB_NEG_COLOR 9
# define ERRMSG_NB_NEG_COLOR "Error\nThe color must not be negative.\n"
# define ERRCODE_COLOR_NO 10
# define ERRMSG_COLOR_NO "Error\nIncorrect color.\n"
# define ERRCODE_LINE 11
# define ERRMSG_LINE "Error\nThe lines before the map are not good.\n"
# define ERRCODE_CHAR_MAP 12
# define ERRMSG_CHAR_MAP "Error\nAn unauthorized character is in the map.\n"
# define ERRCODE_PLAYEUR_MAP 13
# define ERRMSG_PLAYEUR_MAP "Error\nNot the right number of starting points.\n"
# define ERRCODE_INVALID_MAP 14
# define ERRMSG_INVALID_MAP "Error\nThe map is invalid.\n"
# define ERRCODE_MLX 15
# define ERRMSG_MLX "Error\nWhen initializing the minilibx.\n"

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
	void	*mlx;
	void	*win;
	char	**map;
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;

	t_color	ceiling;
	t_color	ground;

}			t_info;

typedef struct s_game
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;

	t_info	*info;
}			t_game;

/* ==================== function parsing ==================== */

int			ft_parsing(int argc, char **argv, t_info *info);
int			ft_init_map_and_arg(int fd, t_info *info);
int			ft_init_arg(t_info *info, char *dest);
int			ft_charg_color(t_color *color, char *line);
int			ft_charg_img(t_img *img, char *line, t_info *info);
int			ft_count_number(char *src);
int			ft_charg_map(t_info *info, char *dest, int i);
int			ft_feasibility_check(t_info *info);

/* ==================== function start ==================== */

int			ft_start(int argc, char **argv, t_info **info, t_game **game);
void		ft_give_value(t_info *info, t_game *game);

/* ==================== function error ==================== */

int			print_error_message(int error_code);
void		*print_error_message_null(int error_code);
int			print_error_message_val(int error_code, int code);

/* ==================== function utils ==================== */

int			ft_strlen(char *src);
int			ft_strlen_char(char *src, char c);
char		*ft_strjoin_free_1(char *s1, char *s2);
int			ft_atoi(const char *nptr);
int			ft_count_nb_char(char *dest, char c);
char		**ft_strcpy_tab(char **src);
char		*ft_strdup(char *src);

/* ========= gnl function ========= */

char		*get_next_line(int fd);
char		*ft_join_modif(char *s1, char *s2);
void		ft_buf_cut(char *dest);
int			ft_chr(char *s);

/* ==================== function free ==================== */

int			ft_free_img(t_info *info);
int			ft_free_map(char **map);

#endif