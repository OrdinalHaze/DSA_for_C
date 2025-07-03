#include<stdio.h>
void main(){

    int a[10]={1,4,5,2,34,67,34,34};
    int loc;
    int n= 8; //no. of elements in array
    int size = 10; // maximum capacity of array item
    int item;


    printf("Enter the index to be inserted \n");
    scanf("%d", &loc);

    printf("Enter the iteam to insert\n");
    scanf("%d",&item);

    if(n==size){
        printf("Its full no new stuff can be inserted\n");

    }else{

        for(int i = n-1;i>=loc;i--){ //Right shifting algorithm
            a[i+1]=a[i];
            
        }
        a[loc] = item;
        n=n+1;

    }

    for(int i =0;i<10;i++){

        printf("%d\t",a[i]);
    }


}