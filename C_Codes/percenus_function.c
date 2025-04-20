#include<stdio.h>
 float percen(float a,float b,float c);

 int main(void){
    float a,b,c;
    printf("Enter the marks of the subjects\n");
    scanf("%f%f%f",&a,&b,&c);
    //float percent =percen(x);
    //percen(s,m,sa);
     printf("the percentage is %f",percen(a,b,c));

 }
 float percen(float a,float b,float c){
    
    return ((a+b+c)/300)*100;
 }