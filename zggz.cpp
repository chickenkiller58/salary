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
		cout<<"���ļ�ʧ��.\n";
		getch();
		exit(-1);
	}
   for(i=0;i<=100;i++,p++){
		fread(p,sizeof(struct zggz),1,fp);
		n++;
		cout<<"  "<<p->num<<"  "<<p->name<<"  "<<p->gw<<"  "<<p->xj<<"  "<<p->zw<<"  "<<p->jx<<"  "<<p->yf<<"  "<<p->shui<<"  "<<p->sf<<endl;
		
		if(feof(fp))
		{
	    cout<<"��ȡ����\n";
		break;
		}
       }
    fclose(fp);
	cout<<"һ����"<<n<<"λԱ��";
}
void write()
{
	FILE*fp;
		int i;
	p=zggz;

	if((fp=fopen("gz.dat","wt+"))==NULL)
	{
		cout<<"���ļ�ʧ��.\n";
		getch();
	    exit(-1);
	}
	
      fwrite(p,sizeof(struct zggz),n,fp);

	fclose(fp);
	
}
void find()
{
	cin>>p->num;
}
int main()
{
    cout<<" "<<"����"<<" "<<"����"<<" "<<"��λ����"<<" "<<"н������"<<" "<<"ְ�����"<<" "<<"��Ч����"<<" "<<"Ӧ������"<<" "<<"��������˰"<<" "<<"ʵ������"<<endl;
    read();


	
	return 0;
}
