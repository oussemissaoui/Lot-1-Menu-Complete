#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>



typedef struct 
{
    SDL_Surface *bg;
    //btn jouer
    SDL_Surface *btn_jouer[2];
    SDL_Rect pos_jouer;
    int etat_btn_jouer;
    //btn option
    SDL_Surface *btn_option[2];
    SDL_Rect pos_option;
    int etat_btn_option;
    //btn meilleur
    SDL_Surface *btn_meilleur[2];
    SDL_Rect pos_meilleur;
    int etat_btn_meilleur;
    //btn histoire
    SDL_Surface *btn_histoire[2];
    SDL_Rect pos_histoire;
    int etat_btn_histoire;
    //btn quitter
    SDL_Surface *btn_quitter[2];
    SDL_Rect pos_quitter;
    int etat_btn_quitter;
    


}Menu;

void init_menu(Menu *m);
void afficher_menu(Menu m,SDL_Surface *ecran);
void mise_a_jour_menu(Menu *m);


int collision_avec_souris(SDL_Rect pos);
void gerer_event_menu(Menu *m,SDL_Event event,int *quitter,int *indice_ecran);
#endif