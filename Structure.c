#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    char name[20];
    char reg_no[12];
}Student;


void get(Student *s)
{
    printf("\nEnter Name: ");
    scanf("%s",s->name);
    printf("\nEnter Reg No: ");
    scanf("%s",s->reg_no);
    
}

void disp(Student *s)
{
    printf("\n\n\nName : %s",s->name);
    printf("\n\nReg No : %s\n\n",s->reg_no);

}


void main()
{
    Student *s;
    int sz = sizeof(s),a=0,i=1;
    char f='y';
    
    s=(Student*)malloc(sz);
   // get(s);

    while(f=='y'){

    printf("\nDo you want to enter the details? (y/n) : ");
    scanf("\n");
    scanf("%c",&f);

    if (f!='y')
        break;
        
    s=(Student*)realloc(s,sz);
    get(s+(a*sz));
    a++;

    }
    
    disp(s);
    while(i<a){
        
    disp(s+(i*sz));
    i++;
    }


}