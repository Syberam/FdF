/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpeaks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 10:17:44 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/03/23 22:34:33 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inude "src/fdf.h"

void		*ft_putpeaks(t_peak *peak, t_mlx *param)
{
	void	*img;
	char	*data;
	int		bpp;
	int		endian;
	int		size_line;
	t_peak	*down;
	
	if (param->imgs->img)
		mlx_destroy_image(param->mlx, param->imgs->img);
	if (!(img = mlx_new_image(param->mlx, peak->w, peak->h)))
		exit (0);
	bpp = 32;
	endian = 0;
	size_line = peak->w ;
	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	while (peak)
	{
	/*	if (peak->xx + peak->w / 2 >= 0 && peak->xx - peak->w / 2 < 1000
			&& peak->yy + peak->h / 2 >= 0 && peak->yy - peak->h / 2 < 1000)
		{*/
			if (peak->next != NULL && peak->y == (peak->next)->y)
				ft_line_al(peak, peak->next, data);
			if (peak->next)
			{
				down = peak->next;
				while (down->x != peak->x && down->next)
					down = down->next;
				if (down->x == peak->x && down->y == peak->y + 1)
					ft_line_al(peak, down, data);
					/*ft_line_antal(peak, down, param);*/
			}
	/*	}*/
		peak = peak->next;
	}
	return (img);
}
