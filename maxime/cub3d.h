/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:02:01 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/13 16:56:30 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ==================== define ==================== */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 255
# endif

# define WIDTH 640
# define HEIGHT 480

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
# define ERRMSG_READ "Error\nfailed to read the file.\n"
# define ERRCODE_MAP_VOID 6
# define ERRMSG_MAP_VOID "Error\nThe map is missing\n"
# define ERRCODE_XPM_FILE 7
# define ERRMSG_XPM_FILE "Error\nImage failed to load.\n"
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
# define ERRCODE_NEW_IMAGE 16
# define ERRMSG_NEW_IMAGE "Error\nCreating main image.\n"
# define ERRCODE_SAME_LINE 17
# define ERRMSG_SAME_LINE "Error\nSame line in file.\n"

/* ==================== include ==================== */

# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

/* ==================== structure   ==================== */

typedef struct s_color
{
	int			r;
	int			g;
	int			b;

}				t_color;

typedef struct s_img
{
	int			w;
	int			h;

	int			*addr;
	int			bpp;
	int			line_length;
	int			endian;
	void		*img;
}				t_img;

typedef struct s_info
{
	void		*mlx;
	void		*win;
	char		**map;
	t_img		no;
	t_img		so;
	t_img		we;
	t_img		ea;
	t_img		door;
	t_img		r;
	t_img		s;
	t_img		sp;
	t_img		spr;
	t_img		spri;
	t_img		sprit;
	t_img		sprite;
	t_img		sprites;
	t_color		ceiling;
	t_color		ground;

}				t_info;

typedef struct s_texture
{
	int			texdir;
	double		wallx;
	int			texx;
	int			texy;
	double		step;
	double		texpos;
}				t_texture;

typedef struct s_aff
{
	int			w;
	int			h;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plan_x;
	double		plan_y;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	t_info		*info;
	void		*img;
	int			*addr;
	int			bpp;
	int			line_length;
	int			endian;
	t_texture	t;
	int			c;
	int			f;
	char		let;
	int			count;
}				t_aff;

/* ==================== function parsing ==================== */

int				ft_parsing(int argc, char **argv, t_info *info);
int				ft_init_map_and_arg(int fd, t_info *info);
int				ft_init_arg(t_info *info, char *dest);
int				ft_charg_color(t_color *color, char *line);
int				ft_charg_img(t_img *img, char *line, t_info *info);
int				ft_count_number(char *src);
int				ft_charg_map(t_info *info, char *dest, int i);
int				ft_feasibility_check(t_info *info);

/* ==================== function start ==================== */

int				ft_start(int argc, char **argv, t_info **info, t_aff **aff);
void			spawn_player(t_aff *aff);

/* ==================== function error ==================== */

int				print_error_message(int error_code);
void			*print_error_message_null(int error_code);
int				print_error_message_val(int error_code, int code);

/* ==================== function utils ==================== */

int				ft_strlen(char *src);
int				ft_strlen_char(char *src, char c);
char			*ft_strjoin_free_1(char *s1, char *s2);
int				ft_atoi(const char *nptr);
int				ft_count_nb_char(char *dest, char c);
char			**ft_strcpy_tab(char **src);
char			*ft_strdup(char *src);
float			absolute(float a);

/* ========= gnl function ========= */

char			*get_next_line(int fd);
char			*ft_join_modif(char *s1, char *s2);
void			ft_buf_cut(char *dest);
int				ft_chr(char *s);

/* ==================== function free ==================== */

int				ft_free_img(t_info *info);
int				ft_free_map(char **map);
int				ft_exit(t_aff *aff);

/* ==================== function algo ==================== */

void			ft_render(t_aff *aff);
int				ft_color_column(t_aff *aff, int x);
void			ft_texture(t_aff *aff);
void			ft_draw_texture(t_aff *aff, int x, int y, t_img *texture);
void			ft_mini_map(t_aff *aff);
/* ==================== function controls ==================== */

void			ft_droite(t_aff *aff);
void			ft_gauche(t_aff *aff);
int				ft_controls(int touche, t_aff *aff);
void			ft_avancer_reculer(int touche, t_aff *aff);
void			ft_droite_gauche(int touche, t_aff *aff);

/* ==================== function sprites ==================== */

void			ft_lettre(t_aff *aff);
void			ft_init_sprites(t_aff *aff);
void			ft_sprites(t_aff *aff, int x, int y);

#endif
