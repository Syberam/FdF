#include "src/fdf.h"

int		main(int argc, char **argv)
{
	t_peak	*current;
	t_peak	*start;
	t_dffi	*im;
	t_mlx	*param;

	param = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	param->mlx = mlx_init();
	param->img = im;
	param->win = mlx_new_window(param->mlx, 1800, 1200, "segment");
	if (argc == 0)
		return (0);
	start = ft_stock_peaks(argv[1]);
	ft_peaks_to_plan(start);
	current = start;
	param->img = ft_putpeaks(start, param);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 5, 5);
	mlx_key_hook(param->win, ft_putkeynbr, param);
	mlx_loop(param->mlx);
	return (0);
}
