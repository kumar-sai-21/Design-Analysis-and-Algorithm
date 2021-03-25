//sai kumar satapathy
//c2_04
#include<stdio.h>
#include<stdbool.h>
#define SIZE 5

int stack[SIZE], top = -1;

bool isFull()
{
    if(top == SIZE-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isEmpty()
{
    if(top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void push(int value)
{
    if (isFull())
    {
        printf("\nStack is Full\n");
        return;
    }
    else
    {
        top++;
        stack[top] = value;
        printf("\nInsertion success\n");
    }
}
int pop()
{
    if (isEmpty())
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        printf("\nDeleted : %d\n", stack[top]);
        top--;
    }
}
void display(){
   if(top == -1)
      printf("\nStack is Empty\n");
   else{
      int i;
      printf("\nStack elements are:\n");
      for(i=0; i<=top; i++)
	 printf("%d\n",stack[i]);
   }
}

void main()
{
    int choice,value;
    while(1)
    {
        printf(" 1.PUSH\n 2.POP\n 3.DISPLAY\n 4.EXIT \n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\n Enter the value to be insert: ");
                    scanf("%d",&value);
                    push(value);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("Enter option is invaild.");

        }
    }
}
