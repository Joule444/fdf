/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:05:38 by jthuysba          #+#    #+#             */
/*   Updated: 2022/11/22 14:34:26 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Initialise une ligne de la map dans la liste
void	init_line(t_point **list, char *line, int y)
{
	t_point	*elem;
	char	**arr;
	char	**parts;
	int		i;
	int		x;
	unsigned int	color;

	arr = ft_split(line, ' ');
	x = 0;
	while (arr[x])
	{
		parts = ft_split(arr[x], ',');
		if (ft_strchr(arr[x], ',') != NULL)
			color = ft_atoi(parts[1]);
		else
			color = 0xffffff;
		elem = my_lstnew(x, y, ft_atoi(parts[0]), color);
		my_lstadd_back(list, elem);
		x++;
		free_arr(parts);
	}
	free_arr(arr);
}

//Compte les elements d'une ligne
int	line_elem_count(char *line)
{
	int		i;
	char	**arr;

	i = 0;
	arr = ft_split(line, ' ');
	while (arr[i])
		i++;
	return (free_arr(arr), i);
}

//Compte tous les elements d'un fichier
int	file_elem_count(char *file)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY, 777);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count += line_elem_count(line);
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), free(line), count);
}

//DELETE
// void    print_list(t_point **list)
// {
//     t_point  *tmp;
//
//     tmp = *list;
//     while (*list)
//     {
//         printf("[x] -> %d\n", (*list)->x);
// 		printf("[y] -> %d\n", (*list)->y);
// 		printf("[z] -> %d\n", (*list)->z);
// 		printf("[color] -> %d\n\n", (*list)->color);
//         (*list) = (*list)->next;
//     }
//     printf("\n////////////// FIN //////////////////\n");
//     *list = tmp;
//
// }
//DELETE

//Initialise liste des points de la map
t_point	**lst_init(char *file)
{
	t_point	**list;
	char	*line;
	int		fd;
	int		y;
	
	list = malloc(sizeof(t_point) * file_elem_count(file));
	if (!list)
		return (NULL);
	*list = NULL;
	fd = open(file, O_RDONLY, 777);
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		init_line(list, line, y);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	// print_list(list);
	return (free(line), list);
}
