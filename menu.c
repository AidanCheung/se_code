#include<stdio.h>
#include<stdlib.h>

int main()
{
	char cmd[128];
	while(1)
	{
		scanf("%s",cmd);
		if(!strcmp(cmd,"help"))
		{
			printf("This is help cmd!\n");
		}
		else if(!strcmp(cmd,"quit"))
		{
			exit(0);
		}
		else if(!strcmp(cmd,"ls"))
		{
			printf("This is ls cmd!\n");
		}
		else if(!strcmp(cmd,"pwd"))
		{
			printf("This is pwd cmd!\n");
		}
		else if(!strcmp(cmd,"ps"))
		{
			printf("This is ps cmd!\n");
		}
		else if(!strcmp(cmd,"vi"))
		{
			printf("This is vi cmd!\n");
		}
		else if(!strcmp(cmd,"sudo"))
		{
			printf("This is sudo cmd!\n");
		}
		else if(!strcmp(cmd,"mkdir"))
		{
			printf("This is mkdir cmd!\n");
		}
		else
		{
			printf("Wrong cmd!\n");
		}
	}
	return 0;
}

