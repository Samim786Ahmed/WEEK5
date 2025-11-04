#include <stdio.h>
#define SIZE 3
int stack[SIZE], top = -1;

void push(int val) {
    if (top == SIZE - 1) printf("Overflow\n");
    else stack[++top] = val;
}
void pop() {
    if (top == -1) printf("Underflow\n");
    else top--;
}
int main() {
    pop();
    push(1); push(2); push(3); push(4);
    return 0;
}