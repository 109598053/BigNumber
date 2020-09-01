#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 1000
void isPositive(char *arr1, char *arr2, char ope);
void add(char *arr1, char *arr2, int positive);
void sub(char *arr1, char *arr2, int positive);
void mult(char *arr1, char *arr2, int positive);
void show(int *ans, int len, int positive);
int positive1, positive2;

void main(){
	char *arr1 = malloc(sizeof(char));
	char *arr2 = malloc(sizeof(char));
	char ope;
	int i, *arr = malloc(sizeof(int));
	
	printf("Input1:");
    scanf("%s", arr1);
	printf("Input2:");
    scanf("%s", arr2);
    fflush(stdin);
	printf("請輸入運算子:");
    ope = getchar();
	
	isPositive(arr1, arr2, ope);
	
	int len1 = strlen(arr1), len2 = strlen(arr2), bigger = 1;
	if(len1 < len2){
		bigger = 2;  //arr順序交換 
	}
	else if(len1 == len2){
		for(i = 0; i < len1; i++){
			if(arr1[i] < arr2[i]){
				bigger = 2;  //arr順序交換 
				break;
			}			
		}
	}
	
	switch(ope){
		case '+':
			if(positive1*positive2 == 1){//+++ -+-
				add(arr1, arr2, positive1);
			}
			else{
				if(bigger == 1){
					sub(arr1, arr2, positive1);
				}
				else if(bigger == 2){
					sub(arr2, arr1, positive2);
				}
			}
			break;
		case '-':
			if(positive1*positive2 == 1){//+-+ ---
				if(bigger == 1){
					sub(arr1, arr2, positive1);
				}
				else if(bigger == 2){
					sub(arr2, arr1, 0 - positive1);
				}
			}
			else{//+-- --+
				add(arr1, arr2, positive1);
			}
			break;
		case '*':
			mult(arr1, arr2, positive1 * positive2);
			break;
	}

    printf("\n----------------\n");
	for (i = 0; i < strlen(arr1); i++)
    {
        printf("%c", *(arr1 + i));
    }
        printf("\n");
	for (i = 0; i < strlen(arr2); i++)
    {
        printf("%c", *(arr2 + i));
    }
	printf("\noperator:%c\n", ope);
    
    
	free(arr1);
	free(arr2);
}

void add(char *arr1, char *arr2, int positive)
{
	int *ans = calloc( MAX,  sizeof(int));
	int len, len1 = strlen(arr1), len2 = strlen(arr2), i=0, j = len1 - 1, k = len2 - 1;
	while(j >= 0 && k >= 0){
		ans[i++]=(arr1[j--] - '0') + (arr2[k--] - '0');
	}
	while(j >= 0){
		ans[i++] = arr1[j--] - '0';
	}
	while(k >= 0){
		ans[i++] = arr2[k--] - '0';
	}
	
	if(len1 > len2){
		len = len1+1;
	}
	else{
		len = len2+1;
	}
	
	for(i = 0; i < len; i++){
		if(ans[i]>=10) {
			ans[i+1]+=ans[i]/10;
			ans[i]=ans[i]%10;
		}
	}
	show(ans, len, positive);
	free(ans);
}
void sub(char *arr1, char *arr2, int positive)
{
	int *ans = calloc( MAX,  sizeof(int));
	int len, len1 = strlen(arr1), len2 = strlen(arr2), i=0, j = len1 - 1, k = len2 - 1;
	while(j >= 0 && k >= 0){
		ans[i++]=(arr1[j--] - '0') - (arr2[k--] - '0');
	}
	while(j >= 0){
		ans[i++] = arr1[j--] - '0';
	}
	while(k >= 0){
		ans[i++] = arr2[k--] - '0';
	}
	
	if(len1 > len2){
		len = len1;
	}
	else{
		len = len2;
	}
//	for(i = 0; i < len; i++){
//		printf("_%d", ans[i]);
//	}
	for(i = 0; i < len; i++){
//		int j;
//			printf("\n--------------------\n");
//		for(j = 0; j < len; j++){
//			printf("_%d", ans[j]);
//		}
		if(ans[i]<0 && ans[i+1]){
			ans[i+1] -= 1;
			ans[i] = 10 + ans[i];
		}
	}
	show(ans, len, positive);
	free(ans);	
}
void isPositive(char *arr1, char *arr2, char ope)
{
	int i;//, len1 = strlen(arr1), len2 = strlen(arr2);
	positive1 = 1, positive2 = 1;
	if(arr1[0] == '-'){
		positive1 = -1;
		for (i = 0; i < strlen(arr1); i++)
	    {
	        *(arr1 + i) = *(arr1 + i + 1);
	    }
	}
	if(arr2[0] == '-'){
		positive2 = -1;
		for (i = 0; i < strlen(arr2); i++)
	    {
	        *(arr2 + i) = *(arr2 + i + 1);
	    }
	}
}
void mult(char *arr1, char *arr2, int positive)
{
	int *ans = calloc( MAX,  sizeof(int));
	int len, len1 = strlen(arr1), len2 = strlen(arr2), i=0, j = len1 - 1, k = len2 - 1;
	//todo
//	while(j >= 0 && k >= 0){
//		ans[i++]=(arr1[j--] - '0') * (arr2[k--] - '0');
//	}
//	while(j >= 0){
//		ans[i++] = arr1[j--] - '0';
//	}
//	while(k >= 0){
//		ans[i++] = arr2[k--] - '0';
//	}
	
	if(len1 > len2){
		len = len1*2;
	}
	else{
		len = len2*2;
	}
	
	for(i = 0; i < len; i++){
		if(ans[i]>=10) {
			ans[i+1]+=ans[i]/10;
			ans[i]=ans[i]%10;
		}
	}
	show(ans, len, positive);
	free(ans);
}


void show(int *ans, int len, int positive){
	int result = 0, i;
	for(i = len-1; i >= 0; i--){
		result += (ans[i] * pow(10, i));
	}
	printf("\nresult:%d\n", result * positive);
}
