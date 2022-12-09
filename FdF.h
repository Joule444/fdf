/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:27:42 by jthuysba          #+#    #+#             */
/*   Updated: 2022/12/09 16:44:07 by jthuysba         ###   ########.fr       */
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
}	t_data;

typedef struct s_scale
{
	int	start_x;
	int	start_y;
	int	zoom;
}	t_scale;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
	int				win_x;
	int				win_y;
	int				real_z;
	struct s_point	*next;
}	t_point;

typedef struct	s_mlx {
	void			*mlx_ptr;
	void			*mlx_win;
	t_data			img;
	struct s_point	**point;
	t_scale			scale;
	unsigned int	color;
}	t_mlx;

//Check Error
int		check_file(char *file);

//MLX
t_mlx	mlx_win_init(void);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//Initialisation de la liste
t_point	**lst_init(char *file);

//Fonctions de liste
t_point	*my_lstnew(int x, int y, int z);
t_point	*my_lstlast(t_point *lst);
void	my_lstadd_back(t_point **lst, t_point *new);
void	my_lstclear(t_point **lst);
int		my_lstsize(t_point *point);

//Bresenham
void	bresenham_line(t_mlx mlx, t_point *p1, t_point *p2);
void	octant_0(t_mlx mlx, t_point *p1, t_point *p2);
void	octant_1(t_mlx mlx, t_point *p1, t_point *p2);
void	octant_6(t_mlx mlx, t_point *p1, t_point *p2);
void	octant_7(t_mlx mlx, t_point *p1, t_point *p2);

//Isometrie
int		iso_x(int x, int y);
int		iso_y(int x, int y, int z, t_scale scale);

//Draw
void	set_points(t_mlx mlx, t_point *point);
void	draw_points(t_mlx mlx, t_point *point);
void	draw_lines(t_mlx mlx, t_point *point);
void	draw(t_mlx mlx);

//Moves
void	mlx_move_keys(int keycode, t_mlx *mlx);
void	z_up(t_mlx *mlx);
void	z_down(t_mlx *mlx);
void	zoom_in(t_mlx *mlx);
void	zoom_out(t_mlx *mlx);
void	change_color(t_mlx *mlx);

//Translation
void	move_up(t_mlx *mlx);
void	move_left(t_mlx *mlx);
void	move_down(t_mlx *mlx);
void	move_right(t_mlx *mlx);

//Utils
void	free_arr(char **arr);

#endif
