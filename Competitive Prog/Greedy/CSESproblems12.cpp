#include <bits/stdc++.h>
using namespace std;

string S;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S;

    map<char, int> freq;

    for (char c : S) freq[c]++;

    int odd = 0;
    char mid = 0;
    for (auto p : freq) {
        if (p.second % 2 != 0) {
            odd++;
            mid = p.first;
        }
    }

    if (odd > 1) {
        cout << "NO SOLUTION";
    } else {
        string half = "";

        for (auto p : freq) {
            half += string(p.second / 2, p.first);
        }

        string result = half;
        if (mid) result += mid;


        reverse(half.begin(), half.end());
        result += half;

        cout << result << '\n';
    }
}