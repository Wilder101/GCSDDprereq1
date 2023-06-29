#ifndef INVENTORY_H
#define INVENTORY_H

/*  Wilder Molyneux
*   University of Washington | Bothell (UWB)
*   Graduate Certificate in Software Design and Development (GCSDD)
*   Prerequisite Sample Coursework
*   May 14, 2023
* 
*   Dr. Emily M. Bender Rule: C++
* 
*   From UWB Computing & Software Systems (CSS) 142:
*   Programming Competency Self-Assessment: First Assessment (one of four)
*   "Batch processing at a soft drink distributorship"
* 
*   inventory.h
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// SoftDrinkInventory class declaration
class SoftDrinkInventory 
{
  public:       
    SoftDrinkInventory();     // Constructor 
    ~SoftDrinkInventory();    // Destructor 
    
    // Public methods
    int buildInventory(const string& inputInventoryFile);
    int processTransactions(const string& inputTransactionsFile);
    void displayReport();
    
  private:
    // Private variables
    string* softDrinkName;
    string* softDrinkID;   
    int* startingInventory;
    int* finalInventory;
    int* transactionCount;
    int inventoryCount;       // total unique IDs in inventory

    // Static constant for maximum inventory capacity
    static const int MAX_INVENTORY = 100;
    
    // Helper methods
    void initializeString(string* stringName);
    void initializeInt(int* intName);
    int findID(const string& searchID);
};

#endif
