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
	printf("%s\n",currencies[0].abbrev);

	return EXIT_SUCCESS;
}
