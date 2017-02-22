/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_test_im.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 11:36:21 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/02/22 19:39:57 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fdf.h"

int			ft_putkeynbr(int keycode, t_mlx *param)
{
	int		si;
	void	*img;
	char	*data;
	float	x;
	float	y;
	float	size;
	int		left;
	int		top;

	size = 100;
	si = 50;
	ft_putnbr(keycode);
	ft_putchar('\n');
	left = 400;
	top = 200;
	size = 400;
	mlx_clear_window(param->mlx, param->win);
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
		size = size * 1.5;
	if (keycode == 78)
		size = size * 0.5;
	if (keycode == 123)
		left -= 10;
	if (keycode == 124)
	{
	img = mlx_xpm_file_to_image(param->mlx, "button_right_arrow_dwn.xpm", &si, &si);
	mlx_put_image_to_window(param->mlx, param->win, img, 100, 750);
	mlx_string_put(param->mlx, param->win, 200, 200, 0x00F1F2F3, "Salut les enfants");
		left += 10;
	}
	if (keycode == 125)
		top += 10;
	if (keycode == 126)
		top -= 10;
	x = 1;
	while (x < size)
	{
		y = -x;
		while ( y < x + 1)
		{
			mlx_pixel_put(param->mlx, param->win, left + (y / 2), top + x, 0x00606060 + 10 * keycode);
		y++;
		}
	x++;
	}
	return (keycode);
}

int			main(void)
{
	t_mlx	*param;
	char	*data;
	char	*img2;
	int		i;
	int		j;
	int		bpp;
	int		size_line;
	int		endian;

	
	i = 0;
	j = 0;
	param = ft_memalloc(sizeof(t_mlx));
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, 800, 800, "mlx 42");
	/*img2 = (char *)mlx_new_image(param->mlx, 300,300);
	while (img2[i])
	{
		img2[i] = 1;
		i++;
	}*/
	if (!(img2 = mlx_new_image(param->mlx, 100, 300)))
		exit(0);
	bpp = 20;
	endian = 0;
	size_line = 100000;
	data = mlx_get_data_addr(img2, &bpp, &size_line, &endian);
	while (i < 120000)
	{	

		data[i + 0] = 0x00 + j;
		data[i + 1] = 0x55 + j;
		data[i + 2] = 0x00 + j;
		data[i + 3] = 0x00;
		if (i % 720 == 0)
			j++;
		i += 4;
	}
	mlx_put_image_to_window(param->mlx, param->win, img2, 200, 200 );
	mlx_key_hook(param->win, ft_putkeynbr, param);
	mlx_loop(param->mlx);
return (0);
}
