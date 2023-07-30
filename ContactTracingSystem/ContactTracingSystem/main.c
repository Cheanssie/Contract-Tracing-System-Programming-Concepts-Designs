#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <Windows.h>
#pragma warning (disable:4996)

void heading();

//Venue module functions
int venueMenu();
int searchVenueMenu();
void displayRecordVenue();
void addRecordVenue();
void modifyRecordVenue();
void searchRecordVenue();
void deleteRecordVenue();
void reportVenue();

//General
typedef struct {
	int day;
	int month;
	int year;
}Date;

typedef struct {
	int hour;
	int minute;
}Time;

int totalDayCount(Date* dateV);//Venue module date function(counting days)

//Venue Module
typedef struct {
	char venueID[7]; //Variable to store Venue ID
	char category[15]; //Variable to store Venue Category
	char description[16]; //Variable to store Venue Desrciption
	int maxVisitor; //Variable to store Venue Max Visitors allowed
	int currentVisitor; //Variable to store Venue Current Visitors
	Date dateSani;
	Time open;
	Time close;
}Venue;

//Sanitization Module
typedef struct {
	Time startTime;
	Time endTime;
}SaniTime;

typedef struct {
	char companyName[20];
	char companyContact[12];
	int numberOfWorkers;
	float price;
}Sanitizer;

typedef struct {
	Date date;
	SaniTime time;
	Venue venue;
	Sanitizer sanitizer;
}Sanitization;

//Visit & Exit Module
typedef struct {
	char visitorIC[15];
	double temperature;
	Date dateEnter;
	Time timeEnter;
	char reason[30];
	char telNo[13];
	Time timeExit;
	char venueID[8];
}VisitExit;

void addVisitExit();
int inputVisit(VisitExit* tmpVE);
void searchVisitExit();
int modifyVisitExit();
void displayVisitExit();
int visitExitMenu();
void deleteVisitExit();
void inputExit();
int searchMenuVE();
int modifyMenuVE();
void reportVisitExit();

//Sanitization Record Module
void addSanitization();
void searchSanitization();
void displaySanitization();
int searchMenuSani();
void modifySanitization();
int modifyMenuSani();
void sanitizationInput(Sanitization* tmpS);
int sanitizationMenu();
void deleteSanitization();
void reportSanitization();

//Visitor Information Module
typedef struct {
	char IC[15];
	char name[30];
	char contactNo[15];
	char position[30];
	char latestVenueVisited[8];
	char reason[30];
	float temperature;
	char gender[7];
	Date date;
	Time time;
}VisitorInfo;

VisitorInfo tepvisitor[100];//store visitor's details
VisitorInfo vInfo[100];
VisitorInfo visitor[100];//store visitor's details 
int visitorMenu();
void newVisitor();
void searchVisitor();
void visitorList();
void modifyVisitor();
void deleteVisitor();
void reportVisitor();
FILE* fptr;

//Staff Information Module
typedef struct {
	int staffID;
	char staffName[20];
	char staffIC[13];
	char staffGender;
	char staffPosition[20];
	char faculty[10];
	int password;
	int contactNo;
}Staff;

Staff s;
Staff tempStaff1[100];

void addStaff();
void staffLogin();
int checkID(int id);
int staffMenu2();
int staffMenu1();
void searchStaff();
void modifyStaff();
void deleteStaff();
void displayStaff();

void main() {
	char reply;
	int choice;
	char validator;
	int stay = 0;

	do {
		system("cls");
		heading();
		choice = 0;
		reply = 'N';
		//Prompt user to enter decisions based on menu given.
		printf("%13s===============================================\n", "");
		printf("%13s||%26s%19s\n", "", "Main Menu", "||");
		printf("%13s||%-43s||\n", "", "-------------------------------------------");
		printf("%13s||   %-40s||\n%13s||   %-40s||\n%13s||   %-40s||\n%13s||   %-40s||\n%13s||   %-40s||\n%13s||   %-40s||\n", "", "1.Visitor Information", "", "2.Staff Information", "", "3.Visit and Exit", "", "4.Venue Information", "", "5.Sanitization Information", "", "6.Quit");
		printf("%13s===============================================\n", "");
		do {
			printf("----Please enter your selection : ");	rewind(stdin);
			scanf("%d%c", &choice, &validator);
			switch (choice) {
			case 1:
				stay = visitorMenu(); break;
			case 2:
				stay = staffMenu1(); break;
			case 3:
				stay = visitExitMenu(); break;
			case 4:
				stay = venueMenu(); break;
			case 5:
				stay = sanitizationMenu(); break;
			case 6:
				break;
			default: {
				printf("Invalid Choice!\n"); rewind(stdin);
			}
			}
		} while (choice < 1 || choice > 6 || validator != '\n');
		if (choice == 6) {
			break;
		}
		if (stay == 1) {
			reply = 'Y';
			continue;
		}
		do {

			printf("\n\nReturn to main menu ? (Y = Yes | N = No)"); rewind(stdin);
			scanf("%c", &reply);
			reply = toupper(reply);
			if (reply != 'Y' && reply != 'N') {
				printf("\nInvalid choice. Please try again.\n");
			}
		} while (reply != 'Y' && reply != 'N');

	} while (reply == 'Y');

	printf("\nYou have quit the program.\n");
	system("pause");
}

int venueMenu()
{
	//declare variables for menu options to store 
	int choice;
	char decision;
	char validator;
	do {
		do {
			choice = 0;
			system("cls"); //To clear the screen and avoid screen cluster
			heading();
			//Prompt user to enter decisions based on menu given.
			printf("%13s===============================================\n", "");
			printf("%13s||%26s%19s\n", "", "Venue Menu", "||");
			printf("%13s||%-43s||\n", "", "-------------------------------------------");
			printf("%13s|| %31s%13s\n%13s|| %22s%22s\n%13s|| %25s%19s\n%13s|| %25s%19s\n%13s|| %25s%19s\n%13s|| %26s%18s\n%13s|| %26s%18s\n", "", "1. Display the Records", "||", "", "2. Add Record", "||", "", "3. Modify Record", "||", "", "4. Search Record", "||", "", "5. Delete Record", "||", "", "6. Overall Report", "||", "", "7. Return to menu", "||");
			printf("%13s===============================================\n", "");
			printf("----Please enter your selection : ");	rewind(stdin);
			scanf("%d%c", &choice, &validator); rewind(stdin);
			switch (choice) { //Switch option to select user's desired option
			case 1:
				displayRecordVenue(); break;
			case 2:
				addRecordVenue(); break;
			case 3:
				modifyRecordVenue(); break;
			case 4:
				searchRecordVenue(); break;
			case 5:
				deleteRecordVenue(); break;
			case 6:
				reportVenue(); break;
			case 7:
				break;
			default:
				printf("\nInvalid choice. Please try again. Select according to the table.\n");
				getchar();
			}
			if (validator != '\n') {
				printf("Only numeric input is acceptable!\n");
			}
		} while (choice < 1 || choice > 7 || validator != '\n');

		//Prompt user to return to main menu to use different function(or same).
		if (choice == 7) {
			return 1;
		}
		do {
			printf("\n\nReturn to venue menu ? (Y = Yes | N = No)"); rewind(stdin);
			scanf("%c", &decision);
			decision = toupper(decision);
			if (decision != 'Y' && decision != 'N') {
				printf("Invalid choice. Please try again.\n");
			}
		} while (decision != 'Y' && decision != 'N');
	} while (decision == 'Y');
}

int searchVenueMenu() {
	int choice;
	char validator;
	do {
		printf("===============================================\n");
		printf("||%-8s%-35s||\n", " ", "SEARCH VENUE RECORDS");
		printf("++%-43s++\n", "-------------------------------------------");
		printf("|| %-42s||\n|| %-42s||\n|| %-42s||\n", "1. VENUE ID", "2. CATEGORY", "3. DESCRIPTION");
		printf("===============================================\n");
		rewind(stdin);
		scanf("%d%c", &choice, &validator);
		if (choice != 1 && choice != 2 && choice != 3 || validator == '\n') {
			printf("Choose your choice based on the table according to the number.\n");
		}
	} while ((choice != 1 && choice != 2 && choice != 3));

	return choice;
}

void displayRecordVenue() {
	Venue venue[100];//Structure variable to store records of venue
	Sanitization sanitization[100];
	Date tempDate[100];
	int totalRecord = 0;	//Variable that store the amount of records displayed
	int sanitizationRecords = 0;
	int sanitizeRecordCheck = 0;
	int sanitizeDateArray = 0;

	//FILE* fptr;
	FILE* fptr;
	fptr = fopen("venueModule.txt", "r");
	if (!fptr) {
		printf("File not found.");
		exit(1);
	}
	system("cls");
	printf("========================\n");
	printf("||   Display Records  ||\n");
	printf("========================\n\n");
	//Table heading for records
	printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
	printf("%-14s%-18s%-21s%-16s%-20s%-18s%-16s%-16s\n", "| Venue ID |", "Venue Category |", "Venue Description |", "Max Visitors |", "Current Visitors |", "Last Sanitized |", "Opening time |", "Closing Time |");
	printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");

	while (fscanf(fptr, "%[^\|]|%[^\|]|%[^\|]|%d|%d|%d-%d-%d|%d:%d|%d:%d\n", &venue[totalRecord].venueID, &venue[totalRecord].category, &venue[totalRecord].description, &venue[totalRecord].maxVisitor, &venue[totalRecord].currentVisitor, &venue[totalRecord].dateSani.day, &venue[totalRecord].dateSani.month, &venue[totalRecord].dateSani.year, &venue[totalRecord].open.hour, &venue[totalRecord].open.minute, &venue[totalRecord].close.hour, &venue[totalRecord].close.minute) != EOF)
	{
		printf("| %-9s%-3s%-15s%-3s%-18s%-3s%-13d%-3s%-17d%-4s%-2.02d-%-2.02d-%-8d%-6s%02d:%-7.02d%-6s%02d:%-7.02d%-3s\n", venue[totalRecord].venueID, "|", venue[totalRecord].category, "|", venue[totalRecord].description, "|", venue[totalRecord].maxVisitor, "|", venue[totalRecord].currentVisitor, "|", venue[totalRecord].dateSani.day, venue[totalRecord].dateSani.month, venue[totalRecord].dateSani.year, "|", venue[totalRecord].open.hour, venue[totalRecord].open.minute, "|", venue[totalRecord].close.hour, venue[totalRecord].close.minute, "|");
		printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
		totalRecord++;
	}

	printf("\n\nTotal records listed : %d\n\n", totalRecord);

	fclose(fptr);
}

void addRecordVenue() {

	Venue venue;			//Variable to store temporary records
	Venue validate[100];	//Variable to validate if duplication of data is found
	char decision;			//Variable to store decisions made by user
	char dateValidator[2];
	char validator;			//Variable to store foreign values (wrong value) to validate  (1)
	char validator2;		//Variable to store foreign values (wrong value) to validate (2)
	int addedRecord = 0;	//Variable to store amount of newly added records
	int word = 0;			//Variable to hold amount of words for further validation
	int IDfound = 0;		//Variable to store amount of records in validate structure      
	int IDsame = 0;			//Variable to hold amount of duplication of ID input by user for validation
	int venueAlpha = 0;		//Variable to hold amount of alphabet in a venue ID for validation
	int venueDigit = 0;		//Variable to hold amount of numbers in a venue ID for validation
	int maxDay;

	FILE* fptr;
	FILE* fptr2;
	fptr2 = fopen("venueModule.txt", "a");
	fptr = fopen("venueModule.txt", "r");
	if (!fptr && !fptr2) {//To validate if file exists
		printf("File not found.");
		exit(1);
	}
	while (fscanf(fptr, "%[^\|]|%[^\|]|%[^\|]|%d|%d|%d-%d-%d|%d:%d|%d:%d\n", &validate[IDfound].venueID, &validate[IDfound].category, &validate[IDfound].description, &validate[IDfound].maxVisitor, &validate[IDfound].currentVisitor, &validate[IDfound].dateSani.day, &validate[IDfound].dateSani.month, &validate[IDfound].dateSani.year, &validate[IDfound].open.hour, &validate[IDfound].open.minute, &validate[IDfound].close.hour, &validate[IDfound].close.minute) != EOF)
	{
		IDfound++;
	}					//Store records from file for validation
	fclose(fptr);

	do {
		system("cls");
		printf("====================\n");
		printf("||   Add Records  ||\n");
		printf("====================\n\n");
		do {
			/*Reset validator variables*/
			IDsame = 0;
			venueAlpha = 0;
			venueDigit = 0;
			venue.maxVisitor = 0;
			venue.currentVisitor = -1;

			printf("Enter venueID: (eg. ABC123):"); rewind(stdin);
			scanf("%s", &venue.venueID);
			for (int b = 0; b < 3; b++) {
				venue.venueID[b] = toupper(venue.venueID[b]);
			}
			if (strlen(venue.venueID) > 6) {
				printf("\nInvalid input, no more than 6 letters. Try again.\n");
			}
			if (strlen(venue.venueID) < 6) {
				printf("\nInvalid input, no less than 6 letters. Try again\n");
			}
			if (strlen(venue.venueID) == 6) {
				for (int a = 0; a < 3; a++) {
					if (isalpha(venue.venueID[a]) == 0) {
						printf("\nFirst 3 letters of a venue ID must be alphabet.\n");
						venueAlpha++;
						break;
					}
				}
				for (int e = 4; e < 6; e++) {
					if (isdigit(venue.venueID[e]) == 0) {
						printf("Last 3 letters of venue ID must be a digit\n");
						venueDigit++;
						break;
					}
				}
				for (int i = 0; i < IDfound; i++) {
					if (strcmp(venue.venueID, validate[i].venueID) == 0) {
						printf("\nVenue ID is already in the system. Use a unique Venue ID.\n");
						IDsame++;
					}
				}
			}
		} while (strlen(venue.venueID) != 6 || IDsame != 0 || venueAlpha != 0 || venueDigit != 0);

		do {
			printf("Enter category of venue:"); rewind(stdin);
			scanf("%s", &venue.category);

			if (strlen(venue.category) > 15) {
				printf("\nInvalid input, no more than 15 letters. Try again.\n");
			}
		} while (strlen(venue.category) > 15);

		do {
			printf("Enter description of venue:"); rewind(stdin);
			scanf("%[^\n]", &venue.description);
			for (int i = 0; venue.description[i] != '\0'; i++) {
				if (venue.description[i] == ' ') {
					word++;
				}
			}
			if (word > 16) {
				printf("\nInvalid input, only 15 words allowed. Try again.\n");
			}
		} while (word > 16);

		do {
			printf("Enter max visitors of venue:"); rewind(stdin);
			scanf("%d%c", &venue.maxVisitor, &validator);
			if (validator != '\n' || venue.maxVisitor == 0 || venue.maxVisitor < 0) {
				printf("\nInvalid input, only numbers allowed and visitors cannot be none(0) or negative. Try again.\n");
			}

		} while (validator != '\n' || venue.maxVisitor == 0 || venue.maxVisitor < 0);

		do {
			printf("Enter current visitors of venue:"); rewind(stdin);
			scanf("%d%c", &venue.currentVisitor, &validator2);
			if (validator2 != '\n' || venue.currentVisitor > venue.maxVisitor || venue.currentVisitor < 0) {
				printf("\nInvalid input, only numbers allowed and visitors cannot be more than %d (max visitors allowed) or negative. Try again\n", venue.maxVisitor);
			}
		} while (validator2 != '\n' || (venue.currentVisitor > venue.maxVisitor) || venue.currentVisitor < 0);

		do {
			printf("Date last sanitized(DD-MM-YYYY):"); rewind(stdin);
			scanf("%d%c%d%c%d", &venue.dateSani.day, &dateValidator[0], &venue.dateSani.month, &dateValidator[1], &venue.dateSani.year);
			switch (venue.dateSani.month) {

			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12: {
				maxDay = 31;
			}break;
			case 2: {
				if (venue.dateSani.year % 4 == 0) {
					maxDay = 29;
				}
				else
				{
					maxDay = 28;
				}
			}break;

			default:
				maxDay = 30;
			}

			if (dateValidator[0] != '-' || dateValidator[1] != '-') {
				printf("\nOnly '-' Available for Date Format\n");
			}
			else if (venue.dateSani.day < 1 || venue.dateSani.day > maxDay || venue.dateSani.month < 0 || venue.dateSani.month > 12) {
				printf("\nInvalid Date's/Month's Range\n");
			}
			if (venue.dateSani.year < 2020 || venue.dateSani.year > 2021) {
				printf("\nInvalid year. Please try again.\n");
			}
		} while (venue.dateSani.day < 1 || venue.dateSani.day > maxDay || venue.dateSani.month < 0 || venue.dateSani.month > 12 || dateValidator[0] != '-' || dateValidator[1] != '-' || (venue.dateSani.year < 2020 || venue.dateSani.year > 2021));

		do {
			printf("Venue open time(HH:MM):"); rewind(stdin);
			scanf("%d%c%d", &venue.open.hour, &validator, &venue.open.minute);
			if (venue.open.hour < 0 || venue.open.hour > 23 || venue.open.minute < 0 || venue.open.minute > 59) {
				printf("\nInvalid Time Range!\n");
			}
			if (validator != ':') {
				printf("\nOnly ':' Available in Time Format\n");
			}
		} while (venue.open.hour < 0 || venue.open.hour > 23 || venue.open.minute < 0 || venue.open.minute > 59 || validator != ':');

		do {
			printf("Venue closing time(HH:MM):"); rewind(stdin);
			scanf("%d%c%d", &venue.close.hour, &validator, &venue.close.minute);
			if (venue.close.hour < 0 || venue.close.hour > 23 || venue.close.minute < 0 || venue.close.minute > 59 || (venue.open.hour == venue.close.hour && venue.open.minute > venue.close.minute)) {
				printf("\nInvalid Time Range!\n");
			}
			if (validator != ':') {
				printf("\nOnly ':' Available for Time Format\n");
			}
			if (venue.open.hour > venue.close.hour) {
				printf("\nInvalid time close. Venue cannot be opened for more than 24 hours or overnight. Try again\n");
			}
			if (venue.open.hour == venue.close.hour && venue.open.minute == venue.close.minute) {
				printf("\nInvalid time close. Venue cannot close when it just opened. Try again\n");
			}
		} while (venue.close.hour < 0 || venue.close.hour > 23 || venue.close.minute < 0 || venue.close.minute > 59 || validator != ':' || (venue.open.hour > venue.close.hour) || (venue.open.hour == venue.close.hour && venue.open.minute == venue.close.minute) || (venue.open.hour == venue.close.hour && venue.open.minute > venue.close.minute));


		//Table heading for adding records
		printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
		printf("%-14s%-18s%-21s%-16s%-20s%-18s%-16s%-16s\n", "| Venue ID |", "Venue Category |", "Venue Description |", "Max Visitors |", "Current Visitors |", "Last Sanitized |", "Opening time |", "Closing Time |");
		printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
		printf("| %-9s%-3s%-15s%-3s%-18s%-3s%-13d%-3s%-17d%-4s%-2.02d-%-2.02d-%-8d%-6s%02d:%-7.02d%-6s%02d:%-7.02d%-3s\n", venue.venueID, "|", venue.category, "|", venue.description, "|", venue.maxVisitor, "|", venue.currentVisitor, "|", venue.dateSani.day, venue.dateSani.month, venue.dateSani.year, "|", venue.open.hour, venue.open.minute, "|", venue.close.hour, venue.close.minute, "|");
		printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");

		do {//Prompt user for confirmation of action
			printf("\nConfirm to add record? (Y = Yes | N = No)\n"); rewind(stdin);
			scanf("%c", &decision);
			decision = toupper(decision);
			if (decision == 'Y')
			{//Write newly added records into file
				fprintf(fptr2, "%s|%s|%s|%d|%d|%02d-%02d-%-4d|%02d:%02d|%02d:%02d\n", venue.venueID, venue.category, venue.description, venue.maxVisitor, venue.currentVisitor, venue.dateSani.day, venue.dateSani.month, venue.dateSani.year, venue.open.hour, venue.open.minute, venue.close.hour, venue.close.minute);
				fclose(fptr2);
				addedRecord++;
			}
			else if (decision == 'N')
			{
				printf("\nRecord is not added.\n");
			}
			else
			{
				printf("\nInvalid choice. Please try again.\n");
			}
		} while (decision != 'Y' && decision != 'N');

		do {//Prompt user for continuation of action
			printf("\nContinue adding record ? (Y = yes | N = No)\n"); rewind(stdin);
			scanf("%c", &decision);
			decision = toupper(decision);
			if (decision != 'Y' && decision != 'N') {
				printf("\nInvalid choice. Please try again.\n");
			}
		} while (decision != 'Y' && decision != 'N');
	} while (decision == 'Y');
	printf("Total records added : %d", addedRecord);//Display amount of records added
}

void modifyRecordVenue() {
	Venue venue[100];
	Venue temp;
	Sanitization sanitization[100];
	char dateValidator[2];
	char decision, validator, validator2, searchCategory[20], searchID[7];
	int totalRecord = 0, recordsFound = 0, updatedRecord = 0, recordNo = 0, word = 0, IDsame = 0, venueDigit = 0, venueAlpha = 0, arraySearch, modChoice, searchedRecord, quitChoice;
	int maxDay;
	int saniRecord = 0;
	int saniRecordFound = 0;
	int searchedRecordSani;
	int arraySearchSani;

	FILE* fptr;
	FILE* fptr2;

	fptr = fopen("venueModule.txt", "r");
	fptr2 = fopen("SanitizationModule.txt", "r");
	if (!fptr || !fptr2) {
		printf("File not found.");
		exit(-1);
	}

	while (fscanf(fptr, "%[^\|]|%[^\|]|%[^\|]|%d|%d|%d-%d-%d|%d:%d|%d:%d\n", &venue[totalRecord].venueID, &venue[totalRecord].category, &venue[totalRecord].description, &venue[totalRecord].maxVisitor, &venue[totalRecord].currentVisitor, &venue[totalRecord].dateSani.day, &venue[totalRecord].dateSani.month, &venue[totalRecord].dateSani.year, &venue[totalRecord].open.hour, &venue[totalRecord].open.minute, &venue[totalRecord].close.hour, &venue[totalRecord].close.minute) != EOF)
	{
		totalRecord++;
	}
	fclose(fptr);

	while (fscanf(fptr2, "%d-%d-%d|%d:%d|%d:%d|%[^\|]|%[^\|]|%d|%[^\|]|%f\n", &sanitization[saniRecord].date.day, &sanitization[saniRecord].date.month, &sanitization[saniRecord].date.year, &sanitization[saniRecord].time.startTime.hour, &sanitization[saniRecord].time.startTime.minute, &sanitization[saniRecord].time.endTime.hour, &sanitization[saniRecord].time.endTime.minute, &sanitization[saniRecord].venue.venueID, &sanitization[saniRecord].sanitizer.companyName, &sanitization[saniRecord].sanitizer.numberOfWorkers, &sanitization[saniRecord].sanitizer.companyContact, &sanitization[saniRecord].sanitizer.price) != EOF)
	{
		saniRecord++;
	}
	fclose(fptr2);

	do {
		recordsFound = 0;
		saniRecordFound = 0;
		system("cls");
		printf("=======================\n");
		printf("||   Modify Records  ||\n");
		printf("=======================\n\n");
		do {
			printf("Enter venue's ID that you wish to modify. (eg. ABC123)"); rewind(stdin);
			scanf("%s", &searchID);
			for (int b = 0; b < 3; b++) {
				searchID[b] = toupper(searchID[b]);
			}

			printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
			printf("%-14s%-18s%-21s%-16s%-20s%-18s%-16s%-16s\n", "| Venue ID |", "Venue Category |", "Venue Description |", "Max Visitors |", "Current Visitors |", "Last Sanitized |", "Opening time |", "Closing Time |");
			printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");

			for (arraySearch = 0; arraySearch < totalRecord; arraySearch++)
			{
				if (strcmp(venue[arraySearch].venueID, searchID) == 0)
				{
					printf("| %-9s%-3s%-15s%-3s%-18s%-3s%-13d%-3s%-17d%-4s%-2.02d-%-2.02d-%-8d%-6s%02d:%-7.02d%-6s%02d:%-7.02d%-3s\n", venue[arraySearch].venueID, "|", venue[arraySearch].category, "|", venue[arraySearch].description, "|", venue[arraySearch].maxVisitor, "|", venue[arraySearch].currentVisitor, "|", venue[arraySearch].dateSani.day, venue[arraySearch].dateSani.month, venue[arraySearch].dateSani.year, "|", venue[arraySearch].open.hour, venue[arraySearch].open.minute, "|", venue[arraySearch].close.hour, venue[arraySearch].close.minute, "|");
					searchedRecord = arraySearch;
					recordsFound++;
				}
			}
			for (arraySearchSani = 0; arraySearchSani < saniRecord; arraySearchSani++) {
				if (strcmp(sanitization[arraySearchSani].venue.venueID, searchID) == 0) {
					searchedRecordSani = arraySearchSani;
					saniRecordFound++;
				}
			}
			if (recordsFound == 0)
			{
				printf("|%-10s|%-17s|%-20s|%-15s|%-19s|%-17s|%-15s|%-15s|\n", "", "", "", "", "", "", "", "");
				printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
				printf("\nVenue ID not found in records. Try again.\n\n");
			}

		} while (recordsFound == 0);

		printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");

		do {
			modChoice = modifyVenueMenu();

			if (modChoice == 1) {
				do {
					IDsame = 0;
					venueAlpha = 0;
					venueDigit = 0;
					printf("Enter venueID: (eg. ABC123):"); rewind(stdin);
					scanf("%s", &temp.venueID);
					for (int b = 0; b < 3; b++) {
						temp.venueID[b] = toupper(temp.venueID[b]);
					}
					if (strlen(temp.venueID) > 6) {
						printf("\nInvalid input, no more than 6 letters\n");
					}
					if (strlen(temp.venueID) < 6) {
						printf("\nInvalid input, no less than 6 letters\n");
					}
					if (strlen(temp.venueID) == 6) {
						for (int a = 0; a < 3; a++) {
							if (isalpha(temp.venueID[a]) == 0) {
								printf("\nFirst 3 letters of a venue ID must be alphabet.\n");
								venueAlpha++;
								break;
							}
						}
						for (int e = 4; e < 6; e++) {
							if (isdigit(temp.venueID[e]) == 0) {
								printf("Last 3 letters of venue ID must be a digit\n");
								venueDigit++;
								break;
							}
						}
						for (int i = 0; i < totalRecord; i++) {
							if (strcmp(temp.venueID, venue[i].venueID) == 0) {
								printf("\nVenue ID is already in the system. Use a unique Venue ID.\n");
								IDsame++;
							}
						}
					}
				} while (strlen(temp.venueID) != 6 || IDsame != 0 || venueAlpha != 0 || venueDigit != 0);
			}

			if (modChoice == 2) {
				do {
					printf("Enter category of venue:"); rewind(stdin);
					scanf("%s", &temp.category);

					if (strlen(temp.category) > 15) {
						printf("\nInvalid input, no more than 15 letters. Try again.\n");
					}
				} while (strlen(temp.category) > 15);
			}

			if (modChoice == 3) {
				do {
					printf("Enter description of venue:"); rewind(stdin);
					scanf("%[^\n]", &temp.description);
					for (int i = 0; temp.description[i] != '\0'; i++) {
						if (temp.description[i] == ' ') {
							word++;
						}
					}
					if (word > 16) {
						printf("\nInvalid input, only 15 words allowed. Try again.\n");
					}
				} while (word > 16);
			}

			if (modChoice == 4) {
				do {
					printf("Enter max visitors of venue:"); rewind(stdin);
					scanf("%d%c", &temp.maxVisitor, &validator);
					if (validator != '\n' || temp.maxVisitor == 0) {
						printf("\nInvalid input, only numbers allowed and visitors cannot be none(0). Try again.\n");
					}
				} while (validator != '\n' || (temp.maxVisitor == 0));
			}

			if (modChoice == 5) {
				do {
					printf("Enter current visitors of venue:"); rewind(stdin);
					scanf("%d%c", &temp.currentVisitor, &validator);
					if (validator != '\n' || temp.currentVisitor > temp.maxVisitor) {
						printf("\nInvalid input, only numbers allowed and visitors cannot be more than %d (max visitors allowed). Try again\n", temp.maxVisitor);
					}
				} while (validator != '\n' || (temp.currentVisitor > temp.maxVisitor));
			}

			if (modChoice == 6) {
				do {
					printf("Date last sanitized(DD-MM-YYYY):"); rewind(stdin);
					scanf("%d%c%d%c%d", &temp.dateSani.day, &dateValidator[0], &temp.dateSani.month, &dateValidator[1], &temp.dateSani.year);

					switch (temp.dateSani.month) {

					case 1:
					case 3:
					case 5:
					case 7:
					case 8:
					case 10:
					case 12: {
						maxDay = 31;
					}break;
					case 2: {
						if (temp.dateSani.year % 4 == 0) {
							maxDay = 29;
						}
						else
						{
							maxDay = 28;
						}
					}break;

					default:
						maxDay = 30;
					}

					if (dateValidator[0] != '-' || dateValidator[1] != '-') {
						printf("\nOnly '-' Available for Date Format\n");
					}
					else if (temp.dateSani.day < 1 || temp.dateSani.day > maxDay || temp.dateSani.month < 0 || temp.dateSani.month > 12) {
						printf("\nInvalid Date's/Month's Range\n");
					}
					if (temp.dateSani.year < 2020 || temp.dateSani.year > 2021) {
						printf("\nInvalid year. Please try again.\n");
					}
				} while (temp.dateSani.day < 1 || temp.dateSani.day > maxDay || temp.dateSani.month < 0 || temp.dateSani.month > 12 || dateValidator[0] != '-' || dateValidator[1] != '-' || (temp.dateSani.year < 2020 || temp.dateSani.year > 2021));
			}

			if (modChoice == 7) {
				do {
					printf("Venue open time(HH:MM):"); rewind(stdin);
					scanf("%d%c%d", &temp.open.hour, &validator, &temp.open.minute);
					if (temp.open.hour < 0 || temp.open.hour > 23 || temp.open.minute < 0 || temp.open.minute > 59) {
						printf("\nInvalid Time Range!\n");
					}
					if (validator != ':') {
						printf("\nOnly ':' Available in Time Format\n");
					}
				} while (temp.open.hour < 0 || temp.open.hour > 23 || temp.open.minute < 0 || temp.open.minute > 59 || validator != ':');

				do {
					printf("Venue closing time(HH:MM):"); rewind(stdin);
					scanf("%d%c%d", &temp.close.hour, &validator, &temp.close.minute);
					if (temp.close.hour < 0 || temp.close.hour > 23 || temp.close.minute < 0 || temp.close.minute > 59 || (temp.open.hour == temp.close.hour && temp.open.minute > temp.close.minute)) {
						printf("\nInvalid Time Range!\n");
					}
					if (validator != ':') {
						printf("\nOnly ':' Available for Time Format\n");
					}
					if (temp.open.hour > temp.close.hour) {
						printf("\nInvalid time close. Venue cannot be opened for more than 24 hours or overnight. Try again\n");
					}
					if (temp.open.hour == temp.close.hour && temp.open.minute == temp.close.minute) {
						printf("\nInvalid time close. Venue cannot close when it just opened. Try again\n");
					}
				} while (temp.close.hour < 0 || temp.close.hour > 23 || temp.close.minute < 0 || temp.close.minute > 59 || validator != ':' || (temp.open.hour > temp.close.hour) || (temp.open.hour == temp.close.hour && temp.open.minute == temp.close.minute) || (temp.open.hour == temp.close.hour && temp.open.minute > temp.close.minute));
			}

			if (modChoice == 8) {
				do {
					/*Reset validator variables*/
					IDsame = 0;
					venueAlpha = 0;
					venueDigit = 0;
					temp.maxVisitor = 0;
					temp.currentVisitor = -1;

					printf("Enter venueID: (eg. ABC123):"); rewind(stdin);
					scanf("%s", &temp.venueID);
					for (int b = 0; b < 3; b++) {
						temp.venueID[b] = toupper(temp.venueID[b]);
					}
					if (strlen(temp.venueID) > 6) {
						printf("\nInvalid input, no more than 6 letters. Try again.\n");
					}
					if (strlen(temp.venueID) < 6) {
						printf("\nInvalid input, no less than 6 letters. Try again\n");
					}
					if (strlen(temp.venueID) == 6) {
						for (int a = 0; a < 3; a++) {
							if (isalpha(temp.venueID[a]) == 0) {
								printf("\nFirst 3 letters of a venue ID must be alphabet.\n");
								venueAlpha++;
								break;
							}
						}
						for (int e = 4; e < 6; e++) {
							if (isdigit(temp.venueID[e]) == 0) {
								printf("Last 3 letters of venue ID must be a digit\n");
								venueDigit++;
								break;
							}
						}
						for (int i = 0; i < totalRecord; i++) {
							if (strcmp(temp.venueID, venue[i].venueID) == 0) {
								printf("\nVenue ID is already in the system. Use a unique Venue ID.\n");
								IDsame++;
							}
						}
					}
				} while (strlen(temp.venueID) != 6 || IDsame != 0 || venueAlpha != 0 || venueDigit != 0);

				do {
					printf("Enter category of venue:"); rewind(stdin);
					scanf("%s", &temp.category);

					if (strlen(temp.category) > 15) {
						printf("\nInvalid input, no more than 15 letters. Try again.\n");
					}
				} while (strlen(temp.category) > 15);

				do {
					printf("Enter description of venue:"); rewind(stdin);
					scanf("%[^\n]", &temp.description);
					for (int i = 0; temp.description[i] != '\0'; i++) {
						if (temp.description[i] == ' ') {
							word++;
						}
					}
					if (word > 16) {
						printf("\nInvalid input, only 15 words allowed. Try again.\n");
					}
				} while (word > 16);

				do {
					printf("Enter max visitors of venue:"); rewind(stdin);
					scanf("%d%c", &temp.maxVisitor, &validator);
					if (validator != '\n' || temp.maxVisitor == 0 || temp.maxVisitor < 0) {
						printf("\nInvalid input, only numbers allowed and visitors cannot be none(0) or negative. Try again.\n");
					}

				} while (validator != '\n' || temp.maxVisitor == 0 || temp.maxVisitor < 0);

				do {
					printf("Enter current visitors of venue:"); rewind(stdin);
					scanf("%d%c", &temp.currentVisitor, &validator2);
					if (validator2 != '\n' || temp.currentVisitor > temp.maxVisitor || temp.currentVisitor < 0) {
						printf("\nInvalid input, only numbers allowed and visitors cannot be more than %d (max visitors allowed) or negative. Try again\n", temp.maxVisitor);
					}
				} while (validator2 != '\n' || (temp.currentVisitor > temp.maxVisitor) || temp.currentVisitor < 0);

				do {
					printf("Date last sanitized(DD-MM-YYYY):"); rewind(stdin);
					scanf("%d%c%d%c%d", &temp.dateSani.day, &dateValidator[0], &temp.dateSani.month, &dateValidator[1], &temp.dateSani.year);

					switch (temp.dateSani.month) {

					case 1:
					case 3:
					case 5:
					case 7:
					case 8:
					case 10:
					case 12: {
						maxDay = 31;
					}break;
					case 2: {
						if (temp.dateSani.year % 4 == 0) {
							maxDay = 29;
						}
						else
						{
							maxDay = 28;
						}
					}break;

					default:
						maxDay = 30;
					}

					if (dateValidator[0] != '-' || dateValidator[1] != '-') {
						printf("\nOnly '-' Available for Date Format\n");
					}
					else if (temp.dateSani.day < 1 || temp.dateSani.day > maxDay || temp.dateSani.month < 0 || temp.dateSani.month > 12) {
						printf("\nInvalid Date's/Month's Range\n");
					}
					if (temp.dateSani.year < 2020 || temp.dateSani.year > 2021) {
						printf("\nInvalid year. Please try again.\n");
					}
				} while (temp.dateSani.day < 1 || temp.dateSani.day > maxDay || temp.dateSani.month < 0 || temp.dateSani.month > 12 || dateValidator[0] != '-' || dateValidator[1] != '-' || (temp.dateSani.year < 2020 || temp.dateSani.year > 2021));

				do {
					printf("Venue open time(HH:MM)"); rewind(stdin);
					scanf("%d%c%d", &temp.open.hour, &validator, &temp.open.minute);
					if (temp.open.hour < 0 || temp.open.hour > 23 || temp.open.minute < 0 || temp.open.minute > 59) {
						printf("\nInvalid Time Range!\n");
					}
					if (validator != ':') {
						printf("\nOnly ':' Available in Time Format\n");
					}
				} while (temp.open.hour < 0 || temp.open.hour > 23 || temp.open.minute < 0 || temp.open.minute > 59 || validator != ':');

				do {
					printf("Venue closing time(HH:MM):"); rewind(stdin);
					scanf("%d%c%d", &temp.close.hour, &validator, &temp.close.minute);
					if (temp.close.hour < 0 || temp.close.hour > 23 || temp.close.minute < 0 || temp.close.minute > 59 || (temp.open.hour == temp.close.hour && temp.open.minute > temp.close.minute)) {
						printf("\nInvalid Time Range!\n");
					}
					if (validator != ':') {
						printf("\nOnly ':' Available for Time Format\n");
					}
					if (temp.open.hour > temp.close.hour) {
						printf("\nInvalid time close. Venue cannot be opened for more than 24 hours or overnight. Try again\n");
					}
					if (temp.open.hour == temp.close.hour && temp.open.minute == temp.close.minute) {
						printf("\nInvalid time close. Venue cannot close when it just opened. Try again\n");
					}
				} while (temp.close.hour < 0 || temp.close.hour > 23 || temp.close.minute < 0 || temp.close.minute > 59 || validator != ':' || (temp.open.hour > temp.close.hour) || (temp.open.hour == temp.close.hour && temp.open.minute == temp.close.minute) || (temp.open.hour == temp.close.hour && temp.open.minute > temp.close.minute));
			}

			if (modChoice != 1 && modChoice != 2 && modChoice != 3 && modChoice != 4 && modChoice != 5 && modChoice != 6 && modChoice != 7 && modChoice != 8) {
				printf("\nInvalid choice, choose again according to the table.\n");
			}
		} while (modChoice != 1 && modChoice != 2 && modChoice != 3 && modChoice != 4 && modChoice != 5 && modChoice != 6 && modChoice != 7 && modChoice != 8);

		do {
			printf("\nDo you wish to modify the record ?(Y = Yes | N = No) "); rewind(stdin);
			scanf("%c", &decision);
			decision = toupper(decision);
			if (decision == 'Y') {
				if (modChoice == 1) {
					strcpy(venue[searchedRecord].venueID, temp.venueID);
					updatedRecord++;
				}
				if (modChoice == 2) {
					strcpy(venue[searchedRecord].category, temp.category);
					updatedRecord++;
				}
				if (modChoice == 3) {
					strcpy(venue[searchedRecord].description, temp.description);
					updatedRecord++;
				}
				if (modChoice == 4) {
					venue[searchedRecord].maxVisitor = temp.maxVisitor;
					updatedRecord++;
				}
				if (modChoice == 5) {
					venue[searchedRecord].currentVisitor = temp.currentVisitor;
					updatedRecord++;
				}
				if (modChoice == 6) {
					venue[searchedRecord].dateSani.day = temp.dateSani.day;
					venue[searchedRecord].dateSani.month = temp.dateSani.month;
					venue[searchedRecord].dateSani.year = temp.dateSani.year;
					if (saniRecordFound != 0) {
						sanitization[searchedRecordSani].date.day = temp.dateSani.day;
						sanitization[searchedRecordSani].date.month = temp.dateSani.month;
						sanitization[searchedRecordSani].date.year = temp.dateSani.year;
					}
					updatedRecord++;
				}
				if (modChoice == 7) {
					venue[searchedRecord].open.hour = temp.open.hour;
					venue[searchedRecord].open.minute = temp.open.minute;
					venue[searchedRecord].close.hour = temp.close.hour;
					venue[searchedRecord].close.minute = temp.close.minute;
					updatedRecord++;
				}
				if (modChoice == 8) {
					strcpy(venue[searchedRecord].venueID, temp.venueID);
					strcpy(venue[searchedRecord].category, temp.category);
					strcpy(venue[searchedRecord].description, temp.description);
					venue[searchedRecord].maxVisitor = temp.maxVisitor;
					venue[searchedRecord].currentVisitor = temp.currentVisitor;
					venue[searchedRecord].dateSani.day = temp.dateSani.day;
					venue[searchedRecord].dateSani.month = temp.dateSani.month;
					venue[searchedRecord].dateSani.year = temp.dateSani.year;
					venue[searchedRecord].open.hour = temp.open.hour;
					venue[searchedRecord].open.minute = temp.open.minute;
					venue[searchedRecord].close.hour = temp.close.hour;
					venue[searchedRecord].close.minute = temp.close.minute;
					if (saniRecordFound != 0) {
						sanitization[searchedRecordSani].date.day = temp.dateSani.day;
						sanitization[searchedRecordSani].date.month = temp.dateSani.month;
						sanitization[searchedRecordSani].date.year = temp.dateSani.year;
					}
					updatedRecord++;
				}

				fptr = fopen("venueModule.txt", "w");
				for (int writingFile = 0; writingFile < totalRecord; writingFile++)
				{
					fprintf(fptr, "%s|%s|%s|%d|%d|%02d-%02d-%-4d|%02d:%02d|%02d:%02d\n", venue[writingFile].venueID, venue[writingFile].category, venue[writingFile].description, venue[writingFile].maxVisitor, venue[writingFile].currentVisitor, venue[writingFile].dateSani.day, venue[writingFile].dateSani.month, venue[writingFile].dateSani.year, venue[writingFile].open.hour, venue[writingFile].open.minute, venue[writingFile].close.hour, venue[writingFile].close.minute);
				}
				fclose(fptr);

				if (modChoice > 5 && modChoice < 9) {
					fptr2 = fopen("SanitizationModule.txt", "w");
					for (int writingFile2 = 0; writingFile2 < saniRecord; writingFile2++)
					{
						fprintf(fptr2, "%02d-%02d-%d|%02d:%02d|%02d:%02d|%s|%s|%d|%s|%.2f\n", sanitization[writingFile2].date.day, sanitization[writingFile2].date.month, sanitization[writingFile2].date.year, sanitization[writingFile2].time.startTime.hour, sanitization[writingFile2].time.startTime.minute, sanitization[writingFile2].time.endTime.hour, sanitization[writingFile2].time.endTime.minute, sanitization[writingFile2].venue.venueID, sanitization[writingFile2].sanitizer.companyName, sanitization[writingFile2].sanitizer.numberOfWorkers, sanitization[writingFile2].sanitizer.companyContact, sanitization[writingFile2].sanitizer.price);
					}
					fclose(fptr2);
				}

				printf("\n\nUpdated record.\n\n");
				printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
				printf("%-14s%-18s%-21s%-16s%-20s%-18s%-16s%-16s\n", "| Venue ID |", "Venue Category |", "Venue Description |", "Max Visitors |", "Current Visitors |", "Last Sanitized |", "Opening time |", "Closing Time |");
				printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
				printf("| %-9s%-3s%-15s%-3s%-18s%-3s%-13d%-3s%-17d%-4s%-2.02d-%-2.02d-%-8d%-6s%02d:%-7.02d%-6s%02d:%-7.02d%-3s\n", venue[searchedRecord].venueID, "|", venue[searchedRecord].category, "|", venue[searchedRecord].description, "|", venue[searchedRecord].maxVisitor, "|", venue[searchedRecord].currentVisitor, "|", venue[searchedRecord].dateSani.day, venue[searchedRecord].dateSani.month, venue[searchedRecord].dateSani.year, "|", venue[searchedRecord].open.hour, venue[searchedRecord].open.minute, "|", venue[searchedRecord].close.hour, venue[searchedRecord].close.minute, "|");
				printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
			}
			else if (decision == 'N') {
				printf("\nRecord is not modified.\n");
			}
			else {
				printf("\nInvalid choice. Please try again.\n");
			}
		} while (decision != 'Y' && decision != 'N');
		do {
			printf("Continue modifying record? ?(Y = Yes | N = No)"); rewind(stdin);
			scanf("%c", &decision);
			decision = toupper(decision);
			if (decision != 'Y' && decision != 'N') {
				printf("Invalid choice. Please try again.");
			}
		} while (decision != 'Y' && decision != 'N');
	} while (decision == 'Y');

	printf("\n\nTotal records updated  : %d\n", updatedRecord);
}

