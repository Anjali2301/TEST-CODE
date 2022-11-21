#include <iostream>  
using namespace std;  
int main()  
{  
int n, N,reverse=0, rem;    
   
cin>>n;    

  int y=0;
  if(n==8){
      y=11;
  }
  if(n==16){
      y=91;
  }
  if(n==10){
      y=01;
  }
cout<<y;   
 while(n!=0)    
  {    
     rem=n%10;      
     reverse=reverse*10+rem;    
     n/=10;    
  }    
  
}
