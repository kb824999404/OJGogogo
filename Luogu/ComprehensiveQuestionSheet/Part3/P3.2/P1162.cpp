#include <bits/stdc++.h>
#include <queue>
using namespace std;
const int MAX=32;
int N;
int m_map[MAX][MAX]={-1};
bool visited[MAX][MAX] = {false};

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

struct _Point{
    int x;
    int y;
};
typedef struct _Point Point;


void bfs(int x,int y){
    if(visited[x][y]||m_map[x][y]!=0)   return;

    queue<Point> q = queue<Point>();
    Point p_start = Point();
    p_start.x=x;
    p_start.y=y;
    q.push(p_start);

    while (!q.empty())
    {
        Point p = q.front();
        q.pop();
        visited[p.x][p.y] = true;
        for(int i=0;i<4;i++){
            int x_new = p.x + dx[i];
            int y_new = p.y + dy[i];
            if(m_map[x_new][y_new]==0&&!visited[x_new][y_new]){
                Point tmp = Point();
                tmp.x = x_new;
                tmp.y = y_new;
                q.push(tmp);
            }
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            m_map[i][j] = -1;
        }
    }
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>m_map[i][j];
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            visited[i][j] = false;
        }
    }

    for(int i=1;i<=N;i++){
        bfs(i,1);
        bfs(i,N);
        bfs(1,i);
        bfs(N,i);
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(!visited[i][j]&&m_map[i][j]==0){
                m_map[i][j] = 2;
            }
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<<m_map[i][j]<<' ';
        }
        cout<<endl;
    }


    return 0;
}