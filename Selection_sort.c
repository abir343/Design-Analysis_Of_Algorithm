#include <stdio.h>
 
#define MAX 100
 
int main() {
    int arr[MAX],limit;
    int i,j,temp,position;
     
    printf("Enter total number of elements : ");
    scanf("%d",&limit);
     
    printf("Enter array elements : ");
    for(i=0; i<limit; i++) { scanf("%d",&arr[i]); }
     
    /*sort elements in Ascending Order*/
    for(i=0; i<(limit); i++) {
        position=i;
        for(j=i+1; j<limit; j++) {
            if(arr[position]>arr[j]) { position=j; }
            if(position!=i) {
                temp=arr[i];
                arr[i]=arr[position];
                arr[position]=temp;                
            }
        }
    }
 
    printf("Array elements in Ascending Order : ");
    for(i=0; i<limit; i++)
        printf("%d ",arr[i]);
     
    return 0;
}