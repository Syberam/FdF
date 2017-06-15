/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_submenunav.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 21:42:03 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/15 21:42:07 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void		ft_submenunav(t_mlx *param)
{
	mlx_string_put(param->mlx, param->win, 100, 40, 0x00FFFFFF, " 7  8  9");
	mlx_string_put(param->mlx, param->win, 100, 70, 0x00FFFFFF, " 4  5  6");
	mlx_string_put(param->mlx, param->win, 100, 100, 0x00FFFFFF, " 1  2  3");
}
