#ifndef TP_RESEAU_H
#define TP_RESEAU_H

int CreerSocketTCP(void);
int ConnexionServeur(int, char *, int );
int EnvoyerDonnees(int , char *);
int RecevoirDonnees(int , char *, int);
int FermerSocket(int);
int CreerServeur(int , int );
int AttenteConnexionClient(int );

#endif
