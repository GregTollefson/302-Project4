// driver.cpp
// CS 302 – Project 4: OS Priority Scheduler (Heap & Priority Queue)
//
// This driver demonstrates all required functionality of your
// ArrayMaxHeap, PriorityQueue, and heapSort implementations.
//
// INSTRUCTIONS:
//   1. Section A (Process) is scaffolded for you — fill in the TODOs.
//   2. Choose two more item types from: NetworkPacket, DiskRequest,
//      Interrupt, PrintJob. Add their #include lines below.
//   3. Fill in Sections B and C following the same pattern as Section A.
//   4. Do not change the structure or labels of the output sections —
//      grading depends on them.

#include "Process.h"
#include "NetworkPacket.h"

// TODO: Add #include lines for your two additional item types.
// Example:
//   #include "NetworkPacket.h"
//   #include "PrintJob.h"

#include "PriorityQueue.h"
#include "heapSort.h"
#include "EmptyHeapException.h"
#include <iostream>
#include <string>

using namespace std;

// -------------------------------------------------------
// Utility: prints a labeled section divider
// -------------------------------------------------------
void printSection(const string& label)
{
    cout << endl;
    cout << "============================================" << endl;
    cout << "  " << label << endl;
    cout << "============================================" << endl;
}

// -------------------------------------------------------
// Utility: prints a labeled sub-divider within a section
// -------------------------------------------------------
void printStep(const string& label)
{
    cout << endl << "--- " << label << " ---" << endl;
}


