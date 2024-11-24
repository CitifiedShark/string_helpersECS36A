
#include "string_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


char* join(char** strings, int num_strings, char* seperator){
    /*
      Create a new string by joining all of the strings in strings together
      with seperator between each string. If num_strings is <= 0
      returns the empty string. 

      @param strings: The strings to join together
      @param num_strings: The number of strings to join together
      @param seperator: The string to place between each string
      @returns: a new string with seperator between each string in strings
    */
    char* empty_string[0];

    // If num_strings is <= 0
    // return the empty string
    if (num_strings <= 0) {
      return empty_string[0] = '\0';
    }

    // Find out how long the new string list needs to be
    int new_string_len = 1;
    new_string_len += strlen(strings[0]);
    for (int i = 1; i < num_strings; i++) {
      new_string_len += strlen(strings[i]);
      new_string_len += strlen(seperator);
    }

    // Allocate the memory for the new string list
    char* new_string = malloc(new_string_len * sizeof(char));

    // Add on the seperator and string
    new_string[0] = '\0';
    strcat(new_string, strings[0]);
    for (int i = 1; i < num_strings; i++) {
      strcat(new_string, seperator);
      strcat(new_string, strings[i]);
      }
    
    return new_string;
}

char* read_any_len_line() {
    /*
    Read a line of any length from the user input. 
    The newline character, while read, is not included in the returned string.
    @returns: The next line of characters from the input stream
    @modifies: stdin
    */
    int size = 100;

    // Initialize the line
    char* line = malloc(size * sizeof(char));

    // Read user input
    fgets(line, size * sizeof(char), stdin);

    // Reallocate memory depending on length of string and remove newline from input
    for (int i = 0; i < strlen(line); i++) {
      if (strlen(line) > size) {
        size += 1;
        char* line = realloc(line, size * sizeof(char));
      }
      if (line[i] == '\n') {
        line[i] = '\0';
      }
    }
    return line;
}


