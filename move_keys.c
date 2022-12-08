/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:26:52 by jthuysba          #+#    #+#             */
/*   Updated: 2022/12/08 17:27:00 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	move_up(t_mlx *mlx)
{
	t_point	*elem;

	elem = *mlx->point;
	while (elem)
	{
		elem->y--;
		elem->win_y -= 20;
		elem = elem->next;
	}
}

void	move_left(t_mlx *mlx)
{
	t_point	*elem;

	elem = *mlx->point;
	while (elem)
	{
		elem->x--;
		elem->win_x -= 20;
		elem = elem->next;
	}
}

void	move_down(t_mlx *mlx)
{
	t_point	*elem;

	elem = *mlx->point;
	while (elem)
	{
		elem->y++;
		elem->win_y += 20;
		elem = elem->next;
	}
}

void	move_right(t_mlx *mlx)
{
	t_point	*elem;

	elem = *mlx->point;
	while (elem)
	{
		elem->x++;
		elem->win_x += 20;
		elem = elem->next;
	}
}

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

void	zoom_in(t_mlx *mlx)
{
	mlx->info.zoom *= 2;
	if (mlx->info.zoom <= 0)
		mlx->info.zoom = 1;
	printf("zoom %d\n", mlx->info.zoom);
	set_points(*mlx, *mlx->point);
}

void	zoom_out(t_mlx *mlx)
{
	mlx->info.zoom /= 2;
	printf("zoom %d\n", mlx->info.zoom);
	set_points(*mlx, *mlx->point);
}

void	change_color(t_mlx *mlx)
{
	mlx->color *= 1.1;
	printf("color %d\n", mlx->color);
}

void	mlx_move_keys(int keycode, t_mlx *mlx)
{
	printf("keycode %d\n", keycode);
	if (keycode == 119) //W
		move_down(mlx);
	else if (keycode == 97) //A
		move_right(mlx);
	else if (keycode == 115) //S
		move_up(mlx);
	else if (keycode == 100) //D
		move_left(mlx);
	else if (keycode == 65362)
		z_up(mlx);
	else if (keycode == 65364)
		z_down(mlx);
	else if (keycode == 65451)
		zoom_in(mlx);
	else if (keycode == 65453)
		zoom_out(mlx);
	else if (keycode == 99)
		change_color(mlx);
	else
		return ;
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img);
	mlx->img.img = mlx_new_image(mlx->mlx_ptr, 1920, 1080);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, &mlx->img.line_length,
			&mlx->img.endian);
	draw_lines(*mlx, *mlx->point);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.img, 0, 0);
}
