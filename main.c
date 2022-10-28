/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:28:03 by jthuysba          #+#    #+#             */
/*   Updated: 2022/10/28 16:48:35 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <stdio.h>

//Verifie l'extension du fichier
int	check_file(char *file)
{
	int	i;

	i = ft_strlen(file) - 4;
	if (strncmp(file + i, ".fdf", 4) == 0)
		return (1);
	else
		return (0);
}

//Place un pixel
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

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

void	bresenham_line(t_mlx mlx, int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	m;
	int	x;
	int	y;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	m = dy / dx;
	x = x1;
	while (x < x2)
	{
		y = m * x + y1;
		my_mlx_pixel_put(&mlx.img, x, y, 0xffffff);
		x++;
	}
}

//Lit et place une ligne de la map
void	mlx_draw_row(t_mlx mlx, char *line, int y, int zoom)
{
	int		x;
	int		z;
	int		i;
	char	**arr;
	char	**parts;
	char	*color;

	x = 500;
	i = 0;
	arr = ft_split(line, ' ');
	while (arr[i])
	{
		parts = ft_split(arr[i], ',');
		//OSEF POUR LINSTANT
		if (ft_strchr(arr[i], ',') != NULL)
		{
			color = malloc(sizeof(char) * ft_strlen(parts[1]));
			ft_strlcpy(color, parts[1], ft_strlen(parts[1]));
		}
		else
			color = (char *) 0xffffff;
		z = ft_atoi(parts[0]);
		my_mlx_pixel_put(&mlx.img, (x - y), ((x + y - z) / 2), color);
		bresenham_line(mlx, (x - y), ((x + y - z) / 2), (x + zoom - y), ((x + zoom + y - z) / 2));
		i++;
		x += zoom;
	}
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	char	*line;
	int		fd;
	char	**arr;
	int		y;
	int		zoom;

	zoom = 10;
	y = 0;
	if (argc != 2)
		return (0);
	if (!check_file(argv[1]))
		return (0);
	mlx = mlx_win_init();
	fd = open(argv[1], O_RDONLY, 777);
	line = get_next_line(fd);
	while (line)
	{
		mlx_draw_row(mlx, line, y, zoom);
		y += zoom;
		printf("%s", line);
		line = get_next_line(fd);
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.img.img, 0, 0);
	mlx_loop(mlx.mlx_ptr);
}
