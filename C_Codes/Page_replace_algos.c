//FIFO page replacement
// #include <stdio.h>
// int main()
// {
// int referenceString[10], pageFaults = 0, m, n, s, pages, frames;
// printf("\nEnter the number of Pages:\t");
// scanf("%d", &pages);
// printf("\nEnter reference string values:\n");
// for( m = 0; m < pages; m++)
// {
//    printf("Value No. [%d]:\t", m + 1);
//    scanf("%d", &referenceString[m]);
// }
// printf("\n What are the total number of frames:\t");
// {
//    scanf("%d", &frames);
// }
// int temp[frames];
// for(m = 0; m < frames; m++)
// {
//   temp[m] = -1;
// }
// for(m = 0; m < pages; m++)
// {
//   s = 0;
//   for(n = 0; n < frames; n++)
//    {
//       if(referenceString[m] == temp[n])
//          {
//             s++;
//             pageFaults--;
//          }
//    }     
//    pageFaults++;
//    if((pageFaults <= frames) && (s == 0))
//       {
//         temp[m] = referenceString[m];
//       }   
//    else if(s == 0)
//       {
//         temp[(pageFaults - 1) % frames] = referenceString[m];
//       }
//       printf("\n");
//       for(n = 0; n < frames; n++)
//        {     
//          printf("%d\t", temp[n]);
//        }
// } 
// printf("\nTotal Page Faults:\t%d\n", pageFaults);
// return 0;
// }

// Optimum page replacement
// #include<stdio.h>
 
// int main()
// {
//     int no_of_frames, no_of_pages, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
//     printf("Enter number of frames: ");
//     scanf("%d", &no_of_frames);
    
//     printf("Enter number of pages: ");
//     scanf("%d", &no_of_pages);
    
//     printf("Enter page reference string:");
    
//     for(i = 0; i < no_of_pages; ++i){
//         scanf("%d", &pages[i]);
//     }
    
//     for(i = 0; i < no_of_frames; ++i){
//         frames[i] = -1;
//     }
    
//     for(i = 0; i < no_of_pages; ++i){
//         flag1 = flag2 = 0;
        
//         for(j = 0; j < no_of_frames; ++j){
//             if(frames[j] == pages[i]){
//                    flag1 = flag2 = 1;
//                    break;
//                }
//         }
        
//         if(flag1 == 0){
//             for(j = 0; j < no_of_frames; ++j){
//                 if(frames[j] == -1){
//                     faults++;
//                     frames[j] = pages[i];
//                     flag2 = 1;
//                     break;
//                 }
//             }    
//         }
        
//         if(flag2 == 0){
//         	flag3 =0;
        	
//             for(j = 0; j < no_of_frames; ++j){
//             	temp[j] = -1;
            	
//             	for(k = i + 1; k < no_of_pages; ++k){
//             		if(frames[j] == pages[k]){
//             			temp[j] = k;
//             			break;
//             		}
//             	}
//             }
            
//             for(j = 0; j < no_of_frames; ++j){
//             	if(temp[j] == -1){
//             		pos = j;
//             		flag3 = 1;
//             		break;
//             	}
//             }
            
//             if(flag3 ==0){
//             	max = temp[0];
//             	pos = 0;
            	
//             	for(j = 1; j < no_of_frames; ++j){
//             		if(temp[j] > max){
//             			max = temp[j];
//             			pos = j;
//             		}
//             	}            	
//             }
			
// 			frames[pos] = pages[i];
// 			faults++;
//         }
        
//         printf("\n");
        
//         for(j = 0; j < no_of_frames; ++j){
//             printf("%d\t", frames[j]);
//         }
//     }
    
//     printf("\n\nTotal Page Faults = %d", faults);
//     printf("\n page miss ratio = %d/%d", faults, no_of_pages);
//     return 0;
// }

//LRU
// #include<stdio.h>

// int findLRU(int time[], int n){
// 	int i, minimum = time[0], pos = 0;

// 	for(i = 1; i < n; ++i){
// 		if(time[i] < minimum){
// 			minimum = time[i];
// 			pos = i;
// 		}
// 	}
	
// 	return pos;
// }

// int main()
// {
//     int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
// 	printf("Enter number of frames: ");
// 	scanf("%d", &no_of_frames);
	
