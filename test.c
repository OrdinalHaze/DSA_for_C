#include <stdio.h>
int f=-1;
int r=-1;
void Enqueue(int Q[],int s)
{
    int m;
    printf("enter element");
    scanf("%d",&m);
    if(r==s-1)
    {
        printf("Queue is full");
        printf("\n");
    }
    else if (f==-1 && r==-1)
    {
        f=r=0;
        Q[r]=m;
    }
    else
    {
        r=r+1;
        Q[r]=m;
    }
    printf("\n");
}
void Dequeue(int Q[],int s)
{
    if(f==-1 && r==-1)
    {
        printf("Queue is empty");
        printf("\n");
    }
    else if (r==f)
    {
        printf("Deleted item is %d:",Q[f]);
        f=r=-1;
        printf("\n");
    }
    else
    {
        printf("Deleted item is%d :",Q[f]);
        f+=1;
        printf("\n");
    }
    printf("\n");
}
void Display(int Q[],int s)
{
    int i;
    if(f==-1 && r==-1)
    {
        printf("Queue is empty");
        printf("\n");
    }
    else
    {
        for(i=f;i<=r;i++) 
        {
            printf("%d\t",Q[i]);
            printf("\n");
        }
    }

    
}
void main()
{
    int ch,n,q[30];
    printf("Enter size of queue");
    scanf("%d",&n);
    do
    {
        printf("Enter 1:Enqueue,2:Dequeue,3:Display,4:exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            Enqueue(q,n);
            break;
            case 2:
            Dequeue(q,n);
            break;
            case 3:
            Display(q,n);
            break;
            default:
            printf("Incorrect choice");
        }
    }while(ch!=4);
    printf("\n");
}