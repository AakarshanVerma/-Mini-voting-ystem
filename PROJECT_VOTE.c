#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 10

// Function to display the menu
void displayMenu() {
    printf("Welcome to the voting system!\n");
    printf("1. Add candidate\n");
    printf("2. View candidates\n");
    printf("3. Vote for a candidate\n");
    printf("4. display result\n");
    printf("5. exit\n");
}

// Function to add a candidate
void addCandidate(char candidates[][50], int *numCandidates) {
    if (*numCandidates < MAX_CANDIDATES) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[*numCandidates]);
        (*numCandidates)++;
        printf("Candidate added successfully!\n");
    } else {
        printf("Max number of candidates reached!\n");
    }
}

// Function to view all candidates
void viewCandidates(char candidates[][50], int numCandidates) {
    printf("List of candidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i+1, candidates[i]);
    }
}

// Function to vote for a candidate
void voteForCandidate(int votes[], int numCandidates) {
    int candidate;
 printf("Enter candidate number to vote for: ");
    scanf("%d", &candidate);
    if (candidate >= 1 && candidate <= numCandidates) {
        votes[candidate-1]++;
        printf("Vote recorded successfully!\n");
    } else {
        printf("Invalid candidate number!\n");
    }
}

// Function to display the results
void displayResults(char candidates[][50], int votes[], int numCandidates) {
    printf("Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d\n", candidates[i], votes[i]);
    }
}

// Main function
int main() {
    char candidates[MAX_CANDIDATES][50];
    int votes[MAX_CANDIDATES] = {0};
    int numCandidates = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addCandidate(candidates, &numCandidates);
                break;
case 2:
                viewCandidates(candidates, numCandidates);
                break;
            case 3:
                voteForCandidate(votes, numCandidates);
                break;
            case 4:
                displayResults(candidates, votes, numCandidates);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
        printf("\n");
    } while (choice != 5);

    return 0;
}