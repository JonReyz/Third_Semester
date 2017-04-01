#include <stdio.h>
#include <stdlib.h>



void transform(char** grid, int H, int W){
	int i, j, counter, counter2;
	char** grid2;

	grid2 = malloc(sizeof(char*)*H);

	for(i = 0; i < H; i++){
		grid2[i] = malloc(sizeof(char)*W);
		for(j = 0; j < W; j++){
			if(grid[i][j] == '*'){
				counter = 0;
				if(i != 0 && grid[i -1][j] == '#'){
					counter++;
				}
				if(i < (H -1) && grid[i + 1][j] == '#'){
					counter++;
				}
				if(j != 0 && grid[i][j - 1] == '#'){
					counter++;
				}
				if(j < (W -1) && grid[i][j + 1] == '#'){
					counter++;
				}
				if(counter < 2 || counter > 3){
					grid2[i][j] = '.';
				}
				else grid2[i][j] = '*';	
			}
			if(grid[i][j] == '#'){
				counter = 0;
				if(i != 0 && grid[i -1][j] == '*'){
					counter++;
				}
				if(i < (H -1) && grid[i + 1][j] == '*'){
					counter++;
				}
				if(j != 0 && grid[i][j - 1] == '*'){
					counter++;
				}
				if(j < (W -1) && grid[i][j + 1] == '*'){
					counter++;
				}
				if(counter < 2 || counter > 3){
					grid2[i][j] = '.';
				}
				else grid2[i][j] = '#';	
			}
			if(grid[i][j] == '.'){
				counter = 0;
				counter2 = 0;
				if(i != 0){
					if(grid[i - 1][j] == '*')
						counter++;
					else if(grid[i - 1][j] == '#'){
						counter2++;
					}
				}
				if(j != 0){
					if(grid[i][j - 1] == '*')
						counter++;
					else if(grid[i][j - 1] == '#'){
						counter2++;
					}
				}
				if(i < (H - 1)){
					if(grid[i+ 1][j] == '*'){
						counter ++;
					}
					else if(grid[i+1][j] == '#'){
						counter2++;
					}
				}
				if(j < (W - 1)){
					if(grid[i][j + 1] == '*'){
						counter ++;
					}
					else if(grid[i][j + 1] == '#'){
						counter2++;
					}
				}
				if(counter == 1 && counter2 == 2){
					grid2[i][j] = '*';
				}
				else if(counter == 2 && counter2 == 1){
					grid2[i][j] = '#';
				}
				else{
					grid2[i][j] = '.';
				}
			}

		}
	}
	for(i = 0; i < H; i++){
		for(j = 0; j < W; j++){
			grid[i][j] = grid2[i][j];
		}
	}
	for(i = 0; i < H; i++){
		free(grid2[i]);
	}
	free(grid2);
}

int main (){
	int  H, W, T, i, j;
	char c;
	scanf("%d%d%d", &H, &W, &T);
	
	char** grid;
	grid = malloc(sizeof(char*)*H);

	for(i = 0; i < H; i++){
		grid[i]  = malloc(sizeof(char)*W);
		for(j = 0; j < W; j++){
			do{
				c = fgetc(stdin);
			}while(c != '*' && c != '#' && c != '.');
			grid[i][j] = c;
		}
	}

	for(i = 0; i < T; i++){
		transform(grid, H, W);
	}

	for(i = 0; i < H; i++){
		for(j = 0 ; j < W; j++){
			printf("%c", grid[i][j]);
		}
		printf("\n");
	}
	return 0;
}