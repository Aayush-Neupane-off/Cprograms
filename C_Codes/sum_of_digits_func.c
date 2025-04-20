#include<stdio.h>
int sumo(int m,int sum,int n);
int main(void){
    int n,m,sum=0;
    printf("Enter the number");
    scanf("%d",&n);
    sumo(m,sum,n);
}

int sumo(int m,int sum,int n){
    while (n>0)
    {
       m=n%10;
       sum=sum+m;
        n=n/10;
    }
    
    printf("the sum is %d\n",sum);

    return sum;
}