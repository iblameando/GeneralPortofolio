#include <iostream>
using namespace std;

int main () {
	int N;
	cin >> N;
	
	if (N == 3 || N == 2) {
		cout << "NO SOLUTION";
		return 0;
	}
	
	for (int i = 2; i <= N; i += 2) {
		cout << i << " ";
	}
	
	for (int i = 1; i <= N; i += 2) {
		cout << i << " ";
	}
}
