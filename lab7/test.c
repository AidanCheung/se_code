#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int Quit(int argc,char *argv[])
{
	exit(0);
}

int  Version(int argc, char* argv[])
{
    printf("Menu Program V1.0\n");
    return 0;
}

int main(int argc,char *argv[])
{
	MenuConfig("version","xxx v1.0(Menu program v1.0 inside)",Version);
	MenuConfig("quit","Quit from xxx menu\n",Quit);
	ExecuteMenu();
}