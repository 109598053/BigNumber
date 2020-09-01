#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
void add(char *arr1, char *arr2);
char * sub(char *arr1, char *arr2);
char * mult(char *arr1, char *arr2);

void main(){
	char *arr1 = malloc(sizeof(char));
	char *arr2 = malloc(sizeof(char));
	char ch1, ch2, ope;
	int i, *arr = malloc(sizeof(int));
	
	printf("Input1:");
    scanf("%s", arr1);
	
	printf("Input2:");
    scanf("%s", arr2);
    
	int len, len1 = strlen(arr1), len2 = strlen(arr2);
    
    fflush(stdin);
	printf("請輸入運算子:");
    ope = getchar();
	
	switch(ope){
		case '+':
			add(arr1, arr2);
			break;
		case '-':
			if(len1 > len2){
				len = len1;
			}
			else{
				len = len2;
			}
//			ans = sub(arr1, arr2);
			break;
		case '*':
			if(len1 > len2){
				len = len1*2;
			}
			else{
				len = len2*2;
			}
//			ans = mult(arr1, arr2);
			break;
	}

        printf("\n");
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

void add(char *arr1, char *arr2)
{
	int *ans = malloc( MAX *sizeof(int));
	int i=0, j = strlen(arr1) - 1, k = strlen(arr2) - 1;
	while(j >= 0 && k >= 0){
		ans[i++]=(arr1[j--] - '0') + (arr2[k--] - '0');
	}
	while(j >= 0){
		ans[i++] = arr1[j--] - '0';
	}
	while(k >= 0){
		ans[i++] = arr2[k--] - '0';
	}
	int len;
	if(strlen(arr1) > strlen(arr2)){
		len = strlen(arr1);
	}
	else{
		len = strlen(arr2);
	}
	for(i = 0; i < len; i++){
		if(ans[i]>=10) {
			ans[i+1]+=ans[i]/10;
			ans[i]=ans[i]%10;
		}
	}
	for(i = len; i >= 0; i--){
		int a = ans[i];
		if(i==len && a==0){
			continue;
		}
		else{
	    	printf("%d ", a);
		}
	}
}
char * sub(char *arr1, char *arr2)
{
    return arr1;
}
char * mult(char *arr1, char *arr2)
{
    /* Implement function `hello()` here. */
    return arr1;
}
