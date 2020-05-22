#include<bits/stdc++.h>
using namespace std;


void inputFile(vector<int>& vec,int n){
    int val;
  ifstream in_file("files/inputArray.txt");
    for(int i{0};i<n;i++){
        in_file>>val;
        vec.push_back(val);
    }
       
}

void merge(int l,int x,int u,vector<int>& vec){
  while(l<x+1){
    if(x>u)
      break;
    if(vec.at(l)>vec.at(x+1)){
      
      l++;
      x++;
    }  
    l++;
  }
}

 
void merge_sort(int l,int u,vector<int>& vec)
{  
   for(int i{l};i<=u;i++)
       cout<<vec[i]<<" | ";
  cout<<endl;
  int x,i;
  if(l==u)
  return ;
  else
  {
    x=(u+l)/2;
    merge_sort(l,x,vec);
    merge_sort(x+1,u,vec);
    merge(l,x,u,vec);

    cout<<"after"<<endl;

     for(int i{l};i<=u;i++)
       cout<<vec[i]<<" | ";
  cout<<endl;
    
  }
}
  


int main()
{
  int n;
  vector<int>vec;
  cout<<"Enter the no of elements:";
  cin>>n;
  inputFile(vec,n);

  for(int i{0};i<n;i++)
  cout<<vec[i]<<" | ";
  cout<<endl;

  merge_sort(0,n-1,vec);
  
  cout<<"SORTED ARRAY"<<endl;
  for(int i{0};i<n;i++)
  cout<<vec[i]<<" | ";
  cout<<endl;

  return 0;
}