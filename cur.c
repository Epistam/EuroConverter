#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/defs.h"
#include "include/cur.h"
#include "include/net.h"

// Basic currencies initialization based on config data
void curInit(Currencies currencies) {
	strncpy(currencies[0].abbrev,CUR_1_ABBR, CUR_ABBR_SIZE);
	strncpy(currencies[0].fullName, CUR_1_NAME, CUR_NAME_SIZE);
	strncpy(currencies[1].abbrev,CUR_2_ABBR, CUR_ABBR_SIZE);
	strncpy(currencies[1].fullName, CUR_2_NAME, CUR_NAME_SIZE);
	strncpy(currencies[2].abbrev,CUR_3_ABBR, CUR_ABBR_SIZE);
	strncpy(currencies[2].fullName, CUR_3_NAME, CUR_NAME_SIZE);
	strncpy(currencies[3].abbrev,CUR_4_ABBR, CUR_ABBR_SIZE);
	strncpy(currencies[3].fullName, CUR_4_NAME, CUR_NAME_SIZE);
}

// Get an individual currency's change rate
void getRate(Cur currency) {
	currency.rate = queryRate(currency); 
}

// Get an individual currency's change rate history
void getHistory(Cur currency, int days) {
	currency.histPtr = queryHistory(currency, days);
}
