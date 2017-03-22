#include "src/fdf.h"

t_pers	*ft_pers_init(t_mlx *param)
{
	t_pers	*pers;

	pers = (t_pers *)ft_memalloc(sizeof(t_pers));
	pers->zoom = 1;
	pers->x = 2;
	pers->zx = 0;
	pers->yx = 2;
	pers->y = 2;
	pers->zy = 5;
	pers->xy = 0;
	param->pers = pers;
	return (pers);
}

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
	param->win = mlx_new_window(param->mlx, 1800, 1200, "segment");
	pers = ft_pers_init(param);
	start = ft_stock_peaks(argv[1]);
	ft_peaks_to_plan(start, pers);
	current = start;
	image = ft_putpeaks(start, param);
	mlx_put_image_to_window(param->mlx, param->win, image, ((1800 - param->imgs->start->w) / 2), ((1200 - param->imgs->start->h) / 2));
	param->imgs->img = image;
	param->imgs->start = start;
	mlx_do_key_autorepeaton(param->mlx);
	/*mlx_key_hook(param->win, ft_putkeynbr, param);*/
	mlx_hook(param->win, 2, 3, ft_putkeynbr, param);
	mlx_loop(param->mlx);
	return (0);
}
