#include <fstream>
#include "Function.h"
#include "Linked.h"
using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("data.txt");
    if (!inFile.is_open()) {
        cout << "Error opening files";
        return 1;
    }
    Linked list1;
    readFile(inFile, list1);
    list1.printList();
}