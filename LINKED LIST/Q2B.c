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
void insert_End(int data){
    struct node *new_node, *temp;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if(head == NULL){
        head = new_node;
        return;
    }
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}
void display_node(){
    struct node *temp;
    temp = head;
    printf("Head = %p\n", head);
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
    printf("List after inserting at beginning:\n");
    display_node();
    insert_End(5);
    insert_End(6);
    printf("\nList after inserting at end:\n");
    display_node();
    return 0;
}