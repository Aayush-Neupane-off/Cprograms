// FIFO Disk Scheduling
// #include <stdio.h>
// #include <stdlib.h>

// void fcfs_disk_schedule(int arr[], int n, int head) {
//     int total_seek_time = 0;
//     int current_head = head;
    
//     printf("Sequence of disk access: %d", current_head);
    
//     for (int i = 0; i < n; ++i) {
//         total_seek_time += abs(current_head - arr[i]);
//         current_head = arr[i];
//         printf(" -> %d", current_head);
//     }
    
//     printf("\nTotal Seek Time: %d\n", total_seek_time);
// }

// int main() {
//     int n;
//     printf("Enter the number of disk requests: ");
//     scanf("%d", &n);
    
//     int arr[n];
//     printf("Enter the disk requests: ");
//     for (int i = 0; i < n; ++i) {
//         scanf("%d", &arr[i]);
//     }
    
//     int head;
//     printf("Enter the initial position of the disk head: ");
//     scanf("%d", &head);
    
//     fcfs_disk_schedule(arr, n, head);
    
//     return 0;
// }

// SSTF
// #include <stdio.h>
// #include <stdlib.h>

// void sstf_disk_schedule(int arr[], int n, int head) {
//     int total_seek_time = 0;
//     int current_head = head;
//     int visited[n]; // Track visited requests
//     int sequence[n]; // Store sequence of accesses

//     // Initialize visited array
//     for (int i = 0; i < n; ++i) {
//         visited[i] = 0;
//     }

//     // Iterate through all requests
//     for (int i = 0; i < n; ++i) {
//         int min_distance = 999;
//         int nearest_index = -1;

//         // Find the nearest unvisited request to the current head
//         for (int j = 0; j < n; ++j) {
//             if (!visited[j]) {
//                 int distance = abs(current_head - arr[j]);
//                 if (distance < min_distance) {
//                     min_distance = distance;
//                     nearest_index = j;
//                 }
//             }
//         }

//         // Update total seek time and head position
//         total_seek_time += min_distance;
//         current_head = arr[nearest_index];
//         visited[nearest_index] = 1;
//         sequence[i] = current_head; // Store the accessed disk

//         // Print the sequence of accesses
//         printf(" -> %d", current_head);
//     }

//     printf("\nTotal Seek Time: %d\n", total_seek_time);
// }

// int main() {
//     int n;
//     printf("Enter the number of disk requests: ");
//     scanf("%d", &n);

//     int arr[n];
//     printf("Enter the disk requests: ");
//     for (int i = 0; i < n; ++i) {
//         scanf("%d", &arr[i]);
//     }

//     int head;
//     printf("Enter the initial position of the disk head: ");
//     scanf("%d", &head);

//     printf("Sequence of disk access:");
//     sstf_disk_schedule(arr, n, head);

//     return 0;
// }

//  WAP to simulate SCAN Disk Scheduling Algorithm
// #include <stdio.h>
// #include <stdlib.h>

// void sort(int arr[], int n) {
//     int temp;
//     for (int i = 0; i < n-1; i++) {
//         for (int j = 0; j < n-i-1; j++) {
//             if (arr[j] > arr[j+1]) {
//                 temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }
// }

// void scan(int requests[], int n, int head, int disk_size, int direction) {
//     int total_seek_operations = 0;
//     int seek_sequence[n + 2]; // Extra space for the end points
//     int distance, cur_track;
//     int index = 0;
    
//     // Sort the request array
//     sort(requests, n);
    
//     // Find the index of the first request that is greater than the head
//     for (int i = 0; i < n; i++) {
//         if (requests[i] > head) {
//             index = i;
//             break;
//         }
//     }
    
//     int seq_index = 0;

//     // Scan towards left (decreasing)
//     if (direction == 0) {
//         // Move towards left end
//         for (int i = index - 1; i >= 0; i--) {
//             cur_track = requests[i];
//             seek_sequence[seq_index++] = cur_track;
//             distance = abs(cur_track - head);
//             total_seek_operations += distance;
//             head = cur_track;
//         }
        
//         // Move to the beginning of the disk
//         seek_sequence[seq_index++] = 0;
//         distance = head; // Distance to 0 from current head
//         total_seek_operations += distance;
//         head = 0;

