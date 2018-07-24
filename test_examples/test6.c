#include<stdio.h>

int main()
{
	int i=10,j=12;
	int k;
	float f=34.6;
	char s;
	if(i<100)
	{
		j=i;
		while(j<50)
		{
			k=j;
			j++;
		}
		while(j<50)
		{
			k=j;
			j++;
		}
	}
	else
	{
		j=j+5;
		while(j<50)
		{
			k=j;
			j++;
		}
		while(j<50)
		{
			k=j;
			j++;
		}
	}
}
