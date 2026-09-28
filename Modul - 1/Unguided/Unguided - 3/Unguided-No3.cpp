#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input : ";
    cin >> n;
    
    cout << "output :" << endl;
    
    for (int i = 0; i <= n; i++) {
        for (int s = 0; s < i * 2; s++) {
            cout << " ";
        }
        
        int angka = n - i;
        
        for (int j = angka; j >= 1; j--) {
            if (j != angka || i > 0) cout << " ";
            cout << j;
        }
        
        if (angka > 0) cout << " ";
        cout << "*";
        
        for (int j = 1; j <= angka; j++) {
            cout << " " << j;
        }
        
        cout << endl;
    }
    
    return 0;
}