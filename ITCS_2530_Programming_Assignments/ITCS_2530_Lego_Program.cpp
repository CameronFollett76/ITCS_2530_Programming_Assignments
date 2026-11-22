#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;

const int MAX_SETS = 50;

enum BuilderTier
{
	BEGINNER = 1,
	INTERMEDIATE,
	ADVANCED
};

// Function Declarations
void displayBanner();

void collectInput(string& favoriteTheme, int& setsOwned, double& hoursPerWeek, char& addAnother, string& setName,
	int& setNumber, double& setPrice, int& totalSetsEntered, double& totalCollectionValue,
	string setNames[], int setNumbers[], double setPrices[]);

void calculateStatistics(int totalSetsEntered, double totalCollectionValue, double hoursPerWeek, double& averageSetPrice, double& hoursPerYear);

void displayStatistics(int totalSetsEntered, double totalCollectionValue, double averageSetPrice);

BuilderTier determineBuilderTier(double hoursPerWeek, int setsOwned, double hoursPerYear);

void displayTierRecommendation(BuilderTier tier, double hoursPerWeek, int setsOwned);

int displayMenu(double hoursPerWeek, int setsOwned, double hoursPerYear,
	string& favoriteTheme, char& addAnother, string& setName, int& setNumber, double& setPrice,
	int& totalSetsEntered, double& totalCollectionValue, double& averageSetPrice,
	string setNames[], int setNumbers[], double setPrices[]);

void saveReport(string favoriteTheme, int setsOwned, double hoursPerWeek, double hoursPerYear, int totalSetsEntered, double totalCollectionValue,
	double averageSetPrice, const string setNames[], const int setNumbers[], const double setPrices[]);

void changeConsoleColor();

int main()
{
	// Declaring the Variables.
	string favoriteTheme;
	int setsOwned;
	double hoursPerWeek;
	double hoursPerYear;
	int menuChoice;
	char addAnother;
	string setName;
	int setNumber;
	double setPrice;
	int totalSetsEntered = 0;
	double totalCollectionValue = 0.0;
	double averageSetPrice = 0.0;
	string setNames[MAX_SETS];
	int setNumbers[MAX_SETS];
	double setPrices[MAX_SETS];

	// Call color function to change color
	changeConsoleColor();

	// Call upon Welcome Banner Function
	displayBanner();

	// Collect user input & information
	collectInput(favoriteTheme, setsOwned, hoursPerWeek, addAnother, setName, setNumber, setPrice, totalSetsEntered, totalCollectionValue,
		setNames, setNumbers, setPrices);
	// Calculate the average price of the LEGO sets entered.

	// Calculate the collection statistics
	calculateStatistics(totalSetsEntered, totalCollectionValue, hoursPerWeek, averageSetPrice, hoursPerYear);

	// Display the statistics
	displayStatistics(totalSetsEntered, totalCollectionValue, averageSetPrice);

	// Display the LEGO collection summary.
	cout << endl;
	cout << "========================================" << endl;
	cout << "          COLLECTION SUMMARY" << endl;
	cout << "========================================" << endl;
	cout << "Total Sets Entered: " << totalSetsEntered << endl;
	cout << "Total Collection Value: $" << totalCollectionValue << endl;
	cout << "========================================" << endl;

	// Save and Display the report
	saveReport(favoriteTheme, setsOwned, hoursPerWeek, hoursPerYear, totalSetsEntered, totalCollectionValue, averageSetPrice,
		setNames, setNumbers, setPrices);

	// Display Menu
	do
	{
		menuChoice = displayMenu(hoursPerWeek, setsOwned, hoursPerYear,
			favoriteTheme, addAnother, setName, setNumber, setPrice,
			totalSetsEntered, totalCollectionValue, averageSetPrice,
			setNames, setNumbers, setPrices);
	} while (menuChoice != 4);

	return 0;
}

// Function Definitions
void displayBanner()
{
	// Display the welcome banner for the LEGO Builder Profile
	cout << "Welcome to the LEGO Builder Profile!" << endl;
}

