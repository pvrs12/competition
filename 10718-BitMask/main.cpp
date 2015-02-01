#include <stdio.h>
typedef long long int ll;
ll solve(ll L, ll U, ll N) {
    ll res = 0;
    int gt = 0;
    int i;
    for (i = 31; i >= 0; i--) {
        if (gt) {
            if ((U & (1LL << i)) && !(N & (1LL << i)))
                res |= 1LL << i;
            else if ((U & (1LL << i)))
                U |= (1LL << i) - 1;
        } else {
            if ((U & (1LL << i)) && (L & (1L << i)))
                res |= 1LL << i;
            else if ((U & (1LL << i)) && !(N & (1LL << i))) {
                res |= 1LL << i;
                gt = 1;
            } else if ((U & (1LL << i)))
                U |= (1LL << i) - 1;
        }
    }
    return res;
}
int main() {
    ll N, L, U;
    while (scanf("%lld %lld %lld", &N, &L, &U) == 3)
        printf("%lld\n", solve(L, U, N));
    return 0;
}
