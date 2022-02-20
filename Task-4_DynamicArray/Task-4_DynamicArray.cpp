#include <iostream>
#include "ArrayFormatter.h"

using namespace std;

int** initArray(int rows, int cols)
{
   int** arr = new int* [rows];

   for (int row = 0; row < rows; row++)
   {
      for (int col = 0; col < cols; col++)
      {
         arr[row] = new int[col];
      }
   }

   return arr;
}

void fillArray(int** arr, int rows, int cols)
{
   for (int row = 0; row < rows; row++)
   {
      for (int col = 0; col < cols; col++)
      {
         arr[row][col] = rand() % 10 + 1;
         cout << arr[row][col] << endl;
      }
   }
}



int main()
{
   int cols = rand() % 11 + 1;
   int rows = rand() % 10 + 1;

   int** dynamicArray = initArray(rows, cols);

   fillArray(dynamicArray, rows, cols);

   cout << "cols count = " << cols << endl;

   ArrayFormatter* formatter = new ArrayFormatter(cols);
   cout << formatter->format(dynamicArray, cols, rows) << endl;
}


