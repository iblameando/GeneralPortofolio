// Cyclic Algorithm Implementation

#include <bits/stdc++.h>
#define hatsune ios::sync_with_stdio(0);
#define miku cin.tie(0);
using namespace std;

int main() {
    hatsune miku
    long long N;
    // Reads the number of positions to rotate.
    cin >> N;

    // Stores the two circular sequences that will be rotated.
    char A1[3] = {'A', 'B', 'C'};
    char A2[5] = {'A', 'B', 'C', 'D', 'E'};

    // Finds each sequence's starting index using the remainder after rotation.
    int shift1 = N % 3;
    int shift2 = N % 5;

    // Prints the three-character sequence starting from its rotated position.
    for (int i = 0; i < 3; i++) {
        // Modulo makes the index wrap back to the beginning of the sequence.
        cout << A1[(shift1 + i) % 3] << " ";
    }
    // Moves the output to the next line before printing the second sequence.
    cout << endl;

    // Prints the five-character sequence starting from its rotated position.
    for (int i = 0; i < 5; i++) {
        // Modulo makes the index wrap back to the beginning of the sequence.
        cout << A2[(shift2 + i) % 5] << " ";
    }
}
