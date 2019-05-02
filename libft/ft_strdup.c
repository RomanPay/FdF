/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrost-g <ofrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:44:52 by ofrost-g          #+#    #+#             */
/*   Updated: 2019/05/02 17:27:18 by ofrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(src);
	dst = (char*)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	len = 0;
	while (src[len] != '\0')
	{
		dst[len] = src[len];
		len++;
	}
	dst[len] = '\0';
	return (dst);
}
