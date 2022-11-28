/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:18:33 by jthuysba          #+#    #+#             */
/*   Updated: 2022/11/28 16:27:43 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Place les points de la figure
void	draw_points(t_mlx mlx, t_point *point, t_info info)
{
	while (point)
	{
		point->win_x = iso_x((point->x * info.zoom) + info.start_x, (point->y * info.zoom) + info.start_y);
		point->win_y = iso_y((point->x * info.zoom) + info.start_x, (point->y * info.zoom) + info.start_y, point->z, info);
		my_mlx_pixel_put(&mlx.img, point->win_x, point->win_y, mlx.color);
		point = point->next;
	}
}

//Retourne le prochain maillon de meme x que point
t_point	*get_next_col(t_point *point)
{
	t_point	*elem;

	if (point->next == NULL)
		return (point);
	elem = point->next;
	while (elem)
	{
		if (elem->x == point->x)
			return (elem);
		elem = elem->next;
	}
	return (point);
}

//Trace les lignes entres les points de la figure
void	draw_lines(t_mlx mlx, t_point *point, t_info info)
{
	t_point	*elem;
	
	while (point->next)
	{
		if (point->next->y == point->y)
			bresenham_line(mlx, point->win_x, point->win_y, point->next->win_x, point->next->win_y);
		elem = get_next_col(point);
		bresenham_line(mlx, point->win_x, point->win_y, elem->win_x, elem->win_y);
		point = point->next;
	}
}