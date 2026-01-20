#include "utils.h"

long compute_value(object *objects, int n) {
	long total_value = 0;
	for (int i = 0; i < n; i++) {
		total_value += (long)objects[i].value;
	}
	return total_value;
}

long compute_weight(object *objects, int n) {
	long total_weight = 0;
	for (int i = 0; i < n; i++) {
		total_weight += (long)objects[i].weight;
	}
	return total_weight;
}
