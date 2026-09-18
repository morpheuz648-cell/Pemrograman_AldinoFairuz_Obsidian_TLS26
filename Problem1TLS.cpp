#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    
    cout << "Jumlah astronot (N): ";
    cin >> N;
    cout << "Nilai K awal: ";
    cin >> K;

    if (N <= 0) return 1;
    if (K < 2) K = 2;

    vector<int> astro;
    for (int i = 1; i <= N; ++i) {
        astro.push_back(i);
    }

    vector<int> gugur;
    int pos = 0;

    cout << "\n=== Log Eliminasi ===\n";

    while (astro.size() > 1) {
        int hapus = (pos + K - 1) % astro.size();
        int id = astro[hapus];
        
        gugur.push_back(id);
        
        cout << "Astronot " << id << " gugur (K awal=" << K << "). ";

        astro.erase(astro.begin() + hapus);
        pos = hapus;

        if (id % 2 == 0) {
            K += 2; 
        } else {
            K -= 1; 
            if (K < 2) K = 2;
        }
        cout << "K baru=" << K << "\n";
    }

    cout << "\n=== Hasil Akhir ===\n";
    cout << "Urutan gugur: ";
    for (size_t i = 0; i < gugur.size(); ++i) {
        cout << gugur[i] << (i == gugur.size() - 1 ? "" : ", ");
    }
    
    cout << "\nAstronot bertahan: " << astro[0] << "\n";

    return 0;
}