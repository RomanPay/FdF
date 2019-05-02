/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculating_iso.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrost-g <ofrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 20:18:12 by ofrost-g          #+#    #+#             */
/*   Updated: 2019/04/22 21:55:36 by ofrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_x(t_glob *com, t_map *map)
{
	int tmp_y;
	int tmp_z;

	tmp_y = (int)(map->y * cos(com->img.angle_x * M_PI / 180) +
			map->z * sin(com->img.angle_x * M_PI / 180));
	tmp_z = (int)(map->z * cos(com->img.angle_x * M_PI / 180) -
			map->y * sin(com->img.angle_x * M_PI / 180));
	map->y = tmp_y;
	map->z = tmp_z;
}

void	rotate_y(t_glob *com, t_map *map)
{
	int tmp_x;
	int tmp_z;

	tmp_x = (int)(map->x * cos(com->img.angle_y * M_PI / 180) +
			map->z * sin(com->img.angle_y * M_PI / 180));
	tmp_z = (int)(map->z * cos(com->img.angle_y * M_PI / 180) -
			map->x * sin(com->img.angle_y * M_PI / 180));
	map->x = tmp_x;
	map->z = tmp_z;
}

void	rotate_z(t_glob *com, t_map *map)
{
	int tmp_x;
	int tmp_y;

	tmp_x = (int)(map->x * cos(com->img.angle_z * M_PI / 180) -
			map->y * sin(com->img.angle_z * M_PI / 180));
	tmp_y = (int)(map->x * sin(com->img.angle_z * M_PI / 180) +
			map->y * cos(com->img.angle_z * M_PI / 180));
	map->x = tmp_x;
	map->y = tmp_y;
}

t_point	image_calc(t_glob com, t_map map)
{
	t_point result;

	map.x = (map.x - (com.obj.x / 2)) * com.img.zoom;
	map.y = (map.y - (com.obj.y / 2)) * com.img.zoom;
	map.z = (int)(map.z * com.z_stand * com.img.zoom);
	rotate_x(&com, &map);
	rotate_y(&com, &map);
	rotate_z(&com, &map);
	if (com.iso == 0)
	{
		result.x = map.x + WIDTH / 2 + (com.img.stepx);
		result.y = map.y + HEIGHT / 2 + (com.img.stepy);
		result.color = map.color;
	}
	else
	{
		result.x = (map.x - map.y) * cos(0.523599) +
				WIDTH / 2 + (com.img.stepx);
		result.y = (map.x + map.y) * sin(0.523599) - map.z +
				HEIGHT / 2 + (com.img.stepy);
		result.color = map.color;
	}
	return (result);
}
