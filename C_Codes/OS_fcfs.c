// #include <stdio.h>
// #include <stdlib.h>

// // Function to calculate total seek time using FCFS
// int fcfs_disk_scheduling(int requests[], int n, int initial_position) {
//     int current_position = initial_position;
//     int total_seek_time = 0;

//     for (int i = 0; i < n; i++) {
//         int seek_distance = abs(requests[i] - current_position);
//         total_seek_time += seek_distance;
//         current_position = requests[i];
//     }

//     return total_seek_time;
// }

// int main() {
//     int n; // Number of requests
//     printf("Enter the number of disk requests: ");
//     scanf("%d", &n);

//     int disk_requests[n]; // Array to store track numbers
//     printf("Enter the disk requests (track numbers):\n");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &disk_requests[i]);
//     }

//     int initial_head_position; // Initial position of the disk head
//     printf("Enter the initial head position: ");
//     scanf("%d", &initial_head_position);

//     int total_seek_time = fcfs_disk_scheduling(disk_requests, n, initial_head_position);
//     printf("Total seek time using FCFS: %d cylinders\n", total_seek_time);

//     return 0;
// }

