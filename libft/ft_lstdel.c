/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrost-g <ofrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:57:13 by ofrost-g          #+#    #+#             */
/*   Updated: 2019/05/02 17:27:17 by ofrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *var;

	if (alst && *alst)
	{
		while ((*alst) != 0)
		{
			var = (*alst)->next;
			ft_lstdelone(&(*alst), del);
			(*alst) = var;
		}
	}
}
