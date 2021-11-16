#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void PrintRow(int** a, const int rowNo, const int colCount, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < colCount - 1)
        PrintRow(a, rowNo, colCount, colNo + 1);
    else
        cout << endl;
}
void PrintRows(int** a, const int K, const int N, int rowNo)
{
    PrintRow(a, rowNo, N, 0);
    if (rowNo < K - 1)
        PrintRows(a, K, N, rowNo + 1);
    else
        cout << endl;
}
void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateRows(int** a, const int K, const int N, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, N, Low, High, 0);
    if (rowNo < K - 1)
        CreateRows(a, K, N, Low, High, rowNo + 1);
}

bool ZeroElem(int** a, const int colCount, int rowNo, int colNo, bool z)
{
    if (a[rowNo][colNo] == 0)
    {
        z = true;
    }


    if (colNo < colCount - 1)
         ZeroElem(a, colCount, rowNo, colNo + 1, z);
    else return z;

}

int NumbRowZeros(int** a, const int rowCount, const int colCount, int rowNo, int k)
{
    if (ZeroElem(a, colCount, rowNo, 0, false) == true)
        k++;

    if (rowNo < rowCount - 1)
        NumbRowZeros(a, rowCount, colCount, rowNo + 1, k);

    else
        return k;
}




int NumbIdentElem(int** a, const int colCount, int rowNo, int colNo, int elem, int k)
{
    
    if (elem == a[rowNo][colNo])
        k++;
    if (colNo < colCount - 1)
        NumbIdentElem(a, colCount, rowNo, colNo + 1, elem, k);
    else return k;

}

int maxNumbIdentElem(int** a, const int colCount, int rowNo, int colNo, int maxkil)
{
    if (NumbIdentElem(a, colCount, rowNo, 0, a[rowNo][colNo], 0) > maxkil)
    {
        maxkil = NumbIdentElem(a, colCount, rowNo, 0, a[rowNo][colNo], 0);
        
    }

    if (colNo < colCount - 1)
        maxNumbIdentElem(a, colCount, rowNo, colNo + 1, maxkil);
    else return maxkil;
}

void NomRowMaxSer(int** a, const int rowCount, const int colCount, int rowNo, int nomr, int max)
{
    if (maxNumbIdentElem(a, colCount, rowNo, 0, 0) > max)
    {
        max = maxNumbIdentElem(a, colCount, rowNo, 0, 0);
        nomr = rowNo;
    }

    if (rowNo < rowCount - 1)
        NomRowMaxSer(a, rowCount, colCount, rowNo + 1, nomr, max);
    else cout << "nomer ryadka = " << nomr;

}


int main()
{
    srand((unsigned)time(NULL));
    int Low = -17;
    int High = 15;

    int rowCount, colCount;

    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    CreateRows(a, rowCount, colCount, Low, High, 0);
   

    PrintRows(a, rowCount, colCount, 0);

    cout << "kilkist ryadkiv z zero = " << NumbRowZeros(a, rowCount, colCount, 0, 0) << endl;

    NomRowMaxSer(a, rowCount, colCount, 0, 0, 0);


    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;

}