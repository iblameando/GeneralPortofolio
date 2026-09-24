#include <iostream>
#include <vector>
using namespace std;

int main () {
	int N;
	cin >> N;
	
	vector<int> A(N);
	long long count = 0;
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	for (int i = 1; i < N; i++) {
		if (A[i] < A[i-1]) {
			count += A[i-1] - A[i];
			A[i] = A[i-1];
		}
	}
	
	cout << count << endl;
}
