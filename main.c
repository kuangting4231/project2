#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include "stack.h"
#include "land.h"
#include "administrator.h"


void mainmenu()//显示登录菜单
{
printf("\n\n\t\t\t\t        Welcome to the book management system     \n\n");
printf("\t\t\t\t**************************************************\n\n");
printf("\t\t\t\t                 1.Landing system             \n\n");
printf("\t\t\t\t                 2.New account                \n\n");
printf("\t\t\t\t                 3.Exit system                \n\n");
printf("\t\t\t\t**************************************************\n");
return ;
}


void main()
{
	char t;
	mainmenu();
	t=getch();
	switch(t)
  {
	  case '1':
	    land();
	    break;
	  case '2':
	  	newAcount();
	  	break;
	  case '3':
	  	system("cls");
  	    exit(0);
	    break;
      default :break;
  }
return ;
}



void newAcount()//新建账户密码
{
	FILE *fp;
    char t;
	int accountName;
	char password[20],password1[20],name[20];

	while(1){
    system("cls");
    printf("\n\n\n\n\n\n\t\t\t\t************************************************\n\n");
    printf("\t\t\t\t           Please choose your identity:         \n\n");
    printf("\t\t\t\t                   1.Student                    \n\n");
    printf("\t\t\t\t                   2.Administrator              \n\n");
    printf("\t\t\t\t************************************************\n\n");
    t=getch();
    if(t=='1'||t=='2') break;
    else
        printf("input error");
	}


        if (t=='1'){
            if ((fp=fopen("student.txt","r"))==NULL)
	{
      fp=fopen("student.txt","w");
      fclose(fp);
    }
    system("cls");
	fp=fopen("student.txt","a");
	}
	    else if (t=='2'){
            if ((fp=fopen("administrator.txt","r"))==NULL)
	{
      fp=fopen("administrator.txt","w");
      fclose(fp);
    }
    system("cls");
	fp=fopen("administrator.txt","a");
	}


	for(;;)//while(1)
	{
	    printf("\n\t\t\t\tPlease enter your name :");
	    scanf("%s",name);
	    printf("\n\t\t\t\tPlease enter your ID number(StudentID(staffID)) :");
        scanf("%d",&accountName);
        printf("\n\t\t\t\tPlease enter your password :");
	    scanf("%s",password);
        printf("\n\t\t\t\tPlease enter your password again:");
	    scanf("%s",password1);
	   if(strcmp(password,password1)==0)
	   {
	       fprintf(fp,"%s %d %s\n",name,accountName,password);
		   break;
       }
       else
	   {
	       printf("\n\t\t\t\tThe two passwords do not match!!!press any key to continue");
           getch();
		   system("cls");
		         }
   }
   fclose(fp);
   printf("\n\t\t\t\tCreation successful, press any key to return");
   getch();
   system("cls");
   main();
}



int   matchAccount(int IDnum,char password1[20],char IDjudge)//匹配数据库中的账号密码
{
	FILE*fp;
	int accountName;
	char password[20];
    if (IDjudge=='1'){
        fp=fopen("student.txt","r");
    }
    if(IDjudge=='2'){
        fp=fopen("administrator.txt","r");
    }
	if (fp==NULL)//不存在读者文件
	  {
         system ("cls");
		 printf("\n\t\t\t\t No user, please create, press any key to continue");
		 getch();
	 	 system("cls");
		 main();
      }


        for(;!feof(fp);)
      {
        fscanf(fp,"%d%s",&accountName ,password);
        if(IDnum==accountName)
        {
        	if(strcmp(password1,password)==0)
			return 1;
			else
			{
			return -1;
		   }
	    }
	  }
	  return 0;
 }

void land()//输入账户密码的登录函数
{
	int ID;
	char password[20];
	int match=0;
	char t;
	while(1){
        system("cls");
        printf("\n\n\n\n\n\n\t\t\t\t*************************************************************\n\n");
        printf("\t\t\t\t           Please select the system you want to log in         \n\n");
        printf("\t\t\t\t                    1.Student                                \n\n");
        printf("\t\t\t\t                    2.Administrator                          \n\n");
        printf("\t\t\t\t*************************************************************\n\n");
        t=getch();
        if(t=='1'||t=='2') break;
        else
            printf("input error");
	}

	system("cls");
    printf("\t\t\t\tPlease enter your account name(studentID or job number): ");
    scanf("%d",&ID);
    printf("\n\t\t\t\tPlease enter your password : ");
    scanf("%s",password);
    match=matchAccount(ID,password,t);
     if(match==1)
	 {
       printf("\n\t\t\t\tLogin successful, press any key to continue");
	   if(t=='1'){
         getch();


	   }
	   if(t=='2'){
         getch();
         administrator();
	   }
	 }
	 else
	 {
	 	if(match==-1)
		 {
		 printf("\n\t\t\t\tThe password is wrong!!!");
		 getch();
         land();
		 }
		 if(match==0)
		 printf("\n\t\t\t\tThe user does not exit!!!");
		 getch();
		 system("cls");
		 main();
	 }
}



