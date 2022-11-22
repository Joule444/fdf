/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fonct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:51:03 by jthuysba          #+#    #+#             */
/*   Updated: 2022/11/22 16:51:47 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Initialise un nouveau point/maillon
t_point	*my_lstnew(int x, int y, int z, unsigned int color)
{
	t_point	*a;

	a = malloc(sizeof(t_point));
	a->x = x;
	a->y = y;
	a->z = 5 * z;
	a->color = color;
	a->next = NULL;
	return (a);
}

//Retourne le dernier maillon de la liste
t_point	*my_lstlast(t_point *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

//Ajoute un nouveau maillon a la fin de la liste
void	my_lstadd_back(t_point **lst, t_point *new)
{
	t_point	*a;

	if (lst)
	{
		if (*lst)
		{
			a = my_lstlast(*lst);
			a->next = new;
		}
		else
			*lst = new;
	}
}

//Free une liste entiere
void	my_lstclear(t_point **lst)
{
	t_point	*elem;

	if (lst)
	{
		while (*lst)
		{
			elem = (*lst)->next;
			free(*lst);
			*lst = elem;
		}
	}
}
