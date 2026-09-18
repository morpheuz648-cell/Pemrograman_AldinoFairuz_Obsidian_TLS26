#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string enkripsi(string pesan) {
    string hsl = "";
    int nilai_sblm = 0;
    
    for (size_t i = 0; i < pesan.length(); ++i) {
        char ch = toupper(pesan[i]);
        if (ch >= 'A' && ch <= 'Z') {
            int val = ch - 'A' + 1;
            int barunilai;
            if (i == 0) {
                barunilai = val;
            } else {
                barunilai = ((val - 1 + nilai_sblm) % 26) + 1;
            }
            hsl += (char)('A' + barunilai - 1);
            nilai_sblm = val;
        } else {
            hsl += pesan[i];
            nilai_sblm = 0;
        }
    }
    return hsl;
}

int main() {
    string pesan;
    cout << "Masukkan teks: ";
    getline(cin, pesan);
    
    cout << "Hasil sandi: " << enkripsi(pesan) << endl;
    
    return 0;
}