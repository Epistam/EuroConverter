#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For STDIN_FILENO
#include <sys/ioctl.h> // For term interaction / sending flags to it 
#include <termios.h>
#include <string.h>
#include "include/defs.h"
#include "include/cur.h"
#include "include/ui.h"
#include "include/net.h"

int main(void) {

	initTerm();
	atexit(resetTerm);
	displayRefresh();

	Currencies currencies;

	curInit(currencies);
	//int i;
	//printf("%s",currencies[0].fullName);

	UiMenu menu;

//	menu.entries[0].title = malloc((strlen(UI_MENUENTRY_1_TEXT)+1)*sizeof(char));
//	strncpy(menu.entries[0].title,UI_MENUENTRY_1_TEXT,strlen(UI_MENUENTRY_1_TEXT)+1);

	menu.entries[0].title = strdup(UI_MENUENTRY_1_TEXT);
	//initMenu(menu, currencies);

	printf("%s\n",menu.entries[0].title);
	puts("");

	return EXIT_SUCCESS;
}
