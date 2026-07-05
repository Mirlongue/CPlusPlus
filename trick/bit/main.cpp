#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 100010;

int a[MAXN];
int c[MAXN];
int n;

int lowbit(int x) {
    return x & -x;
}

int query(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)) ans += c[i];
    return ans;
}

void insert(int x, int v) {
    for (int i = x; i < MAXN; i += lowbit(i)) c[i] += v;
}

void init(int n) {
    for (int i = 1; i <= n; i++) {
        insert(i, a[i]);
    }
}

int main() {

    memset(a, 0, sizeof(a));

    int n = 16;
    for(int i = 1 ; i <= 16; i++) {
        a[i] = 1;
    }
    init(16);
    cout << query(16) << endl;
    cout << query(8) << endl;
    cout << query(4) << endl;

    for (int i = 1; i <= 16; i++) {
        cout << c[i] << " ";
    }
    cout << endl;

    return 0;
}