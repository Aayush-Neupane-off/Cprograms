#include <iostream>
using namespace std;

// Function prototypes
void BubbleSort(int *a, int n);
void InsertionSort(int *a, int n);
void SelectionSort(int *a, int n);
void MergeSort(int *a, int low, int high);
void Merge(int *a, int low, int high, int mid);
void QuickSort(int *a, int low, int high);
int Partition(int *a, int low, int high);

// Main function
int main() {
    int n, i, choice;
    cout << "Enter the number of data elements to be sorted: ";
    cin >> n;
    int *arr = new int[n];
    int *original = new int[n];

    for(i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
        original[i] = arr[i]; // Save a copy of original array for comparison
    }

    cout << "\nChoose a sorting algorithm:" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. Selection Sort" << endl;
    cout << "4. Merge Sort" << endl;
    cout << "5. Quick Sort" << endl;
    cout << "Enter your choice (1-5): ";
    cin >> choice;

    switch(choice) {
        case 1:
            BubbleSort(arr, n);
            break;
        case 2:
            InsertionSort(arr, n);
            break;
        case 3:
            SelectionSort(arr, n);
            break;
        case 4:
            MergeSort(arr, 0, n - 1);
            break;
        case 5:
            QuickSort(arr, 0, n - 1);
            break;
        default:
            cout << "Invalid choice" << endl;
            delete[] arr;
            delete[] original;
            return 1;
    }

    // Printing the sorted data.
    cout << "\nSorted Data: ";
    for (i = 0; i < n; i++)
        cout << "->" << arr[i];

    cout << endl;

    delete[] arr;
    delete[] original;
    return 0;
}

// Bubble Sort function
void BubbleSort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                // Swap a[j] and a[j + 1]
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }}}}

// Insertion Sort function
void InsertionSort(int *a, int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        /* Move elements of a[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

// Selection Sort function
void SelectionSort(int *a, int n) {
    int min_idx;
    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        int temp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = temp;
    }
}

// Merge Sort functions
void MergeSort(int *a, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, high, mid);
    }
}

void Merge(int *a, int low, int high, int mid) {
    int i, j, k, temp[high - low + 1];
    i = low;
    k = 0;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = a[i++];
    }
    while (j <= high) {
        temp[k++] = a[j++];
    }
    for (i = low; i <= high; i++) {
        a[i] = temp[i - low];
    }
}

// Quick Sort functions
void QuickSort(int *a, int low, int high) {
    if (low < high) {
        int pi = Partition(a, low, high);
        QuickSort(a, low, pi - 1);
        QuickSort(a, pi + 1, high);
    }
}

int Partition(int *a, int low, int high) {
    int pivot = a[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (a[j] < pivot) {
            i++; // increment index of smaller element
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return (i + 1);
}


