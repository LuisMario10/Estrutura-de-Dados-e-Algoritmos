#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define SIZE_NAMES 20

typedef struct _team {
    char *name;
    int pointing;
} Team;

typedef struct _championship {
    char *name;
    Team **classification;
    int sizeClassification;
    int numberofTeams;
} Championship;

Team *createTeam(char *name) {
    Team *newTeam = (Team*) calloc(1, sizeof(Team));
    newTeam->name = NULL;
    newTeam->name = name;
    newTeam->pointing = 0;
    return newTeam;
}

void viewTeam(Team *teamRef) {
    printf("Nome: %s - Pontos: %i\n", teamRef->name, teamRef->pointing);
}

void teamWin(Team *teamRef) {
    teamRef->pointing = teamRef->pointing + 3;
}

void teamDraw(Team *teamRef) {
    teamRef->pointing ++;
}

void clearTeam(Team **teamRef) {
    free(*teamRef);
    *teamRef = NULL;
}


Championship *createChampionship(char *name, int numberofTeams) {
    Championship *newChampionship = (Championship*) calloc(1, sizeof(Championship));
    newChampionship->name = name;
    newChampionship->sizeClassification = 0;
    newChampionship->numberofTeams = numberofTeams;
    newChampionship->classification = (Team **) calloc(1, sizeof(Team*));
    return newChampionship;
}

void addTeamInClassification(Championship *championshipRef, Team *teamRef) {
    if(championshipRef->sizeClassification == championshipRef->numberofTeams) {
        printf("Campeonato esta lotado");
    } else {
        championshipRef->classification[championshipRef->sizeClassification] = teamRef;
        championshipRef->sizeClassification++;
    }
}

void viewClassification(Championship *championshipRef) {
    printf("==========%s==========\n", championshipRef->name);
    printf("Posicao - Nome do Time - Pontos\n\n");
    for(int i = 0; i < 5; i++) {
        printf("Posicao: %i - %s - %i\n", i + 1, 
        championshipRef->classification[i]->name,
        championshipRef->classification[i]->pointing);
    }
}

void clearChampionship(Championship **championshipRef) {
    Championship *AUXchampionshipRef = *championshipRef;
    for(int i = 0; i < AUXchampionshipRef->sizeClassification; i++) {
        clearTeam(&(AUXchampionshipRef->classification[i]));
    }
    free(AUXchampionshipRef->classification);
    AUXchampionshipRef->classification = NULL;

    free(AUXchampionshipRef);
    *championshipRef = NULL;
}


int main(void) {
    Championship *newChampionship = createChampionship("Campeonato-Teste", 5);

    Team *clube1 = createTeam("Time A");
    Team *clube2 = createTeam("Time B");
    Team *clube3 = createTeam("Time C");
    Team *clube4 = createTeam("Time D");
    Team *clube5 = createTeam("Time E");
    addTeamInClassification(newChampionship, clube1);
    addTeamInClassification(newChampionship, clube2);
    addTeamInClassification(newChampionship, clube3);
    addTeamInClassification(newChampionship, clube4);
    addTeamInClassification(newChampionship, clube5);
    // Stert Championship
    for(int i = 0; i < newChampionship->sizeClassification; i++) {
        for(int j = i+1; j < newChampionship->sizeClassification; j++) {
            int decisions[newChampionship->sizeClassification];
            printf("%s x %s: ", 
            newChampionship->classification[i]->name,
            newChampionship->classification[j]->name);
            printf("[0] Empate - [1] Casa vence - [2] Visitante vence: \n");
            scanf("%i", &decisions[j]);
            if(decisions[j] == 0) {
                teamDraw(newChampionship->classification[i]);
                teamDraw(newChampionship->classification[j]);
            } else if(decisions[j] == 1) {
                teamWin(newChampionship->classification[i]);
            } else if(decisions[j] == 2) {
                teamWin(newChampionship->classification[j]);
            }
        }
    }

    Team *aux;
    for(int i = 0; i < newChampionship->sizeClassification; i++){
        for(int j = 0; j < (newChampionship->sizeClassification - i - 1); j++){
            if(newChampionship->classification[j]->pointing < 
            newChampionship->classification[j + 1]->pointing) {
                aux = newChampionship->classification[j];
                newChampionship->classification[j] = newChampionship->classification[j + 1];
                newChampionship->classification[j + 1] = aux;
            }
        }
    }
    viewClassification(newChampionship);
    
    clearChampionship(&newChampionship);
    return 0;
}