// 	printf("Enter number of pages: ");
// 	scanf("%d", &no_of_pages);
	
// 	printf("Enter reference string: ");
	
//     for(i = 0; i < no_of_pages; ++i){
//     	scanf("%d", &pages[i]);
//     }
    
// 	for(i = 0; i < no_of_frames; ++i){
//     	frames[i] = -1;
//     }
    
//     for(i = 0; i < no_of_pages; ++i){
//     	flag1 = flag2 = 0;
    	
//     	for(j = 0; j < no_of_frames; ++j){
//     		if(frames[j] == pages[i]){
// 	    		counter++;
// 	    		time[j] = counter;
// 	   			flag1 = flag2 = 1;
// 	   			break;
//    			}
//     	}
    	
//     	if(flag1 == 0){
// 			for(j = 0; j < no_of_frames; ++j){
// 	    		if(frames[j] == -1){
// 	    			counter++;
// 	    			faults++;
// 	    			frames[j] = pages[i];
// 	    			time[j] = counter;
// 	    			flag2 = 1;
// 	    			break;
// 	    		}
//     		}	
//     	}
    	
//     	if(flag2 == 0){
//     		pos = findLRU(time, no_of_frames);
//     		counter++;
//     		faults++;
//     		frames[pos] = pages[i];
//     		time[pos] = counter;
//     	}
    	
//     	printf("\n");
    	
//     	for(j = 0; j < no_of_frames; ++j){
//     		printf("%d\t", frames[j]);
//     	}
// 	}
	
// 	printf("\n\nTotal Page Faults = %d", faults);
//     printf("\n page miss ratio = %d/%d", faults, no_of_pages);
//     return 0;
// }

//second chance page replacement 
// #include <stdio.h>

// int hasspace(int m, int f[m][3])
// {
// 	int i;
// 	for(i=0; i<m; i++)
// 	{
// 		if(f[i][0] == -1)
// 			return i;
// 	}
// 	return -1;
// }

// int available(int m, int f[m][3], int x)
// {
// 	int i;
// 	for(i=0; i<m; i++)
// 		if(f[i][0] == x)
// 			return i;
// 	return -1;
// }

// void printF(int m, int f[m][3])
// {
// 	int i;
// 	for(i=0; i<m; i++)
// 	{
// 		if(f[i][0] != -1)
// 		{
// 			if(i != 0)
// 				printf("\t");
// 			printf("\t\t%d\t     %d\t\t  %d\n",f[i][0],f[i][1],f[i][2]);
// 		}
// 	}
// }

// int doweskip(int k, int m, int skip[m])
// {
// 	int i;
// 	for(i=0; i<m; i++)
// 		if(k == skip[i])
// 			return 1;
// 	return 0;
// }

// int FIFO(int m, int f[m][3], int skip[m])
// {
//     int i, index, maxtc, flag = 0; 
//     for(i=0; i<m; i++)
//     {
// 		if(doweskip(f[i][0],m,skip) == 0)
// 		{
// 			if(flag == 0)
// 			{
// 				maxtc = f[i][1];
// 				index = i;
// 				flag = 1;
// 			}
// 			else if(f[i][1] > maxtc)
// 			{
// 				maxtc = f[i][1];
// 				index = i;
// 			}
// 		}
//     }

//     return index;
// }

// void updateskip(int k, int m, int skip[m])
// {
// 	int i;
// 	for(i=0; i<m; i++)
// 	{
// 		if(skip[i] == -1)
// 		{
// 			skip[i] = k;
// 			return;
// 		}
// 	}
// }

// int getvictim(int m, int f[m][3])
// {
//     int i, index, count = 0, maxtc, flag = 0, skip[m];
	
// 	for(i=0; i<m; i++)
// 		skip[i] = -1;
    
// 	for(i=0; i<m; i++)
//         if(f[i][2] == 1)
//             count++;
    
//     if(count == 0 || count == m)
//     {
//         if(count == m)
//            	for(i=0; i<m; i++)					
//                 f[i][2] = 0;
//         index = FIFO(m,f,skip);
//     }
//     else
//     {
//         for(i=0; i<m; i++)					
//         {
// 			index = FIFO(m,f,skip);
// 			if(f[index][2] == 1)
// 			{
// 				f[index][2] = 0;
// 				updateskip(f[index][0],m,skip);
// 			}
// 			else
// 				break;
//         }
//     }
//     return index;	
// }

