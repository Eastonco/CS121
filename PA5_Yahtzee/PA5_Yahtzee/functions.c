#include "Header.h"

int printMenu(void) { // runs through the menu. Loops for invalid user input
	int num = 0, usr_attempt = 0;
	do {
		usr_attempt++;
		if (usr_attempt > 1) {
			system("cls");
			printf("Invalid user input, please submit a valid choice\n\n"); //prompts user input is invalid if 2 try 
		}
		puts("1. Print game rules");
		puts("2. Start a game of Yahtzee");
		puts("3. Exit");
		printf("\nChoice: ");
		scanf("%d", &num);
		system("cls");
		if (num == 1) {
			printRules();
			usr_attempt--;
			system("Pause");
			system("cls");
		}
	} while (num != 2 && num != 3);
	return num;
}

void printRules(void) { //prints Rules
	printf("The Rules of Yahtzee\n\nThe scorecard used for Yahtzee is composed of two sections. A upper section and a lower section. A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections. The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box. If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12. Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds. If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus. The lower section contains a number of poker like combinations. See the table provided below:");
	printf("\n\n\tName\t\t\tCombination\t\t\tScore");
	printf("\nThree-of-a-kind  || Three dice with the same face  ||  Sum of all face valuse on 5 dice");
	printf("\nFour-of-a-kind   || Four dice with teh same face   ||  Sum of all face values on 5 dice");
	printf("\nFull House       || One pair and three-of-a-kind   ||  25 points");
	printf("\nSmall Straight   || A sequence of four dice        ||  30 points");
	printf("\nLarge Straight   || A sequence of five dice        ||  40 points");
	printf("\nYahtzee          || Five dice with the same face   ||  50 points");
	printf("\nChance           || May be used for any sequence   ||  Sum of all face values on 5 dice\n\n");
}

int rollDie(void) { // Rolls a die
	int num = 0;
	num = rand() % 6 + 1;

	return num;
}

bool isValidNum(int num) {
	bool isValidNum = false;
	if (num >= 1 && num <= 6) {
		isValidNum = true;
	}
	return isValidNum;
}

int S1_point(int round[]) {
	int i, points = 0;
	for (i = 0; i < 5; i++) {
		if (round[i] == 1) {
			points++;
		}
	}
	return points;
}

int S2_point(int round[]) {
	int i, points = 0;
	for (i = 0; i < 5; i++) {
		if (round[i] == 2) {
			points += 2;
		}
	}
	return points;
}

int S3_point(int round[]) {
	int i, points = 0;
	for (i = 0; i < 5; i++) {
		if (round[i] == 3) {
			points += 3;
		}
	}
	return points;
}

int S4_point(int round[]) {
	int i, points = 0;
	for (i = 0; i < 5; i++) {
		if (round[i] == 4) {
			points += 4;
		}
	}
	return points;
}

int S5_point(int round[]) {
	int i, points = 0;
	for (i = 0; i < 5; i++) {
		if (round[i] == 5) {
			points += 5;
		}
	}
	return points;
}

int S6_point(int round[]) {
	int i, points = 0;
	for (i = 0; i < 5; i++) {
		if (round[i] == 6) {
			points += 6;
		}
	}
	return points;
}

int threeOfAKind(int round[]) {
	int i, points = 0, s1c = 0, s2c = 0, s3c = 0, s4c = 0, s5c = 0, s6c = 0;
	for (i = 0; i < 5; i++) {
		if (round[i] == 1)
			s1c++;
		if (round[i] == 2)
			s2c++;
		if (round[i] == 3)
			s3c++;
		if (round[i] == 4)
			s4c++;
		if (round[i] == 5)
			s5c++;
		if (round[i] == 6)
			s6c++;
		}
	if (s1c >= 3 || s2c >= 3 || s3c >= 3 || s4c >= 3 || s5c >= 3 || s6c >= 3) {
		for (i = 0; i < 5; i++) {
			points += (int)round[i];
		}
	}
	return points;
}


int fourOfAKind(int round[]) {
	int i, points = 0, s1c = 0, s2c = 0, s3c = 0, s4c = 0, s5c = 0, s6c = 0;
	for (i = 0; i < 5; i++) {
		if (round[i] == 1)
			s1c++;
		if (round[i] == 2)
			s2c++;
		if (round[i] == 3)
			s3c++;
		if (round[i] == 4)
			s4c++;
		if (round[i] == 5)
			s5c++;
		if (round[i] == 6)
			s6c++;
	}
	if (s1c >= 4 || s2c >= 4 || s3c >= 4 || s4c >= 4 || s5c >= 4 || s6c >= 4) {
		for (i = 0; 1 < 5; i++) {
			points += (int)round[i];
		}
	}
	return points;
}

