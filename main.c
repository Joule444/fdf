/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:28:03 by jthuysba          #+#    #+#             */
/*   Updated: 2022/12/06 17:19:13 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <stdio.h>
 
t_info	scale(t_mlx mlx)
{
	t_info	info;
	
	info.start_x = 700;
	info.start_y = -100;
	if (my_lstsize(*mlx.point) < 100)
		info.zoom = 60;
	if (my_lstsize(*mlx.point) >= 100 && my_lstsize(*mlx.point) <= 200)
		info.zoom = 37;
	if (my_lstsize(*mlx.point) > 200 && my_lstsize(*mlx.point) <= 300)
		info.zoom = 35;
	if (my_lstsize(*mlx.point) > 300 && my_lstsize(*mlx.point) <= 400)
		info.zoom = 30;
	if (my_lstsize(*mlx.point) > 400 && my_lstsize(*mlx.point) <= 500)
		info.zoom = 20;
	if (my_lstsize(*mlx.point) > 500 && my_lstsize(*mlx.point) <= 2000)
		info.zoom = 19;
	if (my_lstsize(*mlx.point) > 2000 && my_lstsize(*mlx.point) <= 3000)
		info.zoom = 13;
	if (my_lstsize(*mlx.point) > 3000 && my_lstsize(*mlx.point) <= 10000)
		info.zoom = 9;
	if (my_lstsize(*mlx.point) > 10000 && my_lstsize(*mlx.point) <= 50000)
		info.zoom = 4;
	if (my_lstsize(*mlx.point) > 50000 && my_lstsize(*mlx.point) <= 100000)
		info.zoom = 3;
	if (my_lstsize(*mlx.point) > 100000)
		info.zoom = 2;
	return (info);
}

int	mlx_keypress(int keycode, t_mlx mlx)
{
	if (keycode == 65307) //Escape
	{
		mlx_destroy_image(mlx.mlx_ptr, mlx.img.img);
		mlx_destroy_window(mlx.mlx_ptr, mlx.mlx_win);
		mlx_destroy_display(mlx.mlx_ptr);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 119 || keycode == 97
		|| keycode == 115 || keycode == 100)
	{
		mlx_move_keys(keycode, mlx);
	}
	return (0);
}

void    print_list(t_point **list)
{
    t_point  *tmp;

    tmp = *list;
    printf("/////////////// LISTE /////////////////\n");
    while (*list)
    {
        printf("[win x] -> %d\n", (*list)->win_x);
		printf("[win y] -> %d\n", (*list)->win_y);
        (*list) = (*list)->next;
    }
    printf("\n////////////// FIN //////////////////\n");
    *list = tmp;

}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	
	//Verifie si arguments valables
	if (argc != 2)
		return (0);
	if (!check_file(argv[1]))
		return (0);

	mlx = mlx_win_init();
	mlx.first_draw = 1;
	mlx.point = lst_init(argv[1]);

	mlx.info = scale(mlx);
	mlx.color = 0xD2B4DE;

	draw_points(mlx, *mlx.point, mlx.info);
	draw_lines(mlx, *mlx.point, mlx.info);

	print_list(mlx.point);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.img.img, 0, 0);
	mlx_key_hook(mlx.mlx_win, mlx_keypress, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
