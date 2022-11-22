#include <iostream>
#include "tads/arrays.cpp"
using namespace std;
#define INF 99999 

// int min(int a, int b){
//     return a<=b ? a : b;
// }

int main(){
    int cantElem, cota, cantSumas;
    cin >> cantElem;
    int* elementos = new int[cantElem];
    for(int i=1; i<= cantElem; i++){
        cin >> elementos[i-1];
    }
    cin >> cota;
    cin>> cantSumas;
    int* sumas = new int[cantSumas];
    for(int i=1; i<= cantSumas; i++){
        cin >> sumas[i-1];
    }
    int** matDP = new int*[cantElem];
    for(int i=0; i<cantElem; i++){
        matDP[i] = new int[cota+1];
    }

    for(int i=0; i<cantElem; matDP[i++][0]=0);
    for(int j=0; j<=cota; j++){
        matDP[0][j] = j%elementos[0]==0 ? j/elementos[0] : INF;
    }

    for(int i=1; i<cantElem; i++){
        for(int j=1; j<=cota; j++){
            if(j<elementos[i]){
                matDP[i][j] = matDP[i-1][j];
            } else {
                matDP[i][j] = min(matDP[i-1][j], 1+matDP[i][j-elementos[i]]);
            }
        }
    }
    for (int i=0; i<cantSumas ; i++){
        int min=INF;
        for (int k=0;k<cantElem;k++){
          if ((matDP[k][sumas[i]])<min){
            min=matDP[k][sumas[i]];
          }
        }
        if(min==INF){
          cout << "0" << endl;
        }else {
          cout << "1" << endl;
        }
        
    }
    delete [] elementos;
    delete [] sumas;






 
    
    return 0;
}