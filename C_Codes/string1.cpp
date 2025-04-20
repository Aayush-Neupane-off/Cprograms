#include<stdio.h>
int main(void){
	char firstName[]="AAYUSH\0";
	char lastName[]="NEUPANE\0";
	for(int i='A';i<'\0';i++){
		printf("%c",i);
	}
	for(int j='N';j<'\0';j++){
		printf("%c",j);
	}
}
