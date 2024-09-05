# Heap
https://www.youtube.com/watch?v=pLIajuc31qk

A heap is a complete binary tree that respects the heap property.

* A complete binary tree is a binary tree where every level is completely filled except for perhaps the last level, whose leafs must be as far left as possible.
* The heap property gives a strict ordering between parent and children nodes. In a min heap, every parent node should be less than or equal to both its children. In a max heap, the opposite should be true.

A heap can be efficiently stored in an array.

There are 4 key operations that a heap should have:
- Heapify: building the heap structure from an arbitrary array
- Inserting elements: You should be able to add elements while preserving the heap structure
- Return max/min element
- Extracting max/min element: you should be able to remove the largest/smallest element while preserving the heap structure
