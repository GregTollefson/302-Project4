
Keep commits small and focused (one feature or fix per commit).

---

## 🧠 Phase 0 – Conceptual Setup (Before Coding)

### Understand the Heap Invariant
- A max-heap is a complete binary tree  
- Every parent node is greater than or equal to its children  
- The maximum element is always at the root  

### Understand Array Representation
- Left child: 2i + 1  
- Right child: 2i + 2  
- Parent: (i - 1) / 2  

### Understand Core Operations
- add():
  - Insert at end of array  
  - Trickle up until heap property is restored  

- remove():
  - Replace root with last element  
  - Reduce size  
  - Trickle down to restore heap  

### Understand Architecture
- ArrayMaxHeap<T> manages heap logic  
- PriorityQueue<T> is a wrapper (has-a heap)  
- heapSort<T>() reuses trickleDown()  

---

## 🧩 Phase 1 – Complete Process

### Implement:
- operator<
- operator==
- operator<<

### Rules:
- Compare only priority_  
- Higher priority_ = higher priority  

### Test:
- Create sample Process objects  
- Verify comparisons behave correctly  
- Verify output formatting  

---

## 🏗️ Phase 2 – Basic Heap (Insert + Peek)

### Implement in ArrayMaxHeap<T>:
- Constructor  
- isEmpty()  
- getNumberOfNodes()  
- peekTop()  
- add() (inline trickle-up)  

### Key Algorithm (Trickle-Up):
1. Insert item at end  
2. While parent < child:
   - Swap  
   - Move upward  

### Test:
- Add several items  
- Call peekTop()  
- Confirm highest-priority item is returned  

---

## 🔽 Phase 3 – Implement trickleDown()

### Location:
- heapSort.h  

### Function:
trickleDown(T arr[], int index, int size)

### Algorithm:
1. Compare parent with both children  
2. Select the larger child  
3. If parent < child:
   - Swap  
   - Continue downward  
4. Stop when heap property is restored  

### Important:
- Reused by:
  - ArrayMaxHeap::remove()  
  - heapSort()  

---

## 🧹 Phase 4 – Heap Removal

### Implement:
- remove()  
- heapRebuild(index) → calls trickleDown()  

### Algorithm:
1. Replace root with last element  
2. Decrement item count  
3. Call heapRebuild(0)  

### Test:
- Add multiple items  
- Repeatedly call remove()  
- Verify descending priority order  

---

## 📦 Phase 5 – PriorityQueue<T>

### Implement:
- add()  
- remove()  
- peek()  
- isEmpty()  
- getSize()  

### Design Pattern:
- Each method forwards to heap_  

### Special Case:
- peek():
  - Catch EmptyHeapException  
  - Rethrow with updated message  

### Test:
- Run Section A (Process)  

---

## 🔄 Phase 6 – heapSort<T>()

### Build Phase:
- Convert array into max-heap  
- Start from last parent (size/2 - 1) to root  

### Sort Phase:
- Swap root with last element  
- Reduce heap size  
- Call trickleDown()  
- Repeat  

### Result:
- Array sorted in ascending order  

### Test:
- Print before/after  
- Verify correct ordering  

---

## 🧪 Phase 7 – Full Driver Test (Process)

- Add 5 items  
- Peek  
- Remove 2 items  
- Add 3 more items  
- Peek again  
- Remove all  
- Run heapSort()  

### Verify:
- Correct priority behavior  
- Clear output formatting  

---

## 🧱 Phase 8 – Additional Item Types

Choose 2:
- NetworkPacket  
- DiskRequest  
- Interrupt  
- PrintJob  

### For each:
- Implement:
  - operator<  
  - operator==  
  - operator<<  

### Test:
- Run Sections B and C  

---

## 📄 Phase 9 – Documentation

### ADT_Design.md
- Purpose  
- Logical model (no arrays/pointers)  
- Operations  
- Heap invariant  

### Design_Decisions.md
- Item choices  
- Priority meanings  
- operator< rationale  
- trickleDown() reuse  
- Edge cases  

### README.md
- Build instructions  
- Project overview  
- Item types  
- Sample output  
- Known issues  

---

## ✅ Phase 10 – Final Checks

### Functional:
- [ ] add() maintains heap  
- [ ] remove() correct order  
- [ ] peek() correct  
- [ ] heapSort() correct  

### Structural:
- [ ] Templates in headers  
- [ ] Proper delegation in PriorityQueue  
- [ ] No duplicated logic  

### Build:
- [ ] make works  
- [ ] make run works  
- [ ] make clean works  

### Repo Hygiene:
- [ ] .gitignore correct  
- [ ] No IDE/build junk  

### Submission:
- [ ] Fresh clone builds  
- [ ] Output labeled  
- [ ] All files included  

---

## 🔥 Key Insight

The entire project hinges on maintaining the heap invariant in add() and remove().  
If those are correct, everything else will work.