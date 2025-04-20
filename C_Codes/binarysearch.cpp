#include <iostream>
using namespace std;

class BS {
public:
    void BinarySearch(int array[], int num, int keynum) {
        int low = 0;
        int high = num - 1;
        int mid;

        while (low <= high) {
            mid = low + (high - low) / 2; // to avoid potential overflow
            if (keynum < array[mid]) {
                high = mid - 1;
            } else if (keynum > array[mid]) {
                low = mid + 1;
            } else {
                cout << "SEARCH SUCCESSFUL at index " << mid << endl;
                return;
            }
        }

        cout << "SEARCH FAILED" << endl;
    }

    /*
    * Bubble Sort function
    */
    void BubbleSort(int array[], int num) {
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < (num - i - 1); j++) {
                if (array[j] > array[j + 1]) {
                    // Swap elements
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }
};

int main() {
    int num, keynum;

    cout << "Enter the number of elements: ";
    cin >> num;

    if (num <= 0) {
        cout << "Invalid number of elements. Exiting program." << endl;
        return 1;
    }

    int array[100]; // Assuming a maximum of 100 elements (adjust as needed)

    cout << "Enter the elements in ascending order:" << endl;
    for (int i = 0; i < num; i++) {
        cin >> array[i];
    }

    // Sort the array using Bubble Sort
    BS b1;
    b1.BubbleSort(array, num);

    cout << "Enter the element to be searched: ";
    cin >> keynum;

    // Perform binary search on the sorted array
    b1.BinarySearch(array, num, keynum);

    return 0;
}
