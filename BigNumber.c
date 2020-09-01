#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	int *ans = malloc(sizeof(int));
	int i=0, j = strlen(arr1) - 1, k = strlen(arr2) - 1;
	while(j >= 0 && k >= 0){
		printf("\narr1: \n", (arr1[j] - '0') + (arr1[j] - '0'));
		ans[i++]=arr1[j--] + arr2[k--];
	}
	if(j >= 0){
		while(k >= 0){
			ans[i++] = arr1[j--] - '0';
		}
	}
	else if(k >= 0){
		while(k >= 0){
			ans[i++] = arr2[k--] - '0';
		}
	}
	printf("\narr1: \n");
	for (i = strlen(arr1)-1; i >= 0; i--)
    {
        printf("%c ", *(arr1 + i));
    }
	printf("\nans: \n");
	for (i = strlen(arr1)-1; i >= 0; i--)
    {
        printf("%d ", *(ans + i));
    }
	printf("\nans: %d\n", ans);
	for (i = 0; i < strlen(arr1); i++)
    {
        printf(" %d", ans[i]);
    }
	for(i = 0; i < strlen(arr1); i++){
		if(ans[i]>=10) {
			ans[i+1]+=ans[i]/10;
			ans[i]=ans[i]%10;
		}
	}
	printf("\nans:");
	for (i = 0; i < strlen(arr1); i++)
    {
        printf("%c", *(ans + i));
    }
	printf("add:%s\n", ans);
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
