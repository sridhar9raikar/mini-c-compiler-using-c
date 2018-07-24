#include "symbol.h"
#include <ctype.h>
#include "convertion.h"
void constant_folding(char *result,char *arg1,char *op,char *arg2,char *type);

int check_op(char *op)
{
	if(strcmp(op,"+")==0)
		return 1;
	else if(strcmp(op,"-")==0)
		return 1;
	else if(strcmp(op,"*")==0)
		return 1;
	else if(strcmp(op,"/")==0)
		return 1;
	else
		return 0;
}

void constant_propogation(char *result,char *arg1,char *op,char *arg2)
{
	setvbuf (stdout, NULL, _IONBF, 0);

	int a= check_value(arg1);
	int b= check_value(arg2);
	char type[20];
	FILE *fp=fopen("code","a");
	if(a!=-1 && b!=-1)
	{

		//fprintf(fp,"\t%s = %s %s %s\n",result,table[a].val,op,table[b].val);
		if(strcmp(table[a].type,"float")==0 || strcmp(table[b].type,"float")==0)
			strcpy(type,"float");
		else
			strcpy(type,"int");
		constant_folding(result,table[a].val,op,table[b].val,type);
	}
	else if(a!=-1)
	{
		if(strcmp(table[a].type,"float")==0)
			strcpy(type,"float");
		else
			strcpy(type,"int");
		constant_folding(result,table[a].val,op,arg2,type);
	}
	else if(b!=-1)
	{
		if(strcmp(table[b].type,"float")==0)
			strcpy(type,"float");
		else
			strcpy(type,"int");
		constant_folding(result,arg1,op,table[b].val,type);
	}
	
	else
	{
		//printf("called in else \n");
		char type[20];
		if(check_type(arg1)==2 || check_type(arg2)==2)
			strcpy(type,"float");
		else if(check_type(arg1)==1 && check_type(arg2)==1)
			strcpy(type,"int");
		else
			strcpy(type,"int");

		constant_folding(result,arg1,op,arg2,type);
	}
	fclose(fp);
}

void constant_folding(char *result,char *arg1,char *op,char *arg2,char *type)
{
	FILE *fp=fopen("code","a");
	int r=check_op(op);

	if(strcmp(type,"float")==0 && r==1)
	{
		if(isdigit(arg1[0])&&isdigit(arg2[0]))
		{
			float r;
			if(strcmp(op,"*")==0)
			r=strtof(arg1,NULL)*strtof(arg2,NULL);
			else if(strcmp(op,"+")==0)
				r=strtof(arg1,NULL)+strtof(arg2,NULL);
			else if(strcmp(op,"-")==0)
				r=strtof(arg1,NULL)-strtof(arg2,NULL);
			else
				r=strtof(arg1,NULL)/strtof(arg2,NULL);

			fprintf(fp,"\t%s = %f\n",result,r);
			char output[sizeof(float)];
			ftoa(r,output,2);
			addintemp(result,output);
		}
	}
	else if(strcmp(type,"int")==0 && r==1)
	{
		if(isdigit(arg1[0])&&isdigit(arg2[0]))
		{
			int r;
			if(strcmp(op,"*")==0)
			r=atoi(arg1)*atoi(arg2);
			else if(strcmp(op,"+")==0)
				r=atoi(arg1)+atoi(arg2);
			else if(strcmp(op,"-")==0)
				r=atoi(arg1)-atoi(arg2);
			else
				r=atoi(arg1)/atoi(arg2);

			fprintf(fp,"\t%s = %d\n",result,r);
			
			char output[sizeof(int)];
			itoa(r,output);
			addintemp(result,output);
			
		}
	}
	else
		fprintf(fp,"\t%s = %s %s %s\n",result,arg1,op,arg2);
	fclose(fp);
}
