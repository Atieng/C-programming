/*If you realize that the space allocated in 3 is not sufficient show how the
memory can be reallocated using the realloc() function. Illustrate with code*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){

    int n, new_n,i;
    int *arr;
    float *sum, *std_dev, mean=0;

    printf("Enter the number of integers: ");
    scanf("%d", &n);
    // Initial allocation of memory
    arr = (int*)malloc(n*sizeof(int));
    sum =(float*)malloc(sizeof(float));
    std_dev =(float*)malloc(sizeof(float));
    if(arr==NULL || sum==NULL || std_dev==NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }
    *sum =0;
    //Input initial values
    printf("Enter %d integers:\n", n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
        *sum += arr[i];
    }
    //Reallocate memory (increase size)
    printf("Enter the new size: ");
    scanf("%d", &new_n);
    int *temp = realloc(arr, new_n*sizeof(int));
    if(temp==NULL){
        printf("Reallocation failed!\n");
        free(arr);
        return 1;
    }
    else{
        arr = temp;
    }

    //Input additional values
    printf("Enter %d more integers: ", new_n-n);
    for(i=n; i<new_n; i++){
        scanf("%d", &arr[i]);
        *sum += arr[i];
    }

    //Calculate mean
    mean = *sum/new_n;
    //Calculate standard deviation
    *std_dev = 0;
    for (i=0; i<new_n; i++){
        *std_dev += pow(arr[i] - mean, 2);
    }
    *std_dev = sqrt(*std_dev/new_n);

    //output
    printf("sum = %.2f\n", *sum);
    printf("Standard Deviation = %.2f\n", *std_dev);
     
//free Memory
    free(arr);
    free(sum);
    free(std_dev);
    return 0;

}