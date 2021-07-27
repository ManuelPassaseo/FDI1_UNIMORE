#include "scacchiera.h"
#include <stdio.h>
void stampa_scacchiera(const struct scacchiera* sc)
{
	printf("+---+---+---+---+---+---+---+---+");
	for (int r =7 ; r >= 0; --r)
	{
		printf("\n");
		for (int c = 0; c < 8; ++c)
		{
			printf("| %c ",sc->caselle[c*8+r]);
		}
		printf("|\n");
		printf("+---+---+---+---+---+---+---+---+");
	}
}
void stampa_scacchiera1(const struct scacchiera* sc) {
	printf("+---+---+---+---+---+---+---+---+");

	for (int riga = 7; riga >= 0; riga--) {
		printf("\n");
		for (int colonna = 0; colonna < 8; colonna++) {
			printf("| %c ", sc->caselle[colonna * 8 + riga]);
		}
		printf("|\n");
		printf("+---+---+---+---+---+---+---+---+");
	}
}

int main(void)
{
	struct scacchiera sc = {'R','P',' ',' ', ' ', ' ', 'p','r','N','P',' ',' ',' ',' ','p','n','B','P',' ',' ',' ',' ','p','b','Q','P',' ',' ',' ',' ','p','q','K','P',' ',' ',' ',' ','p','k','B','P',' ',' ',' ',' ','p','b','N','P',' ',' ',' ',' ','p','n','R','P',' ',' ',' ',' ','p','r' };
	stampa_scacchiera(&sc);
	return 0;
}