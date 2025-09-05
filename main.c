#include <stdbool.h>
#include <stdio.h>
#include <string.h>

const char *inventoryList[] = {"Resistor",   "Capacitor",   "Inductor",
                               "Diode",      "Transistor",  "Transformer",
                               "Switch",     "LED",         "Amplifier",
                               "PLC module", "Servo motor", "Cable"};

const int inventoryAmount[] = {10, 8, 7, 4, 6, 1, 9, 11, 2, 1, 3, 20};

int listLength = sizeof(inventoryList) / sizeof(inventoryList[0]);
char userInput[50];

bool isPartInInventory(const char *arr[], int length, const char *value) {
  for (int i = 0; i < length; i++) {
    if (strcmp(value, arr[i]) == 0) {
      return true;
    }
  }
  return false;
}

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
      printf("Help: Shows a list of commands.\nList_all_parts: Shows all part "
             "names and how many are in stock.\nExit: Exits the program.");
    } else {
      printf("I don't have a part of the exact name '%s'.\n", userInput);
      printf("When you search for parts, remember to spell correctly\nand "
             "that this program is case-sensitive.\n");
    }
  }

  printf("\nGoodbye!");
}