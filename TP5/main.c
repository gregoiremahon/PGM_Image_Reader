//
//  main.c
//  TP5
//
//  Created by Grégoire Mahon on 16/11/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

char File_format[3] ;
int Lignes, Colonnes;
int ** MatriceLignesColonnes;
int ValeurDeCouleur;

int Binarisation(int seuil, int ValeurCouleurFichier){
    if (ValeurCouleurFichier < seuil){
        ValeurCouleurFichier = 0;
    }
    else{
        ValeurCouleurFichier = 255;
    }
    return ValeurCouleurFichier;
}

int BinarisationInverse(int seuil, int ValeurCouleurFichier){
    if (ValeurCouleurFichier < seuil){
        ValeurCouleurFichier = 255;
    }
    else{
        ValeurCouleurFichier = 0;
    }
    return ValeurCouleurFichier;
}


int main(int argc, const char * argv[]) {
    
    FILE *p = fopen("/Users/gregoiremahon/Langage C 2022/TP5/TP5/TP5/lena.txt","r");
    FILE *c = fopen ("/Users/gregoiremahon/Langage C 2022/TP5/TP5/TP5/ImageRecree.pgm","w");

    if (p == NULL) {
        printf("Erreur fichier\n");
        fprintf(c,"ERREUR LECTURE FICHIER, il doit être convertit en .txt sur MacOS\n");
        return 0;
    }
    else{
        printf("Fichier trouvé, analyse en cours...\n");
    }
    // Saute l'entête du fichier
    fscanf(p, "%s", &File_format);
    fscanf(p, "%s", &File_format);
    fscanf(p, "%s", &File_format);
    fscanf(p, "%s", &File_format);
    fscanf(p, "%s", &File_format);
    fscanf(p, "%s", &File_format);
    fscanf(p, "%s", &File_format);
    fscanf(p, "%s", &File_format);
    fscanf(p, "%s", &File_format);
    fscanf(p, "%s", &File_format);
    // Ecrit le format du fichier (Px)
    fprintf(c,"%s\n", &File_format);
    // Recupère le nombre de lignes et de colonnes
    fscanf(p,"%d %d", &Lignes, &Colonnes);
    printf("Nombre de lignes : %d | Nombre de colonnes : %d\n", Lignes,Colonnes);  //Nombre de lignes et nombre de colonnes
    fprintf(c, "%d %d\n", Lignes,Colonnes);
    
    // Allocation de mémoire
    MatriceLignesColonnes = (int**)malloc(Lignes*sizeof(int*));
    for(int i = 0; i < Lignes; i++) // A chaque ligne, on ajoute une colonne
    {
        MatriceLignesColonnes[i] =(int*) malloc(Colonnes*sizeof(int));
    }

    // Récupération des valeurs :
    
    int ValeurCouleurMax;
    //fscanf(p, "%s", &File_format);
    fscanf(p, "%d", &ValeurCouleurMax); // Recupère la couleur maximale (255 = blanc)
    fprintf(c,"%d\n",ValeurCouleurMax);
    for(int i = 0; i < Lignes; i++){
        for(int j = 0; j < Colonnes; j++){
            fscanf(p, "%d", &ValeurDeCouleur);
            //ValeurDeCouleur = Binarisation((ValeurCouleurMax+1)/2, ValeurDeCouleur); // Binarise les couleurs
            //ValeurDeCouleur = BinarisationInverse((ValeurCouleurMax+1)/2, ValeurDeCouleur); // Binarisation inverse
            MatriceLignesColonnes[i][j] = ValeurDeCouleur;
            fprintf(c,"%d ", MatriceLignesColonnes[i][j]);
        }
        fprintf(c,"\n");
    }
   
    return 0;
}
