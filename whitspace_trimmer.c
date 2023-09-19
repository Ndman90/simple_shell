#include "shell.h"

/**
 * trim_whitespace - function that returns new line
 * with space removed from it
 *
 * @line: to check against
 * Return: newline without space duplicates
 */

char *trim_whitespace(const char *line) {
    /* Find the length of the input string.*/
    int i, left, right, trimmedLength, length = 0;
  char *result = NULL;
    while (line[length] != '\0') {
        length++;
    }

    /* Find the first non-whitespace character from the left.*/
    left = 0;
    while (line[left] == ' ' || line[left] == '\t') {
        left++;
    }

    /* If the entire string is whitespace, return an empty string.*/
    if (left == length) {
        result = (char *)malloc(1);
        if (result != NULL) {
            result[0] = '\0';
        }
        return result;
    }

    /* Find the last non-whitespace character from the right.*/
    right = length - 1;
    while (line[right] == ' ' || line[right] == '\t') {
        right--;
    }

    /* Calculate the length of the trimmed string.*/
    trimmedLength = right - left + 1;

    /* Allocate memory for the trimmed string and copy the characters.*/
    result = (char *)malloc(trimmedLength + 1);
    if (result != NULL) {
        for (i = 0; i < trimmedLength; i++) {
            result[i] = line[left + i];
        }
        result[trimmedLength] = '\0'; /* Null-terminate the result.*/
    }

    return result;
}
