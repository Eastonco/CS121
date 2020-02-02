/*****************************************************************
* Connor Easton                                                  *
* PA: 8                                                          *
* Date Created: April 22, 2018                                   *
* Date Modified: April 25, 2018                                  *
* Description: This project does some cool stuff i guess         *
*****************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


typedef struct occourrences {
	int num_occurrences;
	double frequency;
}Occurrences;

char* my_str_n_cat(char* ptrdest, char* ptrsource, int len);
int binary_search(int sorted_int, int target);
void bubble_sort(char * pointer_array[], int len);
bool is_palindrome(char* ptrString, int length, int index);
int sum_primes(unsigned int n);
void maximum_occurrences(char * ptrString, Occurrences * ptrAlphabet, int * ptrN, char * ptrCharacter);
char *removeSpaces(char *str); 
int check_prime(int n);
