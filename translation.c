/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:23:06 by jthuysba          #+#    #+#             */
/*   Updated: 2022/12/08 18:25:30 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Transation vers le haut 
void	move_up(t_mlx *mlx)
{
	t_point	*elem;

	elem = *mlx->point;
	while (elem)
	{
		elem->y--;
		elem->win_y -= 20;
		elem = elem->next;
	}
}

//Transation vers la gauche 
void	move_left(t_mlx *mlx)
{
	t_point	*elem;

	elem = *mlx->point;
	while (elem)
	{
		elem->x--;
		elem->win_x -= 20;
		elem = elem->next;
	}
}

//Transation vers le bas 
void	move_down(t_mlx *mlx)
{
	t_point	*elem;

	elem = *mlx->point;
	while (elem)
	{
		elem->y++;
		elem->win_y += 20;
		elem = elem->next;
	}
}

//Transation vers la droite 
void	move_right(t_mlx *mlx)
{
	t_point	*elem;

	elem = *mlx->point;
	while (elem)
	{
		elem->x++;
		elem->win_x += 20;
		elem = elem->next;
	}
}
