#include<stdio.h>
 float percen(float s,float m,float sa);

 int main(void){
    int s,m,sa,percent;
    printf("Enter the marks of the subjects");
    scanf("%f%f%f",&s,&m,&sa);
     printf("the percentage is %f",percent);

 }
 float percen(float s,float m,float sa){
    float percent=((s+m+sa)/3)*100;
    return percent;
 }