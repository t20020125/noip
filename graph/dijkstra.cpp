#include <iostream>
#include <stack>
#define M 100
#define N 100
#define INT_MAX 65536
using namespace std;

    int matrix[N][M];      //邻接矩阵
    int n;                 //顶点数
    int e;                 //边数
    int dist[N];           //距离
    int path[N];           //路径，每个点的前一个节点编号
    bool visited[N];       //最短路径是否已经确定

////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////Dijkstra/////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void DijkstraPath(int v0)   //v0表示源顶点
{
    int i,j,k;

    for(i=0;i<n;i++)     //初始化
    {
        if(matrix[v0][i]>0&&i!=v0)
        {
            dist[i]=matrix[v0][i];
            path[i]=v0;     //path记录最短路径上从v0到i的前一个顶点
        }
        else
        {
            dist[i]=INT_MAX;    //若i不与v0直接相邻，则权值置为无穷大
            path[i]=-1;
        }
        visited[i]=false;

    }
    dist[v0]=0;
	path[v0]=v0;
    visited[v0]=true;
    for(i=1;i<n;i++)     //循环扩展n-1次 ，即依次确定剩余的n-1个点的最短路径
    {
        int min=INT_MAX;
        int u=v0;
        for(j=0;j<n;j++)    //寻找未被扩展的权值最小的顶点
        {
            if(visited[j]==false&&dist[j]<min)
            {
                min=dist[j];
                u=j;
            }
        }
        visited[u]=true;//u点的最短路径确定了 ，dist[u]和path[u]在上一轮已经确定了
        for(k=0;k<n;k++)   //更新dist数组的值和路径的值
        {
            if(visited[k]==false&&matrix[u][k]>0&&min+matrix[u][k]<dist[k])
            {
                dist[k]=min+matrix[u][k];
                path[k]=u;
            }
        }
    }
}

void showPath(int v0,int v)   //打印v0到v的最短路径
{
    stack<int> s;//后进先出，和queue相反
    while(v!=v0)
    {
        s.push(v);
        v=path[v];
    }
    s.push(v);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main(int argc, char *argv[])
{
       cin>>n>>e;

        int i,j;
        int s,t,w;      //表示存在一条边s->t,权值为w
        int v0;
         for(i=0;i<N;i++)
            for(j=0;j<M;j++)
                matrix[i][j]=0;

        for(i=0;i<e;i++)
        {
            cin>>s>>t>>w;
            matrix[s][t]=w;
        }
        cin>>v0;        //输入源顶点
        DijkstraPath(v0);
        for(i=0;i<n;i++)
        {
            if(i!=v0)
            {
                showPath(v0,i);
                cout<<dist[i]<<endl;
            }
        }

    return 0;
}
