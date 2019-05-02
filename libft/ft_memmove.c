/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrost-g <ofrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 22:26:27 by ofrost-g          #+#    #+#             */
/*   Updated: 2019/05/02 17:27:18 by ofrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pd;
	unsigned char	*ps;

	pd = (unsigned char*)dst;
	ps = (unsigned char*)src;
	if (dst < src)
	{
		ft_memcpy(dst, src, len);
		return (dst);
	}
	else
	{
		pd = pd + (len - 1);
		ps = ps + (len - 1);
		while (len > 0)
		{
			*pd = *ps;
			ps--;
			pd--;
			len--;
		}
		return (dst);
	}
}
