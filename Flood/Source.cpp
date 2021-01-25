#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n, m;
    while (cin >> n && n) {
        set<string> name;
        cin >> m;
        for (int i = 0; i < n; i++) {
            string temp;
            cin >> temp;
            for (int j = 0; temp[j] != '\0'; j++) {
                if (temp[j] >= 'A' && temp[j] <= 'Z') temp[j] += 32;
            }
            name.insert(temp);
        }
        set<string> sent;
        for (int i = 0; i < m; i++) {
            string temp;
            cin >> temp;
            for (int j = 0; temp[j] != '\0'; j++) {
                if (temp[j] >= 'A' && temp[j] <= 'Z') temp[j] += 32;
            }
            if (name.find(temp) == name.end()) continue;
            sent.insert(temp);
        }
        cout << n - sent.size() << endl;
    }
    return 0;
}
