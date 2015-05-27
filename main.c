#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"


int main(int argc, char** argv) {
    //Dichiarazione Puntatori
    elemento *primo = NULL;
    char scelta[2];
   
    //Inserimento primo elemento della lista
    printf("Vuoi inserire uno studente (s/n) : ");
    scanf("%s", scelta);
    if(!(strcmp(scelta, "s"))) {
        primo = (elemento *) malloc(sizeof(elemento));
        controlloAllocazione(primo);
        
        printf("Nome studente (MAX 30) : ");
        scanf("\n%[^\n]", primo->nome);
        printf("Cognome studente (MAX 30) : ");
        scanf("\n%[^\n]", primo->cognome);
        printf("Classe studente (MAX 4) : ");
        scanf("%s", primo->classe);
        printf("Eta' studente : ");
        scanf("%d", &(primo->eta));
        
        //Inserimento lista
        primo = funzioneInput(primo);
    }
    
    //Lettura della lista
    funzioneOutput(primo);
    
    //Deallocazione della lista
    svuotaLista(primo);
    
    return (EXIT_SUCCESS);
}

