/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrost-g <ofrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 20:47:30 by ofrost-g          #+#    #+#             */
/*   Updated: 2019/05/02 17:27:18 by ofrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		constring(char *str, char c)
{
	int		lenstr;

	lenstr = 0;
	while (*str == c)
		str++;
	if (*str != c)
	{
		while (*str != c)
		{
			if (*str == '\0')
			{
				break ;
			}
			lenstr++;
			str++;
		}
	}
	return (lenstr);
}

static int		qstr(char *str, char c)
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

static char		**createarray(char **arr, char *s, char *temp, char c)
{
	int		i;
	int		j;
	int		lenstr;

	i = 0;
	while (i < qstr(s, c) - 1)
	{
		lenstr = constring(temp, c);
		arr[i] = ft_strnew(lenstr);
		if (!arr[i])
			return (0);
		j = 0;
		while (j < lenstr)
		{
			while (*temp == c)
				temp++;
			arr[i][j] = *temp;
			j++;
			temp++;
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	*temp;
	char	**arr;

	if (!s)
		return (0);
	arr = (char**)malloc(sizeof(char*) * qstr((char*)s, c));
	if (!arr)
		return (0);
	temp = (char*)s;
	arr = createarray(arr, (char*)s, temp, c);
	return (arr);
}
