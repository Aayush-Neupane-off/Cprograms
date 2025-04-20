#include <stdio.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
};

float calculateAverageTurnaroundTime(struct Process processes[], int n) {
    float total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_turnaround_time += processes[i].burst_time;
    }
    return total_turnaround_time / n;
}

float calculateAverageWaitingTime(struct Process processes[], int n) {
    float total_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += total_waiting_time + processes[i].burst_time;
    }
    return total_waiting_time / n;
}

void simulateFCFS(struct Process processes[], int n) {
    int current_time = 0;
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tResponse Time\n");
    for (int i = 0; i < n; i++) {
        // Calculate completion time
        int completion_time = current_time + processes[i].burst_time;
        // Calculate waiting time
        int waiting_time = current_time - processes[i].arrival_time;
        // Calculate response time (same as waiting time for FCFS)
        int response_time = waiting_time;

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time,
               processes[i].burst_time, completion_time, waiting_time, response_time);

        // Update current time
        current_time = completion_time;
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter details for process %d:\n", i + 1);
        processes[i].id = i + 1;
        printf("Arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    // Simulate FCFS scheduling
    simulateFCFS(processes, n);

    float avg_turnaround_time = calculateAverageTurnaroundTime(processes, n);
    float avg_waiting_time = calculateAverageWaitingTime(processes, n);

    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);

    return 0;
}
