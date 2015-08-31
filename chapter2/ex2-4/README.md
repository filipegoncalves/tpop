# Exercise 2-4

Design and implement an algorithm that will sort an array of n integers as slowly as possible. You have to play fair: the algorithm must make progress and eventually terminate, and the implementation must not cheat with tricks like time wasting loops. What is the complexity of your algorithm as a function of n?

# Solution

The algorithm in `sort.c` will sort an array by trying out every possible arrangement of the array and checking if it's the correct (sorted) arrangement. For an array of size N, there are N! possible arrangements, and checking if an arrangement is sorted is O(N), so the algorithm complexity is O(N*N!). The worst case occurs when the array is sorted in reverse.

The file `sample.in` contains some test data; the algorithm works well and seems to be fast for small arrays, but attempting to sort a 1000 integers results in havoc.
