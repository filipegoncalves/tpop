## Exercise 2-1

Quicksort is most naturally expressed recursively. Write it iteratively and compare the two versions. (Hoare describes how hard it was to work out quicksort iteratively, and how neatly it fell into place when he did it recursively.)

## Solution

An iterative version of quicksort is implemented in `qsort_iter.cpp`. It works by keeping a queue of pairs such that the pair `(i, j)` denotes the sub-array `A[i:j-1]`. The algorithm repeatedly pops from the queue, places the pivot in the correct place in the same way as the original quicksort, and adds the left and right sub-array partitions into the queue. It stops when the queue is empty.

The best case, average case and worst case time and space complexity remain the same, but the iterative version has the added benefit of avoiding recursion overhead and the possibility of stack overflow altogether, although one might argue that with `O(log(N))` recursive calls, even with very large arrays stack overflow won't happen.

Here's why: each invocation of quicksort uses `O(1)` memory in the stack; the implementation in the book uses 2 integers - with 32-bit integers, that's 8 bytes. Other house keeping information is needed (return address, arguments, and saved RBP), so we will assume that each invocation uses 32 bytes of stack space (8 bytes for local variables, 8 bytes for the arguments, 4 bytes for the return address and 4 bytes for the saved RBP, plus 8 bytes just to make it a power of 2). A typical value for the stack size in Linux is 8192 KB (8 MB). Assuming we have about half of the stack usable when quicksort is called (4096 KB, or 4 MB), which is pretty conservative, we would need the recursion to go as deep as 128 calls, which means that in the average case the array would need to have 2^128 elements - not going to happen, not even at Google scale.

The previous paragraph pretty much destroyed the only "advantage" that iterative quicksort could have over recursive quicksort. There's no real use for this exercise other than having fun and showing that it can be done. But the code is unnatural, unnecessarily complicated, and needs auxiliary data structures.

On the other hand, in the worst case quicksort does `O(N)` recursive (nested) calls, so the limit would be reached for arrays with 128 or more elements. In this specific case, the iterative solution may be superior, but if the algorithm falls into the worst case with large arrays it's doomed anyway, as the running time is the same.
