#ifndef UI_H
#define UI_H

/**********************
 * Term configuration *
 **********************/

struct termios orig_termios;

void initTerm();
void resetTerm();
struct winsize getTermSize();

/*******************
 * Menu management * (left pane)
 *******************/

#define UI_MENUSIZE 2 // Menu size without currencies

#define UI_MENU_TITLESIZE 20
#define UI_MENU_VALUESIZE 20

#define UI_MENUHEADER "Epistam's Wonderful Money Trading Buddy"

typedef struct {
	char *title;
	char value[UI_MENU_VALUESIZE];
} UiMenuEntry;

typedef struct {
	int sel;
	UiMenuEntry entries[CUR_COUNT + UI_MENUSIZE]; 
} UiMenu;

void initMenu(UiMenu menu);

void displayTitle(int width);
void displaySkel(int height, int width);
void displayDecorations(int height, int width);
void displayEntry(UiMenuEntry menuentry, int sel);
void displayMenu(UiMenu menu);
void displayRefresh();

/************************
 * Histogram management * (right pane)
 ************************/

void displayHist(Cur currency, Hist histogram);

#endif
