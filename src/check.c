/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrost-g <ofrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:37:21 by ofrost-g          #+#    #+#             */
/*   Updated: 2019/04/24 20:27:49 by ofrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		check_column(int a, t_glob *com)
{
	if (com->column == 0 || a == com->column)
	{
		com->column = a;
		return (1);
	}
	else
		return (0);
}

int		check_z(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			return (1);
		if ((str[i] > 47 && str[i] < 58) || str[i] == '-')
			i++;
		else
		{
			ft_putstr("Invalid z!!111!");
			return (0);
		}
	}
	return (1);
}

int		check_color(const char *str)
{
	int		i;

	i = 2;
	if (str[0] != '0' && str[i] != 'x')
	{
		ft_putstr("Invalid color!!!111!!");
		return (0);
	}
	while (str[i] != '\0')
	{
		if ((str[i] > 47 && str[i] < 58) || (str[i] > 65 && str[i] < 91)
		|| (str[i] > 96 && str[i] < 123))
			i++;
		else
		{
			ft_putstr("Invalid color!!!111!!");
			return (0);
		}
	}
	return (1);
}

int		set_light(int s, int e, double percente)
{
	return ((int)((1 - percente) * s + percente * e));
}

double	percent_processing(double s, double e, double stream)
{
	double	placing;
	double	spacing;

	placing = stream - s;
	spacing = e - s;
	return ((spacing == 0) ? 1.0 : (placing / spacing));
}
