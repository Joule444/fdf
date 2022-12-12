/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:31:28 by jthuysba          #+#    #+#             */
/*   Updated: 2022/12/12 13:36:34 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Verifie type du fichier
int	check_file(char *file)
{
	int	i;
	int	fd;

	i = ft_strlen(file) - 4;
	fd = open(file, O_RDONLY, 777);
	if (fd <= 0)
		return (0);
	if (strncmp(file + i, ".fdf", 4) == 0)
		return (1);
	else
		return (0);
}
