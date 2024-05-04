//
//  AddSum.cpp
//  PracticeCPlus
//
//  Created by 황재민 on 5/4/24.
//

#include <stdio.h>
#include <iostream>
using namespace std;


void AddSum(int nCount, int nNum)
{
    int nDigit = 1;
    int nTotal = 0;
    
    for(int nIdx = 0 ; nIdx < nCount ; nIdx++){
        nDigit *= 10;
        nTotal += (nNum % nDigit) / (nDigit / 10);
    }
    
    cout << nTotal;
}
