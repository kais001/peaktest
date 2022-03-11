#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

int main(int argc, char *argv[]){
// sdl_surface : intialisation du surface de travail
SDL_Surface *ecran = NULL, *imageDeFond = NULL,*imageback = NULL,*play1[2],*options1[2],*quit1[2],*back[2],*texte=NULL,*optionbackground=NULL;//reference our image
SDL_Surface *imageDeFond2 = NULL;
Mix_Music *son; //Création d'un pointeur de type Mix_Music
Mix_Chunk *clic; // clic sur button --> son 
int continuer = 1; // boucle  jeu 1 : temchi / 0 le 
int i,j,settingg,playy , i1=0;
float vol=120; // vol max 120 

SDL_Rect positionFond,positionplay1,positionoptions1,positionscoreboard1,positionquit1,positiontexte,positionClic,positionoptionbackground; // les positions d image : x y h w 
SDL_Event event,event1,event2;

positionFond.x = 0;
positionFond.y = 0;


positionoptionbackground.x=0;
positionoptionbackground.y=0;

positiontexte.x=1000;
positiontexte.y=30;

positionplay1.x=175;
positionplay1.y=275;

positionoptions1.x=175;
positionoptions1.y=375;

positionquit1.x=175;
positionquit1.y=475;

SDL_Rect posPlus;
posPlus.x = 800;
posPlus.y = 250;

SDL_Rect posMoins;
posMoins.x = 505;
posMoins.y = 250;

SDL_Rect posvolm;
posvolm.x=513;
posvolm.y=180;

SDL_Rect posresolution;
posresolution.x=515;
posresolution.y=320;

SDL_Rect posretour;
posretour.x=930;
posretour.y=100;

SDL_Rect posres1;
posres1.x=550;
posres1.y=400;

SDL_Rect posres2;
posres2.x=550;
posres2.y=500;

 TTF_Font *police = NULL;  // int font 
SDL_Color couleurnoire = {0, 0, 0}; 


SDL_Init(SDL_INIT_EVERYTHING);// Initialisation de la SDL

    ecran = SDL_SetVideoMode(1366, 759, 32, SDL_HWSURFACE); // espace trav
    imageback= SDL_SetVideoMode(1366, 759, 32, SDL_HWSURFACE);
    //nom du jeu
    SDL_WM_SetCaption("The Journey", NULL); // esm jeu 
    
    //Initialisation Son
	if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)== -1)
	{
	 printf("%s",Mix_GetError());
	}
		
	Mix_Music *musique;
	vol=MIX_MAX_VOLUME;
	Mix_VolumeMusic(vol); // update son
	musique=Mix_LoadMUS("music.mp3"); 
	Mix_PlayMusic(musique,-1); // boucle inf 
	
	//float vol=1;
	Mix_VolumeMusic(vol);

clic = Mix_LoadWAV("souris.wav"); //Chargement de la musique

/* Chargement  des boutons */
int p=1,o=1,q=1;

play1[1] = IMG_Load("playoff.png");
play1[2]=IMG_Load("playon.png");

options1[1] = IMG_Load("optionoff.png");
options1[2]= IMG_Load("optionon.png");

quit1[1] = IMG_Load("exitoff.png");
quit1[2] = IMG_Load("exiton.png");


SDL_Surface *plus=IMG_Load("plus.png");
SDL_Surface *moins=IMG_Load("moins.png");
SDL_Surface *volm=IMG_Load("volume.png");
SDL_Surface *resolution=IMG_Load("resolution.png");
SDL_Surface *retour=IMG_Load("retour.png");
SDL_Surface *res1=IMG_Load("1.png");
SDL_Surface *res2=IMG_Load("2.png");
/* Chargement d'une image dans une surface */
imageDeFond = IMG_Load("backg.png");
imageDeFond2 = IMG_Load("800600.png");
optionbackground=IMG_Load("backop.png");
TTF_Init();//initialisation police
/* Chargement de la police */
police = TTF_OpenFont("Bubble Mint.ttf",50); // bubble police , 50 taille 

