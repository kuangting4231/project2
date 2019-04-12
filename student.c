#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include "stack.h"
#include "land.h"
#include "link.h"
#include "administrator.h"
#include "student.h"
#define N1 sizeof(struct studentbook)


void studentMenu(){
system ("cls");
printf("\n\n\t\t\t\t ***********************************************************\n\n");
printf("\t\t\t\t                 | 1. Borrow book          |               \n\n");
printf("\t\t\t\t                 | 2. Return book          |               \n\n");
printf("\t\t\t\t                 | 3. Search book          |               \n\n");
printf("\t\t\t\t                 | 4. Browse book returns  |               \n\n");
printf("\t\t\t\t                 | 5. Back to main menu    |               \n\n");
printf("\t\t\t\t                 | 6. Log out              |               \n\n");
printf("\t\t\t\t***********************************************************\n");
return ;
}

void student(){
    system("cls");
    studentMenu();
    char t;
    t=getch();
    switch(t){
        case '1':Borrow();break;
        case '2':Return();break;
        case '3':Search();break;
        case '4':Browse();break;
        case '5':main();break;
        case '6':
        system("cls");
  	    exit(0);
	    break;
        default :break;
    }
return ;
}

void Borrow(){
    FILE *fp;
    Book *book;
    char bname[20]={'\0'};
    char data[20]={'\0'};
    int account,ID;
    printf("\n\n\t\t\t\t\t\tPlease enter the book name you want to borrow:");
    scanf("%s",bname);
    book=link("none");
    while(book!=NULL){
       if(!strcmp(book->name,bname)){
        if(book->num >0)
            book->num--;
        else
            printf("The inventory is 0!!! Cannot be lent");
       }
       book=book->next;
    }
    saveBook(book);
    if ((fp=fopen("student-book.txt","r"))==NULL)
	{
      fp=fopen("student-book.txt","w");
      fclose(fp);
    }
	fp=fopen("student-book.txt","a");
	printf("\n\n\t\t\t\tPlease enter your account:");
	scanf("%d",&account);
	printf("\n\t\t\t\tPlease enter the bookID you borrowed:");
	scanf("%d",&ID);
	printf("\n\t\t\t\tPlease enter the borrow data:");
	scanf("%s",data);
	fscanf(fp,"%d %d %s",&account,&ID,data);
	fclose(fp);
	printf("\n\t\t\t\tSuccessful borrowing,Press any key to continue!");
	getch();
	student();
return;
}
void Return(){
FILE *fp;
    Book *q,*q1;
    SB *head=NULL;
    SB *p,*p1,*p2;
    int sum,i,j=0;
	int account=0,ID=0;
    char  btime[20]={'\0'},rtime[20]={'\0'};
    int account1=0,ID1=0,t=0;
    char data[20]={'\0'};

    printf("\n\t\t\t\tPlease enter your account(ID):");
	scanf("%d",&account1);
	printf("\n\t\t\t\tPlease enter the bookID:");
	scanf("%d",&ID1);
	printf("\n\t\t\t\tPlease enter the return data");
	scanf("%s",data);


    if ((fp=fopen("student-book.txt","r"))==NULL)
	    printf("No information of readers!!!!");
    for (sum=0;!feof(fp);sum++)
        fscanf(fp,"%d %d %s %s ",&account,&ID,btime,rtime);
    fclose( fp);

    fp=fopen("student-book.txt","r");
    for(i=0;i<=sum;i++){
        fscanf(fp,"%d %d %s %s ",&account,&ID,btime,rtime);
            j++;
            if(j==1){
                p=p1=(SB*)malloc(N1);
                head=p;
            }
            else{
                p1->next=p;
                p1=p;
                p=(SB*)malloc(N1);
            }
            if(account==account1&&ID==ID1){
                strcpy(rtime,data);
                t++;
            }

            strcpy(p->btime,btime);
            strcpy(p->rtime,rtime);
            p->account=account;
            p->ID=ID;

    }
    if(j==0)
        head=NULL;
    else{
        p1->next=p;
        p->next=NULL;
        }
    p2=head;
    fclose(fp);
    saveSB(p2);

    if(t>0){
        q=link("none");
        q1=q;
        while(q1!=NULL){
            if(ID==q1->bookNumber){
                q1->num++;
            }
            q1=q1->next;
        }
        saveBook(q1);
        printf("\n\t\t\t\tSuccessful borrowing!!!");
    }
	else{
        printf("\nThere is no borrowing record of this book or this people!!!!\n ");

	}
        printf("\nPress any key to return to upper level\n");
        getch();
        student();
}
void SearchMenu(){
    system ("cls");
printf("\n\n\t\t\t\t ***********************************************************\n\n");
printf("\t\t\t\t                 | 1. ID query             |               \n\n");
printf("\t\t\t\t                 | 2. Name query           |               \n\n");
printf("\t\t\t\t                 | 3. Author query         |               \n\n");
printf("\t\t\t\t                 | 4. Type query           |               \n\n");
printf("\t\t\t\t                 | 5. Publisher query      |               \n\n");
printf("\t\t\t\t                 | 6. Publish time query   |               \n\n");
printf("\t\t\t\t***********************************************************\n");
return ;

}
void Search(){
    SearchMenu();
    char t;
    Book *p;
    t=getch();
    system("cls");
    printf("\n***********************************************Book Overview******************************************************");
	printf("\nBookID       name        author         type         publisher        publishtime         price           num");
	printf("\n-------------------------------------------------------------------------------------------------------------");

    p=link("none");
    while(p!=NULL){
        if(t=='1'){
            if (strcmp())
        }
    }

}
void Browse(){
    FILE *fp;
    int account=0,ID=0;
    int sum,i;
    char btime[20]={'\0'},rtime[20]={'\0'};
    fp=fopen("student-book.txt","r");
    if (fp==NULL){
        printf("The file is not exist!Press any key to continue");
        getch();
        student();
    }
    for(sum=0;!feof(fp);sum++){
        fscanf(fp,"%d %d %s %s ",&account,&ID,btime,rtime);
    }
    fclose(fp);
    fp=fopen("student-book.txt","r");
    printf("\n\t\t\t*************************Browse Overview*****************************");
    printf("\n\t\t\t   account(student)    BookID         borrow time       return time  ");
    for(i=0;i<=sum;i++){
        fprintf(fp,"\n\t\t\t   %-12d        %-10d     %-10s        %-10s",account,password);
    }
    fclose(fp);
    printf("Press any key to continue");
    getch();
    student();

}
