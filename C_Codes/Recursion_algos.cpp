// TOH
// #include <iostream>

// void TowerOfHanoi(int n, char source, char target, char auxiliary) {
//     if (n > 0) {
//         TowerOfHanoi(n - 1, source, auxiliary, target);
//         std::cout << "Move disk " << n << " from " << source << " to " << target << std::endl;
//         TowerOfHanoi(n - 1, auxiliary, target, source);
//     }
// }

// int main() {
//     int numDisks;
//     std::cout << "Enter the number of disks: ";
//     std::cin >> numDisks;
//     TowerOfHanoi(numDisks, 'A', 'C', 'B');
//     return 0;
// }

//GCD
#include <iostream>

using namespace std;

// GCD function using Euclidean Algorithm
int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main() {
    int first_number, second_number;
    cout << "Enter First Number : ";
    cin >> first_number;
    cout << "Enter Second Number: ";
    cin >> second_number;

    // Display the GCD
    cout << "Greatest Common Divisor (GCD): ";
    cout << gcd(first_number, second_number) << endl << endl;
    return 0;
}
