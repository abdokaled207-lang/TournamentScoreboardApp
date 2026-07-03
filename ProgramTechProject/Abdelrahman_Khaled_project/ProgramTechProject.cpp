#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


// Structure to define participant data
struct Participant 
{
    int id;
    string name;
    string team;
    double score;
};

// Function prototypes using pointers
void addParticipant(Participant* list, int& count);
void updateScore(Participant* list, int count);
void displayScoreboard(Participant* list, int count);
void saveData(Participant* list, int count);
void loadData(Participant* list, int& count);

const int MAX = 100;

int main() 
{      
    Participant* tournamentList = new Participant[MAX];     // Dynamic memory allocation using pointers [1]
  
    int count = 0;                                   // Variable to track the current number of participants
   
    int choice;                                      // Variable to store the user's menu choice

    loadData(tournamentList, count);                  // Load existing records from file at startup

    do                   // Display the main menu 
    {
        cout << "\n--- Tournament System Menu ---\n";
        cout << "1. Register Participant\n";
        cout << "2. Update Score\n";
        cout << "3. Display Scoreboard\n";
        cout << "4. Save and Exit\n";
        cout << "Enter your choice: ";
       
        while (!(cin >> choice))                        // Input validation to prevent invalid menu entries
        {
            cout << "Invalid choice! Enter a number: ";
            cin.clear();                                // Clear error flags
            cin.ignore(1000, '\n');                     // Ignore invalid input
        }

      switch (choice)                                // Execute the selected menu option
      {
      case 1: addParticipant(tournamentList, count);  // Add a new participant to the tournament
          break;

      case 2: updateScore(tournamentList, count);     // Update the score of an existing participant
          break;

      case 3: displayScoreboard(tournamentList, count);  // Display all participant records and scores
          break;

      case 4:saveData(tournamentList, count);            // Save all participant data before exiting
          cout << "Data saved. Exiting program. Goodbye!\n";
          break;

      default:                                            // Handle invalid menu selections
          cout << "Invalid choice! Please try again.\n";
      }
    } while (choice != 4);
                                                          // Release dynamically allocated memory to prevent memory leaks
    delete[] tournamentList;
    return 0;
}

/* Function to add a new participant to the pointer-based array*/

void addParticipant(Participant* list, int& count) 
{
    if (count >= MAX)                                   // Prevent adding participants beyond the maximum limit
    {
        cout << "Tournament list is full!\n";
        return;
    }

    cout << "\n--- Register New Participant ---\n";
    cout << "Enter ID: ";                            // Input participant ID
   
    while (!(cin >> list[count].id))                 // Validate numeric ID input
    {
        cout << "Invalid input. Please enter a valid ID: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
   
    for (int i = 0; i < count; i++)                 // Check if the ID already exists
    {
        if (list[i].id == list[count].id) {
            cout << "Error: ID already exists!\n";
            return;
        }
    }
    cout << "Enter Name: "; 
    cin >> list[count].name;            // Input participant name
    cout << "Enter Team: ";
    cin >> list[count].team;           // Input participant team
  
    cout << "Enter Initial Score: ";         // Input participant score
   
    while (!(cin >> list[count].score) || list[count].score < 0 )   // Validate score input and prevent invalid values
    {
        cout << "Invalid! Please enter a positive numeric score: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    count++;                                        // Increase participant count after successful registration
    cout << "Participant added successfully!\n";
}
/* Function to display all participants using pointer indexing */

void displayScoreboard(Participant* list, int count) 
{
    if (count == 0)         // Check if the participant list is empty
    {
        cout << "No participants registered yet.\n";
        return;
    }
    // Display scoreboard header                                                           
    cout << "\n--- Tournament Scoreboard ---\n";
    cout << left                                                    
        << setw(10) << "ID"
        << setw(20) << "Name" 
        << setw(20) << "Team"                                          
        << setw(10) << "Score" << endl;

    cout << "-----------------------------------------------------------\n";

    // Display participant information 
    for (int i = 0; i < count; i++)
    {
        cout << left 
            << setw(10) << list[i].id 
            << setw(20) << list[i].name 
            << setw(20) << list[i].team 
            << setw(10) << list[i].score << endl;
    }       
}

/* Function to update score by searching for ID  */

void updateScore(Participant* list, int count) {
    int searchID;
    bool found = false;

    cout << "Enter ID to update: ";   

    while (!(cin >> searchID))                // Validate numeric ID input
    {
        cout << "Invalid input. Please enter a valid ID: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    for (int i = 0; i < count; i++)        // Search for the participant by ID
    {
        if (list[i].id == searchID)
        {
            cout << "Enter new score: ";     

            while (!(cin >> list[i].score) || list[i].score < 0)      // Validate score input
            {
                cout << "Invalid! Please enter a positive numeric score: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            found = true;
            cout << "Score updated successfully!\n";
            break;
        }
    }                               /* Display error message if ID is not found*/
    if (!found)              // Flag is used to check if ID exists after completing the search loop
    { 
        cout << "Error: ID not found.\n";            
    }                                          
}                                             

/* File I/O: Save data to database.txt*/

void saveData(Participant* list, int count) 
{
    ofstream outFile("database.txt");

    if (!outFile)                          // Check if file opened successfully               
    {                                                         
        cout << "Error: Could not open file for saving.\n";
        return;
    }

    for (int i = 0; i < count; i++)        // Save participant data using ' space ' as delimiter
    {                                            
        outFile << list[i].id << " "
                << list[i].name << " "
                << list[i].team << " "
                << list[i].score << endl;
    }
    outFile.close();
}
/* File I/O: Load data from database.txt */

void loadData(Participant* list, int& count)
{
    ifstream inFile("database.txt");

    if (!inFile)                            // Check if file exists and opened successfully
    {
        cout << "No existing data file found.\n";
        return;
    }
	count = 0;                             // Reset count before loading new data

    while (count < MAX &&                   // Load data safely without exceeding array size
        inFile >> list[count].id
        >> list[count].name
        >> list[count].team
        >> list[count].score)
    {
        count++;
    }
}