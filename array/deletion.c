#include<stdio.h>
void main(){

    int a[10]={1,3,2,4,5,7,6};
    int n = 7;
    int flag = 0;
    int item;
    int i;
    

    printf("Enter the item to delete\n");
    scanf("%d",&item);


    for( i = 0;i<=n-1;i++){

        if(a[i] == item){

            
            flag = 1;
            break;

        }

    }
    if( flag == 0){

        printf("The given item not fond in array");
    }else{

        for(int j = i;j<n-1;j++){        //left shifting algorithm that delete the stuff

            a[j]=a[j+1];
            
        }

        n--;
        printf("Item deleted successfully.\n");
        printf("Updated array:\n");
        for(int i = 0; i < n; i++) {
            printf("%d\t", a[i]);
        }

















    }











}