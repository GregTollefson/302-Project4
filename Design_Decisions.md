## operator< Rationale

This means:

- If `a < b`, then **b has higher priority**
- This allows the heap to function as a **max-heap**

The heap uses this comparison to:

- Move higher-priority items upward
- Maintain the heap invariant

---

## trickleDown Design

The `trickleDown()` function is implemented as a reusable free function.

### Design decision

- Do not duplicate logic inside `ArrayMaxHeap`
- Use a single implementation shared by:
  - `ArrayMaxHeap::heapRebuild()`
  - `heapSort()`

### Algorithm

- Compare a node with its children
- Select the larger child
- Swap if needed
- Continue downward until heap property is restored

### Benefits

- Code reuse
- Maintainability
- Consistency across heap operations

---

## Edge Cases

Several edge cases were handled:

- **Removing from an empty heap:**
  - `remove()` returns `false`

- **Peeking an empty heap:**
  - `peek()` throws `EmptyHeapException`

- **Heap of size 1:**
  - `remove()` correctly reduces size to 0

- **Capacity limits:**
  - `add()` returns `false` if heap is full

- **Clearing the heap:**
  - `clear()` resets `itemCount_` and overwrites elements

These ensure robustness and prevent undefined behavior.

