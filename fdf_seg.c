/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_seg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 19:44:29 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/02/21 20:30:40 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fdf.h"

typedef struct		s_pix;
{
	int		x;
	int		y;
	int		color;
	s_pix	*next;
}					t_pix;

t_pix	ft_get_pixel(int x, int y, int color, t_pix *begin)
{
	t_pix	*current;

	current = begin; 
	pixel = ft_memalloc(sizeof(t_pix));
}

void	ft_putseg(t_pix pix1, t_pix pix2, void	*param)
{
	int		x;
	int		xi;
	int		y;
	int		yi;
	int		color;

	x = pix2->x - pix1->x
	y = pix2->y - pix1->y
	xi = 0;
	yi = 0;
	color = (pix2->color - pix1->color < 0 ? -(pix2->color - pix1->color) : pix1->color-pix2->color);
	while (xi <= x)
	{
		yi = (pix1->x/pix1->y) * xi;  
		mlx_pixel_put(param->mlx, param->win, pix1->x + xi, pix1->y + yi, pix1->color);
	}
}

int		main(int argc, char **argv)
{
	t_mlx		*param;
	t_pix		*pixel;

	if (argc < 2)
		ft_putstr("usage : fdf <nom_fichier.fdf>");
	si = 50;
	param = ft_memalloc(sizeof(t_mlx));
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, 800,800, "mlx 42");
	fd = (const int)open(argv[1], O_RDONLY);
	y = 0;
	while (get_next_line(fd, &line) != 0)
	{
		point = ft_strsplit(line, ' ');
		x = 0;
		while (point[x])
		{
			z = ft_atoi(point[x]);
		mlx_string_put(param->mlx, param->win, 100 + 30 * x, 100 + 30 * y, 0x00123456+ 100 * z, point[x]);
			x++;
		}
		y++;
	}
	mlx_loop(param->mlx);
}
