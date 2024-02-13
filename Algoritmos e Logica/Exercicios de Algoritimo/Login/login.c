// Programa de Login

#include <stdio.h>

const int code = 2525;
const int password = 1234;

int inputCode, inputPassword, decision = 2;

int main(void) {
    printf("=== Login ===\n");
    printf("Insira Codigo de Verificacao: \n");
    scanf("%i", &inputCode);

    if(inputCode == code) {
        int attempts = 0;
        while(attempts <= 1) {
            printf("Insira a Senha de Verificacao: \n");
            scanf("%i", &inputPassword);    
            printf("\n");
            if(inputPassword == password) {
                printf("Acesso Permitido!!!\n");
                return 0;
            }

            int error = 0;
            while(decision < 0 || decision > 1) {
                if(error > 0) {
                    printf("Opcao invalida!!!\n\n");
                }
                error++;
                printf("Senha Incorreta!!!\n[0] - Encerrar Programa || [1] - Tentar Novamente?: \n");
                scanf("%i", &decision);
                printf("\n\n");
                if(error == 2) {
                printf("Tente Acessar Uma Outra o Hora...\n");
                return 0;
            }
            }
            
            attempts++;
        }
    }
    printf("Encerrando Programa...");
    return 0;
}