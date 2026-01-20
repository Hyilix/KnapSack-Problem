#include "solutions.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

#define false 0
#define true 1

typedef char bool;

typedef struct {
    bool valid;
    long value;
} MemoEntry;

static void update_best_solution(object *current, int current_size, object *best, int *best_size) {
    *best_size = current_size;
    for (int i = 0; i < current_size; i++) {
        best[i] = current[i];
    }
}

// Create memoization table
static MemoEntry **create_memo_table(int n, int maxw) {
    MemoEntry **memo = malloc(n * sizeof(MemoEntry *));
    for (int i = 0; i < n; i++) {
        memo[i] = malloc((maxw + 1) * sizeof(MemoEntry));
        for (int w = 0; w <= maxw; w++) {
            memo[i][w].valid = false;
        }
    }
    return memo;
}

static void free_memo_table(MemoEntry **memo, int n) {
    for (int i = 0; i < n; i++) {
        free(memo[i]);
    }
    free(memo);
}

static long backtrack_memoized(object *objects, int n, int maxw,
                        object *current, int current_size,
                        object *best, int *best_size,
                        long *best_value,
                        int pos, long current_weight,
                        MemoEntry **memo) {
    if (pos >= n) return 0;

    // Check memo table
    if (memo[pos][current_weight].valid) {
        return memo[pos][current_weight].value;
    }

    long current_value = compute_value(current, current_size);
    if (current_value > *best_value) {
        *best_value = current_value;
        update_best_solution(current, current_size, best, best_size);
    }

    long max_value = current_value;

    // Try including the current object
    if (current_weight + objects[pos].weight <= maxw) {
        current[current_size] = objects[pos];
        max_value = backtrack_memoized(objects, n, maxw,
                                       current, current_size + 1,
                                       best, best_size,
                                       best_value,
                                       pos + 1, current_weight + objects[pos].weight,
                                       memo);
    }

    // Try excluding the current object
    long exclude_value = backtrack_memoized(objects, n, maxw,
                                            current, current_size,
                                            best, best_size,
                                            best_value,
                                            pos + 1, current_weight,
                                            memo);

    // Update the memo table
    memo[pos][current_weight].value = max_value > exclude_value ? max_value : exclude_value;
    memo[pos][current_weight].valid = true;

    return memo[pos][current_weight].value;
}

static int compare_objects(const void *a, const void *b) {
    const object *objA = (const object *)a;
    const object *objB = (const object *)b;
    double ratioA = (double)objA->value / objA->weight;
    double ratioB = (double)objB->value / objB->weight;
    return (ratioB > ratioA) - (ratioA > ratioB);
}

void backtracking(object *objects, int n, int maxw, object *sol, int *sn) {
    // Sort objects by value-to-weight ratio
    qsort(objects, n, sizeof(object), compare_objects);

    // Temporary array for current solution being built
    object *current = malloc(n * sizeof(object));
    if (!current) return;

    // Memoization table
    MemoEntry **memo = create_memo_table(n, maxw);

    long best_value = 0;
    *sn = 0;

    // Start recursive backtracking with memoization
    backtrack_memoized(objects, n, maxw,
                       current, 0,  // Current solution (empty)
                       sol, sn,     // Best solution found
                       &best_value, // Best value found
                       0,           // Start from first object
                       0,           // Current weight = 0
                       memo);

    free_memo_table(memo, n);
    free(current);
}
