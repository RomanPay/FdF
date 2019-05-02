/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrost-g <ofrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:59:11 by ofrost-g          #+#    #+#             */
/*   Updated: 2019/04/24 20:27:49 by ofrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_angle(int key, t_glob *com)
{
	if (key == 91)
		com->img.angle_x++;
	if (key == 84)
		com->img.angle_x--;
	if (key == 86)
		com->img.angle_y++;
	if (key == 88)
		com->img.angle_y--;
	if (key == 82)
		com->img.angle_z++;
	if (key == 65)
		com->img.angle_z--;
	if (key == 116)
		com->z_stand += 0.1;
	if (key == 121)
		com->z_stand -= 0.1;
	if (key == 49)
	{
		if (com->iso)
			com->iso = 0;
		else
			com->iso = 1;
	}
}

int		point_color(t_glob *com, int z)
{
	int		blue;
	int		green;
	int		red;
	double	percent;

	if (z == com->z_min)
		return (com->comcolor);
	if (z == com->z_max)
		return (com->comcolormax);
	percent = percent_processing(com->z_min, com->z_max, z);
	blue = set_light(com->comcolor & 0xff, com->comcolormax & 0xff, percent);
	green = set_light(com->comcolor >> 8 & 0xff,
			com->comcolormax >> 8 & 0xff, percent);
	red = set_light(com->comcolor >> 16 & 0xff,
			com->comcolormax >> 16 & 0xff, percent);
	return ((red << 16) | (green << 8) | blue);
}

void	gradient_map(t_glob *com)
{
	int		i;
	int		j;

	i = 0;
	while (i < com->obj.y)
	{
		j = 0;
		while (j < com->obj.x)
		{
			if (com->map[i][j].color == 0)
				com->map[i][j].color = point_color(com, com->map[i][j].z);
			j++;
		}
		i++;
	}
}

void	calculating(t_glob com, int y, int x)
{
	t_point	s;
	t_point	e;

	s = image_calc(com, com.map[y][x]);
	if (y + 1 < com.obj.y)
	{
		e = image_calc(com, com.map[y + 1][x]);
		draw_line(&com, s, e);
	}
	if (x + 1 < com.obj.x)
	{
		e = image_calc(com, com.map[y][x + 1]);
		draw_line(&com, s, e);
	}
}
