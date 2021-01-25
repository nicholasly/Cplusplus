#include <cstdio>
#include <climits>
#include <cstring>
using namespace std;

int map[101][101];
int visit[101];
int d[101];

int main() {
    int n, i, j, q, t, ans, minn;
    while (~scanf("%d", &n)) {
        memset(visit, 0, sizeof(visit));
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        scanf("%d", &q);
        for (i = 0; i < q; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            map[a - 1][b - 1] = 0;
            map[b - 1][a - 1] = 0;
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
