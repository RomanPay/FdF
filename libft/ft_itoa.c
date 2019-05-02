/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrost-g <ofrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:51:44 by ofrost-g          #+#    #+#             */
/*   Updated: 2019/05/02 17:27:17 by ofrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int		nlen;
	long	lng;

	lng = n;
	nlen = 0;
	if (lng < 0)
	{
		nlen++;
		lng = -lng;
	}
	if (lng / 10 == 0)
		return (nlen + 1);
	while (lng > 0)
	{
		lng = lng / 10;
		nlen++;
	}
	return (nlen);
}

static char	*strwnum(int neg, int len, long n, char *s)
{
	if (n == 0)
		s[--len] = n % 10 + '0';
	while (n > 0)
	{
		s[--len] = n % 10 + '0';
		n /= 10;
	}
	if (neg < 0)
		s[--len] = '-';
	return (s);
}

char		*ft_itoa(int n)
{
	int		nlen;
	int		neg;
	char	*res;
	long	lng;

	lng = n;
	nlen = numlen(lng);
	neg = 1;
	if (lng < 0)
	{
		neg = -neg;
		lng = -lng;
	}
	res = ft_strnew(nlen);
	if (res)
		return (strwnum(neg, nlen, lng, res));
	else
		return (0);
}
