/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putkeynbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:22:44 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/03/14 17:18:19 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fdf.h"

int	ft_putkeynbr(int keycode, t_mlx *param)
{
	if (keycode == 78)
		param->img->pers->zoom--;
	if (keycode == 69)
		param->img->pers->zoom++;
	return (keycode);
}
