/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 21:06:32 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/13 15:31:28 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	ft_rotate_x(int keycode, t_mlx *param)
{
	if (keycode == KEY_ZPP_U)
	{
		param->pers->yx++;
		param->pers->xy--;
	}
	if (keycode == KEY_ZPP_D)
	{
		param->pers->yx--;
		param->pers->xy++;
	}
}
