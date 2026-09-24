// Caesar Cipher Brute Force
#include <iostream>
#include <string>
using namespace std;

string decrypt(string text, int k) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        // Shift each character backward by k positions
        char decrypted = (c - 'a' - k + 26) % 26 + 'a';
        result += decrypted;
    }
    return result;
}

int main() {
    // Read the encrypted text
    string cipher;
    cin >> cipher;

    // Try every possible Caesar Cipher key
    for (int k = 1; k < 26; k++) {
        string decrypted = decrypt(cipher, k);
        cout << "k = " << k << ": " << decrypted << endl;
    }

    return 0;
}