#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

void FillRandMass (int *Arr, unsigned ArrSize, int range)
{
    for(unsigned i = 0; i < ArrSize; ++i)
       {
          Arr[i] = rand() % range;
       }
}
void BubbleSort(int *Arr, unsigned ArrSize, std::string cond)
{
    auto Compare = [] (int &a, int &b, std::string cond)
       {
         if(cond == "up")
           {
             return a > b ? true : false;
           }
          else
           {
             return a < b ? true : false;
           }
        };

    for(unsigned j = 1; j < (ArrSize-1); ++j)
       {
         for(unsigned i = 0; i < (ArrSize - j); ++i)
            {
               if(Compare(Arr[i],Arr[i+1],cond))
               {
                 std::swap(Arr[i], Arr[i+1]);
               }
            }
       }
}

void PrintMass(int* Array, unsigned Size)
{
    for(unsigned i = 0; i < Size; ++i)
       {
          cout<< Array[i] << " ";
       }
    cout<< endl;
}

int main()
{
    cout<< "Enter Mass Size\n" << "> ";
    unsigned Size;
    cin>> Size;
    if(Size < 2)
      {
        cout<< "Wrong Size";
        return 0;
      }
    int *Array = new(std::nothrow) int[Size];
    if(!Array)
      {
         std::cout << "Could not allocate memory";
         return 0;
      }
    cout<< "Before sort:\n";
    FillRandMass(Array, Size, 50);
    PrintMass(Array,Size);
    cout<< "Chose the way to sort 'up' or 'down'\n" << "> ";
    std::string choise;
    cin>> choise;

    if(choise == "up")
      {
        BubbleSort(Array,Size,"up");
      }
    else if (choise == "down")
      {
        BubbleSort(Array,Size,"down");
      }
    else
    {
        cout<< "wrong param";
        return 0;
    }

    cout<< endl << "After" << endl;
    PrintMass(Array,Size);

    delete [] Array;
    return 0;
}
