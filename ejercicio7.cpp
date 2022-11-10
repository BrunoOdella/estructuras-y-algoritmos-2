#include <iostream>
#include "tads/arrays.cpp"
using namespace std;

int minimo(int a, int b, int c){
  if (a<=b && a<=c){
    return a;

  }
  if (b<=a && b<=c){
    return b;
  }
  if (c<=a && c<=c){
    return c;
  }
}

int maximo(int a,int b,int c){
  if (a>=b && a>=c){
    return a;

  }
  if (b>=a && b>=c){
    return b;
  }
  if (c>=a && c>=c){
    return c;
  }
}

int main(){
  int* p1;
  int* p2;
  int* p3;
  int cant1;
  int cant2;
  int cant3;
  int sum1=0;
  int sum2=0;
  int sum3=0;
  int min;
  cin >> cant1;
  for (int i=cant1-1;i>-1;i--){
    int dato;
    cin>> dato;
    sum1+=dato;
    p1[i]=dato;
  }
  cin >> cant2;
  for (int i=cant2-1;i>-1;i--){
    int dato;
    cin>> dato;
    sum2+=dato;
    p2[i]=dato;
  }
  cin>>cant3;
  for (int i=cant3-1;i>-1;i--){
    int dato;
    cin>> dato;
    sum3+=dato;
    p3[i]=dato;
  }
  min = minimo(cant1,cant2,cant3);
  int k=0;
  int ret;
  while (k<min && sum1 != sum2 != sum3){
    
    
    while (sum1 < ret)
    



  }
  
  




    
    
  
  return 0;
}