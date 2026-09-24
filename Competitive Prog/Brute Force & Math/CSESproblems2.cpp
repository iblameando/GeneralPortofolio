#include  <iostream>
#include <vector>
using namespace std;

int main () {
	int N;
	cin >> N;
	
	vector<int> A(N-1);
	long long sum = 0;
	
	for (int i = 0; i < N-1; i++) {
		cin >> A[i];
		sum += A[i];
	}
	
	long long falsesum = static_cast<long long>(N) * (N + 1) / 2;
	
	cout << falsesum - sum;
}

