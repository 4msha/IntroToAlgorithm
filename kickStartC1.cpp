#include<iostream>
using namespace std;

int arr[200000];
int t,n,k;

int solution(){
    int count{0};
    cin>>n>>k;
    for(int i{0};i<n;i++)
       cin>>arr[i];
    for(int i{0};i<n;i++){
        if(arr[i]==k){
            int x=i+1;
            int t=1;
            while(k-t){
                if(arr[x]!=k-t)
                   break;
                t++;
                x++;
                i++;
            }
            if(t==k){
              count++;
              i--;
            }
        }
    }
    return count;
}

int main(){
    int i{1};
    cin>>t;
    while(t--){
        int count=solution();
        cout<<"Case #"<<i<<": "<<count<<endl;
        i++;
    }
    return 0;
}