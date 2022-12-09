/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:28:03 by jthuysba          #+#    #+#             */
/*   Updated: 2022/12/09 17:10:02 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <stdio.h>

//Definie le zoom en fonction de la taille de la carte
t_scale	scale(t_mlx mlx)
{
	t_scale	scale;

	scale.start_x = 700;
	scale.start_y = -100;
	if (my_lstsize(*mlx.point) < 100)
		scale.zoom = 60;
	if (my_lstsize(*mlx.point) >= 100 && my_lstsize(*mlx.point) <= 300)
		scale.zoom = 37;
	if (my_lstsize(*mlx.point) > 300 && my_lstsize(*mlx.point) <= 400)
		scale.zoom = 30;
	if (my_lstsize(*mlx.point) > 400 && my_lstsize(*mlx.point) <= 500)
		scale.zoom = 20;
	if (my_lstsize(*mlx.point) > 500 && my_lstsize(*mlx.point) <= 2000)
		scale.zoom = 19;
	if (my_lstsize(*mlx.point) > 2000 && my_lstsize(*mlx.point) <= 3000)
		scale.zoom = 13;
	if (my_lstsize(*mlx.point) > 3000 && my_lstsize(*mlx.point) <= 10000)
		scale.zoom = 9;
	if (my_lstsize(*mlx.point) > 10000 && my_lstsize(*mlx.point) <= 50000)
		scale.zoom = 4;
	if (my_lstsize(*mlx.point) > 50000 && my_lstsize(*mlx.point) <= 100000)
		scale.zoom = 3;
	if (my_lstsize(*mlx.point) > 100000)
		scale.zoom = 2;
	return (scale);
}

//Ferme la fenetre
int	mlx_close_window(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

//Quand une touche est pressee
int	mlx_keypress(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		mlx_close_window(mlx);
	else
		mlx_move_keys(keycode, mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		return (0);
	if (!check_file(argv[1]))
		return (0);
	mlx = mlx_win_init();
	mlx.point = lst_init(argv[1]);
	mlx.scale = scale(mlx);
	mlx.color = 0xffffff;
	draw(mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.img.img, 0, 0);
	mlx_key_hook(mlx.mlx_win, mlx_keypress, &mlx);
	mlx_hook(mlx.mlx_win, 17, 1L << 17, mlx_close_window, &mlx);
	mlx_loop(mlx.mlx_ptr);
	my_lstclear(mlx.point);
	free(mlx.img.img);
	return (0);
}
