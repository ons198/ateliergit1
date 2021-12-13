#ifdef HAVE_CONFIG_H
# include<config.h>
#endif 

#include <stdio.h>
#include<stdlib.h>
#include"etudiant.h"
#include <string.h>
#include <gtk/gtk.h>

enum
{
  ENOM,
  EPRENOM,
  ECIN,
  EMDP,
  ENIVEAU,
  EAGE,
  EJOUR,
  EMOIS,
  EANNEE,
  ESEXE,
  EEDUCATION,
  EBLOC,
  COLUMNS
  
};



void ajouter(Etudiant etd)

{

   FILE *f ;
   f=fopen("Etudiant1.txt","a+");
   if(f!=NULL)
   {

fprintf(f,"%s %s %s %s %s %d %d %d %d %d %d %d \n",etd.nom,etd.prenom,etd.cin,etd.mdp,etd.age,etd.niveau,etd.sexe, etd.education,etd.d.jour, etd.d.mois,etd.d.annee,etd.bloc );

    fclose(f);

}
}


// Fonction afficher //

void afficher(GtkWidget *liste ,char file[20])
{
GtkCellRenderer *renderer; //ta3ti el fourma mta treeview elli hiya espace bidha//
GtkTreeViewColumn  *column; // fi ena colonne
GtkTreeIter iter;    //       star
GtkListStore *store;   // garde la forme du treeview yani type et forme d colonne
Etudiant etd;
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste); // tekhou fourma d'une liste view
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new (); //stocker la valeur retournéé par la methode getcellrenderer , les 3 lignes y7adhrou colonne
column = gtk_tree_view_column_new_with_attributes("nom",renderer, "text", ENOM, NULL); //stocker l'attribu de chaque colonne , ref essm el colonne rendrer ;type de sortie et affichage Enom ye7seb fi ena ligne
gtk_tree_view_append_column (GTK_TREE_VIEW(liste), column); //tlassa9 les colonnes

