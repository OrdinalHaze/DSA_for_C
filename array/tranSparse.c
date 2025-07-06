#include<stdio.h>
#define MAX 100

struct Element{
    int rows;
    int col;
    int value;
};

void transpose(struct Element a[],struct Element b[]){
    int i,j,k = 1;
    int rows = a[0].rows;
    int cols = a[0].col;
    int num = a[0].value;

    b[0].rows = cols;
    b[0].col = rows;
    b[0].value = num;

    for(i=0; i< cols; i++){
        for(j=1; j<=num;j++){
            if(a[j].col == i){
                b[k].rows = a[j].col;
                b[k].col = a[j].rows;
                b[k].value = a[j].value;
                k++;
            }
        }
    }
}

void print(struct Element a[]){
    printf("Rows Col Value\n");
        for(int i = 0; i <= a[0].value;i++){
            printf("%3d %3d %5d\n",a[i].rows,a[i].col,a[i].value);
        }
    
}

int main(){
    struct Element a[MAX] = {
        {3,3,4},
        {0,0,5},
        {0,2,8},
        {1,1,3},
        {2,0,6}
    };
    
    struct Element b[MAX];

    printf("Original MAtrix\n");
    print(a);

    transpose(a,b);

    printf("\nTransposed Array\n");
    print(b);

    return 0;

}