#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include "stack.h"
#define N sizeof(struct BOOK)


Book *link(char cname[20]){
    FILE *fp;
    fp=fopen("book.txt","r");
    if(fp==NULL)
        printf("The file is not exist");
    Book *head=NULL;
    Book *p,*p1;
    int sum,i,j=0;
	int bookNumber=0,num=0;
    float price=0;
    char  name[20]={'\0'},author[20]={'\0'},type[20]={'\0'},pub[20]={'\0'},pubtime[20]={'\0'};
    for (sum=0;!feof(fp);sum++){
        fscanf(fp,"%d %d %s %s %s %s %s %f",&bookNumber,&num,name,pub,pubtime,author,type,&price);
        }
    fclose( fp);

    fp=fopen("book.txt","r");
    for(i=0;i<=sum;i++){
        fscanf(fp,"%d %d %s %s %s %s %s %f",&bookNumber,&num,name,pub,pubtime,author,type,&price);
        if(strcmp(cname,name)){
            j++;
            if(j==1){
                p=p1=(Book*)malloc(N);
                head=p;
            }
            else{
                p1->next=p;
                p1=p;
                p=(Book*)malloc(N);
            }

            strcpy(p->name,name);
            strcpy(p->publisher,pub);
            strcpy(p->publishtime,pubtime);
            strcpy(p->type,type);
            strcpy(p->author,author);
            p->bookNumber=bookNumber;
            p->num=num;
            p->price=price;
        }
    }
    if(j==0)
        head=NULL;
    else{
        p1->next=p;
        p->next=NULL;
        }
    fclose(fp);
    return head;
}


void saveBook(Book *p){
    FILE *fp;
    fp=fopen("book.txt","w");
    fclose(fp);
    fp=fopen("book.txt","a");

   for (;p!=NULL;)
   {
        fprintf(fp,"%d %d %s %s %s %s %s %f\n",p->bookNumber,p->num,p->name,p->publisher,p->publishtime,p->author,p->type,p->price);
        p=p->next;
   }
   fclose(fp);
return;
}
void saveSB(SB *p){
    FILE *fp;
    fp=fopen("student-book.txt","w");
    fclose(fp);
    fp=fopen("student-book.txt","a");

   for (;p!=NULL;)
   {
        fprintf(fp,"%d %d %s %s \n",p->account,p->ID,p->btime,p->rtime);
        p=p->next;
   }
   fclose(fp);
return;
}

