#ifndef symboltable
#define symboltable
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
char lexval[100];
char lexid[10];
char lextype[10];

int value=0;

struct st
{       
	char name[10];
	char val[10];
	char  type[6];
	int size;
}; 
struct st table[100];

struct token
{
	char name[50];
	char value[50];
};
struct token tok[100];

struct temp
{
	char name[20];
	char value[20];
};
struct temp te[50];
int tc=0;

int tcount=0;

int search(char *s)
{
	for(int i=0;i<value;i++)
	{
		if(strcmp(s,table[i].name)==0)
			return 1;
	}
	return 0;
}

int search1(char *s)
{
	for(int i=0;i<value;i++)
	{
		if(strcmp(s,table[i].name)==0)
			return i;
	}
	return -1;
}

void update(char *s,char *val)
{
	int x=search1(s);
	if(x!=-1)
		strcpy(table[x].val,val);
}

int size(char *type)
{
	if(strcmp(type,"int")==0)
	 	return 4;
	 else if(strcmp(type,"char")==0)
	 	return 2;
	 else if(strcmp(type,"float")==0)
	 	return 8;
	 else if(strcmp(type,"double")==0)
	 	return 16;
	 else
	 	return 0;
}


void add_id(char *type,char *s,char *val)
{
	if(search(s)==0)
	{
	 	strcpy(table[value].name,s);
	 	strcpy(table[value].type,type);
	 	if(val!=NULL)
	 		strcpy(table[value].val,val);	 		
	 	if(strcmp(type,"array")!=0)
	 		table[value].size=size(type);
	 	else
	 		table[value].size=size(lextype)*atoi(lexval);
	 	value++;
	}
}

void print_struct()
{
	FILE *fp;
	fp=fopen("symboltable","w");
	fprintf(fp,"Type\t\t Name\t\t Value\t\t size\t\n");
	for(int i=0;i<value;i++)
	{
		fprintf(fp,"%s\t\t %s\t\t %s\t\t %d\t\n",table[i].type,table[i].name,table[i].val,table[i].size);
	}
	fclose(fp);
}

int check_value(char *arg)
{

	for(int i=0;i<value;i++)
	{
		if(strcmp(table[i].name,arg)==0 && table[i].val!=NULL)
		{
			//printf("%s %s\n",arg,table[i].val);
			return i;
		}
	}
	return -1;
}
int check_type(char *arg)
{
	for(int i=0;i<value;i++)
	{
		if(strcmp(table[i].name,arg)==0 && strcmp(table[i].type,"float")==0)
		{
			return 2;
		}
		else if(strcmp(table[i].name,arg)==0 && strcmp(table[i].type,"int")==0)
		{
			return 1;
		}
	}
	return 0;
}

void addtoken(char *name,char *value)
{
	strcpy(tok[tcount].name,name);
	strcpy(tok[tcount].value,value);
	tcount++;
}
void printtok()
{
	FILE *fp=fopen("token.txt","w");
	for(int i=0;i<tcount;i++)
	{
		fprintf(fp,"<%s , %s >\n",tok[i].name,tok[i].value);
	}
	fclose(fp);
	
}

void addintemp(char *name,char *value)
{
	strcpy(te[tc].name,name);
	strcpy(te[tc].value,value);
	tc++;
}

void update_symbol(char *name,char *temp)
{
	for(int i=0;i<tc;i++)
	{
		if(strcmp(temp,te[i].name)==0)
		{
			int r=check_value(name);
			if(r!=-1)
			{
				strcpy(table[r].val,te[i].value);
				tc--;
			}
			
		}
	}
}

#endif















