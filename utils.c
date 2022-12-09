/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:48:57 by jthuysba          #+#    #+#             */
/*   Updated: 2022/12/09 16:59:10 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Free completement un char**
void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	free(arr);
}

//Converti x en isometrique
int	iso_x(int x, int y)
{
	return (x - y);
}

//Converti y en isometrique
int	iso_y(int x, int y, int z, t_scale scale)
{
	return ((x + y - (z * scale.zoom)) / 2);
}
