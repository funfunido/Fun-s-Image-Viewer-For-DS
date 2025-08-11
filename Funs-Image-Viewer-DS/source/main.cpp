/*---------------------------------------------------------------------------------

	$Id: main.cpp,v 1.13 2008-12-02 20:21:20 dovoto Exp $

---------------------------------------------------------------------------------*/
#include <nds.h>
#include <stdio.h>
#include <iostream>
#include <gl2d.h>
#include <nds/touch.h>
#include <nds/input.h>
#include <random>
#include "viewimg.h"

static volatile int frame = 0;

int rgb1 = 3;
int rgb2 = 18;
int rgb3 = 24;

int backkdropColor = RGB15(rgb1, rgb2, rgb3);

bool showPrint = true;

bool pictureViewed = false;

//---------------------------------------------------------------------------------
// VBlank interrupt handler. This function is executed in IRQ mode - be careful!
//---------------------------------------------------------------------------------
static void Vblank() {
//---------------------------------------------------------------------------------
	frame++;
}

	 	std::random_device rd1; // obtain a random number from hardware

		std::random_device rd2; // obtain a random number from hardware
    	
		std::random_device rd3; // obtain a random number from hardware
		
		std::uniform_int_distribution<> distr(0, 255); // define the range
    	

void testPrint(const char* keyPressed) {

		std::mt19937 gen1(rd1()); // seed the generator
		std::mt19937 gen2(rd2()); // seed the generator
		std::mt19937 gen3(rd3()); // seed the generator

		rgb1 = distr(gen1);
		rgb2 = distr(gen2);
		rgb3 = distr(gen3);


		backkdropColor = RGB15(rgb1, rgb2, rgb3);
		//std::cout << backkdropColor << "\n";


		//std::cout << "Key " << keyPressed << " Pressed" << "\n";
}

void rerollColor() {
		std::mt19937 gen1(rd1()); // seed the generator
		std::mt19937 gen2(rd2()); // seed the generator
		std::mt19937 gen3(rd3()); // seed the generator

		rgb1 = distr(gen1);
		rgb2 = distr(gen2);
		rgb3 = distr(gen3);


		backkdropColor = RGB15(rgb1, rgb2, rgb3);


}


void showhideprint() {
	if (showPrint == true) {
		showPrint = false;
		consoleClear();

	} else if (showPrint == false) {
		showPrint = true;
		std::cout << "	  Fun's Image Viewer For DS" << "\n\n\n";
		std::cout << "Press START to view img.png," << "\n";
		std::cout << "	   in 256 color png format" << "\n\n";
		std::cout << "	  Press R to Show/Hide Text" << "\n\n";
		std::cout << "	  Press SELECT to exit" << "\n\n";

	}


}

//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------

	int box1 = 0;
	int boy1 = 0;
	int box2 = 255;
	int boy2 = 191;
	touchPosition touchXY;

	irqSet(IRQ_VBLANK, Vblank);


	consoleDemoInit();


	std::cout << "	  Fun's Image Viewer For DS" << "\n\n\n";
	std::cout << "Press START to view img.png," << "\n";
	std::cout << "	   in 256 color png format" << "\n\n";
	std::cout << "	  Press R to Show/Hide Text" << "\n\n";
	std::cout << "	  Press SELECT to exit" << "\n\n";	
	




	videoSetMode(MODE_5_3D); 
	vramSetBankA(VRAM_A_MAIN_BG_0x06000000);

	glScreen2D();


	while(pmMainLoop()) {
		
		/*if (!pictureViewed) {

			glBegin2D();

			glBoxFilled(box1, boy1, box2, boy2, backkdropColor);




			glEnd2D();

			glFlush(0);
		}*/


		scanKeys();

		int keys = keysDown();
		if (keys & KEY_SELECT) {
			break;
		} 

		if (keys & KEY_A) {
			rerollColor();


		}
		if (keys & KEY_B) {
			rerollColor();


		}
		if (keys & KEY_X) {
			rerollColor();


		}
		if (keys & KEY_Y) {
			rerollColor();


		}
		if (keys & KEY_R) {
			showhideprint();


		}
		if (keys & KEY_UP) {
			rerollColor();


		}
		if (keys & KEY_DOWN) {
			rerollColor();


		}
		if (keys & KEY_LEFT) {
			rerollColor();


		}
		if (keys & KEY_RIGHT) {
			rerollColor();


		}
		if (keys & KEY_START) {
			pictureViewed = true;
			//glEnd2D();
			//glFlush(0);
			if (viewImage()) {

				std::cout << "	Image Loaded Successfully" << "\n";


			} else {
				std::cout << "Image already loaded or failed to load" << "\n";

			}

		}

		touchRead(&touchXY);

		swiWaitForVBlank();


		//std::cout << "Current Frame : " << frame << "\n";

		//std::cout << "DS Touch X axis: " << touchXY.rawx, touchXY.px;

		//std::cout << "DS Touch Y axis: " << touchXY.rawy, touchXY.py;

	}

	return 0;
}
