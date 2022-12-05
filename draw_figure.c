/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:18:33 by jthuysba          #+#    #+#             */
/*   Updated: 2022/12/05 17:56:58 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Place les points de la figure
void	draw_points(t_mlx mlx, t_point *point, t_info info)
{
	int	zoom_x;
	int	zoom_y;

	while (point)
	{
		zoom_x = (point->x * info.zoom) + info.start_x;
		zoom_y = (point->y * info.zoom) + info.start_y;
		if (!point->win_x && !point->win_y)
		{	
			point->win_x = iso_x(zoom_x, zoom_y);
			point->win_y = iso_y(zoom_x, zoom_y, point->z, info);
		}
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
		{
			if (point->win_x <= point->next->win_x)
				bresenham_line(mlx, point, point->next);
			else
				bresenham_line(mlx, point->next, point);
		}
		elem = get_next_col(point);
		if (point->win_x <= elem->win_x)
			bresenham_line(mlx, point, elem);
		else
			bresenham_line(mlx, elem, point);
		point = point->next;
	}
}
