#include "src/fdf.h"

int	ft_putkeynbr(int keycode, t_mlx *param)
{
	int		si;
	void	*img;
	float		x;
	float		y;
	float		size;
	int			left;
	int			top;

	size = 100;
	si = 50;
	ft_putnbr(keycode);
	ft_putchar('\n');
	x = 1;
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
	void	*img2;
	int		si;
	
	si = 50;
	param = ft_memalloc(sizeof(t_mlx));
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, 800, 800, "mlx 42");
	img2 = mlx_xpm_file_to_image(param->mlx, "button_right_arrow.xpm", &si, &si);
	mlx_put_image_to_window(param->mlx, param->win, img2, 100, 750);
	mlx_key_hook(param->win, ft_putkeynbr, param);
	mlx_loop(param->mlx);
return (0);
}
