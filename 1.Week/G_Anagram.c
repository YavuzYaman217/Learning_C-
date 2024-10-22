#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 10   // Max number of input strings
#define MAX_LEN 256      // Max ASCII character range

int areAnagrams(int freq1[], int freq2[]) {
    for (int i = 0; i < MAX_LEN; i++) {
        if (freq1[i] != freq2[i]) {
            return 0;  // Not anagrams
        }
    }
    return 1;  // They are anagrams
}

int main() {
    // Define strings with NULL termination
    char *strings[] = {"eat", "tea", "tan", "ate", "nat", "bat", NULL};
    char **string = strings;

    // Calculate the number of strings
    int size = 0;
    while (string[size] != NULL) {
        size++;
    }

    // Store the frequency arrays for each string
    int freq[MAX_STRINGS][MAX_LEN] = {0};

    // Compute character frequencies for each string
    for (int i = 0; i < size; i++) {
        for (int j = 0; string[i][j] != '\0'; j++) {
            freq[i][(unsigned char)string[i][j]]++;
        }
    }

    // Group the strings that are anagrams
    int visited[MAX_STRINGS] = {0};  // Track visited strings

    printf("Grouped Anagrams:\n");
    for (int i = 0; i < size; i++) {
        if (visited[i]) continue;  // Skip if already grouped

        // Print the first string in the group
        printf("[ %s", string[i]);
        visited[i] = 1;

        // Find and print all anagrams of the current string
        for (int j = i + 1; j < size; j++) {
            if (!visited[j] && areAnagrams(freq[i], freq[j])) {
                printf(", %s", string[j]);
                visited[j] = 1;  // Mark as visited
            }
        }
        printf(" ]\n");  // Close the group
    }

    return 0;
}
