
/* ------------------------------------------------------------------------------------*/
  /*  * Document Distance Problem 
         This problem calculates percentage similarity between two files.
    * Language used- C++
    * Function Used- 
        * map<string,int> createMap(string location)-- convert a ginven file to map whose
          first attribute is the word and second attribute is the frequency of that word in
          the file
        * void printMap(map<string,int> mapDoc)-- printing map
        * int countTotalWords(map<string,int> mapDoc)-- calculate total no. of words in the
          file.  
          */
 /*-------------------------------------------------------------------------------------------*/


#include<bits/stdc++.h>
using namespace std;

map<string,int> createMap(string location){
ifstream in_file1(location);
string line,doc;
 map<string,int> mapDoc;

     if (in_file1.is_open()) {
            while ( getline (in_file1, line) ) {
               for(int i{0};i<line.length();i++){
                   if(isalpha(line[i]))
                     doc+=toupper(line[i]);    
                   else if(line[i]==' '){
                     auto it=mapDoc.find(doc);
                     if(it!=mapDoc.end()){
                       it->second++;
                     }else
                     {
                       mapDoc.insert(make_pair(doc,1));
                     }
                      doc="";
                   }  
               }
            }
            in_file1.close();
        }
        else
          cout<<"wrongggg";

        return mapDoc;
}

void printMap(map<string,int> mapDoc){
     cout<<"----------------------------------------------------"<<endl;
     for(auto it=mapDoc.begin();it!=mapDoc.end();it++)
        cout<<setw(10)<<left<<it->first<<setw(10)<<it->second<<endl;
}

int countTotalWords(map<string,int> mapDoc){
  long long size{0};
  for(auto it=mapDoc.begin();it!=mapDoc.end();it++)
      size+=it->second;

  return size;
}


int main(){
    string line,doc1,doc2;
    long long int mul{0},size1,size2;
    double dotProduct;
    map<string,int> mapDoc1;
    map<string,int> mapDoc2;

    mapDoc1=createMap("files/a.txt");
    mapDoc2=createMap("files/b.txt");

    printMap(mapDoc1);
    printMap(mapDoc2);

    for(auto it=mapDoc1.begin();it!=mapDoc1.end();it++){
      auto temp=mapDoc2.find(it->first);
      if(temp!=mapDoc2.end()){
        mul+=(temp->second)+(it->second);
        cout<<it->first<<"   "<<temp->first<<"     "<<mul<<endl;;
      }
    }
    
    size1=countTotalWords(mapDoc1);
    size2=countTotalWords(mapDoc2);

    cout<<"mul=="<<mul<<"    size1"<<size1<<"    size2"<<size2<<endl;
    
    dotProduct=(double)mul/(size1+size2);
    dotProduct*=100;

    cout<<"The Following two document are "<<dotProduct<<"%  same."<<endl;

    return 0;
}