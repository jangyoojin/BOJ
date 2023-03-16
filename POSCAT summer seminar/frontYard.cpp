#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<int> multiply(const vector<int>& a, const vector<int>& b)
{
    vector<int> c(a.size() + b.size() + 1, 0);
    for(long long unsigned i =0; i<a.size(); i++){
        for(long long unsigned j=0;j<b.size(); j++){
            c[i+j] += (a[i]*b[j]);
        }
    }
    return c;
}


void addTo(vector<int>& a, const vector<int> b, int k)
{
    int length = b.size();
    a.resize(max(a.size(), b.size()) + 1);
    for(int i = 0; i<length; i++) {
        a[i+k] += b[i];
    }
}
void subFrom(vector<int>& a, const vector<int>& b)
{
	int length = b.size();
	a.resize(max(a.size(), b.size()) + 1);
	for (int i = 0; i < length; i++)
		a[i] -= b[i];
}
vector<int> karatsuba(const vector<int> &a, const vector<int> &b)
{
	int an = a.size(), bn = b.size();
	if (an < bn) return karatsuba(b, a);
	if (an == 0 || bn == 0) return vector<int>();
	if (an <= 50) return multiply(a, b);
	int half = an / 2;
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());
	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);
	addTo(a0, a1, 0);
	addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);
	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);
	return ret;
}

int main(){

    int T, m, n, k;
    string a, b;

    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> m >> n >> k;
        vector<int> A(m), B(n);
        for(int idx = 0; idx < m; idx++) {
            int temp;
            cin >> temp;
            A[idx] = temp;
        }

        for(int idx = 0; idx < n; idx++) {
            int temp;
            cin >> temp;
            B[n-idx-1] = temp;
        }

        for(int idx = 0; idx < m; idx++){
            A[idx] = A[idx] == 2 ? 1 : 0;
        }
        for(int idx = 0; idx < n; idx++){
            B[idx] = B[idx] == 2 ? 1 : 0;
        }

        vector<int> table = karatsuba(A, B);

        for(long long unsigned idx = 0; idx < table.size(); idx++){
            table[idx] = table[idx] ? 0 : 1;
        }

        long long int result = 0;
        int A_start = 0, A_end = A.size()-1;
        int B_start = A.size() - 1, B_end = A.size() + B.size() - 2;

        for(long long unsigned idx = 0; idx < table.size(); idx++) {
            int length = max(A_end, B_end) - min(A_start, B_start) + 1;
            if(length <= k) result += (k - length + 1) * table[idx];
            B_start--;
            B_end--;
        }

        cout << result%1234567890 << endl;
    }

}
