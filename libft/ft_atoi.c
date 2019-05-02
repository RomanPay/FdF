/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrost-g <ofrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:55:03 by ofrost-g          #+#    #+#             */
/*   Updated: 2019/05/02 17:27:17 by ofrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(unsigned long nb, int neg)
{
	if (nb > 9223372036854775807)
	{
		if (neg == -1)
			return (0);
		else
			return (-1);
	}
	else
		return (nb * neg);
}

static char	*chstr(char *s)
{
	int		i;

	i = 0;
	if (*s == 0 || *s == 27)
		return (0);
	while (*s >= 0 && *s < 33)
		s++;
	if (*s == 43)
		s++;
	return ((char*)s);
}

int			ft_atoi(const char *str)
{
	int				i;
	unsigned long	ret;
	int				neg;

	i = 0;
	ret = 0;
	neg = 1;
	if (!(str = chstr((char*)str)))
		return (0);
	if (str[i] == 45 && str[i - 1] != 43)
	{
		neg *= -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		ret = ret * 10 + str[i] % '0';
		i++;
	}
	ret = check(ret, neg);
	return (ret);
}
