/*  Wilder Molyneux
*   University of Washington | Bothell (UWB)
*   Graduate Certificate in Software Design and Development (GCSDD)
*   Prerequisite Sample Coursework
*   May 14, 2023
* 
*   Dr. Emily M. Bender Rule: C++
* 
*   From UWB Computing & Software Systems (CSS) 142:
*   Programming Competency Self-Assessment: First Assessment (one four)
*   "Batch processing at a soft drink distributorship"
*   
*   inventory.cpp
*/

#include "inventory.h"

// SoftDrinkInventory class implementations

// Constructor: "Initializes arrays holding soft drink name and ID to hold all 
// empty strings (calls intitializeString twice to perform the tasks). 
// Initializes arrays holding starting inventory, final inventory, 
// and the counts of the number of transaction to zero (calls initializeInt 
// three times to perform the tasks)."
SoftDrinkInventory::SoftDrinkInventory()
{
    softDrinkName = new string[MAX_INVENTORY];
    softDrinkID = new string[MAX_INVENTORY];
    startingInventory = new int[MAX_INVENTORY];
    finalInventory = new int[MAX_INVENTORY];
    transactionCount = new int[MAX_INVENTORY];
    inventoryCount = 0;

    initializeString(softDrinkName);
    initializeString(softDrinkID);
    initializeInt(startingInventory);
    initializeInt(finalInventory);
    initializeInt(transactionCount);
}

// Destructor deallocates array memory
SoftDrinkInventory::~SoftDrinkInventory()
{
    delete [] softDrinkName;
    delete [] softDrinkID;
    delete [] startingInventory;
    delete [] finalInventory;
    delete [] transactionCount;
}

// Initialize string method
void SoftDrinkInventory::initializeString(string* stringName)
{
    for (int i = 0; i < MAX_INVENTORY; i++)
    {
        stringName[i] = "";
    }
}

// Initialize int method
void SoftDrinkInventory::initializeInt(int* intName)
{
    for (int i = 0; i < MAX_INVENTORY; i++)
    {
        intName[i] = 0;
    }
}

// Build inventory: "Sets the arrays for soft drink name, ID, and starting 
// inventory from information in the data file. The array holding final 
// inventory is set to the same values as the starting inventory."
int SoftDrinkInventory::buildInventory(const string& inputInventoryFile)
{
    // Prepare to read inventory file data
    ifstream inFile;
    inFile.open(inputInventoryFile);
    
    // Check for file opening failure
    if (inFile.fail())
    {
        cout << "Error opening " << inputInventoryFile << " file." << endl;
        return 1;    // terminate gracefully
    }
    
    // Read inventory file data
    int lineCounter = 0;
    while(!inFile.eof())
    {
        inFile >> softDrinkName[lineCounter];
        inFile >> softDrinkID[lineCounter];
        inFile >> startingInventory[lineCounter];
        
        lineCounter++;
    }
    
    // Copy starting inventory values to final inventory
    for (int i = 0; i < lineCounter; i++) 
    {
        finalInventory[i] = startingInventory[i];
    }
    
    // Update inventory count based on inventory read
    inventoryCount = lineCounter;    
    
    inFile.close();
    return 0;
}

// Process transactions: "Processes the transactions by correctly adjusting the 
// final inventory and transaction counts arrays. Data for IDs which don't exist 
// are not processed."
int SoftDrinkInventory::processTransactions(const string& inputTransactionsFile)
{
    // Local variables
    string dataInID = "";
    int dataInQuantity = 0;
    
    // Prepare to read transactions file data
    ifstream inFile;
    inFile.open(inputTransactionsFile);
    
    // Check for file opening failure
    if (inFile.fail())
    {
        cout << "Error opening " << inputTransactionsFile << " file." << endl;
        return 1;    // terminate gracefully
    }
    
    // Read transactions file data
    int lineCounter = 0;
    while(!inFile.eof())
    {
        inFile >> dataInID;
        inFile >> dataInQuantity;
        lineCounter++;
        
        // Check to see if read-in ID is in the inventory
        int tempIDindex = findID(dataInID);
        
        // Process if valid, ignore otherwise
        if (tempIDindex >= 0)
        {
            finalInventory[tempIDindex] = finalInventory[tempIDindex] + dataInQuantity;
            transactionCount[tempIDindex] = transactionCount[tempIDindex] + 1;
        }
    }
    
    inFile.close();
    return 0;
}

// findID: "Takes an ID parameter and returns the position in the array 
// (the subscript) where the soft drink with that ID is found. Return -1 
// if the ID is not found."
int SoftDrinkInventory::findID(const string& searchID)
{
    for (int i = 0; i < MAX_INVENTORY; i++)
    {
        if (softDrinkID[i] == searchID)
        {
            return i;    // ID found
        }
    }
    
    return -1;           // ID not found
}

// Display report: "Displays a report including soft drink name, ID, starting 
// inventory, final inventory, and number of transactions processed."
void SoftDrinkInventory::displayReport()
{
    // Display field sizes
    const int SMALL = 7;
    const int MEDIUM = 15;
    const int LARGE = 19;
    const int XLARGE = 23;
    
    // Display report results
    cout << "Soft drink     ID     Starting Inventory     Final Inventory    # transactions" << endl;
    
    for (int i = 0; i < inventoryCount; i++)
    {
        cout << setw(MEDIUM);
        cout << left << softDrinkName[i];
        
        cout << setw(SMALL);
        cout << softDrinkID[i];
        
        cout << setw(XLARGE);
        cout << startingInventory[i];
        
        cout << setw(LARGE);
        cout << finalInventory[i];
        cout << transactionCount[i] << endl;
    }
    cout << endl;
}
