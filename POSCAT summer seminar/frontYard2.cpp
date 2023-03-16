#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;

 
vector<int> multiply(const vector<int> &a, const vector<int> &b) {
 
    vector<int> c(a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            c[i + j] += a[i] * b[j];
 
    return c;
}



void addTo(vector<int> &a, vector<int>& b, int k) {
    int newsize = a.size() < b.size() + k ? b.size() + k : a.size();
    while (a.size() != newsize) a.push_back(0);
    for (int i = k; i < newsize; i++) {
        a[i] = a[i] + b[i - k];
    }
}
 

void subFrom(vector<int> &a, vector<int>& b) {
    for (int i = 0; i < b.size(); i++) {
        a[i] -= b[i];
    }
}
 
vector<int> karatsuba(const vector<int> &a, const vector<int> &b) {
    int an = a.size();
    int bn = b.size();
    int half = an / 2;
 
    
    if (an < bn) return karatsuba(b, a);
    if (an == 0 || bn == 0) return vector<int>();
    if (an <= 50) return multiply(a, b);
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin()+min<int>(half, b.size()));
 
    vector<int> b1(b.begin() + min<int>(half, b.size()), b.end());
    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);
 
    addTo(a0, a1, 0); 
    addTo(b0, b1, 0);
    vector<int> z1 = karatsuba(a0, b0);
 
    subFrom(z1, z2);
    subFrom(z1, z0);
 
    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half + half);
 
    return ret;
}
 
 
int main()
{
    int T, n, m, k;
    cin >> T;

    for(int i = 0; i < T; i++){
        vector<int> Y(m), G(n);
        scanf("%d %d %d\n", &m, &n, &k);
        for(int idx = 0; idx < m; idx++) {
            int temp;
            cin >> temp;
            Y[idx] = temp;
        }

        for(int idx = 0; idx < n; idx++) {
            int temp;
            cin >> temp;
            G[n - idx -1] = temp;
        }

        for(int idx = 0; idx < m; idx++) {
            Y[idx] = Y[idx] == 2? 1 : 0;
        }
        for(int idx = 0; idx < n; idx++) {
            G[idx] = G[idx] == 2? 1 : 0;
        }
        reverse(G.begin(),G.end());

        vector<int> table = karatsuba(Y, G);
        
        for(int idx = 0; idx < table.size(); idx++) {
            table[idx] = table[idx]? 0 : 1;
        }

        long long unsigned result = 0;
        int Y_start = 0, Y_end = Y.size()-1;
        int G_start = Y.size() - 1, G_end = Y.size() + G.size() - 2;

        for(int idx = 0; idx < table.size(); idx++) {
            int length = max(Y_end, G_end) - min(Y_start, G_start) + 1;
            if(length <= k) result += (k - length + 1) * table[idx];
            G_start--;
            G_end--;
        }

        result %= 1234567890;
        printf("%d\n", result);
    }
    
 
    return 0;
}