#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "functions.h"


int main() {

	error_check();

	menu :
	system("cls");
	printf("\n\t\t\tC PROGRAMM QUIZ-SPIEL");
	printf("\n\t\t________________________________________");
	printf("\n\t\t\t    WILLKOMMEN BEI");
	printf("\n\t\t________________________________________");
	printf("\n\t\t________________________________________");
	printf("\n\t\t\t   EASY MILLIONAIRE");
	printf("\n\t\t________________________________________");
	printf("\n\t\t________________________________________");
	printf("\n\t\t> S druecken, um mit dem Spiel zu beginnen");
	printf("\n\t\t> Q druecken, um das Spiel zu beenden");
	printf("\n\t\t________________________________________\n\n");

		char input;
		char playername[30];
		input = toupper(getch());
		if (input == 'S') {
			system("cls");
			printf("\n Geben Sie Ihren Name ein und bestaetigen Sie mit ENTER: \n\n");
			fflush(stdin);
			gets(playername);
			printf("\n ------------------ Willkommen bei EASY MILLIONAIRE, %s! ---------------", playername);
			printf("\n\n Hier sind einige Tipps, die Sie vor dem Spielen wissen sollten:");
			printf("\n -------------------------------------------------------------------------");
			printf("\n >> In diesem Spiel werden Ihnen 10 Fragen gestellt. Jede richtige Antwort");
			printf("\n    bringt Ihnen 100.000 Euro!");
			printf("\n >> Fuer jede Frage gibt es 4 Antwortmoeglichkeiten: Ist es A, B, C, oder D?");
			printf("\n    Geben Sie Ihre Antwort ein und bestaetigen Sie mit ENTER.");
			printf("\n    Es wird nur das erste Zeichen gewertet!");
			printf("\n >> Sie haben EINEN 50:50-Joker:");
			printf("\n    Sie muessen nur noch zwischen 2 Moeglichkeiten waehlen.");
			printf("\n    Geben Sie dafuer 'J' ein.");
			printf("\n >> Wenn Sie Hilfe brauchen, geben Sie 'H' ein.");
			printf("\n >> Ist Ihre Antwort richtig, kommen Sie zu der naechsten Frage.");
			printf("\n    Wenn nicht, endet das Spiel!");
			printf("\n\n\n Druecken Sie eine beliebige Taste, um mit dem Spiel zu beginnen!\n");
			_getch();
			_getch();
			goto game;
		}
		//Spiel beenden
		else if (input == 'Q') exit(0);
		//bei allen andere Eingaben beim Startscreen bleiben
		else {
			system("cls");
			goto menu;
		}

		///Quiz beginnt
	game:
		system("cls");
		int n;
		char s;
		char Answer;
		int i;
		int money = 0;
		int k = 1;
		int jokercheck[2];
		//bereits gestellte Fragen in Array speichern, um Wiederholungen zu vermeiden
		int array[10];
		for (i = 1; i < 11; i++) {
			printf("\n CASH: %d EURO      JOKER: %d  (Taste 'J')      HILFE (Taste 'H')\n\n", money, k);
			money = money + 100000;

			///Sufe 1
				//zufällige Frage auswählen
			if (i < 4) {
				n = random();
				while (n == array[0] || n == array[1] || n == array[2]) n = random();
				array[i - 1] = n;
				Ausgabe(n);
				//Eingabe Stufe 1
			stage1:
				printf(" Antwort: ");	
				scanf("%c", &Answer);
				s = solution(n);
				//Hilfe aufrufen
				if (toupper(Answer) == 'H') {
					help(money, k, n);
					if (jokercheck[0] == i)
					{
						system("cls");
						printf("\n CASH: %d EURO      JOKER: %d  (Taste 'J')      HILFE (Taste 'H')\n\n", money - 100000, k);
						joker(s, n);
						goto stage1;
					}
					goto stage1;
				}
				//wenn Antwort richtig
				if (toupper(Answer) == s) {
					printf("\n RICHTIG! Beliebige Taste druecken zum Fortfahren.");
					rewind(stdin);
					_getch();
					_getch();
					system("cls");
				}
				else {
					//wenn Antwort falsch -> Spielende, zurück zum Startscreen
					if (toupper(Answer) == 'A' || toupper(Answer) == 'B' || toupper(Answer) == 'C' || toupper(Answer) == 'D') {
						printf("\n FALSCH! %c waere korrekt gewesen.\n", s);

						_getch();
						_getch();
						system("cls");
						END(money);
						_getch();
						_getch();
						goto menu;
					}
					else {
						//Joker aktivieren
						if (toupper(Answer) == 'J') {
							if (k > 0) {
								jokercheck[0] = i;
								getchar();
								k--;
								system("cls");
								rewind(stdin);
								printf("\n CASH: %d EURO      JOKER: %d  (Taste 'J')      HILFE (Taste 'H')\n\n", money - 100000, k);
								joker(s, n);
								goto stage1;
							}
							//Kein Joker mehr
							else {
								system("cls");
								if (jokercheck[0] == i)
								{
									system("cls");
									printf("\n CASH: %d EURO      JOKER: %d  (Taste 'J')      HILFE (Taste 'H')\n\n", money - 100000, k);
									joker(s, n);
								}
								else {
									printf("\n CASH: %d EURO      JOKER: %d  (Taste 'J')      HILFE (Taste 'H')\n\n", money - 100000, k);
									Ausgabe(n);
								}
								getchar();
								printf(" Sie haben keinen Joker mehr...\n\n");
								rewind(stdin);
								goto stage1;
							}
						}
						//Ungueltige Eingabe
						else {
							system("cls");
							if (jokercheck[0] == i)
							{
								system("cls");
								printf("\n CASH: %d EURO      JOKER: %d  (Taste 'J')      HILFE (Taste 'H')\n\n", money - 100000, k);
								joker(s, n);
							}
							else {
								printf("\n CASH: %d EURO      JOKER: %d  (Taste 'J')      HILFE (Taste 'H')\n\n", money - 100000, k);
								Ausgabe(n);
							}
							printf(" Ungueltige Eingabe! Versuchen Sie es nochmal.\n\n");
							rewind(stdin);
							goto stage1;
						}
					}
				}
			}

			///Stufe 2
					//Fragen werden schwerer
			if (i > 3 && i < 7) {
				n = random();
				while (n + 10 == array[3] || n + 10 == array[4] || n + 10 == array[5]) {
					n = random();
				}
				array[i - 1] = n + 10;
				Ausgabe(n + 10);
				//Eingabe
			stage2:
				printf(" Antwort: ");
				scanf("%c", &Answer);
				s = solution(n + 10);
				//Hilfe
				if (toupper(Answer) == 'H') {
					help(money, k, n + 10);
					if (jokercheck[0] == i)
					{
						system("cls");
						printf("\n CASH: %d EURO      JOKER: %d  (Taste 'J')      HILFE (Taste 'H')\n\n", money - 100000, k);
						joker(s, n + 10);
						goto stage2;
					}
					goto stage2;
				}
				//richtig
				if (toupper(Answer) == s) {
					printf("\n RICHTIG! Beliebige Taste druecken zum Fortfahren.");
					rewind(stdin);
					_getch();
					_getch();
					system("cls");
				}
				else {
					//falsch
					if (toupper(Answer) == 'A' || toupper(Answer) == 'B' || toupper(Answer) == 'C' || toupper(Answer) == 'D') {
						printf("\n FALSCH! %c waere korrekt gewesen.\n", s);
						_getch();
						_getch();
						system("cls");
						END(money);
						_getch();
						_getch();
						goto menu;
					}
					else {
						//Joker
						if (toupper(Answer) == 'J') {
							if (k > 0) {
								jokercheck[0] = i;
								getchar();
								k--;
								system("cls");
								rewind(stdin);
								printf("\n CASH: %d EURO      JOKER: %d  (Taste 'J')      HILFE (Taste 'H')\n\n", money - 100000, k);
								joker(s, n + 10);
								goto stage2;
							}
							//kein Joker
							else {
								system("cls");
								if (jokercheck[0] == i)
								{
									system("cls");
									printf("\n CASH: %d EURO      JOKER: %d  (Taste 'J')      HILFE (Taste 'H')\n\n", money - 100000, k);
									joker(s, n + 10);
								}
								else {
									printf("\n CASH: %d EURO      JOKER: %d  (Taste 'J')      HILFE (Taste 'H')\n\n", money - 100000, k);
									Ausgabe(n + 10);
								}
								getchar();
								printf(" Sie haben keinen Joker mehr...\n\n");
								rewind(stdin);
								goto stage2;
							}
						}
						//ungueltige Eingabe
						else {
							system("cls");
							if (jokercheck[0] == i)
							{
								system("cls");
								printf("\n CASH: %d EURO      JOKER: %d  (Taste 'J')      HILFE (Taste 'H')\n\n", money - 100000, k);
								joker(s, n + 10);
							}
							else {
								printf("\n CASH: %d EURO      JOKER: %d  (Taste 'J')      HILFE (Taste 'H')\n\n", money - 100000, k);
								Ausgabe(n + 10);
							}
							printf(" Ungueltige Eingabe! Versuchen Sie es nochmal.\n\n");
							rewind(stdin);
							goto stage2;
						}
					}
				}
			}

			///Stufe 3
					//Fragen werden noch schwerer
			if (i > 6) {
				n = random();
				while (n + 20 == array[6] || n + 20 == array[7] || n + 20 == array[8] || n + 20 == array[9]) {
					n = random();
				}
				array[i - 1] = n + 20;
				Ausgabe(n + 20);
				//Eingabe
			stage3:
				printf("Antwort: ");
				scanf("%c", &Answer);
				s = solution(n + 20);
				//Hilfe
				if (toupper(Answer) == 'H') {
					help(money, k, n + 20);
					if (jokercheck[0] == i)
					{
						system("cls");
						printf("\n CASH: %d EURO      JOKER: %d  (Taste 'J')      HILFE (Taste 'H')\n\n", money - 100000, k);
						joker(s, n + 20);
						goto stage3;
					}
					goto stage3;
				}
				//richtig
				if (toupper(Answer) == s) {
					printf("\n RICHTIG! Beliebige Taste druecken zum Fortfahren.");
					rewind(stdin);
					_getch();
					_getch();
					system("cls");
				}
				else {
					//falsch
					if (toupper(Answer) == 'A' || toupper(Answer) == 'B' || toupper(Answer) == 'C' || toupper(Answer) == 'D') {
						printf("\n FALSCH! %c waere korrekt gewesen.\n", s);
						_getch();
						_getch();
						system("cls");
						END(money);
						_getch();
						_getch();
						goto menu;
					}
					else {
						//Joker
						if (toupper(Answer) == 'J') {
							if (k > 0) {
								jokercheck[0] = i;
								getchar();
								k--;
								system("cls");
								rewind(stdin);
								printf("\n CASH: %d EURO      JOKER: %d  (Taste 'J')      HILFE (Taste 'H')\n\n", money - 100000, k);
								joker(s, n + 20);
								goto stage3;
							}
							//kein Joker
							else {
								system("cls");
								if (jokercheck[0] == i)
								{
									system("cls");
									printf("\n CASH: %d EURO      JOKER: %d  (Taste 'J')      HILFE (Taste 'H')\n\n", money - 100000, k);
									joker(s, n + 20);
								}
								else {
									printf("\n CASH: %d EURO      JOKER: %d  (Taste 'J')      HILFE (Taste 'H')\n\n", money - 100000, k);
									Ausgabe(n + 20);
								}
								getchar();
								printf(" Sie haben keinen Joker mehr...\n\n");
								rewind(stdin);
								goto stage3;
							}
						}
						//ungueltige Eingabe
						else {
							system("cls");
							if (jokercheck[0] == i)
							{
								system("cls");
								printf("\n CASH: %d EURO      JOKER: %d  (Taste 'J')      HILFE (Taste 'H')\n\n", money - 100000, k);
								joker(s, n + 20);
							}
							else {
								printf("\n CASH: %d EURO      JOKER: %d  (Taste 'J')      HILFE (Taste 'H')\n\n", money - 100000, k);
								Ausgabe(n + 20);
							}
							printf(" Ungueltige Eingabe! Versuchen Sie es nochmal.\n\n");
							rewind(stdin);
							goto stage3;
						}
					}
				}
			}
		}

		///Endscreen bei Sieg
		system("cls");
		printf("\n\n\n\t\tHERZLICHEN GLUECKWUNSCH, SIE SIND MILLIONAER!!!\n\n");
		printf("\t\t\t\t   ENDE\n\n\n \t\t\t\t CREDITS:\n\n\t\t\t  Mihaylo Altiparmakov\n\n\t\t\t      Tuan Anh Ngo\n\n\t\t\t     Xuan Lam Nguyen \n\n");
		_getch();
		_getch();
		//zurück zum Startscreen
		goto menu;
}


	