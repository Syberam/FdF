/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putkeynbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:22:44 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/15 01:22:50 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	ft_move(int keycode, t_mlx *param)
{
	if (keycode == KEY_L || keycode == KEY_UPL || keycode == KEY_DL)
		param->pers->pozx -= 30;
	if (keycode == KEY_R || keycode == KEY_UPR || keycode == KEY_DR)
		param->pers->pozx += 30;
	if (keycode == KEY_DOWN || keycode == KEY_DR || keycode == KEY_DL)
		param->pers->pozy += 30;
	if (keycode == KEY_UP || keycode == KEY_UPL || keycode == KEY_UPR)
		param->pers->pozy -= 30;
	if (keycode == KEY_C)
	{
		param->pers->pozx = 0;
		param->pers->pozy = 0;
	}
}
