#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void write(char *buff, FILE *op)
{
	fputs(buff, op);
}
int readline(FILE *fptr, char buff[100])
{
	if ((fgets(buff, 100, fptr) != NULL))
	{
		return 1;
	}
	return 0;

}
char *getFilename(char buff[100])
{
	char *fname = (char *)malloc(sizeof(char) * 100);
	char *check = " include \"";
	int j = 0;
	if (buff[0] == '#')
	{
		for (int i = 1; i <= 9; i++)
		{
			if (buff[i] != check[i])
			{
				return NULL;
			}
		}
		for (int i = 10; buff[i] != '"'; i++)
		{
			*(fname + j) = buff[i];
			j += 1;
		}
		*(fname + j) = '\0';
		return fname;
	}
	return NULL;
}
void writeLine(FILE *fptr, char *buff, FILE *op)
{
	char *fname;
	FILE *fp2 = fopen("demo.txt", "a");
	int v = readline(fptr, buff);
	if (v == 0)
	{
		return;
	}
	else
	{
		fname = getFilename(buff);
		if (fname == NULL)
		{
			write(buff, op);
		
			writeLine(fptr, buff, op);
		}
		else
		{
			writeLine(fopen(fname, "r"), buff, op);
			writeLine(fptr, buff, op);
		}
		return;
	}

}
