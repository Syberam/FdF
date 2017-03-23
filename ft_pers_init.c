/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pers_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:57:03 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/03/23 21:47:53 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fdf.h"

t_pers *ft_pers_init(t_mlx *param)
{
	t_pers	*pers;

	pers = (t_pers *)ft_memalloc(sizeof(t_pers));
	pers->zoom = 1;
	pers->x = 2;
	pers->zx = 0;
	pers->yx = 2;
	pers->y = 2;
	pers->zy = 0.2;
	pers->xy = 0;
	param->pers = pers;
	return (pers);
}
