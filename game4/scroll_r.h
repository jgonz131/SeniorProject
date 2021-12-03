#define SPEED 0x180
#define MAX_SPEED 0x240
#define MAX_RIGHT 0xb000
unsigned char song;
#define MAX_SONGS 2
enum {SONG_GAME, SONG_PAUSE};
enum {SFX_JUMP, SFX_DING, SFX_NOISE};


#pragma bss-name(push, "ZEROPAGE")

// GLOBAL VARIABLES
int fuel = 1000;
char oam_id;
unsigned char bright;
unsigned char bright_count;
unsigned char mounds;
const unsigned char * pointer;
unsigned char game = 0;
unsigned char lives,ded,level,newlevel;
unsigned char game_end = 0;
unsigned char win, lose, restart, levelup;
unsigned char pad1;
unsigned char pad1_new;
unsigned char collision;
unsigned char collision_L;
unsigned char collision_R;
unsigned char collision_U;
unsigned char collision_D;
unsigned char coordinates;
unsigned char changemode;
unsigned char temp1;
unsigned char temp2;
unsigned char temp3;
unsigned char temp4;
unsigned int temp5;
unsigned int temp6;
unsigned int temp7;
unsigned char temp_x;
unsigned char temp_y;
unsigned char eject_L; // from the left
unsigned char eject_R; // remember these from the collision sub routine
unsigned char eject_D; // from below
unsigned char eject_U; // from up
unsigned char direction; //facing left or right?
#define LEFT 0
#define RIGHT 1
unsigned char mode;
enum {TITLE,PLAY, FINISH, SWITCH,PAUSE};
int address;
unsigned char x; // room loader code
unsigned char y,k,i;
unsigned char nt;
unsigned char index;
unsigned char index2;
unsigned char room;
unsigned char map;
unsigned int scroll_x;
unsigned int scroll_y;
unsigned char scroll_count; 
unsigned int pseudo_scroll_x; 
//unsigned int pseudo_scroll_y;
unsigned char L_R_switch;
unsigned int old_x;
unsigned int old_y;





#pragma bss-name(push, "BSS")

unsigned char c_map[240];
unsigned char c_map2[240];

struct Base {
	unsigned char x;
	unsigned char y;
	unsigned char width;
	unsigned char height;
};

struct Base Generic; 
struct Base Generic2; 
struct enemySkier {
	unsigned int x; // low byte is sub-pixel
	unsigned int y;
	signed int vel_x; // speed, signed, low byte is sub-pixel
	signed int vel_y;
};

struct Ball {
	unsigned int x; // low byte is sub-pixel
	unsigned int y;
	signed int vel_x; // speed, signed, handle gravity
	signed int vel_y;
	unsigned int size;
	
};


struct Ball sball = {0x4000,0x7100};

const unsigned char * const brotate[]={
ball1, ball2, ball3, ball4
};
const unsigned char * const bigbrotate[]={
	bigball1, bigball2, bigball3,bigball4
};

struct enemySkier BoxGuy1 = {0x4000,0x6100}; // starting position
// the width and height should be 1 less than the dimensions (14x14)
// note, I'm using the top left as the 0,0 on x,y

#define HERO_WIDTH 5
#define HERO_HEIGHT 5
#define HERO_HEIGHT_SMALL 3
#define HERO_WIDTH_SMALL 3




const unsigned char palettetitle[16]={ 0x0f,0x01,0x21,0x31,0x0f,0x06,0x16,0x26,0x0f,0x07,0x19,0x29 };

const unsigned char palette_bg[]={
0x0f, 0x00, 0x10, 0x30, // black, gray, lt gray, white
0x0f, 0x07, 0x17, 0x27, // oranges
0x0f, 0x02, 0x12, 0x22, // blues
0x0f, 0x09, 0x19, 0x29, // greens
}; 

