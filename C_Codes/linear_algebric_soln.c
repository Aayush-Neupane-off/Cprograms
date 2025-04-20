// // // // #include<stdio.h>
// // // // #include<math.h>
// // // // #include<stdlib.h>
// // // // #define SIZE 10
// // // // int main()
// // // // {
// // // // float a[SIZE][SIZE], x[SIZE], ratio;
// // // // int i,j,k,n;
// // // // printf("Enter number of unknowns: ");
// // // // scanf("%d", &n);
// // // // for(i=1;i<=n;i++)
// // // // {
// // // // for(j=1;j<=n+1;j++)
// // // // // {
// // // // // // // // printf("a[%d][%d] = ",i,j);
// // // // // // // // scanf("%f", &a[i][j]);
// // // // // // // // }
// // // // // // // // }
// // // // // // // // for(i=1;i<=n-1;i++)
// // // // // // // // {
// // // // // // // // if(a[i][i] == 0.0)
// // // // // // // // {
// // // // // // // // printf("Mathematical Error!");
// // // // // // // // exit(0);
// // // // // // // // }
// // // // // // // // for(j=i+1;j<=n;j++)
// // // // // // // // {
// // // // // // // // ratio = a[j][i]/a[i][i];
// // // // // // // // for(k=1;k<=n+1;k++)
// // // // // // // // {
// // // // // // // // a[j][k] = a[j][k] - ratio*a[i][k];
// // // // // // // // }
// // // // // // // // }
// // // // // // // // }
// // // // // // // // x[n] = a[n][n+1]/a[n][n];
// // // // // // // // for(i=n-1;i>=1;i--)
// // // // // // // // {
// // // // // // // // x[i] = a[i][n+1];
// // // // // // // // for(j=i+1;j<=n;j++)
// // // // // // // // {
// // // // // // // // x[i] = x[i] - a[i][j]*x[j];
// // // // // // // // }
// // // // // // // // x[i] = x[i]/a[i][i];
// // // // // // // // }
// // // // // // // // printf("\nSolution:\n");
// // // // // // // // for(i=1;i<=n;i++)
// // // // // // // // {
// // // // // // // // printf("x[%d] = %0.3f\n",i, x[i]);
// // // // // // // // }
// // // // // // // // return(0);
// // // // // // // // }

// // // // // // // // 2. Gauss Jordan method
// // // // // // // #include<stdio.h>
// // // // // // // #include<math.h>
// // // // // // // #define SIZE 10
// // // // // // // int main()
// // // // // // // {
// // // // // // // float a[SIZE][SIZE], x[SIZE], ratio;
// // // // // // // int i,j,k,n;
// // // // // // // printf("Enter number of unknowns: ");
// // // // // // // scanf("%d", &n);
// // // // // // // printf("Enter coefficients of Augmented Matrix:\n");
// // // // // // // for(i=1;i<=n;i++)
// // // // // // // {
// // // // // // // for(j=1;j<=n+1;j++)
// // // // // // // {
// // // // // // // printf("a[%d][%d] = ",i,j);
// // // // // // // scanf("%f", &a[i][j]);
// // // // // // // }
// // // // // // // }
// // // // // // // for(i=1;i<=n;i++)
// // // // // // // {
// // // // // // // if(a[i][i] == 0.0)
// // // // // // // {
// // // // // // // printf("Mathematical Error!");
// // // // // // // exit(0);
// // // // // // // }
// // // // // // // for(j=1;j<=n;j++)
// // // // // // // {
// // // // // // // if(i!=j)
// // // // // // // {ratio = a[j][i]/a[i][i];
// // // // // // // for(k=1;k<=n+1;k++)
// // // // // // // {
// // // // // // // a[j][k] = a[j][k] - ratio*a[i][k];
// // // // // // // } }} }
// // // // // // // for(i=1;i<=n;i++)
// // // // // // // {
// // // // // // // x[i] = a[i][n+1]/a[i][i];
// // // // // // // }
// // // // // // // printf("\nSolution:\n");
// // // // // // // for(i=1;i<=n;i++)
// // // // // // // {
// // // // // // // printf("x[%d] = %0.3f\n",i, x[i]);
// // // // // // // }
// // // // // // // return 0;
// // // // // // // }

