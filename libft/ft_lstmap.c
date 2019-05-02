/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrost-g <ofrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:26:34 by ofrost-g          #+#    #+#             */
/*   Updated: 2019/05/02 17:27:18 by ofrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *tmp;

	if (lst && f)
	{
		tmp = f(lst);
		head = tmp;
		lst = lst->next;
		while (lst)
		{
			tmp->next = f(lst);
			if (!(tmp->next = f(lst)))
				return (0);
			tmp = tmp->next;
			lst = lst->next;
		}
		return (head);
	}
	else
		return (0);
}
