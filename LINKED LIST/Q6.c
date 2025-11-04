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
void remove_Duplicates() {
    struct node *current, *index, *temp;
    if(head == NULL) {
        printf("\nList is empty, nothing to remove!\n");
        return;
    }

    current = head;
    while(current != NULL) {
        index = current;
        while(index->next != NULL) {
            if(current->data == index->next->data) {
                temp = index->next;
                index->next = index->next->next;
                free(temp);
            } else {
                index = index->next;
            }
        }
        current = current->next;
    }
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
    insert_Beg(30);
    insert_Beg(20);
    insert_Beg(10);
    insert_Beg(20);
    insert_Beg(40);
    insert_Beg(30);
    insert_Beg(10);
    printf("Original Linked List:\n");
    display_node();
    remove_Duplicates();
    printf("\nLinked List after removing duplicates:\n");
    display_node();
    return 0;
}