//
//  main.cpp
//  Isenbaev
//
//  Created by Nicholas.L.Y on 2016/5/9.
//  Copyright © 2016 廖颖泓. All rights reserved.
//
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <vld.h>
using namespace std;
const string god = "Isenbaev";
int main() {
    int n;
    cin >> n;
    map<string, set<string> > teammate;
    for (int i = 0; i < n; i++) {
        string s[3];
        for (int j = 0; j < 3; j++) cin >> s[j];
        for (int j = 0; j < 3; j++) {
            for (int k = 0; j < 3; j++) {
                if (j == k) continue;
                teammate[s[j]].insert(s[k]);
            }
        }
    }
    map<string, set<string> >::iterator iter;
    set<string>::iterator its;
    map<string, int> dis;
    for (iter = teammate.begin(); iter != teammate.end(); iter++) {
        dis[iter->first] = -1;
    }
    queue<string> q;
    set<string> all;
    if (teammate.find(god) != teammate.end()) {
        dis[god] = 0;
        q.push(god);
        all.insert(god);
    }
    while (!q.empty()) {
        string temp = q.front();
        q.pop();
        int temp_dis = dis[temp];
        for (its = teammate[temp].begin(); its != teammate[temp].end(); its++) {
            if (all.find(*its) != all.end()) continue;
            all.insert(*its);
            dis[*its] = temp_dis + 1;
            q.push(*its);
        }
    }
    map<string, int>::iterator it;
    for (it = dis.begin(); it != dis.end(); it++) {
        cout << it->first << ' ';
        if (it->second == -1) cout << "undefined" << endl;
        else cout << it->second << endl;
    }
    return 0;
}
