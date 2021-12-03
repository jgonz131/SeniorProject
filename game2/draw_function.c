



void draw_title_screen(void){
	ppu_off();
	oam_clear();
	vram_adr(0x2000);
	vram_unrle(titlescreen);
	pal_bg(palette_title);
	ppu_on_bg();
}

void draw_mouse(void){
	if(mouse1.respawn =1){
		oam_spr(mouse1.mouse_x, mouse1.mouse_y, mouse1.mouse_spr,mouse1.sprite_att );
			//oam_meta_spr(mouse1.mouse_x, mouse1.mouse_y, metamouse);

		  mouse1.mouse_x+=mouse1.mouse_dx;
			mouse1.mouse_y+=mouse1.mouse_dy;

			

			if(mouse1.mouse_x>=(256-8)) mouse1.mouse_dx=-mouse1.mouse_dx;
			if(mouse1.mouse_y>=(240-8)) mouse1.mouse_dy=-mouse1.mouse_dy;
	}
	mouse1.respawn =0;
	}
	
void mouse_coord(void){
	
mouse1.mouse_spr=MOUSE_LEFT;
		
		mouse1.mouse_x=rand8();
		mouse1.mouse_y=rand8();

		//direction bits

		j=rand8();

		//horizontal speed -3..-3, excluding 0
		spr=1+(rand8()%3);
		mouse1.mouse_dx=j&1?-spr:spr;

		//vertical speed

		spr=1+(rand8()%3);
		mouse1.mouse_dy=j&2?-spr:spr;
	
}
void grow_snake(void){
	
	 
	 for(i = 0; i< Snake1.size;i++){
		if(Snake1.head_sprite == SNAKE_HEAD_TILE_RIGHT){ 
			Snake1.lastx = Snake1.x-(8*(i+1));
			Snake1.lasty = Snake1.y;
		} 
		else if(Snake1.head_sprite == SNAKE_HEAD_TILE_LEFT){
			Snake1.lastx = Snake1.x+ (8*(i+1));
			Snake1.lasty = Snake1.y ;
		}
		if(Snake1.head_sprite ==SNAKE_HEAD_TILE_UP){
			Snake1.lastx = Snake1.x ;
			Snake1.lasty = Snake1.y + (8*(i+1));
			
		}
		else if(Snake1.head_sprite == SNAKE_HEAD_TILE_DOWN){
			Snake1.lastx = Snake1.x;
			Snake1.lasty = Snake1.y - (8*(i+1));
		}
	//	Snake1.lasty = Snake1.y - (8*(i+1));

		oam_spr(Snake1.lastx,Snake1.lasty,Snake1.body,Snake1.head_sprite_attribute);
	 }

}
void draw_sprites(void){
	
	oam_clear();
	
	
	oam_spr(Snake1.x,Snake1.y,Snake1.head_sprite,Snake1.head_sprite_attribute);
	void draw_sprites(void){

oam_meta_spr(Cat1.x,Cat1.y,runlb);

	
		
}



void respawn_mouse(void){
if (mouse1.respawn == 1){
	mouse_coord();
	mouse1.respawn =0;
	Snake1.ate =0;
}	
}

void test1(void){
if (test_eating()){
	mouse_coord();
 }
 respawn_mouse();
 grow_snake();
 
}

