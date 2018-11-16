#ifndef CUR_H
#define CUR_H

/*******************************
 * Constants and configuration *
 *******************************/

// General currencies configuration
#define CUR_ABBR_SIZE 3
#define CUR_NAME_SIZE 50

// Specific currencies definition
#define CUR_1_ABBR "ZWD"
#define CUR_2_ABBR "VEF"
#define CUR_3_ABBR "RUB"
#define CUR_4_ABBR "ILS"

#define CUR_1_NAME "Dollar Zimbabwéen"
#define CUR_2_NAME "Bolivar Vénézuelien"
#define CUR_3_NAME "Rouble russe"
#define CUR_4_NAME "Shekel Israélien"

/**************
 * Structures *
 **************/

// Histograms
typedef double *Hist;

// Individual currency
typedef struct { // Individual currency
	char abbrev[CUR_ABBR_SIZE+1]; // Since all values are contiguous in the struct, we need to allow for \0 to appear on the first string// TODO : const with pointers ?
	char fullName[CUR_NAME_SIZE];
	double rate;
	Hist histPtr;
} Cur;

// All used currencies
typedef Cur Currencies[CUR_COUNT]; // All currencies

/*************
 * Functions *
 *************/

// Basic currencies initialization based on config data
void curInit(Currencies currencies);

// Fill in individual currencies with web data
double getChange(Cur currency);
void getHistory(Cur currency, int days);

#endif
