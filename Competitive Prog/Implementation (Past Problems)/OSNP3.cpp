#include <iostream>
#include <vector>
using namespace std;

bool kayu(const vector<long long>& A, long long X, long long M) {
    long long total = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] > X) {
            total += (A[i] - X);
        }
    }
    return total >= M;
}

int main() {
    long long N, M;
    cin >> N >> M;

    vector<long long> A(N);
    long long maxH = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] > maxH) maxH = A[i];
    }

    long long low = 0, high = maxH;
    long long answer = -1;

    while (low <= high) {
        long long mid = (low + high) / 2;
        if (kayu(A, mid, M)) {
            answer = mid;  
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << answer << endl;
}

