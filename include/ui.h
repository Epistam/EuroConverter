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

#define UI_MENUENTRY_1_TEXT "Valeur à convertir (euros) :"

#define UI_MENUHEADER "Epistam's Wonderful Money Trading Buddy"

typedef struct {
	char *title;
	char *value;
} UiMenuEntry;

typedef struct {
	int sel;
	UiMenuEntry entries[4 + UI_MENUSIZE];
} UiMenu;

void initMenu(UiMenu menu, Currencies currencies);

void displayTitle(int width);
void displaySkel(int height, int width);
void displayDecorations(int height, int width);
void displayEntry(UiMenuEntry menuentry, int width);
void displayEntryHighlight(UiMenuEntry menuentry, int width);
void displayMenu(UiMenu menu, int width);
void displayRefresh();

/************************
 * Histogram management * (right pane)
 ************************/

void displayHist(Cur currency, Hist histogram);

#endif
