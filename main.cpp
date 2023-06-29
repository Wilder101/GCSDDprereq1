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
*   main.cpp
*/

#include "inventory.h"

// Main program
int main() 
{
    // Inventory file names
    const string inventoryFile = "data6.txt";
    const string transFile = "data6trans.txt";
       
    // Instantiate the soft drink distributorship object
    SoftDrinkInventory softDrinks; 
    
    // Process the transactions
    softDrinks.buildInventory(inventoryFile);     
    softDrinks.processTransactions(transFile);  

    // Display the results
    softDrinks.displayReport();
    cout << "Thank you for using Soft Drink Inventory Inc." << endl;
    
    return 0;
}
