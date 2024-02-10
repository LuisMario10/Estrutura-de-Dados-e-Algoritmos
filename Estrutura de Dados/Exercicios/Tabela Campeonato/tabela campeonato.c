#include <stdio.h> 

typedef struct _team {
    char *name;
    int points;
} Team;

typedef struct _classification {
    char *name;
    int points;
} Classification;

Team *createTeam(char *nameTeam) {
    Team *newTeam = (Team*) calloc(1, sizeof(Team));
    newTeam->name = nameTeam;
    newTeam->points = 0;
    return newTeam;
}

void cleanTeam(Team **teamRef) {
    free(*teamRef);
    *teamRef = NULL;
}

int main(void) {

    return 0;
}