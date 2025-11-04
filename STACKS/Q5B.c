#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 50
char stack[SIZE]; int top=-1;
void push(char c){ stack[++top]=c; }
char pop(){ return stack[top--]; }
int prec(char c){ if(c=='^')return 3; if(c=='*'||c=='/')return 2; if(c=='+'||c=='-')return 1; return 0; }

void reverse(char exp[]){
    int n=strlen(exp);
    for(int i=0;i<n/2;i++){ char t=exp[i]; exp[i]=exp[n-i-1]; exp[n-i-1]=t; }
    for(int i=0;i<n;i++){ if(exp[i]=='(')exp[i]=')'; else if(exp[i]==')')exp[i]='('; }
}
void infixToPrefix(char exp[]){
    reverse(exp);
    char res[SIZE]; int j=0;
    for(int i=0;exp[i];i++){
        char c=exp[i];
        if(isalnum(c)) res[j++]=c;
        else if(c=='(') push(c);
        else if(c==')'){ while(top!=-1 && stack[top]!='(') res[j++]=pop(); pop(); }
        else{ while(top!=-1 && prec(stack[top])>prec(c)) res[j++]=pop(); push(c); }
    }
    while(top!=-1) res[j++]=pop();
    res[j]='\0'; reverse(res);
    printf("Prefix: %s\n", res);
}
int main(){
    char exp[]="a+b*c";
    infixToPrefix(exp);
    return 0;
}