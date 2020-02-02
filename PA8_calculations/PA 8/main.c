#include "Header.h"
int main(void) {
	//Task 1 ************************************************************************************
	
	char source[100] = {"\0"};
	char dest[100] = { "\0" }; //creates arrays with null characters
	int len = 100;

	printf("Enter a string to copy: ");
	getchar(); //gets input from the user and clears any garbage values
	gets(source);

	printf("Dest address: %d\n", &dest); //prints destiniton address

	int ptr_dest = my_str_n_cat(&dest, &source, len); //coppies the string from source to dest

	printf("Ptr_dest: %d\n", ptr_dest);
	printf("Source: %s\n", source); //prints pointer address to address, source string and copied dest string
	printf("Dest: %s\n", dest);

	system("pause"); //pause and clear screen
	system("cls");
	//Task 2 ************************************************************************************
	int a_sorted_list[20] = { 23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42 }; // array of sorted numbers
	int target_num = -1;
	int target_index = 0;
	printf("Target number (23-42): "); //gets target number from user;
	scanf("%d", &target_num);
	puts("");

	target_index = binary_search(a_sorted_list, target_num, 20); //searches for the number 

	printf("Target num: %d\n", target_num);
	printf("Target index: %d\n", target_index); //prints the target num, index, and the sorted list number at the index
	printf("sortedlist[%d] = %d\n", target_index, a_sorted_list[target_index]);

	system("pause"); //pause and clear screen
	system("cls");
	//Task 3 ************************************************************************************
	char str1[] = "Cats";
	char str2[] = "Antelope";
	char str3[] = "Giraffee"; //a bunch of strings
	char str4[] = "Wild Zebra";
	char str5[] = "Tiger";
	char str6[] = "A magical unicorn";


	char * strings[6] = { str1, str2, str3, str4, str5, str6 }; //makes an array of strings 

	printf("%s\n", strings[0]);
	printf("%s\n", strings[1]);
	printf("%s\n", strings[2]); //prints all the strings in order 
	printf("%s\n", strings[3]);
	printf("%s\n", strings[4]);
	printf("%s\n\n", strings[5]);

	bubble_sort(strings, 6); //sorts the strings 

	printf("%s\n", strings[0]);
	printf("%s\n", strings[1]);
	printf("%s\n", strings[2]); //prints strings again but in sorted order
	printf("%s\n", strings[3]);
	printf("%s\n", strings[4]);
	printf("%s\n\n", strings[5]);


	system("pause"); //pause and clear screen
	system("cls");
	//Task 4 ************************************************************************************
	char palidrome[100] = "\0"; //character array for the palindrome 

	printf("Enter a word or phrase to test for palidrome: ");
	getchar(); //gets input from user
	gets(palidrome);

	removeSpaces(palidrome); //remvoes the whitespace from the palindrome 

	is_palindrome(&palidrome, 7, 0); //tests for palindrome and prints true or false

	system("pause"); //pause and clears screen
	system("cls");
	//Task 5 ************************************************************************************
	
	int input = 0;

	printf("Enter a number you would like to find the sum of prime numbers between 2 and n: ");
	scanf("%d", &input); //gets input form user 
	puts("");

	int total = sum_primes(input); //sums the primes
	printf("%d\n", total); //prints total 

	system("pause"); //pasue and clears screen
	system("cls");
	//Task 6 ************************************************************************************
	char string_count[100] = "\0"; //initialzies variables
	char letter = "\0";
	int count = 0;
	Occurrences alphabet[26] = { { 0,0 } };


	printf("Enter sentence: "); //gets input from user
	getchar();
	gets(string_count);
	printf("Sentence to analyze: %s\n\n", string_count); //prints string to analyze

	maximum_occurrences(&string_count, &alphabet, &count, &letter); //analyzes the string and outputs with pointers 

	printf("Most common letter: %c\n", letter); //prints most common letter and count of that letter from a-z
	printf("Num occurrences: %d\n", count);
}
