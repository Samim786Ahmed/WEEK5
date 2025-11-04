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
int count_Nodes() {
    int count = 0;
    struct node *temp = head;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
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
    insert_Beg(10);
    insert_Beg(20);
    insert_Beg(30);
    insert_Beg(40);
    printf("Linked List:\n");
    display_node();
    int total = count_Nodes();
    printf("\nTotal number of nodes = %d\n", total);
    return 0;
}