#include <iostream>
#include <limits.h>
using namespace std;

int main() {
    int t, V, E;
    int edges[200001][3];
    long long int** dist;

    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> V >> E;
        dist = (long long**)malloc(V*sizeof(long long*));
        for(int i=0;i<V;i++)
            dist[i] = (long long*)malloc(V*sizeof(long long));
        for(int i=0;i<V;i++){
            for(int j=0; j<V;j++)
                dist[i][j] = LONG_LONG_MAX;
        }
        for(int i = 0; i<E; i++)
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        
        for(int i=0;i<V;i++) 
            dist[i][i] = 0;
        
        for(int mid=0; mid<V;mid++){
            for(int start=0; start<V; start++){
                for(int end=0; end<V; end++){
                    int passing = dist[start][end];
                    int taking = dist[start][mid] + dist[mid][end];
                    if (passing > taking) dist[start][end] = taking;
                    else dist[start][end] = passing;
                }
            }
        }

        long long minimum = LONG_LONG_MAX;
        for(int i=0;i<E; i++){
            long long temp = dist[0][edges[i][0]] + dist[edges[i][1]][V-1];
            if (minimum > temp) minimum = temp;
        }
        if (minimum == LONG_LONG_MAX) cout << "-1" <<endl;
        else cout<<minimum<<endl;
    }
}