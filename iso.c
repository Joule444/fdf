/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:58:49 by jthuysba          #+#    #+#             */
/*   Updated: 2022/11/28 16:27:57 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Converti x en isometrique
int	iso_x(int x, int y)
{
	return (x - y);
}

//Converti y en isometrique
int	iso_y(int x, int y, int z, t_info info)
{
	return ((x + y - (z * info.zoom)) / 2);
}
