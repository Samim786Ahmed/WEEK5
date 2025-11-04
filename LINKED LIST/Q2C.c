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
void insert_Pos(int data, int pos){
    struct node *new_node, *temp;
    int i;

    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    if(pos == 1){
        new_node->next = head;
        head = new_node;
        return;
    }
    temp = head;
    for(i = 1; i < pos - 1 && temp != NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("\nPosition %d is invalid! (List may be shorter)\n", pos);
        free(new_node);
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
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

    printf("\nInserting 99 at position 3...\n");
    insert_Pos(99, 3);
    display_node();

    printf("\nInserting 55 at position 1 (beginning)...\n");
    insert_Pos(55, 1);
    display_node();

    printf("\nInserting 77 at position 10 (invalid)...\n");
    insert_Pos(77, 10);
    display_node();
    return 0;
}