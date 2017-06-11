/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_z.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 21:10:05 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/08 15:35:25 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	ft_rotate_z(int keycode, t_mlx *param)
{
	if (keycode == KEY_ROT_R)
		param->pers->xy--;
	if (keycode == KEY_ROT_D)
		param->pers->y--;
	if (keycode == KEY_ROT_L)
		param->pers->y++;
	if (keycode == KEY_ROT_U)
		param->pers->xy++;
}
