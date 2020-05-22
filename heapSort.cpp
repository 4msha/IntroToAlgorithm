// /*----------------------------------------------------------------------------------------------------*/
//     //*************************   Heap sort    *********************
//   
//         * Language used- C++
//         * Function Used- 
//           * void inputFile(vector<int>& vec,int n)--input array function
            //  * void swap(vector<int>& vec,int x,int y)-- swaps to elements of the array 
      //      //  * void max_heapify(vector<int>& vec,int pos,int n//)-- builds the max heap   
            //  * void heap_sort(vector<int>&vec,vector<int>& sortedVec,int n)-- main function for heap sort  

// -----------------------------------------------------------------------------------------------------------------------*/


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

void swap(vector<int>& vec,int x,int y){
    int temp=vec.at(x);
    vec.at(x)=vec.at(y);
    vec.at(y)=temp;
}

void max_heapify(vector<int>& vec,int pos,int n){

    if(pos>n/2)
    return;
    else if(2*pos+2<n){
        if(vec.at(pos)>=vec.at(2*pos+1) && vec.at(pos)>=vec.at(2*pos+2))
          return ;
        else if(vec.at(2*pos+1)>vec.at(2*pos+2)){
            swap(vec,2*pos+1,pos);
            max_heapify(vec,2*pos+1,n);
        }
        else{
            swap(vec,2*pos+2,pos);
            max_heapify(vec,2*pos+2,n);  
        }  
    }
    else if(2*pos+1<n){
        if(vec.at(pos)>=vec.at(2*pos+1))
          return;
        else{
           swap(vec,2*pos+1,pos);
           max_heapify(vec,2*pos+1,n); 
        }  
    }
}

void heap_sort(vector<int>&vec,vector<int>& sortedVec,int n){
    if(n==-1)
    return;
    swap(vec,0,n);
    sortedVec.push_back(vec.at(n));
    max_heapify(vec,0,n);
    heap_sort(vec,sortedVec,n-1);
}

int main()
{
  int val,n,j,key;
  vector<int> vec;
  vector<int> sortedVec;

  cout<<"Enter the no. of Elements:";
  cin>>n;
 
   inputFile(vec,n);
   for(int i=0;i<n;i++)
    cout<<vec[i]<<" | ";
    cout<<endl; 

  for(int i=(n-1)/2;i>=0;i--)
    max_heapify(vec,i,n);
 
   cout<<"After Max Heapify"<<endl;
   for(int i=0;i<n;i++)
      cout<<vec[i]<<" | ";
    cout<<endl; 

   heap_sort(vec,sortedVec,n-1);
  
  cout<<"\n SORTED ARRAY \n ";
  for(int i=0;i<n;i++)
    cout<<sortedVec[i]<<" | ";
    cout<<endl; 
return 0;
}