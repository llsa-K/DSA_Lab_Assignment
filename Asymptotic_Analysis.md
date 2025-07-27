# Part B: Asymptotic Analysis

---

## a) Nested Loops

```c
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        printf("*");
    }
}
```
**Time Complexity:**

- **Best-case:** `O(n²)`  
- **Worst-case:** `O(n²)`  
- **Average-case:** `O(n²)`  

**Step-by-step Analysis:**

- Outer loop runs from `i = 0` to `i < n` → executes `n` times
- For each iteration of the outer loop, inner loop runs from `j = 0` to `j < n` → also executes `n` times
- The inner statement `printf("*");` runs once per inner loop iteration
- Total executions: `n * n = n²`
- Thus, the total number of operations grows proportionally to `n²`

## b) Recursive Function

```c
void func(int n) {
    if (n == 1)
        return;
    func(n/2);
    func(n/2);
}
```

**Time Complexity:**

- **Best-case:** `O(n)`
- **Worst-case:** `O(n)`
- **Average-case:** `O(n)`

**Step-by-step Analysis:**

- Base case: When `n == 1`, time = `O(1)`
- Recursive case: Function calls itself **2 times** with size `n/2`
- Recurrence: `T(n) = 2T(n/2) + O(1)`
- Using Master Theorem:
  - `a = 2`, `b = 2`, `f(n) = O(1)`
  - `log_b(a) = log₂(2) = 1`
  - Since `f(n) = O(n^c)` where `c = 0 < 1`, Case 1 applies

**Result:**
- `T(n) = Θ(n) = O(n)`

**Conclusion:**
- Although the function calls itself twice, the input halves each time, forming a linear recursion tree with total work = `O(n)`

## c) Logarithmic Growth

```c
int i = 1;
while (i < n) {
    printf("%d ", i);
    i = i * 2;
}
```

**Time Complexity:**

- **Best-case:** `O(log n)`
- **Worst-case:** `O(log n)`
- **Average-case:** `O(log n)`

**Step-by-step Analysis:**

- Initialization: `i = 1`
- Condition: loop runs while `i < n`
- Update: `i = i * 2` (i doubles each time)
- Values of `i`: 1, 2, 4, 8, ..., up to `n`
- After `k` iterations: `i = 2^k`
- Loop ends when `2^k ≥ n` → `k ≥ log₂(n)`

**Result:**
- Number of iterations = `O(log n)`
- Each iteration does constant work → total time = `O(log n)`

**Conclusion:**
- The loop grows exponentially and runs in logarithmic time with respect to `n`

## d) Triple Nested Loops

```c
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            printf("*");
        }
    }
}
```

**Time Complexity:**

- **Best-case:** `O(n³)`
- **Worst-case:** `O(n³)`
- **Average-case:** `O(n³)`

**Step-by-step Analysis:**

- Outer loop (`i`): runs `n` times
- Middle loop (`j`): runs `n` times for each `i`
- Inner loop (`k`): runs `n` times for each `j`
- Total iterations: `n × n × n = n³`
- `printf("*");` runs once per innermost loop iteration

**Result:**
- Total work = `O(n³)`

**Conclusion:**
- Three nested loops each run `n` times → total operations grow cubically with `n`


## e) Recursive Fibonacci

```c
int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
```

**Time Complexity:**

- **Best-case:** `O(2^n)`
- **Worst-case:** `O(2^n)`
- **Average-case:** `O(2^n)`

**Step-by-step Analysis:**

- Base case: when `n <= 1`, function returns → `O(1)`
- Recursive case: calls `fib(n-1)` and `fib(n-2)`
- Recurrence relation: `T(n) = T(n-1) + T(n-2) + O(1)`
- Each call branches into 2 more → recursion tree forms
- Total calls ≈ `2^n` (exponential)

**Result:**
- Time complexity = `O(2^n)`

**Conclusion:**
- Due to repeated overlapping subproblems and two recursive calls per level,
  the total number of operations grows exponentially with `n`

## f) Constant Operation

```c
printf("Hello World");
```

**Time Complexity:**

- **Best-case:** `O(n²)`
- **Worst-case:** `O(n²)`
- **Average-case:** `O(n²)`

**Step-by-step Analysis:**

- `printf("Hello World");` → constant time → `O(1)`
- First loop (`i = 0 to n`) → runs `n` times → `O(n)`
- Nested loops (`j` and `k` from `0 to n`) → `n * n = n²` iterations → `O(n²)`
- Inner statement `printf("#");` runs once per inner loop iteration

**Result:**
- Total time = `O(1) + O(n) + O(n²) = O(n²)`

**Conclusion:**
- The dominant term is `O(n²)`, so the overall time complexity is **quadratic**

## g) Two Separated Loops

```c
for (int i = 0; i < n; i++) {
    printf("*");
}
for (int j = 0; j < n; j++) {
    for (int k = 0; k < n; k++) {
        printf("#");
    }
}
```

**Time Complexity:**

- **Best-case:** `O(n²)`
- **Worst-case:** `O(n²)`
- **Average-case:** `O(n²)`

**Step-by-step Analysis:**

- `printf("Hello World");` → runs once → `O(1)`
- First `for` loop (`i = 0 to n`) → runs `n` times → `O(n)`
  - Inside: `printf("*");` runs once per iteration
- Nested loops (`j = 0 to n`, `k = 0 to n`) → total `n * n = n²` iterations → `O(n²)`
  - Inside: `printf("#");` runs once per inner loop iteration

**Result:**
- Total time = `O(1) + O(n) + O(n²) = O(n²)`

**Conclusion:**
- As `n` grows large, `O(n²)` dominates `O(n)` and `O(1)`
- Therefore, total time complexity = `O(n²)`
