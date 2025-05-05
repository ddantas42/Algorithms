#include "mala.h"

int main() {
	// Create a new Mala with a max capacity of 10.0
	Mala *m = mala_create(10.0);
	if (!m) {
		printf("Failed to create Mala.\n");
		return 1;
	}

	printf("Created Mala with max capacity: %.2f\n", mala_get_max_capacity(m));

	// Define some items
	Item it1 = { 101, 2.0, 100.0 };
	Item it2 = { 102, 3.5, 150.0 };
	Item it3 = { 103, 4.0, 200.0 };
	Item it4 = { 104, 5.0, 250.0 }; // Should not fit if inserted after others

	// Insert items
	int idx1 = mala_insert_item(m, &it1);
	int idx2 = mala_insert_item(m, &it2);
	int idx3 = mala_insert_item(m, &it3);
	write(1, "idx2\n", 5);
	int idx4 = mala_insert_item(m, &it4); // Should fail

	printf("Insert results: it1=%d, it2=%d, it3=%d, it4=%d\n", idx1, idx2, idx3, idx4);
	if (idx4 == -1) {
		printf("Correctly failed to insert item it4 due to exceeding max capacity.\n");
	}

	// Display current items
	Item *items1 = mala_get_items(m);
	printf("\nItems in Mala:\n");
	for (int i = 0; i < 3; i++) {
		printf("  ID: %d, Weight: %.2f, Value: %.2f\n", items1[i].id, items1[i].weight, items1[i].value);
	}

	// Remove one item
	int removed_idx = mala_remove_item(m, &it2);
	printf("\nRemoved item with ID %d at index %d\n", it2.id, removed_idx);

	// Show items after removal
	free(items1);
	items1 = mala_get_items(m);
	printf("Items in Mala after removal:\n");
	for (int i = 0; i < 2; i++) {
		printf("  ID: %d, Weight: %.2f, Value: %.2f\n", items1[i].id, items1[i].weight, items1[i].value);
	}

	// Cleanup
	free(items1);
	mala_free(m);
	printf("\nMala memory successfully freed.\n");

	// Sentinel-terminated array of items
	Item items2[] = {
		{ .id = 1, .weight = 5.0, .value = 1000.0 },
		{ .id = 2, .weight = 3.0, .value = 800.0 },
		{ .id = 3, .weight = 3.0, .value = 800.0 },
		{ .id = 4, .weight = 2.0, .value = 400.0 },
		{ .id = 5, .weight = 4.0, .value = 750.0 },
		{ .id = -1 }  // Sentinel
	};

	// Call the optimal solution function
	Mala_solucao *sol = mala_optimal_solution(items2);

	if (!sol) {
		printf("Failed to compute optimal solution.\n");
		return 1;
	}

	// Print result
	printf("Optimal total value: %.2f\n", sol->total_value);
	printf("Selected items:\n");

	for (int i = 0; sol->items[i].id != -1; i++) {
		printf("  ID: %d, Weight: %.2f, Value: %.2f\n",
				sol->items[i].id, sol->items[i].weight, sol->items[i].value);
	}

	// Free solution memory
	free(sol->items);
	free(sol);

	return 0;
}