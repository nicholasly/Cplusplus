#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int **p = new int*[n];
    for (int i = 0; i < n; i++) {
        p[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
        }
    }
    bool flag = true;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += p[0][i];
    }
    for (int i = 0; i < n; i++) {
        int temp = 0;
        for (int j = 0; j < n; j++) {
            temp += p[i][j];
        }
        if (temp != sum) {
            flag = false;
            break;
        }
    }
    
    for (int i = 0; i < n; i++) {
        int temp = 0;
        for (int j = 0; j < n; j++) {
            temp += p[j][i];
        }
        if (temp != sum) {
            flag = false;
            break;
        }
    }
    
    int temp = 0;
    for (int i; i < n; i++) {
        temp += p[i][i];
    }
    if (temp != sum) flag = false;
    
    temp = 0;
    for (int i = 0; i < n; i++) {
        temp += p[i][n - i - 1];
    }
    if (temp != sum) flag = false;
    if (flag) cout << "Yes!" << endl;
    else cout << "No!" << endl;
    for (int i = 0; i < n; i++) {
        delete [] p[i];
    }
    delete [] p;
    return 0;
}

