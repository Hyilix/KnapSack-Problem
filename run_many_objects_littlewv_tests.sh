#!/bin/bash

{ time ./solutions/backpack "./tests/small_weight_value_test_case_1.txt" -bt; } > ./results/swv_tests_bt.txt 2>&1
for i in $(seq 2 20);
do
    { time ./solutions/backpack "./tests/small_weight_value_test_case_$i.txt" -bt; } >> ./results/swv_tests_bt.txt 2>&1
done

{ time ./solutions/backpack "./tests/small_weight_value_test_case_1.txt" -btt; } > ./results/swv_tests_btt.txt 2>&1
for i in $(seq 2 20);
do
    { time ./solutions/backpack "./tests/small_weight_value_test_case_$i.txt" -btt; } >> ./results/swv_tests_btt.txt 2>&1
done

{ time ./solutions/backpack "./tests/small_weight_value_test_case_1.txt" -hv; } > ./results/swv_tests_hv.txt 2>&1
for i in $(seq 2 20);
do
    { time ./solutions/backpack "./tests/small_weight_value_test_case_$i.txt" -hv; } >> ./results/swv_tests_hv.txt 2>&1
done

