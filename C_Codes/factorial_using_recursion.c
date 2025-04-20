#include<stdio.h>
int fact(int x);
int main(void){
    int n;
    printf("enter a number: ");
    scanf("%d",&n);
    printf("Fcatorial  is:%d",fact(n));

}
int fact(int x){
    if(x==0){
        return 1;
    }
    int factNm1=fact(x-1);
    int factN=factNm1*x;
    return factN;
}