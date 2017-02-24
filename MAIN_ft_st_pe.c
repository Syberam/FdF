#include "src/libft/libft.h"

t_peak	*ft_stock_peaks(char *file_path);

void	*ft_seg_to_img(t_peak p1, t_peak p2);

int		main(int argc, char **argv)
{
	t_peak	*current;
	t_peak	*start;
	void	*img;
	t_mlx	*param;

	param = (t_mlx)ft_memalloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(param->mlx, 800, 800, "segment");
	if (argc == 0)
		return (0);
	start = ft_stock_peaks(argv[1]);
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
	img = ft_seg_to_img(start, current);
	ft_put_image_to_window(param->mlx, param->win, img, 200, 200);
	return (0);
}
