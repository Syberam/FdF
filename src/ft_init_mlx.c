/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 21:38:45 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/15 16:31:31 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

t_mlx			*ft_init_mymlx(t_mlx *param)
{
	t_pers		*pers;
	t_img_par	i_p;
	int			i;

	i = 0;
	param->mlx = mlx_init();
	param->img = mlx_new_image(param->mlx, WI_W + param->w, WI_H + param->h);
	param->data = mlx_get_data_addr(param->img, &i_p.bpp, &i_p.size_line, 
										&i_p.endian);
	pers = ft_pers_init(param);
	return (param);
}
