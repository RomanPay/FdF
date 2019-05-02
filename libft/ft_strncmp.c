/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrost-g <ofrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:23:42 by ofrost-g          #+#    #+#             */
/*   Updated: 2019/05/02 17:27:18 by ofrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t len)
{
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	if (len == 0)
		return (0);
	while (*str1 && len-- > 1)
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else
			return (*str1 - *str2);
	}
	return (*str1 - *str2);
}
