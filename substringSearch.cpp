// /*----------------------------------------------------------------------------------------------------*/
//     //*************************   Substring Search using Rolling Hash *********************
//   
//         * Language used- C++
//         * Function Used- 
//         * Data Structure RollingHash

// -----------------------------------------------------------------------------------------------------------------------*/


#include<bits/stdc++.h>
using namespace std;

int RandomPrime=7129;

//-----------------------------------class declaration of random hash ---------------------
class RollingHash{
    public:
      long long int value;
      int hash;
      int plus;

      RollingHash()
      :value(0),hash(0),plus(0){
          cout<<"hash created"<<endl;
      };

      void append(const char& c){
         value=value*7+((int)c-96);
         hash=value%RandomPrime;
         plus++;
      };

      void skip(const char& c){
          value-=((int)c-96)*powF(7,plus-1);
          hash=value%RandomPrime;
          plus--;
      };

     friend bool operator==(const RollingHash& r1,const RollingHash& r2){
          if(r1.hash==r2.hash)
             return true;
          return false;
      }

     int powF(int x,int y){
        int power{1};
        while(y--)
        power*=x;
        return power;
     }

};
//----------------end of classs------------------------//


int main(){
    string s;
    string t="cissurelyabeautifullanguageformeUnfortunatelycsbeautyisnotinitssyntaxorinitscodingstyleItliesinitscoremanydeveloperswhofallinlovewiththislanguageonce";
    cout<<"Enter the string u want to serach"<<endl;
    cin>>s;
    int sLength=s.length();
     // declaring two rolling hash objects 
     RollingHash rs,rt;

    for(auto& x:s)
       rs.append(x);
   
    for(int i{0};i<sLength;i++)
      rt.append(t[i]); 

      cout<<rs.plus<<"  "<<rs.value<<"  "<<rs.hash<<endl;
      cout<<"-----------------------------\n";
       cout<<rt.plus<<"  "<<rt.value<<"  "<<rt.hash<<endl;
       int i;

       //Karp-Rabin------------------------------------
      for(i=1;i<t.length()-sLength;i++){
         if(rt==rs){
             int x=i-1;
             int j=0;
             while(j<sLength){
                 if(t[x]!=s[j]){
                    cout<<"failed\n";
                 }
                 j++;
                 x++;
             }

             if(j==sLength){
                 cout<<"\n--------------------------------------------------------------------\n";
                 cout<<"String Found!!!\n";
                sLength+=i;
                i=i-1;
                    while(i<sLength-1){
                        cout<<t[i]<<" ";
                        i++;
                    } 
                    cout<<"\n";
                    cout<<"-------------------------------------------------------------------\n";
                    break;
             } 
         }
          rt.append(t[i+sLength-1]);
          rt.skip(t[i-1]);
           cout<<rs.plus<<"  "<<rs.value<<"  "<<rs.hash<<endl;
        cout<<"-----------------------------\n";
       cout<<rt.plus<<"  "<<rt.value<<"  "<<rt.hash<<endl;
      }

      if(i==t.length()){
          cout<<" \n string Not Found  \n";
      }

    //   sLength+=i;
    //   while(i<sLength-1){
    //     cout<<t[i]<<" ";
    //     i++;
    //   }

      return 0;    
}