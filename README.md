Knapsack Problem Solver
=======================

A C implementation of the classic 0/1 knapsack problem with multiple solving algorithms, including a parallelized backtracking approach.
Problem Description
Given a set of objects, each with a weight and value, determine which objects to include in a knapsack to maximize total value without exceeding a maximum weight capacity.

# Algorithms

1. High Value (-hv)
A greedy heuristic that sorts objects by a weighted combination of value and weight ratio, then greedily selects items until the knapsack is full. Fast but not guaranteed to find the optimal solution.
2. Backtracking (-bt)
An exact algorithm using recursive backtracking with memoization. Explores all possible combinations while pruning the search space. Guaranteed to find the optimal solution but can be slow for large inputs.
3. Threaded Backtracking (-btt)
A parallelized version of the backtracking algorithm using pthreads. Divides the search space across 16 threads for improved performance on multi-core systems.

# Test Input Format

```
n maxw
w1 v1
w2 v2
...
```

# Test Output Format

```
n = [number of items selected], val = [total value]

real   [time]s
user   [time]s
sys    [time]s
...
```

# Usage

The project contains many running scripts. To run manually, the following command is:

```
./solutions/backpack "*input test*" *algorithm*

where *algorithm* is:
* -hv (High Value)
* -bt (Backtracking)
* -btt (Backtracking Threaded)

```

