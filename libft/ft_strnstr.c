/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrost-g <ofrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:45:13 by ofrost-g          #+#    #+#             */
/*   Updated: 2019/05/02 17:27:18 by ofrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*chekstr(char *haystack, char *needle, size_t l)
{
	int		lent;
	char	*ph;
	char	*pn;

	while (*haystack && l > 0)
	{
		if (*haystack == *needle && l > 0)
		{
			lent = l;
			ph = haystack;
			pn = needle;
			while (*ph == *pn && *pn != '\0' && lent--)
			{
				pn++;
				ph++;
				if (*pn == '\0')
					return ((char*)haystack);
			}
		}
		haystack++;
		l--;
	}
	return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if ((*haystack == '\0' && *needle == '\0') || *needle == '\0')
		return ((char*)haystack);
	if (*haystack == '\0' || (ft_strlen(haystack) < ft_strlen(needle)))
		return (0);
	return (chekstr((char*)haystack, (char *)needle, len));
}
