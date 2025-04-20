#include<stdio.h>

int main(void){
    FILE *fptr;
    fptr = fopen("hello.txt", "a");
    fprintf(fptr, "%c", 'M' );
}