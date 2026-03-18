// 2. Program to Calculate Standard Deviation Using Dynamic Memory
/*To calculate standard deviation:
that is the Square Root ofsummation of X minus mean squared divided by n(THe number of individuals)*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int n, i;
    int *arr;
    float *sum, *std_dev, mean =0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory dynamically
    arr =(int *)malloc(n * sizeof(int));
    sum = (float *)malloc(sizeof(float));
    std_dev = (float *)malloc(sizeof(float));

    if(arr==NULL || sum==NULL || std_dev==NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }
    // Initialize sum 
    *sum = 0;
    // Input values
    printf("Enter %d integers: ", n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
        *sum += arr[i]; // Calculate sum

    }
    //calculate mean
    
    mean = *sum/n;

    //Caclate standard deviation
    *std_dev = 0;
    for(i=0; i<n; i++){
        *std_dev += pow(arr[i] - mean, 2); // Summation of (X - mean)^2
    
    }
*std_dev = sqrt(*std_dev/n);
//Output results
printf("Sum: %.2f\n", *sum);
printf("Standard Deviation: %.2f\n", *std_dev);

// Free Memory
free(arr);
free(sum);
free(std_dev);
return 0;
}

