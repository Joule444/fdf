/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:26:52 by jthuysba          #+#    #+#             */
/*   Updated: 2022/12/06 19:08:25 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	move_up(t_mlx mlx)
{
	t_point	*elem;

	elem = *mlx.point;
	while (elem)
	{
		elem->win_y -= 5;
		elem = elem->next;
	}
}

void	move_left(t_mlx mlx)
{
	t_point	*elem;

	elem = *mlx.point;
	while (elem)
	{
		elem->win_x -= 5;
		elem = elem->next;
	}
}

void	move_down(t_mlx mlx)
{
	t_point	*elem;

	elem = *mlx.point;
	while (elem)
	{
		elem->win_y += 5;
		elem = elem->next;
	}
}

void	move_right(t_mlx mlx)
{
	t_point	*elem;

	elem = *mlx.point;
	while (elem)
	{
		elem->win_x += 5;
		elem = elem->next;
	}
}

// void	z_up(t_mlx mlx)
// {
// 	t_point	*elem;
// 	int		zoom_x;
// 	int		zoom_y;

// 	elem = *mlx.point;
// 	while (elem)
// 	{
// 		elem->z *= 1.1;
// 		zoom_x = (elem->x * mlx.info.zoom) + mlx.info.start_x;
// 		zoom_y = (elem->y * mlx.info.zoom) + mlx.info.start_y;
// 		elem->win_x = iso_x(zoom_x, zoom_y);
// 		elem->win_y = iso_y(zoom_x, zoom_y, elem->z, mlx.info);
// 		elem = elem->next;
// 	}
// 	printf("z up ");
// }

// void	z_down(t_mlx mlx)
// {
// 	t_point	*elem;
// 	int		zoom_x;
// 	int		zoom_y;

// 	elem = *mlx.point;
// 	while (elem)
// 	{
// 		elem->z /= 1.1;
// 		zoom_x = (elem->x * mlx.info.zoom) + mlx.info.start_x;
// 		zoom_y = (elem->y * mlx.info.zoom) + mlx.info.start_y;
// 		elem->win_x = iso_x(zoom_x, zoom_y);
// 		elem->win_y = iso_y(zoom_x, zoom_y, elem->z, mlx.info);
// 		elem = elem->next;
// 	}
// 	printf("z down ");
// }

void	zoom_in(t_mlx mlx)
{
	mlx.info.zoom *= 2;
}

void	zoom_out(t_mlx mlx)
{
	mlx.info.zoom /= 2;
}

void	change_color(t_mlx mlx)
{
	mlx.color += 100;
	mlx_destroy_image(mlx.mlx_ptr, mlx.img.img);
	mlx.img.img = mlx_new_image(mlx.mlx_ptr, 1920, 1080);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length,
			&mlx.img.endian);
	draw_lines(mlx, *mlx.point, mlx.info);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.img.img, 0, 0);
}

void	mlx_move_keys(int keycode, t_mlx mlx)
{
	if (keycode == 119) //W
		move_up(mlx);
	else if (keycode == 97) //A
		move_left(mlx);
	else if (keycode == 115) //S
		move_down(mlx);
	else if (keycode == 100) //D
		move_right(mlx);
	// else if (keycode == 65362)
	// 	z_up(mlx);
	// else if (keycode == 65364)
	// 	z_down(mlx);
	// else if (keycode == 65451)
	// 	zoom_in(mlx);
	// else if (keycode == 65453)
	// 	zoom_out(mlx);
	else if (keycode == 99)
		return (change_color(mlx));
	else
		return ;
	mlx_destroy_image(mlx.mlx_ptr, mlx.img.img);
	mlx.img.img = mlx_new_image(mlx.mlx_ptr, 1920, 1080);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length,
			&mlx.img.endian);
	draw_lines(mlx, *mlx.point, mlx.info);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.img.img, 0, 0);
}
