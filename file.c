#include <stdio.h>
#include <stdlib.h>
typedef struct PLAYER{
	char name[20];
	int score;
	struct PLAYER *next;
};
struct PLAYER player;
struct PLAYER players[10];
int readfile(){
	FILE *steam;
	steam = fopen("blackjack.txt", "r");
	int i = 0;
	while (!feof(steam) && i<10){
		fscanf(steam, "%s", players[i].name);
		fscanf(steam, "%d", &players[i++].score);
	}
	return --i;
	fclose(steam);
}
void writefile(int playernum){
	FILE *steam;
	steam = fopen("blackjack.txt", "w");
	int i = 0;
	while (i<10 && i<playernum){
		fprintf(steam, "%s ", players[i].name);
		fprintf(steam, "%d\n", players[i++].score);
	}
	fclose(steam);
}
void sorting(int playernum){
	int i, j;
	struct PLAYER temp;
	for (j = 0; j<playernum + 1; j++)
	for (i = 0; i<playernum - j; i++)
	if (players[i].score<players[i + 1].score){
		temp = players[i];
		players[i] = players[i + 1];
		players[i + 1] = temp;
	}
}
