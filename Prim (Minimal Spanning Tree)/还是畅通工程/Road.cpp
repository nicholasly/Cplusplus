#include <cstdio>
#include <climits>
#include <cstring>
using namespace std;

int map[101][101];
int visit[101];
int d[101];

int main() {
    int n, i, j, t, ans, minn;
    while (scanf("%d", &n) && n) {
        memset(visit, 0, sizeof(visit));
        memset(d, 0, sizeof(d));
        for (i = 0; i < n * (n - 1) / 2; i++) {
            int a, b, w;
            scanf("%d %d %d", &a, &b, &w);
            map[a - 1][b - 1] = w;
            map[b - 1][a - 1] = w;
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
