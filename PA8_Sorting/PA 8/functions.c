#include "Header.h"

char* my_str_n_cat(char * ptrdest, char * ptrsource, int len)
{
	for (int i = 0; i < len; i++) { //loops through the string len and sets the pointer dest to the source;
		*(ptrdest + i+1) = *(ptrsource + i);
	}

	return ptrdest;
}


int binary_search(int sorted_int[], int target, int len)
{
	int left = 0;
	int right = len;
	bool found = false;
	int target_index = -1;
	int mid = 0;

	while (found == false && left <= right) { //loops through and cuts seach area in half each time
		mid = ((right + left )/ 2);
		if (target == sorted_int[mid]) {
			target_index = mid;
			found = true;
		}
		if (target < sorted_int[mid]) {
			right = mid - 1;
		}
		if (target > sorted_int[mid]) {
			left = mid + 1;
		}
	}


	
	
	return target_index;
}

void bubble_sort(char * pointer_array[], int num_strings)
{
	int index_U = (num_strings - 1), index_C = 0;
	char * tmp = 0;;
	while (index_U > 1) { //sorts the list with strcmp to sort strings accoridng to size
		index_C= 1;
		while(index_C < index_U){
			if (strcmp(pointer_array[index_C], pointer_array[index_C + 1]) > 0) {
				tmp = pointer_array[index_C];
				pointer_array[index_C] = pointer_array[index_C + 1];
				pointer_array[index_C + 1] = tmp;
			}
			index_C++;
		}
		index_U--;
	}
	return;
}



bool is_palindrome(char* ptrString, int length, int index)
{
	if (index >= length) { //base case 
		printf("%s is a palindrome\n", ptrString);
		return true;
	}
	if (ptrString[length-1] != ptrString[index]) { //tests if string[i] == string[i+length] to compare begining and end and move in
		printf("%s is not a palindrome\n", ptrString);
		return false;
	}
	return is_palindrome(ptrString, --length, ++index); //recursion 
}


char *removeSpaces(char *str) //Used function from https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/
{
	int i = 0, j = 0;
	while (str[i]) //loops until end of string
	{
		if (str[i] != ' ') //tests for whitespace 
			str[j++] = str[i]; //if found, copies the next character to overwrite the whitepsace
		i++;
	}
	str[j] = '\0';
	return str;
}


void maximum_occurrences(char * ptrString, Occurrences * ptrAlphabet, int * ptrN, char * ptrCharacter)
{
	int length = strlen(ptrString); //gets length
	char letter = "\0"; //initialzes variables
	int max_char_index = -1;
	int max_count = 0;



	for (int i = 0; i < length; i++) { //loops through string and sets all letters to l
		letter = tolower(ptrString[i]); 
		if (letter != ' ') { //tests for spaces
			letter -= 'a'; //subtracts ascii vales of a to get index values from 0-25
			ptrAlphabet[(int)letter].num_occurrences++; //adds to num_occurrences for corresponding letter 
		}
	}
	for (int i = 0; i < 26; i++) {
		ptrAlphabet[i].frequency = (ptrAlphabet[i].num_occurrences / length); //calculates frquencey of each letter
		if (ptrAlphabet[i].num_occurrences > max_count) {
			max_count = ptrAlphabet[i].num_occurrences; //find the max count of number
			max_char_index = i;
		}
	}

	*ptrN = max_count; //returns max count and max letter thoguh pointers
	*ptrCharacter = (char)max_char_index + (int)'a';
	return;
}



int sum_primes(unsigned int n)
{
	int total = 0;
	int i = n;
	if (n == 2) { //if n == 2; sets total to 2
		return 2;
	}
	while (i-1 >= 2)
	{
		total = check_prime(n) + sum_primes(n - 1); //loops thorugh checking if each number is prime and adding it to the total w/ recurssion
		i--; //subtracts index
	}

	return total; //returns total 
}



int check_prime(int n) { //tests if a number is prime
	int i = n - 1;
	int remainder = -1;
	while (remainder != 0 && i > 1) { //while the reaminder isn't 0 and i> 1
		remainder = n % i; //gets remainder of n/ every number between 2 and n-1 and loops
		i--;
	}
	if (i == 1) //if it made it through the loop, n is a prime
		return n;
	if (i != 1) //if not, n is not a prime and returns 0
		return 0;
}
