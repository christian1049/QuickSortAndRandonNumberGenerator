/**
 * @file QuickSort.cpp
 * @author Christian Lee
 * @brief
 * @version 0.1
 * @date 2022-11-29
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

void QuickSort(float arr[], int l, int r, int s);

int main(int argc, char **arg)
{

    ifstream inFile;
    ifstream infile2;
    infile2.open("input.txt");
    inFile.open("input.txt");
    int n = 0;
    float num;

    while (inFile >> num)
    {
        n++;
    }
    float arr[n];

    n = 0;
    while (!infile2.eof())
    {
        infile2 >> arr[n];
        n++;
    }
    auto start = high_resolution_clock::now();

    int swap = 1;
    QuickSort(arr, 0, n, swap);

    auto total = high_resolution_clock::now() - start;
    double finalTime = duration_cast<microseconds>(total).count();
    string milliseconds = to_string(finalTime / 1000);
    ofstream outFile;
    outFile.open("output.txt");
    // Prints elements of array to out file
    for (int i = 0; i < n; i++)
    {
        outFile << arr[i] << " ";
    }

    outFile << "\n"
            << milliseconds << " seconds"
            << "\n";
    infile2.close();
    inFile.close();
}

void QuickSort(float arr[], int l, int r, int s)
{
    // Stops recursion once it is unary

    if (l >= r)
    {
        return;
    }
    int indexI = l;
    int indexJ = r;
    // Swaps first element with random element
    if (s == 1)
    {
        srand((unsigned)time(NULL));
        int random = rand() % r;
        float temp = arr[random];
        arr[random] = arr[0];
        arr[0] = temp;
        s = 0;
    }

    while (indexI < indexJ)
    {
        // Moves the i index and stops if greater than pivot
        for (int i = indexI + 1; i <= r - 1; i++)
        {
            if (arr[i] > arr[l])
            {
                indexI = i;
                break;
            }
            if (i == r - 1)
            {
                indexI = r - 1;
            }
        }
        // Moves the j index and stops if less than pivot
        for (int j = indexJ - 1; j >= l; j--)
        {
            if (arr[j] < arr[l])
            {
                indexJ = j;
                break;
            }
            if (j == l)
            {
                indexJ = l;
            }
        }
        if (indexI > indexJ)
        {
            break;
        }
        // Swaps i and j index
        float temp2 = arr[indexI];
        arr[indexI] = arr[indexJ];
        arr[indexJ] = temp2;
    }
    // Swaps the pivot with j index
    float temp3 = arr[l];
    arr[l] = arr[indexJ];
    arr[indexJ] = temp3;
    // Recursively calls function
    QuickSort(arr, l, indexJ, 0);
    QuickSort(arr, indexJ + 1, r, 0);
}