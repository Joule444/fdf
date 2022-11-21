/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:55:57 by jthuysba          #+#    #+#             */
/*   Updated: 2022/11/21 13:46:00 by jthuysba         ###   ########.fr       */
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
	return (count);
}

//Rempli une ligne de la matrice
char	*fill_line(char *line)
{
	char	*matrice_line;
	char	**arr;
	char	**parts;
	int		i;

	line[ft_strlen(line) - 1] = '\0';
	matrice_line = (char *)ft_calloc(matrice_line_len(line) + 1, sizeof(char));
	if (!matrice_line)
		return (NULL);
	arr = ft_split(line, ' ');
	i = 0;
	while (arr[i])
	{
		parts = ft_split(arr[i], ',');
		ft_strlcat(matrice_line, parts[0], ft_strlen(matrice_line) + ft_strlen(parts[0]) + 1);
		ft_strlcat(matrice_line, ";", ft_strlen(matrice_line) + 2);
		free_arr(parts);
		i++;
	}
	matrice_line[ft_strlen(matrice_line) - 1] = '$';
	matrice_line[ft_strlen(matrice_line)] = '\0';
	printf("%s\n", matrice_line);
	free_arr(arr);
	return (matrice_line);
}

//Initialise la matrice avec les points de la map
char	**matrice_init(char *file)
{
	char	**matrice;
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY, 777);
	matrice = malloc(sizeof(char *) * (matrice_lines(file) + 1));
	if (!matrice)
		return (NULL);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		matrice[i] = fill_line(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (free(line), matrice);
}
