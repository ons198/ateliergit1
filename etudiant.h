#include <gtk/gtk.h>

typedef struct {
    int jour; 
    int mois;
    int annee;
  } Date;


typedef struct{
    char nom[20];
    char prenom[20];
    char cin[20];
    char mdp[20];
    int niveau;
    char age[20];
    int bloc ;
    Date d ;
    int sexe;
    int education;
} Etudiant;

void ajouter(Etudiant etd );
void afficher(GtkWidget *liste, char file[20]);
void supprimer(char cin[20]);
void modifier(Etudiant e);
void rechercher(char cin[20]);
int nb_etudiant_par_niveau(char niveau[20],Etudiant etd);

