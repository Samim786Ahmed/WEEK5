#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 50
int stack[SIZE], top=-1;
void push(int n){ stack[++top]=n; }
int pop(){ return stack[top--]; }
int main(){
    char exp[]="-+*23*549";
    for(int i=strlen(exp)-1;i>=0;i--){
        if(isdigit(exp[i])) push(exp[i]-'0');
        else{
            int a=pop(), b=pop();
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