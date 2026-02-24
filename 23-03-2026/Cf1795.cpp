#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        vector<long long> pref(n + 1, 0);
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + a[i];

        vector<long long> cnt(n + 2, 0);
        vector<long long> extra(n + 2, 0);

        for (int i = 1; i <= n; i++) {
            long long need = b[i];

            int pos = lower_bound(pref.begin(), pref.end(),
                                  pref[i] - need) - pref.begin();

            cnt[pos + 1]++;
            cnt[i + 1]--;
            long long consumed_before = pref[i] - pref[pos];
            extra[pos] += need - consumed_before;
        }

        for (int i = 1; i <= n; i++)
            cnt[i] += cnt[i - 1];

        for (int i = 1; i <= n; i++) {
            long long result = cnt[i] * a[i] + extra[i];
            cout << result << " ";
        }
        cout << "\n";
    }
}
