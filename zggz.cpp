#include<stdlib.h>
#include<conio.h>
#include<iostream>
using namespace std;
int n=0;
struct zggz
{
	char num[20];
	char name[20];
	int gw,xj,zw,jx,yf,shui,sf;
}zggz[100],*p;
void read()
{   FILE*fp;
	int i;
	p=zggz;
	if((fp=fopen("gz.dat","rt"))==NULL)
	{
		printf("�򲻿��ļ�!\n");
		getch();
		exit(-1);
	}
   for(i=0;i<=100;i++,p++){
		fread(p,sizeof(struct zggz),1,fp);
		n++;
		if(feof(fp))
		{
	    printf("��ȡ����!\n");
		break;
		}
       }
    fclose(fp);
	printf("һ����%dλԱ��\n",n);

}
void write()
{
	FILE*fp;
		int i;
	p=zggz;

	if((fp=fopen("gz.dat","wt+"))==NULL)
	{
	    printf("���ļ�ʧ��.\n");
		getch();
	    exit(-1);
	}
	for(i=1;i<n;i++,p++)
	{
		fwrite(p,sizeof(struct zggz),1,fp);
	}
	fclose(fp);
	
}
void find()
{   
	int i,t=0;
    char gonghao[20];
	printf("����������Ҫ��ѯְ�����ݵĹ���\n");
	scanf("%s",&gonghao);
for(i=0;i<100;i++)
	{
	if(strcmp(gonghao,zggz[i].num)==0)
	{
		printf("%s\t",zggz[i].num);
		printf("%s\t",zggz[i].name);
		printf("%d\t",zggz[i].gw);
		printf("%d\t",zggz[i].xj);
	    printf("%d\t",zggz[i].zw);
		printf("%d\t",zggz[i].jx);
		printf("%d\t",zggz[i].yf);
		printf("%d\t",zggz[i].shui);
		printf("%d\n",zggz[i].sf);
		t=1;
		break;
	}  
}
	if(t==0)
	{
		
		printf("û���ҵ��������\n");
	
	}
	
}
void list()
{

	p=zggz;
	int j;
	printf("����\t");
	printf("����\t");
	printf("��λ����\t");
	printf("н������\t");
	printf("ְ�����\t");
	printf("��Ч����\t");
	printf("Ӧ������\t");
	printf("��������˰\t");
	printf("ʵ������\n");
	
	for(j=0;j<n;j++,p++)
	{
        printf("%s\t",p->num);
		printf("%s\t",p->name);
		printf("%d\t\t",p->gw);
		printf("%d\t\t",p->xj);
		printf("%d\t\t",p->zw);
		printf("%d\t\t",p->jx);
		printf("%d\t\t",p->yf);
		printf("%d\t\t",p->shui);
		printf("%d\n",p->sf);
	}
}
void modify()
{
    int i,t=0;
    char gonghao[20];
	printf("����������Ҫ�޸Ĺ������ݵ�ְ���Ĺ���\n");
	scanf("%s",&gonghao);
    for(i=0;i<100;i++)
	{
	if(strcmp(gonghao,zggz[i].num)==0)
	{   
		t=1;
		printf("�밴˳���������������\n");
		printf("����\t");
	    printf("����\t");
	    printf("��λ����\t");
	    printf("н������\t");
	    printf("ְ�����\t");
	    printf("��Ч����\t");
	    printf("Ӧ������\t");
	    printf("��������˰\t");
	    printf("ʵ������\n");
		scanf("%s%s%d%d%d%d%d%d%d",&zggz[i].num,&zggz[i].name,&zggz[i].gw,&zggz[i].xj,&zggz[i].zw,&zggz[i].jx,&zggz[i].yf,&zggz[i].shui,&zggz[i].sf);
		break;
	}
}
    if(t==0)
	{
		printf("û���ҵ��������\n");
	}
}
void del()
{

}
int main()
{
printf("����ѧУְԱ�Ĺ������ݲ���ϵͳ\n");
	int a; 
    read();
		
do{

	printf("��ѡ�����������Ĳ���\n");
	printf("1  ��ѯ");
	printf("2  ���");
	printf("3  �޸�");
	printf("7  �˳�\n");
	scanf("%d",&a);
	switch(a)
{
case 1:
	find();
	write();
	break;
case 2:
	list();
	write();
	break;
case 3:
    modify();
	write();
	break;
case 7:
	exit(0);
}
}while(-1);
    return 0;
}
