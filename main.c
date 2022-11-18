/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:28:03 by jthuysba          #+#    #+#             */
/*   Updated: 2022/11/18 15:01:30 by jthuysba         ###   ########.fr       */
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

//Lit et place une ligne de la map
void	mlx_draw_row(t_mlx mlx, char *line, int y, int zoom)
{
	int			x;
	int			z;
	int			i;
	char		**arr;
	char		**parts;
	unsigned int	color;

	x = 200;
	i = 0;
	arr = ft_split(line, ' ');
	while (arr[i])
	{
		parts = ft_split(arr[i], ',');
		if (ft_strchr(arr[i], ',') != NULL)
			color = ft_atoi(parts[1]);
		else
			color = 0xffffff;
		z = ft_atoi(parts[0]);
		my_mlx_pixel_put(&mlx.img, iso_x(x, y), iso_y(x, y, z), color);
		// my_mlx_pixel_put(&mlx.img, x, y, color);
		i++;
		x += zoom;
		free_arr(parts);
	}
	free_arr(arr);
}

// int	main(int argc, char **argv)
// {
// 	t_mlx	mlx;
// 	char	*line;
// 	int		fd;
// 	char	**arr;
// 	int		y;
// 	int		zoom;
// 	zoom = 10;
// 	y = 0;
// 	if (argc != 2)
// 		return (0);
// 	if (!check_file(argv[1]))
// 		return (0);
// 	mlx = mlx_win_init();
// 	fd = open(argv[1], O_RDONLY, 777);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		mlx_draw_row(mlx, line, y, zoom);
// 		y += zoom;
// 		printf("%s", line);
// 		line = get_next_line(fd);
// 	}
	// mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.img.img, 0, 0);
	// mlx_loop(mlx.mlx_ptr);
// }

void	mlx_draw_points(t_mlx mlx, int **matrice, unsigned int **color_matrice)
{
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	int		fd;
	char	**matrice;
	char	**color_matrice;
	int i;

	i = 0;
	//Verifie si arguments valables
	if (argc != 2)
		return (0);
	if (!check_file(argv[1]))
		return (0);
	// mlx = mlx_win_init();
	matrice = matrice_init(argv[1]);
	// color_matrice = color_matrice_init(argv[1]);
	// mlx_draw_points(mlx, matrice, color_matrice);
	free_arr(matrice);
	// mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.img.img, 0, 0);
	// mlx_loop(mlx.mlx_ptr);
}
