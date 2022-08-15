#include <stdio.h>
int max_size=5;
int stack[10];
int top= -1;

int is_empty()
{
    return (top==-1)? 1 : 0;
}

int is_full()
{
    return (top == max_size-1)? 1:0;
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
        top--;
        return data;
    }
    
    else
    {
        printf("Couldn't retrive data");

    }
}


void main()
{
    int a;

    for(int i=0;i<max_size;i++)
        {
            printf("\nEnter the element to be inserted: ");
            scanf("%d",&a);
            push(a);
        }

printf("\nIs stack full : %s\n",is_full()?"True": "False");

printf("\nThe Elements are...\n");
for(int i=0;i<max_size;i++)
    printf("%d\n",stack[i]);

printf("\nPopping the elements...\n");
    for(int i=0;i<max_size;i++)
    {
        printf("\nThe top of the stack is %d\n",peek());
        pop();
        
    }

printf("\nIs stack empty : %s",is_empty()?"True": "False");
}