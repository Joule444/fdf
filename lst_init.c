/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:05:38 by jthuysba          #+#    #+#             */
/*   Updated: 2022/11/21 20:03:32 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_point	*my_lstnew(int x, int y, int z, unsigned int color)
{
	t_point	*a;

	a = malloc(sizeof(t_point));
	a->x = x;
	a->y = y;
	a->z = z;
	a->color = color;
	a->next = NULL;
	return (a);
}

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

void	init_line(t_point **list, char *line, int y)
{
	t_point	*elem;
	char	**arr;
	char	**parts;
	int		i;
	int		x;

	arr = ft_split(line, ' ');
	i = 0;
	x = 0;
	while (arr[i])
	{
		parts = ft_split(arr, ',');
		elem = my_lstnew(x, y, ft_atoi(parts[0]), ft_atoi(parts[1]));
		my_lstadd_back(list, elem);
		x++;
		free_arr(parts);
	}
	free_arr(arr);
}

void    print_list(t_point **list)
{
    t_point  *tmp;

    tmp = *list;
    while (*list)
    {
        printf("[x] -> %d\n", (*list)->x);
		printf("[y] -> %d\n", (*list)->y);
		printf("[z] -> %d\n", (*list)->z);
		printf("[color] -> %d\n\n", (*list)->color);
        (*list) = (*list)->next;
    }
    printf("\n////////////// FIN //////////////////\n");
    *list = tmp;

}

t_point	*lst_init(char *file)
{
	t_point	**list;
	char	*line;
	int		fd;
	int		y;
	
	fd = open(file, O_RDONLY, 777);
	*list = malloc(sizeof(t_point));
	if (!*list)
		return (NULL);
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		init_line(list, line, y);
		y++;
		free(line);
		line = get_next_line(fd);
	}
	return (list);
}
