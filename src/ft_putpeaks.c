/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpeaks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 10:17:44 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/12 03:49:42 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void		*ft_putpeaks(t_peak *peak, t_mlx *param, char *data)
{
	void		*img;
	t_img_par	i_p;
	t_peak		*down;

	img = NULL;
	if (img)
		mlx_destroy_image(param->mlx, param->img);
	img = mlx_new_image(param->mlx, peak->w, peak->h);
	param->img = img;
	data = mlx_get_data_addr(img, &i_p.bpp, &i_p.size_line, &i_p.endian);
	while (peak)
	{
		if (peak->next != NULL && peak->y == (peak->next)->y)
			ft_line_al(peak, peak->next, data);
		if (peak->next)
		{
			down = peak->next;
			while (down->x != peak->x && down->next)
				down = down->next;
			if (down->x == peak->x && down->y == peak->y + 1)
				ft_line_al(peak, down, data);
		}
		peak = peak->next;
	}
	return (img);
}
