#include <iostream>

using namespace std;

void calculate_combinations(int h1, int h2, int b1, int b2, int x, int y) {
    // Array to store results
    const int max_combinations = 100; // Assume maximum combinations for simplicity
    int combinations[max_combinations][3]; // Each row stores: h1_x, h2_x, type
    int count = 0;

    // Case 1: h1-b1 and h2-b2
    for (int h1_b1 = 0; h1_b1 <= h1 && h1_b1 <= b1; h1_b1++) {
        for (int h2_b2 = 0; h2_b2 <= h2 && h2_b2 <= b2; h2_b2++) {
            if (h1_b1 + h2_b2 <= x) {
                combinations[count][0] = h1_b1;
                combinations[count][1] = h2_b2;
                combinations[count][2] = 1; // Type 1: h1-b1 & h2-b2
                count++;
            }
        }
    }

    // Case 2: h1-b2 and h2-b1
    for (int h1_b2 = 0; h1_b2 <= h1 && h1_b2 <= b2; h1_b2++) {
        for (int h2_b1 = 0; h2_b1 <= h2 && h2_b1 <= b1; h2_b1++) {
            if (h1_b2 + h2_b1 <= y) {
                combinations[count][0] = h1_b2;
                combinations[count][1] = h2_b1;
                combinations[count][2] = 2; // Type 2: h1-b2 & h2-b1
                count++;
            }
        }
    }

    // Display results
    cout << "Pair Count | Pair Type" << endl;
    cout << "------------------------" << endl;
    for (int i = 0; i < count; i++) {
        cout << "(" << combinations[i][0] << ", " << combinations[i][1] << ") | ";
        if (combinations[i][2] == 1) {
            cout << "h1-b1 & h2-b2" << endl;
        } else {
            cout << "h1-b2 & h2-b1" << endl;
        }
    }
}

int main() {
    int h1 = 3, h2 = 2, b1 = 3, b2 = 2; // Input values
    int x = 4, y = 3;                  // Constraints

    calculate_combinations(h1, h2, b1, b2, x, y);

    return 0;
}