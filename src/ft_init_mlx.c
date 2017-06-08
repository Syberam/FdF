/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 21:38:45 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/08 21:51:31 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

t_mlx		*ft_init_mymlx(void)
{
	t_mlx	*param;
	t_pers	*pers;

	if (!(param = (t_mlx *)ft_memalloc(sizeof(t_mlx) + 1)))
		ft_malloc_error();
	if (!(param->imgs = (t_fdfi *)ft_memalloc(sizeof(t_fdfi) + 1)))
		ft_malloc_error();
	param->mlx = mlx_init();
	pers = ft_pers_init(param);
	return (param);
}
