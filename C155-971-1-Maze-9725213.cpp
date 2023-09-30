#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void check(int a[][7],int *n,int *m,int r[],int s[],int *ptr);
int main()
{
	int i,j,p=1,q=1,flag1=0,k=0;
	int misx[50],misy[50];
	int x[12][7]=
	{
	{0,0,0,0,0,0,0},
	{0,10,1,1,1,1,0},
	{0,1,0,1,1,1,0},
	{0,1,0,1,0,1,0},
	{0,0,1,0,0,1,0},
	{0,1,0,1,1,1,0},
	{0,0,1,1,0,1,0},
	{0,1,1,1,0,0,0},
	{0,0,1,1,1,0,0},
	{0,1,1,1,0,0,0},
	{0,0,1,1,1,1,0},
	{0,0,0,0,0,0,0},
    };
    for(i=0;i<11;i++){
		for(j=0;j<7;j++){
			if(x[i][j]==0){
				printf("#");
			}
			if(x[i][j]==1||x[i][j]==2||x[i][j]==3){
				printf(" ");
			}
			if(x[i][j]==10){
				printf("M");
			}
		}
		printf("\n");
	}
	getch();
	system("cls");
    while(p<11&&q<6){
    	check(x,&p,&q,misx,misy,&k);
	for(i=0;i<11;i++){
		for(j=0;j<7;j++){
			if(x[i][j]==0){
				printf("#");
			}
			if(x[i][j]==1||x[i][j]==2||x[i][j]==3){
				printf(" ");
			}
			if(x[i][j]==10){
				printf("M");
			}
		}
		printf("\n");
	}
	getch();
	system("cls");
    }
    system("cls");
    printf("you win the game");
}
void check(int a[][7],int *n,int *m,int r[],int s[],int *ptr)
{	
int flag=0;
a[*n][*m]=2;
r[*ptr]=*n;
s[*ptr]=*m;
 if(a[*n+1][*m]==1&&flag==0){
    a[*n+1][*m]=10;
    *n=*n+1;
    flag=1;	
}
 if(a[*n+1][*m]!=1&&a[*n][*m+1]==1&&flag==0){
	a[*n][*m+1]=10;
	*m=*m+1;
	flag=1;
}
if(a[*n+1][*m]!=1&&a[*n][*m+1]!=1&&a[*n-1][*m]==1&&flag==0){
	a[*n-1][*m]=10;
	*n=*n-1;
	flag=1;
}
if(a[*n+1][*m]!=1&&a[*n][*m+1]!=1&&a[*n-1][*m]!=1&&a[*n][*m-1]==1&&flag==0){
	a[*n][*m-1]=10;
	*m=*m-1;
	flag=1;
}
if(flag==1){
	*ptr=*ptr+1;
}
if(flag==0){
	if(*n==10&&*m==5){
		*m=*m+1;
		*n=*n+1;
	}else{
		a[*n][*m]=3;
		*n=r[*ptr-1];
		*m=s[*ptr-1];
	a[*n][*m]=10;
	*ptr=*ptr-1;
	}
}
}
