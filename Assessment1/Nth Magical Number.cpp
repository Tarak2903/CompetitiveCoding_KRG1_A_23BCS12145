#include <bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y) {
    while (y) {
        long long t = y;
        y = x % y;
        x = t;
    }
    return x;
}

int main() {
    long long n, a, b;
    cin >> n >> a >> b;

    long long l = min(a, b), r = n * min(a, b);
    long long lcm = (a / gcd(a, b)) * b;

    while (l < r) {
        long long mid = l + (r - l) / 2;
        long long count = mid / a + mid / b - mid / lcm;

        if (count < n)
            l = mid + 1;
        else
            r = mid;
    }

    cout << l;
    return 0;
}
