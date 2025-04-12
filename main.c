//include libs SDL
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

//include .h ...
#include "menu.h"

int main(){
//init SDL
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 8192) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        exit(1); //tnajem ta3mel nafes el verification lel kol
    }

    TTF_Init();

//init game

    SDL_Surface *ecran;
    ecran = SDL_SetVideoMode(1920,1080,32,SDL_HWSURFACE | SDL_DOUBLEBUF);

    int quitter = 0;
    SDL_Event event;

    int indice_ecran=0; //menu Principal

    Menu menu;
    init_menu(&menu);


    while(quitter == 0){

        switch (indice_ecran)
        {
        case 0:
                //code Menu Principal ala 3 partie (1Afficher 2gestion event 3mise a jour)
                //afficher:
                afficher_menu(menu,ecran);
                SDL_Flip(ecran);

                //gestion event:
                gerer_event_menu(&menu,event,&quitter,&indice_ecran);
                

                //mise a jour:
                mise_a_jour_menu(&menu);
            
            break;
        case 1: //sous menu joueur
                afficher_smenu_joueur(menu,ecran);
                SDL_Flip(ecran);

                gerer_event_smenu_joueur(&menu,event,&quitter,&indice_ecran);

                mise_a_jour_smenu_joueur(&menu);

                printf("mode de jeux %d \n",menu.mode_jeux);
            
            

            break;
        


        case 10:

                printf("wselna lel tache joueur\n");

            break;

        default:
            break;
        }

    }

    
    
    //Liberer memoire (RAM)

    SDL_FreeSurface(ecran);   
    SDL_Quit();

}