void collectInput(string& favoriteTheme, int& setsOwned, double& hoursPerWeek, char& addAnother, string& setName,
	int& setNumber, double& setPrice, int& totalSetsEntered, double& totalCollectionValue,
	string setNames[], int setNumbers[], double setPrices[])
{
	if (favoriteTheme.empty())
	{
		cout << "What is your favorite LEGO theme or building style? (e.g., Star Wars, City, Custom Creations, etc.)" << endl;
		getline(cin, favoriteTheme);

		// Input validation for favorite LEGO theme
		while (favoriteTheme.empty())
		{
			cout << "Please enter a LEGO theme or building style." << endl;
			getline(cin, favoriteTheme);
		}

		// Prompt the user for the number of LEGO sets they currently own.
		cout << "How many LEGO sets do you currently own?" << endl;
		cin >> setsOwned;

		// Input validation for the number of LEGO sets owned
		while (cin.fail() || setsOwned < 0)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(200, '\n');
			}

			cout << "Please enter a valid number of LEGO sets (0 or more)." << endl;
			cin >> setsOwned;
		}

		// Prompt the user for the average number of hours they spend building LEGO sets per week.
		cout << "On average, how many hours a week do you spend building LEGO sets?" << endl;
		cin >> hoursPerWeek;

		// Validate input for Hours Per Week
		while (cin.fail() || hoursPerWeek < 0)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(200, '\n');
			}

			cout << "Please enter a valid number of Hours (0 or more)." << endl;
			cin >> hoursPerWeek;
		}

		// Clear the input buffer before using getline for setName
		cin.ignore(200, '\n');
	}

	// Loop to allow the user to enter multiple LEGO sets
	do
	{
		if (totalSetsEntered >= MAX_SETS)
		{
			cout << "Maximum session set capacity (" << MAX_SETS << ") reached." << endl;
			break;
		}

		cout << "Enter the name of a LEGO set you own: ";
		getline(cin, setName);

		while (setName.empty())
		{
			cout << "Please enter a non-empty LEGO set name: ";
			getline(cin, setName);
		}

		cout << "Enter the set number for " << setName << ": ";
		cin >> setNumber;

		// Input validation for LEGO set number (must be greater than 0)
		while (cin.fail() || setNumber <= 0)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(200, '\n');
			}

			cout << "Please enter a valid LEGO set number (greater than 0): ";
			cin >> setNumber;
		}

		cout << "Enter the price of " << setName << ": $";
		cin >> setPrice;

		// Input validation for LEGO set price (must be 0 or more)
		while (cin.fail() || setPrice < 0)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(200, '\n');
			}

			cout << "Please enter a valid price (0 or more): $";
			cin >> setPrice;
		}

		setNames[totalSetsEntered] = setName;
		setNumbers[totalSetsEntered] = setNumber;
		setPrices[totalSetsEntered] = setPrice;

		totalSetsEntered++;
		totalCollectionValue = totalCollectionValue + setPrice;

		// Display the information for the LEGO set just entered.
		cout << endl;
		cout << "LEGO Set Added!" << endl;
		cout << "Set Name: " << setName << endl;
		cout << "Set Number: " << setNumber << endl;
		cout << fixed << setprecision(2);
		cout << "Set Price : $" << setPrice << endl;

		// Ask the user if they want to add another LEGO set
		cout << endl;
		cout << "Do you want to add another LEGO set? (Y/N): ";
		cin >> addAnother;
		cin.ignore(200, '\n'); // Clear the input buffer before the next iteration
	} while ((addAnother == 'Y' || addAnother == 'y') && totalSetsEntered < MAX_SETS);
}

void calculateStatistics(int totalSetsEntered, double totalCollectionValue,
	double hoursPerWeek, double& averageSetPrice, double& hoursPerYear)
{
	if (totalSetsEntered > 0)
	{
		averageSetPrice = totalCollectionValue / totalSetsEntered;
	}

	hoursPerYear = hoursPerWeek * 52;
}

void displayStatistics(int totalSetsEntered, double totalCollectionValue, double averageSetPrice)
{
	cout << endl;
	cout << "====== LEGO COLLECTION STATISTICS ======" << endl;

	for (int statistic = 1; statistic <= 3; statistic++)
	{
		// Display the statistics
		if (statistic == 1)
		{
			cout << "Total Sets Entered: " << totalSetsEntered << endl;
		}
		else if (statistic == 2)
		{
			cout << "Total Collection Value: $" << totalCollectionValue << endl;
		}
		else if (statistic == 3)
		{
			cout << "Average Price Per Set: $" << averageSetPrice << endl;
		}
	}
}

