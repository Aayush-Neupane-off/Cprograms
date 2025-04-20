#include<stdio.h>
int main(void){
float price[3];
printf("Enter the numbers\n");
scanf("%f%f%f",&price[0],&price[1],&price[2]);
printf("total price with gst of item 1 is %f\n",price[0]+0.18*price[0]);
printf("total price with gst of item 2 is %f\n",price[1]+0.18*price[1]);
printf("total price with gst of item 3 is %f\n",price[2]+0.18*price[2]);

}