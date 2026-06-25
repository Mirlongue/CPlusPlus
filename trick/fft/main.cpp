#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

#define N 150010
const double pi = 3.141592653;


bool pre_process(double * & reA, double * & inA,
                 double * & reB, double * & inB, int & len) {
    string st0, st1;
    std::cin >> st0 >> st1;

    for(int i = 0; ; i++) if (st0[i] != '0') {
        st0 = st0.substr(i);
        break;
    }
    cout << "st0: " << st0 << endl;

    for(int i = 0; ; i++) if (st1[i] != '0') {
        st1 = st1.substr(i);
        break;
    }
    cout << "st1: " << st1 << endl;       

    len = 1;
    int lenTmp;
    int len0 = st0.length();
    int len1 = st1.length();
    lenTmp = (len0 > len1 ? len0 : len1);
    while(len < lenTmp) len <<= 1;
    len <<= 1;



    reA = new double[len]{};
    inA = new double[len]{};
    reB = new double[len]{};
    inB = new double[len]{};

    for(int i = 0; i < len; i++) {
        if(i < len0) reA[i] = (double)st0[len0 - i - 1] - '0';
        if(i < len1) reB[i] = (double)st1[len1 - i - 1] - '0';
        inA[i] = inB[i] = 0.0;
    }

    for(int i = 0 ; i < len; i++) printf("%.1f ",reA[i]);
    printf("\n");
    for(int i = 0 ; i < len; i++) printf("%.1f ",reB[i]);

    return true;

}

double reTmp[N], inTmp[N];
void FFT(double *reX, double *inX, int n, int flag) {
    if(n == 1) return;

    double reWm = cos(2 * pi / n), inWm = sin(2 * pi / n);
    if(flag) inWm = -inWm;
    double reW = 1.0, inW = 0.0;
    
    int k, u, i;
    for(k = 1, u = 0; k < n; k += 2, u++) {
        reTmp[u] = reX[k];
        inTmp[u] = inX[k];
    }
    for(k = 2; k < n; k += 2) {
        reX[k/2] = reX[k];
        inX[k/2] = inX[k];
    }
    for(k = u, i = 0; k < n && i < u; k++, i++) {
        reX[k] = reTmp[i];
        inX[k] = inTmp[i];
    }
    FFT(reX, inX, n / 2, flag);
    FFT(reX + n / 2, inX + n / 2, n / 2, flag);
    for(k = 0; k < n / 2; k++) {
        int tag = k + n / 2;
        double reT = reW * reX[tag] - inW * inX[tag];
        double inT = reW * inX[tag] + inW * reX[tag];
        double reU = reX[k], inU = inX[k];
        reX[k] = reU + reT;
        inX[k] = inU + inT;
        reX[tag] = reU - reT;
        inX[tag] = inU - inT;
        double rew_t = reW * reWm - inW * inWm;
        double inw_t = reW * inWm + inW * reWm;
        reW = rew_t;
        inW = inw_t;
    }
    
}

int rev(int x, int ser) {
    int ans = 0;
    for(int i = 0; i < ser; i++) {
        ans <<= 1;
        ans |= x & 1;
        x >>= 1;
    }
    return ans;
}

int main() {


    double * reA, * inA;
    double * reB, * inB;
    int len;
    int * ans;

    while (pre_process(reA, inA, reB, inB, len)) {

        // FFT(reA, inA, len, 0);
        // FFT(reB, inB, len, 0);

        // for(int i = 0; i < len; i++) {
        //     double reC = reA[i] * reB[i] - inA[i] * inB[i];
        //     double inC = reA[i] * inB[i] + inA[i] * reB[i];
        //     reA[i] = reC;
        //     inA[i] = inC;
        // }
        // FFT(reA, inA, len, 1);
        // for(int i = 0; i < len; i++) {
        //     reA[i] /= len;
        //     inA[i] /= len;
        // }

        // for(int i = 0; i < len; i++) ans[i] = (int)(reA[i] + 0.5);
        // for(int i = 0; i < len; i++) {
        //     ans[i + 1] += ans[i] / 10;
        //     ans[i] %= 10;
        // }
        // int len_ans = len0 + len1 + 2;
        // while(ans[len_ans] == 0 && len_ans > 0) len_ans--;

        // printf("\n");
        // for(int i = len_ans; i >= 0; i--)
        //     printf("%d", ans[i]);
        // printf("\n");
    delete[] reA;
    reA = nullptr;
    delete[] inA;
    inA = nullptr;
    delete[] reB;
    reB = nullptr;
    delete[] inB;
    inB = nullptr;

    }

    return 0;
}