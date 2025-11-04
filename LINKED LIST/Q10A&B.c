// Q10(a): Reverse using Iteration
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
void reverseIterative() {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next_node = NULL;
    while (current != NULL) {
        next_node = current->next; 
        current->next = prev;      
        prev = current;          
        current = next_node;
    }
    head = prev; 
}
struct node *reverseRecursiveHelper(struct node *current) {
    if (current == NULL || current->next == NULL) {
        return current;
    }

    struct node *rest = reverseRecursiveHelper(current->next);
    current->next->next = current;
    current->next = NULL;
    return rest;
}

// Q10(b): Reverse using Recursion (Main Call)
void reverseRecursive() {
    head = reverseRecursiveHelper(head);
}

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);

    printf("Original list for Iterative Reverse: ");
    display();
    reverseIterative();
    printf("Reversed (Iterative): ");
    display();
    reverseRecursive();
    printf("Reversed (Recursive): ");
    display();

    return 0;
}