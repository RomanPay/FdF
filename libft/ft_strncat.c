/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrost-g <ofrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:46:14 by ofrost-g          #+#    #+#             */
/*   Updated: 2019/05/02 17:27:18 by ofrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(s1);
	while (s2[i] != '\0' && n > 0)
	{
		s1[len] = s2[i];
		len++;
		i++;
		n--;
	}
	s1[len] = '\0';
	return (s1);
}
