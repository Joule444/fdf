/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:27:42 by jthuysba          #+#    #+#             */
/*   Updated: 2022/12/05 17:48:19 by jthuysba         ###   ########.fr       */
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

typedef struct s_info
{
	int	start_x;
	int	start_y;
	int	zoom;
}	t_info;

typedef struct	s_mlx {
	void			*mlx_ptr;
	void			*mlx_win;
	t_data			img;
	struct s_point	**point;
	unsigned int	color;
	t_info	info;
}	t_mlx;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
	int				win_x;
	int				win_y;
	struct s_point	*next;
}	t_point;

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
int	iso_y(int x, int y, int z, t_info info);

//Draw
void	draw_points(t_mlx mlx, t_point *point, t_info info);
void	draw_lines(t_mlx mlx, t_point *point, t_info info);

//Z fonctions
int	get_z(int x, int y, t_point *point);
int	get_z_max(t_point *point);

//Utils
void	free_arr(char **arr);

//Moves
void	mlx_move_keys(int keycode, t_mlx mlx);

#endif
