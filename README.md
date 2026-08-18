# 🏆 Tournament Scoreboard System

## Description
A robust, console-based application designed for managing and tracking participant scores in various tournaments or competitions. This system allows users to maintain accurate records of participants, update live scores, and view a comprehensive, formatted scoreboard. It ensures data persistence by saving all records to local files (`database.txt`) and loading them automatically upon startup.

## ✨ Features
*   **Participant Registration:** Add new competitors with unique IDs, names, teams, and initial scores.
*   **Live Scoreboard Display:** Presents a clean, tabular view of all participants and their current rankings/scores.
*   **Score Updating:** Easily modify the score of an existing participant using their unique ID.
*   **Data Persistence (I/O):** Automatically saves the entire dataset to `database.txt` upon exit and loads it when the application starts, ensuring no data loss between sessions.
*   **Input Validation:** Includes checks for invalid inputs (e.g., non-numeric IDs or negative scores) to maintain data integrity.

## 💻 Technology Stack
*   **Language:** C++
*   **Platform:** Console/Command Line Interface (CLI)
*   **Core Concepts Demonstrated:** Object-Oriented Programming (OOP), Dynamic Memory Allocation, File Input/Output (File I/O).

## 🚀 How to Run
1.  **Prerequisites:** Ensure you have a C++ compiler installed (e.g., g++ or Visual Studio).
2.  **Compilation:** Navigate to the project directory (`ProgramTechProject/Abdelrahman_Khaled_project/`) and compile the source file:
    ```bash
    # Example using g++
    g++ ProgramTechProject.cpp -o TournamentApp
    ```
3.  **Execution:** Run the compiled executable from your terminal:
    ```bash
    ./TournamentApp
    ```

***
*Developed as a foundational project to demonstrate proficiency in C++ programming, data structure management, and file handling.*