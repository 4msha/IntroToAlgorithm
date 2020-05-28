// /*----------------------------------------------------------------------------------------------------*/
//     //*************************   AVL TREE   *********************
//   
//         * Language used- C++
// //         * Function Used- 
// //         * void inputFile(vector<int>& vec,int n)--input array function
           
//             * void inputFile(vector<int>& vec,int n);
//             * void insertNode(tree * ptr,int value);
//             * tree* getPivot(tree* ptr);
//             * void balancing(tree* ptr,pair<char,char> p);
//             * pair<char,char> getTypeRotation(tree* ptr);
//             * void rrRotation(tree* ptr);
//             * void llRotation(tree* ptr);
//             * void rlRotation(tree* ptr);
//             * void lrRotation(tree* ptr);
//               * void print(tree* ptr);
//               * void calculateHeight(tree* ptr);
         
// ----------------------------------------------------------------------------------*/


#include<bits/stdc++.h>
using namespace std;

struct tree{
    int val;
    int height;
    struct tree *left;
    struct tree *right;
    struct tree * parent;
};

tree *root,*node;

void inputFile(vector<int>& vec,int n);
void insertNode(tree * ptr,int value);
tree* getPivot(tree* ptr);
void balancing(tree* ptr,pair<char,char> p);
pair<char,char> getTypeRotation(tree* ptr);
void rrRotation(tree* ptr);
void llRotation(tree* ptr);
void rlRotation(tree* ptr);
void lrRotation(tree* ptr);
void print(tree* ptr);
void calculateHeight(tree* ptr);


int main(){
   root=NULL;
   vector<int> vec;
   int n;
   pair<char,char>rotationPair;
   cout<<"ENTER THE NO OF NODES "<<endl;
   cin>>n;

   inputFile(vec,n);

   for(int i{0};i<n;i++){
       insertNode(root,vec[i]);
       tree *pivot=node;
        cout<<"After Insertion"<<i+1<<endl;
        cout<<"-----------------------------------\n";
        print(root);
        cout<<"-----------------------------------\n";
       while(pivot!=NULL){
          // cout<<"inside while loop\n";
           pivot=getPivot(pivot);
           if(pivot==NULL){
             cout<<"TREE IS ALL BALANCED !!"<<endl;
             break;
           }
            cout<<"pivot is"<<pivot->val<<endl; 
           rotationPair=getTypeRotation(pivot);
           cout<<"rotating pair "<<rotationPair.first<<rotationPair.second<<endl;
           balancing(pivot,rotationPair);

           cout<<"After BALANCING"<<i+1<<endl;
            cout<<"-----------------------------------\n";
            print(root);
            cout<<"-----------------------------------\n";
       }
   }
}

void inputFile(vector<int>& vec,int n){
    int val;
  ifstream in_file("files/inputArray.txt");
    for(int i{0};i<n;i++){
        in_file>>val;
        vec.push_back(val);
    }
       
}


void insertNode(tree * ptr,int value){
    if(root==NULL){
        node=(tree *)malloc(sizeof(tree));
        node->left=NULL;
        node->right=NULL;
        node->parent=NULL;
        node->val=value;
        node->height=0;
        root=node;
        return ;
    }
    if(ptr->left==NULL && ptr->val>value){
         ptr->height+=1;
         node=(tree *)malloc(sizeof(tree));
        node->left=NULL;
        node->right=NULL;
        node->parent=ptr;
        node->val=value;
        node->height=0;
        ptr->left=node;
    }
    else if(ptr->right==NULL && ptr->val<value){
          ptr->height+=1;
         node=(tree *)malloc(sizeof(tree));
        node->left=NULL;
        node->right=NULL;
        node->parent=ptr;
        node->val=value;
        node->height=0;
        ptr->right=node;
    }
    else{
        ptr->height+=1;
        if(ptr->val>value){
           insertNode(ptr->left,value);

           }
        else{
           insertNode(ptr->right,value); 

        }  
    }
}


