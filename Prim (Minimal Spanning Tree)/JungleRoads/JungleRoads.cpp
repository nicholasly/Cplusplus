#include <cstdio>
#include <climits>
#include <cstring>
using namespace std;

int map[28][28];
int visit[28];
int d[28];

int main() {
    int n, i, j, m, t, ans, minn;
    char c1, c2;
    while (scanf("%d", &n) && n) {
        memset(visit, 0, sizeof(visit));
        memset(d, 0, sizeof(d));
        for (i = 0; i < 28; i++) {
            for (j = 0; j < 28; j++) {
                map[i][j] = INT_MAX;
            }
        }
        for (i = 0; i < n - 1; i++) {
            getchar();
            scanf("%c", &c1);
            scanf("%d", &m);
            for (j = 1; j <= m; j++) {
                scanf("%c", &c2);
                scanf("%c", &c2);
                scanf("%d", &t);
                map[c1 - 'A'][c2 - 'A'] = t;
                map[c2 - 'A'][c1 - 'A'] = t;
            }
        }
        for (i = 0; i < n; i++) {
            d[i] = map[i][0];
        }
        ans = 0;
        visit[0] = 1;
        for (i = 0; i < n - 1; i++) {
            minn = INT_MAX;
            for (j = 0; j < n; j++) {
                if (!visit[j] && minn > d[j]) {
                    minn = d[j];
                    t = j;
                }
            }
            visit[t] = 1;
            ans += minn;
            for (j = 0; j < n; j++) {
                if (!visit[j] && d[j] > map[j][t]) {
                    d[j] = map[j][t];
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
