#ifndef UTILS_H
#define UTILS_H

typedef struct object {
	int weight;
	int value;
	int id;
} object;

long compute_value(object *objects, int n);
long compute_weight(object *objects, int n);

#endif
