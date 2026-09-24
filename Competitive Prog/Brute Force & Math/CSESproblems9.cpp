#include <iostream>
using namespace std;

int main () {
	int N;
	cin >> N;
	
	long long res = 1;
	for (int i = 0; i < N; i++) {
		res = (res * 2) % 1000000007;
	}
	
	cout << res;
}
