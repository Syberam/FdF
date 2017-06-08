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
	if (keycode == 123)
		param->pers->xy--;
	if (keycode == 125)
		param->pers->y--;
	if (keycode == 126)
		param->pers->y++;
	if (keycode == 124)
		param->pers->xy++;
}
