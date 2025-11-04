#include <stdio.h>
#include <stdlib.h>
struct Node { int data; struct Node *next; };
struct Node *top = NULL;

void push(int val) {
    struct Node *new = malloc(sizeof(struct Node));
    new->data = val; new->next = top; top = new;
}
void pop() {
    if (top == NULL) printf("Underflow\n");
    else { struct Node *temp = top; top = top->next; free(temp); }
}
void display() {
    struct Node *t = top;
    if (!t) printf("Empty\n");
    else while (t) { printf("%d ", t->data); t = t->next; }
    printf("\n");
}
int main() {
    push(5); push(10); push(15);
    display();
    pop();
    display();
    return 0;
}