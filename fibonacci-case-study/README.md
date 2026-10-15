# Fibonacci Series in Data Structures: Case Study

Case study assignment for **Data Structures and Algorithms**. We designed and compared three ways of generating the Fibonacci series (recursion, iteration with arrays, and dynamic programming) and used the best one to build a customer loyalty reward system.

**Submission date:** 16 October 2026 **Lecturer:** Dismus Kitaria

## Group Members

| No. | Name | Registration Number |
| :-: | - | - |
| 1 | Brian Kioko | CT204/124305/25 |
| 2 | Wambua Cynthia Mwikali | CT204/125562/25 |
| 3 | Macharia Stena | CT204/124284/25 |
| 4 | Karen Mukami | CT204/121071/24 |


## Repository Structure

```
fibonacci-case-study/
├── README.md
├
├── src/
│   └── fibonacci.cpp                
└── docs/
    └── Fibonacci_Case_Study.docx    
```

## What the Program Does

`src/fibonacci.cpp` contains:

1. `fibRecursive` - recursive method, O(2^n) time

2. `fibSeries` - iterative method using an array, O(n) time

3. `fibMemo` and `fibOptimized` - dynamic programming (memoization and tabulation)

4. `calculateRewards` - customer loyalty reward system (years of loyalty in, reward points per year out)

5. A timing test comparing the four methods for n = 30, which also checks that they all give the same answer

## How to Compile and Run

```
g++ -std=c++17 -O2 src/fibonacci.cpp -o fibonacci
./fibonacci
```

The program asks for the number of years a customer has been loyal (1 to 92), prints the reward points for each year, then prints the execution times for n = 30. Times will differ from machine to machine.

## Sample Output

Input of 8 years:

```
Year    Reward points
1       1
2       1
3       2
4       3
5       5
6       8
7       13
8       21
```

## Performance Summary (n = 30)

| Method | Time complexity | Space complexity |
| - | :-: | :-: |
| Simple recursion | O(2^n) | O(n) |
| Iterative array | O(n) | O(n) |
| Memoization | O(n) | O(n) |
| Two-variable tabulation | O(n) | O(1) |


Our measured times are in the report (Section 6).

## Recommendation

Use the iterative array-based (tabulation) approach for the reward system. It calculates each term once in O(n) time, stores the whole series, and has no recursion overhead. See the report (Section 7) for the full justification.

