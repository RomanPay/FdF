/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrost-g <ofrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:26:42 by ofrost-g          #+#    #+#             */
/*   Updated: 2019/04/24 20:33:56 by ofrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_fdf(t_glob *com)
{
	com->img.zoom = 2;
	com->img.stepx = 2;
	com->img.stepy = 2;
	com->img.angle_x = 0;
	com->img.angle_y = 0;
	com->img.angle_z = 0;
	com->obj.x = 0;
	com->obj.y = 0;
	com->comcolor = 0xffffff;
	com->comcolormax = 0x000000;
	com->z_max = 0;
	com->z_min = 0;
	com->iso = 1;
	com->z_stand = 0.1;
}

void	set_default_color(int ac, char **av, t_glob *com)
{
	if (ac == 3)
	{
		if (!check_color(av[2]))
			exit(0);
		com->comcolor = (int)(strtol(av[2], NULL, 16));
	}
	if (ac == 4)
	{
		if (!check_color(av[2]) || !check_color(av[3]))
			exit(0);
		com->comcolor = (int)strtol(av[2], NULL, 16);
		com->comcolormax = (int)strtol(av[3], NULL, 16);
	}
}

void	free_array(char **str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_alloc_arr(t_glob *com)
{
	int i;

	i = 0;
	com->map = (t_map **)malloc(sizeof(t_map *) * com->obj.y);
	while (i < com->obj.y)
	{
		com->map[i] = (t_map *)malloc(sizeof(t_map) * com->obj.x);
		i++;
	}
}

void	set_z(t_glob *com, char *str)
{
	com->obj.z = ft_atoi(str);
	if (com->z_min > com->obj.z)
		com->z_min = com->obj.z;
	if (com->z_max < com->obj.z)
		com->z_max = com->obj.z;
}
