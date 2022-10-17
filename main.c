/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:28:03 by jthuysba          #+#    #+#             */
/*   Updated: 2022/10/17 16:44:11 by jthuysba         ###   ########.fr       */
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_mlx	mlx_win_init(void)
{
	t_mlx	mlx;
	t_data	img;

	mlx.mlx_ptr = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, 640, 360, "FdF");
	img.img = mlx_new_image(mlx.mlx_ptr, 640, 360);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx.img = img;
	// my_mlx_pixel_put(&img, 10, 10, 0x00FF0000);
	// mlx_put_image_to_window(mlx.mlx_ptr, mlx_win, img.img, 0, 0);
	return (mlx);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	char	*line;
	int		fd;
	char	**arr;
	int		x;
	int		y;

	x = 0;
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
		arr = ft_split(line, ' ');
		while (arr[x])
		{
			if (arr[x][0] == '0')
				my_mlx_pixel_put(&mlx.img, x, y, 0xFFFFFFF);
			else
				my_mlx_pixel_put(&mlx.img, x, y, 0xFFF0909);
			x++;
		}
		y++;
		x = 0;
		printf("%s", line);
		line = get_next_line(fd);
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.img.img, 0, 0);
	mlx_loop(mlx.mlx_ptr);
}
