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
void search_Value(int key) {
    struct node *temp = head;
    int position = 1;
    int found = 0;
    while(temp != NULL) {
        if(temp->data == key) {
            printf("\nValue %d found at position %d\n", key, position);
            found = 1;
            break;
        }
        temp = temp->next;
        position++;
    }
    if(!found)
        printf("\nValue %d not found in the list!\n", key);
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
    insert_Beg(50);
    insert_Beg(40);
    insert_Beg(30);
    insert_Beg(20);
    insert_Beg(10);

    printf("Linked List:\n");
    display_node();
    search_Value(30); 
    search_Value(70);  
    return 0;
}