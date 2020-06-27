/*********************************************************************************************************
 *  -----------------------------DEPTH FIRST SEARCH --Graph---------------------------------------------
 * 
 * List of Function -
 *                  * void createGraph(int v,node arr[])
 *                  * void dfs(node arr[],map<int,int>& visited,int start,int parent)
 * 
 * ***********************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        vector<int>neighbour;
    public:
        // node();
        // node::node(vector<int>vec){
        //     for(auto& x:vec)
        //         neighbour.push_back(x);
        // }
        void setNeighbour(vector<int> vec){
           for(auto& x:vec)
                neighbour.push_back(x); 
        }
        void print(){
            for(auto& y:neighbour){
                cout<<y<<"   ";
            }
        }
};

void createGraph(int v,node arr[]){
   for(int i=0;i<v;i++){
       int choice;
       vector<int>vec;
       do{
           cout<<"Enter the neighbour of "<<i<<" vertice  or -1 if there are no vertices\n";
           cin>>choice;
           if(choice!=-1){
              vec.push_back(choice);
           }
       }while(choice!=-1);
       arr[i].setNeighbour(vec);
   } 
}

void dfs(node arr[],map<int,int>& visited,int start,int parent){
   visited.insert(make_pair(start,parent));
   cout<<start<<"  ";

   for(auto& x:arr[start].neighbour){
       auto it=visited.find(x);
       if(it==visited.end()){
           dfs(arr,visited,x,start);
       }
   }
}

int main(){
    int v,s;
    cout<<"Enter no of vertices\n";
    cin>>v;
    node arr[v];
    createGraph(v,arr);
    for(int i{0};i<v;i++){
        cout<<"the vertex "<<i<<"   ";
        arr[i].print();
        cout<<endl;
    }

    cout<<"Enter the starting vertex for BFS \n";
    cin>>s;
    map<int,int>visited;
    cout<<" DFS \n  ";
    dfs(arr,visited,s,-1);

    return 0;
}