// #include <stdio.h>

// struct Process {
//     int id;
//     int arrival_time;
//     int burst_time;
// };

// float calculateAverageTurnaroundTime(struct Process processes[], int n) {
//     float total_turnaround_time = 0;
//     for (int i = 0; i < n; i++) {
//         total_turnaround_time += processes[i].burst_time;
//     }
//     return total_turnaround_time / n;
// }

// float calculateAverageWaitingTime(struct Process processes[], int n) {
//     float total_waiting_time = 0;
//     int current_time = 0; // Initialize current time

//     for (int i = 0; i < n; i++) {
//         // Calculate waiting time (time spent waiting before execution starts)
//         int waiting_time = current_time - processes[i].arrival_time;
//         if (waiting_time < 0) {
//             // If the process arrives after the current time, adjust waiting time
//             waiting_time = 0;
//             current_time = processes[i].arrival_time;
//         }
//         total_waiting_time += waiting_time;

//         // Calculate completion time
//         int completion_time = current_time + processes[i].burst_time;

//         // Update current time
//         current_time = completion_time;
//     }
//     return total_waiting_time / n;
// }

// void simulateFCFS(struct Process processes[], int n) {
//     int current_time = 0;
//     printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tResponse Time\tTurnaround Time\n");
//     for (int i = 0; i < n; i++) {
//         // Calculate waiting time (time spent waiting before execution starts)
//         int waiting_time = current_time - processes[i].arrival_time;
//         if (waiting_time < 0) {
//             // If the process arrives after the current time, adjust waiting time
//             waiting_time = 0;
//             current_time = processes[i].arrival_time;
//         }

//         // Calculate completion time
//         int completion_time = current_time + processes[i].burst_time;
//         // Calculate response time (same as waiting time for FCFS)
//         int response_time = waiting_time;
//         // Calculate turnaround time
//         int turnaround_time = completion_time - processes[i].arrival_time;

//         printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time,
//                processes[i].burst_time, completion_time, waiting_time, response_time, turnaround_time);

//         // Update current time
//         current_time = completion_time;
//     }
// }

// int main() {
//     int n;
//     printf("Enter the number of processes: ");
//     scanf("%d", &n);

//     struct Process processes[n];
//     for (int i = 0; i < n; i++) {
//         printf("Enter details for process %d:\n", i + 1);
//         processes[i].id = i + 1;
//         printf("Arrival time: ");
//         scanf("%d", &processes[i].arrival_time);
//         printf("Burst time: ");
//         scanf("%d", &processes[i].burst_time);
//     }

//     // Simulate FCFS scheduling
//     simulateFCFS(processes, n);

//     float avg_turnaround_time = calculateAverageTurnaroundTime(processes, n);
//     float avg_waiting_time = calculateAverageWaitingTime(processes, n);

//     printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
//     printf("Average Waiting Time: %.2f\n", avg_waiting_time);

//     return 0;
// }

