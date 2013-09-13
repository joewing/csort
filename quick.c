
/** Sort an array in ascending order using Quick Sort.
 * @param array The data to sort.
 * @param size The number of elements in the array.
 */
void QuickSort(int *array, int size) {

   int pivot, temp;
   int a, b;

   a = 0;
   b = size - 1;
   pivot = array[0];
   for(;;) {

      while(array[a] < pivot && a < size) a += 1;
      while(array[b] > pivot && b > 0) b -= 1;

      if(a > b) break;

      temp = array[a];
      array[a] = array[b];
      array[b] = temp;

      a += 1;
      b -= 1;

   }

   if(size > 1) {
      QuickSort(array, a);
      QuickSort(array + a, size - a);
   }

}

