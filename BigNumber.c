#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
void count(char *arr1, char *arr2);
void isPositive(char *arr1, char *arr2);
//void sub(char *arr1, char *arr2);
char * mult(char *arr1, char *arr2);
int positive1, positive2;

void main(){
	char *arr1 = malloc(sizeof(char));
	char *arr2 = malloc(sizeof(char));
	char ch1, ch2, ope;
	int i, *arr = malloc(sizeof(int));
	
	printf("Input1:");
    scanf("%s", arr1);
	
	printf("Input2:");
    scanf("%s", arr2);
    
    fflush(stdin);
	printf("請輸入運算子:");
    ope = getchar();
	
	isPositive(arr1, arr2);
	
	switch(ope){
		case '+':
		case '-':
			count(arr1, arr2);
			break;
		case '*':
//			ans = mult(arr1, arr2);
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

void count(char *arr1, char *arr2)
{
	int *ans = calloc( MAX,  sizeof(int));
	int len, len1 = strlen(arr1), len2 = strlen(arr2), i=0, j = len1 - 1, k = len2 - 1;
	printf("p1:%d p2:%d\n", positive1, positive2);
	while(j >= 0 && k >= 0){
		ans[i++]=(arr1[j--] - '0') * positive1 + (arr2[k--] - '0') * positive2;
	}
	while(j >= 0){
		ans[i++] = (arr1[j--] - '0') * positive1;
	}
	while(k >= 0){
		ans[i++] = (arr2[k--] - '0') * positive2;
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
		else if(ans[i]<0 && ans[i+1]){ //&& ans[10]>-10???
			ans[i+1] -= 1;
			ans[i] = 10 - ans[i];
		}
	}
	int result = 0;
	for(i = len-1; i >= 0; i--){
		result += (ans[i] * pow(10, i));
	}
	printf("result:%d\n", result);
}
void isPositive(char *arr1, char *arr2)
{
	int i;
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
char * mult(char *arr1, char *arr2)
{
	int len, len1 = strlen(arr1), len2 = strlen(arr2), i=0, j = len1 - 1, k = len2 - 1;
	if(len1 > len2){
		len = len1*2;
	}
	else{
		len = len2*2;
	}
    return arr1;
}
