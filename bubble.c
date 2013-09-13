
/** Sort an array in ascending order using Bubble Sort.
 * @param array The data to sort.
 * @param size The number of elements in the array.
 */
void BubbleSort(int *array, int size) {
   int x, y;
   do {
      y = 0;
      for(x = 0; x < size - 1; x++) {
         if(array[x] > array[x + 1]) {
            const int temp = array[x];
            array[x] = array[x + 1];
            array[x + 1] = temp;
            y = 1;
         }
      }
   } while(y);
}
