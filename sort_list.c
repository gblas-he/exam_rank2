#include <unistd.h>

typedef struct s_list t_list;

struct s_list {
    int data;
    t_list *next;
};

// Ordena una lista enlazada intercambiando los valores de los nodos según la función de comparación proporcionada.
t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int	swap;
	t_list	*tmp;

	tmp = lst; // Guarda el inicio de la lista
	while(lst->next != NULL) // Se detiene en el penúltimo para poder comparar con lst->next
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0) // Si están desordenados compara un nodo con el siguiente
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp; // Vuelve al inicio para verificar de nuevo pq puede estar. Es como i = 0 en sort_int_tab
			// desordenado los nodos anteriores ya que arregla hasta el final un nodo pero los demas no
		}
		else
			lst = lst->next;
	}
	lst = tmp; // Restaura el puntero al inicio
	return (lst);
}