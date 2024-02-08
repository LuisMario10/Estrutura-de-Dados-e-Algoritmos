// Apenas Criar e Deletar Livros
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_NOMES 50

typedef struct _livros {
    char *nome;
    int quantPaginas;
    float preco;
} Livros;

typedef struct _alunos {
    char *nome;
    int turma;
    Livros *livroFavorito;
} Alunos;


typedef struct _Estante_de_Livros {
    Livros **colecaoLivros;
    int tamanhoColecao;
} EstanteLivros;

// Classe Livros
//constructor()
Livros *criarLivros(char *nome, int paginas, float preco) {
    Livros *livro = (Livros*) calloc(1, sizeof(Livros));
    livro->nome = nome;
    livro->quantPaginas = paginas;
    livro->preco = preco;
    return livro;
}

// read()
void verLivro(Livros *livro) {
    printf("Mostrando Livro: \n\n");
    printf("Nome: %s\n", livro->nome);
    printf("Quantidade de Paginas: %i\n", livro->quantPaginas);
    printf("Preco do Livro: %.2f\n\n", livro->preco);
}

Livros *copiarLivros(Livros *livroOriginal) {
    return criarLivros(livroOriginal->nome, livroOriginal->quantPaginas, livroOriginal->preco);
}

// delete()
void deletarLivros(Livros **livroRef) {
    Livros *livro = *livroRef;
    free(livro);
    *livroRef = NULL;
}

// CreateEstante()
EstanteLivros *criarEstante(int tamanho) {
    EstanteLivros *estanteCriada = (EstanteLivros*) calloc(1, sizeof(EstanteLivros));
    estanteCriada->colecaoLivros = (Livros **) calloc(tamanho, sizeof(Livros*));
    estanteCriada->tamanhoColecao = tamanho;
    return estanteCriada;
}

void verLivrosEstante(EstanteLivros *estante) {
    for(int i = 0; i < 5; i++) {
        verLivro(estante->colecaoLivros[i]);
    }
}

void apagarEstante(EstanteLivros **estanteRef) {
    EstanteLivros *estanteAux = *estanteRef;
    for(int i = 0; i < estanteAux->tamanhoColecao; i++) {
        deletarLivros(&estanteAux->colecaoLivros[i]);
    }
    free(estanteAux);
    *estanteRef = NULL;
}

// CLasse Alunos
//constructor()
Alunos *criarAluno(char *nome, int turma, Livros *livroFav) {
    Alunos *aluno = (Alunos*) calloc(1, sizeof(Alunos));
    aluno->nome = nome;
    aluno->turma = turma;
    aluno->livroFavorito = copiarLivros(livroFav);
    return aluno;
}

//read()
void verAluno(Alunos *aluno) {
    printf("Mostrando Aluno: \n\n");
    printf("Nome: %s\n", aluno->nome);
    printf("Turma: %i\n------\n", aluno->turma);
    verLivro(aluno->livroFavorito);
}

//delete()
void tirarAluno(Alunos **aluno) {
    Alunos *alunoDeletado = *aluno;
    deletarLivros(&alunoDeletado->livroFavorito);
    free(alunoDeletado);
    *aluno = NULL;
}


void verificaDesalocacaoEstante(EstanteLivros *estanteRef) {
    printf("novaEstante ta desalocada?");
    if(estanteRef == NULL) {
        puts("true\n");
    } else {
        puts("false\n");
    }
}

int tamanhoEstante;

int main(void) {
    puts("Insira o tamanho da Estante: ");
    scanf("%i", &tamanhoEstante);
    EstanteLivros *novaEstante = criarEstante(tamanhoEstante);
    for(int i = 0; i < tamanhoEstante; i++) {
        novaEstante->colecaoLivros[i] = criarLivros("Livro seila", 300, 123.4);
    }
    verLivrosEstante(novaEstante);
    verificaDesalocacaoEstante(novaEstante);
    apagarEstante(&novaEstante);
    verificaDesalocacaoEstante(novaEstante);
    return 0;
}