renderer=gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("prenom",renderer, "text", EPRENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
    
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("cin",renderer, "text", ECIN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("mdp",renderer, "text", EMDP, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("niveau",renderer, "text", ENIVEAU, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("age",renderer, "text", EAGE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("jour",renderer, "text", EJOUR, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes("mois",renderer, "text", EMOIS, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("annee",renderer, "text", EANNEE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("sexe",renderer, "text", ESEXE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("education",renderer, "text", EEDUCATION, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("bloc",renderer, "text", EBLOC, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT); //9adech 3anna mn colonnes wta3ti type de la var fel colonne

f=fopen(file,"r"); //bech n3ammer el treeview n7el el fichier
if(f==NULL)
{
  return;
}
else
{
   
   while(fscanf(f,"%s %s %s %s %s %d %d %d %d %d %d %d\n",etd.nom, etd.prenom,  etd.cin, etd.mdp,etd.age, &etd.niveau,&etd.sexe, &etd.education,&etd.d.jour, &etd.d.mois, &etd.d.annee , &etd.bloc)!=EOF)
    {
gtk_list_store_append (store, &iter);
gtk_list_store_set (store, &iter, ENOM, etd.nom, EPRENOM, etd.prenom, ECIN, etd.cin, EMDP, etd.mdp, ENIVEAU, etd.niveau, EAGE, etd.age, EJOUR, etd.d.jour, EMOIS, etd.d.mois, EANNEE, etd.d.annee, ESEXE, etd.sexe, EEDUCATION, etd.education,EBLOC,etd.bloc, -1);
    }fclose(f);

gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);

   }
}


//Fonction supprimer //
void supprimer(char cin[20])
{
Etudiant etd;
FILE *f ,*g;
f=fopen("Etudiant1.txt","r");
g=fopen("aux.txt","a+");
if (f!=NULL && g!=NULL)
   {
  while(fscanf(g,"%s %s %s %s %s %d %d %d  %d %d %d \n",etd.nom,etd.prenom,etd.cin,etd.mdp,etd.age,&etd.niveau,&etd.sexe,&etd.education,&etd.d.jour, &etd.d.mois,&etd.d.annee,&etd.bloc)!=EOF)
       {
        if (strcmp(cin,etd.cin)!=0)
          fprintf(g,"%s %s %s %s %s %d %d %d  %d %d %d \n",etd.nom,etd.prenom,etd.cin,etd.mdp,etd.age,etd.niveau,etd.sexe,etd.education,etd.d.jour, etd.d.mois,etd.d.annee, etd.bloc);
          }
     fclose(f);
     fclose(g);

remove("Etudiant1.txt");
rename("aux.txt","Etudiant1.txt");
      }

}

// Fonction modifier //

void modifier(Etudiant etd)
{
Etudiant e;
FILE *f,*g;
 f=fopen("Etudiant1.txt","r");
 g=fopen("aux.txt","a+");
 if (f!=NULL && g!=NULL)
 {
 while(fscanf(f,"%s %s %s %s %s %d %d %d  %d %d %d %d \n",e.nom,e.prenom,e.cin,e.mdp,e.age,&e.niveau,&e.sexe,&e.education,&e.d.jour, &e.d.mois,&e.d.annee,&e.bloc)!=EOF)
      {
         if (strcmp(etd.cin,e.cin)!=0)
         {
              fprintf(g,"%s %s %s %s %s %d %d %d  %d %d %d %d \n",e.nom,e.prenom,e.cin,e.mdp,e.age,e.niveau,e.sexe, e.education,e.d.jour, e.d.mois,e.d.annee,e.bloc);
         }
         else
         {
              fprintf(g,"%s %s %s %s %s %s %d %d  %d %d %s %d \n",etd.nom,etd.prenom,etd.cin,etd.mdp,etd.age,etd.niveau,etd.sexe,etd.education, etd.d.jour,etd.d.mois,etd.d.annee, etd.bloc);
         }
      }
 }
fclose(f);
fclose(g);
remove("Etudiant1.txt");
rename("aux.txt","Etudiant1.txt");
}



// Fonction rechercher //

void rechercher(char cin[20])
{
  Etudiant etd1;
  Etudiant etd2;
  FILE *f=NULL ;
  f= fopen("Etudiant1.txt","r");

  
  if(f!=NULL )
  {
      while(fscanf(f,"%s %s %s %s %s %d %d %d  %d %d %d  \n",etd.nom,etd.prenom,etd.cin,etd.mdp,etd.age,&etd.niveau,&etd.sexe,&etd.education,&etd.d.jour, &etd.d.mois,&etd.d.annee)!=EOF)
      {
           if(strcmp(cin,etd.cin)==0)
            {
               strcpy(etd1.nom,etd2.nom);
               strcpy(etd1.prenom,etd2.prenom);
               strcpy(etd1.age,etd2.age);
               strcpy(etd1.mdp,etd2.mdp);
               etd1.niveau=etd2.niveau;
               etd1.sexe=etd2.sexe;
               etd1.education=etd2.education ;
               etd1.d.jour=etd2.d.jour;
               etd1.d.mois=etd2.d.mois;
               etd1.d.annee=etd1.d.annee;

            }
  fclose(f);
 }
               
  }
fclose(f);
fclose(g);


}


int nb_etudiant_par_niveau( Etudiant etd)
{
int n1, n2, n3, n4, n5;
n1=0, n2=0, n3=0; n4=0; n5=0;
FILE *f;
f=fopen("Etudiant1.txt","r");
if(f!=NULL)
   {
while(fscanf(fn,"%s %s %s %s %s %d %d %d %d %d %d %d \n",etd.nom,etd.prenom,etd.cin,etd.mdp,etd.age,etd.niveau,&etd.sexe,etd.education ,&etd.d.jour, &etd.d.mois,&etd.d.annee,&etd.bloc)!=EOF)
{
   if (etd.niveau=0 )
         { n1=n1+1;}
   else if (etd.niveau=1 )
         { n2=n2+1;}
   else if (etd.niveau=2 )
         { n3=n3+1;}
   else if (etd.niveau=3 )
         { n4=n4+1;}
   else
         { n5=n1+1;}
      } 
}
 fclose(f);

}



