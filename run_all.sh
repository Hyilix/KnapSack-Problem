#!/bin/bash

echo "Running absurd tests..."
./run_absurd_tests.sh

echo "Running large input tests..."
./run_large_input_tests.sh

echo "Running many small objects tests..."
./run_many_objects_littlewv_tests.sh

echo "Running simple tests..."
./run_simple_tests.sh

echo "Running very large input tests..."
./run_very_large_tests.sh
