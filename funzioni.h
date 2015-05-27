//Definizione etichette
#define MAX_CLASS 4
#define MAX_STRLEN 30

//Definizione RECORD
struct s_elemento {
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    char classe[MAX_CLASS+1];
    int eta;
    struct s_elemento *prossimo;
};

typedef struct s_elemento elemento;

void controlloAllocazione(elemento *p);
elemento *funzioneInput(elemento *primo);
void funzioneOutput(elemento *primo);
void svuotaLista(elemento *primo);