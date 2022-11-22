/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:27:42 by jthuysba          #+#    #+#             */
/*   Updated: 2022/11/22 13:58:30 by jthuysba         ###   ########.fr       */
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

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
	int				iso_x;
	int				iso_y;
	struct s_point	*next;
}	t_point;

//Check Error
int		check_file(char *file);

//MLX
t_mlx	mlx_win_init(void);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//Initialisation liste
t_point	**lst_init(char *file);

//Fonctions de liste
t_point	*my_lstnew(int x, int y, int z, unsigned int color);
t_point	*my_lstlast(t_point *lst);
void	my_lstadd_back(t_point **lst, t_point *new);
void	my_lstclear(t_point **lst);

//Bresenham
void	bresenham_line(t_mlx mlx, int x1, int y1, int x2, int y2);
void	octant_0(t_mlx mlx, int x1, int y1, int x2, int y2);
void	octant_1(t_mlx mlx, int x1, int y1, int x2, int y2);
void	octant_6(t_mlx mlx, int x1, int y1, int x2, int y2);
void	octant_7(t_mlx mlx, int x1, int y1, int x2, int y2);

//Isometrie
int		iso_x(int x, int y);
int		iso_y(int x, int y, int z);

//Utils
void	free_arr(char **arr);

#endif
