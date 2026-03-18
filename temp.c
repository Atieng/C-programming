arr = (int*)malloc(3*sizeof(int));
 *temp =realloc(arr,new_size);
if(temp==NULL){
    printf("REallocation failed!\n");

}
else{
    arr =temp;
}