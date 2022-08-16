#include <stdio.h>
int max=5;
int stack[10];
int tos= -1;

int is_empty()
{
    return (tos==-1)? 1 : 0;
}

int is_full()
{
    return (tos == max-1)? 1:0;
}

int peek()
{
    return stack[tos];
}

void push(int a)
{
    if(!is_full())
    {
        tos+=1;
        stack[tos] = a;
    }

    else{
        printf("\nCouldn't insert element.");
    }

}

void disp()
{
    printf("\nThe Elements are...\n");
    for(int i=0;i<=tos;i++)
        printf("%d\n",stack[i]);
}

int pop()
{
    if(!is_empty())
    {
        int data = stack[tos];
        tos--;
        return data;
    }

    else
    {
        printf("\n\nCouldn't remove data");

    }
}


void main()
{
    int a;

    for(int i=0;i<max;i++)
        {
            printf("\nEnter the element to be inserted: ");
            scanf("%d",&a);
            push(a);
        }

printf("\nIs stack full : %s\n",is_full()?"True": "False");

disp();

pop();
pop();

printf("\nPopping the elements...\n");
    for(int i=0;!is_empty();i++)
    {
        printf("\nThe top of the stack is %d\n",peek());
        pop();

    }

pop();

printf("\n\nIs stack empty : %s",is_empty()?"True": "False");
}
