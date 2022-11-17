/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:55:57 by jthuysba          #+#    #+#             */
/*   Updated: 2022/11/17 18:26:17 by jthuysba         ###   ########.fr       */
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

//Compte le nombres de caracteres pour une ligne de la matrice (avec les ';')
int	matrice_line_len(char *line)
{
	int		i;
	int		count;
	char	**arr;
	char	**parts;

	i = 0;
	count = 0;
	arr = ft_split(line, ' ');
	while (arr[i])
	{
		parts = ft_split(arr[i], ',');
		count += ft_strlen(parts[0]) + 1;
		free_arr(parts);
		i++;
	}
	free_arr(arr);
	return (count - 1);
}

//Initialise la matrice avec les points de la map
char **matrice_init(char *file)
{
	char	**matrice;
	int		fd;
	char	*line;
	char	**arr;
	int		i;
	int		j;
	char	**parts;

	fd = open(file, O_RDONLY, 777);
	matrice = malloc(sizeof(char *) * (matrice_lines(file) +  1));
	if (!matrice)
			return (NULL);
	line = get_next_line(fd);
	i = 0;
	j = 0;
	while (line)
	{
		matrice[j] = malloc(sizeof(char) * (matrice_line_len(line) + 1));
		matrice[j] = "\0";
		if (!matrice[j])
			return (NULL);
		arr = ft_split(line, ' ');
		while (arr[i])
		{
			parts = ft_split(arr[i], ',');
			my_strcat(matrice[j], parts[0]);
			printf("%s", matrice[j]);
			free_arr(parts);
			i++;
		}
		free_arr(arr);
		free(line);
		i = 0;
		j++;
		line = get_next_line(fd);
	}
	return (matrice);
}

//Initialise la matrice avec les couleurs de chaque point de la map
char **color_matrice_init(char *file)
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
