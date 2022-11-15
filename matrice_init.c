/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:55:57 by jthuysba          #+#    #+#             */
/*   Updated: 2022/11/15 18:56:51 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Compte le nombres de lignes du fichier
int	matrice_lines(char *file)
{
	int		fd;
	int		i;

	fd = open(file, O_RDONLY, 777);
	i = 0;
	while (get_next_line(fd))
		i++;
	close(fd);
	return (i);
}

//Compte les elements d'une ligne
int	elem_count(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

//Initialise la matrice avec les points de la map
int **matrice_init(char *file)
{
	int					**matrice;
	int					fd;
	char				*line;
	char				**arr;
	int					i;
	int					j;
	char				**parts;

	fd = open(file, O_RDONLY, 777);
	matrice = malloc(sizeof(int *) * matrice_lines(file));
	line = get_next_line(fd);
	i = 0;
	j = 0;
	while (line)
	{
		arr = ft_split(line, ' ');
		matrice[i] = malloc(sizeof(int) * elem_count(arr));
		while (arr[j])
		{
			parts = ft_split(arr[j], ',');
			matrice[i][j] = ft_atoi(parts[0]);
			free_arr(parts);
			j++;
		}
		free_arr(arr);
		free(line);
		i++;
		j = 0;
		line = get_next_line(fd);
	}
	return (matrice);
}

//Initialise la matrice avec les couleurs de chaque point de la map
unsigned int **color_matrice_init(char *file)
{
	unsigned int		**color_matrice;
	int					fd;
	char				*line;
	char				**arr;
	int					i;
	int					j;
	char				**parts;

	fd = open(file, O_RDONLY, 777);
	color_matrice = malloc(sizeof(int *) * matrice_lines(file));
	line = get_next_line(fd);
	i = 0;
	j = 0;
	while (line)
	{
		arr = ft_split(line, ' ');
		color_matrice[i] = malloc(sizeof(int) * elem_count(arr));
		while (arr[j])
		{
			parts = ft_split(arr[j], ',');
			if (ft_strchr(arr[i], ',') != NULL)
				color_matrice[i][j] = ft_atoi(parts[0]);
			else
				color_matrice[i][j] = 0xffffff;
			free_arr(parts);
			j++;
		}
		free_arr(arr);
		free(line);
		i++;
		j = 0;
		line = get_next_line(fd);
	}
	return (color_matrice);
}
