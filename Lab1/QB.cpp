#include <cstdio>
#pragma G++ optimize(2)
using namespace std;
int main() {
    long long j, k, n, S, cnt=0;
    scanf("%lld %lld", &n, &S);
    long long nums[n];
    long sum;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &nums[i]);
    }
    for (long long i = 0; i < n - 2; i++) {
        j = i + 1;
        k = n - 1;
        if (nums[i] + nums[j] + nums[k] == S && nums[i] == nums[k]) {
            long a = k-i;
            cnt+= (a+1)*a*(a-1)/6;
            break;
        }
        while (j < k) {
            sum = nums[i] + nums[j] + nums[k];
            if (sum > S) {
                --k;
            } else if (sum < S) {
                ++j;
            } else {
                if (nums[j] == nums[k]) {
                    cnt += (k-j+1)*(k-j)/2;
                    break;
                }
                long samesk = 0;
                long samesj = 0;
                while (nums [k] == nums[k-samesk]) {
                    ++samesk;
                }
                while (nums [j] == nums[j+samesj]) {
                    ++samesj;
                }
                k-=samesk;
                j+=samesj;
                cnt += samesj*samesk;
            }
        }
    }
    printf("%ld", cnt);
}