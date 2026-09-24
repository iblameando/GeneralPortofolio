#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

bool isValid(string s, int B) {
    if (s.empty()) return false;
    if (s.size() > 1 && s[0] == '0') return false;
    long long val = 0;
    for (char c : s) {
        val = val * 10 + (c - '0');
        if (val >= B) return false;
    }
    return true;
}

int main() {
    int B;
    string Y;
    cin >> B >> Y;

    int N = Y.size();
    vector<int> dp(N + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= N; ++i) {
        for (int len = 1; len <= 6 && len <= i; ++len) {
            string token = Y.substr(i - len, len);
            if (isValid(token, B)) {
                dp[i] = (dp[i] + dp[i - len]) % MOD;
            }
        }
    }

    cout << dp[N] << endl;
    return 0;
}

