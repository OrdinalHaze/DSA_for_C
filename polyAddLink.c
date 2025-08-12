#include<stdio.h>
#include <stdlib.h>

struct Node{
    int Coeff;
    int Expo;
    struct Node* link;
};

struct Node* createNode(int coeff,int expo){
        struct Node* new =(struct Node*)malloc(sizeof(struct Node));
        new->Coeff=coeff;
        new->Expo=expo;
        new->link=NULL;
        return new;
}

void display(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%dx^%d",temp->Coeff,temp->Expo);
        temp=temp->link;
        if(temp != NULL) printf(" + ");
    }
    printf("\n");
}

struct Node* insertAtEnd(struct Node* head,int coeff,int expo ){
    struct Node* new = createNode(coeff,expo);
    if(head == NULL){
        return new;
    }
   struct Node* temp=head;
   while(temp->link != NULL){
        temp=temp->link;

   }
   temp->link=new;
   return head;

}

struct Node* addPoly(struct Node* Phead,struct Node* Qhead){
    struct Node* P,*Q,*Rhead =NULL,*R=NULL;
    P=Phead;
    Q=Qhead;

    while(P != NULL && Q != NULL){
        struct Node* new = NULL;

        if(P->Expo == Q->Expo){
             new = createNode(P->Coeff + Q->Coeff,P->Expo);
            P=P->link;
            Q=Q->link;
        }
        else if(P->Expo>Q->Expo){
             new = createNode(P->Coeff,P->Expo);
            P=P->link;
        }
        else{
             new = createNode(Q->Coeff,Q->Expo);
            Q=Q->link;
        }
        if(Rhead == NULL){
            Rhead = R = new;
        
        }
        else{
            R->link=new;
            R=new;

        }
    }
    while(P != NULL){
        struct Node* new = createNode(P->Coeff,P->Expo);
        if(Rhead == NULL){
            Rhead = R = new;
        
        }
        else{
            R->link=new;
            R=new;

        }
         P=P->link;
    }
    while(Q != NULL){
        struct Node* new = createNode(Q->Coeff,Q->Expo);
        if(Rhead == NULL){
            Rhead = R = new;
        
        }
        else{
            R->link=new;
            R=new;

        }
        Q=Q->link; 
    }

    return Rhead;
}

int main(){
    struct Node* Phead=NULL;
    struct Node* Qhead=NULL;
    struct Node* Rhead=NULL;

    Phead=insertAtEnd(Phead,2,3);
    Phead=insertAtEnd(Phead,-1,2);

    Qhead = insertAtEnd(Qhead,6,4);
    Qhead = insertAtEnd(Qhead,2,3);
    Qhead = insertAtEnd(Qhead,3,2);

    printf("Polynomial 1:");
    display(Phead);
    printf("Polynomial 2:");
    display(Qhead);

    Rhead=addPoly(Phead,Qhead);
    display(Rhead);

    return 0;
}