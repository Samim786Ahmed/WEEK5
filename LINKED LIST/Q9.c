#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;
void insertAtEnd(int usdata) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = usdata;
    temp->next = NULL;
    if (head == NULL) { 
        head = temp; 
        return; 
    }
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = temp;
}
void display() {
    struct node *start = head;
    printf("List: ");
    while(start != NULL) {
        printf("%d ", start->data);
        start = start->next;
    }
    printf("\n");
}
bool isSorted() {
    if (head == NULL || head->next == NULL) {
        return true; 
    }
    struct node *current = head;
    while (current->next != NULL) {
        if (current->data > current->next->data) {
            return false;
        }
        current = current->next;
    }
    return true;
}
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(10);
    printf("List: ");
    display();
    printf("Is sorted? %s\n", isSorted() ? "True" : "False");

    return 0;
}