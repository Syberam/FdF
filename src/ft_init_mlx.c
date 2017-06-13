/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 21:38:45 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/13 16:11:36 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

t_mlx			*ft_init_mymlx(void)
{
	t_mlx		*param;
	t_pers		*pers;
	t_img_par	i_p;

	if (!(param = (t_mlx *)ft_memalloc(sizeof(t_mlx) + 1)))
		ft_malloc_error();
	param->mlx = mlx_init();
	param->img = mlx_new_image(param->mlx, param->w, param->h);
	param->data = mlx_get_data_addr(param->img, &i_p.bpp, &i_p.size_line, 
										&i_p.endian);
	pers = ft_pers_init(param);
	return (param);
}
