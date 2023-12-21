// Shashwat Adhikary

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct Element 
{
    string symbol;
    string name;
    int atomicNo = 0;
    double atomicweight=0.0;
    bool active = true;
};

void setElements(Element elements[]) 
{
    int i;

    for (i = 0;elements[i].atomicNo != 0;) 
    {
        i++;
    }

    cout << "Enter symbol( Capital) " << endl;
    cin >> elements[i].symbol;

    cout << "Enter name " << endl;
    cin >> elements[i].name;

    cout << "Enter atomic Number: " << endl;
    cin >> elements[i].atomicNo;

    cout << "Enter atomic weight: " << endl;
    cin >> elements[i].atomicweight;

}

void searchElements(Element elements[], string s) 
{
    bool b = false;
    for (int i = 0;elements[i].atomicNo != 0; i++) 
    {
        if (elements[i].symbol == s && elements[i].active == true) 
        {
            b = true;
            cout << "Element Name: " << elements[i].name << endl;
            cout << "Element atomic Number: " << elements[i].atomicNo << endl;
            cout << "Element atomic Weight: " << elements[i].atomicweight << endl;

        }
    }
    if (b == false) 
    {
        cout << "Element Not found" << endl;
    }
}
void changeVisibility(Element elements[], string s) 
{
    bool b = false;
    for (int i = 0;elements[i].atomicNo != 0;i++) 
    {
        if (elements[i].symbol == s) 
        {
            elements[i].active = false;
            b = true;
        }
    }
    if (b == false) 
    {
        cout << "Element not found " << endl;
    }

}
void elementsOftextFiles() {
    fstream newfile;

    newfile.open("C:/Users/shash/OneDrive/Documents/Northlake/2022 Fall/COSC 1436/elements.txt", ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()) 
    {   //checking whether the file is open
        string tp;
        while (getline(newfile, tp)) { //read data from file object and put it into string.
            cout << tp << endl; //print the data of the string
        }
        newfile.close(); //close the file object.
    }
}

bool compareSymbol(Element a, Element b) 
{

    return a.symbol < b.symbol;

}

void sortedElements(Element elements[]) 
{
    int size = 0;

    for (int i = 0; elements[i].atomicNo != 0;i++) 
    {
        size++;
    }

    sort(elements, elements + size, compareSymbol);
    cout << "Symbol" << setw(10) << "Name" << setw(15) << "AtomicNo" << setw(15) << "AtomicWeight" << endl;
    for (int i = 0;i < size;i++) 
    {
        cout << elements[i].symbol << setw(15) 
             << elements[i].name << setw(15) 
             << elements[i].atomicNo << setw(15) 
             << elements[i].atomicweight << endl;
    }
}

int main() 
{
    Element elements[50];

    int c;
    string e;

    do 
    {
        cout << "Select an option number from the following menu: " << endl;
        cout << "Option" << setw(10) << "Action" << endl;
        cout << right << "1 " << setw(15) << "Define a chemical name." << endl;
        cout << right << "2 " << setw(15) << "Search for an element." << endl;
        cout << right << "3 " << setw(15) << "Change the visibility of an element." << endl;
        cout << right << "4 " << setw(15) << "Define element from a text file." << endl;
        cout << right << "5 " << setw(15) << "Display the elements sorted by symbol." << endl;
        cout << right << "6" << setw(15) << "Quit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> c;

        switch (c)
        {
        case 1:
            setElements(elements);
            break;

        case 2:
            cout << "Enter symbol(capital) to search your elements " << endl;
            cin >> e;
            searchElements(elements, e);
            break;

        case 3:
            cout << "Enter symbol(capital) to search your elements " << endl;
            cin >> e;
            changeVisibility(elements, e);
            break;

        case 4:
            elementsOftextFiles();
            break;

        case 5:
            sortedElements(elements);
            break;

        case 6:
            cout << "program exited" << endl;
            break;

        default:
            cout << "Enter correct choice!" << endl;
            break;
        }


    } while (c != 6);

    return 0;
}
