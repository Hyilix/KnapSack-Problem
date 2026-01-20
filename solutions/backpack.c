#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "solutions.h"

typedef enum errs {
	ERRINPUT,
	ERROUTPUT,
	ERRALGO,
	ERRMEM
} errs;

int main(int argc, char **argv) {
	if (argc < 3 || argc > 4) {
		fprintf(stderr, "Usage: ./highval input-file algorithm [output-file]\n");
		fprintf(stderr, "Algorithms: -bt / -hv / -placeholder\n");
		exit(ERRINPUT);
	}

	FILE *input = fopen(argv[1], "rt");
	if (input == NULL) {
		fprintf(stderr, "Input file %s was not found\n", argv[1]);
		exit(ERROUTPUT);
	}

	void (*func)(object*, int, int, object*, int*);

	func = NULL;

	if (!strcmp(argv[2], "-hv")) {
		func = high_value;
	}
	if (!strcmp(argv[2], "-bt")) {
		func = backtracking;
	}
    if (!strcmp(argv[2], "-btt")) {
		func = backtracking_thread;
	}


	if (func == NULL) {
		fprintf(stderr, "Algorithm %s is not recognized\n", argv[3]);
		fprintf(stderr, "Algorithms: -bt / -hv / -placeholder\n");
		exit(ERRALGO);
	}


	FILE *output = stdout;

	if (argc == 4) {
		output = fopen(argv[3], "wt");
		if (output == NULL) {
			fprintf(stderr, "Output file %s could not be opened\n", argv[3]);
			exit(ERRMEM);
		}
	}

	int n, maxw;
	fscanf(input, "%d%d", &n, &maxw);

	object *objects = malloc(n * sizeof(*objects));
	object *sol = malloc(n * sizeof(*objects));
	if (objects == NULL || sol == NULL) {
		fprintf(stderr, "Not enough memory to allocate %ld bytes for objects array\n", 2 * n * sizeof(*objects));
	}

	for (int i = 0; i < n; i++) {
		object new_obj;
		new_obj.id = i;
		fscanf(input, "%d%d", &new_obj.weight, &new_obj.value);
		objects[i] = new_obj;
	}

	int sn = 0;

	func(objects, n, maxw, sol, &sn);

	fprintf(output, "n = %d, val = %ld\n", n, compute_value(sol, sn));
	
	/*
	fprintf(output, "\nOptimal objects:\n");

	for (int i = 0; i < sn; i++) {
		fprintf(output, "id=%d: (w=%d, v=%d)\n", sol[i].id, sol[i].weight, sol[i].value);
	}
	*/

	return 0;
}
