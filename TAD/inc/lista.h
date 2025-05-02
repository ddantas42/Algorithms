#ifndef LISTA_H
# define LISTA_H

# include "general.h"

typedef struct s_list {
	void	*info;
	t_list	*prox;
} t_list;

t_list *L_create() {return t_list *;};
t_list *L_insert(t_list *l, void *info);
t_list *L_remove(t_list *l, void *info);
void	L_print(t_list *l);
#endif