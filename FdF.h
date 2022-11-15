/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:27:42 by jthuysba          #+#    #+#             */
/*   Updated: 2022/11/15 13:32:06 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H

#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include "./mlx/mlx.h"
#include "./libft/libft.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_mlx {
	void	*mlx_ptr;
	void	*mlx_win;
	t_data	img;
}				t_mlx;

int	check_file(char *file);

//MLX
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//Algo
void	bresenham_line(t_mlx mlx, int x1, int y1, int x2, int y2);
int	iso_x(int x, int y);
int	iso_y(int x, int y, int z);

//Utils
void	free_arr(char **arr);

#endif
