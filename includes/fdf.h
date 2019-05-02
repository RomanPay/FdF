/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrost-g <ofrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:29:40 by ofrost-g          #+#    #+#             */
/*   Updated: 2019/04/24 20:22:47 by ofrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include "mlx.h"
# include "../libft/libft.h"

# define HEIGHT 1000
# define WIDTH 1000

typedef struct	s_img
{
	int		stepx;
	int		stepy;
	int		zoom;
	int		angle_x;
	int		angle_y;
	int		angle_z;
}				t_img;

typedef struct	s_map
{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_map;

typedef struct	s_lst
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_obj
{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_obj;

typedef struct	s_ptr
{
	int		fd;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}				t_ptr;

typedef struct	s_point
{
	double	x;
	double	y;
	int		color;
}				t_point;

typedef struct	s_glob
{
	t_ptr	ptr;
	t_obj	obj;
	t_lst	*list;
	t_lst	*list_head;
	t_img	img;
	t_map	**map;
	char	*img_str;
	int		bpp;
	int		s_l;
	int		endian;
	int		column;
	int		comcolor;
	int		comcolormax;
	int		z_min;
	int		z_max;
	int		iso;
	double	z_stand;
}				t_glob;

int				get_map(t_glob *com);
void			draw(t_glob com);
void			set_fdf(t_glob *com);
int				check_color(const char *str);
void			free_array(char **str);
void			set_default_color(int ac, char **av, t_glob *com);
double			percent_processing(double s, double e, double stream);
int				set_light(int s, int e, double percente);
int				check_column(int a, t_glob *com);
int				check_z(const char *str);
int				check_color(const char *str);
void			ft_alloc_arr(t_glob *com);
void			set_z(t_glob *com, char *str);
int				point_color(t_glob *com, int z);
void			gradient_map(t_glob *com);
void			set_angle(int key, t_glob *com);
void			calculating(t_glob com, int y, int x);
t_point			image_calc(t_glob com, t_map map);
void			draw_line(t_glob *com, t_point s, t_point e);

#endif
