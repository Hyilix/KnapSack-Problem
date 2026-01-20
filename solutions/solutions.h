#ifndef SOLUTIONS_H
#define SOLUTIONS_H
#include "utils.h"

// objects -> array of initial objects
// n -> number of initial objects
// maxw -> max weight of the backpack
// sol -> array for the solution
// sn -> number of objects in solution (as pointer)
void high_value(object *objects, int n, int maxw, object *sol, int *sn);
void backtracking(object *objects, int n, int maxw, object *sol, int *sn);
void backtracking_thread(object *objects, int n, int maxw, object *sol, int *sn);


#endif
