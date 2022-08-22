#include <stdio.h>
#include <stdlib.h>

int max_size=1;
int *stack;
int top= -1;
int sz = sizeof(int);

void create()
{
    printf("\n\nEnter size of Stack : ");
    scanf("%d",&max_size);
    stack = (int*)malloc(max_size*sz);

}

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

void insert(int* stack, int element)
{
	if(stack!=NULL)
	{    
    max_size++;    
	stack = (int*)realloc(stack,(max_size+1)*sz);
    push(element);
    }
	
    //(size+1) is used because incrementation of size is required//

}

char get()
{
	int ele;
	char fli='Y';
	printf("\nEnter the element to be pushed : ");
	scanf("%d",&ele);
	insert(stack,ele);
	printf("\n\nDo you want to continue? (Y/N) : ");
	scanf("\n");
	scanf("%c",&fli);

	return fli;
}

void inp(int* stack)
{
    int a;
    for(int i=0;i<max_size;i++){
        printf("Enter Element at position %d : ",top+1);
        scanf("%d",&a);
        push(a);
    }
    
}

int pop()
{
    if(!is_empty())
    { 
        int data = stack[top];
        top--;
        max_size--;
        return data;
    }
    
    else
    {
        printf("\nCouldn't retrive data\n");
        return -1;

    }
}

void disp(int* stack)
{
    if(!is_empty())
    {
        for(int i=0;i<max_size;i++)
        {
            printf("\n %d",stack[max_size-i-1]);
        }
        printf("\n\n");
    }

    else
    {
        printf("\nThe Stack is empty!");
    }
    
}

char menu()
{
	char ch;
	printf("\n\nTo Push, Press 1");
	printf("\nTo Display, Press 2");
	printf("\nTo Pop, Press 3");
    printf("\nTo Peek, Press 4");
	printf("\nTo Exit, Press E");
	printf("\nEnter your desired choice : ");
	scanf("\n");
	scanf("%c",&ch);
	return ch;
}

void main()
{
	char fl;
	create();
    inp(stack);
    int pop_fl;

	while((fl=menu())!='E')
	{
		switch(fl)
		{
			case '1':
				while((get())=='Y')
					printf("\n");
				break;
			
			case '2':
				disp(stack);
				break;

			case '3':
                if(!is_empty())
                {
                	printf("\nDeleted Element is : %d",pop());
				    break;
                }

                else
                {
                    printf("\nThe Stack is empty!");
                    break;
                }
                
			case '4':
                if(!is_empty())
                {
                	printf("\nTop of the Stack is : %d",peek());
				    break;
                }

                else
                {
                    printf("\nThe Stack is empty!");
                    break;
                }   

			case 'E':
				break;

			default:
				printf("\n\nInvalid Option, Try Again!\n\n");
				break;
		}
	}  	
}
