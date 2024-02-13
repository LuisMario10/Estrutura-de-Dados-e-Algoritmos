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

// void addTeamInClassification(Championship *championshipRef, Team *teamRef) {
//     championshipRef->classification[championshipRef->sizeClassification] = teamRef;
// }

void viewClassification(Championship *championshipRef) {
    printf("==========%s==========\nPosicao - Nome do Time - Pontos\n\n",championshipRef->name);
    for(int i = 0; i < championshipRef->numberofTeams; i++) {
        printf("Posicao: %i - ", i + 1);
        viewTeam(championshipRef->classification[i]);
    }
}

void startChampionship(Championship *championshipRef) {
    int resultado = 10;
    for(int i = 0; i < championshipRef->sizeClassification; i++) {
        for(int j = i+1; j < championshipRef->sizeClassification; j++) {
            printf("Jogo: %s x %s\n\n", 
            championshipRef->classification[i]->name, 
            championshipRef->classification[j]->name);

            printf("[0]%s vence [1]%s vence ou [2]empate\n", 
            championshipRef->classification[1]->name,
            championshipRef->classification[j]->name);
            scanf("%i", &resultado);
            if(resultado == 0) {
                teamWin(championshipRef->classification[i]);
            } else if(resultado == 1) {
                teamWin(championshipRef->classification[j]);
            } else {
                teamDraw(championshipRef->classification[i]);
                teamDraw(championshipRef->classification[j]);
            }
        }
    }
}

void clearChampionship(Championship **championshipRef) {
    Championship *AUXchampionshipRef = *championshipRef;
    for(int i = 0; i < AUXchampionshipRef->sizeClassification; i++) {
        clearTeam(&(AUXchampionshipRef->classification[i]));
        AUXchampionshipRef->classification[i] = NULL;
    }
    free(AUXchampionshipRef->classification);
    AUXchampionshipRef->classification = NULL;

    free(AUXchampionshipRef);
    *championshipRef = NULL;
}


int main(void) {
    char namesTeams[20][100] = {
        {"Botafogo"},
        {"SaoPaulo"},
        {"Corinthians"},
        {"Vasco"},
        {"Flamengo"},
        {"Juventude"},
        {"Vitoria"},
        {"Criciuma"},
        {"Internacional"},
        {"Palmeiras"},
        {"Gremio"},
        {"RbBragantino"},
        {"Cuiaba"},
        {"Fortaleza"},
        {"Bahia"},
        {"Fluminense"},
        {"Crizeiro"},
        {"AtleticoMG"},
        {"AtleticoGO"},
        {"AthleticoPR"},
    };

    Championship *newChampionship = createChampionship("Brasileirao", 20);
    for(int i = 0; i < newChampionship->numberofTeams; i++) {
        newChampionship->classification[i] = createTeam(namesTeams[i]);
    }
    startChampionship(newChampionship);
    //viewClassification(newChampionship);
    clearChampionship(&newChampionship);
    return 0;
}