BuilderTier determineBuilderTier(double hoursPerWeek, int setsOwned, double hoursPerYear)
{
	if (hoursPerWeek >= 8.0 && setsOwned >= 25 && hoursPerYear >= 400.0)
	{
		return ADVANCED;
	}
	else if ((hoursPerWeek >= 5.0 && setsOwned >= 10) || hoursPerYear >= 260.0)
	{
		return INTERMEDIATE;
	}
	else
	{
		return BEGINNER;
	}
}

void displayTierRecommendation(BuilderTier tier, double hoursPerWeek, int setsOwned)
{
	switch (tier)
	{
	case BEGINNER:
		cout << "Recommended Level: Beginner" << endl;
		if (hoursPerWeek < 3.0 || setsOwned < 5)
		{
			cout << "Recommendation: Aim for 2-3 building hours per week and start with smaller sets." << endl;
		}
		else
		{
			cout << "Recommendation: Maintain a steady weekly building schedule." << endl;
		}
		break;

	case INTERMEDIATE:
		cout << "Recommended Level: Intermediate" << endl;
		cout << "Recommendation: Sort parts by element type and take on larger builds." << endl;
		break;

	case ADVANCED:
		cout << "Recommended Level: Advanced" << endl;
		cout << "Recommendation: Great stage for custom MOCs or modular display layouts." << endl;
		break;

	default:
		cout << "Recommended Level: Beginner" << endl;
		break;
	}
}

int displayMenu(double hoursPerWeek, int setsOwned, double hoursPerYear,
	string& favoriteTheme, char& addAnother, string& setName, int& setNumber, double& setPrice,
	int& totalSetsEntered, double& totalCollectionValue, double& averageSetPrice,
	string setNames[], int setNumbers[], double setPrices[])
{
	int menuChoice;
	BuilderTier recommendedTier = determineBuilderTier(hoursPerWeek, setsOwned, hoursPerYear);

	// Display the user options table
	cout << "==== LEGO Hobby Menu ====" << endl;
	cout << "1. Where to find Your LEGO Hobby Profile" << endl;
	cout << "2. What your building habits are!" << endl;
	cout << "3. Recommend Level & Add Another Set" << endl;
	cout << "4. Thank you for using the LEGO Builder Profile!" << endl;
	cout << "Please enter your choice (1-4): ";
	cin >> menuChoice;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(200, '\n');
		cout << "Please enter a valid menu number (1-4): ";
		cin >> menuChoice;
	}

	cin.ignore(200, '\n');

	// Switch statement to handle menu choices
	switch (menuChoice)
	{
	case 1:
		cout << "Your LEGO Profile has been saved to report.txt" << endl;
		break;

	case 2:
		if (hoursPerWeek >= 5 && setsOwned >= 10)
		{
			cout << "You are a dedicated LEGO builder!" << endl;
		}
		else
		{
			cout << "You are a casual LEGO builder!" << endl;
		}

		if (hoursPerYear >= 260 && hoursPerWeek >= 5)
		{
			cout << "You spent a lot of time throughout the year building LEGO sets!" << endl;
		}
		else
		{
			cout << "You have plenty of room and time to grow your building time!" << endl;
		}
		break;

	case 3:
		displayTierRecommendation(recommendedTier, hoursPerWeek, setsOwned);
		collectInput(favoriteTheme, setsOwned, hoursPerWeek, addAnother, setName, setNumber, setPrice,
			totalSetsEntered, totalCollectionValue, setNames, setNumbers, setPrices);
		calculateStatistics(totalSetsEntered, totalCollectionValue, hoursPerWeek, averageSetPrice, hoursPerYear);
		saveReport(favoriteTheme, setsOwned, hoursPerWeek, hoursPerYear, totalSetsEntered, totalCollectionValue, averageSetPrice,
			setNames, setNumbers, setPrices);
		break;

	case 4:
		cout << "Thank you for using the LEGO Builder Profile!" << endl;
		break;

	default:
		cout << "Invalid choice. Please select 1, 2, 3, or 4." << endl;
	}

	return menuChoice;

}

