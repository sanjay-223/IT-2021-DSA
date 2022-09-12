#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node *ptn;
typedef ptn list;
typedef ptn pos;

typedef int ele;

struct node
{
    ele data;
    ptn next;
    ptn prev;
} *head;

int isempty(list l)
{
    return (head == NULL)?1:0;
}

/*int islast(pos p)
{
    return (p->next == NULL)?1:0;
}*/

pos ins_f(pos p)
{
    int a;
    pos tmp;
    tmp = (ptn)malloc(sizeof(struct node));
    
    if(tmp!=NULL)
    {
        printf("\nEnter first element of list : ");
        scanf("%d",&a);
        tmp->data=a;
        tmp->next=head;
        tmp->prev=NULL;
        if (tmp->next!=NULL)
            head->prev=tmp;
        head=tmp;
    }
    
    return tmp;
}

void ins(ele x, pos p)
{
    pos tmp;
    tmp = (ptn)malloc(sizeof(struct node));
    if((tmp!=NULL))
    {
        tmp->data=x;
        tmp->next=p->next;
        tmp->prev=p;
        p->next=tmp;        
    }
    else
    {
        printf("Couldn't Allocate Memory!");
    }
}

pos find(list l, ele x)
{
    pos p = l;

    while((p != NULL) && (p->data != x))
        p = p->next;

    return p;
}


void disp(ptn head)
{
    pos p;
    p = (ptn)malloc(sizeof(struct node));
    if(p!=NULL)
    {
        p = head;
        while(p != NULL)
        {
            printf("\n%d",p->data);
            p = p->next;
        }
        printf("\n");
    }
    else
        printf("\nEmpty List!\n");
}

void create()
{
    int a,sz;
    pos tmp;
    printf("Enter no. of nodes : ");
    scanf("%d",&sz);
    if(isempty(head))
        tmp=ins_f(head);
    for(int i=0;i<sz-1;i++)
    {
        printf("\nEnter the next element : ");
        scanf("%d",&a);
        ins(a,tmp);
        tmp = tmp->next;
    }
}

void del(ele x)
{
    pos tmp,tmpdel;
    tmp=find(head,x);
    if ((tmp != NULL) && (tmp->next!=NULL) && (tmp->prev!=NULL))
    {
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        free(tmp);
        return;
    }

    

    else if((tmp!=NULL) && (tmp->prev==NULL))
    {
        head=tmp->next;
        free(tmp);
        return;
    }
    else if((tmp!=NULL) && (tmp->next==NULL))
    {
        tmp->prev->next=tmp->next;
        free(tmp);
        return;
    }
    else
        printf("\nElement not Found!\n");
}

char menu()
{
	char ch;
    printf("\n\nPress : ");
	printf("\n\t1. Insert");
	printf("\n\t2. Display");
	printf("\n\t3. Delete");
	printf("\n\t4. Sort");
	printf("\n\t5. Search");
	printf("\n\tE. Exit");
	printf("\n\nEnter your desired choice : ");
	scanf("\n%c",&ch);
	return ch;
}

void sort()
{
    int x;
    pos p,q;
    p = (ptn)malloc(sizeof(ptn));
    q = (ptn)malloc(sizeof(ptn));
    p = head;

    while(p->next != NULL)
    {
        q = head;
        while(q->next != NULL)
        {
            if((q->data)>(q->next->data))
				{
					x = q->data;
                    q->data=q->next->data;
                    q->next->data=x;

				}
            q = q->next;
        }
        p=p->next;
    }
}

void main()
{
    char fl;
    head = NULL;
    create();
    while((fl=menu())!='E')
	{
		switch(fl)
		{
			case '1':
				int op,a;
                pos p;
                printf("\nPress\n\t1.Insert at First Position.\n\t2.Insert Anywhere else.\n\nYour Choice : ");
                scanf("%d",&op);
                if (op==1)
                    ins_f(head);
                else if(op==2)
                {
                    printf("\nInsert after which element : ");
                    scanf("%d",&op);
                    printf("\nElement to be inserted : ");
                    scanf("%d",&a);
                    p=find(head,op);
                    if(p!=NULL)
                        ins(a,p);
                    else
                        printf("\n\nElement not found.Try again.\n");
                }
                break;
			
			case '2':
                disp(head);
                break;

			case '3':
                int x;
                printf("\nElement to be deleted : ");
                scanf("%d",&x);
				del(x);
				break;

			case '4':
				sort();
				disp(head);
				break;

			case '5':
                int y;
                pos r;
                printf("\nElement to be searched for : ");
                scanf("%d",&y);
                r = find(head,y);
                if(r!=NULL)
                    printf("\nElement present at %p",r);
                else
                    printf("\nElement not Found!");

				break;

			case 'E':
				break;

			default:
				printf("\n\nInvalid Option, Try Again!\n\n");
				break;
		}
    }
}