tree* getPivot(tree* ptr){
    if(ptr==NULL)
      return NULL;
    
    ptr=ptr->parent;
    
    if(ptr==NULL)
      return NULL;

    if(ptr->left==NULL){
        if(ptr->right->height>=1)
            return ptr;
        else

            return getPivot(ptr);
    }
    else if(ptr->right==NULL){
        if(ptr->left->height>=1)
            return ptr;
        else
            return getPivot(ptr);
    }
    else{
        if(abs(ptr->left->height-ptr->right->height)<=1)
          return  getPivot(ptr);
        else
          return ptr;
    }
    
    //return ptr;
}

void balancing(tree* ptr,pair<char,char> p){
    if(p.first=='R' && p.second=='R')
      rrRotation(ptr);
    else if(p.first=='L' && p.second=='L')
      llRotation(ptr);
    else if(p.first=='R' && p.second=='L')
      rlRotation(ptr);
    else if(p.first=='L' && p.second=='R')
      lrRotation(ptr);      
}
pair<char,char> getTypeRotation(tree* ptr){
    pair<char,char> p(0,0);
    for(int i{0};i<2;i++){
        if(ptr->left==NULL){
            ptr=ptr->right;
            if(i==0)
              p.first='R';
            else
              p.second='R'; 
        }
        else if(ptr->right==NULL){
            ptr=ptr->left;
            if(i==0)
              p.first='L';
            else
              p.second='L';  
        }else{
          if(ptr->left->height<ptr->right->height){
             ptr=ptr->right;
            if(i==0)
              p.first='R';
            else
              p.second='R';    
          }else{
            ptr=ptr->right;
            if(i==0)
              p.first='L';
            else
              p.second='L'; 
          }
        }
    } 
    return p; 
}

void rrRotation(tree* ptr){

   tree* x=ptr;
   //buuuuugggggggggggg
    while(x!=NULL){
        x->height-=1;
        x=x->parent;
    }
    tree* temp;
    temp=ptr->right;
    temp->parent=ptr->parent;
    ptr->parent=temp;
    ptr->right=temp->left;
    temp->left=ptr;
    if(ptr->right!=NULL)
       ptr->right->parent=ptr;
    if(temp->parent!=NULL){
        if(temp->parent->right->val==ptr->val)
          temp->parent->right=temp;
        else
          temp->parent->left=temp;
    }else{
      root=temp;
    }

    calculateHeight(ptr);

}

void llRotation(tree* ptr){

  tree* x=ptr->parent;
    while(x!=NULL){
        x->height-=1;
        x=x->parent;
    } 

       tree* temp;
    temp=ptr->left;
    temp->parent=ptr->parent;
    ptr->parent=temp;
    ptr->left=temp->right;
    temp->right=ptr;
    if(ptr->left!=NULL)
       ptr->left->parent=ptr;
    if(temp->parent!=NULL){
        if(temp->parent->right->val==ptr->val)
          temp->parent->right=temp;
        else
          temp->parent->left=temp;
    }else{
      root=temp;
    }

    calculateHeight(ptr);

}

void rlRotation(tree* ptr){
    llRotation(ptr->right);
    rrRotation(ptr);
}
void lrRotation(tree* ptr){
    rrRotation(ptr->left);
    llRotation(ptr);
}

void print(tree* ptr){
  if(ptr==NULL)
  return;
  else
  {
    cout<<"  |  "<<ptr->val<<"  h- "<<ptr->height<<endl;
    print(ptr->left);
    print(ptr->right);
  }
  
}

void calculateHeight(tree* ptr){
    if(ptr->left==NULL && ptr->right==NULL){
      ptr->height=0;
    }
    else if(ptr->left==NULL){
      ptr->height=ptr->right->height+1;
    }else if(ptr->right==NULL){
      ptr->height=ptr->left->height+1;
    }else{
      ptr->height=max(ptr->left->height,ptr->right->height)+1;
    }
}