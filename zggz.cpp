#include<stdlib.h>
#include<conio.h>
#include<iostream>
using namespace std;
int n;
struct zggz
{
	char num[20];
	char name[20];
    float gw;//职员岗位工资
	float xj;//职员薪级工资
	float zw;//职员职务工资
	float jx;//职员绩效工资
	float yf;//职员应发工资
	float grsds;//职员的个人所得税
	float sf;//职员实发工资
}zggz[100],*p;
void shui()//计算个人所得税方式
{
float xj;
float zw;
float jx;
float sf;
float grsds;
	if(yf<=500)
		grsds=yf*0.05;
	else if(yf<=2000)
		grsds=yf*0.10;
    else if(p->yf<=5000)
	grsds=p->yf*0.15;
	else if(yf<=20000)
		grsds=yf*0.20;
	else if(yf<=40000)
		grsds=yf*0.25;
	else if(yf<=60000)
		grsds=yf*0.30;
	else if(yf<=80000)
	grsds=yf*0.35;
	else if(yf<=100000)
		grsds=yf*0.40;
	else if(yf>100000)
}	
void read()
{   FILE*fp;
	int i;
	p=zggz;
	if((fp=fopen("gz.dat","rt"))==NULL)
	{
		printf("打不开文件!\n");
		getch();
		exit(-1);
	}
   for(i=0;i<=100;i++,p++){
		fread(p,sizeof(struct zggz),1,fp);
		n++;
		if(feof(fp))
		{
		printf("!");
	    printf("\t\t读取结束!\t\t");
		printf("\t\t                     !\n");
		break;
		}
       }
    fclose(fp);
	printf("!");
	printf("\t\t一共有%d位员工哟.\t\t",n);
   
}
void write()
{
	FILE*fp;
		int i;
	p=zggz;

	if((fp=fopen("gz.dat","wt+"))==NULL)
	{
	    printf("打开文件失败.\n");
		getch();
	    exit(-1);
	}
	for(i=1;i<=n;i++,p++)
	{
		fwrite(p,sizeof(struct zggz),1,fp);
	}
	printf("保存已成功!\n");
	fclose(fp);
	
}
void find()
{   
	int i,t=0;
    char gonghao[20];
	printf("!\t\t\t请输入您想要查询职工数据的工号\t\t\t     !\n");
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
		
		printf("没有找到这个工号\n");
	
	}
	
}
void list()
{

	p=zggz;
	int j;
	printf("工号\t");
	printf("姓名\t");
	printf("岗位工资\t");
	printf("薪级工资\t");
	printf("职务津贴\t");
	printf("绩效工资\t");
	printf("应发工资\t");
	printf("个人所得税\t");
	printf("实发工资\n");
	
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
void modify()//修改数据待修改
{
	float yf;
float gw;
float xj;
float zw;
float jx;
float sf;
float grsds;
    int i,t=0;
    char gonghao[20];
	printf("请输入你想要修改工资数据的职工的工号\n");
	scanf("%s",gonghao);
    for(i=0;i<100;i++)
	{
	if(strcmp(gonghao,zggz[i].num)==0)
	{   
		t=1;
		printf("请按顺序输入你的新数据\n");
		printf("工号\t");
	    printf("姓名\t");
	    printf("岗位工资\t");
	    printf("薪级工资\t");
	    printf("职务津贴\t");
	    printf("绩效工资\t");
		scanf("%s%s%f%f%f%f",zggz[i].num,zggz[i].name,&zggz[i].gw,&zggz[i].xj,&zggz[i].zw,&zggz[i].jx);
		
		printf("经过计算得出其应发工资是%f,个人所得税是%f,实发工资是%f\n",zggz[i].yf,zggz[i].grsds,zggz[i].sf);
		printf("修改数据已成功!请保存.\n");
		break;
	}
}
    if(t==0)
	{
		printf("没有找到这个工号\n");
	}
}
void del()//将函数从指定元素开始一次从后向前覆盖完成删除功能
{   
	int b,i,j,t=0,k=0;
    char gonghao[20];

		printf("是否确定删除数据?\n");
	    printf("1  确定\t");
	    printf("2  退出\t");
		scanf("%d",&b);
	switch(b)
	{
	case 1:
		{
			printf("请输入您想要删除职工数据的工号\n");
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
					printf("删除已成功!请保存.\n");
		            break;
				}  
			}
			if(t==0)
			{
				printf("没有找到这个工号\n");
			}
		}
	case 2:
			{
				break;
			}
	}
}
void add()//增加职工工资函数待修改
{   
	
	int c;
	printf("现在一共有%d位员工\n",n);
	printf("是否确定增加一名职工的工资数据?\n");
	printf("1  确定\t");
	printf("2  退出\t");
	scanf("%d",&c);
	switch(c)
	{
	case 1:
		{
		printf("请按顺序输入你的数据\n");
		printf("工号\t");
	    printf("姓名\t");
	    printf("岗位工资\t");
	    printf("薪级工资\t");
	    printf("职务津贴\t");
	    printf("绩效工资\t");
		scanf("%s%s%f%f%f%f",zggz[n] .num, zggz[n] .name, &zggz[n] .gw, &zggz[n] .xj, &zggz[n] .zw, &zggz[n] .jx);
		/*计算应发工资*/
		zggz[n] .yf=zggz[n] .gw+zggz[n] .xj+zggz[n] .zw +zggz[n] .jx;
		/*计算个人所得税*/
		zggz[n].grsds = shui(zggz[n] .yf);
		/*计算实发工资*/
		zggz[n].sf = 应发工资-个人所得税


		
		printf("添加数据成功!请保存.\n");
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
	printf("\t\t###\t这是学校职员的工资数据操作系统\t###\t\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("!                                                                            !\n");
	printf("!                                                                            !\n"); 
    read();
	printf("                             !  !                                                                            !\n");
do{
	printf("!\t");
	printf("请选择您接下来的操作                                                 !\n");
	printf("!\t");
	printf("1  查询\t");
	printf("2  浏览\t");
	printf("3  修改\t");
	printf("4  删除\t");
	printf("5  增加\t");
	printf("6  保存\t");
	printf("7  退出");
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