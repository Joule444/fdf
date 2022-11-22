/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:28:03 by jthuysba          #+#    #+#             */
/*   Updated: 2022/11/22 16:40:57 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <stdio.h>

void	draw_points(t_mlx mlx, t_point *point, t_info info)
{
	while (point)
	{
		point->win_x = iso_x((point->x * info.zoom) + info.start_x, (point->y * info.zoom) + info.start_y);
		point->win_y = iso_y((point->x * info.zoom) + info.start_x, (point->y * info.zoom) + info.start_y, point->z);
		my_mlx_pixel_put(&mlx.img, point->win_x, point->win_y, point->color);
		point = point->next;
	}
}

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

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_point	**list;
	t_info	info;
	//Verifie si arguments valables
	if (argc != 2)
		return (0);
	if (!check_file(argv[1]))
		return (0);
		
	mlx = mlx_win_init();
	
	list = lst_init(argv[1]);
	info.start_x = 500;
	info.start_y = 0;
	info.zoom = 20;
	draw_points(mlx, *list, info);
	draw_lines(mlx, *list, info);
	my_lstclear(list);
	free(list);
	
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.img.img, 0, 0);
	mlx_loop(mlx.mlx_ptr);
}
