#include<stdlib.h>
#include<conio.h>
#include<iostream>
using namespace std;
int n;
struct zggz
{
	char num[20];
	char name[20];
    float gw;//ְԱ��λ����
	float xj;//ְԱн������
	float zw;//ְԱְ����
	float jx;//ְԱ��Ч����
	float yf;//ְԱӦ������
	float grsds;//ְԱ�ĸ�������˰
	float sf;//ְԱʵ������
}zggz[100],*p;

/*�����������˰��ʽ*/
float shui(float tax)
{
float grsds;

	if(tax<=500)
		grsds=tax*0.05;
	else if(tax<=2000)
		grsds=(tax-500)*0.10+500*0.05;
    else if(tax<=5000)
	grsds=(tax-2000)*0.15+500*0.05+1500*0.10;
	else if(tax<=20000)
		grsds=(tax-5000)*0.20+3000*0.15+1500*0.1+500*0.05;
	else if(tax<=40000)
		grsds=(tax-20000)*0.25+15000*0.20+3000*0.15+1500*0.1+500*0.05;
	else if(tax<=60000)
		grsds=(tax-40000)*0.30+20000*0.25+15000*0.20+3000*0.15+1500*0.1+500*0.05;
	else if(tax<=80000)
	grsds=(tax-60000)*0.35+20000*0.3+20000*0.25+15000*0.20+3000*0.15+1500*0.1+500*0.05;
	else if(tax<=100000)
		grsds=(tax-80000)*0.40+20000*0.35+20000*0.3+20000*0.25+15000*0.20+3000*0.15+1500*0.1+500*0.05;
	else if(tax>100000)
		grsds=(tax-100000)*0.45+20000*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.20+3000*0.15+1500*0.1+500*0.05;
	return (grsds);
}

	
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
		printf("!");
	    printf("\t\t��ȡ����!\t\t");
		printf("\t\t                     !\n");
		break;
		}
       }
    n--;
    fclose(fp);
	printf("!");
	printf("\t\tһ����%dλԱ��Ӵ.\t\t",n);
   
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
	for(i=0;i<n;i++,p++)
	{
		fwrite(p,sizeof(struct zggz),1,fp);
	}
	printf("�����ѳɹ�!\n");
	fclose(fp);
	
}
void find()
{   
	int i,t=0;
    char gonghao[20];
	printf("!\t\t\t����������Ҫ��ѯְ�����ݵĹ���\t\t\t     !\n");
	scanf("%s",gonghao);
for(i=0;i<100;i++)
	{
	if(strcmp(gonghao,zggz[i].num)==0)
	{
        printf("\t%s\n",zggz[i].num);
        printf("\t%s\n",zggz[i].name);
        printf("\t%f\n",zggz[i].gw);
        printf("\t%f\n",zggz[i].xj);
	    printf("\t%f\n",zggz[i].zw);
		printf("\t%f\n",zggz[i].jx);
		printf("\t%f\n",zggz[i].yf);
		printf("\t%f\n",zggz[i].grsds);
		printf("\t%f\n",zggz[i].sf);
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
		printf("%f\t\t",p->gw);
		printf("%f\t\t",p->xj);
		printf("%f\t\t",p->zw);
		printf("%f\t\t",p->jx);
		printf("%f\t\t",p->yf);
		printf("%f\t\t",p->grsds);
		printf("%f\n",p->sf);
	}
}
void modify()//�޸����ݴ��޸�
{
	float grsds;

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
		scanf("%s%s%f%f%f%f",zggz[i].num,zggz[i].name,&zggz[i].gw,&zggz[i].xj,&zggz[i].zw,&zggz[i].jx);
		/*����Ӧ������*/
		zggz[i] .yf=zggz[i] .gw+zggz[i] .xj+zggz[i] .zw +zggz[i] .jx;
		/*�����������˰*/
		
		zggz[i].grsds =shui(zggz[i] .yf);
		/*����ʵ������*/
		zggz[i].sf = zggz[i].yf-zggz[i].grsds;
		printf("��������ó���Ӧ��������%f,��������˰��%f,ʵ��������%f\n",zggz[i].yf,zggz[i].grsds,zggz[i].sf);
		printf("�޸������ѳɹ�!�뱣��.\n");
		break;
	}
}
    if(t==0)
	{
		printf("û���ҵ��������\n");
	}
}
void del()//��������ָ��Ԫ�ؿ�ʼһ�δӺ���ǰ�������ɾ������
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
void add()//����ְ�����ʺ������޸�
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
		scanf("%s%s%f%f%f%f",zggz[n] .num, zggz[n] .name, &zggz[n] .gw, &zggz[n] .xj, &zggz[n] .zw, &zggz[n] .jx);
		printf("%s %s %f %f %f %f",zggz[n].num, zggz[n].name, zggz[n].gw, zggz[n].xj, zggz[n].zw, zggz[n].jx);

		/*����Ӧ������*/
		zggz[n].yf = zggz[n].gw + zggz[n].xj + zggz[n].zw + zggz[n].jx;
		/*�����������˰*/
		zggz[n].grsds = shui(zggz[n].yf);
		/*����ʵ������*/
		zggz[n].sf = zggz[n].yf-zggz[n].grsds ;
		printf("��������ó���Ӧ��������%f,��������˰��%f,ʵ��������%f\n",zggz[n].yf,zggz[n].grsds,zggz[n].sf);
		n++;
        printf("������ݳɹ�!�뱣��.\n");
		}
	case 2:
		{
		break;
		}
	}
}
int main()
{
	int a;
	printf("\t\t###\t����ѧУְԱ�Ĺ������ݲ���ϵͳ\t###\t\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("!                                                                            !\n");
	printf("!                                                                            !\n"); 
    read();
	printf("                             !  !                                                                            !\n");
do{
	printf("!\t");
	printf("��ѡ�����������Ĳ���                                                 !\n");
	printf("!\t");
	printf("1  ��ѯ\t");
	printf("2  ���\t");
	printf("3  �޸�\t");
	printf("4  ɾ��\t");
	printf("5  ����\t");
	printf("6  ����\t");
	printf("7  �˳�");
	printf("              !\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	scanf("%d",&a);
	switch(a)
{
case 1:
	find();
	break;
case 2:
	list();
	break;
case 3:
    modify();
	break;
case 4:
	del();
	break;
case 5:
	add();
	break;
case 6:
	write();
	break;
case 7:
	exit(0);
}
}while(-1);
    return 0;
}