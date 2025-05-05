#include "mala.h"

/**
 * Get the current capacity of the Mala.
 * @param m Pointer to the Mala.
 * @return Current capacity of the Mala.
 */
static float get_current_capacity(Mala *m)
{
	float total = 0;
	Item *copy = m->items;
	while (copy->id != -1)
	{
		total += copy->weight;
		copy++;
	}
	return total;
}

/**
 * Get the number of items in the Mala.
 * @param m Pointer to the Mala.
 * @return Number of items in the Mala.
 */
static int get_item_number(Mala *m)
{
	int count = 0;
	Item *copy = m->items;
	while (copy->id != -1)
	{
		count++;
		copy++;
	}
	return count;
}

/**
 * Create new Mala with a maximum capacity.
 * @param capacidade_maxima Capacidade máxima da mala.
 * @return Pointer to the created Mala.
 */
Mala		 *mala_create(float capacidade_maxima)
{
	if (capacidade_maxima <= 0)
		return NULL;
	Mala *m = (Mala *)malloc(sizeof(Mala));
	if (m == NULL)
		return NULL;
	m->max_capacity = capacidade_maxima;
	m->items = (Item *)malloc(sizeof(Item));
	if (m->items == NULL)
	{
		free(m);
		return NULL;
	}
	m->items[0].id = -1; // Sentinel value to indicate end of items
	return m;
}

/**
 * Free the memory allocated for a Mala.
 * @param m Pointer to the Mala to be freed.
 */
void		 mala_free(Mala *m)
{
	if (m == NULL)
		return;
	if (m->items != NULL)
		free(m->items);
	free(m);
}

/**
 * Get the maximum capacity of the Mala.
 * @param m Pointer to the Mala.
 * @return Maximum capacity of the Mala.
 */
float		 mala_get_max_capacity(Mala *m)
{
	if (m == NULL)
		return -1;
	return m->max_capacity;
}

/**
 * Get a copy of items in the Mala.
 * @param m Pointer to the Mala.
 * @return Pointer to the array of items in the Mala.
 */
Item		 *mala_get_items(Mala *m)
{
	if (m == NULL || m->items == NULL)
		return NULL;
	Item *copy = (Item *)malloc(sizeof(Item) * (get_item_number(m) + 1));
	if (copy == NULL)
		return NULL;
	int i = 0;
	Item *items = m->items;
	while (items[i].id != -1)
	{
		copy[i] = items[i];
		i++;
	}
	copy[i].id = -1; // Sentinel value to indicate end of items
	return copy;
}

/**
 * Insert an item into the Mala.
 * @param m Pointer to the Mala.
 * @param it Pointer to the item to be inserted.
 * @return Index of the inserted item, or -1 if insertion failed.
 */
int			 mala_insert_item(Mala *m, Item *it)
{
	if (m == NULL || it == NULL)
		return -1;
		
	float current_capacity = get_current_capacity(m);
	if (current_capacity + it->weight > m->max_capacity)
		return -1;
	int item_number = get_item_number(m);
	if (item_number >= MAX_ITEMS)
		return -1;
	Item *new_items = (Item *)malloc((item_number + 2) * sizeof(Item));
	if (new_items == NULL)
		return -1;
	for (int i = 0; i < item_number; i++)
		new_items[i] = m->items[i];
	new_items[item_number] = *it;
	new_items[item_number + 1].id = -1; // Sentinel value to indicate end of items
	free(m->items);
	m->items = new_items;
	return item_number;
}

/**
 * Remove an item from the Mala.
 * @param m Pointer to the Mala.
 * @param it Pointer to the item to be removed.
 * @return Index of the removed item, or -1 if removal failed.
 */
int			 mala_remove_item(Mala *m, Item *it)
{
	if (m == NULL || it == NULL)
		return -1;
	int item_number = get_item_number(m);
	while (item_number > 0)
	{
		if (m->items[item_number - 1].id == it->id)
			break;
		item_number--;
	}
	if (item_number == 0)
		return -1;
	Item *new_items = (Item *)malloc((item_number - 1) * sizeof(Item));
	if (new_items == NULL)
		return -1;
	for (int i = 0; i < item_number - 1; i++)
		new_items[i] = m->items[i];
	int total = get_item_number(m);
	for (int i = item_number; i < total; i++)
		new_items[i - 1] = m->items[i];
	free(m->items);
	m->items = new_items;
	return item_number - 1;
}

Mala_solucao *mala_optimal_solution(Item *it)
{
	if (!it) return NULL;

	// Count items
	int n = 0;
	while (it[n].id != -1 && n < MAX_ITEMS)
		n++;

	int capacity = MAX_CAPACITY;

	// Create DP table
	float dp[n + 1][capacity + 1];
	memset(dp, 0, sizeof(dp));

	// Build DP table
	for (int i = 1; i <= n; i++) {
		for (int w = 0; w <= capacity; w++)
		{
			if (it[i - 1].weight > w)
				dp[i][w] = dp[i - 1][w];
			else
			{
				float without = dp[i - 1][w];
				float with = dp[i - 1][(int)(w - it[i - 1].weight)] + it[i - 1].value;
				dp[i][w] = (with > without) ? with : without;
			}
		}
	}

	// Backtrack to find which items were chosen
	int w = capacity;
	Item *selected = malloc((n + 1) * sizeof(Item)); // +1 for sentinel
	if (!selected) return NULL;

	int count = 0;
	for (int i = n; i > 0 && w > 0; i--) {
		if (dp[i][w] != dp[i - 1][w]) {
			selected[count++] = it[i - 1];
			w -= (int)it[i - 1].weight;
		}
	}

	// Add sentinel
	selected[count].id = -1;

	// Build solution
	Mala_solucao *sol = malloc(sizeof(Mala_solucao));
	if (!sol) {
		free(selected);
		return NULL;
	}

	sol->items = selected;
	sol->total_value = dp[n][capacity];

	return sol;
}