// // // // // // // 3. Matrix inversion using Gauss Jordan method
// // // // // // #include<stdio.h>
// // // // // // #include<math.h>
// // // // // // #include<stdlib.h>
// // // // // // #define SIZE 10
// // // // // // int main()
// // // // // // {
// // // // // // float a[SIZE][SIZE], x[SIZE], ratio;
// // // // // // int i,j,k,n;
// // // // // // printf("Enter number of unknowns: ");
// // // // // // scanf("%d", &n);
// // // // // // for(i=1;i<=n;i++)
// // // // // // {
// // // // // // for(j=1;j<=n+1;j++)
// // // // // // {
// // // // // // printf("a[%d][%d] = ",i,j);
// // // // // // scanf("%f", &a[i][j]);
// // // // // // }
// // // // // // }
// // // // // // /* Applying Gauss Elimination */
// // // // // // for(i=1;i<=n-1;i++)
// // // // // // {
// // // // // // if(a[i][i] == 0.0)
// // // // // // {
// // // // // // printf("Mathematical Error!");
// // // // // // exit(0);
// // // // // // }
// // // // // // for(j=i+1;j<=n;j++)
// // // // // // {
// // // // // // ratio = a[j][i]/a[i][i];
// // // // // // for(k=1;k<=n+1;k++)
// // // // // // {
// // // // // // a[j][k] = a[j][k] - ratio*a[i][k];
// // // // // // }
// // // // // // }
// // // // // // }
// // // // // // x[n] = a[n][n+1]/a[n][n];
// // // // // // for(i=n-1;i>=1;i--)
// // // // // // {
// // // // // // x[i] = a[i][n+1];
// // // // // // for(j=i+1;j<=n;j++)
// // // // // // {
// // // // // // x[i] = x[i] - a[i][j]*x[j];
// // // // // // }
// // // // // // x[i] = x[i]/a[i][i];
// // // // // // }
// // // // // // printf("\nSolution:\n");
// // // // // // for(i=1;i<=n;i++)
// // // // // // {
// // // // // // printf("x[%d] = %0.3f\n",i, x[i]);
// // // // // // }
// // // // // // return 0;
// // // // // // }

// // // // // // 4. Matrix Factorization using Doolittle LU Decomposition
// // // // // #include<stdio.h>
// // // // // int main()
// // // // // {
// // // // // float A[20][20]= {0},L[20][20]= {0}, U[20][20];
// // // // // float B[20]= {0}, X[20]= {0},Y[20]= {0};
// // // // // int i,j,k,n;
// // // // // printf("Enter the order of square matrix: ");
// // // // // scanf("%d",&n);
// // // // // printf("\nEnter matrix element:\n");
// // // // // for(i=0; i<n; i++)
// // // // // {
// // // // // for(j=0; j<n; j++)
// // // // // {
// // // // // printf("Enter A[%d][%d] element: ", i,j);
// // // // // scanf("%f",&A[i][j]);
// // // // // }
// // // // // }
// // // // // printf("\nEnter the constant terms: \n");
// // // // // for(i=0; i<n; i++)
// // // // // {
// // // // // printf("B[%d]",i);
// // // // // scanf("%f",&B[i]);
// // // // // }
// // // // // for(j=0; j<n; j++)
// // // // // {
// // // // // for(i=0; i<n; i++)
// // // // // {
// // // // // if(i<=j)
// // // // // {
// // // // // U[i][j]=A[i][j];
// // // // // for(k=0; k<i-1; k++)
// // // // // U[i][j]-=L[i][k]*U[k][j];
// // // // // if(i==j)
// // // // // L[i][j]=1;
// // // // // else
// // // // // L[i][j]=0;
// // // // // }
// // // // // else
// // // // // {
// // // // // L[i][j]=A[i][j];
// // // // // for(k=0; k<=j-1; k++)
// // // // // L[i][j]-=L[i][k]*U[k][j];
// // // // // L[i][j]/=U[j][j];
// // // // // U[i][j]=0;
// // // // // }
// // // // // }
// // // // // }
// // // // // printf("[L]: \n");
// // // // // for(i=0; i<n; i++)
// // // // // {
// // // // // for(j=0; j<n; j++)
// // // // // printf("%9.3f",L[i][j]);
// // // // // printf("\n");
// // // // // }
// // // // // printf("\n\n[U]: \n");
// // // // // for(i=0; i<n; i++)
// // // // // {
// // // // // for(j=0; j<n; j++)
// // // // // printf("%9.3f",U[i][j]);
// // // // // printf("\n");
// // // // // }
// // // // // for(i=0; i<n; i++)
// // // // // {
// // // // // Y[i]=B[i];
// // // // // for(j=0; j<i; j++)
// // // // // {
// // // // // Y[i]-=L[i][j]*Y[j];
// // // // // }
// // // // // }
// // // // // printf("\n\n[Y]: \n");
// // // // // for(i=0; i<n; i++)
// // // // // {
// // // // // printf("%9.3f",Y[i]);
// // // // // }
// // // // // for(i=n-1; i>=0; i--)
// // // // // {
// // // // // X[i]= Y[i];
// // // // // for(j=i+1; j<n; j++)
// // // // // {
// // // // // X[i]-=U[i][j]*X[j];
// // // // // }
// // // // // X[i]/=U[i][i];
// // // // // }
// // // // // printf("\n\n[X]: \n");
// // // // // for(i=0; i<n; i++)
// // // // // {
// // // // // printf("%9.3f",X[i]);
// // // // // }
// // // // // return 0;
// // // // // }
 
