#include "solutions.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

void update_best_solution(object *current, int current_size, object *best, int *best_size) {
    *best_size = current_size;
    for (int i = 0; i < current_size; i++) {
        best[i] = current[i];
    }
}

void backtrack_recursive(object *objects, int n, int maxw, 
                        object *current, int current_size,
                        object *best, int *best_size,
                        long *best_value,
                        int pos, long current_weight) {
    
    // Check if current solution is better than best found so far
    long current_value = compute_value(current, current_size);
    if (current_value > *best_value) {
        *best_value = current_value;
        update_best_solution(current, current_size, best, best_size);
    }
    
    // Try adding remaining objects
    for (int i = pos; i < n; i++) {
        // Check if we can add this object without exceeding weight
        if (current_weight + objects[i].weight <= maxw) {
            // Add object to current solution
            current[current_size] = objects[i];
            
            // Recurse with object added
            backtrack_recursive(objects, n, maxw,
                              current, current_size + 1,
                              best, best_size,
                              best_value,
                              i + 1, 
                              current_weight + objects[i].weight);
        }
    }
}

void backtracking(object *objects, int n, int maxw, object *sol, int *sn) {
    // Temporary array for current solution being built
    object *current = malloc(n * sizeof(object));
    if (!current) return;
    
    long best_value = 0;
    *sn = 0;
    
    // Start recursive backtracking
    backtrack_recursive(objects, n, maxw,
                       current, 0,  // Current solution (empty)
                       sol, sn,     // Best solution found
                       &best_value, // Best value found
                       0,          // Start from first object
                       0);         // Current weight = 0
    
    free(current);
}
