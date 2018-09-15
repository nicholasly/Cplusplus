#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>
using namespace std;

int main() {
    int n, i, j;
    int w[51];
    int dp[100001];
    scanf("%d", &n);
    memset(dp, 0, sizeof(dp));

    int sum = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        sum += w[i];
    }
    for (i = 0; i < n; i++) {
        for (j = sum; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
        }
    }
    int ans = INT_MAX;
    for (i = 0; i <= sum; i++) {
        if (dp[i]) {
            ans = min(ans, abs(sum - dp[i] - dp[i]));
        }
    }
    printf("%d\n", ans);
    return 0;
}
