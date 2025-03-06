##Result of Turkey Election 2023 📜

# Overview 🌍

This program is designed to log user inputs and program outputs related to 2023 Turkey election data. It interacts with various classes to retrieve election-related information and stores user activities and the output that what does users want in a text file that named election.txt.

# Features ✨

Logs user selections and program responses in election.txt.

Clears the log file at the start of each execution.

Supports election-related queries, including:

-- Finding the mayor of a city 🏛️

-- Determining the winning party 🎉

-- Calculating vote percentages 📊

-- Ensures valid user inputs for both operation choice and city plaque numbers.

# Dependencies 📌

Election.cpp

Mayority.cpp

WinnerParty.cpp 

Percentage.cpp

Cities.cpp

Election.h

Mayority.h

WinnerParty.h

Percentage.h

Cities.h

Standard C++ libraries (fstream, iostream)

# How It Works ⚙️

The program prompts the user to choose an election-related operation.

The user provides a valid city plaque number.

Based on the user's selection, the program fetches and logs relevant election data.

The program asks whether the user wants to perform another search.

All actions and inputs are logged in election.txt.

The log file is cleared every time the program restarts.

# How to Run ▶️

Compile the program with a C++ compiler (g++ main.cpp Election.cpp Cities.cpp WinnerParty.cpp Percentage.cpp Mayority.cpp -o main).

Execute the program (.\main.exe).

Follow on-screen instructions to interact with election data.

# Notes 📝

Ensure that the header files and necessary dependencies are included in the project directory.

The log file (election.txt) is erased at the start of every execution to prevent data accumulation.

This program provides detailed information about the 2023 Turkish elections, including:

City Mayor 🏛️ - The elected mayor of a selected city.

Winning Party 🎉 - The political party that won in the selected city.

Vote Percentages 📊 - The percentage of votes each party received in the selected city.
