// // // // // // // 1. Talyor series
// // // // // // #include<stdio.h>
// // // // // // #include<math.h>
// // // // // // int main()
// // // // // // {
// // // // // // int x,i;
// // // // // // int fact = 1,n;
// // // // // // float sum=0;
// // // // // // printf("\n\nEnter the value of x in the series : ");
// // // // // // scanf("%d",&x);
// // // // // // printf("\nEnter the number of terms in the series : ");
// // // // // // scanf("%d",&n);
// // // // // // for(i=1;i<n;i++)
// // // // // // {
// // // // // // fact = fact*i;
// // // // // // sum = sum + (pow(x,i)/fact) ;
// // // // // // }
// // // // // // sum= sum +1; //Since series starts with 1
// // // // // // printf("\nThe sum of the taylor series is : %.2f\n\n",sum);
// // // // // // return 0;
// // // // // // }

// // // // // // 3. Euler’s method
// // // // // #include<stdio.h>
// // // // // #define f(x,y) (2*y-x)/(y+2*x)
// // // // // int main()
// // // // // {
// // // // // float x0, y0, xn, h, yn, slope;
// // // // // int i, n;
// // // // // printf("Enter Initial Condition\n");
// // // // // printf("x0 = ");
// // // // // scanf("%f", &x0);
// // // // // printf("y0 = ");
// // // // // scanf("%f", &y0);
// // // // // printf("Enter calculation point xn = ");
// // // // // scanf("%f", &xn);
// // // // // printf("Enter number of steps: ");
// // // // // scanf("%d", &n);
// // // // // /* Calculating step size (h) */
// // // // // h = (xn-x0)/n;
// // // // // /* Euler's Method */
// // // // // printf("\nx0\ty0\tslope\tyn\n");
// // // // // printf("------------------------------\n");
// // // // // for(i=0; i < n; i++)
// // // // // {
// // // // // slope = f(x0, y0);
// // // // // yn = y0 + h * slope;
// // // // // printf("%.4f\t%.4f\t%0.4f\t%.4f\n",x0,y0,slope,yn);
// // // // // y0 = yn;
// // // // // x0 = x0+h;
// // // // // }
// // // // // /* Displaying result */
// // // // // printf("\nValue of y at x = %0.2f is %0.3f",xn, yn);
// // // // // return 0;
// // // // // }

// // // // // 4. Heun’s method
// // // // #include<stdio.h>
// // // // #define f(x,y) x+y*y
// // // // int main()
// // // // {
// // // // float x,y,h,xn,l;
// // // // printf("Program for Solution of Ordinary Differential Equation\nHeun's Method\n");
// // // // printf("Enter value for x and y\n");
// // // // scanf("%f%f",&x,&y);
// // // // printf("Enter value for h and last of x\n");
// // // // scanf("%f%f",&h,&xn);
// // // // while(x+h<=xn)
// // // // {
// // // // l=(h/2)*(f(x,y)+f(x+h,y+h*f(x,y)));
// // // // y=y+l;
// // // // x=x+h;
// // // // printf("y = %f\tx = %f\n",y,x);
// // // // }
// // // // return 0;
// // // // }

// // // // 5. Range-kutta method
// // // #include<stdio.h>
// // // #define f(x,y) 2*x+3*y
// // // int main()
// // // {
// // // float x0, y0, xn, h, yn, k1, k2, k3, k4, k;
// // // int i, n;
// // // printf("Enter Initial Condition\n");
// // // printf("x0 = ");
// // // scanf("%f", &x0);
// // // printf("y0 = ");
// // // scanf("%f", &y0);
// // // printf("Enter calculation point xn = ");
// // // scanf("%f", &xn);
// // // printf("Enter number of steps: ");
// // // scanf("%d", &n);
// // // h = (xn-x0)/n;
// // // printf("\nx0\ty0\tyn\n");
// // // for(i=0; i < n; i++)
// // // {
// // // k1 = h * (f(x0, y0));
// // // k2 = h * (f((x0+h/2), (y0+k1/2)));
// // // k3 = h * (f((x0+h/2), (y0+k2/2)));
// // // k4 = h * (f((x0+h), (y0+k3)));
// // // k = (k1+2*k2+2*k3+k4)/6;
// // // yn = y0 + k;
// // // printf("%0.4f\t%0.4f\t%0.4f\n",x0,y0,yn);
// // // x0 = x0+h;
// // // y0 = yn;
// // // }
// // // printf("\nValue of y at x = %0.2f is %0.3f",xn, yn);
// // // return 0;
// // // }

