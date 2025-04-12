#include "menu.h"


void init_menu(Menu *m){
    m->bg = IMG_Load("images/menu/bg.png");

    //btn jouer
    m->btn_jouer[0] = IMG_Load("images/menu/Jouer1.png");
    m->btn_jouer[1] = IMG_Load("images/menu/Jouer2.png");

    m->pos_jouer.x = 1920/2 - (m->btn_jouer[0]->w/2);
    m->pos_jouer.y = 250;
    m->pos_jouer.w = m->btn_jouer[0]->w;
    m->pos_jouer.h = m->btn_jouer[0]->h;

    m->etat_btn_jouer = 0;
    //btn option 
    m->btn_option[0] = IMG_Load("images/menu/option1.png");
    m->btn_option[1] = IMG_Load("images/menu/option2.png");

    m->pos_option.x = 1920/2 - (m->btn_option[0]->w/2);
    m->pos_option.y = 250+150;
    m->pos_option.w = m->btn_option[0]->w;
    m->pos_option.h = m->btn_option[0]->h;

    m->etat_btn_option = 0;
    //btn meilleur 
    m->btn_meilleur[0] = IMG_Load("images/menu/meilleur1.png");
    m->btn_meilleur[1] = IMG_Load("images/menu/meilleur2.png");

    m->pos_meilleur.x = 1920/2 - (m->btn_meilleur[0]->w/2);
    m->pos_meilleur.y = 250+150+150;
    m->pos_meilleur.w = m->btn_meilleur[0]->w;
    m->pos_meilleur.h = m->btn_meilleur[0]->h;

    m->etat_btn_meilleur = 0;
    //btn histoire 
    m->btn_histoire[0] = IMG_Load("images/menu/histoire1.png");
    m->btn_histoire[1] = IMG_Load("images/menu/histoire2.png");

    m->pos_histoire.x = 1920/2 - (m->btn_histoire[0]->w/2);
    m->pos_histoire.y = 250+150+150+150;
    m->pos_histoire.w = m->btn_histoire[0]->w;
    m->pos_histoire.h = m->btn_histoire[0]->h;

    m->etat_btn_histoire = 0;
    //btn quitter 
    m->btn_quitter[0] = IMG_Load("images/menu/quitter1.png");
    m->btn_quitter[1] = IMG_Load("images/menu/quitter2.png");

    m->pos_quitter.x = 1920/2 - (m->btn_quitter[0]->w/2);
    m->pos_quitter.y = 250+150+150+150+150;
    m->pos_quitter.w = m->btn_quitter[0]->w;
    m->pos_quitter.h = m->btn_quitter[0]->h;

    m->etat_btn_quitter = 0;
    
}


void afficher_menu(Menu m,SDL_Surface *ecran){
    SDL_BlitSurface(m.bg,NULL,ecran,NULL);

    SDL_BlitSurface(m.btn_jouer[m.etat_btn_jouer],NULL,ecran,&m.pos_jouer);
    SDL_BlitSurface(m.btn_option[m.etat_btn_option],NULL,ecran,&m.pos_option);
    SDL_BlitSurface(m.btn_meilleur[m.etat_btn_meilleur],NULL,ecran,&m.pos_meilleur);
    SDL_BlitSurface(m.btn_histoire[m.etat_btn_histoire],NULL,ecran,&m.pos_histoire);
    SDL_BlitSurface(m.btn_quitter[m.etat_btn_quitter],NULL,ecran,&m.pos_quitter);


}

void mise_a_jour_menu(Menu *m){

    m->etat_btn_jouer = collision_avec_souris(m->pos_jouer);
    m->etat_btn_option = collision_avec_souris(m->pos_option);
    m->etat_btn_meilleur = collision_avec_souris(m->pos_meilleur);
    m->etat_btn_histoire = collision_avec_souris(m->pos_histoire);
    m->etat_btn_quitter = collision_avec_souris(m->pos_quitter);

}

int collision_avec_souris(SDL_Rect pos){
    int mouse_x,mouse_y;
    SDL_GetMouseState(&mouse_x,&mouse_y);


    if(mouse_x > pos.x && mouse_x < (pos.x+pos.w) && mouse_y > pos.y && mouse_y < (pos.y + pos.h) ){
        return 1;
    }else{
        return 0;
    }

}

void gerer_event_menu(Menu *m,SDL_Event event,int *quitter,int *indice_ecran){
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
                *quitter = 1;
            break;
        case SDL_MOUSEBUTTONDOWN:
                if(event.button.button == SDL_BUTTON_LEFT){
                    if(m->etat_btn_quitter == 1){
                        *quitter = 1;
                    }else if(m->etat_btn_jouer == 1){
                        *indice_ecran = 1;
                    }
                }
            break;
        
        default:
            break;
        }
    }
}