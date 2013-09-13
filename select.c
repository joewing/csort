
/** Sort an array in ascending order using Selection Sort
 * @param array The data to be sorted.
 * @param size The number of elements in the array.
 */
void SelectionSort(int *array, int size) {
   int x, y, z;
   int temp;

   for(x = 0; x < size; x++) {
      z = x;
      temp = array[x];
      for(y = x + 1; y < size; y++) {
         if(array[y] < temp) {
            temp = array[y];
            z = y;
         }
      }
      array[z] = array[x];
      array[x] = temp;
   }
}
