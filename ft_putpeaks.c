/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpeaks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 10:17:44 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/03/10 13:39:06 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fdf.h"

void		*ft_putpeaks(t_peak *peak, t_mlx *param)
{
	void	*img;
	char	*data;
	int		bpp;
	int		endian;
	int		size_line;
	t_peak	*down;

	ft_putnbr(peak->w);
	ft_putchar('\t');
	ft_putnbr(peak->h);
	ft_putchar('\n');
	if (!(img = mlx_new_image(param->mlx, peak->w, peak->h)))
		exit (0);
	bpp = 32;
	endian = 0;
	size_line = peak->w ;
	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
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