//SJF
// #include<stdio.h>
// #include<stdlib.h>
// void swap(int *x, int *y)
// {
//     int temp=*x;
//     *x=*y;
//     *y=temp;
// }
// void sortat(int p[], int at[], int bt[], int n)
// {
//   int i, j;
//   for(i=0;i<n;i++)
//   {
//       for(j=i+1;j<n;j++)
//       {   /* sort the process having less arrival*/
// 	  if(at[i]>at[j])
// 	  { 
// 	        swap(&p[i], &p[j]);
// 		swap(&at[i], &at[j]);
// 		swap(&bt[i], &bt[j]);
// 	   }
//            /* if two processes have the same arrival time than sort them having less burst time */
// 	   else if(at[i]==at[j])
// 	   {
// 	      if(bt[i]>bt[j])
//                  swap(&p[i], &p[j]);
//                  swap(&at[i], &at[j]);
//                  swap(&bt[i], &bt[j]);
// 	   }
//        }
//   }
// }
// /* calculate turnaround time and waiting time */
// void tatwt( int ct[], int at[], int bt[], int tat[], int wt[], int n)
// {
//    int i;
//    for(i=0;i<n;i++)
//    {
// 	tat[i]=ct[i]-at[i];
// 	wt[i]=tat[i]-bt[i];
//    }
// }
// int main()
// {
//   int *p, *at, *bt, *tat, *wt, *ct, pos, i, j, min=1000, n;
//   float awt=0, atat=0;
//   printf("\nenter the number of process:");
//   scanf("%d", &n);
//   p=(int*)malloc(n*sizeof(int));
//   at=(int*)malloc(n*sizeof(int));
//   bt=(int*)malloc(n*sizeof(int));
//   ct=(int*)malloc(n*sizeof(int));
//   wt=(int*)malloc(n*sizeof(int));
//   tat=(int*)malloc(n*sizeof(int));
//   printf("enter the process");
//   for(i=0;i<n;i++)
//   {
// 	scanf("%d",&p[i]);
//   }
//   printf("enter the arrival time");
//   for(i=0;i<n;i++)
//   {
// 	scanf("%d",&at[i]);
//   }
//   printf("enter the burst time");
//   for(i=0;i<n;i++)
//   {
// 	scanf("%d",&bt[i]);
//   }
//   sortat(p, at, bt, n);
//   ct[0]=at[0] + bt[0];
//   for(i=1; i<n; i++)
//   {
// 	for(j=i; j<n; j++)
// 	{
// 	    if(at[j]<=ct[i-1])
// 	   {
//               if(bt[j]<min)
//               {
//                  min=bt[j];
//                  pos=j;
//               }
// 	   }
// 	}
//    /*  when you get less burst time process, swap p, at, bt at position 2,
//     and when getting 2nd less burst time swap at position 3rd and so on.  */
//     swap(&p[i], &p[pos]);
//     swap(&at[i], &at[pos]);
//     swap(&bt[i], &bt[pos]);
//     min=1000;
//     ct[i]=ct[i-1]+bt[i];
//   }
//   tatwt(ct, at, bt, tat, wt, n);
//   printf("\np\t at\t bt\t ct\t tat\t wt"); 
//   for(i=0;i<n;i++)
//   {
//     printf("\n%d\t %d\t %d\t %d\t %d\t %d",p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
//   }
//   for(i=0;i<n;i++)
//   { 
//     atat+=tat[i];
//     awt+=wt[i];
//   }
//   // average turnaround time and average waiting time
//   atat=atat/n;
//   awt=awt/n;
//   printf("\n avg tat=%.2f and avg wt=%.2f",atat, awt); 
//   return 0;
// }

//SRTF
// #include <stdio.h>

// struct Process {
//     int id;
//     int arrival_time;
//     int burst_time;
//     int remaining_time; // Remaining burst time
// };

// void simulateSRTF(struct Process processes[], int n) {
//     int current_time = 0;
//     int completed = 0; // Number of completed processes
//     int total_turnaround_time = 0;
//     int total_waiting_time = 0;

//     printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");

//     while (completed < n) {
//         int shortest_index = -1;
//         int shortest_time = 999999; // Initialize with a large value

//         // Find the process with the shortest remaining time
//         for (int i = 0; i < n; i++) {
//             if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
//                 if (processes[i].remaining_time < shortest_time) {
//                     shortest_time = processes[i].remaining_time;
//                     shortest_index = i;
//                 }
//             }
//         }

//         if (shortest_index == -1) {
//             current_time++; // No process to execute, move to the next time unit
//             continue;
//         }

//         // Execute the process with the shortest remaining time
//         processes[shortest_index].remaining_time--;
//         current_time++;

//         if (processes[shortest_index].remaining_time == 0) {
//             completed++;
//             int completion_time = current_time;
//             int turnaround_time = completion_time - processes[shortest_index].arrival_time;
//             int waiting_time = turnaround_time - processes[shortest_index].burst_time;

//             total_turnaround_time += turnaround_time;
//             total_waiting_time += waiting_time;

//             printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[shortest_index].id,
//                    processes[shortest_index].arrival_time, processes[shortest_index].burst_time,
//                    completion_time, waiting_time, turnaround_time);
//         }
//     }

//     float avg_turnaround_time = (float)total_turnaround_time / n;
//     float avg_waiting_time = (float)total_waiting_time / n;

//     printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
//     printf("Average Waiting Time: %.2f\n", avg_waiting_time);
// }

// int main() {
//     int n;
//     printf("Enter the number of processes: ");
//     scanf("%d", &n);

//     struct Process processes[n];
//     for (int i = 0; i < n; i++) {
//         printf("Enter details for process %d:\n", i + 1);
//         processes[i].id = i + 1;
//         printf("Arrival time: ");
//         scanf("%d", &processes[i].arrival_time);
//         printf("Burst time: ");
//         scanf("%d", &processes[i].burst_time);
//         processes[i].remaining_time = processes[i].burst_time;
//     }

