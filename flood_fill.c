typedef struct 	s_point {
	int			x;				// x : Width  | x-axis
	int			y;				// y : Height | y-axis
}				t_point;

// Implementa un algoritmo de flood fill (relleno por inundación) que reemplaza una región conectada de un mismo valor por 'F' en una matriz.
void	fill(char **tab, t_point size, int x, int y, char to_fill)
{
	if (y < 0 || y >= size.y || x < 0 || x >= size.x
		|| tab[y][x] != to_fill)
		return;

	tab[y][x] = 'F';
	fill(tab, size, x - 1, y, to_fill);
	fill(tab, size, x + 1, y, to_fill);
	fill(tab, size, x, y - 1, to_fill);
	fill(tab, size, x, y + 1, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin.x, begin.y, tab[begin.y][begin.x]);
}

