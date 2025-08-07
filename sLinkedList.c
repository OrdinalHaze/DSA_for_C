#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node*link;
    
};

struct Node*head = NULL;

void display(){
    if(head == NULL){
        printf("Linked List is empty\n");

    }
    else{
        struct Node*ptr = head;
        printf("List : ");
        while(ptr != NULL){
            printf("%d ->",ptr->data);
            ptr = ptr->link;

        }
        printf("NULL\n");
    }
}

void insertAtFront(int x){
    struct Node*new = (struct Node*)malloc(sizeof(struct Node));
    new->data=x;
    new->link = head;
    head = new;

}

void insertAtEnd(int x){
    struct Node*new = (struct Node*)malloc(sizeof(struct Node));
    new->data = x;
    new->link = NULL;

    if(head == NULL){
        head = new;
    }else{
        struct Node*ptr = head;
        while(ptr->link != NULL){
            ptr = ptr->link;
        }
        ptr->link = new;
    }
}

void insertAfterKey(int key,int x){
    if(head == NULL){
        printf("Search failed.Insertion not possible\n");
    }

    struct Node*ptr = head;
    while(ptr != NULL && ptr->data != key){
        ptr = ptr->link;

    }

    if(ptr == NULL){
        printf("Search failed.Insertion not possible\n");

    }
    else{
        struct Node*new = (struct Node*)malloc(sizeof(struct Node));
        new->data = x;
        new->link = ptr->link;
        ptr->link = new;
    }
}

void deleteAtFront(){
    if(head == NULL){
        printf("List is empty\n");
    }
}


