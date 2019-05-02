/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrost-g <ofrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:36:25 by ofrost-g          #+#    #+#             */
/*   Updated: 2019/04/24 20:27:49 by ofrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_pixel(t_glob *com, t_point stream)
{
	int		x;
	int		y;
	int		index;

	x = (int)floor(stream.x);
	y = (int)floor(stream.y);
	if (x < 0 || x > WIDTH - 1 || y < 0 || y > HEIGHT - 1)
		return ;
	index = 4 * x + y * com->s_l;
	com->img_str[index] = (char)(stream.color & 0xFF);
	com->img_str[index + 1] = (char)(stream.color >> 8 & 0xFF);
	com->img_str[index + 2] = (char)(stream.color >> 16 & 0xFF);
}

int		size_line(double e_x, double e_y, double st_x, double st_y)
{
	int		len_x;
	int		len_y;
	int		len;

	len_x = abs((int)floor(e_x) - (int)floor(st_x));
	len_y = abs((int)floor(e_y) - (int)floor(st_y));
	len = (len_x > len_y ? len_x : len_y);
	return (len);
}

int		line_color(t_point stream, t_point s, t_point e, t_point delta)
{
	int		blue;
	int		green;
	int		red;
	double	percent;

	if (stream.color == e.color)
		return (stream.color);
	if (fabs(delta.x) > fabs(delta.y))
		percent = percent_processing(s.x, e.x, stream.x);
	else
		percent = percent_processing(s.y, e.y, stream.y);
	red = set_light((s.color >> 16) & 0xff, (e.color >> 16) & 0xff, percent);
	green = set_light((s.color >> 8) & 0xff, (e.color >> 8) & 0xff, percent);
	blue = set_light(s.color & 0xff, e.color & 0xff, percent);
	return ((red << 16) | (green << 8) | blue);
}

void	draw_line(t_glob *com, t_point s, t_point e)
{
	t_point	stream;
	t_point	delta;
	int		len;

	stream.x = s.x;
	stream.y = s.y;
	stream.color = s.color;
	len = size_line(e.x, e.y, stream.x, stream.y);
	delta.x = (e.x - s.x) / len;
	delta.y = (e.y - s.y) / len;
	while (len--)
	{
		stream.x += delta.x;
		stream.y += delta.y;
		stream.color = line_color(stream, s, e, delta);
		draw_pixel(com, stream);
	}
}

void	draw(t_glob com)
{
	int		x;
	int		y;

	y = 0;
	while (y < com.obj.y)
	{
		x = 0;
		while (x < com.obj.x)
		{
			calculating(com, y, x);
			x++;
		}
		y++;
	}
}
