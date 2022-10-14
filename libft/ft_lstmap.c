/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:07:43 by jthuysba          #+#    #+#             */
/*   Updated: 2022/05/16 12:19:07 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;
	t_list	*elem;

	l = 0;
	while (lst)
	{
		elem = ft_lstnew(f(lst->content));
		if (!elem)
		{
			while (l)
			{
				elem = l->next;
				del(l->content);
				free(l);
				l = elem;
			}
			lst = 0;
			return (0);
		}
		ft_lstadd_back(&l, elem);
		lst = lst->next;
	}
	return (l);
}
