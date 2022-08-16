#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    char name[20];
    char reg_no[12];
}student;

void get(student *s)
{
    printf("\nEnter Name : ");
    scanf("%s",s->name);    
    printf("\nEnter Register No. : ");
    scanf("%s",s->reg_no);       
}

void disp(student *s)
{
    printf("\n\nName : %s",s->name);
    printf("\n\nRegister No. : %s\n\n",s->reg_no);
}

void main()
{
    student *s;
    int sz = sizeof(s),a=0,i=1;
    char fl = 'Y';

    s = (student*)malloc(sz);
    
    while(fl=='Y')
    {
        printf("\n\nEnter Student Details ? (Y/N) : ");
        scanf("\n");
        scanf("%c",&fl);
        
        if(fl!='Y')
            break;
        
        s = (student*)realloc(s,sz);
        get(s+(a*sz));
        a++;
    }

    disp(s);
    while(i<a)
    {
        disp(s+(i*sz));
        i++;
    }
}