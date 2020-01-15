#include <gb/gb.h>
#include <stdio.h>
#include "charSprites.c"
#include "background.c"
#include "backgroundTiles.c"
#include "ppSplash.c"
#include "ppSplash1.c"
#include "mtSplashData.c"
#include "mtSplashMap.c"
#include "shooterSplashData.c"
#include "shooterSplashMap.c"
#include "bulletSprite.c"
#include "GameCharacter.c"

struct GameCharacter tank;
struct GameCharacter bullet;
UBYTE spritesize = 4;

void performantdelay(UINT8 numloops){
    UINT8 i;
    for(i = 0; i < numloops; i++){
        wait_vbl_done();
    }     
}


void movegamecharacter(struct GameCharacter* character, UINT8 x, UINT8 y){
    move_sprite(character->spritids[0], x, y);

}


void setupbullet(){
    bullet.x = 180;
    bullet.y = 180;
    bullet.width = 8;
    bullet.height = 8;

    set_sprite_tile(0, 0);
    bullet.spritids[0] = 1;

    movegamecharacter(&bullet, bullet.x, bullet.y);
}

void setuptank(){
    tank.x = 88;
    tank.y = 138;
    tank.width = 8;
    tank.height = 8;

    set_sprite_tile(1, 1);
    tank.spritids[0] = 0;

    movegamecharacter(&tank, tank.x, tank.y);
}

void shoot(){
    int i = 0;
    if(joypad() & J_A){
        
       while(1){
            performantdelay(9);
            bullet.x = 180;
            bullet.y = 180;
            movegamecharacter(&bullet, bullet.x, bullet.y);


            performantdelay(9);
            bullet.x = tank.x;
            bullet.y = tank.y;
            movegamecharacter(&bullet, bullet.x, bullet.y);
            return;

            while(i<100){
                performantdelay(9);
                bullet.y -=2;
                movegamecharacter(&bullet, bullet.x, bullet.y);
                i = i++;
                return;    
            }
            

            // if(bullet.x = -244){
            //     bullet.x = 180;
            //     bullet.y = 180;
            //     movegamecharacter(&bullet, bullet.x, bullet.y);
            //     break;
            //   }
         
        }
      }

}

void main(){

    UINT8 currentspriteindex = 0;

     // these registers must be in this specific order!
    NR52_REG = 0x80; // is 1000 0000 in binary and turns on sound
    NR50_REG = 0x77; // sets the volume for both left and right channel just set to max 0x77
    NR51_REG = 0xFF; // is 1111 1111 in binary, select which chanels we want to use in this case all of them. One bit for the L one bit for the R of all four channels
    set_sprite_data(0, 2, charSprites);

    setuptank();
    setupbullet();

    set_bkg_data(0, 105, mtSplashData);
    set_bkg_tiles(0, 0, 20, 18, mtSplashMap);
    
    SHOW_BKG;
    DISPLAY_ON;

    waitpad(J_START);

    set_bkg_data(0, 126, ppSplash);
    set_bkg_tiles(0, 0, 20, 18, ppSplash1);

    SHOW_BKG;
    DISPLAY_ON;

    waitpad(J_START);

    set_bkg_data(0, 212, shooterSplashData);
    set_bkg_tiles(0, 0, 20, 18, shooterSplashMap);

    SHOW_BKG;
    DISPLAY_ON;

    waitpad(J_START);

    set_bkg_data(0, 7, backgroundTiles);
    set_bkg_tiles(0, 0, 20, 18, background);

    SHOW_SPRITES;
    SHOW_BKG;
    DISPLAY_ON;


    while(1){

        shoot();

        switch(joypad()){
            case J_LEFT:
                tank.x -= 2;
                movegamecharacter(&tank, tank.x, tank.y);
                break;
            case J_RIGHT: 
                tank.x += 2;
                movegamecharacter(&tank, tank.x, tank.y);
                break;  
            case J_UP: 
                tank.y -= 2;
                movegamecharacter(&tank, tank.x, tank.y);
                break; 
            case J_DOWN: 
                tank.y += 2;
                movegamecharacter(&tank, tank.x, tank.y);
                break;
            case J_A: 
                 NR52_REG = 0x80;
                 NR51_REG = 0x11;
                 NR50_REG = 0x77;

                 NR10_REG = 0x1E;
                 NR11_REG = 0x10;
                 NR12_REG = 0xF3;
                 NR13_REG = 0x00;
                 NR14_REG = 0x87;

                 

        }
    performantdelay(5);
    }
}
