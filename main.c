
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*SortFunc)(int *array, int size);

void BubbleSort(int*, int);
void HeapSort(int*, int);
void InsertionSort(int*, int);
void MergeSort(int*, int);
void QuickSort(int*, int);
void RadixSort(int*, int);
void SelectionSort(int*, int);
void ShellSort(int*, int);

static struct {
   const char *name;
   SortFunc func;
} ALGORITHMS[] = {
   { "bubble",    BubbleSort     },
   { "heap",      HeapSort       },
   { "insert",    InsertionSort  },
   { "merge",     MergeSort      },
   { "quick",     QuickSort      },
   { "radix",     RadixSort      },
   { "select",    SelectionSort  },
   { "shell",     ShellSort      }
};

static const int ALGORITHM_COUNT = sizeof(ALGORITHMS) / sizeof(ALGORITHMS[0]);

int main(int argc, char *argv[])
{
   SortFunc func = NULL;
   int *data = NULL;
   int max_count = 128;
   int count = 0;
   int i;

   /* Check usage. */
   if(argc != 2) {
      printf("usage: %s <algorithm>\n", argv[0]);
      printf("algorithms:\n");
      for(i = 0; i < ALGORITHM_COUNT; i++) {
         printf("   %s\n", ALGORITHMS[i].name);
      }
      return -1;
   }

   /* Look up the algorithm to use. */
   for(i = 0; i < ALGORITHM_COUNT; i++) {
      if(!strcmp(argv[1], ALGORITHMS[i].name)) {
         func = ALGORITHMS[i].func;
         break;
      }
   }
   if(i == ALGORITHM_COUNT) {
      printf("ERROR: unknown algorithm specified: %s\n", argv[1]);
      return -1;
   }

   /* Read numbers from stdin. */
   data = (int*)malloc(sizeof(int) * max_count);
   for(;;) {
      if(count >= max_count) {
         max_count *= 2;
         data = (int*)realloc(data, sizeof(int) * max_count);
      }
      if(fscanf(stdin, " %d", &data[count]) != 1) {
         break;
      }
      count += 1;
   }

   /* Sort the data. */
   (func)(data, count);   

   /* Output the results. */
   for(i = 0; i < count; i++) {
      printf("%d\n", data[i]);
   }

   free(data);

   return 0;

}

