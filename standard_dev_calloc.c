#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int n, i;
    int *arr;
    float *sum, *std_dev, mean=0;
    printf("Enter number of elemnets: ");
    scanf("%d", &n);
    // Allocate memory using calloc
    arr = (int *)calloc(n,sizeof(int));
    sum = (float *)calloc(1,sizeof(float));
    std_dev = (float *)calloc(1,sizeof(float));
    if(arr==NULL || sum==NULL || std_dev==NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }
    // Input values
    printf("Enter %d integers: ", n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
        *sum += arr[i];
    }
    //Calculate the mean
    for (i=0;i<n;i++){
        mean=*sum/n;
        *std_dev += pow(arr[i]-mean,2);
    }
    *std_dev = sqrt(*std_dev/n);
    printf("Standard deviation: %f\n", *std_dev);
    // Free allocated memory
    free(arr);
    free(sum);
    free(std_dev);
    return 0;
}

// Calloc() allocates memory and initializes values to zero while malloc() allocates memory without initializing it
//Malloc has I argument(the total size in bytes) while Calloc has 2 arguments (number of elements and size of each element)
/**/