// // // 6. Boundary value problem
// // #include<stdio.h>
// // #include<math.h>
// // #include<stdlib.h>
// // float f1(float x, float y, float z)
// // {
// // return(z);
// // }
// // float f2(float x, float y, float z)
// // {
// // return(x + y);
// // }
// // float shoot(float x0, float y0, float z0, float xn, float h, int p)
// // {
// // float x, y, z, k1, k2, k3, k4, l1, l2, l3, l4, k, l, x1, y1, z1;
// // x = x0;
// // y = y0;
// // z = z0;
// // do
// // {
// // k1 = h * f1(x, y, z);
// // l1 = h * f2(x, y, z);
// // k2 = h * f1(x + h / 2.0, y + k1 / 2.0, z + l1 / 2.0);
// // l2 = h * f2(x + h / 2.0, y + k1 / 2.0, z + l1 / 2.0);
// // k3 = h * f1(x + h / 2.0, y + k2 / 2.0, z + l2 / 2.0);
// // l3 = h * f2(x + h / 2.0, y + k2 / 2.0, z + l2 / 2.0);
// // k4 = h * f1(x + h, y + k3, z + l3);
// // l4 = h * f2(x + h, y + k3, z + l3);
// // l = 1 / 6.0 * (l1 + 2 * l2 + 2 * l3 + l4);
// // k = 1 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
// // y1 = y + k;
// // x1 = x + h;
// // z1 = z + l;
// // x = x1;
// // y = y1;
// // z = z1;
// // if (p == 1)
// // {
// // printf("\n%f\t%f", x, y);
// // }
// // } while (x < xn);
// // return(y);
// // }
// //  int main()
// // {
// // float x0, y0, h, xn, yn, z0, m1, m2, m3, b, b1, b2, b3, e;
// // int p = 0;
// // printf("\n Enter x0,y0,xn,yn,h:");
// // scanf("%f%f%f%f%f", &x0, &y0, &xn, &yn, &h);
// // printf("\n Enter the trial M1:");
// // scanf("%f", &m1);
// // b = yn;
// // z0 = m1;
// // b1 = shoot(x0, y0, z0, xn, h, p = 1);
// // printf("\nB1 is %f", b1);
// // if (fabs(b1 - b) < 0.00005)
// // {
// // printf("\n The value of x and respective z are:\n");
// // e = shoot(x0, y0, z0, xn, h, p = 1);
// // return(0);
// // }
// // else
// // {
// // printf("\nEnter the value of M2:");
// // scanf("%f", &m2);
// // z0 = m2;
// // b2 = shoot(x0, y0, z0, xn, h, p = 1);
// // printf("\nB2 is %f", b2);
// // }
// // if (fabs(b2 - b) < 0.00005)
// // {
// // printf("\n The value of x and respective z are\n");
// // e = shoot(x0, y0, z0, xn, h, p = 1);
// // return(0);
// // }
// // else
// // {
// // printf("\nM2=%f\tM1=%f", m2, m1);
// // m3 = m2 - ((m2 - m1) / (b2 - b1)) * (b2 - b);
// // if (b1 - b2 == 0)
// // exit(0);
// // printf("\nExact value of M =%f", m3);
// // z0 = m3;
// // b3 = shoot(x0, y0, z0, xn, h, p = 0);
// // }
// // if (fabs(b3 - b) < 0.000005)
// // {
// // printf("\nThere is solution :\n");
// // e = shoot(x0, y0, z0, xn, h, p = 1);
// // exit(0);
// // }
// // do
// // {
// // m1 = m2;
// // m2 = m3;
// // b1 = b2;
// // b2 = b3;
// // m3 = m2 - ((m2 - m1) / (b2 - b1)) * (b2 - b);
// // z0 = m3;
// // b3 = shoot(x0, y0, z0, xn, h, p = 0);
// // } while (fabs(b3 - b) < 0.0005);
// // z0 = m3;
// // e = shoot(x0, y0, z0, xn, h, p = 1);
// // }

