// /*----------------------------------------------------------------------------------------------------*/
//     //*************************   Insertion sort    *********************
//   
//         * Language used- C++
//         * Function Used- 
//         * void inputFile(vector<int>& vec,int n)--input array function

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

int main()
{
  int val,n,j,key;
  vector<int> vec;

  cout<<"Enter the no. of Elements:";
  cin>>n;
 
   inputFile(vec,n);

   for (int i = 1; i < n; i++) 
   { 
        key = vec[i]; 
        j = i - 1; 

        while (j >= 0 && vec[j] > key)
        { 
            vec[j + 1] = vec[j]; 
            j = j - 1; 
        } 
        vec[j + 1] = key;

    } 
 
  
  cout<<"\n SORTED ARRAY \n ";
  for(int i=0;i<n;i++)
    cout<<vec[i]<<" | ";
    cout<<endl; 
return 0;
}