/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrost-g <ofrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:58:00 by ofrost-g          #+#    #+#             */
/*   Updated: 2019/05/02 17:27:18 by ofrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *ph;
	const char *pn;

	if ((*haystack == '\0' && *needle == '\0') || *needle == '\0')
		return ((char*)haystack);
	if (*haystack == '\0')
		return (0);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			pn = needle;
			ph = haystack;
			while (*pn == *ph && *pn != '\0')
			{
				pn++;
				ph++;
				if (*pn == '\0')
					return ((char*)haystack);
			}
		}
		haystack++;
	}
	return (0);
}
