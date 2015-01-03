#include <stdio.h>
#include <stdlib.h>
#include "blackjack.h"
#include "file.h"
typedef struct PLAYER{
	char name[20];
	int score;
	struct PLAYER *next;
};
struct PLAYER player;
struct PLAYER players[10];
//struct PLAYER *head = NULL;   
int main(){
	char again;
	int playernum = readfile();
	int i = 0;
	printf("rank\t name\tscore\n");
	while (i < 10 && i < playernum){
		printf("%d \t%s\t%d\n", i+1, players[i].name, players[i].score);
		i++;
	}
	printf("\n\n");
	printf("Please input your name: ");
	scanf("%s", players[playernum].name);
	do{

		play(playernum);
		printf("\nAnd now would you like to play again? Input 'y' or 'n':\n");
		do{
			again = getchar();
		} while (again != 'y' && again != 'n');
	} while (again != 'n');
	printf("\n%s has won %d times.", players[playernum].name, players[playernum].score);
	sorting(playernum);
	writefile(++playernum);
	return 0;
}
