#include <stdio.h>
#include <ctype.h>
#define SIZE 50
int stack[SIZE], top=-1;

void push(int n){ stack[++top]=n; }
int pop(){ return stack[top--]; }

int main(){
    char exp[]="23*54*+9-";
    for(int i=0;exp[i];i++){
        if(isdigit(exp[i])) push(exp[i]-'0');
        else{
            int b=pop(), a=pop();
            switch(exp[i]){
                case '+': push(a+b); break;
                case '-': push(a-b); break;
                case '*': push(a*b); break;
                case '/': push(a/b); break;
            }
        }
    }
    printf("Result: %d\n", stack[top]);
    return 0;
}