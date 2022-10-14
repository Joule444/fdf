/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:28:03 by jthuysba          #+#    #+#             */
/*   Updated: 2022/10/14 14:37:41 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <stdio.h>


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

int	main(int argc, char **argv)
{
	char	*file;

	file = argv[1];
	if (argc != 2)
		return (0);
	if (!check_file(file))
		return (0);
	else
		return (printf("%s", file), 0);
}
