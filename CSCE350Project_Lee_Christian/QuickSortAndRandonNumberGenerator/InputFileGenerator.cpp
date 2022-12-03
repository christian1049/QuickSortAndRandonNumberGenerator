#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void createFile();

int main()
{
    createFile();
}

void createFile()
{
    ofstream myFiles;
    srand((unsigned)time(NULL));
    for (int i = 0; i < 25; i++)
    {
        string fileName = "inputSize_10_FileNumber_" + to_string(i + 1);
        myFiles.open("C:\\Users\\chris\\OneDrive\\Desktop\\School\\CSCE350\\Project\\10_input\\" + fileName);
        for (int i = 0; i < 10; i++)
        {
            double random = -500 + static_cast<float>(rand() / static_cast<float>(RAND_MAX / (500 - (-500))));
            myFiles << random << " ";
        }
        myFiles.close();
    }
    for (int i = 0; i < 25; i++)
    {
        string fileName = "inputSize_100_FileNumber_" + to_string(i + 1);
        myFiles.open("C:\\Users\\chris\\OneDrive\\Desktop\\School\\CSCE350\\Project\\100_input\\" + fileName);
        for (int i = 0; i < 10; i++)
        {
            double random = -500 + static_cast<float>(rand() / static_cast<float>(RAND_MAX / (500 - (-500))));
            myFiles << random << " ";
        }
        myFiles.close();
    }
    for (int i = 0; i < 25; i++)
    {
        string fileName = "inputSize_1000_FileNumber_" + to_string(i + 1);
        myFiles.open("C:\\Users\\chris\\OneDrive\\Desktop\\School\\CSCE350\\Project\\1000_input\\" + fileName);
        for (int i = 0; i < 10; i++)
        {

            double random = -500 + static_cast<float>(rand() / static_cast<float>(RAND_MAX / (500 - (-500))));
            myFiles << random << " ";
        }
        myFiles.close();
    }
}