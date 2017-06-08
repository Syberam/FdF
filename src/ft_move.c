/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putkeynbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:22:44 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/08 17:50:27 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	ft_move(int keycode, t_mlx *param)
{
	if (keycode == 86 || keycode == 89 || keycode == 83)
		param->pers->pozx -= 30;
	if (keycode == 88 || keycode == 85 || keycode == 92)
		param->pers->pozx += 30;
	if (keycode == 84 || keycode == 85 || keycode == 83)
		param->pers->pozy += 30;
	if (keycode == 91 || keycode == 89 || keycode == 92)
		param->pers->pozy -= 30;
	if (keycode == 87)
	{
		param->pers->pozx = 0;
		param->pers->pozy = 0;
	}
}
