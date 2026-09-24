#include <iostream>
#include <string>
using namespace std;

string S;

int cek(string pola) {
    int j = 0;
    int ans = 0;
    for (int i = 0; i < S.length(); i++){
        if (S[i] == pola[j]){
            ans++;
            j++;
            j %= 3;
        }
    }
    return ans;
}
    
int main () {
	cin >> S;
	int maxx = 0;
    maxx = max(maxx, cek("OSN"));
    maxx = max(maxx, cek("ONS"));
    maxx = max(maxx, cek("SON"));
    maxx = max(maxx, cek("SNO"));
    maxx = max(maxx, cek("NOS"));
	maxx = max(maxx, cek("NSO"));
    if (maxx < 3){
        cout << -1;
    } else {
        cout << maxx;
	}		
}
