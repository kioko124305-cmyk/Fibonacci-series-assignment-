#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

// 1. Simple recursion
long long fibRecursive(int n) {
    if (n <= 1) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// 2. Iteration using an array (vector)
vector<long long> fibSeries(int n) {
    vector<long long> fib(n + 1, 0);
    if (n >= 1) fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib;
}

// 3. Dynamic programming using memoization
long long fibMemo(int n, vector<long long>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];

    memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
    return memo[n];
}

// 4. Dynamic programming using two variables
long long fibOptimized(int n) {
    if (n <= 1) return n;
    long long previous = 0, current = 1;

    for (int i = 2; i <= n; i++) {
        long long next = previous + current;
        previous = current;
        current = next;
    }
    return current;
}

// Reward points start 1, 1, 2, 3, 5...
vector<long long> calculateRewards(int years) {
    vector<long long> rewards(years);
    rewards[0] = 1;
    if (years > 1) rewards[1] = 1;

    for (int i = 2; i < years; i++) {
        rewards[i] = rewards[i - 1] + rewards[i - 2];
    }
    return rewards;
}

int main() {
    int years;
    cout << "Enter customer loyalty years (1-92): ";
    cin >> years;

    if (!cin || years < 1 || years > 92) {
        cout << "Please enter a number from 1 to 92.\n";
        return 1;
    }

    vector<long long> rewards = calculateRewards(years);
    cout << "\nYear\tReward points\n";
    for (int i = 0; i < years; i++) {
        cout << i + 1 << "\t" << rewards[i] << "\n";
    }

    // Compare the methods for n = 30.
    // volatile stops the compiler from precomputing the answers or
    // removing the loops, so the timings stay meaningful with -O2.
    volatile int n = 30;
    const int runs = 1000;
    const int recursiveRuns = 10;
    volatile long long answer = 0;

    auto start = steady_clock::now();
    for (int i = 0; i < recursiveRuns; i++) {
        answer = fibRecursive(n);
    }
    auto recursiveTime =
        duration_cast<nanoseconds>(steady_clock::now() - start).count()
        / recursiveRuns;
    long long recursiveResult = answer;

    start = steady_clock::now();
    for (int i = 0; i < runs; i++) {
        vector<long long> values = fibSeries(n);
        answer = values[n];
    }
    auto arrayTime =
        duration_cast<nanoseconds>(steady_clock::now() - start).count() / runs;
    long long arrayResult = answer;

    start = steady_clock::now();
    for (int i = 0; i < runs; i++) {
        vector<long long> memo(n + 1, -1);
        answer = fibMemo(n, memo);
    }
    auto memoTime =
        duration_cast<nanoseconds>(steady_clock::now() - start).count() / runs;
    long long memoResult = answer;

    start = steady_clock::now();
    for (int i = 0; i < runs; i++) {
        answer = fibOptimized(n);
    }
    auto optimizedTime =
        duration_cast<nanoseconds>(steady_clock::now() - start).count() / runs;
    long long optimizedResult = answer;

    bool same = recursiveResult == arrayResult &&
                arrayResult == memoResult &&
                memoResult == optimizedResult;

    cout << "\nFibonacci(30) = " << recursiveResult << "\n";
    cout << "All four methods agree: " << (same ? "yes" : "no") << "\n";
    cout << "Recursive: " << recursiveTime << " ns (average of 10 runs)\n";
    cout << "Array: " << arrayTime << " ns (average of 1000 runs)\n";
    cout << "Memoization: " << memoTime << " ns (average of 1000 runs)\n";
    cout << "Two variables: " << optimizedTime
         << " ns (average of 1000 runs)\n";

    return 0;
}
