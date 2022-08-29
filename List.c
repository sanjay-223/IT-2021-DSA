#include<stdio.h>
#include <stdlib.h>


int *list;
int size;
int sz = sizeof(int);

void create()
{
    printf("\n\nEnter size of list : ");
    scanf("%d",&size);
    list = (int*)malloc(size*sz);

}

void insert(int* list, int element, int pos)
{
	if((list!=NULL)&&(pos<=size))
	{
    
    size++;    
	list = (int*)realloc(list,(size+1)*sz);
	
    //(size+1) is used because incrementation of size is required//

	for(int i=size; i> pos;i--)
		list[i]=list[i-1];
	list[pos] = element;
    }

	else{
		printf("\nCouldn't insert element.");
	}
}


void disp(int* list,int a)
{
    for(int i=0;i<a;i++)
    {
        printf("\n %d",list[i]);
    }
    printf("\n\n");
    
}


void del(int* list, int pos)
{
    if((list!=NULL)&&(pos<=size)&&(pos>-1))
	{
    
    for(int i=pos; i<size;i++)
		list[i]=list[i+1];    

    size--;    
	list = (int*)realloc(list,(size-1)*sz);
	
    //(size-1) is used because decrementation of size is required//

	}
}

int search(int* list,int key)
{
    for(int i=0;i<size;i++)
    	{
			if(list[i]==key)
       			return i;
		}

	fprintf(stderr,"\nElement not found!");
	return -1;
	
}

void inp(int* list)
{
    for(int i=0;i<size;i++){
        printf("Enter Element at Index %d : ",i);
        scanf("%d",list+i);
    }
    
}

void swap(int* a, int*b)
{
	int c = *b;
	*b=*a;
	*a=c;
}

void sort(int* list)
{
// Bubble Sort
for(int i=0;i<size-1;i++)
		{
			for(int j=0;j<size-i-1;j++)
				{
					if(*(list+j)>*(list+j+1))
					{
						swap((list+j),(list+j+1));
					}
				}
		}
}

char menu()
{
	char ch;
	printf("\n\nTo Insert, Press 1");
	printf("\nTo Display, Press 2");
	printf("\nTo Delete, Press 3");
	printf("\nTo Sort, Press 4");
	printf("\nTo Search, Press 5");
	printf("\nTo Exit, Press E");
	printf("\nEnter your desired choice : ");
	scanf("\n");
	scanf("%c",&ch);
	return ch;
}

char get()
{
	int pos,ele;
	char fli='Y';
	printf("\nEnter the element to be inserted : ");
	scanf("%d",&ele);
	printf("\nEnter the position at which the element is to be inserted : ");
	scanf("%d",&pos);
	insert(list,ele,pos);
	printf("\n\nDo you want to continue? (Y/N) : ");
	scanf("\n");
	scanf("%c",&fli);

	return fli;
}

int getdel()
{
	int pos,ele;
	char ch;
	printf("\nDelete by \n 1. Position\n 2. Element\n\nYour Choice : ");
	scanf("\n");
	scanf("%c",&ch);
	if(ch=='1')
	{
		printf("\nEnter Position of the Element to be deleted : ");
		scanf("%d",&pos);
		return pos;
	}

	if(ch=='2')
	{
		printf("\nEnter the Element to be deleted : ");
		scanf("%d",&ele);
		return search(list,ele);
	}

}

int getsea()
{
	int ele;
	printf("\nEnter the Element to be searched : ");
	scanf("%d",&ele);
	return ele;
}

void main()
{
        int a,b;
	char fl;
	create();
    inp(list);

	while((fl=menu())!='E')
	{
		switch(fl)
		{
			case '1':
				while((get())=='Y')
					printf("\n");
				break;
			
			case '2':
				disp(list,size);
				break;

			case '3':
				del(list,getdel());
				disp(list,size);
				break;

			case '4':
				sort(list);
				disp(list,size);
				break;

			case '5':
				 a = getsea();
				 b = search(list,a);
				(b!=-1)?printf("\n%d found at %d",a,b):printf("\n");
				break;

			case 'E':
				break;

			default:
				printf("\n\nInvalid Option, Try Again!\n\n");
				break;
		}

	}  
	
}
