#include <iostream>
#include "tads/arrays.cpp"
using namespace std;


void mostrarPila(int* p,int largo){
  for (int i=largo-1;i>-1;i--){
    cout<< "ELEM:" << i << " "<< p[i] <<endl;
  }
}

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

int pilaMinSuma(int a,int b,int c){
  if (a<=b && a<=c){
    return 1;

  }
  if (b<=a && b<=c){
    return 2;
  }
  if (c<=a && c<=b){
    return 3;
  }
}

int main(){
  
  int cant1;
  int cant2;
  int cant3;
  int sum1=0;
  int sum2=0;
  int sum3=0;
  int min;
  cin >> cant1;
  int* p1= new int[cant1];
  for (int i=cant1-1;i>-1;i--){
    int dato;
    cin>> dato;
    sum1+=dato;
    p1[i]=dato;
    
  }
  cin >> cant2;
  int* p2= new int[cant2];
  for (int i=cant2-1;i>-1;i--){

    int dato;
    cin>> dato;
    sum2+=dato;
    p2[i]=dato;
    
  }
  cin>>cant3;
  int* p3= new int[cant3];
  for (int i=cant3-1;i>-1;i--){
    int dato;
    cin>> dato;
    sum3+=dato;
    p3[i]=dato;
  }
  min = minimo(cant1,cant2,cant3);
  int k=0;
  
  while(k<=min ||  (sum1 != sum2) && (sum1!= sum3) && (sum2 != sum3)){
    
    int minSuma= pilaMinSuma(sum1,sum2,sum3);
    
    if (minSuma==1){
      while (sum2>sum1){
        sum2-=p2[cant2-1];
        
        cant2--;
      }
      while (sum3>sum1){
        sum3-=p3[cant3-1];
        cant3--;
      }
    }else if (minSuma==2){
      while (sum1>sum2){
        sum1-=p1[cant1-1];
        cant1--;
      }
      while (sum3>sum2){
        sum3-=p3[cant3-1];
        cant3--;
      }
    }else if(minSuma==3){
      sum3-=p3[cant3-1];
      cant3--;
      while(sum2>sum3){
        sum2-=p2[cant2-1];
        cant2--;

      }
      while(sum1>sum3){
        sum1-=p1[cant1-1];
        cant1--;

      }
    }
    k++;
  }
  
  cout << sum1 << endl;
  return 0;
}