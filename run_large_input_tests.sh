#!/bin/bash

{ time ./solutions/backpack "./tests/large_object_test_case_1.txt" -bt; } > ./results/large_tests_bt.txt 2>&1
for i in $(seq 2 10);
do
    { time ./solutions/backpack "./tests/large_object_test_case_$i.txt" -bt; } >> ./results/large_tests_bt.txt 2>&1
done

for i in $(seq 1 50);
do
    { time ./solutions/backpack "./tests/more_large_object_test_case_$i.txt" -bt; } >> ./results/large_tests_bt.txt 2>&1
done

{ time ./solutions/backpack "./tests/large_object_test_case_1.txt" -btt; } > ./results/large_tests_btt.txt 2>&1
for i in $(seq 2 10);
do
    { time ./solutions/backpack "./tests/large_object_test_case_$i.txt" -btt; } >> ./results/large_tests_btt.txt 2>&1
done

for i in $(seq 1 50);
do
    { time ./solutions/backpack "./tests/more_large_object_test_case_$i.txt" -btt; } >> ./results/large_tests_btt.txt 2>&1
done

{ time ./solutions/backpack "./tests/large_object_test_case_1.txt" -hv; } > ./results/large_tests_hv.txt 2>&1
for i in $(seq 2 10);
do
    { time ./solutions/backpack "./tests/large_object_test_case_$i.txt" -hv; } >> ./results/large_tests_hv.txt 2>&1
done

for i in $(seq 1 50);
do
    { time ./solutions/backpack "./tests/more_large_object_test_case_$i.txt" -hv; } >> ./results/large_tests_hv.txt 2>&1
done

