// /* 1. LANGRANGE INTERPOLATION */
// // #include<stdio.h>
// // int main()
// // {
// // float x[100], y[100], xp, yp=0, p;
// // int i,j,n;
// // printf("Enter number of data: ");
// // scanf("%d", &n);
// // printf("Enter data:\n");
// // for(i=1;i<=n;i++)
// // {
// // printf("x[%d] = ", i);
// // scanf("%f", &x[i]);
// // printf("y[%d] = ", i);
// // scanf("%f", &y[i]);
// // }
// // printf("Enter interpolation point: ");
// // scanf("%f", &xp);
// // for(i=1;i<=n;i++)
// // {
// // p=1;
// // for(j=1;j<=n;j++)
// // {
// // if(i!=j)
// // {
// // p = p* (xp - x[j])/(x[i] - x[j]);
// // }
// // }
// // yp = yp + p * y[i];
// // }
// // printf("Interpolated value at %.3f is %.3f.", xp, yp);
// // return 0;
// // }

// // /* 2. Newton interpolation using forward method */
// // #include<stdio.h>
// // int main()
// // {
// // float x[20], y[20][20];
// // int i,j, n;
// // /* Input Section */
// // printf("Enter number of data:\n");
// // scanf("%d", &n);
// // printf("Enter data:\n");
// // for(i = 0; i < n ; i++)
// // {
// // printf("x[%d]=", i);
// // scanf("%f", &x[i]);
// // printf("y[%d]=", i);
// // scanf("%f", &y[i][0]);
// // }
// // for(i = 1; i < n; i++)
// // {
// // for(j = 0; j < n-i; j++)
// // {
// // y[j][i] = y[j+1][i-1] - y[j][i-1];
// // }
// // }
// // printf("\nFORWARD DIFFERENCE TABLE\n\n");
// // for(i = 0; i < n; i++)
// // {
// // printf("%0.2f", x[i]);
// // for(j = 0; j < n-i ; j++)
// // {
// // printf("\t%0.2f", y[i][j]);
// // }
// // printf("\n");
// // }
// // return 0;
// // }

// /* 3. Newton interpolation using backward method */
// // #include<stdio.h>
// // int main()
// // {
// // float x[20], y[20][20];
// // int i,j, n;
// // printf("Enter number of data:\n");
// // scanf("%d", &n);
// // printf("Enter data:\n");
// // for(i = 0; i < n ; i++)
// // {
// // printf("x[%d]=", i);
// // scanf("%f", &x[i]);
// // printf("y[%d]=", i);
// // scanf("%f", &y[i][0]);
// // }
// // for(i = 1; i < n; i++)
// // {
// // for(j = n-1; j > i-1; j--)
// // {
// // y[j][i] = y[j][i-1] - y[j-1][i-1];
// // }
// // }
// // printf("\nBACKWARD DIFFERENCE TABLE\n\n");
// // for(i = 0; i < n; i++)
// // {
// // printf("%0.2f", x[i]);
// // for(j = 0; j <= i ; j++)
// // {
// // printf("\t%0.2f", y[i][j]);
// // }
// // printf("\n");
// // }
// // return 0;
// // } 

// // 4. Newton interpolation using dividend method
// #include<stdio.h>
// int main()
// {
// int x[10], y[10], p[10];
// int k,f,n,i,j=1,f1=1,f2=0;
// printf("\nEnter the number of observations:\n");
// scanf("%d", &n);
// printf("\nEnter the different values of x:\n");
// for (i=1;i<=n;i++)
// scanf("%d", &x[i]);
// printf("\nThe corresponding values of y are:\n");
// for (i=1;i<=n;i++)
// scanf("%d", &y[i]);
// f=y[1];
// printf("\nEnter the value of 'k' in f(k) you want to evaluate:\n");
// scanf("%d", &k);
// do
// {
// for (i=1;i<=n-1;i++)
// {
// p[i] = ((y[i+1]-y[i])/(x[i+j]-x[i]));
// y[i]=p[i];
// }
// f1=1;
// for(i=1;i<=j;i++)
// {
// f1*=(k-x[i]);
// }
// f2+=(y[1]*f1);
// n--;
// j++;
// }
// while(n!=1);
// f+=f2;
// printf("\nf(%d) = %d", k , f);
// return 0;
// }
