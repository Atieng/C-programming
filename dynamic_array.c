// 1.Program to allocate memory dynamically for an array of integers, input values, and display them.
/*Reserves a contiguous block of memory on the heap.*/
// Header Files
#include <stdio.h>
#include <stdlib.h>    #Required for memory allocation functions
int main()
{
  int k,i;
  int *arr;
  printf("Enter number of integes(k): ");
  scanf("%d",&k);
  //Allocate memory memory dynamically
  arr = (int *)malloc(k * sizeof(int));

  if (arr==NULL){
    printf("Memory allocation failed!\n");
    return 1;
  }

  //Input values
  printf("Enter %d integers: ", k);
  for(i=0; i<k; i++){
    scanf("%d", &arr[i]);
  }
  //Display values
  printf("You entered:\n");
  for(i=0; i<k; i++){
    printf("%d ", arr[i]);
  }
  
  // Free allocated memory
  free(arr);
  return 0;


}

 