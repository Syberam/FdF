#include "src/fdf.h"

int		main(int argc, char **argv)
{
	t_peak	*current;
	t_peak	*start;
	void	*img;
	t_mlx	*param;

	param = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, 800, 800, "segment");
	if (argc == 0)
		return (0);
	start = ft_stock_peaks(argv[1]);
	ft_peaks_to_plan(start);
	current = start;
	while (current->next)
	{
		ft_putnbr(current->x);
		ft_putchar('\t');
		ft_putnbr(current->y);
		ft_putchar('\t');
		ft_putnbr(current->z);
		ft_putchar('\n');
		current = current->next;
	}
	img = ft_putpeaks(start, param);
	mlx_put_image_to_window(param->mlx, param->win, img, 100, 100);
	mlx_loop(param->mlx);
	return (0);
}
