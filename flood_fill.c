#include <stdio.h>
#include <stdlib.h>

typedef struct 	s_point {
	int			x;				// x : Width  | x-axis
	int			y;				// y : Height | y-axis
}				t_point;

// Implementa un algoritmo de flood fill (relleno por inundación) que reemplaza una región conectada de un mismo valor por 'F' en una matriz.
void	fill(char **tab, t_point size, int x, int y, char to_fill)
{
	// Caso base:
	// - fuera de los límites de la matriz
	// - o el carácter actual no coincide con el objetivo a reemplazar
	if (y < 0 || y >= size.y || x < 0 || x >= size.x
		|| tab[y][x] != to_fill)
		return;

	tab[y][x] = 'F';

	// Llamadas recursivas en las 4 direcciones (arriba, abajo, izquierda, derecha)
	fill(tab, size, x - 1, y, to_fill); // izquierda
	fill(tab, size, x + 1, y, to_fill); // derecha
	fill(tab, size, x, y - 1, to_fill); // arriba
	fill(tab, size, x, y + 1, to_fill); // abajo
}

// Función inicial que lanza el flood fill desde el punto de inicio
void	flood_fill(char **tab, t_point size, t_point begin)
{
	// Guarda el carácter inicial que se quiere reemplazar
	fill(tab, size, begin.x, begin.y, tab[begin.y][begin.x]);
}

// Devuelve una copia dinámica y mutable de zone
char**  make_area(char **zone, t_point size)
{
    char **new;

    new = malloc(sizeof(char *) * size.y); // array de filas
    for (int i = 0; i < size.y; ++i)
    {
        new[i] = malloc(size.x + 1);       // reserva fila + '\0'
        for (int j = 0; j < size.x; ++j)
            new[i][j] = zone[i][j];         // copia carácter a carácter
        new[i][size.x] = '\0';
    }
    return new;
}

int main(void)
{
    t_point size = {8, 5};
    char *zone[] = {                        // matriz original (read-only)
        "11111111",
        "10001001",
        "10010001",
        "10110001",
        "11100001",
    };

    char **area = make_area(zone, size);    // copia mutable de zone
    for (int i = 0; i < size.y; ++i)
        printf("%s\n", area[i]);            // imprime matriz inicial
    printf("\n");

    t_point begin = {7, 4};                 // punto de inicio (esquina inferior derecha)
    flood_fill(area, size, begin);
    for (int i = 0; i < size.y; ++i)
        printf("%s\n", area[i]);            // imprime resultado
    return (0);
}