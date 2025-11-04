#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL; 
void insert_Beg(int data) {
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}
void multiply_By10() {
    struct node *temp = head;

    if(head == NULL) {
        printf("\nList is empty!\n");
        return;
    }

    while(temp != NULL) {
        temp->data = temp->data * 10;
        temp = temp->next;
    }
    printf("\nAll elements have been multiplied by 10.\n");
}
void display_node() {
    struct node *temp = head;
    printf("\nHead = %p\n", head);
    printf("Singly Linked List Nodes are ->\n");

    while(temp != NULL) {
        printf("|%d : %p|  ", temp->data, temp->next);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    insert_Beg(5);
    insert_Beg(10);
    insert_Beg(15);
    insert_Beg(20);;
    printf("Original Linked List:\n");
    display_node();
    multiply_By10();
    printf("\nLinked List after multiplying by 10:\n");
    display_node();
    return 0;
}