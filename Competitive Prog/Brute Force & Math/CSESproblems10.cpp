#include <iostream>
#include <cmath>
using namespace std;

int main () {
	int N;
	cin >> N;
	
	int res;
	int count = 0;
	for (int i = 5; i <= N; i*=5) {
		res = floor(N/i);
		count += res;
	}
	
	cout << count;
	
}
