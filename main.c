#include "minilibx-linux/mlx.h"



typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	color_pixel(char *pixel)
{
	int				i;
	unsigned int	zn;

	i = 0;
	zn =
	while (i < 100)
	{

		if ()
	}
}

int	main(void)
{
    void    *mlx;
    void    *win;
    t_data  img;
    int     largeur = 800;
    int     hauteur = 600;

    // Initialisation de MiniLibX et création de la fenêtre
    mlx = mlx_init();
    win = mlx_new_window(mlx, largeur, hauteur, "BLUE BLUE BLUE");

    // Création de l'image
    img.img = mlx_new_image(mlx, largeur, hauteur);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    // Remplissage de l'image avec une couleur (bleu ici)
    for (int y = 0; y < hauteur; y++)
    {
        for (int x = 0; x < largeur; x++)
        {
            char *dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
            *(unsigned int *)dst = 0x000000FF; // Couleur bleue
        }
    }

    // Affichage de l'image dans la fenêtre
    mlx_put_image_to_window(mlx, win, img.img, 50, 100);

    // Boucle pour garder la fenêtre ouverte
    mlx_loop(mlx);
}
