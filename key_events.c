/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:27:15 by jthuysba          #+#    #+#             */
/*   Updated: 2022/12/12 14:11:30 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Augmente les reliefs
void	z_up(t_mlx *mlx)
{
	t_point	*elem;

	elem = *mlx->point;
	while (elem)
	{
		elem->z *= 2;
		elem = elem->next;
	}
	set_points(*mlx, *mlx->point);
}

//Diminue les reliefs
void	z_down(t_mlx *mlx)
{
	t_point	*elem;

	elem = *mlx->point;
	while (elem)
	{
		if (elem->z != elem->real_z)
			elem->z /= 2;
		elem = elem->next;
	}
	set_points(*mlx, *mlx->point);
}

//Zoom
void	zoom_in(t_mlx *mlx)
{
	if (mlx->scale.zoom > 500)
		return ;
	mlx->scale.zoom *= 2;
	if (mlx->scale.zoom <= 0)
		mlx->scale.zoom = 1;
	set_points(*mlx, *mlx->point);
}

//Dezoom
void	zoom_out(t_mlx *mlx)
{
	if (mlx->scale.zoom > 1)
		mlx->scale.zoom /= 2;
	set_points(*mlx, *mlx->point);
}

//Change la couleur de la figure
void	change_color(t_mlx *mlx)
{
	mlx->color *= 1.1;
}
