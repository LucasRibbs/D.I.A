#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct ponto {
    int x, y;
    ponto(){ x=y=0; }
    ponto(int _x, int _y){ x=_x; y=_y; }
};

int N;

int up_bound(vector<int> &T, int low, int high, int e){
	if ( low < 0) return 0;
    if (low >= high ){
        if ( T[low] > e ) return low;
        return low+1;
    }
    int mid=(low+high)/2;
    if ( e >= T[mid])
        return up_bound(T,mid+1,high,e);
    return up_bound(T,low,mid,e);
}

int PercorrerCima(int i, map<int,vector<int> > &M) {

    int max = 1;
    int k = up_bound(M[i-2], 0, M[i-2].size()-1, M[i][0]);
    int l = 0;

    bool cima = false;

    while(k!=M[i-2].size() and l!=M[i].size()) {

        if(cima) k = up_bound(M[i-2], 0, M[i-2].size()-1, M[i][l]);
        else l = up_bound(M[i], 0, M[i].size()-1, M[i-2][k]);

        cima = !cima;
        max += 1;
    }

    return max;
}

int PercorrerBaixo(int i, map<int,vector<int> > &M) {

    int max = 1;
    int k = up_bound(M[i+2], 0, M[i+2].size()-1, M[i][0]);
    int l = 0;

    bool baixo = false;

    while(k!=M[i+2].size() and l!=M[i].size()) {

        if(baixo) k = up_bound(M[i+2], 0, M[i+2].size()-1, M[i][l]);
        else l = up_bound(M[i], 0, M[i].size()-1, M[i+2][k]);

        baixo = !baixo;
        max += 1;
    }

    return max;
}

int main() {

    map<int,vector<int> > M;
    
    while(cin >> N) {

        M.clear();

        for(int i=0; i<N; ++i) {
            int x, y;
            cin >> x >> y;
            M[y].push_back(x);
        }

        for (map<int,vector<int> >::iterator it=M.begin(); it!=M.end(); ++it)
            sort(it->second.begin(), it->second.end());

        // for (map<int,vector<int> >::iterator it=M.begin(); it!=M.end(); ++it) {
        //     cout<<it->first<<": ";
        //     for(int i=0; i<(it->second).size(); ++i) cout<<it->second[i]<<' ';
        //     cout<<endl;
        // }
        // cout<<endl;

        int result = 0;
        map<int,vector<int> >::iterator it = M.begin();

        while(it != M.end()) {

            int i = it->first;
            int maxCima = 1, maxBaixo = 1;
            if(M.find(i-2) != M.end()) maxCima = PercorrerCima(i, M);
            if(M.find(i+2) != M.end()) maxBaixo = PercorrerBaixo(i, M);

            result = max(result, max(maxCima,maxBaixo) );

            ++it;
        }

        cout<<result<<endl;
    }

    return 0;
}