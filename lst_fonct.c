/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fonct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:51:03 by jthuysba          #+#    #+#             */
/*   Updated: 2022/12/09 17:09:16 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Retourne le nombres de maillons de la liste
int	my_lstsize(t_point *point)
{
	int	i;

	i = 0;
	while (point)
	{
		i++;
		point = point->next;
	}
	return (i);
}

//Initialise un nouveau point/maillon
t_point	*my_lstnew(int x, int y, int z)
{
	t_point	*a;

	a = malloc(sizeof(t_point));
	a->x = x;
	a->y = y;
	a->z = z;
	a->real_z = z;
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
	free(lst);
}
