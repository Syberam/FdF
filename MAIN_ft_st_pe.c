#include "src/fdf.h"

int		main(int argc, char **argv)
{
	t_peak	*current;
	t_peak	*start;
	t_mlx	*param;
	t_pers	*pers;
	void	*image;

	if (argc != 2)
		return (0);
	param = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	param->imgs = (t_fdfi *)ft_memalloc(sizeof(t_fdfi));
	param->imgs->img = (void *)ft_memalloc(sizeof(void));
	param->imgs->start = (t_peak *)ft_memalloc(sizeof(t_peak));
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, 1800, 1200, argv[1]);
	pers = ft_pers_init(param);
	start = ft_stock_peaks(argv[1]);
	ft_peaks_to_plan(start, pers);
	current = start;
	image = ft_putpeaks(start, param);
	param->imgs->img = image;
	param->imgs->start = start;
	mlx_put_image_to_window(param->mlx, param->win, image,
			((1800 - param->imgs->start->w) / 2),
			((1200 - param->imgs->start->h) / 2));
	ft_menu(param);
	mlx_hook(param->win, 2, 3, ft_putkeynbr, param);
	mlx_hook(param->win, 3, 3, ft_keymenu, param);
	mlx_loop(param->mlx);
	return (0);
}
