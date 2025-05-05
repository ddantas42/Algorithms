#ifndef MALA_H
# define MALA_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>

# define MAX_CAPACITY 8
# define MAX_ITEMS 100


typedef struct {
	int		id;
	float	weight;
	float	value;
} Item;

typedef struct {
	float	max_capacity;
	Item	*items;
} Mala;

typedef struct {
	float	total_value;
	Item	*items;
} Mala_solucao;

Mala			 *mala_create(float capacidade_maxima);
void			 mala_free(Mala *m);
float			 mala_get_max_capacity(Mala *m);
Item			 *mala_get_items(Mala *m);
int				 mala_insert_item(Mala *m, Item *it);
int				 mala_remove_item(Mala *m, Item *it);
Mala_solucao	 *mala_optimal_solution(Item *it);


#endif