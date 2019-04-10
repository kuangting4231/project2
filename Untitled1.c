int tjzs()//统计图书文本个数
{
FILE *fp;
int txcl=0,n;
float tprice=0;
char tname[20]={'\0'},tauthor[20]={'\0'},tchuban[20]={'\0'},tkind[20]={'\0'},tshuhao[20]={'\0'};
fp=fopen("library.txt","r");//打开文件
for (n=0;!feof(fp);n++)//逐个读文件
fscanf(fp,"%s%s%s%s%s%d%f",tshuhao,tname,tauthor,tchuban,tkind,&txcl,&tprice);
n--;
fclose(fp);//关闭文件
return (n);//返回个数
}


int tjdzzs()//统计文读者本个数函数

{
FILE *fp;
int zhenghao=0,n;
char mingzi[20]={'\0'},riqi[20]={'\0'},zname[20]={'\0'};
fp=fopen("reader.txt","r");//打开文件
for (n=0;!feof(fp);n++)//逐个读文件
fscanf(fp,"%d%s%s%s ",&zhenghao,&mingzi,&riqi,&zname);
n--;
fclose(fp);//关闭文件
return (n);//返回个数
}


int tjzs3()//统计账号密码文本个数
{
FILE *fp;
int zhao=0,n;
char mm[20]={'\0'};
fp=fopen("land.txt","r");//打开文件
for (n=0;!feof(fp);n++)//逐个读文件
fscanf(fp,"%d %s",&zhao,mm);
n--;
fclose(fp);//关闭文件
return (n);//返回个数
}

