// main.c
// A program to check if a user's part name input
// matches with any of the part names in inventory.

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// The pointer array for the parts in inventory.
const char *inventoryList[] = {"Resistor",   "Capacitor",   "Inductor",
                               "Diode",      "Transistor",  "Transformer",
                               "Switch",     "LED",         "Amplifier",
                               "PLC module", "Servo motor", "Cable"};

// The integer array for how many there are of each part.
const int inventoryAmount[] = {10, 8, 7, 4, 6, 1, 9, 11, 2, 1, 3, 20};

// Defining some variables for later use in the main function.
int listLength = sizeof(inventoryList) / sizeof(inventoryList[0]);
char userInput[50];

// Boolean function which returns true if some input string
// is identical to any element in inventoryList.
bool isPartInInventory(const char *arr[], int length, const char *string) {
  for (int i = 0; i < length; i++) {
    if (strcmp(string, arr[i]) == 0) {
      return true;
    }
  }
  return false;
}

// Asks the user which part they need and prompts them for input.
// The input is checked against every element in inventoryList.
// If isPartInInventory returns true, it says that the part is in stock.
// Also allows the user to ask for what is in stock and to quit the program.
int main() {
  printf("Hi! Welcome to the spare parts inventory.\n");

  while (1) {
    printf("\nWhich part do you need? (type 'Help' for help, type 'Exit' to "
           "quit)\n");
    gets(userInput);

    if (isPartInInventory(inventoryList, listLength, userInput) == true) {
      printf("I've got '%s' here for you.\n", userInput);
    } else if (strcmp(userInput, "Exit") == 0) {
      break;
    } else if (strcmp(userInput, "List all parts") == 0) {
      for (int i = 0; i < listLength; i++) {
        printf("\n%s: %d.", inventoryList[i], inventoryAmount[i]);
      }
    } else if (strcmp(userInput, "Help") == 0) {
      printf("Help: Shows a list of commands.\nList all parts: Shows all part "
             "names and how many are in stock.\nExit: Exits the program.");
    } else {
      printf("I don't have a part of the exact name '%s'.\n", userInput);
      printf("When you search for parts, remember to spell correctly\nand "
             "that this program is case-sensitive.\n");
    }
  }

  printf("\nGoodbye!");
}