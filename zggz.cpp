#include<stdlib.h>
#include<conio.h>
#include<iostream>
using namespace std;
int n;
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
	scanf("%s",gonghao);
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
	scanf("%s",gonghao);
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
		scanf("%s%s%d%d%d%d%d%d%d",zggz[i].num,zggz[i].name,&zggz[i].gw,&zggz[i].xj,&zggz[i].zw,&zggz[i].jx,&zggz[i].yf,&zggz[i].shui,&zggz[i].sf);
		printf("�޸������ѳɹ�!�뱣��.\n");
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
	int b,i,j,t=0,k=0;
    char gonghao[20];

		printf("�Ƿ�ȷ��ɾ������?\n");
	    printf("1  ȷ��\t");
	    printf("2  �˳�\t");
		scanf("%d",&b);
	switch(b)
	{
	case 1:
		{
			printf("����������Ҫɾ��ְ�����ݵĹ���\n");
	        scanf("%s",gonghao);
            for(i=0;i<100;i++)
			{
				if(strcmp(gonghao,zggz[i].num)==0)
				{
					for(j=i+1;j<=n-1;j++)
					{
						zggz[i]=zggz[j];
					}
					n=n-1;
					t=1;
					printf("ɾ���ѳɹ�!�뱣��.\n");
		            break;
				}  
			}
			if(t==0)
			{
				printf("û���ҵ��������\n");
			}
		}
	case 2:
			{
				break;
			}
	}
}
void add()
{   
	
	int c;
	printf("����һ����%dλԱ��\n",n);
	printf("�Ƿ�ȷ������һ��ְ���Ĺ�������?\n");
	printf("1  ȷ��\t");
	printf("2  �˳�\t");
	scanf("%d",&c);
	switch(c)
	{
	case 1:
		{
		printf("�밴˳�������������\n");
		printf("����\t");
	    printf("����\t");
	    printf("��λ����\t");
	    printf("н������\t");
	    printf("ְ�����\t");
	    printf("��Ч����\t");
	    printf("Ӧ������\t");
	    printf("��������˰\t");
	    printf("ʵ������\n");
		scanf("%s%s%d%d%d%d%d%d%d",zggz[n].num,zggz[n].name,&zggz[n].gw,&zggz[n].xj,&zggz[n].zw,&zggz[n].jx,&zggz[n].yf,&zggz[n].shui,&zggz[n].sf);
		n++;
		printf("������ݳɹ�!�뱣��.\n");
		}
	case 2:
		{
		break;
		}
	}
}
void grsds()
{

}
	
int main()
{
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("����ѧУְԱ�Ĺ������ݲ���ϵͳ\n");
	int a; 
    read();
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
do{
	printf("��ѡ�����������Ĳ���\n");
	printf("1  ��ѯ\t");
	printf("2  ���\t");
	printf("3  �޸�\t");
	printf("4  ɾ��\t");
	printf("5  ����\t");
	printf("6  ����\t");
	printf("7  �˳�\n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
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
case 4:
	del();
	write();
	break;
case 5:
	add();
	write();
	break;
case 7:
	exit(0);
}
}while(-1);
    return 0;
}