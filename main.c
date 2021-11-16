#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 100


typedef struct name
{
    char nam[50]
};
struct name names[100];



struct node
{
    char  name [50];
    struct node* next;
};
struct node* head;
typedef int ptr;
typedef struct curnode
{
    ptr next ;
    struct node* headOfCursosNode;
};
typedef ptr list ;
typedef ptr pos;
int freeListNode = SIZE -1;
typedef struct curnode cur;
cur cursor[SIZE];





void insertName(char name [50])
{
    struct node* temp = (struct node*) malloc(sizeof(struct node));

    strcpy(temp ->name, name);
    temp->next=head;
    head =temp;

}
void print(struct node* head)
{

    while(head !=NULL)
    {
        printf("%s\n",head-> name);

        head= head->next;
    }
}



void initializeCursor()
{
    int i;
    for(i=0 ; i<SIZE ; i++)
        cursor[i].next=i+1;
    cursor[SIZE-1].next=0;
}
ptr cursorAlloc()
{
    pos p;
    p=cursor[0].next;
    cursor[0].next =cursor[p].next;
    cursor[p].next=0;
    --freeListNode;
    return p;
}
void insert(list l, pos p, struct node* head )
{

    pos temp = cursorAlloc();
    if(temp)
    {
        cursor[temp].headOfCursosNode = head;
        cursor[temp].next =cursor[p].next;
        cursor[p].next=temp;
    }
    // if (cursor[temp].next==0) strcpy(cursor[l].name,temp);
}
/*void printlist(list l){
pos p= cursor [l]. next;
while(p){
    printf("%s",cursor[p].name);
   p= cursor[p].next;
}}*/
int getDigit(int num, int n)
{
    int r= (int)(num/pow(10,n-1))%10;
    return r;
}
int main()
{
    initializeCursor();
    list a1= cursorAlloc();
    FILE * file;
    file=fopen("names.txt","r");
    int j, i,r,x,mod;
    char line [50];
    int counter=0;
    for(i=0; i<10; i++)
    {
        cursor[i].headOfCursosNode =NULL;
    }
    for(i=0; (!feof(file)) ; i++)
    {
        fgets(line,50,file);
        strcpy(  names[i].nam,line);
        counter++;
    };
    int jj = 0 ;
     for (i=0 ; i<counter ; i++)
         for (j=0 ; j<50 ; j++)
             if (names[i].nam[j]=='\n'){
                 names[i].nam[j]='\0';
                 break;}


    char addedName[50];
    int numberoftask;
    char deletedname[50];

    int taskcount = 9;


    while(taskcount>0)
    {
        printf("\n enter a task if you want!");
        printf("\ntask 1 is for displaying the readed names from the file(or any added name with them)");
        printf("\ntask 2 is for adding new name \n");
        printf("task 3 is for sorting your names \n");
        printf("task 4 is for delete an name from your list \n");
        printf("task 5 is for display the sorted list! \n");
        printf("task 6 is for displaying names that starts with selected character ! \n");

        scanf("%d",&numberoftask);
        if(numberoftask==1)
        {
            taskcount++;
            for(i=0; i<counter; i++)
            {
                printf( "%s\n", names[i].nam);
            }






        }
        if (numberoftask ==2)
        {
            taskcount++;
            printf("please enter the name ");
            scanf("%s",addedName );
            counter++;
            strcpy(  names[counter].nam,addedName);
            counter++;
            printf("its done , pleas select 1 to display ");

        }
        else if (numberoftask ==3)
        {
            taskcount++;
            for(i=0; i<10; i++)
            {
                cursor[i].headOfCursosNode =NULL;
            }
            for(i=10; i<20; i++)
            {
                cursor[i].headOfCursosNode =NULL;
            }
            for(j=0; j<10; ++j)
            {
                head = NULL;
                for(i=0; i<counter; i++)
                {
                    r= names[i].nam[0];
                    x= getDigit(r,1);

                    if((j==x))
                    {
                        insertName(names[i].nam);

                        ;
                    }
                };
                cursor[j].headOfCursosNode=head;



            };
            for(i=9; i>=0; i--)
            {
                head =NULL;
                while( cursor[i].headOfCursosNode!=NULL)
                {
                    r=cursor[i].headOfCursosNode->name[0];
                    x=getDigit(r,2);
                    if(x==9)
                    {
                        head = cursor[x+1].headOfCursosNode;
                        insertName(cursor[i].headOfCursosNode->name);
                        cursor[x+1].headOfCursosNode= head;
                    }
                    head = cursor[x+11].headOfCursosNode;
                    insertName(cursor[i].headOfCursosNode->name);
                    cursor[x+11].headOfCursosNode= head;

                    cursor[i].headOfCursosNode =cursor[i].headOfCursosNode->next;
                }

            }
            printf("your list is sorted now , to display select 5\n");



            /*for(i=10;i<20;i++){
                                         head = NULL;
                                while( cursor[i].headOfCursosNode!=NULL){ r=cursor[i].headOfCursosNode->name[0];
                                x=getDigit(r,3);
                                //printf("%d\n",x);
                                head = cursor[x+20].headOfCursosNode; insertName(cursor[i].headOfCursosNode->name);
                                cursor[x+20].headOfCursosNode= head;
                                cursor[i].headOfCursosNode =cursor[i].headOfCursosNode->next;
                                }
                                }*/

        }
        else if (numberoftask==4)
        {
            taskcount++;
            printf("enter the name that you want to delete\n");
            scanf("%s",deletedname);
            // if (names[0])
        int k;
            for(i=0; i<counter; i++)
            {
                if(strcmp(names[i].nam,deletedname)==0)
                {
                    for ( k= i ; k<counter ; k++)

                        strcpy(names[k].nam,names[k+1].nam);


                }
             else printf("the name is not found");

            }
            printf("\nnow the name is deleted ! , if you want to make sure , just chose 1 !\n");
        }








        else if (numberoftask==5)
        {
            taskcount++;
            int w;
            printf("names after sorting is :\n");
            for(i=1; i<20; i++)
            {
                print(cursor[i].headOfCursosNode);

            }
            printf("if you want to print the names into the file please enter 1 , if not ,press 2");
            scanf("%d",&w);
            if(w==1)
            {


                FILE * f;
                f=fopen("yourList.txt","w");
                for(i=0; i<30; i++)
                {
                    while(cursor[i].headOfCursosNode !=NULL)
                    {
                        fputs(cursor[i].headOfCursosNode-> name, f);
                        fprintf(f,"\n");

                        cursor[i].headOfCursosNode= cursor[i].headOfCursosNode->next;
                    }


                }
                fclose(f);
                printf("\nsee the file\n\n\n\n");



            }

            else
            {


                continue;
            }

        }
        else if (numberoftask==6)
        {
            char select  ;
            int value, val2 ;
            printf("select a character");
            select =getchar();
            value =select;

            printf("?\n");
            printf("or select another task");
            for(i=0; i<counter; i++)
            {
                val2=names[i].nam[0];
                if(value==val2)
                {
                    printf( "\n %s\n", names[i].nam);
                }
            }



        }

        else if (numberoftask>7)
        {
            taskcount++;
            printf("wrong task number , try again");
        }
        else
        {
            taskcount++;
            printf("wrong task number , try again");
        }
    }

    fclose(file);
    return 0;
}