const unsigned char palette_sp[]={
0x0f, 0x01, 0x21, 0x31, 
0,0,0,0,
0,0,0,0,
0,0,0,0
}; 
const unsigned char enemypal[]={
0x0f, 0x06, 0x16, 0x26, 
0,0,0,0,
0,0,0,0,
0,0,0,0
};

const unsigned char paletter[16]={ 0x0f,0x00,0x10,0x30,0x0f,0x01,0x21,0x30,0x0f,0x07,0x16,0x26,0x0f,0x09,0x19,0x29 };
const unsigned char winpal[16]={ 0x0f,0x00,0x10,0x30,0x0f,0x01,0x21,0x31,0x0f,0x06,0x16,0x26,0x0f,0x05,0x0c,0x28 };
const unsigned char losepal[16]={ 0x0f,0x00,0x10,0x30,0x0f,0x01,0x21,0x31,0x0f,0x06,0x16,0x26,0x0f,0x05,0x0c,0x28 };





// 5 bytes per metatile definition, tile TL, TR, BL, BR, palette 0-3
// T means top, B means bottom, L left,R right
// 51 maximum # of metatiles = 255 bytes

const unsigned char metatiles1[]={
	2, 2, 2, 2,  3,
	4, 4, 4, 4,  1,
	9, 9, 9, 9,  2,
	5, 6, 8, 7,  1,
	5, 6, 8, 7,  0
};

const unsigned char metatiles3[]={
	2, 2, 2, 2,  1,
	1, 1, 1, 1,  3,
	3, 3, 3, 3,  1,
	1, 1, 1, 1,  2
};

#include "BG/room1.c"
#include "BG/room2.c"
#include "BG/room3.c"
#include "BG/room4.c"
#include "BG/room5.c"
#include "BG/room6.c"
#include "BG/room7.c"
#include "BG/room8.c"
#include "BG/room9.c"
#include "BG/room10.c"
#include "BG/room11.c"
#include "BG/room12.c"
#include "BG/room13.c"
#include "BG/room14.c"
#include "BG/room15.c"
#include "BG/room16.c"
#include "BG/room17.c"
#include "BG/room18.c"
#include "BG/room19.c"
#include "BG/room20.c"
#include "BG/room21.c"
#include "BG/room22.c"
#include "BG/room23.c"
#include "BG/room24.c"
#include "BG/room25.c"
#include "BG/room26.c"
#include "BG/room27.c"
#include "BG/room28.c"
#include "BG/room29.c"
#include "BG/room30.c"
#include "BG/TitleScreen.h"
#include "BG/winscreen.h"
#include "BG/losescreen.h"
#define MAX_ROOMS (30-1)
#define MAX_SCROLL (MAX_ROOMS*0x100)-1
// data is exactly 240 bytes, 16 * 15
// doubles as the collision map data


const unsigned char * const Rooms[]= {
	room1, room2, room3, room4, room5, room6, room7, room8, room9, room10,
	room11,room12,room13,room14,room15,room16,room17,room18,room19,room20,
	room21,room22,room23,room24,room25,room26,room27,room28,room29,room30
};

const unsigned char Levels[]={
	0,11,21
};

#define MAX_MOUNDS 16
unsigned char mound_x[MAX_MOUNDS];
unsigned char mound_y[MAX_MOUNDS];
unsigned char mound_active[MAX_MOUNDS];
unsigned char mound_room[MAX_MOUNDS];
unsigned char mound_actual_x[MAX_MOUNDS];
unsigned char spr_type[MAX_MOUNDS];

#define TURN_OFF 0xff
#define mound_WIDTH 7
#define mound_HEIGHT 11
#define END_HEIGHT 100
#define END_WIDTH 100



