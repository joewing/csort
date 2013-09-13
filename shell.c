
/** Sort an array in ascending order using Shell Sort.
 * @param array The data to be sorted.
 * @param size The number of elements in the array.
 */
void ShellSort(int *array, int size) {
   int off;
   int x, y;
   for(off = size >> 1; off; off >>= 1) {
      do {
         for(y = x = 0; x < size - off; x++) {
            if(array[x] > array[x + off]) {
               const int temp = array[x];
               array[x] = array[x + off];
               array[x + off] = temp;
               y = 1;
            }
         }
      } while(y);
   }
}
