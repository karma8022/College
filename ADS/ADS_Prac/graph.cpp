#include <iostream>
#include <queue>
using namespace std;

class graph{
    private:
        int num;
        int cost[10][10];
    public:
        void create();
        void display();
        void bfs(int start);
        void dfs();
        void dfsutil(int v ,bool visited[]);
};

void graph::create(){
    cout<<"Enter the number of vertices";
    cin>>num;

    int i,j,val;
    cout<<"Enter i j and val (separated by spaces)";
    cout<<"Enter -1 -1 -1 to exit";

    for(int i =0;i<num;i++){
        for(int j=0;j<num;j++){
            cost[i][j]=999;
        }
    }

    while(true){
        cin>>i>>j>>val;
        if(i==-1 && j==-1 && val==-1){
            break;
        }   
        cost[i][j]=val;
        cost[j][i]=val;
    }
}

void graph::display(){
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(i==j){
                cout<<"0"<<" ";
            }
            else if(cost[i][j]!=999){
                cout<<cost[i][j]<<" ";
            }
            else{
                cout<<999<<" ";
            }
        }
        cout<<endl;
    }
}

void graph::bfs(int start){
    int visited[num]={false};
    queue<int>q;
    visited[start]={true};
    q.push(start);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout<<curr<<" ";
        for(int i =0;i<num;i++){
            if(cost[curr][i]!=999 && !visited[i]){
                visited[i]={true};
                q.push(i);
            }
        }
    }
    cout<<endl;
}

// void graph::dfsutil()

int main(){
    graph g;
    g.create();
    g.display();
    g.bfs(0);
    return 0;
}