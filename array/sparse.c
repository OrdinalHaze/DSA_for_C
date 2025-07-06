#include<stdio.h>
#define MAX 100

struct Element{
    int row;
    int col;
    int value;
};
void addSparse(struct Element a[],struct Element b[],struct Element result[]){
    int i= 1,j = 1,k = 1;
    if(a[0].row != b[0].row || a[0].col != b[0].col){

        printf("Matrices cannot be added\n");
        return;
    }
    result[0].row = a[0].row;
    result[0].col = a[0].col;

    while(i <= a[0].value && j <= b[0].value){
        if(a[i].row == b[j].row && a[i].col == b[j].col){

            result[k].row =a[i].row;
            result[k].col =a[i].col;
            result[k].value = a[j].value + b[j].value;
            i++,j++,k++;

        }
        else if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col )){
            result[k++] = a[i++];
        }
        else{
            result[k++] = b[j++];
        }
    
    }
    while(i <= a[0].value){
        result[k++] = a[i++];

    }
    while(j <= b[0].value){
        result[k++] = b[j++];

    }
    result[0].value = k-1;

}

void printSparse(struct Element s[]){
    printf("Rows col value\n");
    for(int i =0; i<= s[0].value;i++)
        printf("%3d %3d %5d\n",s[i].row,s[i].col,s[i].value);
}



int main(){
    struct Element a[MAX] = {
        {3,3,3},
        {0,0,5},
        {1,1,8},
        {2,2,3}
    };

    struct Element b[MAX]={
        {3,3,2},
        {0,0,2},
        {1,2,4}
    };

    struct Element result[MAX];
    addSparse(a,b,result);

    printf("MAtrix A:\n");
    printSparse(a);

    printf("\nMAtrix B:\n");
    printSparse(b);

    printf("\nResult(A+B):\n");
    printSparse(result);

    return 0;
}