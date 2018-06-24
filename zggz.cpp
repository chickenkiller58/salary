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
	if((fp=fopen("gz.dat","rb"))==NULL)
	{
		cout<<"打开文件失败.\n";
		getch();
		exit(-1);
	}
   for(i=0;i<=100;i++,p++){
		fread(p,sizeof(struct zggz),1,fp);
		n++;
		cout<<"  "<<p->num<<"  "<<p->name<<"  "<<p->gw<<"  "<<p->xj<<"  "<<p->zw<<"  "<<p->jx<<"  "<<p->yf<<"  "<<p->shui<<"  "<<p->sf<<endl;
		
		if(feof(fp))
		{
	    cout<<"读取结束\n";
		break;
		}
       }
    fclose(fp);
	cout<<"一共有"<<n<<"位员工";
}
void write()
{
	FILE*fp;
		int i;
	p=zggz;

	if((fp=fopen("gz.dat","wt+"))==NULL)
	{
		cout<<"打开文件失败.\n";
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
	int i;
    char gonghao[20];
	cin>>gonghao;
for(i=0;i<100;i++)
	{
	if(strcmp(gonghao,zggz[i].num)==0)
	{
		cout<<zggz[i].num<<"  "<<zggz[i].name<<"  "<<zggz[i].gw<<"  "<<zggz[i].xj<<"  "<<zggz[i].zw<<"  "<<zggz[i].jx<<"  "<<zggz[i].yf<<"  "<<zggz[i].shui<<"  "<<zggz[i].sf<<endl;
		break;
	}
	}
}
void list()
{

	p=zggz;
	int j;
	for(j=0;j<n;j++,p++)
	{
        cout<<"  "<<p->num<<"  "<<p->name<<"  "<<p->gw<<"  "<<p->xj<<"  "<<p->zw<<"  "<<p->jx<<"  "<<p->yf<<"  "<<p->shui<<"  "<<p->sf<<endl;
	}
}
void modify()
{
    int i;
    char gonghao[20];
	cin>>gonghao;
    for(i=0;i<100;i++)
	{
	if(strcmp(gonghao,zggz[i].num)==0)
	{
		cin>>zggz[i].num>>"  ">>zggz[i].name>>"  ">>zggz[i].gw>>"  ">>zggz[i].xj>>"  ">>zggz[i].zw>>"  ">>zggz[i].jx>>"  ">>zggz[i].yf>>"  ">>zggz[i].shui>>"  ">>zggz[i].sf;
		break;
	}
}
}
int main()
{
    cout<<" "<<"工号"<<" "<<"姓名"<<" "<<"岗位工资"<<" "<<"薪级工资"<<" "<<"职务津贴"<<" "<<"绩效工资"<<" "<<"应发工资"<<" "<<"个人所得税"<<" "<<"实发工资"<<endl;
    read();
	find();
    list();
	modify();
    write();
	return 0;
}
