#include <stdio.h>
#include <string.h>

/*
 * UCI PROTOCAL
 * STDIN	STDOUT
 * -uci		uciok
 * -isready	readyok
 * -ucinewgame  <make new game>
 * -position    <setup position>
 * -go		<start calculating>
 *
 * Return best move whenever after go 
 * 		OR
 * -stop	bestmove <move>
 *
 * -quit	<shutdown engine>
 *
*/

/*
 * Decodes passed uci command and returns integer
*/
int check_command(char command[]){
	int x = -1;
	if(strcmp(command,"uci")) x = 1;
	if(strcmp(command,"isready")) x = 2;
	if(strcmp(command,"ucinewgame")) x = 3;
	if(strcmp(command,"position")) x = 4;
	if(strcmp(command,"go")) x = 5;
	if(strcmp(command,"stop")) x = 6;
	if(strcmp(command,"quit")) x = 7;
	return x;
}

int run_command(int type, char* token){
	switch (type) {
		case 1:
			printf("uciok\n");
			break;
		case 2:
			printf("readyok\n");
			break;
		case 3:
			//make new game
			break;
		case 4:
			//setup given position
			break;
		case 5:
			//start calculating
			break;
		case 6:
			//return whatever bestmove you got
			break;
		case 7:
			//shutdown engine
			return -1;
			break;
		default:
			break;
	}	
	return 0;
}

/*
 *
 * Main Engine UCI Loop
 *
*/
int main(){
	while(1){
		char command[1028];
		scanf("%s", command);		
		char* token = strtok(command, " ");
		int type = check_command(token);
		int code = run_command(type, token);
		if(code == -1) break;
	}
	return 0;
}