// // // // //  5. Matrix factorization using Cholesky’s method
// // // // #include <stdio.h>
// // // // #include <stdlib.h>
// // // // #include <math.h>
// // // // double *cholesky(double *A, int n) {
// // // // double *L = (double*)calloc(n * n, sizeof(double));
// // // // if (L == NULL)
// // // // exit(EXIT_FAILURE);
// // // // for (int i = 0; i < n; i++)
// // // // for (int j = 0; j < (i+1); j++) {
// // // // double s = 0;
// // // // for (int k = 0; k < j; k++)
// // // // s += L[i * n + k] * L[j * n + k];
// // // // L[i * n + j] = (i == j) ?
// // // // sqrt(A[i * n + i] - s) :
// // // // (1.0 / L[j * n + j] * (A[i * n + j] - s));
// // // // }
// // // // return L;
// // // // }
// // // // void show_matrix(double *A, int n) {
// // // // for (int i = 0; i < n; i++) {
// // // // for (int j = 0; j < n; j++)
// // // // printf("%2.5f ", A[i * n + j]);
// // // // printf("\n");
// // // // }
// // // // }
// // // // int main() {
// // // // int n = 3;
// // // // double m1[] = {25, 15, -5,
// // // // 15, 18, 0,
// // // // -5, 0, 11};
// // // // double *c1 = cholesky(m1, n);
// // // // show_matrix(c1, n);
// // // // printf("\n");
// // // // free(c1);
// // // // n = 4;
// // // // double m2[] = {18, 22, 54, 42,
// // // // 22, 70, 86, 62,
// // // // 54, 86, 174, 134,
// // // // 42, 62, 134, 106};
// // // // double *c2 = cholesky(m2, n);
// // // // show_matrix(c2, n);
// // // // free(c2);
// // // // return 0;
// // // // }

// // // // 6. Jacob iterative method
// // // #include<stdio.h>
// // // #include<math.h>
// // // #define f1(x,y,z) (17-y+2*z)/20
// // // #define f2(x,y,z) (-18-3*x+z)/20
// // // #define f3(x,y,z) (25-2*x+3*y)/20
// // // /* Main function */
// // // int main()
// // // {
// // // float x0=0, y0=0, z0=0, x1, y1, z1, e1, e2, e3, e;
// // // int count=1;
// // // printf("Enter tolerable error:\n");
// // // scanf("%f", &e);
// // // printf("\nCount\tx\ty\tz\n");
// // // do
// // // {
// // // /* Calculation */
// // // x1 = f1(x0,y0,z0);
// // // y1 = f2(x0,y0,z0);
// // // z1 = f3(x0,y0,z0);
// // // printf("%d\t%0.4f\t%0.4f\t%0.4f\n",count, x1,y1,z1);
// // // e1 = fabs(x0-x1);
// // // e2 = fabs(y0-y1);
// // // e3 = fabs(z0-z1);
// // // count++;
// // // x0 = x1;
// // // y0 = y1;
// // // z0 = z1;
// // // }while(e1>e && e2>e && e3>e);
// // // printf("\nSolution: x=%0.3f, y=%0.3f and z = %0.3f\n",x1,y1,z1);
// // // return 0;
// // // }

