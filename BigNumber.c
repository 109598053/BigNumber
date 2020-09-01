#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
//	int size = 200;
	char *arr1;
	char *arr2;
	arr1 = malloc(sizeof(char));
	arr2 = malloc(sizeof(char));
	char ch1;
	char ch2;

	int i = 0;
	printf("Input1:");
	while((ch1 = getchar()) != '\n'){
		*(arr1+i++) = ch1;
	}
	printf("Input2:");
	i = 0;
	while((ch2 = getchar()) != '\n'){
		*(arr2+i++) = ch2;
	}
	
//	add();
//	int size = strlen(arr);
	for (i = 0; i < strlen(arr1); i++)
    {
        printf("%c", *(arr1 + i));
    }
        printf("\n");
	for (i = 0; i < strlen(arr2); i++)
    {
        printf("%c", *(arr2 + i));
    }
    
	free(arr1);
	free(arr2);
}
