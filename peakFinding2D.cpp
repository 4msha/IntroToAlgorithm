/*-----------------------------------------------------------------------------------------------------------
    //*************************   Peak Finding Problem in Two Dimension    *********************
        * Definition of peak- array[i][j] is peak if array[i][j+1], array[i][j-1] ,array[i-1][j]and array[i+1][j] are smaller than array[x]
        * Language used- C++
        * Function Used- 
        * void inputFile(vector<int>& vec,int n)--input array function
        * int peakFinding(vector<int>&vec,int n)-- takes in array and no. of elements as input then
          return the peak of the array .

-----------------------------------------------------------------------------------------------------------------------*/

#include<bits/stdc++.h>
using namespace std;

void inputFile(vector<vector<int>>& vec,int n,int m){
     ifstream in_file("files/inputArray.txt");

     for(int i{0};i<n;i++)
       for(int j{0};j<m;j++){
           in_file>>vec[i][j];
       }
}


int main(){
    vector<vector<int>> vec;
    int n,m;
    cout<<"Enter the dimension n*m :"<<endl;
    cin>>n>>m;
    inputFile(vec,n,m);

    for(int i{0};i<n;i++)
       for(int j{0};j<m;j++)
          cout<<vec[i][j]<<"     ";

    return 0;      
}