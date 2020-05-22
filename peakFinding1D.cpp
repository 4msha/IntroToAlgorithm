// /*--------------------------------------------------------------------------------------*/
//     //*************************   Peak Finding Problem in One Dimension    *********************
//         * Definition of peak- array[x] is peak if array[x+1] ans array[x-1] are smaller than array[x]
//         * Language used- C++
//         * Function Used- 
//         * void inputFile(vector<int>& vec,int n)--input array function
//         * int peakFinding(vector<int>&vec,int n)-- takes in array and no. of elements as input then
//           return the peak of the array .

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

int peakFinding(vector<int>&vec,int n){
    int x=n/2;
    while(x<n&&x>=0){
        if(x==0 || x ==n-1)/* code */
        return vec[x];
        if(vec[x]<vec[x+1])
          x=x+x/2;
        else if(vec[x]<vec[x-1])
          x=x/2;
        else
          return vec[x];
            
    }
}
int main(){
    vector<int> vec;
    int n;
    cout<<"Enter the no Of elements to input"<<endl;
    cin>>n;
    inputFile(vec,n);
    int peak=peakFinding(vec,n);
    cout<<"Input Array is   ";
    for(auto& x:vec)
      cout<<x<<"  ";
    cout<<endl;
      cout<<"Peak of the array is "<<peak<<endl;
    return 0;
}