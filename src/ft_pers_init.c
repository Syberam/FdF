/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pers_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:57:03 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/15 19:31:14 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static int	ft_maxx(t_mlx *param)
{
	int		maxx;
	t_peak	*peak;

	maxx = 0;
	peak = param->start;
	while (peak->next)
	{
		maxx = (peak->y > maxx) ? peak->y : maxx;
		peak = peak->next;
	}
	return (maxx);

}

t_pers		*ft_pers_init(t_mlx *param)
{
	t_pers	*pers;

	pers = (t_pers *)ft_memalloc(sizeof(t_pers));
	pers->zoom = (ft_maxx(param) < 20) ? 10 : 1;
	pers->zoom = (ft_maxx(param) > 50 && ft_maxx(param) <= 150)
												? 5 : pers->zoom;
	pers->zoom = (ft_maxx(param) > 150 && ft_maxx(param) < 200)
												? 2 : pers->zoom;
	pers->x = 2;
	pers->zx = 0;
	pers->yx = 2;
	pers->y = 2;
	pers->zy = 0.2;
	pers->xy = 0;
	pers->pozx = WI_W;
	pers->pozy = WI_H;
	param->pers = pers;
	return (pers);
}
