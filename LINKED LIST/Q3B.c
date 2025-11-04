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
void delete_End(){
    struct node *temp, *prev;

    if(head == NULL){
        printf("\nList is empty, nothing to delete!\n");
        return;
    }
    if(head->next == NULL){
        printf("\nDeleted node = %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    temp = head;
    while(temp->next != NULL){
        prev = temp;        
        temp = temp->next;    
    }
    printf("\nDeleted node = %d\n", temp->data);
    prev->next = NULL;  
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

    delete_End();
    printf("\nList after deleting from end:\n");
    display_node();

    delete_End();
    printf("\nList after another deletion:\n");
    display_node();
    return 0;
}