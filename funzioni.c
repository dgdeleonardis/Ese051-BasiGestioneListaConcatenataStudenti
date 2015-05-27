#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

void controlloAllocazione(elemento *p) {
    if(p == NULL) {
        printf("ERRORE : Impossibile allocare memoria\n");
        exit(1);
    }
}

elemento *funzioneInput(elemento *primo) {
    //Parte dichiarativa
    elemento *temp = NULL;
    char scelta[2];
    
    //Inserimento degli elementi della lista
    printf("Vuoi inserire uno studente (s/n) : ");
    scanf("%s", scelta);
    
    while(!(strcmp(scelta, "s"))) {
        temp = (elemento *) malloc(sizeof(elemento));
        controlloAllocazione(temp);
    
        printf("Nome studente (MAX 30) : ");
        scanf("\n%[^\n]", temp->nome);
        printf("Cognome studente (MAX 30) : ");
        scanf("\n%[^\n]", temp->cognome);
        printf("Classe studente (MAX 4) : ");
        scanf("%s", temp->classe);
        printf("Eta' studente : ");
        scanf("%d", &(temp->eta));
        
        temp->prossimo = primo;
        primo = temp;
        
        printf("Vuoi inserire uno studente (s/n) : ");
        scanf("%s", scelta);
    }   
    return primo;
}

void funzioneOutput(elemento *primo) {
    //Parte Dichiarativa
    elemento *temp = NULL;
    
    //Stampa dei blocchi della lista
    printf("\n");
    printf("NOME; COGNOME; CLASSE; ETA';\n");
    temp = primo;
    
    while(!(temp == NULL)) {
        printf("%s; %s; %s; %d;\n",
                temp->nome,
                temp->cognome,
                temp->classe,
                temp->eta);
        
        temp = temp->prossimo;
    }
    
    
}

void svuotaLista(elemento *primo) {
    //Parte Dichiarativa
    elemento *temp = NULL;
    
    //Deallocazione della lista
    while(primo != NULL) {
        temp = primo->prossimo;
        free(primo);
        primo = temp;
    }
}