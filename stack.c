#include <stdio.h>
int max_size=5;
int stack[10];
int top= -1;

int is_empty()
{
    if(top == -1) 
        return 1;
    else
    return 0;

}

int is_full()
{
    if(top == max_size-1)
        return 1;
    else
    return 0;
}

int peek()

{
    return stack[top];
}

void push(int a)
{   
    if(!is_full())
    {
        top+=1;
        stack[top] = a;
    }

    else{
        printf("\nCouldn't insert element.");
    }

}

int pop()
{
    if(!is_empty())
    { 
        int data = stack[top];
        top-=1;
        return data;
    }
    
    else
    {
        printf("Couldn't retrive data");

    }
}


void main()
{

    push(2);
    push(1);
    push(0);
      push(2);
    push(1);
    push(0);
  push(2);
    push(1);
    push(0);


    printf("\nStack full: %s", is_full()==1 ? "True": "False");

   // printf("\n%d\n",is_full());

    for(int i=0;i<7;i++)
    {
        printf("\nThe top of the stack is %d\n",peek());
        pop();
        
    }

printf("\nstack empty : %s",is_empty()?"True": "False");
}