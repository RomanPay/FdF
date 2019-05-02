/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrost-g <ofrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:40:26 by ofrost-g          #+#    #+#             */
/*   Updated: 2019/04/24 20:27:49 by ofrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	create_map_array(t_glob *com)
{
	t_lst	*temp;

	if (com->obj.x == 0)
	{
		ft_putstr("Null file!!!!!!!1111!!");
		exit(0);
	}
	ft_alloc_arr(com);
	temp = com->list_head;
	while (temp->next != NULL)
	{
		com->map[temp->y][temp->x].x = temp->x;
		com->map[temp->y][temp->x].y = temp->y;
		com->map[temp->y][temp->x].z = temp->z;
		com->map[temp->y][temp->x].color = temp->color;
		temp = temp->next;
	}
	com->map[temp->y][temp->x].x = temp->x;
	com->map[temp->y][temp->x].y = temp->y;
	com->map[temp->y][temp->x].z = temp->z;
	com->map[temp->y][temp->x].color = temp->color;
	gradient_map(com);
}

t_lst	*create_maplst(t_glob *com)
{
	t_lst	*var;

	var = (t_lst *)malloc(sizeof(t_lst));
	var->x = com->obj.x;
	var->y = com->obj.y;
	var->z = com->obj.z;
	var->color = com->obj.color;
	var->next = NULL;
	return (var);
}

int		get_color(t_glob *com, char *str)
{
	char	*temp;

	if ((temp = ft_strchr(str, ',')) != NULL)
	{
		if (!check_color(temp + 1))
			return (0);
		com->obj.color = (int)strtol(++temp, NULL, 16);
	}
	else
		com->obj.color = 0;
	return (1);
}

int		write_map(char **str, t_glob *com, int i)
{
	com->obj.x = 0;
	while (str[i] != '\0')
	{
		if (!check_z(str[i]))
			return (0);
		set_z(com, str[i]);
		if (!get_color(com, str[i]))
			return (0);
		if (com->list == NULL)
		{
			com->list = create_maplst(com);
			com->list_head = com->list;
		}
		else
		{
			com->list->next = create_maplst(com);
			com->list = com->list->next;
		}
		i++;
		com->obj.x++;
	}
	com->obj.y++;
	return (1);
}

int		get_map(t_glob *com)
{
	int		i;
	char	*line;
	char	**str_map;

	com->obj.y = 0;
	com->list = NULL;
	while (get_next_line(com->ptr.fd, &line) == 1)
	{
		if (!(check_column(qstring(line, ' '), com)))
		{
			ft_putstr("Invalid file!!!11!!1");
			return (0);
		}
		i = 0;
		str_map = ft_strsplit(line, ' ');
		if (!write_map(str_map, com, i))
			return (0);
		free_array(str_map);
		free(line);
	}
	close(com->ptr.fd);
	create_map_array(com);
	return (1);
}