// void timecounter(int k, int m, int f[m][3], int flag)
// {
//     int i;
// 	for(i=0; i<m; i++)
// 	{
//         if(flag == 1 && f[i][0] != -1)
//             f[i][1]++;
//         else if(flag == 0 && f[i][0] != -1)
//         {
//             if(i == k)
//                 f[i][1] = 0;
//             else
//                 f[i][1]++;
//         }
// 	}    
// }

// void line()
// {
// 	int i;
// 	printf("\n\t"); 
// 	for(i=0; i<55; i++)
// 		printf("_");
// 	printf("\n\n");
// }

// int iterate(int n, int s[n], int m, int f[m][3])
// {
//     printf("\n\n\tPage\t      Frame\ttime-counter\treference-bit");
// 	line();
// 	int i, k = -1, pf = 0, index = -1;
// 	for(i=0; i<n; i++)
// 	{
// 		//printf("\t");
// 		if( available(m,f,s[i]) == -1 )
// 		{
// 			pf++;
// 			if(hasspace(m,f) != -1)
// 			{
// 				index = hasspace(m,f);
// 				f[index][0] = s[i];
// 				timecounter(index,m,f,0);
// 				f[index][2] = 0;
// 			}
// 			else
// 			{
// 				index = getvictim(m,f);
// 				f[index][0] = s[i];
// 				timecounter(index,m,f,0);
// 				printf(" !--");
// 			}
// 		}
// 		else
// 		{
// 			index = available(m,f,s[i]);
//             timecounter(index,m,f,1);
//             f[index][2] = 1;
// 		}

// 		printf("\t[%d]",s[i]);
// 		printF(m,f);
// 		line();

// 	}
// 	return pf;		
// }

// void setdefault(int m, int f[m][3])
// {
// 	int i;
// 	for(i=0; i<m; i++)
// 	{
// 		f[i][0] = -1;
// 		f[i][1] = -1;
// 		f[i][2] = -1;
// 	}
// }

// void main()
// {
// 	int n, m = 3, i;
// 	printf("\n Enter the length of the reference string: ");
// 	scanf("%d",&n);
	
// 	int s[n];
// 	printf("\n Enter the reference string: "); 
// 	//7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
// 	for(i=0; i<n; i++)
// 	{
// 		scanf("%d",&s[i]);
// 		if(s[i] < 0)
// 		{
// 			printf("\n Reference string cannot have negative entries.\n");
// 			return;
// 		}
// 	}
// 	printf("\n Enter the no. of frames: ");
// 	scanf("%d",&m);
// 	printf("\n");
// 	int f[m][3];
// 	setdefault(m,f);
// 	int pf = iterate(n,s,m,f);
// 	printf("\n\tThe Total number of page faults: %d\n\n",pf);
//     printf("Page miss ratio = %d/%d", pf,n );
// }

//LRU page replacement
// #include <stdio.h>

// void setdefault(int m, int f[m][3])
// {
//     int i;
//     for(i=0; i<m; i++)
//     {
//         f[i][0] = -1;
//         f[i][1] = -1;
//         f[i][2] = -1;
//     }
// }

// int updatefreq(int s, int n, int freq[n][2])
// {
//     int i, flag = 0;
//     for(i=0; i<n; i++)
//     {
//         if(freq[i][0] == s)
//         {
//             freq[i][1]++;
//             flag = 1;
//             return freq[i][1];
//         }
//     }
//     if(flag == 0)
//     {
//         for(i=0; i<n; i++)
//         {
//             if(freq[i][0] == -1)
//                 break;
//         }
//         freq[i][0] = s;
//         freq[i][1]++;
//     }
//     return freq[i][1];
// }

// int available(int s, int m, int f[m][3])
// {
//     int i; 
//     for(i=0; i<m; i++)
//     {
//         if(f[i][0] == s)
//             return i;      
//     }
//     return -1;
// }

// void printF(int s,int m, int f[m][3])
// {
// 	int i;
//     printf("\t[%d]",s);
// 	for(i=0; i<m; i++)
// 	{
//         if(i != 0)
//             printf("\t");
//         if(f[i][0] != -1)
//     		printf("\t\t%d\t\t%d\t\t%d\n",f[i][0],f[i][1],f[i][2]);
// 	}
// }

