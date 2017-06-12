/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:36:04 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/12 03:55:35 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int		main(int argc, char **argv)
{
	t_mlx	*param;
	t_pers	*pers;
	t_peak	*current;
	t_peak	*start;

	if (argc < 1)
		return (0);
	if (!(start = ft_parsing_file(argv)))
		return (0);
	param = ft_init_mymlx();
	start = ft_stock_peaks(start, argv[1], param);
	pers = ft_pers_init(param);
	ft_peaks_to_plan(start, pers);
	current = start;
	param->img = ft_putpeaks(start, param, argv[1]);
	param->start = start;
	param->win = mlx_new_window(param->mlx, 1800, 1200, argv[1]);
	mlx_hook(param->win, 2, 3, ft_putkeynbr, param);
	mlx_hook(param->win, 3, 3, ft_keymenu, param);
	mlx_put_image_to_window(param->mlx, param->win, param->img,
	((1800 - param->start->w) / 2), ((1200 - param->start->h) / 2));
	ft_menu(param);
	mlx_loop(param->mlx);
	return (0);
}
