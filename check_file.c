/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:31:28 by jthuysba          #+#    #+#             */
/*   Updated: 2022/11/15 15:35:16 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Verifie l'extension du fichier
int	check_file(char *file)
{
	int	i;

	i = ft_strlen(file) - 4;
	if (strncmp(file + i, ".fdf", 4) == 0)
		return (1);
	else
		return (0);
}