//     // Simulate SRTF scheduling
//     simulateSRTF(processes, n);

//     return 0;
// }

//RR
// #include <stdio.h>

// struct Process {
//     int id;
//     int arrival_time;
//     int burst_time;
//     int remaining_time; // Remaining burst time
// };

// void simulateRoundRobin(struct Process processes[], int n, int time_quantum) {
//     int current_time = 0;
//     int completed = 0; // Number of completed processes
//     int total_turnaround_time = 0;
//     int total_waiting_time = 0;

//     printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");

//     while (completed < n) {
//         for (int i = 0; i < n; i++) {
//             if (processes[i].remaining_time > 0) {
//                 int execute_time = (processes[i].remaining_time < time_quantum) ? processes[i].remaining_time : time_quantum;

//                 processes[i].remaining_time -= execute_time;
//                 current_time += execute_time;

//                 if (processes[i].remaining_time == 0) {
//                     completed++;
//                     int completion_time = current_time;
//                     int turnaround_time = completion_time - processes[i].arrival_time;
//                     int waiting_time = turnaround_time - processes[i].burst_time;

//                     total_turnaround_time += turnaround_time;
//                     total_waiting_time += waiting_time;

//                     printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id,
//                            processes[i].arrival_time, processes[i].burst_time,
//                            completion_time, waiting_time, turnaround_time);
//                 }
//             }
//         }
//     }

//     float avg_turnaround_time = (float)total_turnaround_time / n;
//     float avg_waiting_time = (float)total_waiting_time / n;

//     printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
//     printf("Average Waiting Time: %.2f\n", avg_waiting_time);
// }

// int main() {
//     int n, time_quantum;
//     printf("Enter the number of processes: ");
//     scanf("%d", &n);
//     printf("Enter the time quantum: ");
//     scanf("%d", &time_quantum);

//     struct Process processes[n];
//     for (int i = 0; i < n; i++) {
//         printf("Enter details for process %d:\n", i + 1);
//         processes[i].id = i + 1;
//         printf("Arrival time: ");
//         scanf("%d", &processes[i].arrival_time);
//         printf("Burst time: ");
//         scanf("%d", &processes[i].burst_time);
//         processes[i].remaining_time = processes[i].burst_time;
//     }

//     // Simulate Round Robin scheduling
//     simulateRoundRobin(processes, n, time_quantum);

//     return 0;
// }

//PREEMITIVE PRIORITY SCHEDULING

// #include <stdio.h>

// // Structure to represent a process
// struct Process {
//     int processId;
//     int arrivalTime;
//     int burstTime;
//     int priority;
//     int completionTime;
//     int turnaroundTime;
//     int waitingTime;
//     int responseTime;
// };

// // Function to sort processes based on priority (non-decreasing order) using bubble sort
// void sortProcesses(struct Process processes[], int n) {
//     // Implementation of bubble sort (similar to previous code)
//     for (int i = 0; i < n - 1; ++i) {
//         for (int j = 0; j < n - i - 1; ++j) {
//             if (processes[j].priority > processes[j + 1].priority) {
//                 // Swap processes[j] and processes[j + 1]
//                 struct Process temp = processes[j];
//                 processes[j] = processes[j + 1];
//                 processes[j + 1] = temp;
//             }
//         }
//     }
// }

// int main() {
//     int n; // Number of processes
//     printf("Enter the number of processes: ");
//     scanf("%d", &n);

//     struct Process processes[n];
//     double totalTurnaroundTime = 0.0;
//     double totalWaitingTime = 0.0;
//     double totalResponseTime = 0.0;

//     // Input process details
//     for (int i = 0; i < n; ++i) {
//         printf("Enter details for process %d:\n", i + 1);
//         processes[i].processId = i + 1;
//         printf("Arrival time: ");
//         scanf("%d", &processes[i].arrivalTime);
//         printf("Burst time: ");
//         scanf("%d", &processes[i].burstTime);
//         printf("Priority: ");
//         scanf("%d", &processes[i].priority);
//     }

//     // Sort processes based on priority
//     sortProcesses(processes, n);

//     // Calculate completion, turnaround, waiting, and response times
//     int currentTime = 0;
//     for (int i = 0; i < n; ++i) {
//         // Calculate waiting time
//         processes[i].waitingTime = currentTime - processes[i].arrivalTime;
//         if (processes[i].waitingTime < 0) {
//             processes[i].waitingTime = 0;
//         }

//         // Calculate turnaround time
//         processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;

