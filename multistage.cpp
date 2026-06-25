#include<iostream>
#include<climits>
using namespace std;

int main(){
    int v;
    cout<<"Enter vertices: ";
    cin>>v;
    int g[v][v];
    cout<<"Enter adjacency matrix (0 if no edge):"<<endl;
    for(int i=0; i<v; i++)
        for(int j=0; j<v; j++) cin>>g[i][j];

    // Forward approach
    int cost[v], d[v];
    cost[v-1]=0;
    for(int i=v-2; i>=0; i--){
        cost[i]=INT_MAX;
        for(int j=i+1; j<v; j++){
            if(g[i][j]!=0 && g[i][j]+cost[j]<cost[i]){
                cost[i]=g[i][j]+cost[j];
                d[i]=j;
            }
        }
    }
    cout<<"Min cost (forward) = "<<cost[0]<<endl;
    cout<<"Path: 0";
    int curr=0;
    while(curr!=v-1){ curr=d[curr]; cout<<" -> "<<curr; }
    cout<<endl;

    // Backward approach
    int bcost[v];
    bcost[0]=0;
    for(int i=1; i<v; i++){
        bcost[i]=INT_MAX;
        for(int j=0; j<i; j++){
            if(g[j][i]!=0 && bcost[j]+g[j][i]<bcost[i])
                bcost[i]=bcost[j]+g[j][i];
        }
    }
    cout<<"Min cost (backward) = "<<bcost[v-1]<<endl;
    return 0;
}
