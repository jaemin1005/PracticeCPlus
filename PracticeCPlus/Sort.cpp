//
//  Sort.cpp
//  PracticeCPlus
//
//  Created by 황재민 on 5/4/24.
//

#include <iostream>
using namespace std;
int* Sort(int nNum);

int *Sort(int nNum){
  int* nArr = new int[nNum];
  int nTemp;

  for(int nIdx=0; nIdx< nNum; nIdx++){
    
    cin >> nArr[nIdx];
  }

  for(int i=0; i<nNum-1; i++){
    for(int j=0; j<nNum-(i+1); j++){
      if(nArr[j] > nArr[j+1]){
        nTemp = nArr[j];
        nArr[j] = nArr[j+1];
        nArr[j+1] = nTemp;
      }
    }
  }

  return nArr;
}
