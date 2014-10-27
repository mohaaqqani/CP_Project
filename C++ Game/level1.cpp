#include <stdio.h>
#include<conio.h>
#include <allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include "level1.h"

 
class lev1
{
   public:
          Genie g;
          Bit1 bit1[10];
          int num_1;
         // enum KEYS{UP,DOWN,LEFT,RIGHT};
         // bool keys[4] = {false,false,false,false};
          
        void initGenie(Genie &pl)
        {
            pl.x = 200;
            pl.y =500;
            pl.ID = PLAYER;
            pl.lives = 2;
            pl.speed = 20;
            pl.bound_x = 6;
            pl.bound_y = 7;
            pl.score = 0; 
             
        } 
        
        void DrawGenie(Genie &pl)
        {
             ALLEGRO_BITMAP *image = al_load_bitmap("tsprite.gif");
             if(pl.x > 970)
             pl.x = 970;
             
             if(pl.x < 10)
             pl.x = 10;           
             al_draw_bitmap(image,pl.x,pl.y,0);
             al_flip_display();
             
        } 
          
          int start()
          {
   
   ALLEGRO_DISPLAY *display = NULL;
   num_1 = 10;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   
   bool done = false;
  
   
  
      
   if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }
    al_init_font_addon();
   al_init_ttf_addon();
   al_init_primitives_addon();
   al_init_image_addon();
   al_install_keyboard();
   al_install_mouse();
   initGenie(g);
   srand(time(NULL));
   initBit1(bit1,10);
   event_queue = al_create_event_queue();
   


    
    
   
   al_register_event_source(event_queue,al_get_keyboard_event_source());
   //al_register_event_source(event_queue,al_get_display_event_source(display));
 
   display = al_create_display(1024,640);
   if(!display) {
      fprintf(stderr, "failed to create display!\n");
      return -1;
   }
        load();     
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue,&ev);
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {      
        start_level1();
        }
  
  
   while(!done)
   {
       drawImage();
       StartBit1(bit1,10);
       UpdateBit1(bit1,10);      
       DrawGenie(g);
       DrawBit1(bit1,10);

       ALLEGRO_EVENT e;
 

       
       al_wait_for_event(event_queue, &ev);

       if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
       {
           switch(ev.keyboard.keycode)
           {
              case ALLEGRO_KEY_A:
                   g.x = g.x - g.speed;
                   break;
              case ALLEGRO_KEY_D: 
                   g.x = g.x + g.speed;
                   break; 
              case ALLEGRO_KEY_ESCAPE:
                   done = true;
                   break;                      
           }       
       }



        
   }
 
  // al_clear_to_color(al_map_rgb(0,0,0));
 
   
 
   //al_rest(3.0);
 
   al_destroy_display(display);
}

void load()
{
    int i=0;
    ALLEGRO_BITMAP *image = al_load_bitmap("Level 1.bmp");
    ALLEGRO_FONT *font24 = al_load_font("Arial.ttf",24,0);
       
     
       al_draw_bitmap(image,0,0,0);
       al_draw_text(font24,al_map_rgb(255,255,255), 0, 0, 0,"Loading..");
       al_flip_display();
       al_rest(1.0);
       
       al_draw_bitmap(image,0,0,0);
       al_draw_text(font24,al_map_rgb(255,255,255), 0, 0, 0,"Loading...");
       al_flip_display();
       al_rest(1.0);
             
       al_draw_bitmap(image,0,0,0); 
       al_draw_text(font24,al_map_rgb(255,255,255), 0, 0, 0,"Loading...."); 
       al_flip_display(); 
       al_rest(1.0);
       

       i++;
       
       al_draw_bitmap(image,0,0,0); 
       al_draw_text(font24,al_map_rgb(255,255,255), 0, 0, 0,"Press Any Key to Continue");
       al_flip_display();
       al_rest(1.0); 
       
       al_destroy_bitmap(image);
       al_destroy_font(font24);
      
}
 
void start_level1()
{
      al_clear_to_color(al_map_rgb(0,0,0));
      ALLEGRO_BITMAP *image1 = al_load_bitmap("lev1.bmp"); 
      al_draw_bitmap(image1,0,0,0);
      al_flip_display();   
      //al_rest(5.0);
      
      al_destroy_bitmap(image1);
      
     
} 

void drawImage()
{
      ALLEGRO_BITMAP *image1 = al_load_bitmap("lev1.bmp"); 
      al_draw_bitmap(image1,0,0,0);
      al_flip_display();   
      //al_rest(5.0);
      
      al_destroy_bitmap(image1);     
}
void initBit1(Bit1 bit1[], int size)
{
    for(int i=0;i <size ; i++)
    {
            bit1[i].ID = BIT1;
            bit1[i].live = false;
            bit1[i].speed = 20;
            bit1[i].bound_x = 18;
            bit1[i].bound_y = 18;
    } 
     
}

void DrawBit1(Bit1 bit1[],int size)
{
    for(int i=0; i< size; i++)
    {
          if(bit1[i].live)  
          {
            al_draw_filled_circle(bit1[i].x,bit1[i].y,20,al_map_rgb(255,0,0));  
            ALLEGRO_BITMAP img              
          }
    } 
}
 
void StartBit1(Bit1 bit1[],int size)
{
    for(int i=0; i< size; i++)
    {
          if(!bit1[i].live)  
          {
            if(rand() %500 == 0)
            {
                bit1[i].live = true;
                bit1[i].x = 30 + rand()% (1024-60);
                bit1[i].y = 0;  
                break;    
            }              
          }
    }      
     
} 
 
void UpdateBit1(Bit1 bit1[],int size)
{
    for(int i=0; i< size; i++)
    {
            if(bit1[i].live)
            {
                bit1[i].y += bit1[i].speed;
                if(bit1[i].y > 640)
                bit1[i].live = false;            
            }
    }      
     
}
   
};
