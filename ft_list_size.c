
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

// Calcula el tamaño de una lista enlazada contando sus nodos.
int	ft_list_size(t_list *begin_list)
{
	t_list *cur;
	int len;

	len = 0;
	cur = begin_list;
	while(cur)
	{
		len++;
		cur = cur->next;
	}
	return(len);
}