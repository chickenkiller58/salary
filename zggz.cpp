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
		printf("打不开文件!\n");
		getch();
		exit(-1);
	}
   for(i=0;i<=100;i++,p++){
		fread(p,sizeof(struct zggz),1,fp);
		n++;
		if(feof(fp))
		{
	    printf("读取结束!\n");
		break;
		}
       }
    fclose(fp);
	printf("一共有%d位员工\n",n);

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
	printf("请输入您想要查询职工数据的工号\n");
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
	    printf("应发工资\t");
	    printf("个人所得税\t");
	    printf("实发工资\n");
		scanf("%s%s%d%d%d%d%d%d%d",zggz[i].num,zggz[i].name,&zggz[i].gw,&zggz[i].xj,&zggz[i].zw,&zggz[i].jx,&zggz[i].yf,&zggz[i].shui,&zggz[i].sf);
		printf("修改数据已成功!请保存.\n");
		break;
	}
}
    if(t==0)
	{
		printf("没有找到这个工号\n");
	}
}
void del()
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
void add()
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
	    printf("应发工资\t");
	    printf("个人所得税\t");
	    printf("实发工资\n");
		scanf("%s%s%d%d%d%d%d%d%d",zggz[n].num,zggz[n].name,&zggz[n].gw,&zggz[n].xj,&zggz[n].zw,&zggz[n].jx,&zggz[n].yf,&zggz[n].shui,&zggz[n].sf);
		n++;
		printf("添加数据成功!请保存.\n");
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
    printf("这是学校职员的工资数据操作系统\n");
	int a; 
    read();
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
do{
	printf("请选择您接下来的操作\n");
	printf("1  查询\t");
	printf("2  浏览\t");
	printf("3  修改\t");
	printf("4  删除\t");
	printf("5  增加\t");
	printf("6  保存\t");
	printf("7  退出\n");
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