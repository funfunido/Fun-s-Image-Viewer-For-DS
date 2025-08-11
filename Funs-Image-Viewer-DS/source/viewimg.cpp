#include "viewimg.h"
#include <iostream>
#include <stdio.h>
#include <nds.h>
#include "output.h"


bool hasDone = false;


bool viewImage() {
    bool success;

    if (not hasDone) {
        int bg3 = bgInit(3, BgType_Bmp8, BgSize_B8_256x256, 0,0);

        dmaCopy(outputBitmap, bgGetGfxPtr(bg3), 256*192);
        dmaCopy(outputPal, BG_PALETTE, 256*sizeof(u16));
        hasDone = true;
    }


    success = hasDone;

    return success;
}