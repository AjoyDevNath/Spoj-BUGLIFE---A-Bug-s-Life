
//Dfs_Code

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
#define MAX 100000

void init_code()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

vector<int>vec[2001];
bool visited[2001];
int color[2001];

bool dfs(int node,int col)//(3,4)
{
    visited[node] = 1;
    color[node] = col;

    for(auto it : vec[node])
    {
        if(!visited[it])
        {
            if(dfs(it,col ^ 1) == false){
                return false;
            }
        }
        else{
            if(color[it] == color[node])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    init_code();
    fastIO();

    int test;
    cin>>test;

    for(int i = 1 ; i <= test;i++){
        int node,edge;
        cin>>node>>edge;//3 3

        memset(visited,0,sizeof(visited));
        memset(color,0,sizeof(color));
        
        for(int i = 1 ; i <= node;i++){
            vec[i].clear();
        }

        while(edge--)
        {
            int x,y;
            cin>>x>>y;//

            vec[x].pb(y);
            vec[y].pb(x);
        }

        bool x;

        for(int i = 1 ; i <= node;i++){
            if(!visited[i]){
             x = dfs(i,1);//(3,1);
            }

            if(x == false){
                break;
            }
        }



        cout<<"Scenario #";

        if(x == true){
            cout<<i<<":"<<"\n";
             cout<<"No suspicious bugs found!"<<"\n";
        }
        else{
            cout<<i<<":"<<"\n";
            cout<<"Suspicious bugs found!"<<"\n";
        }

      }    
}