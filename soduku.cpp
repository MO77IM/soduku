#include <stdio.h>
#include <string.h>
#define SIZE 9
int soduku[SIZE][SIZE]={0};
int add[SIZE][SIZE]={0};
bool check_row(int soduku[][SIZE],int x,int y);
bool check_col(int soduku[][SIZE],int x,int y);
bool check_9(int soduku[][SIZE],int x,int y);
void find(int soduku[][SIZE],int add[][SIZE],int i);
int main(void){
	for(int i=0;i<SIZE;i++)
	  for(int j=0;j<SIZE;j++)
	  {
	  	scanf("%d",&soduku[i][j]);
	  	if(soduku[i][j]==0)
	  	  add[i][j]=1;
	}
	putchar('\n');
	find(soduku,add,0);
	getchar();
	getchar();
	return 0;
}
bool check_row(int soduku[][SIZE],int x,int y){
	int num=soduku[x][y];
	int count=0;
	for(int i=0;i<SIZE;i++)
	{
		if(num==soduku[x][i])
		  count++;
	}
	if(count>=2)
	  return false;
	return true;
}
bool check_col(int soduku[][SIZE],int x,int y){
	int num=soduku[x][y];
	int count=0;
	for(int i=0;i<SIZE;i++)
	{
		if(num==soduku[i][y])
		  count++;
	}
	if(count>=2)
	  return false;
	return true;
}
bool check_9(int soduku[][SIZE],int x,int y){
	int num=soduku[x][y];
	int count=0;
	int add_x=(x/3)*3;
	int add_y=(y/3)*3;
	for(int i=add_x;i<add_x+3;i++)
	  for(int j=add_y;j<add_y+3;j++)
	  {
	  	if(num==soduku[i][j])
	  	  count++;
	  }
	if(count>=2)
	    return false;
	return true;
}
void find(int soduku[][SIZE],int add[][SIZE],int i){
	if(i>=(SIZE)*(SIZE))
    {
      for(int i=0;i<SIZE;i++)
	  {
	  	for(int j=0;j<SIZE;j++)
	  	{
	  		printf("%d ",soduku[i][j]);
	  	}
	  	putchar('\n');
	  }
	  putchar('\n');
	  return;
    }
	int x=i/(SIZE);
	int y=i%(SIZE);
	if(add[x][y])
	{
		for(int j=1;j<=9;j++)
		{
			soduku[x][y]=j;
			if(check_row(soduku,x,y)&&check_col(soduku,x,y)&&check_9(soduku,x,y))
			{
				find(soduku,add,i+1);
			}
		}
		soduku[x][y]=0;
	}
	else
	{
		find(soduku,add,i+1);
	}
	return;
}
