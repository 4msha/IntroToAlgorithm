// /*-----------------------------------------------------------------------------------------------------------
//     //*************************   Peak Finding Problem in Two Dimension    *********************
//         * Definition of peak- array[i][j] is peak if array[i][j+1], array[i][j-1] ,array[i-1][j]and array[i+1][j] are smaller than array[x]
//         * Language used- C++
//         * Function Used- 
//         * void inputFile(vector<int>& vec,int n)--input array function
//         * int peakFinding(vector<int>&vec,int n)-- takes in array and no. of elements as input then
//           return the peak of the array .
        //    * int findGlobalMax(vector<vector<int>>& vec,int n,int x)-- find the glbal maxxima in
        //       a column.
        //    * int peakFinding(vector<vector<int>>& vec,int n,int m) -- finds the peak in 2d matrix 

// ----------------------------------------------------------------------------------------------------------------*/

#include<bits/stdc++.h>
using namespace std;

void inputFile(vector<vector<int>>& vec,int n,int m){
    int val,x{0};
    vector<int>temp;
     ifstream in_file("files/inputArray.txt");
    
     for(int i{0};i<n*m;i++){
        in_file>>val;
        temp.push_back(val);
        
    }
   

     for(int i{0};i<n;i++){
       for(int j{0};j<m;j++,x++){
          
           vec[i][j]=temp[x];
       }
      
     }
}

int findGlobalMax(vector<vector<int>>& vec,int n,int x){
    int max=vec[0][x];
    int index=0;
    for(int i{0};i<n;i++)
        if(max<vec[i][x]){
            max=vec[i][x];
            index=i;
        }
     
    return index;
}

int peakFinding(vector<vector<int>>& vec,int n,int m){
    int x=m/2;
    
    while(x<m&&x>=0){
       int i=findGlobalMax(vec,n,x);
       if(x==0){
           if(vec[i][x]>vec[i][x+1]) 
           return vec[i][x];
           return 0;
       }
       else if(x==m-1){
           if(vec[i][x]>vec[i][x-1]) 
           return vec[i][x];
           return 0;
       }else{
         
       if(vec[i][x]<vec[i][x+1]) 
           x+=ceil((double)x/2);
       else if(vec[i][x]<vec[i][x-1])    
           x=x/2;
       else 
         return vec[i][x];
       }
            
    }
}

int main(){

    int n,m;
    cout<<"Enter the dimension n*m :"<<endl;
    cin>>n>>m;
    vector<vector<int> > vec( n , vector<int> (m, 0));  
    inputFile(vec,n,m);

    cout<<"INPUT ARRAY: ";  
    for(int i{0};i<n;i++)
       for(int j{0};j<m;j++)
          cout<<vec[i][j]<<"   ";
       cout<<endl;

    int peak=peakFinding(vec,n,m);      
    cout<<"PEAK OF THE MATRIX IS"<<peak<<endl;

    return 0;      
}