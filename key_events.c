/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:27:15 by jthuysba          #+#    #+#             */
/*   Updated: 2022/12/08 18:28:45 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Augmente les reliefs
void	z_up(t_mlx *mlx)
{
	t_point	*elem;
	int		zoom_x;
	int		zoom_y;

	elem = *mlx->point;
	while (elem)
	{
		elem->z *= 2;
		elem = elem->next;
	}
	set_points(*mlx, *mlx->point);
	printf("z up\n");
}

//Diminue les reliefs
void	z_down(t_mlx *mlx)
{
	t_point	*elem;
	int		zoom_x;
	int		zoom_y;

	elem = *mlx->point;
	while (elem)
	{
		if (elem->z != 1 && elem->z != -1)
			elem->z /= 2;
		elem = elem->next;
	}
	set_points(*mlx, *mlx->point);
	printf("z down\n");
}

//Zoom
void	zoom_in(t_mlx *mlx)
{
	mlx->scale.zoom *= 2;
	if (mlx->scale.zoom <= 0)
		mlx->scale.zoom = 1;
	printf("zoom %d\n", mlx->scale.zoom);
	set_points(*mlx, *mlx->point);
}

//Dezoom
void	zoom_out(t_mlx *mlx)
{
	mlx->scale.zoom /= 2;
	printf("zoom %d\n", mlx->scale.zoom);
	set_points(*mlx, *mlx->point);
}

//Change la couleur de la figure
void	change_color(t_mlx *mlx)
{
	mlx->color *= 1.1;
	printf("color %d\n", mlx->color);
}
