#include <iostream>

#include <vector>

using namespace std;

vector<int> helper;

long long inv_count(vector<int>&a , int l , int r){

 if(l >= r - 1 ) return 0;

 int m = (l + r) / 2;

 long long x= inv_count (a , l , m);

 long long y = inv_count(a , m , r);

 long long q=0;

 for(int i= l , j= m ; i < m; i++){

 while(j < r && a[i] > a[j]) j++;

 q+=j - m;

 } 

 for(int k=l , i=l , j=m; k < r; k++){

 helper[k]=a[i==m ? j++ :j == r ? i++:a[i]<a[j]? i++: j++];

 }

 for(int i=l ; i < r ; i++)

 a[i]=helper[i];

 return q + x +y;

}

int main (){

 int n;
  cin>>n;

 vector<int> a(n);

 for(int i=0 ; i < n ; i++)

 cin>>a[i];

 helper.resize(n);

 cout<<inv_count(a , 0 , n);

 return 0;

}