void ComboChoicePrint(void) {
	printf("1. Sum of 1's\t\t7. Three-of-a-kind\n");
	printf("2. Sum of 2's\t\t8. Four-of-a-kind\n");
	printf("3. Sum of 3's\t\t9. Full house\n");
	printf("4. Sum of 4's\t\t10. Small straight\n");
	printf("5. Sum of 5's\t\t11. Large straight\n");
	printf("6. Sum of 6's\t\t12. Yahtzee\n");
	printf("\t\t13. Chance\n\n");
}


int ComboChoice(int comboChoice, int *list[], int saved) {
	int points = 0;
	switch (comboChoice) {
	case 1:
		if (choicevalid(1, &list) == true) {
			points = S1_point(saved);
			return points;
		}
		else
	case 2:
		if (choicevalid(2, &list) == true) {
			points = S2_point(saved);
			return points;
		}
	case 3:
		if (choicevalid(3, &list) == true) {
			points = S3_point(saved);
			return points;
		}
	case 4:
		if (choicevalid(4, &list) == true) {
			points = S4_point(saved);
			return points;
		}
	case 5:
		if (choicevalid(5, &list) == true) {
			points = S5_point(saved);
			return points;
		}
	case 6:
		if (choicevalid(6, &list) == true) {
			points = S6_point(saved);
			return points;
		}
	case 7:
		if (choicevalid(7, &list) == true) {
			points = threeOfAKind(saved);
			return points;
		}
	case 8:
		if (choicevalid(8, &list) == true) {
			points = fourOfAKind(saved);
			return points;
		}
	case 9:
		if (choicevalid(9, &list) == true) {
			points = Fullhouse(&saved);
			return points;
		}
	case 10:
		if (choicevalid(10, &list) == true) {
			points = smallStraight(&saved);
			return points;
		}
	case 11:
		if (choicevalid(11, &list) == true) {
			points = LargeStraight(&saved);
			return points;
		}
	case 12:
		if (choicevalid(12, &list) == true) {
			points = Yahtzee(saved);
			return points;
		}
	case 13:
		if (choicevalid(13, &list) == true) {
			points = Chance(saved);
			return points;
		}
	}
}



int smallStraight(int *saved[]) {
	for (int i = 0; i < 5; i++) {
		for (int n = 0; n < 5; n++) {
			if (saved[n] < saved[i]) {
				int temp = saved[i];
				saved[i] = saved[n];
				saved[n] = temp;
			}
		}
	}
	int tempcount = 0, points = 0;
	for (int i = 0; i < 4; i++) {
		if (saved[i] == saved[i + 1] + 1)
			tempcount++;
		if (tempcount >= 4) {
			points = 30;
		}
	}
	return points;
}

int LargeStraight(int *saved[]) {
	for (int i = 0; i < 5; i++) {
		for (int n = 0; n < 5; n++) {
			if (saved[n] < saved[i]) {
				int temp = saved[i];
				saved[i] = saved[n];
				saved[n] = temp;
			}
		}
	}
	int tempcount = 0, points = 0;
	for (int i = 0; i < 4; i++) {
		if (saved[i] == saved[i + 1] + 1)
			tempcount++;
		if (tempcount >= 5) {
			points = 40;
		}
	}
	return points;
}

int Chance(int saved[]) {
	int points = 0;
	for (int i = 0; i < 5; i++) {
		points += saved[i];
	}
	return points; 
}

int Yahtzee(int saved[]) {
	int tempcount = 0, points = 0;
	for (int i = 0; i < 4; i++) {
		if (saved[i] == saved[i + 1])
			tempcount++;
	}
	if (tempcount >= 4)
		points = 50;
	return points;
}

int Fullhouse(int *saved[]) {
	int tempValue = 0, points = 0;
	int fullHouse3 = 0, fullHouse2 = 0;
	for (int i = 0; i < 5; i++) {
		for (int n = 0; n < 5; n++) {
			if (saved[n] < saved[i]) {
				int temp = saved[i];
				saved[i] = saved[n];
				saved[n] = temp;
			}
		}
	}

	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 5; i++) {
			if (saved[j] == saved[i]) {
				tempValue++;
			}
		}
		if (tempValue == 3) {
			fullHouse3 = 1;
		}
		else if (tempValue == 2) {
			fullHouse2 = 1;
		}
	}
	if (fullHouse2 && fullHouse3) {
		points = 25;
	}
	return points;
}


bool choicevalid(int num, int *list[]){ 
	int i, cleanNum = 0;
	bool isvalid = true;
	for (i = 0; i < 13; i++) {
		if (list[i] == num) {
			isvalid = false;
			break;
		}
		if (list[i] == 0) {
			cleanNum = i;
		}
	}
	list[cleanNum] = num;
	return isvalid;
}