/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpeaks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 10:17:44 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/13 16:34:33 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void		*ft_putpeaks(t_peak *peak, t_mlx *param)
{
	t_peak		*down;

	while (peak)
	{
		if (peak->next != NULL && peak->y == (peak->next)->y)
			ft_line_al(peak, peak->next, param);
		if (peak->next)
		{
			down = peak->next;
			while (down->x != peak->x && down->next)
				down = down->next;
			if (down->x == peak->x && down->y == peak->y + 1)
				ft_line_al(peak, down, param);
		}
		peak = peak->next;
	}
	return (param->img);
}
