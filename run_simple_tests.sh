#!/bin/bash

{ time ./solutions/backpack "./tests/test_case_1.txt" -bt; } > ./results/simple_tests_bt.txt 2>&1
for i in $(seq 2 57);
do
    { time ./solutions/backpack "./tests/test_case_$i.txt" -bt; } >> ./results/simple_tests_bt.txt 2>&1
done

{ time ./solutions/backpack "./tests/test_case_1.txt" -btt; } > ./results/simple_tests_btt.txt 2>&1
for i in $(seq 2 57);
do
    { time ./solutions/backpack "./tests/test_case_$i.txt" -btt; } >> ./results/simple_tests_btt.txt 2>&1
done

{ time ./solutions/backpack "./tests/test_case_1.txt" -hv; } > ./results/simple_tests_hv.txt 2>&1
for i in $(seq 2 57);
do
    { time ./solutions/backpack "./tests/test_case_$i.txt" -hv; } >> ./results/simple_tests_hv.txt 2>&1
done

