#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "code_optimize.h"
#include "symbol.h"
void push(char *);
void codegen_exp();
void codegen_assign();
void codegen_umin();
void codegen_while1();
void codegen_while2();
void codegen_while3();

char st[20][20];
int stc=0;
char temp[10];

int top;
int lnum;
int sl[10];
int ltop;


int optimize=0;

void push(char *v)
{
	strcpy(st[++top],v);
}

void codegen_init()
{
	FILE *fp=fopen("code","w");
	fprintf(fp,"----Intermediate Code----\n");
	fclose(fp);
}
void codegen_exp()
{
	FILE *fp=fopen("code","a");
	strcpy(temp,"t");
	char out[10];
	itoa(stc,out);
	stc++;
	strcat(temp,out);
	if(optimize==1)
	{
		
		constant_propogation(temp,st[top-2],st[top-1],st[top]);
	}
	else
		fprintf(fp,"\t%s = %s %s %s\n",temp,st[top-2],st[top-1],st[top]);
	top-=2;
	strcpy(st[top],temp);
	fclose(fp);
}

void codegen_assign()
{
	FILE *fp=fopen("code","a");
	fprintf(fp,"\t%s = %s\n",st[top-2],st[top]);
	update_symbol(st[top-2],st[top]);
	top-=2;
	fclose(fp);
}



void codegen_while1()
{
	FILE *fp=fopen("code","a");
	sl[ltop++]=lnum;
	lnum++;
	sl[ltop]=lnum;
	lnum++;
	fprintf(fp,"L%d: \n",sl[ltop-1]);
	ltop++;
	fclose(fp);
}
void codegen_while2()
{
	FILE *fp=fopen("code","a");
 	strcpy(temp,"t");
	char out[10];
	itoa(stc,out);
 	strcat(temp,out);
 	fprintf(fp,"\t%s = not %s\n",temp,st[top]);
 	fprintf(fp,"\tif %s  goto L%d\n",temp,sl[ltop-1]);
 	stc++;
 	fclose(fp);
}

void codegen_while3()
{
	FILE *fp=fopen("code","a");
	fprintf(fp,"\tgoto L%d \n",sl[ltop-2]);
	fprintf(fp,"L%d:\n",sl[ltop-1]);
	ltop=ltop-2;
	fclose(fp);
}

void codegen_if1()
{
	FILE *fp=fopen("code","a");
	sl[ltop++]=lnum++;
 	strcpy(temp,"t");
	char out[10];
	itoa(stc,out);
 	strcat(temp,out);

 	fprintf(fp,"\t%s = not %s\n",temp,st[top]);
 	fprintf(fp,"\tif %s  goto L%d\n",temp,sl[ltop-1]);
 	stc++;
 	fclose(fp);
}

void codegen_if2()
{
	FILE *fp=fopen("code","a");
	fprintf(fp,"\tgoto L%d\n",sl[ltop-1]);
	fprintf(fp,"L%d: \n",sl[ltop-1]);
	ltop--;
	sl[ltop++]=lnum++;
	fclose(fp);
}
void codegen_if3()
{
	FILE *fp=fopen("code","a");
	fprintf(fp,"\tgoto L%d\n",sl[ltop-1]);
	fprintf(fp,"L%d:\n",sl[ltop-1]);
	ltop--;
	fclose(fp);
	
	
}
void codegen_if4()
{
	FILE *fp=fopen("code","a");
	fprintf(fp,"L%d:\n",sl[ltop-1]);
	ltop--;
	fclose(fp);
}

void codegen_umin()
{
	FILE *fp=fopen("code","a");
 	strcpy(temp,"t");
	char out[10];
	itoa(stc,out);
 	strcat(temp,out);
 	fprintf(fp,"\t%s = -%s\n",temp,st[top]);
 	top--;
 	strcpy(st[top],temp);
 	stc++;
 	fclose(fp);
}