// // // 7. Gauss sedial iterative method
// // #include<stdio.h>
// // #include<math.h>
// // #define f1(x,y,z) (14-y-3*z)/5
// // #define f2(x,y,z) (7-x-9*z)/10
// // #define f3(x,y,z) (17+2*x-7*y)/10
// // /* Main function */
// // int main()
// // {
// // float x0=0, y0=0, z0=0, x1, y1, z1, e1, e2, e3, e;
// // int count=1;
// // printf("Enter tolerable error:\n");
// // scanf("%f", &e);
// // printf("\nCount\tx\ty\tz\n");
// // do
// // {
// // /* Calculation */
// // x1 = f1(x0,y0,z0);
// // y1 = f2(x1,y0,z0);
// // z1 = f3(x1,y1,z0);
// // printf("%d\t%0.4f\t%0.4f\t%0.4f\n",count, x1,y1,z1);
// // /* Error */
// // e1 = fabs(x0-x1);
// // e2 = fabs(y0-y1);
// // e3 = fabs(z0-z1);
// // count++;
// // /* Set value for next iteration */
// // x0 = x1;
// // y0 = y1;
// // z0 = z1;
// // }while(e1>e && e2>e && e3>e);
// // printf("\nSolution: x=%0.3f, y=%0.3f and z = %0.3f\n",x1,y1,z1);
// // return 0;
// // }

// // 8. Power method
// #include<stdio.h>
// #include<math.h>
// #define SIZE 10
// int main()
// {
// float a[SIZE][SIZE], x[SIZE],x_new[SIZE];
// float temp, lambda_new, lambda_old, error;
// int i,j,n, step=1;
// /* Inputs */
// printf("Enter Order of Matrix: ");
// scanf("%d", &n);
// printf("Enter Tolerable Error: ");
// scanf("%f", &error);
// /* Reading Matrix */
// printf("Enter Coefficient of Matrix:\n");
// for(i=1;i<=n;i++)
// {
// for(j=1;j<=n;j++)
// {
// printf("a[%d][%d]=",i,j);
// scanf("%f", &a[i][j]);
// }
// }
// /* Reading Intial Guess Vector */
// printf("Enter Initial Guess Vector:\n");
// for(i=1;i<=n;i++)
// {
// printf("x[%d]=",i);
// scanf("%f", &x[i]);
// }
// /* Initializing Lambda_Old */
// lambda_old = 1;
// /* Multiplication */
// up:
// for(i=1;i<=n;i++)
// {
// temp = 0.0;
// for(j=1;j<=n;j++)
// {
// temp = temp + a[i][j]*x[j];
// }
// x_new[i] = temp;
// }
// /* Replacing */
// for(i=1;i<=n;i++)
// {
// x[i] = x_new[i];
// }
// /* Finding Largest */
// lambda_new = fabs(x[1]);
// for(i=2;i<=n;i++)
// {
// if(fabs(x[i])>lambda_new)
// {
// lambda_new = fabs(x[i]);
// }
// }
// /* Normalization */
// for(i=1;i<=n;i++)
// {
// x[i] = x[i]/lambda_new;
// }
// /* Display */
// printf("\n\nSTEP-%d:\n", step);
// printf("Eigen Value = %f\n", lambda_new);
// printf("Eigen Vector:\n");
// for(i=1;i<=n;i++)
// {
// printf("%f\t", x[i]);
// }
// /* Checking Accuracy */
// if(fabs(lambda_new-lambda_old)>error)
// {
// lambda_old=lambda_new;
// step++;
// goto up;
// }
// return 0;
// }
