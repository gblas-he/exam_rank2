#include <stdlib.h>

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
} 					t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *current;
    t_list *tmp;

    if (!begin_list || !*begin_list)
        return;

    // Primero eliminar nodos del inicio si coinciden
    while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
    {
        tmp = *begin_list;
        *begin_list = (*begin_list)->next;
        free(tmp);
    }

    current = *begin_list;

    // Recorrer el resto de la lista
    while (current && current->next)
    {
        if (cmp(current->next->data, data_ref) == 0)
        {
            tmp = current->next;
            current->next = current->next->next;
            free(tmp);
        }
        else
        {
            current = current->next;
        }
    }
}