//         // After reaching the left end, reverse the direction
//         for (int i = index; i < n; i++) {
//             cur_track = requests[i];
//             seek_sequence[seq_index++] = cur_track;
//             distance = abs(cur_track - head);
//             total_seek_operations += distance;
//             head = cur_track;
//         }
//     }
//     // Scan towards right (increasing)
//     else {
//         // Move towards right end
//         for (int i = index; i < n; i++) {
//             cur_track = requests[i];
//             seek_sequence[seq_index++] = cur_track;
//             distance = abs(cur_track - head);
//             total_seek_operations += distance;
//             head = cur_track;
//         }
        
//         // Move to the end of the disk
//         seek_sequence[seq_index++] = disk_size - 1;
//         distance = abs(disk_size - 1 - head);
//         total_seek_operations += distance;
//         head = disk_size - 1;

//         // After reaching the right end, reverse the direction
//         for (int i = index - 1; i >= 0; i--) {
//             cur_track = requests[i];
//             seek_sequence[seq_index++] = cur_track;
//             distance = abs(cur_track - head);
//             total_seek_operations += distance;
//             head = cur_track;
//         }
//     }

//     printf("Total seek operations: %d\n", total_seek_operations);
//     printf("Seek sequence: ");
//     for (int i = 0; i < seq_index; i++) {
//         printf("%d ", seek_sequence[i]);
//     }
//     printf("\n");
// }

// int main() {
//     int n, head, disk_size, direction;
    
//     printf("Enter the number of requests: ");
//     scanf("%d", &n);
    
//     int requests[n];
//     printf("Enter the request sequence: ");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &requests[i]);
//     }
    
//     printf("Enter the initial head position: ");
//     scanf("%d", &head);
    
//     printf("Enter the total disk size: ");
//     scanf("%d", &disk_size);
    
//     printf("Enter the direction (0 for left, 1 for right): ");
//     scanf("%d", &direction);
    
//     scan(requests, n, head, disk_size, direction);
    
//     return 0;
// }


// WAP to simulate C-SCAN Disk Scheduling Algorithm 
// #include <stdio.h>
// #include <stdlib.h>

// void sort(int arr[], int n) {
//     int temp;
//     for (int i = 0; i < n-1; i++) {
//         for (int j = 0; j < n-i-1; j++) {
//             if (arr[j] > arr[j+1]) {
//                 temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }
// }

// void cscan(int requests[], int n, int head, int disk_size) {
//     int total_seek_operations = 0;
//     int seek_sequence[n + 2]; // Extra space for the end points
//     int distance, cur_track;
//     int index = 0;
    
//     // Sort the request array
//     sort(requests, n);
    
//     // Find the index of the first request that is greater than the head
//     for (int i = 0; i < n; i++) {
//         if (requests[i] > head) {
//             index = i;
//             break;
//         }
//     }
    
//     int seq_index = 0;

//     // Move towards the right end
//     for (int i = index; i < n; i++) {
//         cur_track = requests[i];
//         seek_sequence[seq_index++] = cur_track;
//         distance = abs(cur_track - head);
//         total_seek_operations += distance;
//         head = cur_track;
//     }

//     // Move to the end of the disk
//     seek_sequence[seq_index++] = disk_size - 1;
//     distance = abs(disk_size - 1 - head);
//     total_seek_operations += distance;
//     head = disk_size - 1;

//     // Jump to the beginning of the disk
//     seek_sequence[seq_index++] = 0;
//     distance = disk_size - 1; // Distance to 0 from the end
//     total_seek_operations += distance;
//     head = 0;

//     // Continue moving towards the right from the beginning
//     for (int i = 0; i < index; i++) {
//         cur_track = requests[i];
//         seek_sequence[seq_index++] = cur_track;
//         distance = abs(cur_track - head);
//         total_seek_operations += distance;
//         head = cur_track;
//     }

//     printf("Total seek operations: %d\n", total_seek_operations);
//     printf("Seek sequence: ");
//     for (int i = 0; i < seq_index; i++) {
//         printf("%d ", seek_sequence[i]);
//     }
//     printf("\n");
// }

// int main() {
//     int n, head, disk_size;
    
//     printf("Enter the number of requests: ");
//     scanf("%d", &n);
    
//     int requests[n];
//     printf("Enter the request sequence: ");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &requests[i]);
//     }
    
//     printf("Enter the initial head position: ");
//     scanf("%d", &head);
    
//     printf("Enter the total disk size: ");
//     scanf("%d", &disk_size);
    
//     cscan(requests, n, head, disk_size);
    
//     return 0;
// }

// WAP to simulate LOOK Disk Scheduling Algorithm
// #include <stdio.h>
// #include <stdlib.h>

