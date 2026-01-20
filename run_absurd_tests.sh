#!/bin/bash

{ time ./solutions/backpack "./tests/adjusted_absurd_test_case_1.txt" -bt; } > ./results/absurd_tests_bt.txt 2>&1
for i in $(seq 2 10);
do
    { time ./solutions/backpack "./tests/adjusted_absurd_test_case_$i.txt" -bt; } >> ./results/absurd_tests_bt.txt 2>&1
done

{ time ./solutions/backpack "./tests/adjusted_absurd_test_case_1.txt" -btt; } > ./results/absurd_tests_btt.txt 2>&1
for i in $(seq 2 10);
do
    { time ./solutions/backpack "./tests/adjusted_absurd_test_case_$i.txt" -btt; } >> ./results/absurd_tests_btt.txt 2>&1
done

{ time ./solutions/backpack "./tests/adjusted_absurd_test_case_1.txt" -hv; } > ./results/absurd_tests_hv.txt 2>&1
for i in $(seq 2 10);
do
    { time ./solutions/backpack "./tests/adjusted_absurd_test_case_$i.txt" -hv; } >> ./results/absurd_tests_hv.txt 2>&1
done

