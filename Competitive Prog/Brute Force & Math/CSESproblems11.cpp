#include <iostream>
#include <vector>
using namespace std;

int main () {
	int N;
	cin >> N;
	
	vector<pair<int, int> > A(N);
	
	for (int i = 0; i < N; i++) {
		cin >> A[i].first >> A[i].second;
	}
	
	for (int i = 0; i < N; i++) {
		int a = A[i].first;
		int b = A[i].second;
		
		if ((a + b) % 3 == 0 && min(a, b) * 2 >= max(a, b)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}	
}