// void sort(int arr[], int n) {
//     int temp;
//     for (int i = 0; i < n-1; i++) {
//         for (int j = 0; j < n-i-1; j++) {
//             if (arr[j] > arr[j+1]) {
//                 temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }
// }

// void look(int requests[], int n, int head, int direction) {
//     int total_seek_operations = 0;
//     int seek_sequence[n];
//     int distance, cur_track;
//     int index = 0;
    
//     // Sort the request array
//     sort(requests, n);
    
//     // Find the index of the first request that is greater than the head
//     for (int i = 0; i < n; i++) {
//         if (requests[i] > head) {
//             index = i;
//             break;
//         }
//     }
    
//     int seq_index = 0;

//     // Scan towards left (decreasing)
//     if (direction == 0) {
//         // Move towards left end
//         for (int i = index - 1; i >= 0; i--) {
//             cur_track = requests[i];
//             seek_sequence[seq_index++] = cur_track;
//             distance = abs(cur_track - head);
//             total_seek_operations += distance;
//             head = cur_track;
//         }

//         // After reaching the leftmost request, reverse the direction
//         for (int i = index; i < n; i++) {
//             cur_track = requests[i];
//             seek_sequence[seq_index++] = cur_track;
//             distance = abs(cur_track - head);
//             total_seek_operations += distance;
//             head = cur_track;
//         }
//     }
//     // Scan towards right (increasing)
//     else {
//         // Move towards right end
//         for (int i = index; i < n; i++) {
//             cur_track = requests[i];
//             seek_sequence[seq_index++] = cur_track;
//             distance = abs(cur_track - head);
//             total_seek_operations += distance;
//             head = cur_track;
//         }

//         // After reaching the rightmost request, reverse the direction
//         for (int i = index - 1; i >= 0; i--) {
//             cur_track = requests[i];
//             seek_sequence[seq_index++] = cur_track;
//             distance = abs(cur_track - head);
//             total_seek_operations += distance;
//             head = cur_track;
//         }
//     }

//     printf("Total seek operations: %d\n", total_seek_operations);
//     printf("Seek sequence: ");
//     for (int i = 0; i < seq_index; i++) {
//         printf("%d ", seek_sequence[i]);
//     }
//     printf("\n");
// }

// int main() {
//     int n, head, direction;
    
//     printf("Enter the number of requests: ");
//     scanf("%d", &n);
    
//     int requests[n];
//     printf("Enter the request sequence: ");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &requests[i]);
//     }
    
//     printf("Enter the initial head position: ");
//     scanf("%d", &head);
    
//     printf("Enter the direction (0 for left, 1 for right): ");
//     scanf("%d", &direction);
    
//     look(requests, n, head, direction);
    
//     return 0;
// }

//WAP to simulate C-LOOK Disk Scheduling Algorithm
// #include <stdio.h>
// #include <stdlib.h>

// void sort(int arr[], int n) {
//     int temp;
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n - i - 1; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
// }

// void clook(int requests[], int n, int head) {
//     int total_seek_operations = 0;
//     int seek_sequence[n];
//     int distance, cur_track;
//     int index = 0;

//     // Sort the request array
//     sort(requests, n);

//     // Find the index of the first request that is greater than the head
//     for (int i = 0; i < n; i++) {
//         if (requests[i] > head) {
//             index = i;
//             break;
//         }
//     }

//     int seq_index = 0;

//     // Move towards the right end
//     for (int i = index; i < n; i++) {
//         cur_track = requests[i];
//         seek_sequence[seq_index++] = cur_track;
//         distance = abs(cur_track - head);
//         total_seek_operations += distance;
//         head = cur_track;
//     }

//     // Jump to the beginning of the request queue
//     for (int i = 0; i < index; i++) {
//         cur_track = requests[i];
//         seek_sequence[seq_index++] = cur_track;
//         distance = abs(cur_track - head);
//         total_seek_operations += distance;
//         head = cur_track;
//     }

//     printf("Total seek operations: %d\n", total_seek_operations);
//     printf("Seek sequence: ");
//     for (int i = 0; i < seq_index; i++) {
//         printf("%d ", seek_sequence[i]);
//     }
//     printf("\n");
// }

// int main() {
//     int n, head;

//     printf("Enter the number of requests: ");
//     scanf("%d", &n);

//     int requests[n];
//     printf("Enter the request sequence: ");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &requests[i]);
//     }

//     printf("Enter the initial head position: ");
//     scanf("%d", &head);

//     clook(requests, n, head);

//     return 0;
// }
