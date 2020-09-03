#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
void isPositive(char *arr1, char *arr2, char ope);
int isBigger(char *arr1, char *arr2);
int add(char *arr1, char *arr2, int *ans);
int sub(char *arr1, char *arr2, int *ans);
int mult(char *arr1, char *arr2, int *ans);
void show(int *ans, int len, int positive);
void test();
void testOper(char input1[], char input2[], char ope);
int positive1, positive2;

void main(){
	test();	
}

void isPositive(char *arr1, char *arr2, char ope)
{
	int i, len1 = strlen(arr1), len2 = strlen(arr2);
	positive1 = 1, positive2 = 1;
	if(arr1[0] == '-'){
		positive1 = -1;
		for (i = 0; i < len1; i++)
	    {
	        *(arr1 + i) = *(arr1 + i + 1);
	    }
	}
	if(arr2[0] == '-'){
		positive2 = -1;
		for (i = 0; i < len2; i++)
	    {
	        *(arr2 + i) = *(arr2 + i + 1);
	    }
	}
}
int isBigger(char *arr1, char *arr2)
{
	int i, len1 = strlen(arr1), len2 = strlen(arr2);
	if(len1 < len2){
		return 2;  //arr順序交換 
	}
	if(len1 == len2){
		for(i = 0; i < len1; i++){
			if(arr1[i] < arr2[i]){
				return 2;
			}			
		}
	}
	return 1;
}
int add(char *arr1, char *arr2, int *ans)
{
	int len, len1 = strlen(arr1), len2 = strlen(arr2), i = 0, j = len1 - 1, k = len2 - 1;
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
	return len;
}
int sub(char *arr1, char *arr2, int *ans)
{
	int  len1 = strlen(arr1), len2 = strlen(arr2), i = 0, j = len1 - 1, k = len2 - 1;
	while(j >= 0 && k >= 0){
		ans[i++]=(arr1[j--] - '0') - (arr2[k--] - '0');
	}
	while(j >= 0){
		ans[i++] = arr1[j--] - '0';
	}
	while(k >= 0){
		ans[i++] = arr2[k--] - '0';
	}
	int len = len1;
	if(len1 < len2){
		len = len2;
	}
	for(i = 0; i < len; i++){
		if(ans[i]<0 && ans[i+1]){
			ans[i+1] -= 1;
			ans[i] = 10 + ans[i];
		}
	}
	return len;
}
int mult(char *arr1, char *arr2, int *ans)
{
	int len1 = strlen(arr1), len2 = strlen(arr2), len = len1 + len2 , i, j;
    for(i = 0; i < len1; i++) {
        if(arr1[i] == 0) continue;
        for(j = 0; j < len2; j++) {
			ans[len-(i+j+2)] += (arr1[i] - '0') * (arr2[j] - '0');
        }
    }
	for(i = 0; i < len; i++){
		if(ans[i] >= 10) {
			ans[i+1] += ans[i] / 10;
			ans[i] = ans[i] % 10;
		}
	}
	return len;
}
void show(int *ans, int len, int positive){
	if(positive == -1){
		printf("-");
	}
	int i;
    for(i = len-1; i > 0 && ans[i] == 0; --i);
    while(i >= 0){
		printf("%d", ans[i--]);
	}
	printf("\n");
}
void test(){
	testOper("-2", "9999999999999999999999999999", '*');	printf("-19999999999999999999999999998\n\n");
	testOper("9999999999999999999999999999", "-2", '*');	printf("-19999999999999999999999999998\n\n");
	testOper("9999999", "987", '+');	printf("10000986\n\n");
	testOper("-9999999", "-987", '+');	printf("-10000986\n\n");
	testOper("1111333", "333", '+');	printf("1111666\n\n");
	testOper("333", "-1111333", '+');	printf("-1111000\n\n");
	testOper("-333", "1111333", '+');	printf("1111000\n\n");
	testOper("333", "-1111333", '+');	printf("-1111000\n\n");
	testOper("-9999999", "987", '+');	printf("-10000986\n\n");
	testOper("9999999", "-987", '-');	printf("10000986\n\n");
	testOper("9999999", "987", '-');	printf("9999012\n\n");
	testOper("-9999999", "-987", '-');	printf("-9999012\n\n");
	testOper("333", "1111333", '-');	printf("-1111000\n\n");
	testOper("0", "0", '*');		printf("0\n\n");
	testOper("123", "123", '*');	printf("15129\n\n");
	testOper("-123", "123", '*');	printf("-15129\n\n");
	testOper("123", "-123", '*');	printf("-15129\n\n");
	testOper("-123", "-123", '*');	printf("15129\n\n");
	testOper("1231", "123", '*');	printf("151413\n\n");
	testOper("-123", "1231", '*');	printf("-151413\n\n");
}
void testOper(char input1[], char input2[], char ope){
	int i, len1 = strlen(input1), len2 = strlen(input2), *ans = calloc(MAX, sizeof(int));
	char *arr1 = malloc(len1 * sizeof(char)), *arr2 = malloc(len2 * sizeof(char));

	for(i = 0; i < len1; i++){
		arr1[i] = input1[i];
	}
	arr1[i] = '\0';
	for(i = 0; i < len2; i++){
		arr2[i] = input2[i];
	}
	arr2[i] = '\0';

	isPositive(arr1, arr2, ope);  //判斷正負，去掉正負符號 
	
	int bigger = isBigger(arr1, arr2);  //判斷兩數絕對值大小 
	int len, positive = positive1;
	switch(ope){
		case '+':
			if(positive1*positive2 == 1){//+++ -+-
				len = add(arr1, arr2, ans);
				break;
			}
			if(bigger == 1){
				len = sub(arr1, arr2, ans);
				break;
			}
			len = sub(arr2, arr1, ans);
			positive = positive2;//bigger == 2
			break;
		case '-':
			if(positive1*positive2 == 1){//+-+ ---
				if(bigger == 1){
					len = sub(arr1, arr2, ans);
					break;
				}
				len = sub(arr2, arr1, ans);
				positive =  positive1 * (-1);//bigger == 2
				break;
			}
			len = add(arr1, arr2, ans);
			break;
		case '*':
			len = mult(arr1, arr2, ans);
			positive =  positive1 * positive2;//bigger == 2
			break;
	}
	show(ans, len, positive);
	free(arr1);
	free(arr2);
	free(ans);
}