/* Écriture du texte dans la SDL_Surface */
 texte = TTF_RenderText_Blended(police, "THE JOURNEY", couleurnoire); // appliqui 
 
j=1;
    while (continuer)
    {
   
    SDL_WaitEvent(&event);// lire evenement 
 switch(event.type)
    {
	// echap --> to5rej 
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE: /* Appui sur la touche Echap, on arrête le programme */
                    continuer = 0;
                    break;
            }
            break;
            
        
            
 case SDL_MOUSEBUTTONDOWN: // souris 
//quit
Mix_PlayChannel(1, clic, 0); 
  if(event.button.x >= positionquit1.x && event.button.x <= (positionquit1.x + 278) && event.button.y >= positionquit1.y && event.button.y <= positionquit1.y+87)
                             { 
                                 Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                 SDL_Flip(ecran);
                                 continuer = 0;
                             }
                             
                             
                             
//option
else if(event.button.x >= positionoptions1.x && event.button.x <= (positionoptions1.x + 278) && event.button.y >= positionoptions1.y && event.button.y <= positionoptions1.y+87)
                              {

                                Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                SDL_Flip(ecran);
                                
                                SDL_BlitSurface(optionbackground,NULL,ecran,&positionoptionbackground);
                                SDL_BlitSurface(plus,NULL, ecran,&posPlus);
    	                        SDL_BlitSurface(moins,NULL, ecran,&posMoins);
    	                        SDL_BlitSurface(volm,NULL, ecran,&posvolm); // blitsurface : affichage sur l ecran 
    	                        SDL_BlitSurface(resolution,NULL, ecran,&posresolution);
    	                        SDL_BlitSurface(retour,NULL, ecran,&posretour);
    	                        SDL_BlitSurface(res1,NULL, ecran,&posres1);
    	                        SDL_BlitSurface(res2,NULL, ecran,&posres2);
                                SDL_Flip(ecran);
//settings
                               settingg=1;
                                while (settingg==1)
                                {
                                
                                
                                
        
                                
                                    SDL_WaitEvent(&event2);
                                    switch(event2.type)
                                    {
                                                      

                                    
                                    
case SDL_MOUSEBUTTONDOWN: // son yetzad wala yon9es 
         	if (event2.button.button == SDL_BUTTON_LEFT)
         	{
                       //click on retour
	        	if(event2.button.x>930 && event2.button.x<980 && event2.button.y>100 && event2.button.y<150 )
	        	{
	        		settingg=0;
	        	}
	        	//click on plus
	        	if(event2.button.x>800 && event2.button.x<850 && event2.button.y>250 && event2.button.y<300 )
	        	{
	        		if((vol)<120)
	                {
	                	(vol)+=20;
	                	
	                }
	                Mix_VolumeMusic(vol);
	                printf("%f\n",vol);
	        	}

	        	//click on moins
	        	if(event2.button.x>500 && event2.button.x<550 && event2.button.y>250 && event2.button.y<300 )
	        	{
	        		if((vol)>=20)
	                {
	                	(vol)-=20;
	                	
	                }
	                Mix_VolumeMusic(vol);
	                printf("%f\n",vol);
	        	}
	        	
	        	
	        	
	        	
	        	
	        	
	        	
	        	
	        	//resolution
	        	if(event2.button.x>550 && event2.button.x<795 && event2.button.y>400 && event2.button.y<475 )
	        	{
	        	ecran = SDL_SetVideoMode(800, 600,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                        SDL_BlitSurface(imageDeFond2, NULL, ecran, &positionFond);
	        	 SDL_FreeSurface(imageDeFond2);
	        	SDL_Flip(ecran); // mise a jour ecran 
	        	}
	        	
         	}
break;

case SDL_KEYDOWN:
        	printf("%f\n",vol);
            switch(event2.key.keysym.sym)
            {
                

                case SDLK_UP: // flech fou9ani 
                
                if((vol)<120)
                {
                	(vol)+=20;
                }
                Mix_VolumeMusic(vol);
                break;

                case SDLK_DOWN: // flech loutani 
                if((vol)>=20)
                {
                	(vol)-=20;
                }
                Mix_VolumeMusic(vol);
                break; 
                case SDLK_ESCAPE: // to5rej 
                     settingg=0;
                break;  
                                    
                                    

            }
            break;
            } 
          SDL_Flip(ecran);
            }  
                                

    
    }
    
    
    //play button
                        else if(event.button.x >= positionplay1.x && event.button.x <= (positionplay1.x + 278) && event.button.y >= positionplay1.y && event.button.y <= positionplay1.y+87)
                              {
                                Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                 SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                                  SDL_BlitSurface(texte, NULL, ecran, &positiontexte);
                                SDL_Flip(ecran);
                                playy=1;
                                while (playy==1)
                                {
                                    SDL_WaitEvent(&event1);
                                    switch(event1.type)
                                    {
                                        case SDL_KEYDOWN:
                                            switch (event1.key.keysym.sym)
                                            {
                                            case SDLK_ESCAPE:
                                                playy=0;
                                                break;
                                            }
                                    }
                                }
                                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

    SDL_BlitSurface(texte, NULL, ecran, &positiontexte);
                              }
break;
 case SDL_MOUSEMOTION://quit button
  if(event.motion.x >= positionquit1.x && event.motion.x <= (positionquit1.x + 278) && event.motion.y >= positionquit1.y && event.motion.y <= positionquit1.y+87)
                             {   SDL_SetColorKey(quit1[2], SDL_SRCCOLORKEY, SDL_MapRGB(quit1[2]->format, 0, 0, 0));
                                 SDL_BlitSurface(quit1[2],NULL,ecran,&positionquit1);
                                 SDL_Flip(ecran);
                             }
                        
else if(event.motion.x >= positionoptions1.x && event.motion.x <= (positionoptions1.x + 278) && event.motion.y >= positionoptions1.y && event.motion.y <= positionoptions1.y+87){  

SDL_SetColorKey(options1[2], SDL_SRCCOLORKEY, SDL_MapRGB(options1[2]->format, 0, 0, 0));
SDL_BlitSurface(options1[2], NULL, ecran, &positionoptions1);
                                 
                                 SDL_Flip(ecran);
                              }
else if(event.motion.x >= positionplay1.x && event.motion.x <= (positionplay1.x + 278) && event.motion.y >= positionplay1.y && event.motion.y <= positionplay1.y+87){ 
                              SDL_SetColorKey(play1[2], SDL_SRCCOLORKEY, SDL_MapRGB(play1[2]->format, 0, 0, 0));
                                 SDL_BlitSurface(play1[2],NULL,ecran,&positionplay1);
                                 SDL_Flip(ecran);
                   }
else{
     SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

    SDL_BlitSurface(texte, NULL, ecran, &positiontexte); /* Blit du texte */
                           
SDL_SetColorKey(play1[1], SDL_SRCCOLORKEY, SDL_MapRGB(play1[1]->format, 0, 0, 0));
    SDL_BlitSurface(play1[1], NULL, ecran, &positionplay1);

SDL_SetColorKey(options1[1], SDL_SRCCOLORKEY, SDL_MapRGB(options1[1]->format, 0, 0, 0));

    SDL_BlitSurface(options1[1], NULL, ecran, &positionoptions1);

SDL_SetColorKey(quit1[1], SDL_SRCCOLORKEY, SDL_MapRGB(quit1[1]->format, 0, 0, 0));

    SDL_BlitSurface(quit1[1], NULL, ecran, &positionquit1);
    SDL_Flip(ecran);
    }
                   break;
    }
SDL_Flip(imageback);
}

/* On libère la surface */
SDL_FreeSurface(imageDeFond);
SDL_FreeSurface(play1[p]);
SDL_FreeSurface(quit1[q]);
SDL_FreeSurface(options1[o]);
TTF_CloseFont(police);
Mix_FreeMusic(son);
Mix_Quit();
TTF_Quit();
Mix_CloseAudio(); //Fermeture de l'API
SDL_FreeSurface(texte);
SDL_Quit();

return EXIT_SUCCESS;
}
