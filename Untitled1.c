int tjzs()//ͳ��ͼ���ı�����
{
FILE *fp;
int txcl=0,n;
float tprice=0;
char tname[20]={'\0'},tauthor[20]={'\0'},tchuban[20]={'\0'},tkind[20]={'\0'},tshuhao[20]={'\0'};
fp=fopen("library.txt","r");//���ļ�
for (n=0;!feof(fp);n++)//������ļ�
fscanf(fp,"%s%s%s%s%s%d%f",tshuhao,tname,tauthor,tchuban,tkind,&txcl,&tprice);
n--;
fclose(fp);//�ر��ļ�
return (n);//���ظ���
}


int tjdzzs()//ͳ���Ķ��߱���������

{
FILE *fp;
int zhenghao=0,n;
char mingzi[20]={'\0'},riqi[20]={'\0'},zname[20]={'\0'};
fp=fopen("reader.txt","r");//���ļ�
for (n=0;!feof(fp);n++)//������ļ�
fscanf(fp,"%d%s%s%s ",&zhenghao,&mingzi,&riqi,&zname);
n--;
fclose(fp);//�ر��ļ�
return (n);//���ظ���
}


int tjzs3()//ͳ���˺������ı�����
{
FILE *fp;
int zhao=0,n;
char mm[20]={'\0'};
fp=fopen("land.txt","r");//���ļ�
for (n=0;!feof(fp);n++)//������ļ�
fscanf(fp,"%d %s",&zhao,mm);
n--;
fclose(fp);//�ر��ļ�
return (n);//���ظ���
}