//         // Calculate response time (same as waiting time for non-preemptive)
//         processes[i].responseTime = processes[i].waitingTime;

//         // Calculate completion time
//         processes[i].completionTime = currentTime + processes[i].burstTime;

//         // Update total times
//         totalTurnaroundTime += processes[i].turnaroundTime;
//         totalWaitingTime += processes[i].waitingTime;
//         totalResponseTime += processes[i].responseTime;

//         // Update current time
//         currentTime = processes[i].completionTime;
//     }

//     // Display process details in tabular form
//     printf("\nProcess\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\tResponse Time\n");
//     for (int i = 0; i < n; ++i) {
//         printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].processId,
//                processes[i].arrivalTime, processes[i].burstTime, processes[i].priority,
//                processes[i].completionTime, processes[i].turnaroundTime,
//                processes[i].waitingTime, processes[i].responseTime);
//     }

//     // Display average turnaround, waiting, and response times
//     printf("\nAverage Turnaround Time: %.2lf\n", totalTurnaroundTime / n);
//     printf("Average Waiting Time: %.2lf\n", totalWaitingTime / n);
//     printf("Average Response Time: %.2lf\n", totalResponseTime / n);

//     return 0;
// }

// NON Preemitive priority scheduling 
// #include <stdio.h>

// // Structure to represent a process
// struct Process {
//     int processId;
//     int arrivalTime;
//     int burstTime;
//     int priority;
//     int completionTime;
//     int turnaroundTime;
//     int waitingTime;
//     int responseTime;
// };

// // Function to sort processes based on priority (non-decreasing order) using bubble sort
// void sortProcesses(struct Process processes[], int n) {
//     for (int i = 0; i < n - 1; ++i) {
//         for (int j = 0; j < n - i - 1; ++j) {
//             if (processes[j].priority > processes[j + 1].priority) {
//                 // Swap processes[j] and processes[j + 1]
//                 struct Process temp = processes[j];
//                 processes[j] = processes[j + 1];
//                 processes[j + 1] = temp;
//             }
//         }
//     }
// }

// int main() {
//     int n; // Number of processes
//     printf("Enter the number of processes: ");
//     scanf("%d", &n);

//     struct Process processes[n];
//     double totalTurnaroundTime = 0.0;
//     double totalWaitingTime = 0.0;
//     double totalResponseTime = 0.0;

//     // Input process details
//     for (int i = 0; i < n; ++i) {
//         printf("Enter details for process %d:\n", i + 1);
//         processes[i].processId = i + 1;
//         printf("Arrival time: ");
//         scanf("%d", &processes[i].arrivalTime);
//         printf("Burst time: ");
//         scanf("%d", &processes[i].burstTime);
//         printf("Priority: ");
//         scanf("%d", &processes[i].priority);
//     }

//     // Sort processes based on priority
//     sortProcesses(processes, n);

//     // Calculate completion, turnaround, waiting, and response times
//     int currentTime = 0;
//     for (int i = 0; i < n; ++i) {
//         // Calculate waiting time
//         processes[i].waitingTime = currentTime - processes[i].arrivalTime;
//         if (processes[i].waitingTime < 0) {
//             processes[i].waitingTime = 0;
//         }

//         // Calculate turnaround time
//         processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;

//         // Calculate response time (same as waiting time for non-preemptive)
//         processes[i].responseTime = processes[i].waitingTime;

//         // Calculate completion time
//         processes[i].completionTime = currentTime + processes[i].burstTime;

//         // Update total times
//         totalTurnaroundTime += processes[i].turnaroundTime;
//         totalWaitingTime += processes[i].waitingTime;
//         totalResponseTime += processes[i].responseTime;

//         // Update current time
//         currentTime = processes[i].completionTime;
//     }

//     // Display process details in tabular form
//     printf("\nProcess\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\tResponse Time\n");
//     for (int i = 0; i < n; ++i) {
//         printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].processId,
//                processes[i].arrivalTime, processes[i].burstTime, processes[i].priority,
//                processes[i].completionTime, processes[i].turnaroundTime,
//                processes[i].waitingTime, processes[i].responseTime);
//     }

//     // Display average turnaround, waiting, and response times
//     printf("\nAverage Turnaround Time: %.2lf\n", totalTurnaroundTime / n);
//     printf("Average Waiting Time: %.2lf\n", totalWaitingTime / n);
//     printf("Average Response Time: %.2lf\n", totalResponseTime / n);

//     return 0;
// }
