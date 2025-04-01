#include "dsa.h"
#include "dynamicArray.h"
#include "stack.h"
/* #include <gtest/gtest.h> */
#include <assert.h>

int main(void) {
  // errors to investigate
  // ==22030== Invalid write of size 8
  // ==22030==    at 0x485E2A0: addElement (dynamicArray.c:47)
  // ==22030==    by 0x1091EB: main (dsa.c:12)
  // ==22030==  Address 0x4a72120 is 0 bytes after a block of size 80 alloc'd
  // ==22030==    at 0x48447A8: malloc (vg_replace_malloc.c:446)
  // ==22030==    by 0x485E13F: newDynamicArray (dynamicArray.c:19)
  // ==22030==    by 0x1091AA: main (dsa.c:10)
  // ==22030==
  // ==22030==
  // ==22030== HEAP SUMMARY:
  // ==22030==     in use at exit: 0 bytes in 0 blocks
  // ==22030==   total heap usage: 4 allocs, 4 frees, 632 bytes allocated
  // ==22030==
  // ==22030== All heap blocks were freed -- no leaks are possible
  // ==22030==
  // ==22030== For lists of detected and suppressed errors, rerun with: -s
  // ==22030== ERROR SUMMARY: 2 errors from 1 contexts (suppressed: 0 from 0)
  //
  DynamicArray *dynamicArray;
  int elements[ARRAY_LENGTH];
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    elements[i] = i;
  }
  dynamicArray = newDynamicArray(NULL);
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    dynamicArray->addElement(dynamicArray, (int *)&elements[i]);
  }
  destroyDynamicArray(dynamicArray);
  // ------- Everything according to dynamic Array
  // ----- Stack
  Stack *stack = newStack();
  int N = 5;
  int elementsStack[N];
  for (int i = 0; i < N; i++) {
    elementsStack[i] = i;
    stack->push(stack, (int *)&elementsStack[i]);
  }
  assert(stack->dynamicArray->counter - 1 == N - 1);
  destroyStack(stack);
  // ------- Everything according to stack
  // ==23898== Invalid write of size 8
  // ==23898==    at 0x485E4F9: addElement (dynamicArray.c:47)
  // ==23898==    by 0x109238: main (dsa.c:34)
  // ==23898==  Address 0x4a72120 is 0 bytes after a block of size 80 alloc'd
  // ==23898==    at 0x48447A8: malloc (vg_replace_malloc.c:446)
  // ==23898==    by 0x485E398: newDynamicArray (dynamicArray.c:19)
  // ==23898==    by 0x1091F4: main (dsa.c:32)
  // ==23898==
  // ==23898== Invalid write of size 8
  // ==23898==    at 0x485E4F9: addElement (dynamicArray.c:47)
  // ==23898==    by 0x485FE5F: enqueue (queue.c:23)
  // ==23898==    by 0x1093D8: main (dsa.c:55)
  // ==23898==  Address 0x4a726a0 is 0 bytes after a block of size 80 alloc'd
  // ==23898==    at 0x48447A8: malloc (vg_replace_malloc.c:446)
  // ==23898==    by 0x485E398: newDynamicArray (dynamicArray.c:19)
  // ==23898==    by 0x485FD1A: newQueue (queue.c:5)
  // ==23898==    by 0x10937F: main (dsa.c:50)
  // ==23898==
  // ==23898== Use of uninitialised value of size 8
  // ==23898==    at 0x109416: main (dsa.c:58)
  // ==23898==
  // ==23898== Invalid read of size 4
  // ==23898==    at 0x109416: main (dsa.c:58)
  // ==23898==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
  // ==23898==
  // ==23898==
  // ==23898== Process terminating with default action of signal 11 (SIGSEGV): dumping core
  // ==23898==  Access not within mapped region at address 0x0
  // ==23898==    at 0x109416: main (dsa.c:58)
  // ==23898==  If you believe this happened as a result of a stack
  // ==23898==  overflow in your program's main thread (unlikely but
  // ==23898==  possible), you can try to increase the size of the
  // ==23898==  main thread stack using the --main-stacksize= flag.
  // ==23898==  The main thread stack size used in this run was 8388608.
  // ==23898==
  // ==23898== HEAP SUMMARY:
  // ==23898==     in use at exit: 432 bytes in 3 blocks
  // ==23898==   total heap usage: 12 allocs, 9 frees, 1,496 bytes allocated
  // ==23898==
  // ==23898== LEAK SUMMARY:
  // ==23898==    definitely lost: 0 bytes in 0 blocks
  // ==23898==    indirectly lost: 0 bytes in 0 blocks
  // ==23898==      possibly lost: 0 bytes in 0 blocks
  // ==23898==    still reachable: 432 bytes in 3 blocks
  // ==23898==         suppressed: 0 bytes in 0 blocks
  // ==23898== Rerun with --leak-check=full to see details of leaked memory
  // ==23898==
  // ==23898== Use --track-origins=yes to see where uninitialised values come from
  // ==23898== For lists of detected and suppressed errors, rerun with: -s
  // ==23898== ERROR SUMMARY: 6 errors from 4 contexts (suppressed: 0 from 0)
  // [1]    23898 segmentation fault (core dumped)  valgrind ./dsaRun
  //
  // Queue
  Queue *queue = newQueue();

  int elementsQueue[ARRAY_LENGTH];
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    elementsQueue[i] = i;
    queue->enqueue(queue, (int *)&elementsQueue[i]);
  }
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    int queueElement = *(int *)(queue->dynamicArray->array)[i];
    assert(queueElement == elements[i]);
  }

}
