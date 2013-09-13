
static void DoRadixSort(unsigned int *array, int size, int bit_index);

/** Sort an array in ascending order using Radix Sort.
 * @param array The array to sort.
 * @param size The number of elements in the array.
 */
void RadixSort(int *array, int size) {
   const int bit_count = 8 * sizeof(int);
   DoRadixSort((unsigned int*)array, size, bit_count - 1);
}

/** Helper method for Radix Sort.
 * @param array The array to sort.
 * @param size The number of elements in the array.
 * @param bit_index The bit of the elements to sort.
 */
void DoRadixSort(unsigned int *array, int size, int bit_index) {

   int index1, index2;
   int bit1, bit2;
   unsigned int temp;
   unsigned int mask;

   /* Swap out-of-order elements for this bit. */
   mask = 1 << bit_index;
   index1 = 0;
   index2 = 1;
   while(index2 < size) {

      bit1 = array[index1] & mask;
      bit2 = array[index2] & mask;

      if(bit1 && bit2) {

         ++index2;

      } else if(bit1 && !bit2) {

         temp = array[index1];
         array[index1] = array[index2];
         array[index2] = temp;

         ++index1;
         ++index2;

      } else {

         /* bit1 is not set. */

         ++index1;
         ++index2;

      }

   }

   /* Sort the sub-arrays. */
   if(bit_index > 0) {

      /* Make sure we split in the right spot. */
      while(!(array[index1] & mask) && index1 < size) {
         ++index1;
      }

      /* Handle zeros. */
      if(index1 > 0) {
         DoRadixSort(array, index1, bit_index - 1);
      }

      /* Handle ones. */
      if(size > index1) {
         DoRadixSort(&array[index1], size - index1, bit_index - 1);
      }

   }

}

