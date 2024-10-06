
#include <stdio.h>
 
int main() {
	printf("\n");
	int score;
	// The next couple of lines of code is to get the score from the user until it gets a value less than two

	while (1) {
		// Responsible for getting score from user
		printf("Enter a score(0 or 1 to stop): ");
		scanf("%d", &score);
	
		// Checks if the score is less than two
		if (score == 1 || score == 0) {
			printf("Terminating program. \n:");
			break;
		}
		// Intializes the value of each action and their score value
		int TD = 6;
		int FieldGoal = 3;
		int Safety = 2;
		int TD2 = 8;
		int TD1 = 7;
		
		// Intializes variables to store possible amounts of actions
		int td, fg, saf, td2pc, td1fg;

		printf("\n");
		printf("Possible combinations to reach the score of %d:\n", score);
		printf("\n");

		// For loops responsible for calculating possible combinations
		for (int td = 0; td <= score / TD; td++) {
			for (int fg = 0; fg <= score / FieldGoal; fg++) {
				for (int saf = 0; saf <= score / Safety; saf++) {
					for (int td2 = 0; td2 <= score / TD2; td2++) {
						for (int td1 = 0; td1 <= score / TD1; td1++) {

							// Checks for valid combinations and prints them
							int score2 = (td * TD) + (fg * FieldGoal) + (saf * Safety) + (td2 * TD2) + (td1 * TD1);
							if (score2 == score) {
						       	printf("TD: %d, FG: %d, SAF: %d, TD+2PC: %d, TD+1FG: %d\n", td, fg, saf, td2, td1);
							}
						}
					}	
				}
			}	
		}
	}
		return 0;}