int modifyVenueMenu() {
	int modChoice;
	printf("\n\n===================================================================\n");
	printf("|| Which category would you like to modify ? (Choose from 1 - 6) ||\n");
	printf("||%-63s||\n", "---------------------------------------------------------------");
	printf("|| %-61s ||\n|| %-61s ||\n|| %-61s ||\n|| %-61s ||\n|| %-61s ||\n|| %-61s ||\n|| %-61s ||\n|| %-61s ||\n", "1. Venue ID", "2. Venue Category", "3. Venue Description", "4. Max Venue Visitors", "5. Current Venue Visitors", "6. Date sanitized", "7. Open/Close time", "8. Modify All.");
	printf("===================================================================\n");
	rewind(stdin);
	scanf("%d", &modChoice);

	return modChoice;
}

void searchRecordVenue() {
	Venue venue[100];
	int totalRecord = 0, Searching, recordFound = 0, venueDigit = 0, venueAlpha = 0, word = 0, choice;
	char searchedRecord[20], decision, validator;
	FILE* fptr;
	fptr = fopen("venueModule.txt", "r");
	if (!fptr) {
		printf("File not found.");
		exit(-1);
	}
	while (fscanf(fptr, "%[^\|]|%[^\|]|%[^\|]|%d|%d|%d-%d-%d|%d:%d|%d:%d\n", &venue[totalRecord].venueID, &venue[totalRecord].category, &venue[totalRecord].description, &venue[totalRecord].maxVisitor, &venue[totalRecord].currentVisitor, &venue[totalRecord].dateSani.day, &venue[totalRecord].dateSani.month, &venue[totalRecord].dateSani.year, &venue[totalRecord].open.hour, &venue[totalRecord].open.minute, &venue[totalRecord].close.hour, &venue[totalRecord].close.minute) != EOF)
	{
		totalRecord++;
	}
	fclose(fptr);
	system("cls");

	do {
		system("cls");
		recordFound = 0;
		choice = searchVenueMenu();
		switch (choice) {
		case 1:
			system("cls");
			printf("======================\n");
			printf("||   Search Report  ||\n");
			printf("======================\n");
			do {
				do {
					venueDigit = 0;
					venueAlpha = 0;
					printf("Enter venue ID (eg. ABC123):"); rewind(stdin);
					scanf("%s", &searchedRecord);
					for (int b = 0; b < 3; b++) {
						searchedRecord[b] = toupper(searchedRecord[b]);
					}
					if (strlen(searchedRecord) > 6) {
						printf("\nInvalid input, no more than 6 letters. Try again.\n");
					}
					if (strlen(searchedRecord) < 6) {
						printf("\nInvalid input, no more than 6 letters. Try again.\n");
					}
					if (strlen(searchedRecord) == 6) {
						for (int a = 0; a < 3; a++) {
							if (isalpha(searchedRecord[a]) == 0) {
								printf("\nFirst 3 letters of a venue ID must be alphabet.\n");
								venueAlpha++;
								break;
							}
						}
						for (int e = 4; e < 6; e++) {
							if (isdigit(searchedRecord[e]) == 0) {
								printf("Last 3 letters of venue ID must be a digit.\n");
								venueDigit++;
								break;
							}
						}
					}
				} while (venueDigit != 0 || venueAlpha != 0 || strlen(searchedRecord) != 6);

				printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
				printf("%-14s%-18s%-21s%-16s%-20s%-18s%-16s%-16s\n", "| Venue ID |", "Venue Category |", "Venue Description |", "Max Visitors |", "Current Visitors |", "Last Sanitized |", "Opening time |", "Closing Time |");
				printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
				for (Searching = 0; Searching < totalRecord; Searching++)
				{
					if (strcmp(venue[Searching].venueID, searchedRecord) == 0)
					{
						printf("| %-9s%-3s%-15s%-3s%-18s%-3s%-13d%-3s%-17d%-4s%-2.02d-%-2.02d-%-8d%-6s%02d:%-7.02d%-6s%02d:%-7.02d%-3s\n", venue[Searching].venueID, "|", venue[Searching].category, "|", venue[Searching].description, "|", venue[Searching].maxVisitor, "|", venue[Searching].currentVisitor, "|", venue[Searching].dateSani.day, venue[Searching].dateSani.month, venue[Searching].dateSani.year, "|", venue[Searching].open.hour, venue[Searching].open.minute, "|", venue[Searching].close.hour, venue[Searching].close.minute, "|");
						printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");

						recordFound++;
					}
				}
				if (recordFound == 0)
				{
					printf("|%-10s|%-17s|%-20s|%-15s|%-19s|%-17s|%-15s|%-15s|\n", "", "", "", "", "", "", "", "");
					printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
					printf("\nNo such record found in the system. \nPress any key to try again or press 0 to quit.\n");
					scanf("%d", &choice);
				}
			} while (recordFound == 0 && choice != 0);
			break;

		case 2:
			system("cls");
			printf("======================\n");
			printf("||   Search Report  ||\n");
			printf("======================\n");
			do {
				do {
					printf("Enter category :"); rewind(stdin);
					scanf("%s", &searchedRecord);
					if (strlen(searchedRecord) > 15) {
						printf("\nInvalid input, no more than 15 letters. Try again.\n");
					}
				} while (strlen(searchedRecord) > 15);
				printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
				printf("%-14s%-18s%-21s%-16s%-20s%-18s%-16s%-16s\n", "| Venue ID |", "Venue Category |", "Venue Description |", "Max Visitors |", "Current Visitors |", "Last Sanitized |", "Opening time |", "Closing Time |");
				printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
				for (Searching = 0; Searching < totalRecord; Searching++)
				{
					if (strcmp(venue[Searching].category, searchedRecord) == 0)
					{
						printf("| %-9s%-3s%-15s%-3s%-18s%-3s%-13d%-3s%-17d%-4s%-2.02d-%-2.02d-%-8d%-6s%02d:%-7.02d%-6s%02d:%-7.02d%-3s\n", venue[Searching].venueID, "|", venue[Searching].category, "|", venue[Searching].description, "|", venue[Searching].maxVisitor, "|", venue[Searching].currentVisitor, "|", venue[Searching].dateSani.day, venue[Searching].dateSani.month, venue[Searching].dateSani.year, "|", venue[Searching].open.hour, venue[Searching].open.minute, "|", venue[Searching].close.hour, venue[Searching].close.minute, "|");
						printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");

						recordFound++;
					}
				}
				if (recordFound == 0)
				{
					printf("|%-10s|%-17s|%-20s|%-15s|%-19s|%-17s|%-15s|%-15s|\n", "", "", "", "", "", "", "", "");
					printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
					printf("\nNo such record found in the system. \nPress any key to try again or press 0 to quit.\n");
					scanf("%d", &choice);
				}
			} while (recordFound == 0 && choice != 0);
			break;

		case 3:
			system("cls");
			printf("======================\n");
			printf("||   Search Report  ||\n");
			printf("======================\n");
			do {
				do {
					printf("Enter description :"); rewind(stdin);
					scanf("%[^\n]", &searchedRecord);
					for (int i = 0; searchedRecord[i] != '\0'; i++) {
						if (searchedRecord[i] == ' ') {
							word++;
						}
					}
					if (word > 16) {
						printf("Invalid input, only 15 words allowed. Try again.");
					}
				} while (word > 16);

				printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
				printf("%-14s%-18s%-21s%-16s%-20s%-18s%-16s%-16s\n", "| Venue ID |", "Venue Category |", "Venue Description |", "Max Visitors |", "Current Visitors |", "Last Sanitized |", "Opening time |", "Closing Time |");
				printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
				for (Searching = 0; Searching < totalRecord; Searching++)
				{
					if (strcmp(venue[Searching].description, searchedRecord) == 0)
					{
						printf("| %-9s%-3s%-15s%-3s%-18s%-3s%-13d%-3s%-17d%-4s%-2.02d-%-2.02d-%-8d%-6s%02d:%-7.02d%-6s%02d:%-7.02d%-3s\n", venue[Searching].venueID, "|", venue[Searching].category, "|", venue[Searching].description, "|", venue[Searching].maxVisitor, "|", venue[Searching].currentVisitor, "|", venue[Searching].dateSani.day, venue[Searching].dateSani.month, venue[Searching].dateSani.year, "|", venue[Searching].open.hour, venue[Searching].open.minute, "|", venue[Searching].close.hour, venue[Searching].close.minute, "|");
						printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");

						recordFound++;
					}
				}

				if (recordFound == 0)
				{
					printf("|%-10s|%-17s|%-20s|%-15s|%-19s|%-17s|%-15s|%-15s|\n", "", "", "", "", "", "", "", "");
					printf("%s\n", "+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
					printf("No such record found in the system. \nPress any key to try again or press 0 to quit.\n");
					scanf("%d", &choice);
				}
			} while (recordFound == 0 && choice != 0);
			break;
		}

		printf("Total record found : %d\n\n", recordFound);

		do {
			printf("Continue searching? (Y = Yes | N = No)"); rewind(stdin);
			scanf("%c", &decision);
			decision = toupper(decision);
			if (decision != 'Y' && decision != 'N') {
				printf("Invalid choice. Please try again.");
			}
		} while (decision != 'Y' && decision != 'N');
	} while (decision == 'Y');
}

void deleteRecordVenue() {
	FILE* fptr;
	FILE* fptr2;
	Venue venue[100];
	int totalRecord = 0, recordFound = 0, choice, delListNo = 0, totalDeleted = 0, delRecord, searchedRecord;
	char deleteCate[20], decision;

	fptr = fopen("venueModule.txt", "r");
	if (!fptr) {
		printf("File not found");
		exit(-1);
	}
	while (fscanf(fptr, "%[^\|]|%[^\|]|%[^\|]|%d|%d|%d-%d-%d|%d:%d|%d:%d\n", &venue[totalRecord].venueID, &venue[totalRecord].category, &venue[totalRecord].description, &venue[totalRecord].maxVisitor, &venue[totalRecord].currentVisitor, &venue[totalRecord].dateSani.day, &venue[totalRecord].dateSani.month, &venue[totalRecord].dateSani.year, &venue[totalRecord].open.hour, &venue[totalRecord].open.minute, &venue[totalRecord].close.hour, &venue[totalRecord].close.minute) != EOF) {
		totalRecord++;
	}
	fclose(fptr);

	do {
		recordFound = 0;
		delListNo = 0;
		do {
			system("cls");
			printf("======================\n");
			printf("||  Delete Records  ||\n");
			printf("======================");
			printf("\n\nEnter venue category that you wish to delete. (Eg.laboratory)"); rewind(stdin);
			scanf("%s", &deleteCate);

			printf("%s\n", "+-----+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
			printf("%-3s%-14s%-18s%-21s%-16s%-20s%-18s%-16s%-16s\n", "| No. ", "| Venue ID |", "Venue Category |", "Venue Description |", "Max Visitors |", "Current Visitors |", "Last Sanitized |", "Opening time |", "Closing Time |");
			printf("%s\n", "+-----+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
			for (int i = 0; i < totalRecord; i++)
			{
				if (strcmp(venue[i].category, deleteCate) == 0)
				{
					delListNo++;
					printf("|%-5d%-3s%-8s%-3s%-15s%-3s%-18s%-3s%-13d%-3s%-17d%-4s%-2.02d-%-2.02d-%-8d%-6s%02d:%-7.02d%-6s%02d:%-7.02d%-3s\n", delListNo, "|", venue[i].venueID, "|", venue[i].category, "|", venue[i].description, "|", venue[i].maxVisitor, "|", venue[i].currentVisitor, "|", venue[i].dateSani.day, venue[i].dateSani.month, venue[i].dateSani.year, "|", venue[i].open.hour, venue[i].open.minute, "|", venue[i].close.hour, venue[i].close.minute, "|");
					recordFound++;
					searchedRecord = i;
				}
			}
			if (recordFound == 0)
			{
				printf("|%-5s|%-10s|%-17s|%-20s|%-15s|%-19s|%-17s|%-15s|%-15s|\n", "", "", "", "", "", "", "", "", "");
				printf("%s\n", "+-----+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
				printf("\nVenue category not found in records. \nPress any key to try again or press 0 to exit.\n"); rewind(stdin);
				scanf("%d", &choice);
			}
			else if (recordFound == 1)
			{
				printf("%s\n", "+-----+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
				do {
					printf("\n\nDo you wish to delete the record ? (Y = Yes | N = No)"); rewind(stdin);
					scanf("%c", &decision);
					decision = toupper(decision);
					if (decision == 'Y')
					{
						do {
							venue[searchedRecord] = venue[searchedRecord + 1];
							searchedRecord++;
						} while (searchedRecord < totalRecord);

						totalDeleted++;
						totalRecord--;

						fptr2 = fopen("venueModule.txt", "w");
						for (int writingFile = 0; writingFile < totalRecord; writingFile++)
						{
							fprintf(fptr2, "%s|%s|%s|%d|%d|%02d-%02d-%-4d|%02d:%02d|%02d:%02d\n", venue[writingFile].venueID, venue[writingFile].category, venue[writingFile].description, venue[writingFile].maxVisitor, venue[writingFile].currentVisitor, venue[writingFile].dateSani.day, venue[writingFile].dateSani.month, venue[writingFile].dateSani.year, venue[writingFile].open.hour, venue[writingFile].open.minute, venue[writingFile].close.hour, venue[writingFile].close.minute);
						}
						fclose(fptr2);

						printf("\n\nRecord deleted.\n");
					}
					else if (decision == 'N') {
						printf("\nRecord not deleted\n\n");
					}
					else {
						printf("Invalid choice, Please try again.");
					}
				} while (decision != 'Y' && decision != 'N');
			}
			else {
				printf("%s\n", "+-----+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");

				do {
					printf("Enter record that you wish to delete. (Eg. 1)");
					scanf("%d", &delRecord);

					if (delRecord > delListNo && delRecord < delListNo) {
						printf("\nInvalid record, enter the number according to the table shown ( No. )\n");
					}
				} while (delRecord > delListNo && delRecord < delListNo);

				delListNo = 1;
				for (int a = 0; a < totalRecord; a++)
				{
					if (strcmp(venue[a].category, deleteCate) == 0) {
						if (delListNo == delRecord) {
							printf("%s\n", "+-----+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
							printf("%-3s%-14s%-18s%-21s%-16s%-20s%-18s%-16s%-16s\n", "| No. ", "| Venue ID |", "Venue Category |", "Venue Description |", "Max Visitors |", "Current Visitors |", "Last Sanitized |", "Opening time |", "Closing Time |");
							printf("%s\n", "+-----+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
							printf("|%-5d%-3s%-8s%-3s%-15s%-3s%-18s%-3s%-13d%-3s%-17d%-4s%-2.02d-%-2.02d-%-8d%-6s%02d:%-7.02d%-6s%02d:%-7.02d%-3s\n", delListNo, "|", venue[a].venueID, "|", venue[a].category, "|", venue[a].description, "|", venue[a].maxVisitor, "|", venue[a].currentVisitor, "|", venue[a].dateSani.day, venue[a].dateSani.month, venue[a].dateSani.year, "|", venue[a].open.hour, venue[a].open.minute, "|", venue[a].close.hour, venue[a].close.minute, "|");
							printf("%s\n\n", "+-----+----------+-----------------+--------------------+---------------+-------------------+-----------------+---------------+---------------+");
							do {
								printf("Do you wish to delete the record ? (Y = Yes | N = No)");  rewind(stdin);
								scanf("%c", &decision);
								decision = toupper(decision);
								if (decision == 'Y')
								{
									do {
										venue[a] = venue[a + 1];
										a++;
									} while (a < totalRecord);
									totalDeleted++;
									totalRecord--;

									fptr2 = fopen("venueModule.txt", "w");
									for (int writingFile = 0; writingFile < totalRecord; writingFile++)
									{
										fprintf(fptr2, "%s|%s|%s|%d|%d|%02d-%02d-%-4d|%02d:%02d|%02d:%02d\n", venue[writingFile].venueID, venue[writingFile].category, venue[writingFile].description, venue[writingFile].maxVisitor, venue[writingFile].currentVisitor, venue[writingFile].dateSani.day, venue[writingFile].dateSani.month, venue[writingFile].dateSani.year, venue[writingFile].open.hour, venue[writingFile].open.minute, venue[writingFile].close.hour, venue[writingFile].close.minute);
									}
									fclose(fptr2);

									printf("\nRecord deleted.\n");
								}
								else if (decision == 'N') {
									printf("\nRecord not deleted\n\n");
								}
								else {
									printf("\nInvalid choice, Please try again.\n\n");
								}
							} while (decision != 'Y' && decision != 'N');
						}
						delListNo++;
					}
				}
			}
		} while (recordFound == 0 && choice != 0);
		do {
			printf("Continue to delete more records ? (Y = Yes | N = No)"); rewind(stdin);
			scanf("%c", &decision);
			decision = toupper(decision);
			if (decision != 'Y' && decision != 'N') {
				printf("\nInvalid choice. Please try again.\n");
			}
		} while (decision != 'Y' && decision != 'N');
	} while (decision == 'Y');

	printf("\n\nTotal records deleted  : %d\n", totalDeleted);
}

void reportVenue() {
	Venue venue[100];
	Date recordDate;
	Date currentDate;
	int totalRecord = 0;
	int maxDay;
	int currentDayReport;
	int currentMonthReport;
	int currentYearReport;
	int currentTotalDays = 0;
	int recordTotalDays = 0;
	int lastSanitized;
	int yearDif = 0;
	int tempDays = 0;
	char dateValidator[2];
	char venueStatus[40];
	char sanitizeStatus[20] = "Unknown";

	FILE* fptr;

	fptr = fopen("venueModule.txt", "r");
	if (!fptr) {
		printf("File not found.");
		exit(-1);
	}
	system("cls");
	printf("====================\n");
	printf("||  Venue Report  ||\n");
	printf("====================");
	do {
		printf("\n\nEnter current date(DD-MM-YYYY):"); rewind(stdin);
		scanf("%d%c%d%c%d", &currentDate.day, &dateValidator[0], &currentDate.month, &dateValidator[1], &currentDate.year);

		switch (currentDate.month) {

		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: {
			maxDay = 31;
		}break;
		case 2: {
			if (currentDate.year % 4 == 0) {
				maxDay = 29;
			}
			else
			{
				maxDay = 28;
			}
		}break;

		default:
			maxDay = 30;
		}

		if (dateValidator[0] != '-' || dateValidator[1] != '-') {
			printf("\nOnly '-' Available for Date Format\n");
		}
		else if (currentDate.day < 1 || currentDate.day > maxDay || currentDate.month < 0 || currentDate.month > 12) {
			printf("\nInvalid Date's/Month's Range\n");
		}
		if (currentDate.year < 2020 || currentDate.year > 2021) {
			printf("\nInvalid year. Please try again.\n");
		}
	} while (currentDate.day < 1 || currentDate.day > maxDay || currentDate.month < 0 || currentDate.month > 12 || dateValidator[0] != '-' || dateValidator[1] != '-' || (currentDate.year < 2020 || currentDate.year > 2021));

	printf("%86s", "============================================================\n");
	printf("%27s%34s %23s\n", "||", "Venue Report", "||");
	printf("%86s", "============================================================\n");


	printf("+----------+----------------+------------------+-------------------+----------------------------------------+\n");
	printf("%s%17s%19s%16s%4s%28s%13s\n", "| Venue ID |", "Venue Category |", "Current Visitors |", "Last sanitized", "|", "Status Of Venue", "|");
	printf("+----------+----------------+------------------+-------------------+----------------------------------------+\n");

	currentTotalDays = totalDayCount(&currentDate);

	while (fscanf(fptr, "%[^\|]|%[^\|]|%[^\|]|%d|%d|%d-%d-%d|%d:%d|%d:%d\n", &venue[totalRecord].venueID, &venue[totalRecord].category, &venue[totalRecord].description, &venue[totalRecord].maxVisitor, &venue[totalRecord].currentVisitor, &venue[totalRecord].dateSani.day, &venue[totalRecord].dateSani.month, &venue[totalRecord].dateSani.year, &venue[totalRecord].open.hour, &venue[totalRecord].open.minute, &venue[totalRecord].close.hour, &venue[totalRecord].close.minute) != EOF) {
		if (yearDif > 0) {
			currentTotalDays = currentTotalDays - tempDays;
		}
		else {
			recordTotalDays = recordTotalDays - tempDays;
		}
		tempDays = 0;
		yearDif = 0;
		yearDif = currentDate.year - venue[totalRecord].dateSani.year;
		if (yearDif > 0) {
			if (venue[totalRecord].dateSani.year % 4 == 0) {
				currentTotalDays = currentTotalDays + (366 * yearDif);
				tempDays = 366 * yearDif;
			}
			else {
				currentTotalDays = currentTotalDays + (365 * yearDif);
				tempDays = 365 * yearDif;
			}
		}

		recordTotalDays = totalDayCount(&venue[totalRecord].dateSani);

		lastSanitized = currentTotalDays - recordTotalDays;
		if (lastSanitized >= 30) {
			strcpy(venueStatus, "Venue in urgent need of sanitization. ");
			strcpy(sanitizeStatus, " Day(s) Ago.");
		}
		else if (lastSanitized >= 7) {
			strcpy(venueStatus, "Venue needs to be sanitized in a week.");
			strcpy(sanitizeStatus, " Day(s) Ago.");
		}
		else if (lastSanitized >= 0 && lastSanitized < 7) {
			strcpy(venueStatus, "Venue is safe to use.                 ");
			if (lastSanitized == 0) {
				strcpy(sanitizeStatus, " Today      ");
			}
			else {
				strcpy(sanitizeStatus, " Day(s) Ago.");
			}
		}
		else {
			strcpy(venueStatus, "Venue is safe to use.                 ");
			strcpy(sanitizeStatus, " Hereafter.");
			lastSanitized = abs(lastSanitized);
		}

		if (lastSanitized == 0) {
			printf("| %-9s%-3s%-14s%-9s%-10d%-4s%-2s%-14s%-3s%-11s%-s\n", venue[totalRecord].venueID, "|", venue[totalRecord].category, "|", venue[totalRecord].currentVisitor, "|", " ", sanitizeStatus, "|", venueStatus, "|");
			printf("+----------+----------------+------------------+-------------------+----------------------------------------+\n");
		}
		else {
			printf("| %-9s%-3s%-14s%-9s%-10d%-4s%-3d%-13s%-3s%-11s%-s\n", venue[totalRecord].venueID, "|", venue[totalRecord].category, "|", venue[totalRecord].currentVisitor, "|", lastSanitized, sanitizeStatus, "|", venueStatus, "|");
			printf("+----------+----------------+------------------+-------------------+----------------------------------------+\n");
		}
		totalRecord++;
	}
	printf("\n\nTotal Record Shown : %d\n", totalRecord);
}

int totalDayCount(Date* dateV) {
	int year;
	int dayInMonth = 0;
	int totalDays;

	year = 365;

	for (int monthCheck = 1; monthCheck < dateV->month; monthCheck++) {
		switch (monthCheck) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: {
			dayInMonth = dayInMonth + 31;
		}break;
		case 2: {
			if (dateV->year % 4 == 0) {
				dayInMonth = dayInMonth + 29;
			}
			else {
				dayInMonth = dayInMonth + 28;
			}

		}break;
		default:
			dayInMonth = dayInMonth + 30;
		}
	}
	totalDays = year + dayInMonth + dateV->day;
}

int sanitizationMenu()//Menu of modules in Sanitization Records
{
	int numberOfModule; //Number of module prompt and read by user
	char decision;//Decision to return to menu
	char validator;//To validate
	do
	{
		do
		{
			numberOfModule = 0;//Assign to 0
			system("cls");//Clear screen
			heading();
			//Display Modules in Sanitization Module for user to choose
			printf("%13s===============================================\n", "");
			printf("%13s||%31s%14s\n", "", "Sanitization Module", "||");
			printf("%13s||%-43s||\n", "", "-------------------------------------------");
			printf("%13s|| %31s%13s\n%13s|| %22s%22s\n%13s|| %25s%19s\n%13s|| %25s%19s\n%13s|| %25s%19s\n%13s|| %25s%19s\n%13s|| %25s%19s\n", "", "1. Display the Records", "||", "", "2. Add Record", "||", "", "3. Modify Record", "||", "", "4. Search Record", "||", "", "5. Delete Record", "||", "", "6. Report Record", "||", "", "7. Exit Function", "||");
			printf("%13s===============================================\n", "");
			printf("----Please enter your selection : "); rewind(stdin);//Prompt and read number of module
			scanf("%d%c", &numberOfModule, &validator);
			switch (numberOfModule)
			{
			case 1:
				displaySanitization(); break;//Go to display module in Sanitization Records
			case 2:
				addSanitization(); break;//Go to add module in Sanitization Records
			case 3:
				modifySanitization(); break;//Go to modify module in Sanitization Records
			case 4:
				searchSanitization(); break;//Go to search module in Sanitization Records
			case 5:
				deleteSanitization(); break;//Go to delete module in Sanitization Records
			case 6:
				reportSanitization(); break;//Go to report module in Sanitization Records
			case 7:
				return 1;//Go back to main function
			default: {
				printf("Please choose a number within the range given.\n");
				getchar();
			}
			}//End switch
			if (validator != '\n') {
				printf("Only numeric input is acceptable!\n");
			}
		} while (numberOfModule < 1 || numberOfModule > 7 || validator != '\n');//End loop for validation of number of module
		do {
			printf("\n\nReturn to Sanitization Menu ? (Y = Yes | N = No)"); rewind(stdin);//Prompt and read decision
			scanf("%c", &decision);
			decision = toupper(decision);
			if (decision != 'Y' && decision != 'N') {
				printf("Invalid choice. Please try again.\n");
			}
		} while (decision != 'Y' && decision != 'N');
	} while (decision == 'Y');//End loop to exit
}

void displaySanitization()//Display module in Sanitization Records
{
	Sanitization sanitization;//Declara variable sanitization for struct Sanitization
	int numberOfRecords = 0;//number of records contains in the file
	FILE* fptr;//Declara file pointer
	fptr = fopen("SanitizationModule.txt", "r");//Open file to read
	if (fptr == NULL)//Check if file exist
	{
		printf("Error");
		exit(-1);//Exit program
	}

	system("cls");//Clear screen
	//Display title
	printf("+========================+\n");
	printf("+  %-22s+\n", "Display Sanitization");
	printf("+========================+\n");
	printf("+------------+------------+------------+----------+------------------------------+------------------+-----------------+-----------+\n");
	printf("|%8s%5s%11s%2s%10s%3s%9s%2s%21s%10s%17s%2s%16s%2s%10s%2s\n", "Date", "|", "Start Time", "|", "End Time", "|", "Venue ID", "|", "Company Name", "|", "Number Of Worker", "|", "Company Contact", "|", "Price(RM)", "|");
	printf("+------------+------------+------------+----------+------------------------------+------------------+-----------------+-----------+\n");

	//Read from file
	while (fscanf(fptr, "%d-%d-%d|%d:%d|%d:%d|%[^\|]|%[^\|]|%d|%[^\|]|%f\n", &sanitization.date.day, &sanitization.date.month, &sanitization.date.year,
		&sanitization.time.startTime.hour, &sanitization.time.startTime.minute, &sanitization.time.endTime.hour, &sanitization.time.endTime.minute, &sanitization.venue.venueID,
		&sanitization.sanitizer.companyName, &sanitization.sanitizer.numberOfWorkers, &sanitization.sanitizer.companyContact, &sanitization.sanitizer.price) != EOF)
	{
		numberOfRecords++;//To count number of records
		//Display all records
		printf("| %02d-%02d-%d |   %02d:%02d    |   %02d:%02d    | %-8s | %-28s | %9d%9s%14s%4s%9.2f%3s\n", sanitization.date.day, sanitization.date.month, sanitization.date.year,
			sanitization.time.startTime.hour, sanitization.time.startTime.minute, sanitization.time.endTime.hour, sanitization.time.endTime.minute, sanitization.venue.venueID,
			sanitization.sanitizer.companyName, sanitization.sanitizer.numberOfWorkers, "|", sanitization.sanitizer.companyContact, "|", sanitization.sanitizer.price, "|");
		printf("+------------+------------+------------+----------+------------------------------+------------------+-----------------+-----------+\n");
	}

	printf("%d of Records Displayed--\n", numberOfRecords);//Display total number of records displayed
	fclose(fptr);//Close file
}

void addSanitization()//Add module in Sanitization Records
{
	Sanitization tmpS;//Declara variable tmpS for struct Sanitization for temporarily purpose
	char proceed;//Proceed to loop
	char commit;//commit to save into file
	FILE* fptr;//Declara file pointer
	fptr = fopen("SanitizationModule.txt", "a");//Open file to append
	if (fptr == NULL)//Check if file exist
	{
		printf("Error");
		exit(-1);//Exit program
	}

	do
	{
		system("cls");//Clear screen
		sanitizationInput(&tmpS);//Call function for user to input using &tmpS to store
		//Display record inputted
		printf("+------------+------------+------------+----------+------------------------------+------------------+-----------------+-----------+\n");
		printf("|%8s%5s%11s%2s%10s%3s%9s%2s%21s%10s%17s%2s%16s%2s%10s%2s\n", "Date", "|", "Start Time", "|", "End Time", "|", "Venue ID", "|", "Company Name", "|", "Number Of Worker", "|", "Company Contact", "|", "Price(RM)", "|");
		printf("+------------+------------+------------+----------+------------------------------+------------------+-----------------+-----------+\n");
		printf("| %02d-%02d-%d |   %02d:%02d    |   %02d:%02d    | %-8s | %-28s | %9d%9s%14s%4s%9.2f%3s\n", tmpS.date.day, tmpS.date.month, tmpS.date.year, tmpS.time.startTime.hour, tmpS.time.startTime.minute, tmpS.time.endTime.hour, tmpS.time.endTime.minute, tmpS.venue.venueID, tmpS.sanitizer.companyName, tmpS.sanitizer.numberOfWorkers, "|", tmpS.sanitizer.companyContact, "|", tmpS.sanitizer.price, "|");
		printf("+------------+------------+------------+----------+------------------------------+------------------+-----------------+-----------+\n");
		printf("Comfirm to commit (Y = yes) ? "); rewind(stdin);//Prompt and read commit
		scanf("%c", &commit);
		commit = toupper(commit);
		if (commit == 'Y')//if yes, write to file
		{
			fprintf(fptr, "%02d-%02d-%d|%02d:%02d|%02d:%02d|%s|%s|%d|%s|%.2f\n", tmpS.date.day, tmpS.date.month, tmpS.date.year, tmpS.time.startTime.hour, tmpS.time.startTime.minute, tmpS.time.endTime.hour, tmpS.time.endTime.minute, tmpS.venue.venueID, tmpS.sanitizer.companyName, tmpS.sanitizer.numberOfWorkers, tmpS.sanitizer.companyContact, tmpS.sanitizer.price);
		}
		do {
			printf("Proceed to add new data? (Y = Yes | N = No)"); rewind(stdin);//Prompt and read proceed
			scanf("%c", &proceed);
			proceed = toupper(proceed);
			if (proceed != 'Y' && proceed != 'N') {
				printf("Invalid choice.Please try again.\n");
			}
		} while (proceed != 'Y' && proceed != 'N');
	} while (proceed == 'Y');//End loop to exit
	fclose(fptr);//Close file
}

void sanitizationInput(Sanitization* tmpS)//Input function for Sanitization Records
{
	Venue venue[100];//Declara variable venue for struct Sanitization for temporarily purpose
	int numberOfRecords = 0;//number of records contains in the file
	char connector[4];//Connector for Date and IC
	int dayMax;//Maximum day in a month
	int venueChar = 0;//Venue's character
	int venueDigit = 0;//Venue's digit
	int exist;//Venue existing in file
	char validator;//T validate
	FILE* fptr;//Declara file pointer
	fptr = fopen("venueModule.txt", "r");//Open file to read
	if (fptr == NULL)//Check if file exist
	{
		printf("Error");
		exit(-1);//Exit program
	}

	//Read from file
	while (fscanf(fptr, "%[^\|]|%[^\|]|%[^\|]|%d|%d|%d-%d-%d|%d:%d|%d:%d\n", &venue[numberOfRecords].venueID, &venue[numberOfRecords].category, &venue[numberOfRecords].description, &venue[numberOfRecords].maxVisitor, &venue[numberOfRecords].currentVisitor, &venue[numberOfRecords].dateSani.day, &venue[numberOfRecords].dateSani.month, &venue[numberOfRecords].dateSani.year, &venue[numberOfRecords].open.hour, &venue[numberOfRecords].open.minute, &venue[numberOfRecords].close.hour, &venue[numberOfRecords].close.minute) != EOF)
	{
		numberOfRecords++;//Store records from file for validation
	}
	fclose(fptr);//Close file

	system("cls");//Clear screen

	do
	{
		printf("Enter Date (DD-MM-YYYY) : "); rewind(stdin);//Prompt and ead Date
		scanf("%d%c%d%c%d", &tmpS->date.day, &connector[0], &tmpS->date.month, &connector[1], &tmpS->date.year);
		switch (tmpS->date.month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: dayMax = 31; break;
		case 2: if (tmpS->date.year % 4 == 0)
			dayMax = 29;
			  else
			dayMax = 28;
			break;
		default:
			dayMax = 30;
		}//End switch
		if (connector[0] != '-' || connector[1] != '-')
			printf("Please follow the format shown.\a\n");
		if (tmpS->date.month < 1 || tmpS->date.month > 12 || tmpS->date.day < 1 || tmpS->date.day > dayMax)
			printf("Invalid date.\a\n");//End for Date validation
	} while (tmpS->date.month < 1 || tmpS->date.month > 12 || tmpS->date.day < 1 || tmpS->date.day > dayMax || connector[0] != '-' || connector[1] != '-');//End loop for Date validation

	do
	{
		printf("Enter Start Time (HH:MM) in 24-hour clock > "); rewind(stdin);//Prompt and read Start Time
		scanf("%d%c%d", &tmpS->time.startTime.hour, &connector[2], &tmpS->time.startTime.minute);
		if (connector[2] != ':')
			printf("Please follow the format shown.\a\n");
		if (tmpS->time.startTime.hour < 0 || tmpS->time.startTime.hour > 23 || tmpS->time.startTime.minute < 0 || tmpS->time.startTime.minute > 59)
			printf("Invalid time.\a\n");//End for start time validation
	} while (tmpS->time.startTime.hour < 0 || tmpS->time.startTime.hour > 23 || tmpS->time.startTime.minute < 0 || tmpS->time.startTime.minute > 59 || connector[2] != ':');//End loop for Start Time validation

	do
	{
		printf("Enter End Time (HH:MM) in 24-hour clock > "); rewind(stdin);//Prompt and read End time
		scanf("%d%c%d", &tmpS->time.endTime.hour, &connector[3], &tmpS->time.endTime.minute);
		if (connector[3] != ':')
			printf("Please follow the format shown.\a\n");
		if (tmpS->time.endTime.hour < 0 || tmpS->time.endTime.hour > 23 || tmpS->time.endTime.minute < 0 || tmpS->time.endTime.minute > 59)
			printf("Invalid time.\a\n");
		if (tmpS->time.startTime.hour > tmpS->time.endTime.hour)
			printf("End Time must be after Start Time.\n\a");
		if (tmpS->time.startTime.hour == tmpS->time.endTime.hour)
			if (tmpS->time.startTime.minute > tmpS->time.endTime.minute)
				printf("End Time must be after Start Time.\n\a");//End for End Time validation
	} while (tmpS->time.endTime.hour < 0 || tmpS->time.endTime.hour > 23 || tmpS->time.endTime.minute < 0 || tmpS->time.endTime.minute > 59 || connector[3] != ':' ||
		tmpS->time.startTime.hour > tmpS->time.endTime.hour || (tmpS->time.startTime.hour == tmpS->time.endTime.hour && tmpS->time.startTime.minute > tmpS->time.endTime.minute));//End loop for End Time validation

	do {
		venueChar = 0;//Assign to 0
		venueDigit = 0;//Assign to 0
		printf("Enter Venue ID(eg. ABC123):"); rewind(stdin);//Prompt and read Venue ID
		scanf("%s", &tmpS->venue.venueID);

		//Check for venue character
		for (int i = 0; i < 3; i++) {
			if (isalpha(tmpS->venue.venueID[i]) == 0) {
				printf("\nFirst 3 letters of a venue ID must be alphabet.\n");
				venueChar++;
				break;
			}
		}
		//Check for venue digit
		for (int j = 4; j < 6; j++) {
			if (isdigit(tmpS->venue.venueID[j]) == 0) {
				printf("Last 3 letters of venue ID must be a digit\n");
				venueDigit++;
				break;
			}
		}
		//Convert venue character
		for (int v = 0; v < 6; v++) {
			tmpS->venue.venueID[v] = toupper(tmpS->venue.venueID[v]);
		}
		//Check venue from file
		for (int u = 0; u < numberOfRecords; u++) {
			if (strcmp(tmpS->venue.venueID, venue[u].venueID) == 0) {
				exist = 1;
			}
		}
		if (exist == 0) {
			printf("Venue ID Not Existing!\n");
		}
	} while (strlen(tmpS->venue.venueID) > 8 || venueChar != 0 || venueDigit != 0 || exist == 0);//End loop for Venue ID validation

	printf("Enter Company Name > "); rewind(stdin);//Prompt and read Company Name
	scanf("%[^\n]", &tmpS->sanitizer.companyName);

	do
	{
		printf("Enter number of workers > ");  rewind(stdin);//Prompt and read number of workers from company
		scanf("%d%c", &tmpS->sanitizer.numberOfWorkers, &validator);
		if (tmpS->sanitizer.numberOfWorkers < 1 || validator != '\n')
			printf("Invalid input.\n");//End for number of workers validation
	} while (tmpS->sanitizer.numberOfWorkers < 1 || validator != '\n');//End loop for number of workers validation

	do
	{
		printf("Enter Company Contact Number (012-3456789) > "); rewind(stdin);//Prompt and read Company Contact Number
		scanf("%s", &tmpS->sanitizer.companyContact);
		if (isdigit(tmpS->sanitizer.companyContact[0]) == 0 || isdigit(tmpS->sanitizer.companyContact[1]) == 0 || isdigit(tmpS->sanitizer.companyContact[2]) == 0 || isdigit(tmpS->sanitizer.companyContact[4]) == 0 || isdigit(tmpS->sanitizer.companyContact[5]) == 0 || isdigit(tmpS->sanitizer.companyContact[6]) == 0 || isdigit(tmpS->sanitizer.companyContact[7]) == 0 || isdigit(tmpS->sanitizer.companyContact[8]) == 0 || isdigit(tmpS->sanitizer.companyContact[9]) == 0 || isdigit(tmpS->sanitizer.companyContact[10]) == 0)
			printf("Please ensure input is numeric\a\n");
		else if (tmpS->sanitizer.companyContact[3] != '-' || strlen(tmpS->sanitizer.companyContact) < 11 || strlen(tmpS->sanitizer.companyContact) > 13)
			printf("Please follow the format.\a\n");//End for Company Contact Number validation
	} while (isdigit(tmpS->sanitizer.companyContact[0]) == 0 || isdigit(tmpS->sanitizer.companyContact[1]) == 0 || isdigit(tmpS->sanitizer.companyContact[2]) == 0 || isdigit(tmpS->sanitizer.companyContact[4]) == 0 || isdigit(tmpS->sanitizer.companyContact[5]) == 0 || isdigit(tmpS->sanitizer.companyContact[6]) == 0 || isdigit(tmpS->sanitizer.companyContact[7]) == 0 || isdigit(tmpS->sanitizer.companyContact[8]) == 0 || isdigit(tmpS->sanitizer.companyContact[9]) == 0 || isdigit(tmpS->sanitizer.companyContact[10]) == 0 || tmpS->sanitizer.companyContact[3] != '-' || strlen(tmpS->sanitizer.companyContact) < 11 || strlen(tmpS->sanitizer.companyContact) > 13);//End loop for Company Contact Number validation

	do
	{
		printf("Enter price > "); rewind(stdin);//Prompt and read Price
		scanf("%f%c", &tmpS->sanitizer.price, &validator);
		if (tmpS->sanitizer.numberOfWorkers <= 0 || validator != '\n')
			printf("Invalid input.\n");//End for Price validation
	} while (tmpS->sanitizer.price <= 0 || validator != '\n');//End loop for Price validation

	for (int i = 0; i < numberOfRecords; i++)
	{
		if (strcmp(venue[i].venueID, tmpS->venue.venueID) == 0)
		{
			venue[i].dateSani = tmpS->date;
		}
	}
}

void searchSanitization()//Search module in Sanitization Records
{
	Sanitization sanitization[100];//Declara variable sanitization for 100 in struct Sanitization
	Sanitization tmpS;//Declara variable tmpS for struct Sanitization for temporarily purpose
	int numberOfRecords = 0;//number of records contains in the file
	int selection;//Selection from user
	char connector[2];//Connector for Date
	int dayMax;//Maximum day in a month
	int recordDisplay = 0;//Record displayed
	int venueChar = 0;//Venue's character
	int venueDigit = 0;//Venue's digit
	int exist;//Venue existing in file
	char proceed;//Proceed to loop
	FILE* fptr;//Declara file pointer
	fptr = fopen("SanitizationModule.txt", "r");//Open file to read
	if (fptr == NULL)//Check if file exist
	{
		printf("Error");
		exit(-1);//Exit program
	}

	//Read from file
	while (fscanf(fptr, "%d-%d-%d|%d:%d|%d:%d|%[^\|]|%[^\|]|%d|%[^\|]|%f\n", &sanitization[numberOfRecords].date.day, &sanitization[numberOfRecords].date.month, &sanitization[numberOfRecords].date.year, &sanitization[numberOfRecords].time.startTime.hour, &sanitization[numberOfRecords].time.startTime.minute, &sanitization[numberOfRecords].time.endTime.hour, &sanitization[numberOfRecords].time.endTime.minute, &sanitization[numberOfRecords].venue.venueID, &sanitization[numberOfRecords].sanitizer.companyName, &sanitization[numberOfRecords].sanitizer.numberOfWorkers, &sanitization[numberOfRecords].sanitizer.companyContact, &sanitization[numberOfRecords].sanitizer.price) != EOF)
	{
		numberOfRecords++;//To count number of records
	}

	do
	{
		system("cls");//Clear screen
		selection = searchMenuSani();//Call function and assign data into selection
		if (selection == -1) {
			break;
		}
		switch (selection)
		{
		case 1: {
			do
			{
				printf("Enter Date (DD-MM-YYYY) > "); rewind(stdin);//Prompt and ead Date
				scanf("%d%c%d%c%d", &tmpS.date.day, &connector[0], &tmpS.date.month, &connector[1], &tmpS.date.year);
				switch (tmpS.date.month)
				{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12: dayMax = 31; break;
				case 2: if (tmpS.date.year % 4 == 0)
					dayMax = 29;
					  else
					dayMax = 28;
					break;
				default:
					dayMax = 30;
				}//End switch
				if (connector[0] != '-' || connector[1] != '-')
					printf("Please follow the format shown.\a\n");
				if (tmpS.date.month < 1 || tmpS.date.month > 12 || tmpS.date.day < 1 || tmpS.date.day > dayMax)
					printf("Invalid date.\a\n");//End for Date validation
			} while (tmpS.date.month < 1 || tmpS.date.month > 12 || tmpS.date.day < 1 || tmpS.date.day > dayMax || connector[0] != '-' || connector[1] != '-');//End loop for Date validation

			//Display title
			printf("+------------+------------+------------+----------+------------------------------+------------------+-----------------+-----------+\n");
			printf("|%8s%5s%11s%2s%10s%3s%9s%2s%21s%10s%17s%2s%16s%2s%10s%2s\n", "Date", "|", "Start Time", "|", "End Time", "|", "Venue ID", "|", "Company Name", "|", "Number Of Worker", "|", "Company Contact", "|", "Price(RM)", "|");
			printf("+------------+------------+------------+----------+------------------------------+------------------+-----------------+-----------+\n");
			//Loop to display records
			for (int i = 0; i < numberOfRecords; i++)
			{
				if (sanitization[i].date.day == tmpS.date.day && sanitization[i].date.month == tmpS.date.month && sanitization[i].date.year == tmpS.date.year)
				{
					recordDisplay++;//Count record Displayed
					printf("| %02d-%02d-%d |   %02d:%02d    |   %02d:%02d    | %-8s | %-28s | %9d%9s%14s%4s%9.2f%3s\n", sanitization[i].date.day, sanitization[i].date.month, sanitization[i].date.year, sanitization[i].time.startTime.hour, sanitization[i].time.startTime.minute, sanitization[i].time.endTime.hour, sanitization[i].time.endTime.minute, sanitization[i].venue.venueID, sanitization[i].sanitizer.companyName, sanitization[i].sanitizer.numberOfWorkers, "|", sanitization[i].sanitizer.companyContact, "|", sanitization[i].sanitizer.price, "|");
					printf("+------------+------------+------------+----------+------------------------------+------------------+-----------------+-----------+\n");
				}
			}
			if (recordDisplay == 0)
				printf("No reocrds found.\n");//End display records
		}break;
		case 2: {
			do {
				venueChar = 0;//Assign to 0
				venueDigit = 0;//Assign to 0
				printf("Enter Venue ID(eg. ABC123):"); rewind(stdin);//Prompt and read Venue ID
				scanf("%s", &tmpS.venue.venueID);

				//Check for venue character
				for (int i = 0; i < 3; i++) {
					if (isalpha(tmpS.venue.venueID[i]) == 0) {
						printf("\nFirst 3 letters of a venue ID must be alphabet.\n");
						venueChar++;
						break;
					}
				}
				//Check for venue digit
				for (int j = 4; j < 6; j++) {
					if (isdigit(tmpS.venue.venueID[j]) == 0) {
						printf("Last 3 letters of venue ID must be a digit\n");
						venueDigit++;
						break;
					}
				}
				//Convert venue character
				for (int v = 0; v < 6; v++) {
					tmpS.venue.venueID[v] = toupper(tmpS.venue.venueID[v]);
				}
				//Check venue from file
				for (int u = 0; u < numberOfRecords; u++) {
					if (strcmp(tmpS.venue.venueID, sanitization[u].venue.venueID) == 0) {
						exist = 1;
					}
				}
				if (exist == 0) {
					printf("Venue ID Not Existing!\n");
				}
			} while (strlen(tmpS.venue.venueID) > 8 || venueChar != 0 || venueDigit != 0 || exist == 0);//End loop for Venue ID validation
			//Display title
			printf("+------------+------------+------------+----------+------------------------------+------------------+-----------------+-----------+\n");
			printf("|%8s%5s%11s%2s%10s%3s%9s%2s%21s%10s%17s%2s%16s%2s%10s%2s\n", "Date", "|", "Start Time", "|", "End Time", "|", "Venue ID", "|", "Company Name", "|", "Number Of Worker", "|", "Company Contact", "|", "Price(RM)", "|");
			printf("+------------+------------+------------+----------+------------------------------+------------------+-----------------+-----------+\n");
			//Loop to display records
			for (int i = 0; i < numberOfRecords; i++)
			{
				if (strcmp(sanitization[i].venue.venueID, tmpS.venue.venueID) == 0)
				{
					recordDisplay++;//Count record Displayed
					printf("| %02d-%02d-%d |   %02d:%02d    |   %02d:%02d    | %-8s | %-28s | %9d%9s%14s%4s%9.2f%3s\n", sanitization[i].date.day, sanitization[i].date.month, sanitization[i].date.year, sanitization[i].time.startTime.hour, sanitization[i].time.startTime.minute, sanitization[i].time.endTime.hour, sanitization[i].time.endTime.minute, sanitization[i].venue.venueID, sanitization[i].sanitizer.companyName, sanitization[i].sanitizer.numberOfWorkers, "|", sanitization[i].sanitizer.companyContact, "|", sanitization[i].sanitizer.price, "|");
					printf("+------------+------------+------------+----------+------------------------------+------------------+-----------------+-----------+\n");

				}
			}
			if (recordDisplay == 0)
				printf("No reocrds found.\n");//End display records
		}break;
		case 3: {
			printf("Enter Company Name > "); rewind(stdin);//Prompt and read Company Name
			scanf("%[^\n]", &tmpS.sanitizer.companyName);
			//Display title
			printf("+------------+------------+------------+----------+------------------------------+------------------+-----------------+-----------+\n");
			printf("|%8s%5s%11s%2s%10s%3s%9s%2s%21s%10s%17s%2s%16s%2s%10s%2s\n", "Date", "|", "Start Time", "|", "End Time", "|", "Venue ID", "|", "Company Name", "|", "Number Of Worker", "|", "Company Contact", "|", "Price(RM)", "|");
			printf("+------------+------------+------------+----------+------------------------------+------------------+-----------------+-----------+\n");
			//Loop to display records
			for (int i = 0; i < numberOfRecords; i++)
			{
				if (strcmp(sanitization[i].sanitizer.companyName, tmpS.sanitizer.companyName) == 0)
				{
					recordDisplay++;//Count record Displayed
					printf("| %02d-%02d-%d |   %02d:%02d    |   %02d:%02d    | %-8s | %-28s | %9d%9s%14s%4s%9.2f%3s\n", sanitization[i].date.day, sanitization[i].date.month, sanitization[i].date.year, sanitization[i].time.startTime.hour, sanitization[i].time.startTime.minute, sanitization[i].time.endTime.hour, sanitization[i].time.endTime.minute, sanitization[i].venue.venueID, sanitization[i].sanitizer.companyName, sanitization[i].sanitizer.numberOfWorkers, "|", sanitization[i].sanitizer.companyContact, "|", sanitization[i].sanitizer.price, "|");
					printf("+------------+------------+------------+----------+------------------------------+------------------+-----------------+-----------+\n");
				}
			}
			if (recordDisplay == 0)
				printf("No reocrds found.\n");//End display records
		}break;
		}
		do {
			printf("Proceed to search other data? (Y = Yes | N = No)"); rewind(stdin);//Prompt and read proceed
			scanf("%c", &proceed);
			proceed = toupper(proceed);
			if (proceed != 'Y' && proceed != 'N') {
				printf("Invalid choice.Please try again.\n");
			}
		} while (proceed != 'Y' && proceed != 'N');
	} while (proceed == 'Y');//End loop to exit
	fclose(fptr);//Close file
}

int searchMenuSani()//Search Menu for Sanitization Records
{
	int selection;//Selection from user
	char validator;
	do
	{
		system("cls");//Clear screen
		//Display menu of Search Menu for searchSanitization module in Sanitization Records
		printf("++===========================================++\n");
		printf("||%-8s%-35s||\n", " ", "SEARCH SANITIZATION RECORDS");
		printf("++%-43s++\n", "-------------------------------------------");
		printf("|| %-42s||\n|| %-42s||\n|| %-42s||\n|| %-42s||\n", "1. DATE", "2. VENUE ID", "3. COMPANY NAME", "[-1 TO CANCEL]");
		printf("++===========================================++\n");
		printf("Enter number of section to search > "); rewind(stdin);//Prompt and read selection
		scanf("%d%c", &selection, &validator);
		if (selection == -1) {
			return -1;
		}
		if (selection < 1 || selection > 4 || validator != '\n')
		{
			printf("Please choose a number within the range given.\n");
		}//End search menu validation
	} while (selection < 1 || selection > 4 || validator != '\n');//End loop to exit
	return selection;//Return
}

void modifySanitization()//Modify module in Sanitization Records
{
	Sanitization sanitization[100];//Declara variable sanitization for 100 in struct Sanitization
	Sanitization tmpS;//Declara variable tmpS for struct Sanitization for temporarily purpose
	int numberOfRecords = 0;//number of records contains in the file
	char connector[4];//Connector for Date and IC
	int dayMax;//Maximum day in a month
	int recordDisplay = 0;//Record displayed
	int selection;//Selection from user
	int venueChar = 0;//Venue's character
	int venueDigit = 0;//Venue's digit
	int exist;//Venue existing in file
	char modify;//Comfirmation to modify
	char commit;//commit to save into file
	char proceed;//Proceed to loop
	int number[100] = { 0 };//To display number of records
	int noEnter;//Number of records enter by user
	int modifyCount = 0;//Count number of records modified
	char validator;//To validate
	FILE* fptr1;//Declara file pointer
	FILE* fptr;//Declara file pointer
	fptr = fopen("SanitizationModule.txt", "r");//Open file to read
	if (fptr == NULL)//Check if file exist
	{
		printf("Error");
		exit(-1);//Exit program
	}

	//Read from file
	while (fscanf(fptr, "%d-%d-%d|%d:%d|%d:%d|%[^\|]|%[^\|]|%d|%[^\|]|%f\n", &sanitization[numberOfRecords].date.day, &sanitization[numberOfRecords].date.month, &sanitization[numberOfRecords].date.year, &sanitization[numberOfRecords].time.startTime.hour, &sanitization[numberOfRecords].time.startTime.minute, &sanitization[numberOfRecords].time.endTime.hour, &sanitization[numberOfRecords].time.endTime.minute, &sanitization[numberOfRecords].venue.venueID, &sanitization[numberOfRecords].sanitizer.companyName, &sanitization[numberOfRecords].sanitizer.numberOfWorkers, &sanitization[numberOfRecords].sanitizer.companyContact, &sanitization[numberOfRecords].sanitizer.price) != EOF)
	{
		numberOfRecords++;//To count number of records
	}

	do
	{
		system("cls");//Clear screen
		do
		{
			tmpS.date.day = 0;//Assign to 0
			tmpS.date.month = 0;//Assign to 0
			tmpS.date.year = 0;//Assign to 0
			printf("Enter Date (DD-MM-YYYY) : "); rewind(stdin);//Prompt and ead Date
			scanf("%d%c%d%c%d", &tmpS.date.day, &connector[0], &tmpS.date.month, &connector[1], &tmpS.date.year);
			switch (tmpS.date.month)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12: dayMax = 31; break;
			case 2: if (tmpS.date.year % 4 == 0)
				dayMax = 29;
				  else
				dayMax = 28;
				break;
			default:
				dayMax = 30;
			}//End switch
			if (connector[0] != '-' || connector[1] != '-')
				printf("Please follow the format shown.\a\n");
			if (tmpS.date.month < 1 || tmpS.date.month > 12 || tmpS.date.day < 1 || tmpS.date.day > dayMax)
				printf("Invalid date.\a\n");//End for Date validation
		} while (tmpS.date.month < 1 || tmpS.date.month > 12 || tmpS.date.day < 1 || tmpS.date.day > dayMax || connector[0] != '-' || connector[1] != '-');//End loop for Date validation
		//Display title
		printf("+-----+------------+------------+------------+----------+------------------------------+------------------+-----------------+-----------+\n");
		printf("|%4s%2s%8s%5s%11s%2s%10s%3s%9s%2s%21s%10s%17s%2s%16s%2s%10s%2s\n", "No.", "|", "Date", "|", "Start Time", "|", "End Time", "|", "Venue ID", "|", "Company Name", "|", "Number Of Worker", "|", "Company Contact", "|", "Price(RM)", "|");
		printf("+-----+------------+------------+------------+----------+------------------------------+------------------+-----------------+-----------+\n");
		recordDisplay = 0;//Assign to 0
		//Loop to display records
		for (int i = 0; i < numberOfRecords; i++)
		{
			if (sanitization[i].date.day == tmpS.date.day && sanitization[i].date.month == tmpS.date.month && sanitization[i].date.year == tmpS.date.year)
			{
				recordDisplay++;//Count record Displayed
				number[i] = recordDisplay;//Assign recordDisplay to number
				printf("| %03d | %02d-%02d-%d |   %02d:%02d    |   %02d:%02d    | %-8s | %-28s | %9d%9s%14s%4s%9.2f%3s\n", number[i], sanitization[i].date.day, sanitization[i].date.month, sanitization[i].date.year, sanitization[i].time.startTime.hour, sanitization[i].time.startTime.minute, sanitization[i].time.endTime.hour, sanitization[i].time.endTime.minute, sanitization[i].venue.venueID, sanitization[i].sanitizer.companyName, sanitization[i].sanitizer.numberOfWorkers, "|", sanitization[i].sanitizer.companyContact, "|", sanitization[i].sanitizer.price, "|");
				printf("+-----+------------+------------+------------+----------+------------------------------+------------------+-----------------+-----------+\n");

			}
		}
		if (recordDisplay == 0)
			printf("No records found.\n");//End display records
		else
		{
			do {
				printf("Want to modify? (Y = Yes | N = No)"); rewind(stdin);//Prompt and read modify
				scanf("%c", &modify);
				modify = toupper(modify);
				if (modify != 'Y' && modify != 'N') {
					printf("Please choose a number within the range given.\n");
				}
			} while (modify != 'Y' && modify != 'N');
			if (modify == 'Y')//if yes
			{
				do
				{
					noEnter = 0;
					printf("Enter No > "); rewind(stdin);//Prompt and read noEnter
					scanf("%d%c", &noEnter, &validator);
				} while (noEnter < 1 || noEnter > recordDisplay || validator != '\n');//End loop for noEnter Validation
				//Loop to check same Date
				for (int i = 0; i < numberOfRecords; i++)
				{
					//If Date same
					if (sanitization[i].date.day == tmpS.date.day && sanitization[i].date.month == tmpS.date.month && sanitization[i].date.year == tmpS.date.year && noEnter == number[i])
					{
						selection = modifyMenuSani();//Call function and assign data into selection
						if (selection == -1) {
							break;
						}
						switch (selection)
						{
						case 1: {
							do
							{
								printf("Enter Date (DD-MM-YYYY) > "); rewind(stdin);//Prompt and ead Date
								scanf("%d%c%d%c%d", &sanitization[i].date.day, &connector[0], &sanitization[i].date.month, &connector[1], &sanitization[i].date.year);
								switch (sanitization[i].date.month)
								{
								case 1:
								case 3:
								case 5:
								case 7:
								case 8:
								case 10:
								case 12: dayMax = 31; break;
								case 2: if (sanitization[i].date.year % 4 == 0)
									dayMax = 29;
									  else
									dayMax = 28;
									break;
								default:
									dayMax = 30;
								}//End switch
								if (connector[0] != '-' || connector[1] != '-')
									printf("Please follow the format shown.\a\n");
								if (sanitization[i].date.month < 1 || sanitization[i].date.month > 12 || sanitization[i].date.day < 1 || sanitization[i].date.day > dayMax)
									printf("Invalid date.\a\n");//End for Date validation
							} while (sanitization[i].date.month < 1 || sanitization[i].date.month > 12 || sanitization[i].date.day < 1 || sanitization[i].date.day > dayMax || connector[0] != '-' || connector[1] != '-');//End loop for Date validation
						}break;
						case 2: {
							do
							{
								printf("Enter Start Time (HH:MM) in 24-hour clock > "); rewind(stdin);//Prompt and read Start Time
								scanf("%d%c%d", &sanitization[i].time.startTime.hour, &connector[2], &sanitization[i].time.startTime.minute);
								if (connector[2] != ':')
									printf("Please follow the format shown.\a\n");
								if (sanitization[i].time.startTime.hour < 0 || sanitization[i].time.startTime.hour > 23 || sanitization[i].time.startTime.minute < 0 || sanitization[i].time.startTime.minute > 59)
									printf("Invalid time.\a\n");//End for start time validation
							} while (sanitization[i].time.startTime.hour < 0 || sanitization[i].time.startTime.hour > 23 || sanitization[i].time.startTime.minute < 0 || sanitization[i].time.startTime.minute > 59 || connector[2] != ':');//End loop for Start Time validation
						}break;
						case 3: {
							do
							{
								printf("Enter End Time (HH:MM) in 24-hour clock > "); rewind(stdin);//Prompt and read End time
								scanf("%d%c%d", &sanitization[i].time.endTime.hour, &connector[3], &sanitization[i].time.endTime.minute);
								if (connector[3] != ':')
									printf("Please follow the format shown.\a\n");
								if (sanitization[i].time.endTime.hour < 0 || sanitization[i].time.endTime.hour > 23 || sanitization[i].time.endTime.minute < 0 || sanitization[i].time.endTime.minute > 59)
									printf("Invalid time.\a\n");
								if (sanitization[i].time.startTime.hour > sanitization[i].time.endTime.hour)
									printf("End Time must be after Start Time.\n\a");
								if (sanitization[i].time.startTime.hour == sanitization[i].time.endTime.hour)
									if (sanitization[i].time.startTime.minute > sanitization[i].time.endTime.minute)
										printf("End Time must be after Start Time.\n\a");//End for End Time validation
							} while (sanitization[i].time.endTime.hour < 0 || sanitization[i].time.endTime.hour > 23 || sanitization[i].time.endTime.minute < 0 || sanitization[i].time.endTime.minute > 59 || connector[3] != ':' || sanitization[i].time.startTime.hour > sanitization[i].time.endTime.hour || (sanitization[i].time.startTime.hour == sanitization[i].time.endTime.hour && sanitization[i].time.startTime.minute > sanitization[i].time.endTime.minute));//End loop for End Time validation
						}break;
						case 4: {
							do {
								venueChar = 0;//Assign to 0
								venueDigit = 0;//Assign to 0
								printf("Enter Venue ID(eg. ABC123):"); rewind(stdin);//Prompt and read Venue ID
								scanf("%s", &sanitization[i].venue.venueID);

								//Check for venue character
								for (int i = 0; i < 3; i++) {
									if (isalpha(sanitization[i].venue.venueID[i]) == 0) {
										printf("\nFirst 3 letters of a venue ID must be alphabet.\n");
										venueChar++;
										break;
									}
								}
								//Check for venue digit
								for (int j = 4; j < 6; j++) {
									if (isdigit(sanitization[i].venue.venueID[j]) == 0) {
										printf("Last 3 letters of venue ID must be a digit\n");
										venueDigit++;
										break;
									}
								}
								//Convert venue character
								for (int v = 0; v < 6; v++) {
									sanitization[i].venue.venueID[v] = toupper(sanitization[i].venue.venueID[v]);
								}
								//Check venue from file
								for (int u = 0; u < numberOfRecords; u++) {
									if (strcmp(sanitization[i].venue.venueID, sanitization[u].venue.venueID) == 0) {
										exist = 1;
									}
								}
								if (exist == 0) {
									printf("Venue ID Not Existing!\n");
								}
							} while (strlen(sanitization[i].venue.venueID) > 8 || venueChar != 0 || venueDigit != 0 || exist == 0);//End loop for Venue ID validation
						}break;
						case 5: {
							printf("Enter Company Name > "); rewind(stdin);//Prompt and read Company Name
							scanf("%[^\n]", &sanitization[i].sanitizer.companyName);
						}break;
						case 6: {
							do
							{
								printf("Enter number of workers > ");  rewind(stdin);//Prompt and read number of workers from company
								scanf("%d%c", &sanitization[i].sanitizer.numberOfWorkers, &validator);
								if (sanitization[i].sanitizer.numberOfWorkers < 1 || validator != '\n')
									printf("Invalid input.\n");//End for number of workers validation
							} while (sanitization[i].sanitizer.numberOfWorkers < 1 || validator != '\n');//End loop for number of workers validation
						}break;
						case 7: {
							do
							{
								printf("Enter Company Contact Number (012-3456789) > "); rewind(stdin);//Prompt and read Company Contact Number
								scanf("%s", &sanitization[i].sanitizer.companyContact);
								if (isdigit(sanitization[i].sanitizer.companyContact[0]) == 0 || isdigit(sanitization[i].sanitizer.companyContact[1]) == 0 || isdigit(sanitization[i].sanitizer.companyContact[2]) == 0 || isdigit(sanitization[i].sanitizer.companyContact[4]) == 0 || isdigit(sanitization[i].sanitizer.companyContact[5]) == 0 || isdigit(sanitization[i].sanitizer.companyContact[6]) == 0 || isdigit(sanitization[i].sanitizer.companyContact[7]) == 0 || isdigit(sanitization[i].sanitizer.companyContact[8]) == 0 || isdigit(sanitization[i].sanitizer.companyContact[9]) == 0 || isdigit(sanitization[i].sanitizer.companyContact[10]) == 0)
									printf("Please ensure input is numeric\a\n");
								else if (sanitization[i].sanitizer.companyContact[3] != '-' || strlen(sanitization[i].sanitizer.companyContact) < 11 || strlen(sanitization[i].sanitizer.companyContact) > 13)
									printf("Please follow the format.\a\n");//End for Company Contact Number validation
							} while (isdigit(sanitization[i].sanitizer.companyContact[0]) == 0 || isdigit(sanitization[i].sanitizer.companyContact[1]) == 0 || isdigit(sanitization[i].sanitizer.companyContact[2]) == 0 || isdigit(sanitization[i].sanitizer.companyContact[4]) == 0 || isdigit(sanitization[i].sanitizer.companyContact[5]) == 0 || isdigit(sanitization[i].sanitizer.companyContact[6]) == 0 || isdigit(sanitization[i].sanitizer.companyContact[7]) == 0 || isdigit(sanitization[i].sanitizer.companyContact[8]) == 0 || isdigit(sanitization[i].sanitizer.companyContact[9]) == 0 || isdigit(sanitization[i].sanitizer.companyContact[10]) == 0 || sanitization[i].sanitizer.companyContact[3] != '-' || strlen(sanitization[i].sanitizer.companyContact) < 11 || strlen(sanitization[i].sanitizer.companyContact) > 13);//End loop for Company Contact Number validation
						}break;
						case 8: {
							do
							{
								printf("Enter price > "); rewind(stdin);//Prompt and read Price
								scanf("%f%c", &sanitization[i].sanitizer.price, &validator);
								if (sanitization[i].sanitizer.numberOfWorkers <= 0 || validator != '\n')
									printf("Invalid input.\n");//End for Price validation
							} while (sanitization[i].sanitizer.price <= 0 || validator != '\n');//End loop for Price validation
						}break;
						case 9: {
							sanitizationInput(&sanitization[i]);//Call function to modify all
						}break;
						}
						printf("Comfirm to commit (Y = yes) ? "); rewind(stdin);//Prompt and read commit
						scanf("%c", &commit);
						commit = toupper(commit);
						if (commit == 'Y')//if yes
						{
							modifyCount++;
							fptr1 = fopen("SanitizationModule.txt", "w");//Open file to write
							for (int j = 0; j < numberOfRecords; j++)
							{
								//Write into file
								fprintf(fptr1, "%02d-%02d-%d|%02d:%02d|%02d:%02d|%s|%s|%d|%s|%.2f\n", sanitization[j].date.day, sanitization[j].date.month, sanitization[j].date.year, sanitization[j].time.startTime.hour, sanitization[j].time.startTime.minute, sanitization[j].time.endTime.hour, sanitization[j].time.endTime.minute, sanitization[j].venue.venueID, sanitization[j].sanitizer.companyName, sanitization[j].sanitizer.numberOfWorkers, sanitization[j].sanitizer.companyContact, sanitization[j].sanitizer.price);
							}
							fclose(fptr1);//Close file
						}

					}
				}
			}
		}
		do {
			printf("Proceed to modify other data? (Y = Yes | N = No)"); rewind(stdin);//Prompt and read proceed
			scanf("%c", &proceed);
			proceed = toupper(proceed);
			if (proceed != 'Y' && proceed != 'N') {
				printf("Please choose a number within the range given.\n");
			}
		} while (proceed != 'Y' && proceed != 'N');
	} while (proceed == 'Y');//End loop to exit

	fclose(fptr);//Close file
	printf("%d Record(s) Updated!\n", modifyCount);
}

int modifyMenuSani()//Modify Menu for Sanitization Records
{
	int selection;//Selection from user
	char validator;//To validate
	do
	{
		//Display menu of Search Menu for searchSanitization module in Sanitization Records
		printf("++===========================================++\n");
		printf("||%-8s%-35s||\n", " ", "MODIFY SANITIZATION RECORDS");
		printf("++%-43s++\n", "-------------------------------------------");
		printf("|| %-42s||\n|| %-42s||\n|| %-42s||\n|| %-42s||\n|| %-42s||\n|| %-42s||\n|| %-42s||\n|| %-42s||\n|| %-42s||\n|| %-42s||\n", "1. DATE", "2. START TIME", "3. END TIME", "4. VENUE ID", "5. COMPANY NAME", "6. NUMBER OF WORKER", "7. COMPANY CONTACT NUMBER", "8. PRICE", "9. ALL", "[-1 TO CANCEL]");
		printf("++===========================================++\n");
		printf("Enter number of section to search > "); rewind(stdin);//Prompt and read selection
		scanf("%d%c", &selection, &validator);
		if (selection == -1) {
			return -1;
		}
		if (selection < 1 || selection > 9 || validator != '\n')
		{
			printf("Please choose a number within the range given.\n");
		}//End search menu validation
	} while (selection < 1 || selection > 9 || validator != '\n');//End loop to exit
	return selection;//Return
}

void deleteSanitization()//Delete module in Sanitization Records
{
	Sanitization sanitization[100];//Declara variable sanitization for 100 in struct Sanitization
	Sanitization input;//Declara variable input in struct Sanitization
	int numberOfRecords = 0;//number of records contains in the file
	char connector[4];//Connector for Date and IC
	int dayMax;//Maximum day in a month
	int recordDisplay = 0;//Record displayed
	int deleteCount = 0;//Count number of records deleted
	int number[100] = { 0 };//To display number of records
	int noEnter;//Number of records enter by user
	char reply;//Confirmation to delete
	char validator;//To validate
	FILE* fptr1;//Declara file pointer
	FILE* fptr;//Declara file pointer
	fptr = fopen("SanitizationModule.txt", "r");//Open file to read
	if (fptr == NULL)//Check if file exist
	{
		printf("Error");
		exit(-1);//Exit program
	}

	//Read from file
	while (fscanf(fptr, "%d-%d-%d|%d:%d|%d:%d|%[^\|]|%[^\|]|%d|%[^\|]|%f\n", &sanitization[numberOfRecords].date.day, &sanitization[numberOfRecords].date.month, &sanitization[numberOfRecords].date.year, &sanitization[numberOfRecords].time.startTime.hour, &sanitization[numberOfRecords].time.startTime.minute, &sanitization[numberOfRecords].time.endTime.hour, &sanitization[numberOfRecords].time.endTime.minute, &sanitization[numberOfRecords].venue.venueID, &sanitization[numberOfRecords].sanitizer.companyName, &sanitization[numberOfRecords].sanitizer.numberOfWorkers, &sanitization[numberOfRecords].sanitizer.companyContact, &sanitization[numberOfRecords].sanitizer.price) != EOF)
	{
		numberOfRecords++;//To count number of records
	}
	fclose(fptr);//Close file

	do
	{
		system("cls");//Clear screen
		recordDisplay = 0;
		do
		{
			input.date.day = 0;//Assign to 0
			input.date.month = 0;//Assign to 0
			input.date.year = 0;//Assign to 0
			printf("Enter Date (DD-MM-YYYY) : "); rewind(stdin);//Prompt and ead Date
			scanf("%d%c%d%c%d", &input.date.day, &connector[0], &input.date.month, &connector[1], &input.date.year);
			switch (input.date.month)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12: dayMax = 31; break;
			case 2: if (input.date.year % 4 == 0)
				dayMax = 29;
				  else
				dayMax = 28;
				break;
			default:
				dayMax = 30;
			}//End switch
			if (connector[0] != '-' || connector[1] != '-')
				printf("Please follow the format shown.\a\n");
			if (input.date.month < 1 || input.date.month > 12 || input.date.day < 1 || input.date.day > dayMax)
				printf("Invalid date.\a\n");//End for Date validation
		} while (input.date.month < 1 || input.date.month > 12 || input.date.day < 1 || input.date.day > dayMax || connector[0] != '-' || connector[1] != '-');//End loop for Date validation
		//Display title
		printf("+-----+------------+------------+------------+----------+------------------------------+------------------+-----------------+-----------+\n");
		printf("|%4s%2s%8s%5s%11s%2s%10s%3s%9s%2s%21s%10s%17s%2s%16s%2s%10s%2s\n", "No.", "|", "Date", "|", "Start Time", "|", "End Time", "|", "Venue ID", "|", "Company Name", "|", "Number Of Worker", "|", "Company Contact", "|", "Price(RM)", "|");
		printf("+-----+------------+------------+------------+----------+------------------------------+------------------+-----------------+-----------+\n");
		//Loop to display records
		for (int i = 0; i < numberOfRecords; i++)
		{
			if (sanitization[i].date.day == input.date.day && sanitization[i].date.month == input.date.month && sanitization[i].date.year == input.date.year)
			{
				recordDisplay++;//Count record Displayed
				number[i] = recordDisplay;//Assign recordDisplay to number
				printf("| %03d | %02d-%02d-%d |   %02d:%02d    |   %02d:%02d    | %-8s | %-28s | %9d%9s%14s%4s%9.2f%3s\n", number[i], sanitization[i].date.day, sanitization[i].date.month, sanitization[i].date.year, sanitization[i].time.startTime.hour, sanitization[i].time.startTime.minute, sanitization[i].time.endTime.hour, sanitization[i].time.endTime.minute, sanitization[i].venue.venueID, sanitization[i].sanitizer.companyName, sanitization[i].sanitizer.numberOfWorkers, "|", sanitization[i].sanitizer.companyContact, "|", sanitization[i].sanitizer.price, "|");
				printf("+-----+------------+------------+------------+----------+------------------------------+------------------+-----------------+-----------+\n");

			}
		}
		if (recordDisplay == 0)
			printf("No records found.\n");//End display records
		else
		{
			do
			{
				noEnter = 0;
				printf("Enter No > "); rewind(stdin);//Prompt and read noEnter
				scanf("%d%c", &noEnter, &validator);
			} while (noEnter < 1 || noEnter > recordDisplay || validator != '\n');//End loop for noEnter Validation
			//Loop to check same Date
			for (int i = 0; i < numberOfRecords; i++)
			{
				//If Date same
				if (sanitization[i].date.day == input.date.day && sanitization[i].date.month == input.date.month && sanitization[i].date.year == input.date.year && noEnter == number[i])
				{
					do {
						printf("Sure to delete? (Y = Yes | N = No)"); rewind(stdin);//Prompt and read reply
						scanf("%c", &reply);
						reply = toupper(reply);
					} while (reply != 'Y' && reply != 'N');
					if (reply == 'Y')//If yes
					{
						deleteCount++;//Count delete
						//Loop to move data
						for (int j = i; j < numberOfRecords; j++)
						{
							sanitization[j] = sanitization[j + 1];//Move data from one to another one
						}
					}
				}
			}
		}
		numberOfRecords -= deleteCount;//Update numberOf Records
		fptr1 = fopen("SanitizationModule.txt", "w");//Open file  to write
		for (int u = 0; u < numberOfRecords; u++) {
			//Write into file
			fprintf(fptr1, "%02d-%02d-%d|%02d:%02d|%02d:%02d|%s|%s|%d|%s|%.2f\n", sanitization[u].date.day, sanitization[u].date.month, sanitization[u].date.year, sanitization[u].time.startTime.hour, sanitization[u].time.startTime.minute, sanitization[u].time.endTime.hour, sanitization[u].time.endTime.minute, sanitization[u].venue.venueID, sanitization[u].sanitizer.companyName, sanitization[u].sanitizer.numberOfWorkers, sanitization[u].sanitizer.companyContact, sanitization[u].sanitizer.price);
		}
		fclose(fptr1);//Close file
		do {
			printf("Proceed to delete other data? (Y = Yes | N = No)"); rewind(stdin);//Prompt and read proceed
			scanf("%c", &reply);
			reply = toupper(reply);
			if (reply != 'Y' && reply != 'N') {
				printf("Please choose a number within the range given.\n");
			}
		} while (reply != 'Y' && reply != 'N');
	} while (reply == 'Y');//End loop to exit
	printf("%d Records Deleted!\n", deleteCount);
}

void reportSanitization()//Report module in Sanitization Records
{
	Sanitization sanitization[100];//Declara variable sanitization for 100 in struct Sanitization
	Venue venue[100];//Declara variable venue for 100 in struct Venue
	int numberOfRecords[2] = { 0 };//number of records contains in the file
	int month;//month in number
	int year;//year in number
	char connector;//Connector for Date
	Date lastSani;//last sanitization date
	char venueId[8];//Venue recommended to sanitize
	int number = 0;//number of venue to sanitize
	char monthName[12];//Month by name
	int recordDisplay = 0;//Record displayed
	float totalPrice;//Total price
	char proceed;//Proceed to loop
	FILE* fptr;//Declara file pointer
	FILE* inPtr1;//Declara file pointer
	inPtr1 = fopen("venueModule.txt", "r");//Open file to read
	fptr = fopen("SanitizationModule.txt", "r");//Open file to read
	if (fptr == NULL || inPtr1 == NULL)//Check if file exist
	{
		printf("Error");
		exit(-1);//Exit program
	}

	//Read from file
	while (fscanf(fptr, "%d-%d-%d|%d:%d|%d:%d|%[^\|]|%[^\|]|%d|%[^\|]|%f\n", &sanitization[numberOfRecords[0]].date.day, &sanitization[numberOfRecords[0]].date.month, &sanitization[numberOfRecords[0]].date.year, &sanitization[numberOfRecords[0]].time.startTime.hour, &sanitization[numberOfRecords[0]].time.startTime.minute, &sanitization[numberOfRecords[0]].time.endTime.hour, &sanitization[numberOfRecords[0]].time.endTime.minute, &sanitization[numberOfRecords[0]].venue.venueID, &sanitization[numberOfRecords[0]].sanitizer.companyName, &sanitization[numberOfRecords[0]].sanitizer.numberOfWorkers, &sanitization[numberOfRecords[0]].sanitizer.companyContact, &sanitization[numberOfRecords[0]].sanitizer.price) != EOF)
	{
		numberOfRecords[0]++;//To count number of records in sanitization file
	}
	while (fscanf(inPtr1, "%[^\|]|%[^\|]|%[^\|]|%d|%d|%d-%d-%d|%d:%d|%d:%d\n", &venue[numberOfRecords[1]].venueID, &venue[numberOfRecords[1]].category, &venue[numberOfRecords[1]].description, &venue[numberOfRecords[1]].maxVisitor, &venue[numberOfRecords[1]].currentVisitor, &venue[numberOfRecords[1]].dateSani.day, &venue[numberOfRecords[1]].dateSani.month, &venue[numberOfRecords[1]].dateSani.year, &venue[numberOfRecords[1]].open.hour, &venue[numberOfRecords[1]].open.minute, &venue[numberOfRecords[1]].close.hour, &venue[numberOfRecords[1]].close.minute) != EOF)
	{
		numberOfRecords[1]++;//To count number of records in venue file
	}

	do
	{
		system("cls");//Clear screen
		do {
			recordDisplay = 0;//Assign to 0 to reset
			totalPrice = 0;//Assign to 0 to reset
			printf("Enter Month & Year to Search (MM-YYYY):"); rewind(stdin);
			scanf("%d%c%d", &month, &connector, &year);
			switch (month)//Assign month name
			{
			case 1:
				strcpy(monthName, "January"); break;
			case 2:
				strcpy(monthName, "Febuary"); break;
			case 3:
				strcpy(monthName, "March"); break;
			case 4:
				strcpy(monthName, "April"); break;
			case 5:
				strcpy(monthName, "May"); break;
			case 6:
				strcpy(monthName, "June"); break;
			case 7:
				strcpy(monthName, "July"); break;
			case 8:
				strcpy(monthName, "August"); break;
			case 9:
				strcpy(monthName, "September"); break;
			case 10:
				strcpy(monthName, "October"); break;
			case 11:
				strcpy(monthName, "November"); break;
			case 12:
				strcpy(monthName, "December"); break;
			default:
				printf("Invalid Month's range\n");
			}//End switch
		} while (month < 1 || month > 12 || connector != '-');//End loop for month validation	
		//Display title
		printf("\nReport on %s %d\n", monthName, year);
		printf("_________\n");
		printf("+----------+---------------+------------------------------+-----------+----------------+\n");
		printf("|%9s%2s%14s%2s%21s%10s%10s%2s%15s%2s\n", "Venue ID", "|", "Venue Category", "|", "Company Name", "|", "Price(RM)", "|", "Last sanitized", "|");
		printf("+----------+---------------+------------------------------+-----------+----------------+\n");
		//Loop to display records
		for (int i = 0; i < numberOfRecords[0]; i++)
		{
			for (int j = 0; j < numberOfRecords[1]; j++)
			{
				if (month == sanitization[i].date.month && year == sanitization[i].date.year)
				{
					if (strcmp(venue[j].venueID, sanitization[i].venue.venueID) == 0)
					{
						recordDisplay++;//Count record Displayed
						totalPrice += sanitization[i].sanitizer.price;//Count total price
						printf("| %-8s | %-13s | %-28s |%9.2f%3s   %02d-%02d-%d   |\n", sanitization[i].venue.venueID, venue[j].category, sanitization[i].sanitizer.companyName,
							sanitization[i].sanitizer.price, "|", sanitization[i].date.day, sanitization[i].date.month, sanitization[i].date.year);
						printf("+----------+---------------+------------------------------+-----------+----------------+\n");
					}
				}
			}
		}
		if (recordDisplay == 0)
			printf("No records found.\n");//End display records
		else {
			printf("\nSummary\n");
			printf("____\n");
			printf("+--------------------------------------------------------------------------------------+\n");
			printf("| %02d records found. %68s\n", recordDisplay, "|");//End display records
			printf("| Total price spent : RM%.2f %56s\n", totalPrice, "|");//Display total price
			printf("| Next suggested venue to be sanitize : %48s\n", "|");
			lastSani.day = sanitization[0].date.day;//Assign to first value of data
			lastSani.month = sanitization[0].date.month;//Assign to first value of data
			lastSani.year = sanitization[0].date.year;//Assign to first value of data
			//Loop to display venue to be sanitize next
			for (int u = 0; u < recordDisplay; u++)
			{
				if (sanitization[u].date.year <= lastSani.year)//Check year
				{
					lastSani.year = sanitization[u].date.year;
					if (sanitization[u].date.month <= lastSani.month)//Check month
					{
						lastSani.month = sanitization[u].date.month;
						if (sanitization[u].date.day <= lastSani.day)//Check day
						{
							lastSani.day = sanitization[u].date.day;
							strcpy(venueId, sanitization[u].venue.venueID);//Assign venue
							number++;//Count number of venue displayed
							printf("| %d. %s %76s\n", number, venueId, "|");
						}
					}
				}
			}
			printf("+--------------------------------------------------------------------------------------+\n\n");
		}

		printf("Proceed to display other report (Y = yes) ? "); rewind(stdin);//Prompt and read proceed
		scanf("%c", &proceed);
		proceed = toupper(proceed);
	} while (proceed == 'Y');//End loop to exit
	fclose(fptr);//Close file
	fclose(inPtr1);//Close file
}

int visitExitMenu() {
	int choice;
	char reply;
	char validator;
	char stay = 0;

	do {
		do {
			choice = 0;
			system("cls");
			heading();
			printf("\n");
			printf("%20s================================\n", "");
			printf("%20s||     %20s   ||\n", "", "Visit and Exit Menu");
			printf("%20s||----------------------------||\n", "");
			printf("%20s||      %-22s||\n%20s||      %-22s||\n%20s||      %-22s||\n%20s||      %-22s||\n%20s||      %-22s||\n%20s||      %-22s||\n%20s||      %-22s||\n", "", "1.Display Record", "", "2.Search Record", "", "3.Add Record", "", "4.Modify Record", "", "5.Delete Record", "", "6.Generate Report", "", "7.Back to Main Menu");
			printf("%20s================================\n", "");
			printf("----Please enter your selection : "); rewind(stdin);
			scanf("%d%c", &choice, &validator);
			switch (choice)
			{
			case 1:
				displayVisitExit(); break;
			case 2:
				searchVisitExit(); break;
			case 3:
				addVisitExit(); break;
			case 4:
				stay = modifyVisitExit(); break;
			case 5:
				deleteVisitExit(); break;
			case 6:
				reportVisitExit(); break;
			case 7:
				return 1;
			default:
			{
				printf("Invalid Choice!\n"); rewind(stdin);
				getchar();
			}
			if (stay == 1) {
				continue;
			}
			}
			if (validator != '\n') {
				printf("Only numeric input is acceptable!\n");
			}
		} while (choice < 1 || choice > 7 || validator != '\n');

		do {
			printf("\n\nReturn to Visit & Exit menu ? (Y = Yes | N = No)"); rewind(stdin);
			scanf("%c", &reply);
			reply = toupper(reply);
			if (reply != 'Y' && reply != 'N') {
				printf("Invalid choice. Please try again.\n");
			}
		} while (reply != 'Y' && reply != 'N');
	} while (reply == 'Y');
}

void addVisitExit() {

	VisitExit visitExit;                              //Declare a variable using Visitor structure type
	VisitorInfo tempInfo[100];                    //Uses to hold data for updating visitor info
	Venue validate[100];
	int choice;
	int idFound = 0;
	int vCount = 0;                               //Store number of records added
	char reply;                                   //Uses to store decision from user
	char validator;                               //Uses to validate and avoid user enter aplhabets into integer placeholder and etc
	int maxDay;                                   //Uses to store maximum days of a specific month
	int action;                                   //To determine cancel adding function or not
	FILE* outPtr;                                 //File pointer to output record into file
	outPtr = fopen("visit&exit.txt", "a");        //Open file for appending text
	FILE* fptr1;
	fptr1 = fopen("visitorInfo.dat", "rb");

	FILE* fptr2;
	fptr2 = fopen("venueModule.txt", "r");  //To input records from Venue module for checking existence of venue

	while (fscanf(fptr2, "%[^\|]|%[^\|]|%[^\|]|%d|%d|%d-%d-%d|%d:%d|%d:%d\n", &validate[idFound].venueID, &validate[idFound].category, &validate[idFound].description, &validate[idFound].maxVisitor, &validate[idFound].currentVisitor, &validate[idFound].dateSani.day, &validate[idFound].dateSani.month, &validate[idFound].dateSani.year, &validate[idFound].open.hour, &validate[idFound].open.minute, &validate[idFound].close.hour, &validate[idFound].close.minute) != EOF) {
		idFound++;
	}

	if (fptr1 == NULL || fptr2 == NULL) {
		printf("Error\n");
		exit(-1);
	}
	int infoCount = 0;
	while (fread(&tempInfo[infoCount], sizeof(VisitorInfo), 1, fptr1) != 0) {//read the data inside the file
		infoCount++;
	}

	fclose(fptr1);
	fclose(fptr2);


	//Loop use to continuous adding purpose
	do {
		system("cls");
		//Function's label
		printf("+-------------------+\n");
		printf("|     ADD RECORD    |\n");
		printf("+-------------------+\n");
		do {
			system("cls");
			printf("++===========================================++\n");
			printf("||%-8s%-35s||\n", " ", "ADD VISIT & EXIT RECORDS");
			printf("++%-43s++\n", "-------------------------------------------");
			printf("|| %-42s||\n|| %-42s||\n|| %-42s||\n", "1. Visiting", "2. Exiting", "[-1 To Cancel]");
			printf("++===========================================++\n");
			printf("\nEnter Selection:"); rewind(stdin);
			scanf("%d%c", &choice, &validator);
			if (choice == -1) {
				break;
			}
			if (choice < 1 || choice > 2 || validator != '\n') {
				//Prompt invalid input
				printf("Invalid Choice\n");
				printf("Please choose the numeric within the range shown!\n"); rewind(stdin);
				getchar();
			}
		} while (choice < 1 || choice > 2 || validator != '\n');
		if (choice == -1) {
			break;
		}
		if (choice == 1) {
			action = inputVisit(&visitExit);

			if (action == 1) {
				break;
			}
			else if (action == 2) {
				system("cls");
				printf("The visitor has been added! Modification function is available!\n");
				vCount = 1;
				break;
			}
			else {
				printf("Successfully Input!\n\n");
			}

			//Heading for each column of data
			printf("\n%-15s%-15s%-28s%-18s%-13s%-10s%-13s\n", "Date Entered", "Time Entered", "Reason", "Visitor IC No", "Tel-Number", "Venue ID", "Temperature");
			printf("%-15s%-15s%-28s%-18s%-13s%-10s%-13s\n", "=============", "=============", "==========================", "================", "===========", "========", "===========");
			printf("%02d-%02d-%-9d%02d:%-12.02d%-28s%-18s%-13s%-10s%-13.1lf\n", visitExit.dateEnter.day, visitExit.dateEnter.month, visitExit.dateEnter.year, visitExit.timeEnter.hour, visitExit.timeEnter.minute, visitExit.reason, visitExit.visitorIC, visitExit.telNo, visitExit.venueID, visitExit.temperature);
			//Confirmation to add data
			do {
				printf("\nAre you sure to add it?(Y = Yes | N = No)"); rewind(stdin);
				scanf("%c", &reply);
				reply = toupper(reply);
				if (reply != 'Y' && reply != 'N') {
					printf("Invalid choice. Please try again.\n");
				}
			} while (reply != 'Y' && reply != 'N');
			//Append the new data to the text file
			if (reply == 'Y') {
				for (int i = 0; i < idFound; i++) {
					if (strcmp(visitExit.venueID, validate[i].venueID) == 0) {
						validate[i].currentVisitor++;
						if (validate[i].currentVisitor > validate[i].maxVisitor) {
							printf("The maximum number of visitor has been reached!\n");
							break;
						}
						else {
							FILE* outPtr3;
							outPtr3 = fopen("venueModule.txt", "w");
							for (int a = 0; a < idFound; a++) {
								fprintf(outPtr3, "%s|%s|%s|%d|%d|%02d-%02d-%-4d|%02d:%02d|%02d:%02d\n", validate[a].venueID, validate[a].category, validate[a].description, validate[a].maxVisitor, validate[a].currentVisitor, validate[a].dateSani.day, validate[a].dateSani.month, validate[a].dateSani.year, validate[a].open.hour, validate[a].open.minute, validate[a].close.hour, validate[a].close.minute);
							}
							fclose(outPtr3);
							fprintf(outPtr, "%02d-%02d-%-4d|%02d:%02d|%s|%s|%s|%s|%.1lf|%02d:%02d\n", visitExit.dateEnter.day, visitExit.dateEnter.month, visitExit.dateEnter.year, visitExit.timeEnter.hour, visitExit.timeEnter.minute, visitExit.reason, visitExit.visitorIC, visitExit.telNo, visitExit.venueID, visitExit.temperature, visitExit.timeExit.hour, visitExit.timeExit.minute);

							for (int u = 0; u < infoCount; u++) {
								if (strcmp(visitExit.visitorIC, tempInfo[u].IC) == 0) {
									tempInfo[u].date = visitExit.dateEnter;
									strcpy(tempInfo[u].latestVenueVisited, visitExit.venueID);
									strcpy(tempInfo[u].reason, visitExit.reason);
									strcpy(tempInfo[u].contactNo, visitExit.telNo);
									tempInfo[u].temperature = visitExit.temperature;
									tempInfo[u].time = visitExit.timeEnter;
									FILE* outPtr2;
									outPtr2 = fopen("visitorInfo.dat", "wb");

									for (int v = 0; v < infoCount; v++) {
										fwrite(&tempInfo[v], sizeof(VisitorInfo), 1, outPtr2);
									}

									fclose(outPtr2);
									break;
								}
							}
							vCount++;
							fclose(outPtr);
							break;

						}
					}
				}


			}
		}
		else {
			inputExit();
		}
		do {
			//Prompt and read for looping
			printf("\nContinue to Add?(Y = Yes | N = No)"); rewind(stdin);
			scanf("%c", &reply);
			reply = toupper(reply);
			if (reply != 'Y' && reply != 'N') {
				printf("Invalid choice. Please try again.\n");
			}
		} while (reply != 'Y' && reply != 'N');


	} while (reply == 'Y');
}

int inputVisit(VisitExit* tmpVE) {
	int maxDay;                          //Uses to store maximum days of a specific month
	char validator;                      //Uses to validate and avoid user enter aplhabets into integer placeholder
	char dateValidator1;                 //Uses to validate date format
	char dateValidator2;
	int venueAlpha;                      //Uses to validate the format of venue id
	int venueDigit;                      //Uses to validate the format of venue id
	int exist;                           //Check existence of record in other modules
	int wordCount;
	char reply;                          //Uses to accept any reply from user

	VisitorInfo tempInfo[100];
	Venue validate[100];
	int idFound = 0;
	FILE* fptr;
	fptr = fopen("venueModule.txt", "r");  //To input records from Venue module for checking existence of venue

	while (fscanf(fptr, "%[^\|]|%[^\|]|%[^\|]|%d|%d|%d-%d-%d|%d:%d|%d:%d\n", &validate[idFound].venueID, &validate[idFound].category, &validate[idFound].description, &validate[idFound].maxVisitor, &validate[idFound].currentVisitor, &validate[idFound].dateSani.day, &validate[idFound].dateSani.month, &validate[idFound].dateSani.year, &validate[idFound].open.hour, &validate[idFound].open.minute, &validate[idFound].close.hour, &validate[idFound].close.minute) != EOF) {
		idFound++;
	}
	fclose(fptr);
	FILE* fptr2;
	fptr2 = fopen("visitorInfo.dat", "rb"); //To input records from Visitor module for checking existence of visitor information

	if (fptr2 == NULL || fptr == NULL) {
		printf("Unable to open the file\n");
		exit(-1);
	}
	int infoCount = 0;
	while (fread(&tempInfo[infoCount], sizeof(VisitorInfo), 1, fptr2) != 0) {//read the data inside the file
		infoCount++;
	}
	fclose(fptr2);

	//Prompt and Read for visitor IC or enter -1 as Sentinal to exit from this function 
	do {
		printf("%-50s:", "Enter Visitor IC(Including'-')[-1 To Exit]"); rewind(stdin);
		scanf("%s", &tmpVE->visitorIC);
		if (strlen(tmpVE->visitorIC) == 14) {
			if (isdigit(tmpVE->visitorIC[0]) == 0 || isdigit(tmpVE->visitorIC[1]) == 0 || isdigit(tmpVE->visitorIC[2]) == 0 || isdigit(tmpVE->visitorIC[3]) == 0 || isdigit(tmpVE->visitorIC[4]) == 0 || isdigit(tmpVE->visitorIC[5]) == 0 || isdigit(tmpVE->visitorIC[7]) == 0 || isdigit(tmpVE->visitorIC[8]) == 0 || isdigit(tmpVE->visitorIC[10]) == 0 || isdigit(tmpVE->visitorIC[11]) == 0 || isdigit(tmpVE->visitorIC[12]) == 0 || isdigit(tmpVE->visitorIC[13]) == 0) {
				printf("IC Must Be In Numeric(Inlcuding'-')\n");
			}
			else if (tmpVE->visitorIC[6] != '-' || tmpVE->visitorIC[9] != '-') {
				printf("Only '-' Available for IC Format\n");
			}
		}
		else if (tmpVE->visitorIC[0] == '-' && tmpVE->visitorIC[1] == '1' && tmpVE->visitorIC[2] == NULL) {
			//Return 1 to cancel adding function
			return 1;
		}
		else {
			printf("The length is inccorect\n");
		}
	} while (isdigit(tmpVE->visitorIC[0]) == 0 || isdigit(tmpVE->visitorIC[1]) == 0 || isdigit(tmpVE->visitorIC[2]) == 0 || isdigit(tmpVE->visitorIC[3]) == 0 || isdigit(tmpVE->visitorIC[4]) == 0 || isdigit(tmpVE->visitorIC[5]) == 0 || tmpVE->visitorIC[6] != '-' || isdigit(tmpVE->visitorIC[7]) == 0 || isdigit(tmpVE->visitorIC[8]) == 0 || tmpVE->visitorIC[9] != '-' || isdigit(tmpVE->visitorIC[10]) == 0 || isdigit(tmpVE->visitorIC[11]) == 0 || isdigit(tmpVE->visitorIC[12]) == 0 || isdigit(tmpVE->visitorIC[13]) == 0 || strlen(tmpVE->visitorIC) != 14);
	//Checking the existence of visitor, if not exist prompt and read user to add or cancel adding record
	exist = 0;
	for (int u = 0; u < infoCount; u++) {
		if (strcmp(tmpVE->visitorIC, tempInfo[u].IC) == 0) {
			exist = 1;
		}
	}

	if (exist == 0) {
		do {
			printf("The visitor is not existing! Add Visitor?(Y = Yes | N = No)\n"); rewind(stdin);
			scanf("%c", &reply);
			reply = toupper(reply);
			if (reply != 'Y' && reply != 'N') {
				printf("Invalid choice. Please try again.\n");
			}
		} while (reply != 'Y' && reply != 'N');
		reply = toupper(reply);
		if (reply == 'Y') {
			system("cls");
			newVisitor();
			return 2;
		}
		else if (reply != 'Y') {
			//Return 1 to cancel adding function
			return 1;
		}

	}

	//Prompt and Read for date enter, T is the sentinal for automatically input system date
	do {

		printf("%-50s:", "Enter Date Entered(DD-MM-YYYY)"); rewind(stdin);
		scanf("%d%c%d%c%d", &tmpVE->dateEnter.day, &dateValidator1, &tmpVE->dateEnter.month, &dateValidator2, &tmpVE->dateEnter.year);

		switch (tmpVE->dateEnter.month) {

		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: {
			maxDay = 31;
		}break;
		case 2: {
			if (tmpVE->dateEnter.year % 4 == 0) {
				maxDay = 29;
			}
			else
			{
				maxDay = 28;
			}
		}break;

		default:
			maxDay = 30;
		}

		if (dateValidator1 != '-' || dateValidator2 != '-') {
			printf("Only '-' Available for Date Format\n");
		}
		else if (tmpVE->dateEnter.day < 1 || tmpVE->dateEnter.day > maxDay || tmpVE->dateEnter.month < 0 || tmpVE->dateEnter.month > 12) {
			printf("Invalid Date's/Month's Range\n");
		}

	} while (tmpVE->dateEnter.day < 1 || tmpVE->dateEnter.day > maxDay || tmpVE->dateEnter.month < 0 || tmpVE->dateEnter.month > 12 || dateValidator1 != '-' || dateValidator2 != '-');

	//Prompt and Read for visiting reason
	do {
		wordCount = 0;
		printf("%-50s:", "Enter Visiting Reason(Less than 3 words)"); rewind(stdin);
		scanf("%[^\n]", &tmpVE->reason);
		for (int i = 0; i < 30; i++) {
			if (tmpVE->reason[i] == ' ') {
				wordCount++;
			}
		}
		if (wordCount > 2 && strlen(tmpVE->reason) > 29) {
			printf("Only 3 words allowed!\n");
		}
	} while (wordCount > 2 && strlen(tmpVE->reason) > 29);

	//Prompt and Read for tel-Number
	do {
		printf("%-50s:", "Enter Tel-Number(XXX-XXXXXXXX)"); rewind(stdin);
		scanf("%s", &tmpVE->telNo);
		if (tmpVE->telNo[3] != '-' || tmpVE->telNo[3] == NULL || strlen(tmpVE->telNo) > 13 || strlen(tmpVE->telNo) < 11) {
			printf("Invalid Tel Format\n");
		}
		else if (isdigit(tmpVE->telNo[0]) == 0 || isdigit(tmpVE->telNo[1]) == 0 || isdigit(tmpVE->telNo[2]) == 0 || isdigit(tmpVE->telNo[4]) == 0 || isdigit(tmpVE->telNo[5]) == 0 || isdigit(tmpVE->telNo[6]) == 0 || isdigit(tmpVE->telNo[7]) == 0 || isdigit(tmpVE->telNo[8]) == 0 || isdigit(tmpVE->telNo[9]) == 0 || (isdigit(tmpVE->telNo[10]) == 0 && tmpVE->telNo != NULL) || tmpVE->telNo[3] != '-') {
			printf("Input Must Be In Numeric(Including '-')\n");
		}

	} while (isdigit(tmpVE->telNo[0]) == 0 || isdigit(tmpVE->telNo[1]) == 0 || isdigit(tmpVE->telNo[2]) == 0 || isdigit(tmpVE->telNo[4]) == 0 || isdigit(tmpVE->telNo[5]) == 0 || isdigit(tmpVE->telNo[6]) == 0 || isdigit(tmpVE->telNo[7]) == 0 || isdigit(tmpVE->telNo[8]) == 0 || isdigit(tmpVE->telNo[9]) == 0 || (isdigit(tmpVE->telNo[10]) == 0 && tmpVE->telNo != NULL) || strlen(tmpVE->telNo) > 13 || strlen(tmpVE->telNo) < 11);

	//Prompt and Read for Time Enter
	do {
		printf("%-50s:", "Enter Time Entered(HH:MM) in 24-hour clock"); rewind(stdin);
		scanf("%d%c%d", &tmpVE->timeEnter.hour, &validator, &tmpVE->timeEnter.minute);

		if (tmpVE->timeEnter.hour < 0 || tmpVE->timeEnter.hour > 23 || tmpVE->timeEnter.minute < 0 || tmpVE->timeEnter.minute > 59) {
			printf("Invalid Time Range!\n");
		}
		if (validator != ':') {
			printf("Only ':' Available in Time Format\n");
		}
	} while (tmpVE->timeEnter.hour < 0 || tmpVE->timeEnter.hour > 23 || tmpVE->timeEnter.minute < 0 || tmpVE->timeEnter.minute > 59 || validator != ':');

	//Prompt and Read for Venue Id
	do {
		exist = 0;
		venueAlpha = 0;
		venueDigit = 0;
		printf("%-50s:", "Enter Venue ID(eg. ABC123)"); rewind(stdin);
		scanf("%s", &tmpVE->venueID);

		for (int a = 0; a < 3; a++) {
			if (isalpha(tmpVE->venueID[a]) == 0) {
				printf("\nFirst 3 letters of a venue ID must be alphabet.\n");
				venueAlpha++;
				break;
			}
		}
		for (int e = 4; e < 6; e++) {
			if (isdigit(tmpVE->venueID[e]) == 0) {
				printf("Last 3 letters of venue ID must be a digit\n");
				venueDigit++;
				break;
			}
		}
		for (int i = 0; i < 6; i++) {
			tmpVE->venueID[i] = toupper(tmpVE->venueID[i]);
		}
		//Checking the existence if the Venue Id
		for (int u = 0; u < idFound; u++) {
			if (strcmp(tmpVE->venueID, validate[u].venueID) == 0) {
				exist = 1;
			}
		}
		if (exist == 0) {
			printf("Venue ID Not Existing!\n");
		}
	} while (strlen(tmpVE->venueID) != 6 || venueAlpha != 0 || venueDigit != 0 || exist == 0);

	//Prompt and Read for appropriate Visitor Temperature
	do {
		printf("%-50s:", "Enter Visitor Temperature"); rewind(stdin);
		scanf("%lf%c", &tmpVE->temperature, &validator);
		if (tmpVE->temperature < 33 || tmpVE->temperature > 45 || validator != '\n') {
			printf("Please Enter Appropriate Value\n");
		}
	} while (tmpVE->temperature < 33 || tmpVE->temperature > 45 || validator != '\n');

	tmpVE->timeExit.hour = 0;
	tmpVE->timeExit.minute = 0;

	//Return 0 when all the inputs are successfully filled
	return 0;
}

void inputExit() {
	VisitExit visitExit[100];
	Venue venue[100];
	char validator;
	char tmpIC[15];
	int numOfRecords = 0;
	int idFound = 0;
	int exist = 0;
	FILE* inPtr;              //Declare file pointer for input data from text file
	FILE* inPtr2;
	inPtr = fopen("visit&exit.txt", "r");      //Open text file for reading
	inPtr2 = fopen("venueModule.txt", "r");

	while (fscanf(inPtr2, "%[^\|]|%[^\|]|%[^\|]|%d|%d|%d-%d-%d|%d:%d|%d:%d\n", &venue[idFound].venueID, &venue[idFound].category, &venue[idFound].description, &venue[idFound].maxVisitor, &venue[idFound].currentVisitor, &venue[idFound].dateSani.day, &venue[idFound].dateSani.month, &venue[idFound].dateSani.year, &venue[idFound].open.hour, &venue[idFound].open.minute, &venue[idFound].close.hour, &venue[idFound].close.minute) != EOF) {
		idFound++;
	}
	//Check existence of text file
	if (inPtr == NULL || inPtr2 == NULL) {
		printf("Unable to open the file\n");
		exit(-1);
	}
	//Read data from text file until EOF
	while (fscanf(inPtr, "%d-%d-%d|%d:%d|%[^\|]|%[^\|]|%[^\|]|%[^\|]|%lf|%d:%d\n", &visitExit[numOfRecords].dateEnter.day, &visitExit[numOfRecords].dateEnter.month, &visitExit[numOfRecords].dateEnter.year, &visitExit[numOfRecords].timeEnter.hour, &visitExit[numOfRecords].timeEnter.minute, &visitExit[numOfRecords].reason, &visitExit[numOfRecords].visitorIC, &visitExit[numOfRecords].telNo, &visitExit[numOfRecords].venueID, &visitExit[numOfRecords].temperature, &visitExit[numOfRecords].timeExit.hour, &visitExit[numOfRecords].timeExit.minute) != EOF) {
		numOfRecords++;
	}

	do {
		printf("%-50s:", "Enter Visitor IC(Including'-')"); rewind(stdin);
		scanf("%s", &tmpIC);
		if (strlen(tmpIC) == 14) {
			if (isdigit(tmpIC[0]) == 0 || isdigit(tmpIC[1]) == 0 || isdigit(tmpIC[2]) == 0 || isdigit(tmpIC[3]) == 0 || isdigit(tmpIC[4]) == 0 || isdigit(tmpIC[5]) == 0 || isdigit(tmpIC[7]) == 0 || isdigit(tmpIC[8]) == 0 || isdigit(tmpIC[10]) == 0 || isdigit(tmpIC[11]) == 0 || isdigit(tmpIC[12]) == 0 || isdigit(tmpIC[13]) == 0) {
				printf("IC Must Be In Numeric(Inlcuding'-')\n");
			}
			else if (tmpIC[6] != '-' || tmpIC[9] != '-') {
				printf("Only '-' Available for IC Format\n");
			}
		}
		else {
			printf("The length is inccorect\n");
		}
	} while (isdigit(tmpIC[0]) == 0 || isdigit(tmpIC[1]) == 0 || isdigit(tmpIC[2]) == 0 || isdigit(tmpIC[3]) == 0 || isdigit(tmpIC[4]) == 0 || isdigit(tmpIC[5]) == 0 || tmpIC[6] != '-' || isdigit(tmpIC[7]) == 0 || isdigit(tmpIC[8]) == 0 || tmpIC[9] != '-' || isdigit(tmpIC[10]) == 0 || isdigit(tmpIC[11]) == 0 || isdigit(tmpIC[12]) == 0 || isdigit(tmpIC[13]) == 0 || strlen(tmpIC) != 14);

	for (int i = 0; i < numOfRecords; i++) {
		if (strcmp(tmpIC, visitExit[i].visitorIC) == 0 && visitExit[i].timeExit.hour == 0 && visitExit[i].timeExit.minute == 0) {
			//Prompt and Read for Time Exit
			do {
				printf("%-50s:", "Enter Time Exited(HH:MM) in 24-hour clock"); rewind(stdin);
				scanf("%d%c%d", &visitExit[i].timeExit.hour, &validator, &visitExit[i].timeExit.minute);

				if (visitExit[i].timeExit.hour < 0 || visitExit[i].timeExit.hour > 23 || visitExit[i].timeExit.minute < 0 || visitExit[i].timeExit.minute > 59) {
					printf("Invalid Time Range!\n");
				}
				if (validator != ':') {
					printf("Only ':' Available for Time Format\n");
				}
				if ((visitExit[i].timeEnter.hour > visitExit[i].timeExit.hour) || (visitExit[i].timeEnter.hour == visitExit[i].timeExit.hour && visitExit[i].timeEnter.minute > visitExit[i].timeExit.minute)) {
					printf("Time Exit must greater than Time Enter\n");
				}
			} while (visitExit[i].timeExit.hour < 0 || visitExit[i].timeExit.hour > 23 || visitExit[i].timeExit.minute < 0 || visitExit[i].timeExit.minute > 59 || validator != ':' || (visitExit[i].timeEnter.hour > visitExit[i].timeExit.hour) || (visitExit[i].timeEnter.hour == visitExit[i].timeExit.hour && visitExit[i].timeEnter.minute > visitExit[i].timeExit.minute));

			printf("\n%-15s%-15s%-28s%-18s%-13s%-10s%-13s%-10s\n", "Date Entered", "Time Entered", "Reason", "Visitor IC No", "Tel-Number", "Venue ID", "Temperature", "Time Exited");
			printf("%-15s%-15s%-28s%-18s%-13s%-10s%-13s%-10s\n", "=============", "=============", "==========================", "================", "===========", "========", "===========", "=============");
			printf("%02d-%02d-%-9d%02d:%-12.02d%-28s%-18s%-13s%-10s%-13.1lf%02d:%-12.02d\n", visitExit[i].dateEnter.day, visitExit[i].dateEnter.month, visitExit[i].dateEnter.year, visitExit[i].timeEnter.hour, visitExit[i].timeEnter.minute, visitExit[i].reason, visitExit[i].visitorIC, visitExit[i].telNo, visitExit[i].venueID, visitExit[i].temperature, visitExit[i].timeExit.hour, visitExit[i].timeExit.minute);


			exist = 1;
			for (int v = 0; v < idFound; v++) {
				if (strcmp(venue[v].venueID, visitExit[i].venueID) == 0) {
					venue[v].currentVisitor--;
					break;
				}
			}
			break;
		}
	}
	if (exist == 0) {
		printf("Visitor not Found!\n");
	}
	FILE* outptr1;
	outptr1 = fopen("visit&exit.txt", "w");
	for (int u = 0; u < numOfRecords; u++) {
		fprintf(outptr1, "%02d-%02d-%-4d|%02d:%02d|%s|%s|%s|%s|%.1lf|%02d:%02d\n", visitExit[u].dateEnter.day, visitExit[u].dateEnter.month, visitExit[u].dateEnter.year, visitExit[u].timeEnter.hour, visitExit[u].timeEnter.minute, visitExit[u].reason, visitExit[u].visitorIC, visitExit[u].telNo, visitExit[u].venueID, visitExit[u].temperature, visitExit[u].timeExit.hour, visitExit[u].timeExit.minute);
	}
	fclose(outptr1);
	FILE* outPtr2;
	outPtr2 = fopen("venueModule.txt", "w");
	for (int a = 0; a < idFound; a++) {
		fprintf(outPtr2, "%s|%s|%s|%d|%d|%02d-%02d-%-4d|%02d:%02d|%02d:%02d\n", venue[a].venueID, venue[a].category, venue[a].description, venue[a].maxVisitor, venue[a].currentVisitor, venue[a].dateSani.day, venue[a].dateSani.month, venue[a].dateSani.year, venue[a].open.hour, venue[a].open.minute, venue[a].close.hour, venue[a].close.minute);
	}
	fclose(outPtr2);


}

void searchVisitExit() {
	int searchKey;                             //Use to determine user's preference variable to search
	int recordFound;                           //Calculate the number of records that have successfully searched by user
	int numOfRecords = 0;                      //Calculate total number of records in text file
	char reply;                                //Uses to store decision from user
	Date input;                                //Set of variables that use to store input value
	char validator;                            //Uses to validate and avoid user enter aplhabets into integer placeholder and etc
	char dateValidator1;                       //Uses to validate the date format
	char dateValidator2;                       //Uses to validate the date format
	int maxDay;                                //Uses to store maximum days of a specific month
	char inputVisitorIC[15];                   //Declare variable for temporarily hold search input from user
	char venueID[8];                           //Uses to store input value from user
	VisitExit tmpVE[100];                         //Temporarily variables use to hold all the records form text file
	FILE* inPtr;                               //Declare file pointer for input data from text file
	inPtr = fopen("visit&exit.txt", "r");      //Open text file for reading
	//Check existence of text file
	if (inPtr == NULL) {
		printf("Unable to open the file\n");
		exit(-1);
	}
	//Read data from text file until EOF
	while (fscanf(inPtr, "%d-%d-%d|%d:%d|%[^\|]|%[^\|]|%[^\|]|%[^\|]|%lf|%d:%d\n", &tmpVE[numOfRecords].dateEnter.day, &tmpVE[numOfRecords].dateEnter.month, &tmpVE[numOfRecords].dateEnter.year, &tmpVE[numOfRecords].timeEnter.hour, &tmpVE[numOfRecords].timeEnter.minute, &tmpVE[numOfRecords].reason, &tmpVE[numOfRecords].visitorIC, &tmpVE[numOfRecords].telNo, &tmpVE[numOfRecords].venueID, &tmpVE[numOfRecords].temperature, &tmpVE[numOfRecords].timeExit.hour, &tmpVE[numOfRecords].timeExit.minute) != EOF) {
		numOfRecords++;
	}

	fclose(inPtr);
	//Loop use to continuous searching purpose
	do {
		system("cls");
		searchKey = searchMenuVE();    //Call function to display the menu of search keys
		if (searchKey == -1) {
			break;
		}
		recordFound = 0;             //Store number of record found

		//Determine the search key and enter to the respective statement
		switch (searchKey) {
		case 1://Search key using date
		{
			do {
				input.day = 0;
				input.month = 0;
				input.year = 0;
				printf("\nEnter Date(DD-MM-YYYY):"); rewind(stdin);
				scanf("%d%c%d%c%d", &input.day, &dateValidator1, &input.month, &dateValidator2, &input.year);
				switch (input.month) {

				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12: {
					maxDay = 31;
				}break;
				case 2: {
					if (input.year % 4 == 0) {
						maxDay = 29;
					}
					else
					{
						maxDay = 28;
					}
				}break;

				default:
					maxDay = 30;
				}
				if (dateValidator1 != '-' || dateValidator2 != '-') {
					printf("Only '-' Available for Date Format\n");
				}
				else if (input.day < 1 || input.day > maxDay || input.month < 0 || input.month > 12) {
					printf("Invalid Date's/Month's Range\n");
				}
			} while (input.day < 1 || input.day > maxDay || input.month < 0 || input.month > 12 || dateValidator1 != '-' || dateValidator2 != '-');

			printf("\n%-15s%-15s%-28s%-18s%-13s%-10s%-13s%-10s\n", "Date Entered", "Time Entered", "Reason", "Visitor IC No", "Tel-Number", "Venue ID", "Temperature", "Time Exited");
			printf("%-15s%-15s%-28s%-18s%-13s%-10s%-13s%-10s\n", "=============", "=============", "==========================", "================", "===========", "========", "===========", "=============");

			for (int i = 0; i < numOfRecords; i++) {
				if (input.day == tmpVE[i].dateEnter.day && input.month == tmpVE[i].dateEnter.month && input.year == tmpVE[i].dateEnter.year) {
					recordFound++;
					printf("%02d-%02d-%-9d%02d:%-12.02d%-28s%-18s%-13s%-10s%-13.1lf%02d:%-12.02d\n", tmpVE[i].dateEnter.day, tmpVE[i].dateEnter.month, tmpVE[i].dateEnter.year, tmpVE[i].timeEnter.hour, tmpVE[i].timeEnter.minute, tmpVE[i].reason, tmpVE[i].visitorIC, tmpVE[i].telNo, tmpVE[i].venueID, tmpVE[i].temperature, tmpVE[i].timeExit.hour, tmpVE[i].timeExit.minute);
				}
			}
			if (recordFound == 0) {
				printf("No record found!\n");
			}
		}break;

		case 2://search key using visitor IC
		{
			do {
				printf("\nEnter Visitor IC(Including'-'):"); rewind(stdin);
				scanf("%s", &inputVisitorIC);
				if (isdigit(inputVisitorIC[0]) == 0 || isdigit(inputVisitorIC[1]) == 0 || isdigit(inputVisitorIC[2]) == 0 || isdigit(inputVisitorIC[3]) == 0 || isdigit(inputVisitorIC[4]) == 0 || isdigit(inputVisitorIC[5]) == 0 || isdigit(inputVisitorIC[7]) == 0 || isdigit(inputVisitorIC[8]) == 0 || isdigit(inputVisitorIC[10]) == 0 || isdigit(inputVisitorIC[11]) == 0 || isdigit(inputVisitorIC[12]) == 0 || isdigit(inputVisitorIC[13]) == 0) {
					printf("IC Must Be In Numeric(Inlcuding'-')\n");
				}
				else if (inputVisitorIC[6] != '-' || inputVisitorIC[9] != '-') {
					printf("Only '-' Available for IC Format\n");
				}
			} while (isdigit(inputVisitorIC[0]) == 0 || isdigit(inputVisitorIC[1]) == 0 || isdigit(inputVisitorIC[2]) == 0 || isdigit(inputVisitorIC[3]) == 0 || isdigit(inputVisitorIC[4]) == 0 || isdigit(inputVisitorIC[5]) == 0 || inputVisitorIC[6] != '-' || isdigit(inputVisitorIC[7]) == 0 || isdigit(inputVisitorIC[8]) == 0 || inputVisitorIC[9] != '-' || isdigit(inputVisitorIC[10]) == 0 || isdigit(inputVisitorIC[11]) == 0 || isdigit(inputVisitorIC[12]) == 0 || isdigit(inputVisitorIC[13]) == 0);


			printf("\n%-15s%-15s%-28s%-18s%-13s%-10s%-13s%-10s\n", "Date Entered", "Time Entered", "Reason", "Visitor IC No", "Tel-Number", "Venue ID", "Temperature", "Time Exited");
			printf("%-15s%-15s%-28s%-18s%-13s%-10s%-13s%-10s\n", "=============", "=============", "==========================", "================", "===========", "========", "===========", "=============");
			for (int i = 0; i < numOfRecords; i++) {
				if (strcmp(inputVisitorIC, tmpVE[i].visitorIC) == 0) {
					recordFound++;
					printf("%02d-%02d-%-9d%02d:%-12.02d%-28s%-18s%-13s%-10s%-13.1lf%02d:%-12.02d\n", tmpVE[i].dateEnter.day, tmpVE[i].dateEnter.month, tmpVE[i].dateEnter.year, tmpVE[i].timeEnter.hour, tmpVE[i].timeEnter.minute, tmpVE[i].reason, tmpVE[i].visitorIC, tmpVE[i].telNo, tmpVE[i].venueID, tmpVE[i].temperature, tmpVE[i].timeExit.hour, tmpVE[i].timeExit.minute);
				}
			}
			if (recordFound == 0) {
				printf("No record found!\n");
			}
		}break;

		case 3://Search key using Venue ID
		{
			printf("\nEnter Venue ID:"); rewind(stdin);
			scanf("%s", &venueID);

			for (int i = 0; i < 6; i++) {
				venueID[i] = toupper(venueID[i]);
			}

			printf("\n%-15s%-15s%-28s%-18s%-13s%-10s%-13s%-10s\n", "Date Entered", "Time Entered", "Reason", "Visitor IC No", "Tel-Number", "Venue ID", "Temperature", "Time Exited");
			printf("%-15s%-15s%-28s%-18s%-13s%-10s%-13s%-10s\n", "=============", "=============", "==========================", "================", "===========", "========", "===========", "=============");
			for (int i = 0; i < numOfRecords; i++) {
				if (strcmp(venueID, tmpVE[i].venueID) == 0) {
					recordFound++;
					printf("%02d-%02d-%-9d%02d:%-12.02d%-28s%-18s%-13s%-10s%-13.1lf%02d:%-12.02d\n", tmpVE[i].dateEnter.day, tmpVE[i].dateEnter.month, tmpVE[i].dateEnter.year, tmpVE[i].timeEnter.hour, tmpVE[i].timeEnter.minute, tmpVE[i].reason, tmpVE[i].visitorIC, tmpVE[i].telNo, tmpVE[i].venueID, tmpVE[i].temperature, tmpVE[i].timeExit.hour, tmpVE[i].timeExit.minute);
				}
			}
			if (recordFound == 0) {
				printf("No record found!\n");
			}
		}break;

		}
		//Prompt and read for looping
		do {
			printf("\nContinue to Search?(Y = Yes | N = No)"); rewind(stdin);
			scanf("%c", &reply);
			reply = toupper(reply);
			if (reply != 'Y' && reply != 'N') {
				printf("Invalid choice. Please try again.\n");
			}
		} while (reply != 'Y' && reply != 'N');
	} while (reply == 'Y');

}

int searchMenuVE() {
	//This menu enable user to search according to the data they wish to use
	int choice;
	char validator;                //Uses to validate and avoid user enter aplhabets into integer placeholder

	do {
		system("cls");
		printf("++===========================================++\n");
		printf("||%-8s%-35s||\n", " ", "SEARCH VISIT & EXIT RECORDS");
		printf("++%-43s++\n", "-------------------------------------------");
		printf("|| %-42s||\n|| %-42s||\n|| %-42s||\n|| %-42s||\n", "1. DATE", "2. VISITOR IC", "3. VENUE ID", "[-1 TO CANCEL]");
		printf("++===========================================++\n");
		printf("\nSearch According to:"); rewind(stdin);
		scanf("%d%c", &choice, &validator);
		if (choice == -1) {
			return -1;
		}
		if (choice < 1 || choice > 3 || validator != '\n') {
			//Prompt invalid input
			printf("Invalid Choice\n");
			printf("Please choose the numeric within the range shown!\n"); rewind(stdin);
			getchar();
		}
	} while (choice < 1 || choice > 3 || validator != '\n');
	return choice;
}

int modifyVisitExit() {
	VisitorInfo tempInfo[100];
	int recordFound;                     //Store number of recordFound 
	int numOfRecords = 0;                //Store total number of records read from text file
	Date input;                          //Set of variables that use to store input value
	int recordNo[100] = { 0 };           //Uses to show the sequence number of record
	int searchNo;                        //Store the input value of recordNo from user
	char reply;                          //Uses to store any reply from user
	char validator;                      //Uses to validate and avoid user enter aplhabets into integer placeholder
	char dateValidator1;                 //Uses to validate the date format
	char dateValidator2;                 //Uses to validate the date format
	int maxDay;                          //Uses to store maximum days of a specific month
	int choice;                          //Uses to accept value returns from modify menu
	int venueAlpha;                      //Uses to validate the format of venue id
	int venueDigit;                      //Uses to validate the format of venue id
	int wordCount;
	int modifyCount = 0;
	VisitExit tmpVE[100];                   //Temporarily hold data from text file
	FILE* inPtr;                         //Declare file pointer for input from text file
	FILE* outPtr;                        //Declare file pointer for output into text file
	inPtr = fopen("visit&exit.txt", "r");

	//Read all the data from text file
	while (fscanf(inPtr, "%d-%d-%d|%d:%d|%[^\|]|%[^\|]|%[^\|]|%[^\|]|%lf|%d:%d\n", &tmpVE[numOfRecords].dateEnter.day, &tmpVE[numOfRecords].dateEnter.month, &tmpVE[numOfRecords].dateEnter.year, &tmpVE[numOfRecords].timeEnter.hour, &tmpVE[numOfRecords].timeEnter.minute, &tmpVE[numOfRecords].reason, &tmpVE[numOfRecords].visitorIC, &tmpVE[numOfRecords].telNo, &tmpVE[numOfRecords].venueID, &tmpVE[numOfRecords].temperature, &tmpVE[numOfRecords].timeExit.hour, &tmpVE[numOfRecords].timeExit.minute) != EOF) {
		//Count the number of record read from text file
		numOfRecords++;
	}

	FILE* fptr;
	fptr = fopen("visitorInfo.dat", "rb"); //To input records from Visitor module for updation
	//Check the existence of file

	if (fptr == NULL || inPtr == NULL) {
		printf("Unable to open the file\n");
		exit(-1);
	}
	int infoCount = 0;
	while (fread(&tempInfo[infoCount], sizeof(VisitorInfo), 1, fptr) != 0) {//read the data inside the file
		infoCount++;
	}
	fclose(fptr);

	fclose(inPtr);

	do {
		system("cls");
		printf("+========================+\n");
		printf("+ %-23s+\n", "Modify Visit and Exit");
		printf("+========================+\n\n");        //Labelling of function
		recordFound = 0;

		do {
			input.day = 0;
			input.month = 0;
			input.year = 0;
			printf("Enter Date Entered(DD-MM-YYYY):"); rewind(stdin);
			scanf("%d%c%d%c%d", &input.day, &dateValidator1, &input.month, &dateValidator2, &input.year);

			switch (input.month) {

			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12: {
				maxDay = 31;
			}break;
			case 2: {
				if (input.year % 4 == 0) {
					maxDay = 29;
				}
				else
				{
					maxDay = 28;
				}
			}break;

			default:
				maxDay = 30;
			}
			if (dateValidator1 != '-' || dateValidator2 != '-') {
				printf("Only '-' Available for Date Format\n");
			}
			else if (input.day < 1 || input.day > maxDay || input.month < 0 || input.month > 12) {
				printf("Invalid Date's/Month's Range\n");
			}
		} while (input.day < 1 || input.day > maxDay || input.month < 0 || input.month > 12 || dateValidator1 != '-' || dateValidator2 != '-');


		//Heading for each column of data
		printf("\n%-7s%-15s%-15s%-28s%-18s%-13s%-10s%-13s%-10s\n", "No", "Date Entered", "Time Entered", "Reason", "Visitor IC", "Tel-Number", "Venue ID", "Temperature", "Time Exited");
		printf("%-7s%-15s%-15s%-28s%-18s%-13s%-10s%-13s%-10s\n", "=====", "=============", "=============", "==========================", "================", "===========", "========", "===========", "=============");
		//Display the data that matched with the date
		for (int i = 0; i < numOfRecords; i++) {
			if (input.day == tmpVE[i].dateEnter.day && input.month == tmpVE[i].dateEnter.month && input.year == tmpVE[i].dateEnter.year) {
				//Count the number of record matched with the date
				recordFound++;
				recordNo[i] = recordFound;
				printf("%-7.02d%02d-%02d-%-9d%02d:%-12.02d%-28s%-18s%-13s%-10s%-13.1lf%02d:%-12.02d\n", recordNo[i], tmpVE[i].dateEnter.day, tmpVE[i].dateEnter.month, tmpVE[i].dateEnter.year, tmpVE[i].timeEnter.hour, tmpVE[i].timeEnter.minute, tmpVE[i].reason, tmpVE[i].visitorIC, tmpVE[i].telNo, tmpVE[i].venueID, tmpVE[i].temperature, tmpVE[i].timeExit.hour, tmpVE[i].timeExit.minute);

			}
		}
		if (recordFound == 0) {
			//If no record matched, display the message
			printf("No Record Found!\n");
		}
		else
		{
			do {
				printf("\nWant to Modify? (Y = Yes | N = No)"); rewind(stdin);
				scanf("%c", &reply);
				reply = toupper(reply);
				if (reply != 'Y' && reply != 'N') {
					printf("Invalid code! Please enter again.\n");
				}
			} while (reply != 'Y' && reply != 'N');
			if (reply == 'Y') {
				//If the number of record matched not equal to zero, run this statement
				do {
					printf("\nEnter No:"); rewind(stdin);
					scanf("%d%c", &searchNo, &validator);
					if (searchNo <= 0 || searchNo > recordFound || validator != '\n') {
						printf("Invalid Input!\n");
					}
				} while (searchNo <= 0 || searchNo > recordFound || validator != '\n');



				//Determine the record matched with the input data from user
				for (int i = 0; i < numOfRecords; i++) {
					//If every input matched with the respective record, read the statement
					if (input.day == tmpVE[i].dateEnter.day && input.month == tmpVE[i].dateEnter.month && input.year == tmpVE[i].dateEnter.year && searchNo == recordNo[i]) {
						do {

							printf("\n%-15s%-15s%-28s%-18s%-13s%-10s%-13s%-10s\n", "Date Entered", "Time Entered", "Reason", "Visitor IC No", "Tel-Number", "Venue ID", "Temperature", "Time Exited");
							printf("%-15s%-15s%-28s%-18s%-13s%-10s%-13s%-10s\n", "=============", "=============", "==========================", "================", "===========", "========", "===========", "=============");
							printf("%02d-%02d-%-9d%02d:%-12.02d%-28s%-18s%-13s%-10s%-13.1lf%02d:%-12.02d\n\n", tmpVE[i].dateEnter.day, tmpVE[i].dateEnter.month, tmpVE[i].dateEnter.year, tmpVE[i].timeEnter.hour, tmpVE[i].timeEnter.minute, tmpVE[i].reason, tmpVE[i].visitorIC, tmpVE[i].telNo, tmpVE[i].venueID, tmpVE[i].temperature, tmpVE[i].timeExit.hour, tmpVE[i].timeExit.minute);

							choice = modifyMenuVE();
							printf("Enter New Data...\n");
							switch (choice)
							{
							case 1: {
								do {
									printf("%-30s:", "Enter Time Entered(HH:MM)"); rewind(stdin);
									scanf("%d%c%d", &tmpVE[i].timeEnter.hour, &validator, &tmpVE[i].timeEnter.minute);
									if (tmpVE[i].timeEnter.hour < 0 || tmpVE[i].timeEnter.hour > 23 || tmpVE[i].timeEnter.minute < 0 || tmpVE[i].timeEnter.minute > 59 || (tmpVE[i].timeEnter.hour == tmpVE[i].timeExit.hour && tmpVE[i].timeEnter.minute > tmpVE[i].timeExit.minute) || tmpVE[i].timeEnter.hour > tmpVE[i].timeExit.hour) {
										printf("Invalid Time Range!\n");
									}
									if (validator != ':') {
										printf("Only ':' Available in Time Format\n");
									}
								} while (tmpVE[i].timeEnter.hour < 0 || tmpVE[i].timeEnter.hour > 23 || tmpVE[i].timeEnter.minute < 0 || tmpVE[i].timeEnter.minute > 59 || validator != ':' || (tmpVE[i].timeEnter.hour == tmpVE[i].timeExit.hour && tmpVE[i].timeEnter.minute > tmpVE[i].timeExit.minute) || tmpVE[i].timeEnter.hour > tmpVE[i].timeExit.hour);
							}break;
							case 2: {
								do {
									wordCount = 0;
									printf("%-50s:", "Enter Visiting Reason(Less than 3 words)"); rewind(stdin);
									scanf("%[^\n]", &tmpVE[i].reason);
									for (int i = 0; i < 30; i++) {
										if (tmpVE[i].reason[i] == ' ') {
											wordCount++;
										}
									}
									if (wordCount > 2 && strlen(tmpVE[i].reason) > 29) {
										printf("Only 3 words allowed!\n");
									}
								} while (wordCount > 2 && strlen(tmpVE[i].reason) > 29);
							}break;
							case 3: {
								do {
									printf("%-30s:", "Enter Tel-Number(XXX-XXXXXXXX)"); rewind(stdin);
									scanf("%s", &tmpVE[i].telNo);
									if (tmpVE[i].telNo[3] != '-' || strlen(tmpVE[i].telNo) > 13 || strlen(tmpVE[i].telNo) < 11) {
										printf("Only '-' Available for Tel Format\n");
									}
									else if (isdigit(tmpVE[i].telNo[0]) == 0 || isdigit(tmpVE[i].telNo[1]) == 0 || isdigit(tmpVE[i].telNo[2]) == 0 || isdigit(tmpVE[i].telNo[4]) == 0 || isdigit(tmpVE[i].telNo[5]) == 0 || isdigit(tmpVE[i].telNo[6]) == 0 || isdigit(tmpVE[i].telNo[7]) == 0 || isdigit(tmpVE[i].telNo[8]) == 0 || isdigit(tmpVE[i].telNo[9]) == 0 || (isdigit(tmpVE[i].telNo[10]) == 0 && tmpVE[i].telNo != NULL) || tmpVE[i].telNo[3] != '-') {
										printf("Input Must Be In Numeric(Including '-')\n");
									}
								} while (isdigit(tmpVE[i].telNo[0]) == 0 || isdigit(tmpVE[i].telNo[1]) == 0 || isdigit(tmpVE[i].telNo[2]) == 0 || isdigit(tmpVE[i].telNo[4]) == 0 || isdigit(tmpVE[i].telNo[5]) == 0 || isdigit(tmpVE[i].telNo[6]) == 0 || isdigit(tmpVE[i].telNo[7]) == 0 || isdigit(tmpVE[i].telNo[8]) == 0 || isdigit(tmpVE[i].telNo[9]) == 0 || (isdigit(tmpVE[i].telNo[10]) == 0 && tmpVE[i].telNo != NULL) || strlen(tmpVE[i].telNo) > 13 || strlen(tmpVE[i].telNo) < 11);
							}break;
							case 4: {
								do {
									venueAlpha = 0;
									venueDigit = 0;
									printf("Enter venueID: (eg. ABC123)"); rewind(stdin);
									scanf("%s", &tmpVE[i].venueID);
									if (strlen(tmpVE[i].venueID) > 8) {
										printf("\nInvalid input, no more than 8 letters\n");
									}
									for (int a = 0; a < 3; a++) {
										if (isalpha(tmpVE[i].venueID[a]) == 0) {
											printf("\nFirst 3 letters of a venue ID must be alphabet.\n");
											venueAlpha++;
											break;
										}
									}
									for (int e = 4; e < 6; e++) {
										if (isdigit(tmpVE[i].venueID[e]) == 0) {
											printf("Last 3 letters of venue ID must be a digit\n");
											venueDigit++;
											break;
										}
									}
								} while (strlen(tmpVE[i].venueID) > 8 || venueAlpha != 0 || venueDigit > 0);
							}break;
							case 5: {
								do {
									printf("%-30s:", "Enter Time Exited(HH:MM)"); rewind(stdin);
									scanf("%d%c%d", &tmpVE[i].timeExit.hour, &validator, &tmpVE[i].timeExit.minute);
									if (tmpVE[i].timeExit.hour < 0 || tmpVE[i].timeExit.hour > 23 || tmpVE[i].timeExit.minute < 0 || tmpVE[i].timeExit.minute > 59) {
										printf("Invalid Time Range!\n");
									}
									if (validator != ':') {
										printf("Only ':' Available for Time Format\n");
									}
									if ((tmpVE[i].timeEnter.hour > tmpVE[i].timeExit.hour) || (tmpVE[i].timeEnter.hour == tmpVE[i].timeExit.hour) && (tmpVE[i].timeExit.minute < tmpVE[i].timeEnter.minute)) {
										printf("Time Exit must greater than Time Enter\n");
									}
								} while (tmpVE[i].timeExit.hour < 0 || tmpVE[i].timeExit.hour > 23 || tmpVE[i].timeExit.minute < 0 || tmpVE[i].timeExit.minute > 59 || validator != ':' || (tmpVE[i].timeEnter.hour > tmpVE[i].timeExit.hour) || (tmpVE[i].timeEnter.hour == tmpVE[i].timeExit.hour) && (tmpVE[i].timeExit.minute < tmpVE[i].timeEnter.minute));
							}break;
							case 6: {
								do {
									printf("%-30s:", "Enter Visitor Temperature"); rewind(stdin);
									scanf("%lf%c", &tmpVE[i].temperature, &validator);
									if (tmpVE[i].temperature < 33 || tmpVE[i].temperature>45 || validator != '\n') {
										printf("Please Enter Appropriate Value\n");
									}
								} while (tmpVE[i].temperature < 33 || tmpVE[i].temperature>45 || validator != '\n');
							}break;
							case 7: {
								inputVisit(&tmpVE[i]);
							}break;
							default:
								printf("Invalid Selection!\n");
							}
						} while (choice < 1 || choice > 7);

						printf("\n%-15s%-15s%-28s%-18s%-13s%-10s%-13s%-10s\n", "Date Entered", "Time Entered", "Reason", "Visitor IC No", "Tel-Number", "Venue ID", "Temperature", "Time Exited");
						printf("%-15s%-15s%-28s%-18s%-13s%-10s%-13s%-10s\n", "=============", "=============", "==========================", "================", "===========", "========", "===========", "=============");
						printf("%02d-%02d-%-9d%02d:%-12.02d%-28s%-18s%-13s%-10s%-13.1lf%02d:%-12.02d\n\n", tmpVE[i].dateEnter.day, tmpVE[i].dateEnter.month, tmpVE[i].dateEnter.year, tmpVE[i].timeEnter.hour, tmpVE[i].timeEnter.minute, tmpVE[i].reason, tmpVE[i].visitorIC, tmpVE[i].telNo, tmpVE[i].venueID, tmpVE[i].temperature, tmpVE[i].timeExit.hour, tmpVE[i].timeExit.minute);
						do {
							//Confirmation to modify record
							printf("Sure to Modify?(Y = Yes | N = No)"); rewind(stdin);
							scanf("%c", &reply);
							reply = toupper(reply);
							if (reply != 'Y' && reply != 'N') {
								printf("Invalid choice. Please try again.\n");
							}
						} while (reply != 'Y' && reply != 'N');

						if (reply == 'Y') {
							//Update the visitor information
							for (int v = 0; v < infoCount; v++) {
								if (tempInfo[v].date.day == input.day && tempInfo[v].date.month == input.month && tempInfo[v].date.year == input.year && strcmp(tempInfo[v].IC, tmpVE[i].visitorIC) == 0) {
									switch (choice)
									{
									case 1: {tempInfo[v].time = tmpVE[i].timeEnter; break; }
									case 2: {strcpy(tempInfo[v].reason, tmpVE[i].reason); break; }
									case 3: {strcpy(tempInfo[v].contactNo, tmpVE[i].telNo); break; }
									case 4: {strcpy(tempInfo[v].latestVenueVisited, tmpVE[i].venueID); break; }
									case 6: {tempInfo[v].temperature = tmpVE[i].temperature; break; }
									case 7: {
										tempInfo[v].date = tmpVE[i].dateEnter;
										tempInfo[v].time = tmpVE[i].timeEnter;
										strcpy(tempInfo[v].reason, tmpVE[i].reason);
										strcpy(tempInfo[v].contactNo, tmpVE[i].telNo);
										strcpy(tempInfo[v].latestVenueVisited, tmpVE[i].venueID);
										tempInfo[v].temperature = tmpVE[i].temperature;
										strcpy(tempInfo[v].IC, tmpVE[i].visitorIC);
									}

									}
								}
							}
							FILE* outPtr2;
							outPtr2 = fopen("visitorInfo.dat", "wb");

							if (outPtr2 == NULL) {
								printf("Unable to open the file\n");
								exit(-1);
							}

							for (int v = 0; v < infoCount; v++) {
								fwrite(&tempInfo[v], sizeof(VisitorInfo), 1, outPtr2);
							}

							fclose(outPtr2);

							//If confirmed to modify, write the data into text file
							modifyCount++;
							outPtr = fopen("visit&exit.txt", "w");
							for (int u = 0; u < numOfRecords; u++) {
								fprintf(outPtr, "%02d-%02d-%-4d|%02d:%02d|%s|%s|%s|%s|%.1lf|%02d:%02d\n", tmpVE[u].dateEnter.day, tmpVE[u].dateEnter.month, tmpVE[u].dateEnter.year, tmpVE[u].timeEnter.hour, tmpVE[u].timeEnter.minute, tmpVE[u].reason, tmpVE[u].visitorIC, tmpVE[u].telNo, tmpVE[u].venueID, tmpVE[u].temperature, tmpVE[u].timeExit.hour, tmpVE[u].timeExit.minute);
							}
							fclose(outPtr);

						}

					}
				}
			}
		}
		//Prompt and read for loop
		do {
			printf("Continue to Modity?(Y = Yes | N = No)"); rewind(stdin);
			scanf("%c", &reply);
			reply = toupper(reply);
			if (reply != 'Y' && reply != 'N') {
				printf("Invalid code! Please enter again.\n");
			}
		} while (reply != 'Y' && reply != 'N');


	} while (reply == 'Y');
	printf("%d Record(s) Updated\n", modifyCount);
	return 0;
}

int modifyMenuVE() {
	int choice;
	char validator;
	do {
		system("cls");
		printf("++===============================================================++\n");
		printf("|| Which category would you like to modify ? (Choose from 1 - 7) ||\n");
		printf("||     %-58s||\n||     %-58s||\n||     %-58s||\n||     %-58s||\n||     %-58s||\n||     %-58s||\n||     %-58s||\n", "1.Time Entered", "2.Reason", "3.Tel-Number", "4.Venue ID", "5.Time Exited", "6.Temperature", "7.All");
		printf("++===============================================================++\n\n");
		printf("Enter Selection (1-7)"); rewind(stdin);
		scanf("%d%c", &choice, &validator);
		if (validator != '\n') {
			printf("Please choose the numeric within the range shown!\n");
		}
	} while (validator != '\n');

	return choice;
}

void displayVisitExit() {
	VisitExit visitExit;                                       //Declare variable using the Visitor structure type
	int numOfRecords = 0;                                  //Initiallizing number of records to store the count of records displayed
	FILE* inPtr;                                           //Declare the file pointer for data input from text file
	inPtr = fopen("visit&exit.txt", "r");                  //open the text file
	//Checking the exist of the text file
	if (inPtr == NULL) {
		printf("Unable to open the file\n");
		exit(-1);
	}

	system("cls");
	printf("+========================+\n");
	printf("+ %-23s+\n", "Display Visit and Exit");
	printf("+========================+\n");
	//Display the heading for each column of data
	printf("%-15s%-15s%-28s%-18s%-13s%-11s%-14s%-10s\n", "+--------------+", "+--------------+", "+--------------------------+", "+----------------+", "+--------------+", "+----------+", "+-------------+", "+-------------+");
	printf("%-15s%-15s%-28s%-18s%-13s%-11s%-14s%-10s\n", "| Date Entered |", "| Time Entered |", "|         Reason           |", "| Visitor IC No  |", "|    Tel-No    |", "| Venue ID |", "| Temperature |", "| Time Exited |");
	printf("%-15s%-15s%-28s%-18s%-13s%-11s%-14s%-10s\n", "+--------------+", "+--------------+", "+--------------------------+", "+----------------+", "+--------------+", "+----------+", "+-------------+", "+-------------+");
	//Read data from the text file until the EOF
	while (fscanf(inPtr, "%d-%d-%d|%d:%d|%[^\|]|%[^\|]|%[^\|]|%[^\|]|%lf|%d:%d\n", &visitExit.dateEnter.day, &visitExit.dateEnter.month, &visitExit.dateEnter.year, &visitExit.timeEnter.hour, &visitExit.timeEnter.minute, &visitExit.reason, &visitExit.visitorIC, &visitExit.telNo, &visitExit.venueID, &visitExit.temperature, &visitExit.timeExit.hour, &visitExit.timeExit.minute) != EOF) {
		//Calculte the records read 
		numOfRecords++;
		printf("| %02d-%02d-%-6d || %02d:%-9.02d || %-24s || %-14s || %-12s || %-8s || %-11.1lf || %02d:%-8.02d |\n", visitExit.dateEnter.day, visitExit.dateEnter.month, visitExit.dateEnter.year, visitExit.timeEnter.hour, visitExit.timeEnter.minute, visitExit.reason, visitExit.visitorIC, visitExit.telNo, visitExit.venueID, visitExit.temperature, visitExit.timeExit.hour, visitExit.timeExit.minute);
		printf("%-15s%-15s%-28s%-18s%-13s%-11s%-14s%-10s\n", "+--------------+", "+--------------+", "+--------------------------+", "+----------------+", "+--------------+", "+----------+", "+-------------+", "+-------------+");

	}
	//Display number of records displayed
	printf("\n%d of Records Displayed ~\n", numOfRecords);
	fclose(inPtr);
}

void deleteVisitExit() {
	VisitExit tmpVE[100];                     //Temporarily hold data from text file       
	int numOfRecords = 0;                  //Store total number of records read from text file
	int deleteNo;                          //Store user input value to delete a specific record
	int maxDay;                            //Uses to store maximum days of a specific month
	int deletionCount = 0;                 //Store number of deleted record(s)
	char reply;                            //Uses to store any reply from user
	char dateValidator1;                 //Uses to validate the date format
	char dateValidator2;               //Uses to validate the date format
	int recordFound = 0;                   //Uses to show the sequence number of record
	int recordNo[100];                     //Uses to store the sequence number of record
	char validator;
	Date input;                            //Set of variables that use to store input value
	FILE* inPtr;                           //Declare file pointer for input from text file
	FILE* outPtr;                          //Declare file pointer for output into text file
	inPtr = fopen("visit&exit.txt", "r");
	//Check the existence of text file
	if (inPtr == NULL) {
		printf("Unable to open the file\n");
		exit(-1);
	}

	//Read all the data from text file
	while (fscanf(inPtr, "%d-%d-%d|%d:%d|%[^\|]|%[^\|]|%[^\|]|%[^\|]|%lf|%d:%d\n", &tmpVE[numOfRecords].dateEnter.day, &tmpVE[numOfRecords].dateEnter.month, &tmpVE[numOfRecords].dateEnter.year, &tmpVE[numOfRecords].timeEnter.hour, &tmpVE[numOfRecords].timeEnter.minute, &tmpVE[numOfRecords].reason, &tmpVE[numOfRecords].visitorIC, &tmpVE[numOfRecords].telNo, &tmpVE[numOfRecords].venueID, &tmpVE[numOfRecords].temperature, &tmpVE[numOfRecords].timeExit.hour, &tmpVE[numOfRecords].timeExit.minute) != EOF) {
		//Count the number of record read from text file
		numOfRecords++;
	}

	do {
		system("cls");
		printf("================================\n");
		printf("||     Deletion of Records    ||\n");
		printf("================================\n");
		recordFound = 0;
		deleteNo = 0;
		do {
			input.day = 0;
			input.month = 0;
			input.year = 0;
			printf("Enter Date Entered(DD-MM-YYYY):"); rewind(stdin);
			scanf("%d%c%d%c%d", &input.day, &dateValidator1, &input.month, &dateValidator2, &input.year);
			switch (input.month) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12: {
				maxDay = 31;
			}break;
			case 2: {
				if (input.year % 4 == 0) {
					maxDay = 29;
				}
				else
				{
					maxDay = 28;
				}
			}break;
			default:
				maxDay = 30;
			}
			if (dateValidator1 != '-' || dateValidator2 != '-') {
				printf("Only '-' Available for Date Format\n");
			}
			else if (input.day < 1 || input.day > maxDay || input.month < 0 || input.month > 12) {
				printf("Invalid Date's/Month's Range\n");
			}
		} while (input.day < 1 || input.day > maxDay || input.month < 0 || input.month > 12 || dateValidator1 != '-' || dateValidator2 != '-');
		//Heading for each column of data
		printf("\n%-5s%-15s%-15s%-28s%-18s%-13s%-10s%-13s%-10s\n", "No", "Date Entered", "Time Entered", "Reason", "Visitor IC No", "Tel-Number", "Venue ID", "Temperature", "Time Exited");
		printf("%-5s%-15s%-15s%-28s%-18s%-13s%-10s%-13s%-10s\n", "===", "=============", "=============", "==========================", "================", "===========", "========", "===========", "=============");


		//Display the data that matched with the date
		for (int i = 0; i < numOfRecords; i++) {
			if (input.day == tmpVE[i].dateEnter.day && input.month == tmpVE[i].dateEnter.month && input.year == tmpVE[i].dateEnter.year) {
				//Count the number of record matched with the date
				recordFound++;
				recordNo[i] = recordFound;
				printf("%-5.02d%02d-%02d-%-9d%02d:%-12.02d%-28s%-18s%-13s%-10s%-13.1lf%02d:%-12.02d\n", recordNo[i], tmpVE[i].dateEnter.day, tmpVE[i].dateEnter.month, tmpVE[i].dateEnter.year, tmpVE[i].timeEnter.hour, tmpVE[i].timeEnter.minute, tmpVE[i].reason, tmpVE[i].visitorIC, tmpVE[i].telNo, tmpVE[i].venueID, tmpVE[i].temperature, tmpVE[i].timeExit.hour, tmpVE[i].timeExit.minute);

			}
		}
		if (recordFound == 0) {
			//If no record matched, display the message
			printf("No Record Found!\n");
		}
		else {
			//If the number of record matched not equal to zero, run this statement
			do {
				printf("\nEnter No:"); rewind(stdin);
				scanf("%d%c", &deleteNo, &validator);
				if (validator != '\n' || deleteNo == 0 || deleteNo > recordFound) {
					printf("Invalid input! Please try again!\n");
				}
			} while (validator != '\n' || deleteNo == 0 || deleteNo > recordFound);

			for (int i = 0; i < numOfRecords; i++) {
				if (input.day == tmpVE[i].dateEnter.day && input.month == tmpVE[i].dateEnter.month && input.year == tmpVE[i].dateEnter.year && deleteNo == recordNo[i]) {
					//Heading for each column of data
					printf("\n%-15s%-15s%-28s%-18s%-13s%-10s%-13s%-10s\n", "Date Entered", "Time Entered", "Reason", "Visitor IC No", "Tel-Number", "Venue ID", "Temperature", "Time Exited");
					printf("%-15s%-15s%-28s%-18s%-13s%-10s%-13s%-10s\n", "=============", "=============", "==========================", "================", "===========", "========", "===========", "=============");
					printf("%02d-%02d-%-9d%02d:%-12.02d%-28s%-18s%-13s%-10s%-13.1lf%02d:%-12.02d\n\n", tmpVE[i].dateEnter.day, tmpVE[i].dateEnter.month, tmpVE[i].dateEnter.year, tmpVE[i].timeEnter.hour, tmpVE[i].timeEnter.minute, tmpVE[i].reason, tmpVE[i].visitorIC, tmpVE[i].telNo, tmpVE[i].venueID, tmpVE[i].temperature, tmpVE[i].timeExit.hour, tmpVE[i].timeExit.minute);
					//Confirmation to delete record
					do {
						printf("Sure to Delete?(Y = Yes | N = No)\n"); rewind(stdin);
						scanf("%c", &reply);
						reply = toupper(reply);
						if (reply != 'Y' && reply != 'N') {
							printf("Invalid choice. Please try again.\n");
						}
					} while (reply != 'Y' && reply != 'N');
					if (reply == 'Y') {
						deletionCount++;
						for (int u = i; u < numOfRecords; u++) {
							tmpVE[u] = tmpVE[u + 1];
						}
						numOfRecords -= deletionCount;

						//If confirmed to modify, write the data into text file
						outPtr = fopen("visit&exit.txt", "w");
						for (int u = 0; u < numOfRecords; u++) {
							fprintf(outPtr, "%02d-%02d-%-4d|%02d:%02d|%s|%s|%s|%s|%.1lf|%02d:%02d\n", tmpVE[u].dateEnter.day, tmpVE[u].dateEnter.month, tmpVE[u].dateEnter.year, tmpVE[u].timeEnter.hour, tmpVE[u].timeEnter.minute, tmpVE[u].reason, tmpVE[u].visitorIC, tmpVE[u].telNo, tmpVE[u].venueID, tmpVE[u].temperature, tmpVE[u].timeExit.hour, tmpVE[u].timeExit.minute);
						}
						fclose(outPtr);
					}
				}
			}



		}
		do {
			//Prompt and read for loop
			printf("Continue to Delete?(Y = Yes | N = No)"); rewind(stdin);
			scanf("%c", &reply);
			reply = toupper(reply);
			if (reply != 'Y' && reply != 'N') {
				printf("Invalid choice. Please try again.\n");
			}
		} while (reply != 'Y' && reply != 'N');

	} while (reply == 'Y');
	printf("%d of Records Deleted\n", deletionCount);
}

void reportVisitExit() {
	Venue venue[100];
	VisitExit visitor[100];                  //Declare variable using the Visitor structure type
	int maxDay;                            //Uses to store maximum days of a specific month
	char reply;                            //Uses to store any reply from user
	char dateValidator;                    //Uses to validate the date format
	int numOfRecords[2] = { 0 };               //Uses to store the number of records from different files
	int month;                             //Uses to store user input of month in numeric
	int year;                              //Uses to store user input of year in numeric
	int existOfRecord;
	double highestTemp[2] = { 0 };                 //Uses to store highest temperature for different purposes
	char monthName[10];                    //Uses to convert numeric month into string
	int highestVisit = 0;                  //Uses to store the highest number of visitor
	int highestVenueIndex[2];              //Uses to store the index value of highest number of visitor and temperature

	FILE* inPtr;                                           //Declare the file pointer for data input from text file
	inPtr = fopen("visit&exit.txt", "r");                  //open the text file
	FILE* inPtr1;                                           //Declare the file pointer for data input from text file
	inPtr1 = fopen("venueModule.txt", "r");                  //open the text file
	//Checking the exist of the text file
	if (inPtr == NULL || inPtr1 == NULL) {
		printf("Unable to open the file\n");
		exit(-1);
	}

	//Read data from text file until EOF
	while (fscanf(inPtr, "%d-%d-%d|%d:%d|%[^\|]|%[^\|]|%[^\|]|%[^\|]|%lf|%d:%d\n", &visitor[numOfRecords[0]].dateEnter.day, &visitor[numOfRecords[0]].dateEnter.month, &visitor[numOfRecords[0]].dateEnter.year, &visitor[numOfRecords[0]].timeEnter.hour, &visitor[numOfRecords[0]].timeEnter.minute, &visitor[numOfRecords[0]].reason, &visitor[numOfRecords[0]].visitorIC, &visitor[numOfRecords[0]].telNo, &visitor[numOfRecords[0]].venueID, &visitor[numOfRecords[0]].temperature, &visitor[numOfRecords[0]].timeExit.hour, &visitor[numOfRecords[0]].timeExit.minute) != EOF) {
		numOfRecords[0]++;
	}
	while (fscanf(inPtr1, "%[^\|]|%[^\|]|%[^\|]|%d|%d|%d-%d-%d|%d:%d|%d:%d\n", &venue[numOfRecords[1]].venueID, &venue[numOfRecords[1]].category, &venue[numOfRecords[1]].description, &venue[numOfRecords[1]].maxVisitor, &venue[numOfRecords[1]].currentVisitor, &venue[numOfRecords[1]].dateSani.day, &venue[numOfRecords[1]].dateSani.month, &venue[numOfRecords[1]].dateSani.year, &venue[numOfRecords[1]].open.hour, &venue[numOfRecords[1]].open.minute, &venue[numOfRecords[1]].close.hour, &venue[numOfRecords[1]].close.minute) != EOF)
	{
		numOfRecords[1]++;
	}
	do {
		int numOfPeople[100] = { 0 };          //Uses to store number of visitor for each venue
		existOfRecord = 0;
		do
		{
			system("cls");
			heading();
			printf("\nEnter Month&Year to Search (XX-YYYY):"); rewind(stdin);
			scanf("%d%c%d", &month, &dateValidator, &year);
			switch (month)
			{
			case 1:
				strcpy(monthName, "January"); break;
			case 2:
				strcpy(monthName, "Febuary"); break;
			case 3:
				strcpy(monthName, "March"); break;
			case 4:
				strcpy(monthName, "April"); break;
			case 5:
				strcpy(monthName, "May"); break;
			case 6:
				strcpy(monthName, "June"); break;
			case 7:
				strcpy(monthName, "July"); break;
			case 8:
				strcpy(monthName, "August"); break;
			case 9:
				strcpy(monthName, "September"); break;
			case 10:
				strcpy(monthName, "October"); break;
			case 11:
				strcpy(monthName, "November"); break;
			case 12:
				strcpy(monthName, "December"); break;
			default:
				printf("Invalid Month's range\n");
				break;
			}
		} while (month < 1 || month > 12 || dateValidator != '-');

		printf(" ++------------------------++\n");
		printf("    %s %s %-5d\n", "Report on", monthName, year);
		printf(" ++------------------------++\n");


		//Display the heading for each column of data
		printf(" %-12s%-22s%-28s%-22s\n", "+----------+", "+--------------------+", "+--------------------------+", "+-------------------------------+");
		printf(" %-12s%-22s%-28s%-22s\n", "| Venue ID |", "| Venue  Description |", "| Number of people Visited |", "| Highest Visitor's Temperature |");
		printf(" %-12s%-22s%-28s%-22s\n", "+----------+", "+--------------------+", "+--------------------------+", "+-------------------------------+");

		//Finding the highest temperature for each venue and update the highest temperature from all venues

		for (int i = 0; i < numOfRecords[1]; i++) {
			highestTemp[0] = 0;
			for (int u = 0; u < numOfRecords[0]; u++) {
				if (year == visitor[u].dateEnter.year && month == visitor[u].dateEnter.month && strcmp(venue[i].venueID, visitor[u].venueID) == 0) {
					existOfRecord = 1;
					numOfPeople[i]++;
					if (visitor[u].temperature > highestTemp[0]) {
						highestTemp[0] = visitor[u].temperature;
					}
				}

			}
			//Updating the highest number of visitations and its index
			if (numOfPeople[i] > highestVisit) {
				highestVisit = numOfPeople[i];
				highestVenueIndex[0] = i;
			}
			if (numOfPeople[i] != 0) {
				printf(" | %-9s|| %-19s||             %-13d||             %-18.2lf|\n", venue[i].venueID, venue[i].description, numOfPeople[i], highestTemp[0]);
				printf(" %-12s%-22s%-28s%-22s\n", "+----------+", "+--------------------+", "+--------------------------+", "+-------------------------------+");
			}
			//Updating highest temperature of visitor and its index
			if (highestTemp[0] > highestTemp[1]) {
				highestTemp[1] = highestTemp[0];
				highestVenueIndex[1] = i;
			}
		}

		if (existOfRecord == 0) {
			printf("\n No record Found!\n");
		}
		else {
			printf("\n\ COMMENT__________________________________________________________________________________________\n");
			printf("  The Most Frequently Used Venue >\n");
			printf("%57s %-8s\n", "Venue ID             :", venue[highestVenueIndex[0]].venueID);
			printf("%57s %-8s\n", "Venue Description    :", venue[highestVenueIndex[0]].description);
			printf("  The Highest Risk Venue         >\n");
			printf("%57s %-8s\n", "Venue ID             :", venue[highestVenueIndex[1]].venueID);
			printf("%57s %-8s\n", "Venue Description    :", venue[highestVenueIndex[1]].description);
			printf("\n\ THE END__________________________________________________________________________________________\n");

		}
		do {
			printf("\nContinue to Generate Report? (Y = Yes | N = No)"); rewind(stdin);
			scanf("%c", &reply);
			reply = toupper(reply);
			if (reply != 'Y' && reply != 'N') {
				printf("Invalid choice. Please try again.\n");
			}
		} while (reply != 'Y' && reply != 'N');

	} while (reply == 'Y');

	fclose(inPtr);
	fclose(inPtr1);

}

int visitorMenu() { //visitor menu

	char choice, selection, selection2;
	char reply;

	do {
		do {
			system("cls");
			heading();
			printf("%19s+=================================+\n", "");
			printf("%19s||    VISITOR INFORMATION MENU   ||\n", "");
			printf("%19s||-------------------------------||\n", "");
			printf("%19s||	 1. New Visitor             ||\n", "");
			printf("%19s||	 2. Search                  ||\n", "");
			printf("%19s||	 3. List Of Visitor         ||\n", "");
			printf("%19s||	 4. Modify Visitor          ||\n", "");
			printf("%19s||	 5. Delete Visitor          ||\n", "");
			printf("%19s||	 6. Generate Report         ||\n", "");
			printf("%19s||	 7. Exit To Main Menu       ||\n", ""); //back to main menu to choose another menu
			printf("%19s+=================================+\n", "");
			printf("----Please enter your selection : ");
			scanf("%c", &choice);
			if (choice == '1') {
				system("cls");

				do
				{
					printf("Are you sure want to add new Visitor? (Y = Yes | N = No): ");
					rewind(stdin);
					scanf("%c", &selection);

					if (selection == 'Y' || selection == 'y')
					{
						newVisitor();
						break;
					}
					else if (selection == 'N' || selection == 'n')
					{
						system("cls");
						break;//back to visitor Menu
					}
					else
						system("cls");
					printf("Invalid! \n");

				} while (selection != 'Y' || selection != 'y' || selection != 'N' || selection != 'n');

			}
			else if (choice == '2') {
				system("cls");
				searchVisitor();
			}
			else if (choice == '3') {
				system("cls");
				visitorList();
			}
			else if (choice == '4') {
				system("cls");
				modifyVisitor();
			}
			else if (choice == '5') {
				system("cls");
				deleteVisitor();
			}
			else if (choice == '6') {
				system("cls");
				reportVisitor();
			}
			else if (choice == '7') {
				system("cls");
				return 1;//main menu
			}
			else
				system("cls");


		} while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7');
		do {
			printf("Return to Visitor Menu?(Y = Yes | N = No)\n"); rewind(stdin);
			scanf("%c", &reply);
			reply = toupper(reply);
			if (reply != 'Y' && reply != 'N') {
				printf("Invalid choice. Please try again.\n");
			}
		} while (reply != 'Y' && reply != 'N');
	} while (reply == 'Y');
}

void newVisitor() {
	VisitExit visitExit;//Append new record
	VisitorInfo tempVisitor;//store visitor's details
	char choice, selection;
	char validate1, validate2, validate3;
	int venueAlpha;
	int venueDigit;
	int exist = 0;
	Venue validate[100];
	int idFound = 0;
	FILE* fptr2;
	fptr2 = fopen("visit&exit.txt", "a");
	FILE* fptr;
	fptr = fopen("venueModule.txt", "r");
	if (!fptr) {
		printf("File not found.");
		exit(1);
	}
	while (fscanf(fptr, "%[^\|]|%[^\|]|%[^\|]|%d|%d|%d-%d-%d|%d:%d|%d:%d\n", &validate[idFound].venueID, &validate[idFound].category, &validate[idFound].description, &validate[idFound].maxVisitor, &validate[idFound].currentVisitor, &validate[idFound].dateSani.day, &validate[idFound].dateSani.month, &validate[idFound].dateSani.year, &validate[idFound].open.hour, &validate[idFound].open.minute, &validate[idFound].close.hour, &validate[idFound].close.minute) != EOF) {
		idFound++;
	}
	fclose(fptr);
	fptr = fopen("VisitorInfo.dat", "ab");
	do {
		printf("\n----Please insert the Vistor's information :\n\n\n");

		do {
			printf("Visitor IC No (xxxxxx-xx-xxxx) : ");
			rewind(stdin);
			scanf("%s", &tempVisitor.IC);
			if (isdigit(tempVisitor.IC[0]) == 0 || isdigit(tempVisitor.IC[1]) == 0 || isdigit(tempVisitor.IC[2]) == 0 || isdigit(tempVisitor.IC[3]) == 0 || isdigit(tempVisitor.IC[4]) == 0 || isdigit(tempVisitor.IC[5]) == 0 || isdigit(tempVisitor.IC[7]) == 0 || isdigit(tempVisitor.IC[8]) == 0 || isdigit(tempVisitor.IC[10]) == 0 || isdigit(tempVisitor.IC[11]) == 0 || isdigit(tempVisitor.IC[12]) == 0 || isdigit(tempVisitor.IC[13]) == 0) {
				printf("IC Must Be In Numeric(Inlcuding'-')\n");
			}
			else if (tempVisitor.IC[6] != '-' || tempVisitor.IC[9] != '-') {
				printf("Only '-' Available for IC Format\n");
			}
		} while (isdigit(tempVisitor.IC[0]) == 0 || isdigit(tempVisitor.IC[1]) == 0 || isdigit(tempVisitor.IC[2]) == 0 || isdigit(tempVisitor.IC[3]) == 0 || isdigit(tempVisitor.IC[4]) == 0 || isdigit(tempVisitor.IC[5]) == 0 || isdigit(tempVisitor.IC[7]) == 0 || isdigit(tempVisitor.IC[8]) == 0 || isdigit(tempVisitor.IC[10]) == 0 || isdigit(tempVisitor.IC[11]) == 0 || isdigit(tempVisitor.IC[12]) == 0 || isdigit(tempVisitor.IC[13]) == 0 || tempVisitor.IC[6] != '-' || tempVisitor.IC[9] != '-');


		printf("Visitor Name : ");
		rewind(stdin);
		scanf("%[^\n]", &tempVisitor.name);

		do {
			printf("Enter Tel-Number(XXX-XXXXXXXX) :"); rewind(stdin);
			scanf("%s", &tempVisitor.contactNo);
			if (tempVisitor.contactNo[3] != '-') {
				printf("Only '-' Available for Tel Format\n");
			}
			else if (isdigit(tempVisitor.contactNo[0]) == 0 || isdigit(tempVisitor.contactNo[1]) == 0 || isdigit(tempVisitor.contactNo[2]) == 0 || isdigit(tempVisitor.contactNo[4]) == 0 || isdigit(tempVisitor.contactNo[5]) == 0 || isdigit(tempVisitor.contactNo[6]) == 0 || isdigit(tempVisitor.contactNo[7]) == 0 || isdigit(tempVisitor.contactNo[8]) == 0 || isdigit(tempVisitor.contactNo[9]) == 0 || (isdigit(tempVisitor.contactNo[10]) == 0 && tempVisitor.contactNo != NULL)) {
				printf("Input Must Be In Numeric(Including '-')\n");
			}
		} while (isdigit(tempVisitor.contactNo[0]) == 0 || isdigit(tempVisitor.contactNo[1]) == 0 || isdigit(tempVisitor.contactNo[2]) == 0 || isdigit(tempVisitor.contactNo[4]) == 0 || isdigit(tempVisitor.contactNo[5]) == 0 || isdigit(tempVisitor.contactNo[6]) == 0 || isdigit(tempVisitor.contactNo[7]) == 0 || isdigit(tempVisitor.contactNo[8]) == 0 || isdigit(tempVisitor.contactNo[9]) == 0 || (isdigit(tempVisitor.contactNo[10]) == 0 && tempVisitor.contactNo != NULL || tempVisitor.contactNo[3] != '-'));


		printf("Position (Students / faculty/ administrative / office staff / general workers / outsiders) : ");
		rewind(stdin);
		scanf("%[^\n]", &tempVisitor.position);

		do {
			venueAlpha = 0;
			venueDigit = 0;
			printf("Enter Venue ID(eg. ABC123):"); rewind(stdin);
			scanf("%s", &tempVisitor.latestVenueVisited);

			for (int a = 0; a < 3; a++) {
				if (isalpha(tempVisitor.latestVenueVisited[a]) == 0) {
					printf("\nFirst 3 letters of a venue ID must be alphabet.\n");
					venueAlpha++;
					break;
				}
			}
			for (int e = 4; e < 6; e++) {
				if (isdigit(tempVisitor.latestVenueVisited[e]) == 0) {
					printf("Last 3 letters of venue ID must be a digit\n");
					venueDigit++;
					break;
				}
			}
			for (int i = 0; i < 6; i++) {
				tempVisitor.latestVenueVisited[i] = toupper(tempVisitor.latestVenueVisited[i]);
			}
			for (int u = 0; u < idFound; u++) {
				if (strcmp(tempVisitor.latestVenueVisited, validate[u].venueID) == 0) {
					exist = 1;
				}
			}
			if (exist == 0) {
				printf("Venue ID Not Existing!\n");
			}
		} while (strlen(tempVisitor.latestVenueVisited) != 6 || venueAlpha != 0 || venueDigit != 0 || exist == 0);

		printf("Reason : ");
		rewind(stdin);
		scanf("%[^\n]", &tempVisitor.reason);

		do {
			printf("Temperature : ");
			scanf("%f", &tempVisitor.temperature);
			if (tempVisitor.temperature < 36.00 || tempVisitor.temperature>40.00)
			{
				printf("Please insert again.\n");
			}
			if (tempVisitor.temperature <= 37.5)
			{
				printf("Warning! Temperature is more than 37.5!\n");
			}
		} while (tempVisitor.temperature < 36.00 || tempVisitor.temperature>40.00);

		printf("Gender (female / male ): ");
		rewind(stdin);
		scanf("%[^\n]", &tempVisitor.gender);


		do {
			printf("Date (DD-MM-YYYY) : ");
			rewind(stdin);
			scanf("%2d%c%2d%c%4d", &tempVisitor.date.day, &validate1, &tempVisitor.date.month, &validate2, &tempVisitor.date.year);

			if (tempVisitor.date.day > 31 || tempVisitor.date.day <= 0)
			{
				printf("invalid date\n");
			}
			if (tempVisitor.date.month >= 13 || tempVisitor.date.month <= 0)
			{
				printf("invalid month\n");
			}
		} while (tempVisitor.date.day > 31 || tempVisitor.date.day <= 0 || tempVisitor.date.month >= 13 || tempVisitor.date.month <= 0);

		do {
			printf("Time (HH:MM) : ");
			rewind(stdin);
			scanf("%2d%c%2d", &tempVisitor.time.hour, &validate3, &tempVisitor.time.minute);

			if (tempVisitor.time.hour >= 25 || tempVisitor.time.hour < 0)
			{
				printf("Invalid hour!\n");
			}
			else if (tempVisitor.time.minute >= 60 || tempVisitor.time.minute < 0)
			{
				printf("Invalid minute!\n");
			}
		} while (tempVisitor.time.hour >= 25 || tempVisitor.time.hour < 0 || tempVisitor.time.minute >= 60 || tempVisitor.time.minute < 0);

		printf("\n\n+-----------------+------------------+------------------+-----------------+----------+----------------------------+-----------------+---------------+------------+-------+\n");
		printf("|  IC             |   NAME           | CONTACT          |  POSITION       | VENUR ID |       REASON		  |  TEMPERATURE    |GENDER         | DATE       | TIME  |\n");
		printf("+-----------------+------------------+------------------+-----------------+----------+----------------------------+-----------------+---------------+------------+-------+\n");
		printf("|%-16s |%-17s |%-15s   |%-15s  |%-10s|%-25s   |%-16.2f |%-14s |%2d%c%2d%c%4d  |%2d:%2d  |\n", tempVisitor.IC, tempVisitor.name, tempVisitor.contactNo, tempVisitor.position, tempVisitor.latestVenueVisited, tempVisitor.reason, tempVisitor.temperature, tempVisitor.gender, tempVisitor.date.day, validate1, tempVisitor.date.month, validate2, tempVisitor.date.year, tempVisitor.time.hour, tempVisitor.time.minute);
		printf("+-----------------+------------------+------------------+-----------------+----------+----------------------------+-----------------+---------------+------------+-------+\n\n\n");

		do {
			printf("Are you sure you want to add visitor? (Y = Yes | N = No) : ");//ask user want to sure add or not ,if yes the information will insert into binary file.
			rewind(stdin);
			scanf("%c", &choice);
			choice = toupper(choice);
			if (choice == 'Y') {
				visitExit.dateEnter = tempVisitor.date;
				visitExit.timeEnter = tempVisitor.time;
				strcpy(visitExit.reason, tempVisitor.reason);
				strcpy(visitExit.visitorIC, tempVisitor.IC);
				strcpy(visitExit.venueID, tempVisitor.latestVenueVisited);
				strcpy(visitExit.telNo, tempVisitor.contactNo);
				visitExit.temperature = tempVisitor.temperature;
				visitExit.timeExit.hour = 0;
				visitExit.timeExit.minute = 0;
				fwrite(&tempVisitor, sizeof(VisitorInfo), 1, fptr);//write into visitorInfo file
				fprintf(fptr2, "%02d-%02d-%-4d|%02d:%02d|%s|%s|%s|%s|%.1lf|%02d:%02d\n", visitExit.dateEnter.day, visitExit.dateEnter.month, visitExit.dateEnter.year, visitExit.timeEnter.hour, visitExit.timeEnter.minute, visitExit.reason, visitExit.visitorIC, visitExit.telNo, visitExit.venueID, visitExit.temperature, visitExit.timeExit.hour, visitExit.timeExit.minute);
			}
			else if (choice == 'N') {

				printf("Nothing has been added!\n");//if no want to add , it will not write into the file.

			}
			else
				printf("Invalid code! Please enter again.\n");

		} while (choice != 'Y' && choice != 'N');
		do {
			printf("Continue to add?(Y = Yes  | N = No)"); rewind(stdin);
			scanf("%c", &choice);
			choice = toupper(choice);
			if (choice != 'Y' && choice != 'N') {
				printf("Invalid code! Please enter again.\n");
			}

		} while (choice != 'Y' && choice != 'N');
	} while (choice == 'Y');
	fclose(fptr);
	fclose(fptr2);
}

void searchVisitor() {

	char searchName[30], selection, searchDate[15];
	int count, i = 0, j, choice;
	float searchTemperature;
	int confirm = 0;

	fptr = fopen("VisitorInfo.dat", "rb");

	if (fptr == NULL)
	{
		printf("Error");
		exit(-1);
	}

	while (!feof(fptr))
	{

		fread(&visitor[i], sizeof(VisitorInfo), 1, fptr);

		i++;
	}

	fclose(fptr);

	count = i;
	do {
		do {
			printf("++==============================++\n");//lets user choose the ways which ways they want to search
			printf("||	WAYS TO SEARCH          || \n");
			printf("++==============================++\n");
			printf("||	1. Name                 ||\n");
			printf("||	2. Temperature          || \n");
			printf("||	3. Date                 ||\n");
			printf("||	4. Exit                 ||\n");
			printf("+===============================++\n\n");

			printf("----Please enter your selection : ");
			scanf("%02d", &choice);
		} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
		system("cls");

		int countVisi = 0;

		switch (choice) {
		case 1:
		{
			printf("\n\n-----Name to search : ");
			rewind(stdin);
			scanf("%[^\n]", &searchName);

			fptr = fopen("VisitorInfo.dat", "rb");

			if (fptr == NULL)
			{
				printf("Error");
				exit(-1);
			}

			for (int a = 0; a < count; a++)
			{


				if (strcmp(searchName, visitor[a].name) == 0)//to check the search name is same with name inside visitor struct 
				{
					tepvisitor[countVisi] = visitor[a];//if yes then it will copy to the TepVisitor which is the new struct 

					countVisi++;//then count inside got how many data
				}
			}

			fclose(fptr);


			if (countVisi != 0)
				for (int z = 0; z < 1; z++)
				{
					printf("Record Found!\n===========================\n\n");
					printf("+-----------------+------------------+------------------+-----------------+----------+----------------------------+-----------------+---------------+------------+-------+\n");
					printf("|  IC             |   NAME           | CONTACT          |  POSITION       | VENUR ID |       REASON		  |  TEMPERATURE    |GENDER         | DATE       | TIME  |\n");
					printf("+-----------------+------------------+------------------+-----------------+----------+----------------------------+-----------------+---------------+------------+-------+\n");
					for (j = 0; j < countVisi; j++)
					{
						printf("|%-16s |%-17s |%-15s   |%-15s  |%-10s|%-25s   |%-16.2f |%-14s |%2d-%2d-%4d  |%2d:%2d  |\n", tepvisitor[j].IC, tepvisitor[j].name, tepvisitor[j].contactNo, tepvisitor[j].position, tepvisitor[j].latestVenueVisited, tepvisitor[j].reason, tepvisitor[j].temperature, tepvisitor[j].gender, tepvisitor[j].date.day, tepvisitor[j].date.month, tepvisitor[j].date.year, tepvisitor[j].time.hour, tepvisitor[j].time.minute);
						printf("+-----------------+------------------+------------------+-----------------+----------+----------------------------+-----------------+---------------+------------+-------+\n");
					}//will show the new struct data which is same data with the user found.

				}

			else
				printf("Record No Found! \n");

		}break;

		case 2:
		{
			printf("\n\n-----Temperature to search : ");
			rewind(stdin);
			scanf("%f", &searchTemperature);

			fptr = fopen("VisitorInfo.dat", "rb");

			if (fptr == NULL)
			{
				printf("Error");
				exit(-1);
			}

			for (int a = 0; a < count; a++)
			{


				if (searchTemperature == visitor[a].temperature)//same with the search name ways
				{
					tepvisitor[countVisi] = visitor[a];

					countVisi++;
				}
			}

			fclose(fptr);


			if (countVisi != 0)
				for (int z = 0; z < 1; z++)
				{
					printf("Record Found!\n===========================\n\n");
					printf("+-----------------+------------------+------------------+-----------------+----------+----------------------------+-----------------+---------------+------------+-------+\n");
					printf("|  IC             |   NAME           | CONTACT          |  POSITION       | VENUR ID |       REASON		  |  TEMPERATURE    |GENDER         | DATE       | TIME  |\n");
					printf("+-----------------+------------------+------------------+-----------------+----------+----------------------------+-----------------+---------------+------------+-------+\n");
					for (j = 0; j < countVisi; j++)
					{
						printf("|%-16s |%-17s |%-15s   |%-15s  |%-10s|%-25s   |%-16.2f |%-14s |%2d-%2d-%4d  |%2d:%2d  |\n", tepvisitor[j].IC, tepvisitor[j].name, tepvisitor[j].contactNo, tepvisitor[j].position, tepvisitor[j].latestVenueVisited, tepvisitor[j].reason, tepvisitor[j].temperature, tepvisitor[j].gender, tepvisitor[j].date.day, tepvisitor[j].date.month, tepvisitor[j].date.year, tepvisitor[j].time.hour, tepvisitor[j].time.minute);
						printf("+-----------------+------------------+------------------+-----------------+----------+----------------------------+-----------------+---------------+------------+-------+\n");
					}//will show the new struct data which is same data with the user found.


				}
			else
				printf("Record No Found! \n");

		}break;

		case 3:
		{
			char validate2, validate1;
			int searchDay, searchmonth, searchYear;


			do {
				printf("\n\n-----Date to search(DD-MM-YYYY) : ");
				rewind(stdin);
				scanf("%2d%c%2d%c%4d", &searchDay, &validate1, &searchmonth, &validate2, &searchYear);

				if (searchDay >= 31 || searchDay <= 0)
				{
					printf("invalid date\n");
				}
				if (searchmonth >= 13 || searchmonth <= 0)
				{
					printf("invalid month\n");
				}
			} while (searchDay >= 31 || searchDay <= 0 || searchmonth >= 13 || searchmonth <= 0);



			fptr = fopen("VisitorInfo.dat", "rb");

			if (fptr == NULL)
			{
				printf("Error");
				exit(-1);
			}

			for (int a = 0; a < count; a++)
			{


				if (searchDay == visitor[a].date.day && searchmonth == visitor[a].date.month && searchYear == visitor[a].date.year)//same with the search name ways
				{
					tepvisitor[countVisi] = visitor[a];

					countVisi++;
				}
			}

			fclose(fptr);


			if (countVisi != 0)
				for (int z = 0; z < 1; z++)
				{
					printf("Record Found!\n===========================\n\n");
					printf("+-----------------+------------------+------------------+-----------------+----------+----------------------------+-----------------+---------------+------------+-------+\n");
					printf("|  IC             |   NAME           | CONTACT          |  POSITION       | VENUR ID |       REASON		  |  TEMPERATURE    |GENDER         | DATE       | TIME  |\n");
					printf("+-----------------+------------------+------------------+-----------------+----------+----------------------------+-----------------+---------------+------------+-------+\n");
					for (j = 0; j < countVisi; j++)
					{

						printf("|%-16s |%-17s |%-15s   |%-15s  |%-10s|%-25s   |%-16.2f |%-14s |%2d-%2d-%4d  |%2d:%2d  |\n", tepvisitor[j].IC, tepvisitor[j].name, tepvisitor[j].contactNo, tepvisitor[j].position, tepvisitor[j].latestVenueVisited, tepvisitor[j].reason, tepvisitor[j].temperature, tepvisitor[j].gender, tepvisitor[j].date.day, tepvisitor[j].date.month, tepvisitor[j].date.year, tepvisitor[j].time.hour, tepvisitor[j].time.minute);
						printf("+-----------------+------------------+------------------+-----------------+----------+----------------------------+-----------------+---------------+------------+-------+\n");
					}//will show the new struct data which is same data with the user found.

				}
			else
				printf("Record No Found! \n");

		}break;

		default:
			break;
		}

		if (choice == 4) {
			break;
		}
		do {
			printf("Continue searching? (Y = Yes | N = No) : ");//ask user want to continue searching not?
			rewind(stdin);
			scanf("%c", &selection);
			selection = toupper(selection);
			if (selection != 'Y' && selection != 'N') {
				printf("Invalid code! Please enter again.\n");
			}
		} while (selection != 'Y' && selection != 'N');
		if (selection == 'Y') {
			i = 0;
			confirm++;//if y/Y ,the comfirm will become 1
			system("cls");

		}
		else if (selection == 'N') {
			i = 0;
			system("cls");
			break;//if not then back to menu
		}


	} while (confirm > 0);
}

void visitorList() {

	int i = 0, sum = 0;
	char selection;

	fptr = fopen("visitorInfo.dat", "rb");

	if (fptr == NULL) {
		printf("Error\n");
		exit(-1);
	}

	while (!feof(fptr)) {

		fread(&tepvisitor[i], sizeof(VisitorInfo), 1, fptr);//read the data inside the file

		i++;
	}

	fclose(fptr);



	printf("%100s", "---VISITOR INFORMATION---\n\n");
	printf("+-----------------+------------------+------------------+-----------------+----------+----------------------------+-----------------+---------------+------------+-------+\n");
	printf("|  IC             |   NAME           | CONTACT          |  POSITION       | VENUR ID |       REASON		  |  TEMPERATURE    |GENDER         | DATE       | TIME  |\n");
	printf("+-----------------+------------------+------------------+-----------------+----------+----------------------------+-----------------+---------------+------------+-------+\n");
	for (int j = 0; j < i - 1; j++) {

		printf("|%-16s |%-17s |%-15s   |%-15s  |%-10s|%-25s   |%-16.2f |%-14s |%2d-%2d-%4d  |%2d:%2d  |\n", tepvisitor[j].IC, tepvisitor[j].name, tepvisitor[j].contactNo, tepvisitor[j].position, tepvisitor[j].latestVenueVisited, tepvisitor[j].reason, tepvisitor[j].temperature, tepvisitor[j].gender, tepvisitor[j].date.day, tepvisitor[j].date.month, tepvisitor[j].date.year, tepvisitor[j].time.hour, tepvisitor[j].time.minute);
		printf("+-----------------+------------------+------------------+-----------------+----------+----------------------------+-----------------+---------------+------------+-------+\n");
		sum++;
	}


	printf("\n\n %d records were found\n\n", sum);

}

void modifyVisitor() {
	VisitorInfo t[100], temp;
	int mCount = 0, modifyID, u, choice4, found, countMdf = 0, namefound = 0;
	char confirm, decision2, name[50], validate1, validate2;

	FILE* fptrM1;
	fptrM1 = fopen("visitorInfo.dat", "rb");

	if (fptrM1 == NULL) {
		printf("Unable to open the file\n");
		exit(-1);
	}

	while (fread(&t[mCount], sizeof(VisitorInfo), 1, fptrM1) != 0)
		++mCount;

	fclose(fptrM1);

	printf("\nMODIFY VISITOR INFORMATION \n");
	printf("====================\n");

	do {
		do {
			printf("\nEnter NAME of the record you want to modify > ");
			rewind(stdin);
			scanf("%[^\n]", &name);

			for (u = 0; u < mCount; u++) {

				if (strcmp(name, t[u].name) == 0) {
					printf("\nRecord found\n");
					printf("------------\n");
					printf("Visitor IC         : %s\n", t[u].IC);
					printf("Visitor Name       : %s\n", t[u].name);
					printf("Visitor Contact    : %s\n", t[u].contactNo);
					printf("Position           : %s\n", t[u].position);
					printf("Venue ID           : %s\n", t[u].latestVenueVisited);
					printf("Reason             : %s\n", t[u].reason);
					printf("Temperature        : %.2f\n", t[u].temperature);
					printf("Gender             : %s\n", t[u].gender);
					printf("Date               : %d-%d-%d\n", t[u].date.day, t[u].date.month, t[u].date.year);
					printf("Time               : %d:%d\n", t[u].time.hour, t[u].time.minute);
					printf("\n");
					namefound++;
					found = u;
					temp = t[u];
				}
			}

			if (namefound == 0)
				printf("\nUnable to search the record\n");

		} while (namefound == 0);

		printf("	-------------------------------------------------\n");
		printf("	|	1.Edit visitor IC			|\n");
		printf("	|	2.Edit visitor name			|\n");
		printf("	|	3.Edit visitor contact			|\n");
		printf("	|	4.Edit visitor position			|\n");
		printf("	|	5.Edit visitor latest venue visit	|\n");
		printf("	|	6.Edit visitor reason			|\n");
		printf("	|	7.Edit visitor temperature		|\n");
		printf("	|	8.Edit visitor gender			|\n");
		printf("	|	9.Edit visitor date			|\n");
		printf("	|	10.Edit visitor time			|\n");
		printf("	|	11.Exit to visit menu			|\n");
		printf("	-------------------------------------------------\n");
		printf("	Which part of the record you want to modify > ");
		scanf("%d", &choice4);
		printf("\n");

		switch (choice4) {
		case 1:
			printf("New IC :");
			rewind(stdin);
			scanf("%[^\n]", &temp.IC);
			do {
				printf("%-30s:", "Enter Visitor IC(Including'-')"); rewind(stdin);
				scanf("%s", &temp.IC);
				if (isdigit(temp.IC[0]) == 0 || isdigit(temp.IC[1]) == 0 || isdigit(temp.IC[2]) == 0 || isdigit(temp.IC[3]) == 0 || isdigit(temp.IC[4]) == 0 || isdigit(temp.IC[5]) == 0 || isdigit(temp.IC[7]) == 0 || isdigit(temp.IC[8]) == 0 || isdigit(temp.IC[10]) == 0 || isdigit(temp.IC[11]) == 0 || isdigit(temp.IC[12]) == 0 || isdigit(temp.IC[13]) == 0) {
					printf("IC Must Be In Numeric(Inlcuding'-')\n");
				}
				else if (temp.IC[6] != '-' || temp.IC[9] != '-') {
					printf("Only '-' Available for IC Format\n");
				}
			} while (isdigit(temp.IC[0]) == 0 || isdigit(temp.IC[1]) == 0 || isdigit(temp.IC[2]) == 0 || isdigit(temp.IC[3]) == 0 || isdigit(temp.IC[4]) == 0 || isdigit(temp.IC[5]) == 0 || temp.IC[6] != '-' || isdigit(temp.IC[7]) == 0 || isdigit(temp.IC[8]) == 0 || temp.IC[9] != '-' || isdigit(temp.IC[10]) == 0 || isdigit(temp.IC[11]) == 0 || isdigit(temp.IC[12]) == 0 || isdigit(temp.IC[13]) == 0);
			break;
		case 2:
			printf("New name:");
			rewind(stdin);
			scanf("%[^\n]", &temp.name); break;

		case 3:
			do {
				printf("New contactNo:");
				rewind(stdin);
				scanf(" %[^\n]", &temp.contactNo);
				if (temp.contactNo[3] != '-') {
					printf("Only '-' Available for Tel Format\n");
				}
				else if (isdigit(temp.contactNo[0]) == 0 || isdigit(temp.contactNo[1]) == 0 || isdigit(temp.contactNo[2]) == 0 || isdigit(temp.contactNo[4]) == 0 || isdigit(temp.contactNo[5]) == 0 || isdigit(temp.contactNo[6]) == 0 || isdigit(temp.contactNo[7]) == 0 || isdigit(temp.contactNo[8]) == 0 || isdigit(temp.contactNo[9]) == 0 || (isdigit(temp.contactNo[10]) == 0 && temp.contactNo != NULL)) {
					printf("Input Must Be In Numeric(Including '-')\n");
				}

			} while (isdigit(temp.contactNo[0]) == 0 || isdigit(temp.contactNo[1]) == 0 || isdigit(temp.contactNo[2]) == 0 || isdigit(temp.contactNo[4]) == 0 || isdigit(temp.contactNo[5]) == 0 || isdigit(temp.contactNo[6]) == 0 || isdigit(temp.contactNo[7]) == 0 || isdigit(temp.contactNo[8]) == 0 || isdigit(temp.contactNo[9]) == 0 || (isdigit(temp.contactNo[10]) == 0 && temp.contactNo != NULL || temp.contactNo[3] != '-'));
			break;

		case 4:
			printf("New position :");
			rewind(stdin);
			scanf("%[^\n]", &temp.position); break;

		case 5:
			printf("New latestVenueVisited :");
			rewind(stdin);
			scanf("%[^\n]", &temp.latestVenueVisited); break;

		case 6:
			printf("New reason :");
			rewind(stdin);
			scanf("%[^\n]", &temp.reason); break;

		case 7:
			do {
				printf("New temperature :");
				rewind(stdin);
				scanf("%f", &temp.temperature);
				if (temp.temperature < 36.00 && temp.temperature>40.00)
				{
					printf("Please insert again.\n");
				}
			} while (temp.temperature < 36.00 && temp.temperature>40.00);
			break;
		case 8:
			printf("New gender :");
			rewind(stdin);
			scanf("%[^\n]", &temp.gender); break;

		case 9:
			do {
				printf("New date :");
				rewind(stdin);
				scanf("%2d%c%2d%c%4d", &temp.date.day, &validate1, &temp.date.month, &validate2, &temp.date.year);
				if (temp.date.day >= 31 || temp.date.day <= 0)
				{
					printf("invalid date\n");
				}
				if (temp.date.month >= 13 || temp.date.month <= 0)
				{
					printf("invalid month\n");
				}
			} while (temp.date.month >= 31 || temp.date.day <= 0 || temp.date.month >= 13 || temp.date.day <= 0); break;

		case 10:
			do {
				printf(" time (hh:mm) : ");
				rewind(stdin);
				scanf("%2d%c%2d", &temp.time.hour, &validate2, &temp.time.minute);
				if (temp.time.hour >= 25 || temp.time.hour < 0)
				{
					printf("invalid hour!\n");
				}
				else if (temp.time.minute >= 60 || temp.time.minute < 0)
				{
					printf("invalid minute!\n");
				}

			} while (temp.time.minute >= 60 || temp.time.hour < 0 || temp.time.hour >= 25 || temp.time.minute < 0); break;

		case 11:
		{
			break;
		}
		default:
			printf("Which part of the record you want to modify > \n");
			scanf("%d", &choice4);
			printf("\n");
		}
		if (choice4 == 11) {
			break;
		}

		printf("\nSure to modify? (Y = Yes | N = No) > ");
		rewind(stdin);
		scanf("%c", &confirm);

		if (toupper(confirm) == 'Y') {
			t[found] = temp;
			++countMdf;

			printf("MODIFY SUCCESFUL!\n\n");
			printf("Visitor IC         : %s\n", t[found].IC);
			printf("Visitor Name       : %s\n", t[found].name);
			printf("Visitor Contact    : %s\n", t[found].contactNo);
			printf("Position           : %s\n", t[found].position);
			printf("Venue ID           : %s\n", t[found].latestVenueVisited);
			printf("Reason             : %s\n", t[found].reason);
			printf("Temperature        : %.2f\n", t[found].temperature);
			printf("Gender             : %s\n", t[found].gender);
			printf("Date               : %d-%d-%d\n", t[found].date.day, t[found].date.month, t[found].date.year);
			printf("Time               : %d:%d\n", t[found].time.hour, t[found].time.minute);
		}

		else
			printf("UNSUCCESFUL!\n");

		printf("\n< %d records modified \n", countMdf);
		printf("\nContinue? (Y = Yes | N = No) > ");
		rewind(stdin);
		scanf("%c", &decision2);


	} while (toupper(decision2) == 'Y');


	if (countMdf > 0) {
		FILE* fptrM2;
		fptrM2 = fopen("visitorInfo.dat", "wb");

		if (fptrM2 == NULL) {
			printf("Unable to open the file\n");
			exit(-1);
		}

		for (u = 0; u < mCount; u++) {
			fwrite(&t[u], sizeof(VisitorInfo), 1, fptrM2);
		}

		fclose(fptrM2);
	}

}

void deleteVisitor() {
	VisitorInfo v[100];
	int dCount = 0, u, find;
	char confirm2, name[50];

	FILE* fptr3 = fopen("visitorInfo.dat", "rb");
	if (!fptr3) {
		printf("Unable to open the file\n");
		exit(-1);
	}

	while (fread(&v[dCount], sizeof(VisitorInfo), 1, fptr3) != 0)
		dCount++;

	fclose(fptr3);

	printf("\nDelete Visitor Information\n");
	printf("====================\n");

	printf("Enter name you want to delete > ");
	rewind(stdin);
	scanf("%[^\n]", &name);

	for (u = 0; u < dCount; u++) {

		if (strcmp(name, v[u].name) == 0) {
			printf("\nRecord found\n");
			printf("------------\n");
			printf("Visitor IC         : %s\n", v[u].IC);
			printf("Visitor Name       : %s\n", v[u].name);
			printf("Visitor Contact    : %s\n", v[u].contactNo);
			printf("Position           : %s\n", v[u].position);
			printf("Venue ID: %s\n", v[u].latestVenueVisited);
			printf("Reason             : %s\n", v[u].reason);
			printf("Temperature        : %.2f\n", v[u].temperature);
			printf("Gender             : %s\n", v[u].gender);
			printf("Date               : %d-%d-%d\n", v[u].date.day, v[u].date.month, v[u].date.year);
			printf("Time               : %d:%d\n", v[u].time.hour, v[u].time.minute);

			printf("\nSure to delete? (Y = Yes | N = No) > ");
			rewind(stdin);
			scanf("%c", &confirm2);
			confirm2 = toupper(confirm2);

			if (confirm2 == 'Y') {
				dCount -= 1;

				for (int d = u; d < dCount; d++) {
					v[d] = v[d + 1];
				}
			}

		}
	}

	fptr3 = fopen("visitorInfo.dat", "wb");
	if (!fptr3) {
		printf("Unable to open the file\n");
		exit(-1);
	}

	for (int a = 0; a < dCount; a++) {
		fwrite(&v[a], sizeof(VisitorInfo), 1, fptr3);
	}

	fclose(fptr3);
}

void reportVisitor() {
	VisitorInfo vt[100];
	int numRecords = 0, numTem = 0, arrayTem, countTemp = 0, report;
	float highestTem = 0, lowestTem = 0;
	FILE* ptrV;
	ptrV = fopen("visitorInfo.dat", "rb");

	if (ptrV == NULL)
	{
		printf("Unable to open the file.");
		exit(-1);
	}

	while (!feof(ptrV))
	{
		fread(&vt[numRecords], sizeof(VisitorInfo), 1, ptrV);
		numRecords++;
	}
	fclose(ptrV);
	arrayTem = numRecords;
	numRecords = numRecords - 1;


	do {
		system("cls");
		printf("%19s++==================================++\n", "");//lets user choose the ways which ways they want to search
		printf("%19s||	REPORT OF VISITOR INFORMATION  || \n", "");
		printf("%19s++==================================++\n", "");
		printf("%19s||	1. By Month                    ||\n", "");
		printf("%19s||	2. By Highest Temperature      || \n", "");
		printf("%19s||	3. Exit                        ||\n", "");
		printf("%19s+===================================++\n\n", "");

		printf("Your Selection ? :");
		scanf("%d", &report);
	} while (report != 1 && report != 2 && report != 3);

	if (report == 1)
	{
		printf("There got %d person entered the school .\n\n\n", numRecords);


		int jan = 0, feb = 0, mar = 0, apr = 0, may = 0, jun = 0, jul = 0, aug = 0, sep = 0, oct = 0, nov = 0, dec = 0, calVst = 0, year = 2020;


		printf(" Visitor On Year 2021 . \n\n\n");
		for (int m = 0; m < numRecords; m++)
		{
			if (vt[m].date.month == 1) {
				visitor[calVst] = vt[m];
				jan++;
			}
			if (vt[m].date.month == 2) {
				visitor[calVst] = vt[m];
				feb++;
			}
			if (vt[m].date.month == 3) {
				visitor[calVst] = vt[m];
				mar++;
			}
			if (vt[m].date.month == 4) {
				visitor[calVst] = vt[m];
				apr++;
			}
			if (vt[m].date.month == 5) {
				visitor[calVst] = vt[m];
				may++;
			}
			if (vt[m].date.month == 6) {
				visitor[calVst] = vt[m];
				jun++;
			}
			if (vt[m].date.month == 7) {
				visitor[calVst] = vt[m];
				jul++;
			}
			if (vt[m].date.month == 8) {
				visitor[calVst] = vt[m];
				aug++;
			}
			if (vt[m].date.month == 9) {
				visitor[calVst] = vt[m];
				sep++;
			}
			if (vt[m].date.month == 10) {
				visitor[calVst] = vt[m];
				oct++;
			}
			if (vt[m].date.month == 11) {
				visitor[calVst] = vt[m];
				nov++;
			}
			if (vt[m].date.month == 12) {
				visitor[calVst] = vt[m];
				dec++;
			}

		}


		if (jan != 0)
		{

			for (int o = 0; o < 1; o++)
			{
				printf("	JANUARY :\n");
				printf("	+--------------------------------+-------------+\n");
				printf("	| %-25s	 | %-15s	\n", "NAME", "TEMPERATURE |");
				printf("	+--------------------------------+-------------+\n");
				for (int p = 0; p < numRecords; p++) {
					if (vt[p].date.month == 1)
					{
						for (int y = 0; y < 1; y++)
						{
							printf("	| %-25s	 |%.2f        |\n", vt[p].name, vt[p].temperature);
							printf("	+--------------------------------+-------------+\n");
						}


					}
				}
			}
		}
		if (feb != 0)
		{

			for (int o = 0; o < 1; o++)
			{
				printf("\n\n	FEBUARY :\n");
				printf("	+--------------------------------+-------------+\n");
				printf("	| %-25s	 | %-15s	\n", "NAME", "TEMPERATURE |");
				printf("	+--------------------------------+-------------+\n");

				for (int p = 0; p < numRecords; p++) {
					if (vt[p].date.month == 2)
					{
						for (int y = 0; y < 1; y++)
						{
							printf("	| %-25s	 |%.2f        |\n", vt[p].name, vt[p].temperature);
							printf("	+--------------------------------+-------------+\n");
						}
					}
				}
			}
		}
		if (mar != 0)
		{

			for (int o = 0; o < 1; o++)
			{
				printf("\n\n	MARCH :\n");
				printf("	+--------------------------------+-------------+\n");
				printf("	| %-25s	 | %-15s	\n", "NAME", "TEMPERATURE |");
				printf("	+--------------------------------+-------------+\n");

				for (int p = 0; p < numRecords; p++) {
					if (vt[p].date.month == 3)
					{
						for (int y = 0; y < 1; y++)
						{
							printf("	| %-25s	 |%.2f        |\n", vt[p].name, vt[p].temperature);
							printf("	+--------------------------------+-------------+\n");
						}
					}
				}
			}
		}
		if (apr != 0)
		{

			for (int o = 0; o < 1; o++)
			{
				printf("\n\n	APRIL :\n");
				printf("	+--------------------------------+-------------+\n");
				printf("	| %-25s	 | %-15s	\n", "NAME", "TEMPERATURE |");
				printf("	+--------------------------------+-------------+\n");

				for (int p = 0; p < numRecords; p++) {
					if (vt[p].date.month == 4)
					{
						for (int y = 0; y < 1; y++)
						{
							printf("	| %-25s	 |%.2f        |\n", vt[p].name, vt[p].temperature);
							printf("	+--------------------------------+-------------+\n");
						}

					}
				}
			}
		}
		if (may != 0)
		{

			for (int o = 0; o < 1; o++)
			{
				printf("\n\n	MAY :\n");
				printf("	+--------------------------------+-------------+\n");
				printf("	| %-25s	 | %-15s	\n", "NAME", "TEMPERATURE |");
				printf("	+--------------------------------+-------------+\n");

				for (int p = 0; p < numRecords; p++) {
					if (vt[p].date.month == 5)
					{
						for (int y = 0; y < 1; y++)
						{
							printf("	| %-25s	 |%.2f        |\n", vt[p].name, vt[p].temperature);
							printf("	+--------------------------------+-------------+\n");
						}

					}
				}
			}
		}
		if (jun != 0)
		{

			for (int o = 0; o < 1; o++)
			{
				printf("\n\n	JUNE :\n");
				printf("	+--------------------------------+-------------+\n");
				printf("	| %-25s	 | %-15s	\n", "NAME", "TEMPERATURE |");
				printf("	+--------------------------------+-------------+\n");

				for (int p = 0; p < numRecords; p++) {
					if (vt[p].date.month == 6)
					{
						for (int y = 0; y < 1; y++)
						{
							printf("	| %-25s	 |%.2f        |\n", vt[p].name, vt[p].temperature);
							printf("	+--------------------------------+-------------+\n");
						}
					}
				}
			}
		}
		if (jul != 0)
		{

			for (int o = 0; o < 1; o++)
			{
				printf("\n\n	JULY :\n");
				printf("	+--------------------------------+-------------+\n");
				printf("	| %-25s	 | %-15s	\n", "NAME", "TEMPERATURE |");
				printf("	+--------------------------------+-------------+\n");

				for (int p = 0; p < numRecords; p++) {
					if (vt[p].date.month == 7)
					{
						for (int y = 0; y < 1; y++)
						{
							printf("	| %-25s	 |%.2f        |\n", vt[p].name, vt[p].temperature);
							printf("	+--------------------------------+-------------+\n");
						}
					}
				}
			}
		}
		if (aug != 0)
		{

			for (int o = 0; o < 1; o++)
			{
				printf("\n\n	AUGUST :\n");
				printf("	+--------------------------------+-------------+\n");
				printf("	| %-25s	 | %-15s	\n", "NAME", "TEMPERATURE |");
				printf("	+--------------------------------+-------------+\n");

				for (int p = 0; p < numRecords; p++) {
					if (vt[p].date.month == 8)
					{
						for (int y = 0; y < 1; y++)
						{
							printf("	| %-25s	 |%.2f        |\n", vt[p].name, vt[p].temperature);
							printf("	+--------------------------------+-------------+\n");
						}

					}
				}
			}
		}
		if (sep != 0)
		{

			for (int o = 0; o < 1; o++)
			{
				printf("\n\n	SEPTEMBER :\n");
				printf("	+--------------------------------+-------------+\n");
				printf("	| %-25s	 | %-15s	\n", "NAME", "TEMPERATURE |");
				printf("	+--------------------------------+-------------+\n");

				for (int p = 0; p < numRecords; p++) {
					if (vt[p].date.month == 9)
					{
						for (int y = 0; y < 1; y++)
						{
							printf("	| %-25s	 |%.2f        |\n", vt[p].name, vt[p].temperature);
							printf("	+--------------------------------+-------------+\n");
						}
					}
				}
			}
		}
		if (oct != 0)
		{

			for (int o = 0; o < 1; o++)
			{
				printf("\n\n	OCTOBER :\n");
				printf("	+--------------------------------+-------------+\n");
				printf("	| %-25s	 | %-15s	\n", "NAME", "TEMPERATURE |");
				printf("	+--------------------------------+-------------+\n");

				for (int p = 0; p < numRecords; p++) {
					if (vt[p].date.month == 10)
					{
						for (int y = 0; y < 1; y++)
						{
							printf("	| %-25s	 |%.2f        |\n", vt[p].name, vt[p].temperature);
							printf("	+--------------------------------+-------------+\n");
						}
					}
				}
			}
		}
		if (nov != 0)
		{

			for (int o = 0; o < 1; o++)
			{
				printf("\n\n	NOVEMBER :\n");
				printf("	+--------------------------------+-------------+\n");
				printf("	| %-25s	 | %-15s	\n", "NAME", "TEMPERATURE |");
				printf("	+--------------------------------+-------------+\n");

				for (int p = 0; p < numRecords; p++) {
					if (vt[p].date.month == 11)
					{
						for (int y = 0; y < 1; y++)
						{
							printf("	| %-25s	 |%.2f        |\n", vt[p].name, vt[p].temperature);
							printf("	+--------------------------------+-------------+\n");
						}
					}
				}
			}
		}
		if (dec != 0)
		{

			for (int o = 0; o < 1; o++)
			{
				printf("\n\n	DECEMBER :\n");
				printf("	+--------------------------------+-------------+\n");
				printf("	| %-25s	 | %-15s	\n", "NAME", "TEMPERATURE |");
				printf("	+--------------------------------+-------------+\n");

				for (int p = 0; p < numRecords; p++) {
					if (vt[p].date.month == 12)
					{
						for (int y = 0; y < 1; y++)
						{
							printf("	| %-25s	 |%.2f        |\n", vt[p].name, vt[p].temperature);
							printf("	+--------------------------------+-------------+\n");
						}

					}
				}
			}
		}

	}

	printf("\n\n\n");

	if (report == 2)
	{
		for (int j = 0; j < numRecords; j++)
		{

			if (vt[j].temperature >= highestTem)
			{
				highestTem = vt[j].temperature;
			}


		}
		for (int z = 0; z < numRecords; z++)
		{
			if (highestTem == vt[z].temperature)
			{
				visitor[countTemp] = vt[z];
				countTemp++;
			}
		}

		printf("\n\nThe highest temperature is %.2f\n\n", highestTem);
		if (countTemp != 0)
		{
			for (int l = 0; l < 1; l++)
			{
				printf("	+------------------------------------------------------+\n");
				printf("	| %-20s    |%-10s	 |%-10s   |\n", "NAME", "DATE", "TINE");
				printf("	+------------------------------------------------------+\n");
			}
			for (int s = 0; s < countTemp; s++)
			{
				printf("	| %-15s         |%2d%c%2d%c%2d    |%2d:%2d        |\n", visitor[s].name, visitor[s].date.day, '-', visitor[s].date.month, '-', visitor[s].date.year, visitor[s].time.hour, visitor[s].time.minute);
				printf("	+------------------------------------------------------+\n");
				numTem++;
			}

		}
		printf("\n\nThere got %d person who had the highest temperature is %.2f\n\n", numTem, highestTem);
	}
	printf("\n\nNOTICE!!\nIf there are many visitor's temperature is more than or equal 37.\nBE CAREFUL\nThey cannot enter into TARUC\n");

	if (report == 3) {
		system("cls");
	}
	fclose(ptrV);
}

int staffMenu1() {
	int choice1;
	char menu1;

	do {
		system("cls");
		heading();
		printf("%19s==================================\n", "");
		printf("%19s||  Administrative Staff Module ||\n", "");
		printf("%19s||------------------------------||\n", "");
		printf("%19s|| 1. Add New Staff Details     ||\n%19s|| 2. Staff Login [MENU 2]      ||\n%19s|| 3. Display Staff Details     ||\n%19s|| 4. Exits                     ||\n", "", "", "", "");
		printf("%19s==================================\n", "");
		printf("----Please enter your selection : ");
		scanf("%d", &choice1);

		if (choice1 == 2)
			staffLogin();

		switch (choice1) {
		case 1:
			addStaff(); break;
		case 3:
			displayStaff(); break;
		default:
			exit(-1);
		}

		printf("\nDo you want back to MENU 1? (Y = Yes | N = No) > ");
		rewind(stdin);
		scanf("%c", &menu1);
		menu1 = toupper(menu1);
		printf("\n");

	} while (menu1 == 'Y');
}

void addStaff() {
	int calGender;
	char decision1;

	FILE* fptrS;
	fptrS = fopen("staff.dat", "ab");

	if (fptrS == NULL) {
		printf("Unable to open the file\n");
		exit(-1);
	}

	do {
		system("cls");

		printf("==================================\n");
		printf("||         ADD NEW STAFF        ||\n");
		printf("==================================\n\n");

		printf("Enter staff ID (-1 back to MENU 1) > ");
		rewind(stdin);
		scanf("%d", &s.staffID);

		if (s.staffID == -1) {
			printf("\n");
			system("cls");
			staffMenu1();
		}

		printf("Enter staff name > ");
		rewind(stdin);
		scanf("%[^\n]", &s.staffName);
		printf("Enter staff IC > ");
		rewind(stdin);
		scanf("%[^\n]", &s.staffIC);

		do {
			printf("Enter staff gender (M/F) > ");
			rewind(stdin);
			scanf("%c", &s.staffGender);
			s.staffGender = toupper(s.staffGender);
		} while (s.staffGender != 'M' && s.staffGender != 'F');

		printf("Enter staff position > ");
		rewind(stdin);
		scanf("%[^\n]", &s.staffPosition);
		printf("Enter staff faculty > ");
		rewind(stdin);
		scanf("%[^\n]", &s.faculty);
		printf("Enter password > ");
		rewind(stdin);
		scanf("%d", &s.password);
		printf("Enter contact number > ");
		rewind(stdin);
		scanf("%d", &s.contactNo);

		fwrite(&s, sizeof(Staff), 1, fptrS);

		do {
			printf("\nDo you want to continue? (Y = Yes | N = No) > ");
			rewind(stdin);
			scanf("%c", &decision1);
			decision1 = toupper(decision1);

		} while (decision1 != 'Y' && decision1 != 'N');

	} while (decision1 == 'Y');

	fclose(fptrS);
}

void staffLogin() {
	int id, pw, i = 0, count1 = 0, logout = 0;

	FILE* fptrL;
	fptrL = fopen("staff.dat", "rb");

	if (fptrL == NULL) {
		printf("Unable to open the file\n");
		exit(-1);
	}

	while (!feof(fptrL)) {
		fread(&tempStaff1[i], sizeof(Staff), 1, fptrL);
		i++;
	}

	count1 = i;

	system("cls");
	do {
		printf("==================================\n");
		printf("||         STAFF LOGIN          ||\n");
		printf("==================================\n\n");

		printf("Enter staff ID (-1 back to MENU 1) > ");
		rewind(stdin);
		scanf("%d", &id);

		if (id == -1) {
			printf("\n");

			staffMenu1();
		}

		if (checkID(id) == 1) {

			for (int j = 0; j < count1; j++) {

				if (id == tempStaff1[j].staffID) {

					do {
						printf("Enter password > ");
						rewind(stdin);
						scanf("%d", &pw);

						if (pw == tempStaff1[j].password) {
							printf("\nLOGIN SUCCESFUL!");

							logout = staffMenu2();
						}

						else
							printf("\nIncorrect Password!\n\n");

						if (logout == 1) break;

					} while (pw != tempStaff1[j].password);
				}
			}
		}

		else
			printf("\nIncorrect Id!\n\n");

	} while (checkID(id) != 1);

	fclose(fptrL);
}

int checkID(int id) {
	int count = 0, num, i = 0;

	FILE* fptrL;
	fptrL = fopen("staff.dat", "rb");

	while (!feof(fptrL)) {
		fread(&tempStaff1[i], sizeof(Staff), 1, fptrL);
		i++;
	}

	count = i;

	for (int a = 0; a < count; a++) {

		if (id == tempStaff1[a].staffID)
			return num = 1;
	}

	return num = 0;
}

int staffMenu2() {
	int choice2;
	char menu2;

	do {
		do {
			system("cls");
			heading();

			printf("%19s==================================\n", "");
			printf("%19s||         Staff Logined        ||\n", "");
			printf("%19s||------------------------------||\n", "");
			printf("%19s|| 1. Search Staff Details      ||\n%19s|| 2. Modify Staff Details      ||\n%19s|| 3. Delete Staff Details      ||\n%19s|| 4. Log Out                   ||\n", "", "", "", "");
			printf("%19s==================================\n", "");
			printf("----Please enter your selection : ");
			scanf("%d", &choice2);

			switch (choice2) {
			case 1:
				searchStaff(); break;
			case 2:
				modifyStaff(); break;
			case 3:
				deleteStaff(); break;
			case 4:
				system("cls");
				printf("LOG OUT SUCCESFUL!\n\n");
				staffMenu1(); break;
			default:
				printf("\nInvalid choice\n");
			}
		} while (choice2 < 1 || choice2 > 4);

		printf("\nDo you want back to MENU 2? (Y = Yes | N = No) > ");
		rewind(stdin);
		scanf("%c", &menu2);

	} while (menu2 == 'Y' || menu2 == 'y');
}

void searchStaff() {
	Staff tempStaff2[100];
	Staff tempStaff3[100];

	int searchID, i = 0, count3 = 0, choice3, searchStaff = 0, j = 0;
	char searchName[20], searchIC[13];

	FILE* fptrH;
	fptrH = fopen("staff.dat", "rb");

	if (fptrH == NULL) {
		printf("Unable to open the file\n");
		exit(-1);
	}

	while (!feof(fptrH)) {
		fread(&tempStaff1[i], sizeof(Staff), 1, fptrH);
		i++;
	}

	fclose(fptrH);

	count3 = i;

	do {
		system("cls");

		printf("==================================\n");
		printf("||     SEARCH STAFF DETAILS     ||\n");
		printf("||------------------------------||\n");
		printf("|| 1. Staff ID                  ||\n|| 2. Staff Name                ||\n|| 3. Staff IC                  ||\n|| -1 Back                      ||\n");
		printf("==================================\n\n");

		printf("Which part of the record you want to search > ");
		rewind(stdin);
		scanf("%d", &choice3);

		if (choice3 == -1)
			break;

		if (choice3 == 1) {

			do {
				printf("\nEnter STAFF ID of the record you want to search > ");
				rewind(stdin);
				scanf("%d", &searchID);

				for (int a = 0; a < count3; a++) {

					if (searchID == tempStaff1[a].staffID) {
						tempStaff3[searchStaff] = tempStaff1[a];

						searchStaff++;
					}
				}

				if (searchStaff != 0) {

					for (int z = 0; z < 1; z++) {
						printf("+----------+------------+--------------+--------+----------------+---------+----------+----------------+\n");
						printf("| Staff ID | Staff Name |   Staff IC   | Gender | Staff Position | Faculty | Password | Contact Number |\n");
						printf("+----------+------------+--------------+--------+----------------+---------+----------+----------------+\n");

						for (j = 0; j < searchStaff; j++) {
							printf("| %-8d | %-10s | %-12s | %-6c | %-14s | %-7s | %-8d | 0%-13d |\n", tempStaff3[j].staffID, tempStaff3[j].staffName, tempStaff3[j].staffIC, tempStaff3[j].staffGender, tempStaff3[j].staffPosition, tempStaff3[j].faculty, tempStaff3[j].password, tempStaff3[j].contactNo);
							printf("+----------+------------+--------------+--------+----------------+---------+----------+----------------+\n");
						}
					}
				}

				else
					printf("\nUnable to search the record\n");

			} while (searchStaff == 0);
		}

		else if (choice3 == 2) {
			do {
				printf("\nEnter STAFF NAME of the record you want to search > ");
				rewind(stdin);
				scanf("%[^\n]", &searchName);

				for (int a = 0; a < count3; a++) {

					if (strcmp(searchName, tempStaff1[a].staffName) == 0) {
						tempStaff3[searchStaff] = tempStaff1[a];

						searchStaff++;
					}
				}

				if (searchStaff != 0) {

					for (int z = 0; z < 1; z++) {
						printf("+----------+------------+--------------+--------+----------------+---------+----------+----------------+\n");
						printf("| Staff ID | Staff Name |   Staff IC   | Gender | Staff Position | Faculty | Password | Contact Number |\n");
						printf("+----------+------------+--------------+--------+----------------+---------+----------+----------------+\n");

						for (j = 0; j < searchStaff; j++) {
							printf("| %-8d | %-10s | %-12s | %-6c | %-14s | %-7s | %-8d | 0%-13d |\n", tempStaff3[j].staffID, tempStaff3[j].staffName, tempStaff3[j].staffIC, tempStaff3[j].staffGender, tempStaff3[j].staffPosition, tempStaff3[j].faculty, tempStaff3[j].password, tempStaff3[j].contactNo);
						}
					}
				}

				else
					printf("\nUnable to search the record!\n");

			} while (searchStaff == 0);
		}

		else if (choice3 == 3) {
			do {
				printf("\nEnter STAFF IC of the record you want to search > ");
				rewind(stdin);
				scanf("%[^\n]", &searchIC);

				for (int a = 0; a < count3; a++) {
					if (strcmp(searchIC, tempStaff1[a].staffIC) == 0) {
						tempStaff3[searchStaff] = tempStaff1[a];

						searchStaff++;
					}
				}

				if (searchStaff != 0) {
					for (int z = 0; z < 1; z++) {
						printf("+----------+------------+--------------+--------+----------------+---------+----------+----------------+\n");
						printf("| Staff ID | Staff Name |   Staff IC   | Gender | Staff Position | Faculty | Password | Contact Number |\n");
						printf("+----------+------------+--------------+--------+----------------+---------+----------+----------------+\n");

						for (j = 0; j < searchStaff; j++) {
							printf("| %-8d | %-10s | %-12s | %-6c | %-14s | %-7s | %-8d | 0%-13d |\n", tempStaff3[j].staffID, tempStaff3[j].staffName, tempStaff3[j].staffIC, tempStaff3[j].staffGender, tempStaff3[j].staffPosition, tempStaff3[j].faculty, tempStaff3[j].password, tempStaff3[j].contactNo);
						}
					}
				}

				else
					printf("\nUnable to search the record\n");

			} while (searchStaff == 0);
		}

		else
			printf("\nInvalid choice!\n\n");

	} while (choice3 < 1 || choice3 > 3);

	fclose(fptrH);
}

void modifyStaff() {
	Staff m[20], temp;
	int mCount = 0, modifyID, u, countMdf1 = 0, choice4, found, countMdf2 = 0;
	char confirm1, decision2;

	FILE* fptrM1;
	fptrM1 = fopen("staff.dat", "rb");

	if (fptrM1 == NULL) {
		printf("Unable to open the file\n");
		exit(-1);
	}

	while (fread(&m[mCount], sizeof(Staff), 1, fptrM1) != 0)
		++mCount;

	fclose(fptrM1);

	do {
		system("cls");

		do {
			printf("==================================\n");
			printf("||     MODIFY STAFF DETAILS     ||\n");
			printf("==================================\n\n");

			printf("Enter STAFF ID of the record you want to modify (-1 back to MENU 2) > ");
			scanf("%d", &modifyID);

			if (modifyID == -1) {
				system("cls");
				staffMenu2();
			}

			for (u = 0; u < mCount; u++) {

				if (m[u].staffID == modifyID) {
					printf("\nRecord found\n");
					printf("------------\n");
					printf("Staff ID       : %d\n", m[u].staffID);
					printf("Staff Name     : %s\n", m[u].staffName);
					printf("Staff IC       : %s\n", m[u].staffIC);
					printf("Gender         : %c\n", m[u].staffGender);
					printf("Position       : %s\n", m[u].staffPosition);
					printf("Faculty        : %s\n", m[u].faculty);
					printf("Password       : %d\n", m[u].password);
					printf("Contact number : 0%d\n", m[u].contactNo);
					printf("\n");

					countMdf1++;
					found = u;
					temp = m[u];
				}
			}

			if (countMdf1 == 0)
				printf("\nUnable to search the record\n");

		} while (countMdf1 == 0);

		printf("+--------------------------------+\n");
		printf("| 1. Staff ID                    |\n| 2. Staff Name                  |\n| 3. Staff IC                    |\n| 4. Staff Gender                |\n| 5. Staff Position              |\n| 6. Staff Faculty               |\n| 7. Staff Password              |\n| 8. Staff Contact Number        |\n");
		printf("+--------------------------------+\n");
		printf("Which part of the record you want to modify > ");
		scanf("%d", &choice4);
		printf("\n");

		switch (choice4) {
		case 1:
			printf("New staff ID > ");
			scanf("%d", &temp.staffID); break;
		case 2:
			printf("New staff name > ");
			rewind(stdin);
			scanf("%[^\n]", &temp.staffName); break;
		case 3:
			printf("New staff IC > ");
			rewind(stdin);
			scanf("%[^\n]", &temp.staffIC); break;
		case 4:
			printf("New gender > ");
			rewind(stdin);
			scanf("%c", &temp.staffGender); break;
		case 5:
			printf("New position > ");
			rewind(stdin);
			scanf("%[^\n]", &temp.staffPosition); break;
		case 6:
			printf("New faculty > ");
			rewind(stdin);
			scanf("%[^\n]", &temp.faculty); break;
		case 7:
			printf("New password > ");
			scanf("%d", &temp.password); break;
		case 8:
			printf("New contact number > ");
			scanf("%d", &temp.contactNo); break;
		default:
			printf("Which part of the record you want to modify > \n");
			scanf("%d", &choice4);
			printf("\n");
		}

		printf("\nSure to modify? (Y = Yes | N = No) > ");
		rewind(stdin);
		scanf("%c", &confirm1);

		if (toupper(confirm1) == 'Y') {
			m[found] = temp;
			++countMdf2;

			printf("\nMODIFY SUCCESFUL!\n\n");
			printf("Staff ID       : %d\n", m[found].staffID);
			printf("Staff Name     : %s\n", m[found].staffName);
			printf("Staff IC       : %s\n", m[found].staffIC);
			printf("Gender         : %c\n", m[found].staffGender);
			printf("Position       : %s\n", m[found].staffPosition);
			printf("Faculty        : %s\n", m[found].faculty);
			printf("Password       : %d\n", m[found].password);
			printf("Contact number : 0%d\n", m[found].contactNo);
		}

		else
			printf("\nUNSUCCESFUL!\n");

		printf("\n< %d records modified >\n", countMdf2);
		printf("\nContinue? (Y = Yes | N = No) > ");
		rewind(stdin);
		scanf("%c", &decision2);

	} while (toupper(decision2) == 'Y');

	if (countMdf2 > 0) {
		FILE* fptrM2;
		fptrM2 = fopen("staff.dat", "wb");

		if (fptrM2 == NULL) {
			printf("Unable to open the file\n");
			exit(-1);
		}

		for (u = 0; u < mCount; u++) {
			fwrite(&m[u], sizeof(Staff), 1, fptrM2);
		}

		fclose(fptrM2);
	}
}

void deleteStaff() {
	Staff d[20];
	int dCount = 0, u, find;
	char confirm2;

	FILE* fptr3 = fopen("staff.dat", "rb");
	if (!fptr3) {
		printf("Unable to open the file\n");
		exit(-1);
	}

	while (fread(&d[dCount], sizeof(Staff), 1, fptr3) != 0)
		dCount++;

	fclose(fptr3);

	system("cls");

	printf("==================================\n");
	printf("||     DELETE STAFF DETAILS     ||\n");
	printf("==================================\n\n");

	printf("Enter STAFF ID you want to delete (-1 back to MENU 2) > ");
	scanf("%d", &find);

	if (find == -1) {
		system("cls");
		staffMenu2();
	}

	for (u = 0; u < dCount; u++) {

		if (find == d[u].staffID) {
			printf("\nRecord found\n");
			printf("------------\n");
			printf("Staff ID       : %d\n", d[u].staffID);
			printf("Staff Name     : %s\n", d[u].staffName);
			printf("Staff IC       : %s\n", d[u].staffIC);
			printf("Gender         : %c\n", d[u].staffGender);
			printf("Position       : %s\n", d[u].staffPosition);
			printf("Faculty        : %s\n", d[u].faculty);
			printf("Password       : %d\n", d[u].password);
			printf("Contact number : 0%d\n", d[u].contactNo);

			printf("\nSure to delete? (Y = Yes | N = No) > ");
			rewind(stdin);
			scanf("%c", &confirm2);
			confirm2 = toupper(confirm2);

			if (confirm2 == 'Y') {
				dCount -= 1;

				for (int v = u; v < dCount; v++) {
					d[v] = d[v + 1];
				}
			}
		}
	}

	fptr3 = fopen("staff.dat", "wb");
	if (!fptr3) {
		printf("Unable to open the file\n");
		exit(-1);
	}

	for (int a = 0; a < dCount; a++) {
		fwrite(&d[a], sizeof(Staff), 1, fptr3);
	}

	fclose(fptr3);

	displayStaff();
}

void displayStaff() {
	int countRec = 0;

	FILE* fptrD;
	fptrD = fopen("staff.dat", "rb");

	if (fptrD == NULL) {
		printf("Unable to open the file\n");
		exit(-1);
	}

	printf("==================================\n");
	printf("||    DISPLAY STAFF DETAILS     ||\n");
	printf("==================================\n\n");

	printf("+----------+------------+--------------+--------+----------------+---------+----------+----------------+\n");
	printf("| Staff ID | Staff Name |   Staff IC   | Gender | Staff Position | Faculty | Password | Contact Number |\n");
	printf("+----------+------------+--------------+--------+----------------+---------+----------+----------------+\n");

	while (fread(&s, sizeof(Staff), 1, fptrD) != 0) {
		printf("| %-8d | %-10s | %-12s | %-6c | %-14s | %-7s | %-8d | 0%-13d |\n", s.staffID, s.staffName, s.staffIC, s.staffGender, s.staffPosition, s.faculty, s.password, s.contactNo);
		++countRec;
	}

	printf("+----------+------------+--------------+--------+----------------+---------+----------+----------------+\n");
	printf("\n< %d record(s) listed >\n", countRec);

	fclose(fptrD);
}


void heading() {//Header & Logo
	printf("  =======================================================================\n");
	printf("[]     +++ + +++    ++++++     ++ ++ ++       +       +     ++ ++ ++     []\n");
	printf("[]         +       +      +    +       +      +       +    +             []\n");
	printf("[]         +       +      +    +        +     +       +    +             []\n");
	printf("[]         +       +      +    +       +      +       +    +             []\n");
	printf("[]         +       ++ ++ ++    ++ ++ +        +       +    +             []\n");
	printf("[]         +       +      +    +      +       +       +    +             []\n");
	printf("[]         +       +      +    +       +      +       +    +             []\n");
	printf("[]         +       +      +    +       +       + +++ +      ++ ++ ++     []\n");
	printf("  =======================================================================\n");

	printf("%19s[]=[]=[]=[]=[]=[]=[]=[]=[]=[]=[]=[]\n", "");
	printf("%19s||                               ||\n", "");
	printf("%19s||     CONTACT-TRACING SYSTEM    ||\n", "");
	printf("%19s||                               ||\n", "");
	printf("%19s[]=[]=[]=[]=[]=[]=[]=[]=[]=[]=[]=[]\n", "");

}