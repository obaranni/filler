#include "../../inc/filler.h"

void		init_window(t_filler *f)
{
	f->win.mlx = mlx_init();
	f->win.win = mlx_new_window(f->win.mlx, WIN_W, WIN_H, "FILLER");
	f->win.img_m = mlx_new_image(f->win.mlx, 600, WIN_H);
	f->win.data_m = mlx_get_data_addr(f->win.img_m, &(f->win.bpp),
								  &(f->win.size_line), &(f->win.endian));
}

void		visualize_players(t_filler *f)
{
	f->win.img_l = mlx_new_image(f->win.mlx, IMG_LR_W, WIN_H);
	f->win.img_r = mlx_new_image(f->win.mlx, IMG_LR_W, WIN_H);
	f->win.data_l = mlx_get_data_addr(f->win.img_l, &(f->win.bpp),
									  &(f->win.size_line), &(f->win.endian));
	f->win.data_r = mlx_get_data_addr(f->win.img_r, &(f->win.bpp),
									  &(f->win.size_line), &(f->win.endian));

	int i = 0;
	int j = 0;

	while (i < WIN_H)
	{
		int color;
		color = 20002424;
		ft_memcpy(f->win.data_l + (j * 4 + i * f->win.size_line), &color, 4);
		color = 16711680;
		ft_memcpy(f->win.data_r + (j * 4 + i * f->win.size_line), &color, 4);
		j++;
        if (j == IMG_LR_W)
        {
            j = 0;
            i++;
        }
	}


	mlx_put_image_to_window(f->win.mlx, f->win.win, f->win.img_l, 0, 0);
	mlx_put_image_to_window(f->win.mlx, f->win.win, f->win.img_r, IMG_LR_W + IMG_M_W, 0);
}

int			visualize_game(t_filler *f)
{
    mlx_destroy_image(f->win.mlx, f->win.img_m);
    f->win.img_m = mlx_new_image(f->win.mlx, IMG_M_W, WIN_H);
    f->win.data_m = mlx_get_data_addr(f->win.img_m, &(f->win.bpp),
                                      &(f->win.size_line), &(f->win.endian));

    int i = 0;
    int j = 0;

    while (i < WIN_H)
    {
        int color;
        color = 65280;
        ft_memcpy(f->win.data_m + (j * 4 + i * f->win.size_line), &color, 4);
        j++;
        if (j == IMG_M_W)
        {
            j = 0;
            i++;
        }
    }

	mlx_put_image_to_window(f->win.mlx, f->win.win, f->win.img_m, IMG_LR_W, 0);
	return (0);
}