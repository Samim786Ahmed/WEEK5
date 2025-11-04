#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL; 
void insert_Beg(int data){
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data; 
    new_node->next = head; 
    head = new_node;      
}
void delete_Pos(int pos){
    struct node *temp, *prev;
    int i;
    if(head == NULL){
        printf("\nList is empty, nothing to delete!\n");
        return;
    }
    if(pos == 1){
        temp = head;
        head = head->next;
        printf("\nDeleted node = %d (from position %d)\n", temp->data, pos);
        free(temp);
        return;
    }
    temp = head;
    for(i = 1; i < pos && temp != NULL; i++){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("\nInvalid position %d! (List may be shorter)\n", pos);
        return;
    }
    prev->next = temp->next;
    printf("\nDeleted node = %d (from position %d)\n", temp->data, pos);
    free(temp);
}
void display_node(){
    struct node *temp;
    temp = head;
    printf("\nHead = %p\n", head);
    printf("Singly Linked List Nodes are ->\n");

    while(temp != NULL){
        printf("|%d : %p|  ", temp->data, temp->next);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    insert_Beg(4);
    insert_Beg(3);
    insert_Beg(2);
    insert_Beg(1);
    printf("Initial Linked List:\n");
    display_node();
    delete_Pos(2);
    printf("\nList after deleting node at position 2:\n");
    display_node();
    delete_Pos(1);
    printf("\nList after deleting node at position 1:\n");
    display_node();
    delete_Pos(10); 
    printf("\nList after trying to delete invalid position:\n");
    display_node();

    return 0;
}