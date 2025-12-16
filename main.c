// SparePartsInventoryAssistant
// A program to check if a user's part name input
// matches with any of the part names in inventory.

// Necessary library functions.
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// The array of pointers to strings for the parts in inventory.
const char *INVENTORY_LIST[] = {"Resistor",   "Capacitor",   "Inductor",
                                "Diode",      "Transistor",  "Transformer",
                                "Switch",     "LED",         "Amplifier",
                                "PLC module", "Servo motor", "Cable"};

// The integer array for how many there are of each part.
const int INVENTORY_AMOUNT[] = {10, 8, 7, 4, 6, 1, 9, 11, 2, 1, 3, 20};

// Defining some variables for later use.
size_t listLength = _Countof(INVENTORY_LIST);
char playerCount[50];

// Defining a partNumber variable to be used in isStringInArray later.
int partNumber = 0;

// Assistant messages:
const char ASSISTANT_GREETING[] = "Hi! Welcome to the spare parts inventory.\n";
const char ASSISTANT_QUESTION[] =
    "\nWhich part do you need? (type 'Help' for help, type 'Exit' to "
    "quit)\n";
const char ASSISTANT_REPLY_POSITIVE[] = "I've got '%s' here for you.\n";
const char ASSISTANT_REPLY_NEGATIVE[] =
    "I don't have a part of the exact name '%s'.\n";
const char ASSISTANT_HELP[] =
    "When you search for parts, remember to spell correctly "
    "and that this program is case-sensitive.\n";
const char ASSISTANT_GOODBYE[] = "\nGoodbye!";
const char HELP_COMMAND[] = "Help";
const char HELP_TEXT[] =
    "Help: Shows a list of commands."
    "\nList all parts: Shows all part names and how many are in stock."
    "\nExit: Exits the program."
    "\nIf you still need a part, type its name correctly.";
const char LIST_COMMAND[] = "List all parts";
const char EXIT_COMMAND[] = "Exit";

// A general boolean function which returns true if some input string
// is identical to any element in an array of pionters to strings.
bool isStringInArray(const char *arr[], size_t length, const char inputString[],
                     int *stringNumber) {
  for (int i = 0; i < length; i++) {
    // Returns true and the element number if the input and element match.
    if (strcmp(inputString, arr[i]) == 0) {
      *stringNumber = i;
      return true;
    }
  }
  return false;
}

// A general function to find the string with most letters
// in an an array of pointers to strings.
int longestStringInArray(const char *arr[], size_t length, int longestString) {
  longestString = 0;
  for (int i = 0; i < length; i++) {
    if (longestString < strlen(arr[i])) {
      longestString = strlen(arr[i]);
    }
  }
  return longestString;
}

// Prompts the user for input as to what part they're looking for.
// Has additional 'Help', 'Exit', and 'List all parts' commands.
int main() {
  printf("%s", ASSISTANT_GREETING);

  // Finding the part name with most letters
  // using the longestStringInArray function.
  int longestPartName =
      longestStringInArray(INVENTORY_LIST, listLength, longestPartName);

  // Main loop where the user enters a part name
  // and it's checked against the inventory list.
  while (1) {
    printf("%s", ASSISTANT_QUESTION);

    // Prompts the user for inputting a part name.
    fgets(playerCount, sizeof(playerCount), stdin);
    // Removes trailing newline if it is present
    size_t inputLength = strlen(playerCount);
    if (inputLength > 0 && playerCount[inputLength - 1] == '\n') {
      playerCount[inputLength - 1] = '\0';
    }

    // Checks if the user input is identical to any element in inventoryList.
    if (isStringInArray(INVENTORY_LIST, listLength, playerCount, &partNumber)) {
      printf(ASSISTANT_REPLY_POSITIVE, INVENTORY_LIST[partNumber]);
      // Checks if the user has entered 'Exit' and breaks the loop if so.
    } else if (strcmp(playerCount, EXIT_COMMAND) == 0) {
      break;
      // Checks if the user has entered 'List all parts'
      // and uses a for loop to list them if so.
    } else if (strcmp(playerCount, LIST_COMMAND) == 0) {
      for (int i = 0; i < listLength; i++) {
        // Uses longestPartName and longestPartAmount to
        // dynamically format the output from 'List all parts'.
        printf("\n%-*s: %d", longestPartName + 1, INVENTORY_LIST[i],
               INVENTORY_AMOUNT[i]);
      }
      // Checks if the user has entered 'Help' and lists all commands if so.
    } else if (strcmp(playerCount, HELP_COMMAND) == 0) {
      printf("%s", HELP_TEXT);
      // If no command nor any part name has been entered
      // the following is printed.
    } else {
      printf(ASSISTANT_REPLY_NEGATIVE, playerCount);
      printf("%s", ASSISTANT_HELP);
    }
  }

  printf("%s", ASSISTANT_GOODBYE);
}