#include <stdio.h>


int max_array(int intarr[], int intarr_length);
int hashme(char* morse);

int hashme(char* morse) {
	int total = 0;
	
	// This is the algorithm!!
	for(int i=0; morse[i]; i++) {
		total += ((morse[i] - '0') * (i+2));
	}
	return total;
}

int main() {

	char* arr[27] = {
	"10111",		//a
	"111010101",	//b
	"11101011101",	//c
	"1110101",		//d
	"1",			//e
	"101011101",	//f
	"111011101",	//g
	"1010101",		//h
	"101",			//i
	"1011101110111",//j
	"111010111",	//k
	"101110101",	//l
	"1110111",		//m
	"11101",		//n
	"11101110111",	//o
	"10111011101",	//p
	"1110111010111",//q
	"1011101",		//r
	"10101",		//s
	"111",			//t
	"1010111",		//u
	"101010111",	//v
	"101110111",	//w
	"11101010111",	//x
	"1110101110111",//y
	"11101110101"	//z
	};



	// convert zero's and one's to an index (hashing)
	int intarr[27];// = NULL;
	int i = 0;
	while(i < 26) {
		intarr[i] = hashme(arr[i]);
		i++;
	}

	//check for duplicates
	int m = 0;
	int n = 0;
	int p = 0;
	int q = 0;
	int collisions = 0;
	int intarr_length = (int)(sizeof(intarr)/sizeof(intarr[0]));
	int collision_nr[10];
	int collision_char_nr[10];
	while(m < intarr_length) {
		while(n < intarr_length) {
			if(m == n) {
				n++;
			}
			else if(intarr[m] == intarr[n]) {
				collisions++;
				collision_nr[p++] = intarr[m];
				collision_char_nr[q++] = m;
				collision_char_nr[q++] = n;
				n++;
			}
			else {
				n++;
			}
		}
		n = 0;
		m++;
	}
	collision_nr[p] = '\0';
	collision_char_nr[q] = '\0';
	m = 0;

	printf("\ncollissions: %d", collisions);
	printf("\nCollision nr's:");
	for(int i=0;collision_nr[i]; i++) {
		printf("%d,", collision_nr[i]);
	}
	printf("\ncollision char nr's: ");
	for(int i=0;collision_nr[i]; i++) {
		printf("%c,", collision_char_nr[i]+97);
	}
	
	// Give max of intarr
	int max = max_array(intarr, intarr_length);
	printf("\nmax: %d\n", max);



	// printf("size array: %d\n", (sizeof(intarr)/sizeof(intarr[0])) );

	// for(int i=0; *arr[i]; i++) {
	// 	// int i = 1;
	// 	//int total = 0;
	// 	printf("%s\n", arr[i]);
	// 	// for(; *arr; arr++) {
	// 	// 	total += (*a - '0')*i;
	// 	// 	i++;
	// 		//printf("%d\n", *a - '0');
	// 	}
		//printf("%d\n", total);
	

}


int max_array(int* intarr, int intarr_length) {
	int i, max=-32000;
	for(i=0; i<intarr_length; i++) {
		if(intarr[i]>max) {
			max=intarr[i];
		}
	}
	return max;
}