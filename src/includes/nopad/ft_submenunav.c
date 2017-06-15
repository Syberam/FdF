/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_submenunav.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 21:42:28 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/15 21:42:54 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void		ft_menu(t_mlx *param)
{
	mlx_string_put(param->mlx, param->win, 100, 40, 0x00FFFFFF, " Q  W  E");
	mlx_string_put(param->mlx, param->win, 100, 70, 0x00FFFFFF, " A  S  D");
	mlx_string_put(param->mlx, param->win, 100, 100, 0x00FFFFFF, " Z  X  C");
}
