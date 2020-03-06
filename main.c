#include "tp_reseau_linux.h"
#include <stdio.h>
#include <unistd.h>


int main(void){

	int s,co,recevoir,close,envois;
	int port=25;
	char donnees1[100];
	char donnees2[100];
	//char data[]="helo caddeb\r\n";

	s=creersockettcp();
	if(s==-1){
		perror("erreur creation s#include");

		return -1;
		     }
		    // printf("%d",s);

	co=connexionserveur(s,"192.168.0.59",port);
	if (co==-1){
		perror("erreur connexion serveur");
		return -1;
			}
			//printf("connexion serveur ok\n");

	recevoir=recevoirdonnees(s, donnees1, 100);
	if(recevoir==-1){
		perror("erreur reception: ");
		return -1;}

	donnees1[recevoir]='\0';
	printf("\n%s\n\n", donnees1);


	envois=envoyerdonnees(s, "helo caddeb\r\n");
		if(envois==-1){
		perror("erreur envois data: ");
		return -1;
			        }
	recevoir=recevoirdonnees(s, donnees1, 100);
	if(recevoir==-1){
		perror("erreur reception: ");
		return -1;}


	donnees1[recevoir]='\0';
	printf("\n%s\n\n", donnees1);


	envois=envoyerdonnees(s, "mail from: potiblagueur@geii.fr\r\n");
		if(envois==-1){
		perror("erreur envois data: ");
		return -1;
			        }
	recevoir=recevoirdonnees(s, donnees1, 100);
	if(recevoir==-1){
		perror("erreur reception: ");
		return -1;}


	donnees1[recevoir]='\0';
	printf("\n%s\n\n", donnees1);


	envois=envoyerdonnees(s, "rcpt to: caddeb@\r\n");
		if(envois==-1){
		perror("erreur envois data: ");
		return -1;
			        }
	recevoir=recevoirdonnees(s, donnees1, 100);
	if(recevoir==-1){
		perror("erreur reception: ");
		return -1;}

			        
	donnees1[recevoir]='\0';
	printf("\n%s\n\n", donnees1);

	close=fermersocket(s);
	if(close==-1){
		perror("erreur fermeture: ");
		return -1;
			     }
 }
