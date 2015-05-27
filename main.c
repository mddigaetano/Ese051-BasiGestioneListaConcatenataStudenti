#include <stdio.h>
#include <stdlib.h>

#define MAX_NOMELEN 25
#define MAX_CLASSELEN 4

typedef struct s_studente{
    char nome[MAX_NOMELEN+1];
    char cognome[MAX_NOMELEN+1];
    char classe[MAX_CLASSELEN+1];
    unsigned int eta;
}studente;

typedef struct s_elemento{
    studente v;
    struct s_elemento* next;
}elemento;

void CreaLista(elemento**);
void aggiungiElementoTesta(elemento**);
void StampaLista(elemento*);
void SvuotaLista(elemento*);

int main(int argc, char** argv) {
    elemento* primo=NULL;
    
    CreaLista(&primo);
    
    StampaLista(primo);
    
    SvuotaLista(primo);
    
    return (EXIT_SUCCESS);
}

void CreaLista(elemento** primo){
    char ctrl[2]="s";
    
    while(strcmp(ctrl,"n")){
        aggiungiElementoTesta(primo);
        
        if(primo==NULL){
            fprintf(stderr,"Errore nell'aggiunta di un elemento");
            exit(1);
        }
        printf("Vuoi aggiungere altri elementi alla lista? (s/n): ");
        scanf("%s",ctrl);
        printf("\n");
    }
}

void aggiungiElementoTesta(elemento** testa){
   elemento* temp=NULL;
   
   temp=(elemento*)malloc(sizeof(elemento));
   if(temp==NULL){
       fprintf(stderr,"Errore aggiunta elemento");
       exit(1);
   }
   
   printf("Inserisci il nome: ");
   scanf("\n%[^\n]",(*temp).v.nome);
   printf("Inserisci il cognome: ");
   scanf("\n%[^\n]",(*temp).v.cognome);
   printf("Inserisci la classe: ");
   scanf("\n%[^\n]",(temp->v).classe);
   printf("Inserisci l'eta': ");
   scanf("%d", &((temp->v).eta));
   
   temp->next=*testa;
   *testa=temp;
}

void StampaLista(elemento* testa){
    int i=1;
    
    while(testa){
        printf("%d° studente\n",i);
        printf("Nome: %s\n",(testa->v).nome);
        printf("Cognome: %s\n",(testa->v).cognome);
        printf("Classe: %s\n",(testa->v).classe);
        printf("Eta': %d\n\n",(testa->v).eta);
        
        testa=testa->next;        
        i++;
    }
}

void SvuotaLista(elemento* testa){
    elemento* temp=NULL;
    
    while(testa){
        temp=(testa)->next;
        free(testa);
        testa=temp;
    }
}
