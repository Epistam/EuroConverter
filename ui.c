#include <stdio.h>
#include <stdlib.h>
#include <termios.h> // Terminal attributes
#include <unistd.h> // For STDIN_FILENO
#include <string.h>
#include <sys/ioctl.h> // For term interaction / sending flags to it 
#include "include/defs.h"
#include "include/cur.h"
#include "include/ui.h"

/**********************
 * Term configuration *
 **********************/

#define termClear() printf("\033[2J") // move to (0,0) too
#define termClearLine() printf("\033[K") // move to (0,0) too
#define termUp() printf("\033\[1A")
#define termDown() printf("\033\[1B")
#define termFwd() printf("\033\[1C")
#define termBack() printf("\033\[1D")
#define termGoto(x,y) printf("\033[%d;%dH", y, x) // some fucking how coords are inverted in the term codes

void initTerm() {
	// Get current terminal attributes
	tcgetattr(STDIN_FILENO, &orig_termios);
	// Disable raw mode at exit
	atexit(resetTerm);
	// Duplicate attributes
	struct termios raw = orig_termios;
	// Disable echo and canonical on the duplicate attributes
	raw.c_lflag &= ~(ECHO | ICANON);
	// "commit" new attributes to shell
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
	// Hiding cursor
	fputs("\033[?25l",stdout);
}

void resetTerm() {
	// Resend original attributes to terminal
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
	// Restoring cursor
	fputs("\033[?25h",stdout);
}

struct winsize getTermSize() {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	
	return w;
}

/*******************
 * Menu management *
 *******************/

void initMenu(UiMenu menu, Currencies currencies) {
	int i;
	//menu.entries[0].title = malloc((strlen(UI_MENUENTRY_1_TEXT)+1)*sizeof(char));
	//strncpy(menu.entries[0].title,UI_MENUENTRY_1_TEXT,strlen(UI_MENUENTRY_1_TEXT)+1);
	//for(i = 1 ; i < CUR_COUNT ; i++) sprintf(menu.entries[i].title,"%s (%s) :",currencies[i-1].fullName,currencies[i-1].abbrev);
	// last ligne chargement
}

void displayTitle(int width) {
	int i;
	fputs("\033[48;5;15m",stdout); // Set line background color
	fputs("\033[38;5;0m",stdout); // Reset font color 

	if(width < strlen(UI_MENUHEADER)) { // In case of small window
		fwrite(UI_MENUHEADER, width-3, 1, stdout); // For size control
		fputs("...",stdout);
	} else {
		int j = (width/2)-(strlen(UI_MENUHEADER)/2), k = (width/2)+(strlen(UI_MENUHEADER)/2);

		for(i = 0 ; i < j ; i++) fputs(" ",stdout);
		fputs(UI_MENUHEADER,stdout);
		for(i=k; i < width -1 ; i++) fputs(" ",stdout);
	}

	fputs("\033[49m",stdout); // Reset line background color
	fputs("\033[39m",stdout); // Reset font color 
}

void displayDecorations(int height, int width) {
	fputs("\033[48;5;239m",stdout); // Set line background color

	int i;
	// Horizontal lines
	termGoto(1,2);
	for(i = 0 ; i < width ; i++) {
		fputs(" ",stdout);
	}
	termGoto(1,height);
	for(i = 0 ; i < width ; i++) {
		fputs(" ",stdout);
	}
	// Left side line
	termGoto(0,2);
	for(i = 0 ; i < height ; i++) {
		fputs(" ",stdout);
		termBack();
		termDown();
	}
	termGoto(2,2);
	for(i = 0 ; i < height ; i++) {
		fputs(" ",stdout);
		termBack();
		termDown();
	}
	// Middle line
	termGoto(width/2,2);
	for(i = 0 ; i < height ; i++) {
		fputs(" ",stdout);
		termBack();
		termDown();
	}
	termGoto(width/2+1,2);
	for(i = 0 ; i < height ; i++) {
		fputs(" ",stdout);
		termBack();
		termDown();
	}
	// Right line
	termGoto(width-1,2);
	for(i = 0 ; i < height ; i++) {
		fputs(" ",stdout);
		termBack();
		termDown();
	}
	termGoto(width,2);
	for(i = 2 ; i < height+1 ; i++) {
		fputs(" ",stdout);
		termGoto(width,i);
	}

	fputs("\033[49m",stdout); // Reset line background color
}

// Display skeleton
void displaySkel(int height, int width) {

	termClear();
	termGoto(0,0);

	displayTitle(width);
	displayDecorations(height, width);	
	termGoto(5,5);
}

// Display individual entries
void displayEntry(UiMenuEntry menuentry, int sel) {
	 // highlight si menu.sel
}

// Display the whole menu : header, entries and footer (?)
void displayMenu(UiMenu menu) {
	int i;
	//displayTitle();
	for(i = 0 ; i < UI_MENUSIZE ; i++) displayEntry(menu.entries[i], i);
		
}

void displayRefresh() {
	struct winsize w = getTermSize();
	displaySkel(w.ws_row, w.ws_col);

	fflush(stdout);
}

// Right half of screen 
void displayHist(Cur currency, Hist histogram) {
	
}