void saveReport(string favoriteTheme, int setsOwned, double hoursPerWeek, double hoursPerYear, int totalSetsEntered, double totalCollectionValue,
	double averageSetPrice, const string setNames[], const int setNumbers[], const double setPrices[])
{

	//Output to a text file
	ofstream reportFile("report.txt");

	// Display the title for the report
	cout << "==================================================" << endl;
	cout << "             MY LEGO HOBBY PROFILE" << endl;
	cout << "==================================================" << endl;

	reportFile << "==================================================" << endl;
	reportFile << "             MY LEGO HOBBY PROFILE" << endl;
	reportFile << "==================================================" << endl;

	// Display Column Headers
	cout << endl;
	cout << left << setw(40) << "Information" << right << setw(15) << "Your Answers" << endl;
	cout << "-------------------------------------------------------" << endl;

	reportFile << endl;
	reportFile << left << setw(40) << "Information" << right << setw(15) << "Your Answers" << endl;
	reportFile << "-------------------------------------------------------" << endl;

	// Format the output to display two decimal places
	cout << fixed << setprecision(2);
	reportFile << fixed << setprecision(2);

	// Display the LEGO Hobby Profile information
	cout << left << setw(40) << "Favorite LEGO Theme/Building Style" << right << setw(15) << favoriteTheme << endl;
	reportFile << left << setw(40) << "Favorite LEGO Theme/Building Style" << right << setw(15) << favoriteTheme << endl;

	cout << left << setw(40) << "Number of LEGO Sets Owned" << right << setw(15) << setsOwned << endl;
	reportFile << left << setw(40) << "Number of LEGO Sets Owned" << right << setw(15) << setsOwned << endl;

	cout << left << setw(40) << "Average Hours Spent Building per Week" << right << setw(15) << hoursPerWeek << endl;
	reportFile << left << setw(40) << "Average Hours Spent Building per Week" << right << setw(15) << hoursPerWeek << endl;

	cout << left << setw(40) << "Total Hours Spent Building per Year" << right << setw(15) << hoursPerYear << endl;
	reportFile << left << setw(40) << "Total Hours Spent Building per Year" << right << setw(15) << hoursPerYear << endl;

	cout << left << setw(40) << "Total LEGO Sets Entered" << right << setw(15) << totalSetsEntered << endl;
	reportFile << left << setw(40) << "Total LEGO Sets Entered" << right << setw(15) << totalSetsEntered << endl;

	cout << left << setw(40) << "Total Collection Value" << right << setw(15) << totalCollectionValue << endl;
	reportFile << left << setw(40) << "Total Collection Value" << right << setw(15) << totalCollectionValue << endl;

	cout << left << setw(40) << "Average Price Per Set" << right << setw(15) << averageSetPrice << endl;
	reportFile << left << setw(40) << "Average Price Per Set" << right << setw(15) << averageSetPrice << endl;

	cout << "-------------------------------------------------------" << endl;
	reportFile << "-------------------------------------------------------" << endl;

	if (totalSetsEntered > 0)
	{
		cout << endl;
		cout << left << setw(25) << "Set Name" << right << setw(12) << "Set #" << setw(18) << "Price" << endl;
		cout << "-------------------------------------------------------" << endl;

		reportFile << endl;
		reportFile << left << setw(25) << "Set Name" << right << setw(12) << "Set #" << setw(18) << "Price" << endl;
		reportFile << "-------------------------------------------------------" << endl;

		for (int i = 0; i < totalSetsEntered; i++)
		{
			cout << left << setw(25) << setNames[i] << right << setw(12) << setNumbers[i] << setw(18) << setPrices[i] << endl;
			reportFile << left << setw(25) << setNames[i] << right << setw(12) << setNumbers[i] << setw(18) << setPrices[i] << endl;
		}

		cout << "-------------------------------------------------------" << endl;
		reportFile << "-------------------------------------------------------" << endl;
	}

	// Close the report file
	reportFile.close();
}

void changeConsoleColor()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Change the console text color
	SetConsoleTextAttribute(hConsole, 11);
}