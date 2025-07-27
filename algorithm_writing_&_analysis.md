# Part A:  Algorithm writing & Analysis

## 1. Find Maximum and Minimum Element in a List of n Integers

### Algorithm
1. Start
2. Set max ← A[0]
3. Set min ← A[0]
4. For i ← 1 to n - 1 do  
    If A[i] > max, then set max ← A[i]  
    If A[i] < min, then set min ← A[i]
5. End For
6. Print max and min
7. End

### A Priori Analysis
•	Operation: One pass through the list (comparing each element).
•	Time Complexity:
 O(n) as each of the n elements is visited once.

## 2. Count the Number of Odd and Even Numbers in an Array of Size n

### Algorithm

1. Initialize odd ← 0, even ← 0
2. For each element in the array:
3. If the element is divisible by 2, increment even
4. Else, increment odd
5. After the loop, even holds the count of even numbers and odd holds the count of odd numbers.

### A Priori Analysis

•	Operation: One pass through the array, with a modulus and conditional check.
•	Time Complexity:
O(n) as each of the n elements is processed once.

## 3. Reverse a Given Array of Integers of Size n

### Algorithm

1. Initialize two pointers: start ← 0, end ← n - 1
2. While start < end, do:
3. Swap array[start] and array[end]
4. Increment start by 1
5. Decrement end by 1
6. The array is now reversed.

### A Priori Analysis

•	Operation: Swap elements from both ends moving toward the center.
•	Time Complexity:
O(n)as about n/2 swaps are done, still considered O(n).

