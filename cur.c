#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/defs.h"
#include "include/cur.h"
#include "include/net.h"

// Basic currencies initialization based on config data
void curInit(Currencies currencies) {
/*	currencies[0].abbrev = malloc((strlen(CUR_1_ABBR)+1)*sizeof(char)); // +1 is to allow room for '\0'
	currencies[0].fullName = malloc((strlen(CUR_1_NAME)+1)*sizeof(char));
	strncpy(currencies[0].abbrev,CUR_1_ABBR, strlen(CUR_1_ABBR)+1);
	strncpy(currencies[0].fullName, CUR_1_NAME, strlen(CUR_1_NAME)+1);

	currencies[1].abbrev = malloc((strlen(CUR_2_ABBR)+1)*sizeof(char));
	currencies[1].fullName = malloc((strlen(CUR_2_NAME)+1)*sizeof(char));
	strncpy(currencies[1].abbrev,CUR_2_ABBR, strlen(CUR_2_ABBR)+1);
	strncpy(currencies[1].fullName, CUR_2_NAME, strlen(CUR_2_NAME)+1);

	currencies[2].abbrev = malloc((strlen(CUR_3_ABBR)+1)*sizeof(char));
	currencies[2].fullName = malloc((strlen(CUR_3_NAME)+1)*sizeof(char));
	strncpy(currencies[2].abbrev,CUR_3_ABBR, strlen(CUR_3_ABBR)+1);
	strncpy(currencies[2].fullName, CUR_3_NAME, strlen(CUR_3_NAME)+1);

	currencies[3].abbrev = malloc((strlen(CUR_4_ABBR)+1)*sizeof(char));
	currencies[3].fullName = malloc((strlen(CUR_4_NAME)+1)*sizeof(char));
	strncpy(currencies[3].abbrev,CUR_4_ABBR, strlen(CUR_4_ABBR)+1);
	strncpy(currencies[3].fullName, CUR_4_NAME, strlen(CUR_4_NAME)+1);
*/
	// Apparamment strdup s'occupe des problèmes de mémoire contigue avec les \0 dans les struct
	currencies[0].abbrev = strdup(CUR_1_ABBR);
	currencies[0].fullName = strdup(CUR_1_NAME);
	currencies[1].abbrev = strdup(CUR_2_ABBR);
	currencies[1].fullName = strdup(CUR_2_NAME);
	currencies[2].abbrev = strdup(CUR_3_ABBR);
	currencies[2].fullName = strdup(CUR_3_NAME);
	currencies[3].abbrev = strdup(CUR_4_ABBR);
	currencies[3].fullName = strdup(CUR_4_NAME);
}

// Get an individual currency's change rate
void getRate(Cur currency) {
	currency.rate = queryRate(currency); 
}

// Get an individual currency's change rate history
void getHistory(Cur currency, int days) {
	currency.histPtr = queryHistory(currency, days);
}