// // 7. Shooting method
// #include<stdio.h>
// #include<math.h>
// #include<stdlib.h>
// float f1(float x,float y,float z)
// {
// return(z);
// }
// float f2(float x,float y,float z)
// {
// return(x+y);
// }
// float shoot(float x0,float y0,float z0,float xn,float h,int p)
// {
// float x,y,z,k1,k2,k3,k4,l1,l2,l3,l4,k,l,x1,y1,z1;
// x=x0;
// y=y0;
// z=z0;
// do
// {
// k1=h*f1(x,y,z);
// l1=h*f2(x,y,z);
// k2=h*f1(x+h/2.0,y+k1/2.0,z+l1/2.0);
// l2=h*f2(x+h/2.0,y+k1/2.0,z+l1/2.0);
// k3=h*f1(x+h/2.0,y+k2/2.0,z+l2/2.0);
// l3=h*f2(x+h/2.0,y+k2/2.0,z+l2/2.0);
// k4=h*f1(x+h,y+k3,z+l3);
// l4=h*f2(x+h,y+k3,z+l3);
// l=1/6.0*(l1+2*l2+2*l3+l4);
// k=1/6.0*(k1+2*k2+2*k3+k4);
// y1=y+k;
// x1=x+h;
// z1=z+l;
// x=x1;
// y=y1;
// z=z1;
// if(p==1)
// {
// printf("\n%f\t%f",x,y);
// }
// }while(x<xn);
// return(y);
// }
// int main()
// {
// float x0,y0,h,xn,yn,z0,m1,m2,m3,b,b1,b2,b3,e;
// int p=0;
// printf("\n Enter x0,y0,xn,yn,h:");
// scanf("%f%f%f%f%f",&x0,&y0,&xn,&yn,&h);
// printf("\n Enter the trial M1:");
// scanf("%f",&m1);
// b=yn;
// z0=m1;
// b1=shoot(x0,y0,z0,xn,h,p=1);
// printf("\nB1 is %f",b1);
// if(fabs(b1-b)<0.00005)
// {
// printf("\n The value of x and respective z are:\n");
// e=shoot(x0,y0,z0,xn,h,p=1);
// return(0);
// }
// else
// {
// printf("\nEnter the value of M2:");
// scanf("%f",&m2);
// z0=m2;
// b2=shoot(x0,y0,z0,xn,h,p=1);
// printf("\nB2 is %f",b2);
// }
// if(fabs(b2-b)<0.00005)
// {
// printf("\n The value of x and respective z are\n");
// e= shoot(x0,y0,z0,xn,h,p=1);
// return(0);
// }
// else
// {
// printf("\nM2=%f\tM1=%f",m2,m1);
// m3=m2+(((m2-m1)*(b-b2))/(1.0*(b2-b1)));
// if(b1-b2==0)
// exit(0);
// printf("\nExact value of M =%f",m3);
// z0=m3;
// b3=shoot(x0,y0,z0,xn,h,p=0);
// }
// if(fabs(b3-b)<0.000005)
// {
// printf("\nThere is solution :\n");
// e=shoot(x0,y0,z0,xn,h,p=1);
// exit(0);
// }
// do
// {
// m1=m2;
// m2=m3;
// b1=b2;
// b2=b3;
// m3=m2+(((m2-m1)*(b-b2))/(1.0*(b2-b1)));
// z0=m3;
// b3=shoot(x0,y0,z0,xn,h,p=0);
// }while(fabs(b3-b)<0.0005);
// z0=m3;
// e=shoot(x0,y0,z0,xn,h,p=1);
// }

