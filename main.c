/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:28:03 by jthuysba          #+#    #+#             */
/*   Updated: 2022/11/21 20:04:16 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <stdio.h>

//Place un pixel
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!(x >= 0 && y >= 0 && x <= 1920 && y <= 1080))
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

//Initialise une fenetre
t_mlx	mlx_win_init(void)
{
	t_mlx	mlx;
	t_data	img;

	mlx.mlx_ptr = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, 1920, 1080, "FdF");
	img.img = mlx_new_image(mlx.mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	mlx.img = img;
	return (mlx);
}

int	iso_x(int x, int y)
{
	return (x - y);
}

int	iso_y(int x, int y, int z)
{
	return ((x + y - z) / 2);
}

int	get_z(char **matrice, int x, int y)
{
	int	i;

	i = 0;
	while (x > 0)
	{
		if (matrice[y][i] == ';')
			x--;
		i++;
	}
	return (ft_atoi(matrice[y] + i));
}

// void	mlx_draw_points(t_mlx mlx, char **matrice, t_coord coord)
// {
// 	int	x;
// 	int	y;
// 	int	win_x;
// 	int	win_y;
// 	int	count_x;
// 	int	count_y;

// 	x = 0;
// 	y = 0;
// 	win_x = coord.start_x;
// 	win_y = coord.start_y;
// 	count_x = 0;
// 	count_y = 0;
// 	while (matrice[y])
// 	{
// 		while (matrice[y][x])
// 		{
// 			if (matrice[y][x] == ';' || matrice[y][x] == '$' || matrice[y][x] == '!')
// 			{
// 				printf("z %d\n", get_z(matrice, win_x / coord.start_x, win_y / coord.start_y));
// 				my_mlx_pixel_put(&mlx.img, iso_x(win_x, win_y), iso_y(win_x, win_y, 0), 0xffffff);
// 				win_x += coord.zoom;
// 				count_x++;
// 			}
// 			x++;
// 		}
// 		x = 0;
// 		win_x = coord.start_x;
// 		y++;
// 		count_y++;
// 		win_y += coord.zoom;
// 	}
// }

// void	mlx_draw_lines(t_mlx mlx, char **matrice, t_coord coord)
// {
// 	int	x;
// 	int	y;
// 	int	win_x;
// 	int	win_y;

// 	x = 0;
// 	y = 0;
// 	win_x = coord.start_x;
// 	win_y = coord.start_y;
// 	while (matrice[y])
// 	{
// 		while (matrice[y][x])
// 		{
// 			if (matrice[y][x] == ';' && matrice[y][ft_strlen(matrice[y]) - 1] != '!')
// 			{
// 				bresenham_line(mlx, iso_x(win_x, win_y), iso_y(win_x, win_y, 0), iso_x(win_x + coord.zoom, win_y), iso_y(win_x + coord.zoom, win_y, 0));
// 				bresenham_line(mlx, iso_x(win_x, win_y), iso_y(win_x, win_y, 0), iso_x(win_x, win_y + coord.zoom), iso_y(win_x, win_y + coord.zoom, 0));
// 				win_x += coord.zoom;
// 			}
// 			else if (matrice[y][x] == '$' && matrice[y][ft_strlen(matrice[y]) - 1] != '!')//Dernier caractere de la ligne
// 				bresenham_line(mlx, iso_x(win_x, win_y), iso_y(win_x, win_y, 0), iso_x(win_x, win_y + coord.zoom), iso_y(win_x, win_y + coord.zoom, 0));
// 			else if (matrice[y][x] == ';' && matrice[y][ft_strlen(matrice[y]) - 1] == '!')//Derniere ligne
// 			{
// 				bresenham_line(mlx, iso_x(win_x, win_y), iso_y(win_x, win_y, 0), iso_x(win_x + coord.zoom, win_y), iso_y(win_x + coord.zoom, win_y, 0));
// 				win_x += coord.zoom;
// 			}
// 			x++;
// 		}
// 		x = 0;
// 		win_x = coord.start_x;
// 		y++;
// 		win_y += coord.zoom;
// 	}
// }

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_point	*elem;

	//Verifie si arguments valables
	if (argc != 2)
		return (0);
	if (!check_file(argv[1]))
		return (0);
	// mlx = mlx_win_init();
	elem = lst_init(argv[1]);
	// mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.img.img, 0, 0);
	// mlx_loop(mlx.mlx_ptr);
}
