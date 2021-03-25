//sai kumar satapathy
//c2_04
#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include<stdlib.h>

int max_size=100;
int top=-1;

void push(int stack[],int n)
{

    if(top>=max_size)
    {
        printf("obverflow");
        exit(1);
    }
    else{
        top++;
        stack[top]=n;

    }
    return;
}
int pop(int stack[])
{
    if(top==-1)
    {
        printf("underflow");
        exit(1);
    }
    else
    {
        int value=stack[top];
        top--;

        return value;
    }
}
int  isoperand(char item)
{
    if (item=='^' || item== '/' || item=='*' || item=='+' || item == '-')
       return 1;
    else
       return 0;

}
int postfix_eval(char postfix[])
{
    int i=0;
    int digit=0;
    int p=0;
    int res =0;
    int op1,op2;
    int stack[max_size];
    char item=postfix[i];
    while(item!='\0')
    {
        if(item==' ') //  Pushing the values if space encountered
        {
            i++;
            item=postfix[i];
             continue;
        }

        else if(isdigit(item)){
         while (isdigit(item))
         {
             digit=digit*10+item-'0'; // for more than 1 digit
             i++;
             item=postfix[i];
         }
         push(stack,digit);
         digit=0;

        }

        else if(isoperand(item))
        {
           op2=pop(stack);
           op1=pop(stack);
           switch (item)
           {
              case '+': res = op1+op2;

                        break;
              case '-': res = op1-op2;

                        break;
             case '*': res = op1*op2;

                        break;
              case '/': res = op1/op2;
                ;
                       break;

           }

           push(stack,res);
        }

        i++;
        item=postfix[i];
        }

    return res;
}

int main()
{
    char postfix[max_size];
    printf("enter the expression");
    gets(postfix);
    int res= postfix_eval(postfix);
    printf("enter the  evaluated value is ->\n");
    printf("%d\n",res);
}
