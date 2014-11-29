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
	"10111",
	"111010101",
	"11101011101",
	"1110101",
	"1",
	"101011101",
	"111011101",
	"1010101",
	"101",
	"1011101110111",
	"111010111",
	"101110101",
	"1110111",
	"11101",
	"11101110111",
	"10111011101",
	"1110111010111",
	"1011101",
	"10101",
	"111",
	"1010111",
	"101010111",
	"101110111",
	"11101010111",
	"1110101110111",
	"11101110101"
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
	int collisions = 0;
	int intarr_length = (int)(sizeof(intarr)/sizeof(intarr[0]));
	char* collision_nr;
	while(m < intarr_length) {
		while(n < intarr_length) {
			if(m == n) {
				n++;
			}
			else if(intarr[m] == intarr[n]) {
				collisions++;
				collision_nr[p] = intarr[m];
				p++;
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
	m = 0;

	printf("\ncollissions: %d\n", collisions);
	printf("Collision nr's:");
	for(int i=0;collision_nr[i]; i++) {
		printf("%d,", collision_nr[i]);
	}

	// Give max of intarr
	int max = max_array(intarr, intarr_length);
	printf("max: %d\n", max);



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