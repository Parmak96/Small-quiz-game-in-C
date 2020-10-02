#include "functions.h"
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

FILE *fp, *ap, *bp, *cp, *dp, *sp;

void Ausgabe(int n) {
	char str[300], asr[100], bsr[100], csr[100], dsr[100];
	int i = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	fp = fopen("quiz.txt", "r");
	while (fgets(str, 300, fp) != NULL) {

		i++;
		if (i == n) {
			printf("\t%s", str);

		}
	}
	fclose(fp);

	ap = fopen("answerA.txt", "r");
	while (fgets(asr, 100, ap) != NULL) {
		a++;
		if (a == n) {
			printf("\t\t%s\n", asr);

		}
	}
	fclose(ap);

	bp = fopen("answerB.txt", "r");
	while (fgets(bsr, 100, bp) != NULL) {
		b++;
		if (b == n) {
			printf("\t\t%s\n", bsr);

		}
	}
	fclose(bp);

	cp = fopen("answerC.txt", "r");
	while (fgets(csr, 100, cp) != NULL) {
		c++;
		if (c == n) {
			printf("\t\t%s\n", csr);

		}
	}
	fclose(cp);

	dp = fopen("answerD.txt", "r");
	while (fgets(dsr, 100, dp) != NULL) {
		d++;
		if (d == n) {
			printf("\t\t%s\n", dsr);

		}
	}
	fclose(dp);
}



char solution(int n)
{
	int count = 0;
	char sol[100];
	char s;
	sp = fopen("solution.txt", "r");
	while (fgets(sol, 100, sp) != NULL) {
		count++;
		if (count == n) {
			s = sol[0];

		}
	}
	fclose(sp);

	return s;
}


int random()
{
	int random;
	srand(time(NULL));
	random = rand() % 10 + 1;
	return random;
}


void END(int money) {
	printf("\n\n\n\t    HERZLICHEN GLUECKWUNSCH, SIE HABEN %d EURO GEWONNEN!!! \n\n", money - 100000);
	printf("\t\t\t\t    ENDE\n\n\n \t\t\t\t  CREDITS:\n\n\t\t\t   Mihaylo Altiparmakov\n\n\t\t\t       Tuan Anh Ngo\n\n\t\t\t      Xuan Lam Nguyen\n\n");
	_getch();
}

void joker(char s, int n) {

	FILE *fp, *ap, *bp, *cp, *dp;
	char str[300], asr[100], bsr[100], csr[100], dsr[100];
	int i = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	fp = fopen("quiz.txt", "r");
	if (fp == NULL) {
		perror("Error opening file");
		return(-1);
	}
	while (fgets(str, 300, fp) != NULL) {

		i++;
		if (i == n) {
			printf("\t%s", str);

		}
	}
	fclose(fp);

	if (s == 'A' || s == 'C') {
		ap = fopen("answerA.txt", "r");
		if (ap == NULL) {
			perror("Error opening file");
			return(-1);
		}
		while (fgets(asr, 100, ap) != NULL) {
			a++;
			if (a == n) {
				printf("\t\t%s\n", asr);

			}
		}
		fclose(ap);

		cp = fopen("answerC.txt", "r");
		if (cp == NULL) {
			perror("Error opening file");
			return(-1);
		}
		while (fgets(csr, 100, cp) != NULL) {
			c++;
			if (c == n) {
				printf("\t\t%s\n", csr);

			}
		}
		fclose(cp);

	}

	if (s == 'B' || s == 'D') {

		bp = fopen("answerB.txt", "r");
		if (bp == NULL) {
			perror("Error opening file");
			return(-1);
		}
		while (fgets(bsr, 100, bp) != NULL) {
			b++;
			if (b == n) {
				printf("\t\t%s\n", bsr);

			}
		}
		fclose(bp);

		dp = fopen("answerD.txt", "r");
		if (dp == NULL) {
			perror("Error opening file");
			return(-1);
		}
		while (fgets(dsr, 100, dp) != NULL) {
			d++;
			if (d == n) {
				printf("\t\t%s\n", dsr);

			}
		}
		fclose(dp);

	}


}

void error_check() {
	//"quiz.txt" prüfen
	fp = fopen("quiz.txt", "r");
	if (fp == NULL) {
		perror("'quiz.txt' fehlt! Error");
		exit(0);
	}
	fclose(fp);
	//"answerA.txt" prüfen
	ap = fopen("answerA.txt", "r");
	if (ap == NULL) {
		perror("'answerA.txt' fehlt! Error");
		exit(0);
	}
	fclose(ap);
	//"answerB.txt" prüfen
	bp = fopen("answerB.txt", "r");
	if (bp == NULL) {
		perror("'answerB.txt' fehlt! Error");
		exit(0);
	}
	fclose(bp);
	//"answerC.txt" prüfen
	cp = fopen("answerC.txt", "r");
	if (cp == NULL) {
		perror("'answerC.txt' fehlt! Error");
		exit(0);
	}
	fclose(cp);
	//"answerD.txt" prüfen
	dp = fopen("answerD.txt", "r");
	if (dp == NULL) {
		perror("'answerD.txt' fehlt! Error");
		exit(0);
	}
	fclose(dp);
	//"solution.txt" prüfen
	sp = fopen("solution.txt", "r");
	if (sp == NULL) {
		perror("'solution.txt' fehlt! Error");
		exit(0);
	}
	fclose(sp);
}

void help(int money, int k, int n) {
	system("cls");
	printf("\n                       HILFE                                              ");
	printf("\n -------------------------------------------------------------------------");
	printf("\n >> In diesem Spiel werden Ihnen 10 Fragen gestellt. Jede richtige Antwort");
	printf("\n    bringt Ihnen 100.000 Euro!");
	printf("\n >> Fuer jede Frage gibt es 4 Antwortmoeglichkeiten: Ist es A, B, C, oder D?");
	printf("\n    Geben Sie Ihre Antwort ein und bestaetigen Sie mit ENTER.");
	printf("\n    Es wird nur das erste Zeichen gewertet!");
	printf("\n >> Sie haben EINEN 50:50-Joker:");
	printf("\n    Sie muessen nur noch zwischen 2 Moeglichkeiten waehlen.");
	printf("\n    Geben Sie dafuer 'J' ein.");
	printf("\n >> Ist Ihre Antwort richtig, kommen Sie zu der naechsten Frage.");
	printf("\n    Wenn nicht, endet das Spiel!\n");
	printf("\n\n    Druecken Sie eine beliebige Taste, um fortzufahren.");
	rewind(stdin);
	_getch();
	_getch();
	system("cls");
	printf("\n CASH: %d EURO      JOKER: %d  (Taste 'J')      HILFE (Taste 'H')\n\n", money - 100000, k);
	Ausgabe(n);
	rewind(stdin);
}