enum{MOUNDS, END};
const unsigned char level_1_mounds[]={
	0x61,0,0x65,MOUNDS,
	0x81,1,0x85,MOUNDS,
	0x61,2,0x95,MOUNDS,
	0x61,3,0x75,MOUNDS,
	0x81,4,0x85,MOUNDS,
	0x61,5,0x125,MOUNDS,
	0x81,6,0x150,MOUNDS,
	0x61,7,0x95,MOUNDS,
	0x81,8,0x75,MOUNDS,
	0x61,9,0x85,MOUNDS,
	0x70,9,0x1000,END,
	0x80,9,0x1000,END,
	TURN_OFF
};
const unsigned char level_2_mounds[]={
	0x61,0,0x65,MOUNDS,
	0x81,1,0x85,MOUNDS,
	0x61,2,0x95,MOUNDS,
	0x61,3,0x75,MOUNDS,
	0x81,4,0x85,MOUNDS,
	0x61,5,0x125,MOUNDS,
	0x81,6,0x150,MOUNDS,
	0x61,7,0x95,MOUNDS,
	0x81,8,0x75,MOUNDS,
	0x61,9,0x85,MOUNDS,
	0x70,9,0x1000,END,
	0x80,9,0x1000,END,
	TURN_OFF
};
const unsigned char level_3_mounds[]={
	0x61,0,0x65,MOUNDS,
	0x81,1,0x85,MOUNDS,
	0x61,2,0x95,MOUNDS,
	0x61,3,0x75,MOUNDS,
	0x81,4,0x85,MOUNDS,
	0x61,5,0x125,MOUNDS,
	0x81,6,0x150,MOUNDS,
	0x61,7,0x95,MOUNDS,
	0x81,8,0x75,MOUNDS,
	0x61,9,0x85,MOUNDS,
	0x70,9,0x1000,END,
	0x80,9,0x1000,END,
	TURN_OFF
};

const unsigned char * const Mounds_list[]={
	level_1_mounds, level_2_mounds, level_3_mounds
};

#define MAX_ENEMY 17
unsigned char enemy_x[MAX_ENEMY];
unsigned char enemy_y[MAX_ENEMY];
unsigned char enemy_active[MAX_ENEMY];
unsigned char enemy_room[MAX_ENEMY];
unsigned char enemy_actual_y[MAX_ENEMY];
unsigned char enemy_actual_x[MAX_ENEMY];
#define ENEMY_WIDTH 13
#define ENEMY_HEIGHT 13
const unsigned char level_1_enemies[]={
	0xc2,0,0xb0,
	
	0xc2,2,0xc0,
	0xc2,3,0xf0,
	TURN_OFF
};


const unsigned char level_2_enemies[]={
	0xc2,0,0xb0,
	0x00,0,0xc0,
	0x00,2,0xf0,
	0xc2,2,0xb0,
	0x00,3,0xc0,
	0xc2,3,0xf0,
	0x00,4,0xb0,
	0xc2,4,0xc0,
	0x00,5,0xf0,
	0xc2,5,0xb0,
	0x00,6,0xc0,
	0xc2,6,0xf0,
	TURN_OFF
};
const unsigned char level_3_enemies[]={
	0xc2,0,0xb0,
	0xc2,0,0xc0,
	0xc2,2,0xf0,
	0xc2,2,0xb0,
	0xc2,3,0xc0,
	0xc2,3,0xf0,
	0xc2,4,0xb0,
	0xc2,4,0xc0,
	0xc2,5,0xf0,
	0xc2,5,0xb0,
	0xc2,6,0xc0,
	0xc2,6,0xf0,
	TURN_OFF
};
const unsigned char * const Enemies_list[]={
	level_1_enemies, level_2_enemies, level_3_enemies
};


// PROTOTYPES
void load_room(void);
void draw_sprites(void);
void movement(void);	
void bg_collision(void);
void draw_screen_R(void);
void new_cmap(void);
void bg_collision_sub(void);
void show_title_screen(void);
void show_win_screen(void);
void show_lose_screen(void);
void check_spr_objects(void);
char get_position(void);
void sprite_obj_init(void);
void skier_move(void);
void sprite_collisions(void);