int main()
{

        
    // Test code to check remove
    std::cout << "=== Phase 4 Test: remove() ===\n";

    ArrayMaxHeap<Process> heap(10);

    heap.add(Process("disk_sync", 1, 3));
    heap.add(Process("kernel_init", 2, 9));
    heap.add(Process("user_shell", 3, 5));
    heap.add(Process("net_handler", 4, 7));

    while (!heap.isEmpty())
    {
        std::cout << "Top: " << heap.peekTop() << '\n';
        heap.remove();
    }

std::cout << "isEmpty(): " << std::boolalpha << heap.isEmpty() << '\n';
std::cout << "================================\n\n";


    // ========================================================
    // SECTION A — Process
    // ========================================================
    // This section is scaffolded for you as a pattern.
    // Fill in each TODO, then replicate the same structure
    // in Sections B and C with your two chosen item types.

    printSection("SECTION A: Process Priority Queue");

    const int QUEUE_A_CAPACITY = 10;

    PriorityQueue<Process> queueA(QUEUE_A_CAPACITY);

    printStep("A1. Initial State");
    cout << "isEmpty(): " << (queueA.isEmpty() ? "true" : "false") << endl;
    cout << "getSize(): " << queueA.getSize() << endl;


    // --------------------------------------------------------
    // A2. Add 5 items with distinct priority values
    // --------------------------------------------------------
    printStep("A2. Adding 5 Items");

    // TODO: Create 5 Process items with distinct priority values
    //       and add them to queueA. Print each item as you add it.
    //
    // Example:
    //   Process p1("kernel_init", 1, 9);
    //   queueA.add(p1);
    //   cout << "Added: " << p1 << endl;
    //
    //   Process p2("user_shell", 2, 5);
    //   queueA.add(p2);
    //   cout << "Added: " << p2 << endl;
    //
    //   ... (3 more)

    printStep("A2. Adding 5 Items");

    Process p1("kernel_init", 1, 9);
    queueA.add(p1);
    cout << "Added: " << p1 << endl;

    Process p2("user_shell", 2, 5);
    queueA.add(p2);
    cout << "Added: " << p2 << endl;

    Process p3("disk_sync", 3, 3);
    queueA.add(p3);
    cout << "Added: " << p3 << endl;

    Process p4("net_handler", 4, 7);
    queueA.add(p4);
    cout << "Added: " << p4 << endl;

    Process p5("garbage_collect", 5, 1);
    queueA.add(p5);
    cout << "Added: " << p5 << endl;

    cout << "getSize(): " << queueA.getSize() << endl;


    // --------------------------------------------------------
    // A3. Peek — confirm highest priority is at the top
    // --------------------------------------------------------
    printStep("A3. Peek — Highest Priority Item");

    // TODO: Call queueA.peek() and display the result.
    cout << "peek(): " << queueA.peek() << endl;


    // --------------------------------------------------------
    // A4. Remove 2 items — confirm they emerge in priority order
    // --------------------------------------------------------
    printStep("A4. Remove 2 Items (should be highest-priority first)");

    // TODO: Peek and remove twice, printing what comes out.
    cout << "Removing: " << queueA.peek() << endl;
    queueA.remove();
    cout << "Removing: " << queueA.peek() << endl;
    queueA.remove();

    cout << "getSize(): " << queueA.getSize() << endl;


    // --------------------------------------------------------
    // A5. Add 3 more items — at least one with higher priority
    //     than the current top
    // --------------------------------------------------------
    printStep("A5. Adding 3 More Items (including one higher-priority)");

    // TODO: Add 3 more Process items. At least one must have a higher
    //       priority value than the item currently at the top of the queue.
    //       Print each item as you add it.

    Process p6("audio_daemon", 6, 4);
    queueA.add(p6);
    cout << "Added: " << p6 << endl;

    Process p7("security_patch", 7, 10);
    queueA.add(p7);
    cout << "Added: " << p7 << endl;

    Process p8("log_rotate", 8, 6);
    queueA.add(p8);
    cout << "Added: " << p8 << endl;


    // --------------------------------------------------------
    // A6. Peek — confirm new highest priority is now at top
    // --------------------------------------------------------
    printStep("A6. Peek After New Additions");

    // TODO: Call queueA.peek() and confirm the new top.
    cout << "peek(): " << queueA.peek() << endl;


    // --------------------------------------------------------
    // A7. Remove all remaining items — confirm full priority order
    // --------------------------------------------------------
    printStep("A7. Drain Queue — Confirm Priority Order Throughout");

    // TODO: Remove all remaining items, printing each one.
    while (!queueA.isEmpty())
    {
        cout << "Removing: " << queueA.peek() << endl;
        queueA.remove();
    }
    cout << "isEmpty(): " << (queueA.isEmpty() ? "true" : "false") << endl;
    cout << "getSize(): " << queueA.getSize() << endl;


    // --------------------------------------------------------
    // A8. HeapSort demo — plain array of 6 Process items
    // --------------------------------------------------------
    printStep("A8. HeapSort Demo");

    // TODO: Declare a plain array of 6 Process items with unsorted priorities.
    //
    // Example:
    Process sortArr[6] = {
        Process("ps_a", 10, 4),
        Process("ps_b", 11, 7),
        Process("ps_c", 12, 1),
        Process("ps_d", 13, 9),
        Process("ps_e", 14, 3),
        Process("ps_f", 15, 6)
    };

    // TODO: Print the array BEFORE sorting.
    cout << "Before heapSort:" << endl;
    for (int i = 0; i < 6; i++) 
    { 
        cout << "  " << sortArr[i] << endl; 
    }

    // TODO: Call heapSort on the array.
    heapSort(sortArr, 6);

    // TODO: Print the array AFTER sorting.
    cout << "After heapSort (ascending priority order):" << endl;
    for (int i = 0; i < 6; i++) 
    { 
        cout << "  " << sortArr[i] << endl; 
    }


    // ========================================================
    // SECTION B — [TODO: Replace with your first chosen type]
    // ========================================================
    // Choose from: NetworkPacket, DiskRequest, Interrupt, PrintJob
    // Follow the exact same pattern as Section A above:
    // steps B1–B7 mirror A1–A7, and B8 mirrors A8.
    // Create items appropriate to this type's domain.

   printSection("SECTION B: Network Packet Priority Queue");

    const int QUEUE_B_CAPACITY = 10;

    PriorityQueue<NetworkPacket> queueB(QUEUE_B_CAPACITY);

    printStep("B1. Initial State");
    cout << "isEmpty(): " << (queueB.isEmpty() ? "true" : "false") << endl;
    cout << "getSize(): " << queueB.getSize() << endl;

    // --------------------------------------------------------
    // B2. Add 5 items with distinct priority values
    // --------------------------------------------------------
    printStep("B2. Adding 5 Items");

    NetworkPacket np1("video_stream", 1, 9);
    queueB.add(np1);
    cout << "Added: " << np1 << endl;

    NetworkPacket np2("voice_call", 2, 7);
    queueB.add(np2);
    cout << "Added: " << np2 << endl;

    NetworkPacket np3("http_request", 3, 3);
    queueB.add(np3);
    cout << "Added: " << np3 << endl;

    NetworkPacket np4("email", 4, 2);
    queueB.add(np4);
    cout << "Added: " << np4 << endl;

    NetworkPacket np5("file_download", 5, 1);
    queueB.add(np5);
    cout << "Added: " << np5 << endl;

    cout << "getSize(): " << queueB.getSize() << endl;

    // --------------------------------------------------------
    // B3. Peek — confirm highest priority is at the top
    // --------------------------------------------------------
    printStep("B3. Peek — Highest Priority Item");
    cout << "peek(): " << queueB.peek() << endl;

    // --------------------------------------------------------
    // B4. Remove 2 items — confirm they emerge in priority order
    // --------------------------------------------------------
    printStep("B4. Remove 2 Items (should be highest-priority first)");
    cout << "Removing: " << queueB.peek() << endl;
    queueB.remove();
    cout << "Removing: " << queueB.peek() << endl;
    queueB.remove();

    cout << "getSize(): " << queueB.getSize() << endl;

    // --------------------------------------------------------
    // B5. Add 3 more items — at least one with higher priority
    // --------------------------------------------------------
    printStep("B5. Adding 3 More Items (including one higher-priority)");

    NetworkPacket np6("video_stream_hd", 6, 10);
    queueB.add(np6);
    cout << "Added: " << np6 << endl;

    NetworkPacket np7("security_patch", 7, 6);
    queueB.add(np7);
    cout << "Added: " << np7 << endl;

    NetworkPacket np8("debug_logs", 8, 4);
    queueB.add(np8);
    cout << "Added: " << np8 << endl;

    // --------------------------------------------------------
    // B6. Peek — confirm new highest priority is now at top
    // --------------------------------------------------------
    printStep("B6. Peek After New Additions");
    cout << "peek(): " << queueB.peek() << endl;

    // --------------------------------------------------------
    // B7. Remove all remaining items
    // --------------------------------------------------------
    printStep("B7. Drain Queue — Confirm Priority Order Throughout");
    while (!queueB.isEmpty())
    {
        cout << "Removing: " << queueB.peek() << endl;
        queueB.remove();
    }
    cout << "isEmpty(): " << (queueB.isEmpty() ? "true" : "false") << endl;
    cout << "getSize(): " << queueB.getSize() << endl;

    // --------------------------------------------------------
    // B8. HeapSort demo — plain array of 6 Process items
    // --------------------------------------------------------
    printStep("B8. HeapSort Demo");

    // TODO: Declare a plain array of 6 Process items with unsorted priorities.
    //
    // Example:
        NetworkPacket networkSortArr[6] = {
        NetworkPacket("ps_a", 10, 4),
        NetworkPacket("ps_b", 11, 7),
        NetworkPacket("ps_c", 12, 1),
        NetworkPacket("ps_d", 13, 9),
        NetworkPacket("ps_e", 14, 3),
        NetworkPacket("ps_f", 15, 6)
    };

    // TODO: Print the array BEFORE sorting.
    cout << "Before heapSort:" << endl;
    for (int i = 0; i < 6; i++) 
    { 
        cout << "  " << networkSortArr[i] << endl; 
    }

    // TODO: Call heapSort on the array.
    heapSort(networkSortArr, 6);

    // TODO: Print the array AFTER sorting.
    cout << "After heapSort (ascending priority order):" << endl;
    for (int i = 0; i < 6; i++) 
    { 
        cout << "  " << networkSortArr[i] << endl; 
    }


    // ========================================================
    // SECTION C — [TODO: Replace with your second chosen type]
    // ========================================================
    // Choose a different type than Section B: NetworkPacket, DiskRequest, Interrupt, PrintJob
    // Follow the exact same pattern as Section A above:
    // steps C1–C7 mirror A1–A7, and C8 mirrors A8.
    // Create items appropriate to this type's domain.

    printSection("SECTION C: [TypeC] Priority Queue");

    const int QUEUE_C_CAPACITY = 10;

    // TODO: Construct PriorityQueue<TypeC> queueC(QUEUE_C_CAPACITY);

    printStep("C1. Initial State");
    // TODO

    printStep("C2. Adding 5 Items");
    // TODO

    printStep("C3. Peek — Highest Priority Item");
    // TODO

    printStep("C4. Remove 2 Items");
    // TODO

    printStep("C5. Adding 3 More Items (including one higher-priority)");
    // TODO

    printStep("C6. Peek After New Additions");
    // TODO

    printStep("C7. Drain Queue — Confirm Priority Order Throughout");
    // TODO

    printStep("C8. HeapSort Demo");
    // TODO


    // ========================================================
    // All checks complete
    // ========================================================
    cout << endl;
    cout << "============================================" << endl;
    cout << "  All checks complete." << endl;
    cout << "============================================" << endl;

    return 0;
}
