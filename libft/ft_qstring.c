/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qstring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrost-g <ofrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:59:54 by ofrost-g          #+#    #+#             */
/*   Updated: 2019/04/23 14:39:34 by ofrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		qstring(char *str, char c)
{
	int		qstring;

	qstring = 0;
	while (*str)
	{
		if (*str != c)
		{
			while (*str != c)
			{
				if (*str == '\0')
					break ;
				str++;
			}
			qstring++;
		}
		if (*str == '\0')
			break ;
		str++;
	}
	return (qstring + 1);
}