// int hasSpace(int m, int f[m][3])
// {
//     int i; 
//     for(i=0; i<m; i++)
//     {
//         if(f[i][0] == -1)
//             return i;
//     }
//     return -1;
// }

// int checkFreq(int m, int f[m][3])
// {
//     int i, min, flag = 0, index, count = 0; 
//     for(i=0; i<m; i++)
//     {
//         if(i == 0)
//         {
//             min = f[i][2];
//             index = i;
//         }
//         else
//         {
//             if(f[i][2] != min)
//             {
//                 flag = 1;
//                 if(f[i][2] < min)
//                 {
//                     min = f[i][2];
//                     index = i;
//                 }
//             }
//         }
//     }

//     for(i=0; i<m; i++)
//     {
//         if(f[i][2] == min)
//             count++;
//     }

//     if(flag == 0)
//         return -1;
//     if(flag == 1 && count == 1)
//         return index;

//     int maxtc;
//     if(count > 1 && count < m)
//     {
//         for(i=0; i<m; i++)
//         {
//             if(f[i][2] == min)
//             {
//                 if(i == 0)
//                 {
//                     maxtc = f[i][1];
//                     index = i;
//                 }
//                 else if(f[i][1] > maxtc)
//                 {
//                     maxtc = f[i][1];
//                     index = i;
//                 }
//             }
//         }
//     }
//     return index;
// }

// int LRU(int m, int f[m][3])
// {
//     int i, max, index; 
//     for(i=0; i<m; i++)
//     {
//         if(i == 0)
//         {
//             max = f[i][1];
//             index = i;
//         }
//         else if(f[i][1] > max)
//         {
//             max = f[i][1];
//             index = i;
//         }
//     }
//     return index;
// }

// void line()
// {
//     int i;
//     printf("\n\t");
//     for(i=0; i<52; i++)
//     {
//         printf("_");
//     }
//     printf("\n\n");
// }

// void timecounter(int k, int m, int f[m][3], int flag)
// {
//     int i;
// 	for(i=0; i<m; i++)
// 	{
//         if(flag == 1 && f[i][0] != -1)
//             f[i][1]++;
//         else if(flag == 0 && f[i][0] != -1)
//         {
//             if(i == k)
//                 f[i][1] = 0;
//             else
//                 f[i][1]++;
//         }
// 	}    
// }

// int iterate(int n, int s[n], int freq[n][2], int m, int f[m][3])
// {
//     int i, newfreq, index, pf = 0;
//     printf("\n\tElement\t      Frames\t   Timecounter\t   Frequency\n\n");
//     for(i=0; i<n; i++)
//     {
//         newfreq = updatefreq(s[i],n,freq);
        
//         if(available(s[i],m,f) == -1)
//         {
//             pf++;
//             printf("!--");
//             if(hasSpace(m,f) != -1)
//             {
//                 index = hasSpace(m,f);
//             }
//             else
//             {
//                 if(checkFreq(m,f) == -1)
//                 {
//                     index = LRU(m,f);
//                 }
//                 else
//                 {
//                     index = checkFreq(m,f);
//                 }
//             }
//             f[index][0] = s[i];
//             timecounter(index,m,f,0);
//         }
//         else
//         {
//             index = available(s[i],m,f);
//             timecounter(index,m,f,1);
//         }  
//         f[index][2] = newfreq;
//         printF(s[i],m,f); 
//         line();     
//     }
//     return pf;
// }

// void main()
// {
//     int i, n, m=3, pf;
//     printf(" Enter the total number of page requests: ");
//     scanf("%d",&n);

//     int s[n], freq[n][2], f[m][3];
//     printf(" Enter the %d page requests: ",n);
//     for(i=0; i<n; i++)
//     {
//         scanf("%d",&s[i]);
//         freq[i][0] = -1;
//         freq[i][1] = 0;
//         if(s[i] < 0)
//         {
//             printf("\n\t!-- Page requests cannot be negative --!");
//             return;
//         }
//     }
// 	printf("\n Enter the no. of frames: ");
// 	scanf("%d",&m);
//     setdefault(m,f);
//     pf = iterate(n,s,freq,m,f);
//     printf("\n\tThe total number of page faults: %d\n",pf);
//      printf("Page miss ratio = %d/%d", pf,n );
// }


