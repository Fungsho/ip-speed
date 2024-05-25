#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_IP_LENGTH 40

// Function to check if a string is a valid IPv4 address
int isIPv4(char* ip) {
    // Implementation to check if the string is a valid IPv4 address
    // You can use your own implementation or a library function like inet_pton
    return 1; // Placeholder, replace with actual implementation
}

// Function to check if a string is a valid IPv6 address
int isIPv6(char* ip) {
    // Implementation to check if the string is a valid IPv6 address
    // You can use your own implementation or a library function like inet_pton
    return 1; // Placeholder, replace with actual implementation
}

// Function to extract IP addresses from a line of text
void extractIPs(char* line, FILE* outputFile, char* linkPrefix, char* linkSuffix) {
    char* token;
    char* delimiters = " ,;:.!?\"()\t\n";

    token = strtok(line, delimiters);
    while (token != NULL) {
        if (isIPv4(token) || isIPv6(token)) {
            fprintf(outputFile, "%s%s%s\n", linkPrefix, token, linkSuffix);
        }
        token = strtok(NULL, delimiters);
    }
}

int main() {
    FILE* inputFile, * outputFile;
    char inputFilename[MAX_LINE_LENGTH];
    char outputFilename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    char linkPrefix[MAX_LINE_LENGTH];
    char linkSuffix[MAX_LINE_LENGTH];

    // Prompt user for input and output filenames
    printf("Enter the input filename: ");
    scanf("%s", inputFilename);
    printf("Enter the output filename: ");
    scanf("%s", outputFilename);

    // Prompt user for link prefix and suffix
    printf("Enter the link prefix: ");
    scanf("%s", linkPrefix);
    printf("Enter the link suffix: ");
    scanf("%s", linkSuffix);

    // Open input file for reading
    inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open output file for writing
    outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    // Read each line from input file
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        // Extract IPs from the line and write to output file
        extractIPs(line, outputFile, linkPrefix, linkSuffix);
    }

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    printf("IP extraction and link generation completed. Results saved to %s\n", outputFilename);

    return 0;
}
