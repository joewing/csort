
static void Heapify(int *array, int size);

/** Sort an array in ascending order using Heap Sort.
 * This runs O(n lg n).
 * @param array The data to sort.
 * @param size The number of elements in the array.
 */
void HeapSort(int *array, int size) {

   int x;

   /* Create the heap. O(n lg n) */
   for(x = 2; x <= size; x++) {
      int index = x - 1;
      while(index > 0) {
         const int next_index = index / 2;
         if(array[next_index] < array[index]) {
            const int temp = array[next_index];
            array[next_index] = array[index];
            array[index] = temp;
            index = next_index;
         } else {
            break;
         }
      }
   }

   /* Loop removing the max element and placing it at the end.  O(n lg n) */
   while(size > 0) {
      const int temp = array[0];
      size -= 1;
      array[0] = array[size];
      array[size] = temp;
      Heapify(array, size);
   }

}

/** Restore the max-heap property after inserting an item to the heap.
 * This runs O(lg n).
 * @param array The heap.
 * @param size The number of elements in the heap.
 */
void Heapify(int *array, int size) {

   int index;
   int max_index;
   int right_index;
   int left_index;
   int temp;
   int repeat;

   index = 0;
   do {

      repeat = 0;
      left_index = index * 2;
      if(left_index < size) {

         /* Check the left child. */
         max_index = index;
         if(array[left_index] > array[max_index]) {
            max_index = left_index;
         }

         /* Check the right child. */
         right_index = left_index + 1;
         if(right_index < size) {
            if(array[right_index] > array[max_index]) {
               max_index = right_index;
            }
         }

         /* Swap and go again if needed. */
         if(max_index != index) {
            temp = array[max_index];
            array[max_index] = array[index];
            array[index] = temp;
            index = max_index;
            repeat = 1;
         }

      }

   } while(repeat);

}

