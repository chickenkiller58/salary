
#include<stdio.h>
#include<string.h>
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
 {    int i;
      
	  FILE *fp;
	  p=zggz;
	  if((fp=fopen("gz.dat","r"))==NULL)
	  {
		  printf("�򲻿��ļ�\n");
		  getch();
		  exit(-1);
	  }
  for(i=0;i<=100;i++,p++)
 { 
      n++;
	  fread(p,sizeof(struct zggz),1,fp);
	  cout<<p->num<<p->name<<p->gw<<p->xj<<p->zw<<p->jx<<p->yf<<p->shui<<p->sf<<endl;
	  
	  if(feof(fp))
	  {
		  break;
	  }
	      
 }
      fclose(fp);
      cout<<"һ����"<<n<<"λְ��"<<endl;
 }
int main()
{   
  cout<<"����"<<"  " <<"����"<<"  "<<"��λ����"<<"  "<<"н������"<<"  "<<"��λ����"<<"  "<<"jx����"<<"  "<<"yf����"<<"  "<<"��������˰"<<"  "<<"ʵ�ʹ���"<<endl;
  read();
  return 0;
}
