#include <stdlib.h>
#include <string.h>
#include "solutions.h"

static int maximumw;

int objectwvcomp(const void *obj1, const void *obj2) {
	object o1 = *(object*)obj1;
	object o2 = *(object*)obj2;

	double wvr1 = 1.0 * o1.value;
	double wvr2 = 1.0 * o2.value;

	double wr1 = 1.0 * maximumw / o1.weight;
	double wr2 = 1.0 * maximumw / o2.weight;

	// importance ratio = 1/e
	double impr = 0.5;

	wvr1 = wvr1 * impr + wr1 * (1 - impr);
	wvr2 = wvr2 * impr + wr2 * (1 - impr);

	if (o1.value == 0) {
		return 1;
	}
    if (o2.value == 0) {
        return -1;
    }

	if (wvr1 > wvr2) {
		return -1;
	}

	if (wvr2 > wvr1) {
		return 1;
	}
	return 0;
}

void high_value(object *objects, int n, int maxw, object *sol, int *sn) {
	maximumw = maxw;
	qsort(objects, n, sizeof(*objects), objectwvcomp);

	long current_weight = 0; 
	long max_weight = (long)maxw;

	int i = 0;
	*sn = 0;
	while (current_weight < max_weight && i < n) {
		if (current_weight + objects[i].weight <= max_weight) {
			sol[*sn] = objects[i];
			*sn = *sn + 1;
			current_weight += objects[i].weight;
		}
		i++;
	}
}
