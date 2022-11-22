/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:58:49 by jthuysba          #+#    #+#             */
/*   Updated: 2022/11/22 13:59:16 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	iso_x(int x, int y)
{
	return (x - y);
}

int	iso_y(int x, int y, int z)
{
	return ((x + y - z) / 2);
}
