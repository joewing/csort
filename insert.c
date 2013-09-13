
/** Sort an array in ascending order using Insertion Sort.
 * @param array The data to sort.
 * @param size The number of elements in the array.
 */
void InsertionSort(int *array, int size) {
   int x, y;
   for(x = 1; x < size; x++) {
      const int temp = array[x];
      for(y = x - 1; y >= -1; y--) {
         if(temp < array[y] && y >= 0) {
            array[y + 1] = array[y];
         } else {
            array[y + 1] = temp;
            break;
         }
      }
   }
}
