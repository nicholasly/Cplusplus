#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int startx, starty, endx, endy;
int used[9][9];
int mov[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};

static int i = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

struct node {
    int x, y;
};

bool issafe(int x, int y) {
    return (x > 0 && y > 0 && x <= 8 && y <= 8 && used[x][y] == 0);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        char a, b;
        cin >> a >> startx;
        starty = a - 'b';
        cin >> b >> endx;
        endy = b - 'b';
        
        node no;
        no.x = startx;
        no.y = starty;
        int step = 0, flag = 0;

        vector<node> v[64];
        v[0].push_back(no);
        memset(used, 0, sizeof(used));
        used[startx][starty] = 1;

        if (startx != endx || starty != endy) {
            while (1) {
                vector<node>::iterator it;
                for (it = v[step].begin(); it != v[step].end(); it++) {
                    node f =  * it;
                    for (int i = 0; i < 8; i++) {
                        node temp;
                        temp.x = f.x + mov[i][0];
                        temp.y = f.y + mov[i][1];
                        if (temp.x == endx && temp.y == endy) {
                            flag = 1;
                            break;
                        }
                        if (issafe(temp.x, temp.y)) {
                            v[step + 1].push_back(temp);
                            used[temp.x][temp.y] = 1;
                        }
                    }
                    if (flag == 1) break;
                }
                step++;
                if (flag == 1) break;
            }
        }
        cout << "To get from " << a << startx << " to " << b << endx << " takes " << step << " knight moves." << endl;
    }
    return 0;
}
