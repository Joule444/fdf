/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:26:52 by jthuysba          #+#    #+#             */
/*   Updated: 2022/12/12 13:37:24 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Ecrase l'ancienne image et dessine la nouvelle
void	mlx_refresh_image(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img);
	mlx->img.img = mlx_new_image(mlx->mlx_ptr, 1920, 1080);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
	draw_points(*mlx, *mlx->point);
	draw_lines(*mlx, *mlx->point);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.img, 0, 0);
}

//Execute une action en fonction de la touche pressee
void	mlx_move_keys(int keycode, t_mlx *mlx)
{
	if (keycode == 119)
		move_down(mlx);
	else if (keycode == 97)
		move_right(mlx);
	else if (keycode == 115)
		move_up(mlx);
	else if (keycode == 100)
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
	mlx_refresh_image(mlx);
}
