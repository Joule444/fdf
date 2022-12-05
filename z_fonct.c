/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_fonct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:39:01 by jthuysba          #+#    #+#             */
/*   Updated: 2022/12/05 15:29:25 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Retourne le z du point x, y
int	get_z(int x, int y, t_point *point)
{
	while (point->win_x != x || point->win_y != y)
		point = point->next;
	return (point->z);
}

//Retourne le z max entre tous les points
int	get_z_max(t_point *point)
{
	int	max;

	max = point->z;
	while (point)
	{
		if (point->z > max)
			max = point->z;
		point = point->next;
	}
	return (max);
}
