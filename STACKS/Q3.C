#include <stdio.h>
#define SIZE 5
int stack[SIZE], top = -1;

void push(int val) {
    if (top == SIZE - 1) printf("Overflow\n");
    else { stack[++top] = val; printf("Pushed %d\n", val); }
}
void pop() {
    if (top == -1) printf("Underflow\n");
    else printf("Popped %d\n", stack[top--]);
}
void display() {
    if (top == -1) printf("Empty\n");
    else for (int i = top; i >= 0; i--) printf("%d ", stack[i]);
    printf("\n");
}
int main() {
    push(1); display();
    push(2); display();
    pop(); display();
    push(3); display();
    return 0;
}