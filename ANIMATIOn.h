#ifndef ANIMATION_H
#define ANIMATION_H

#include "OLED_Driver.h"
#include "GUI_Paint.h"
#include "DEV_Config.h"
#include "Debug.h"
#include <math.h>

// functions
void drawLipsShape(UBYTE *image, int centerX, int centerY);
void writeText(UBYTE *image, int x, int y, const char* message, const void* font);
void drawFilledRect(int x0, int y0, int x1, int y1, UWORD color);
void drawSpeechBubble(UBYTE *image, int x, int y, int w, int h, const char* text);
void drawPhoneSymbol(UBYTE *image, int x, int y);
void drawShockedGirl(UBYTE *image);
void updateDisplay(UBYTE *image, int &animationState, int positions[][2], int numPositions, const char *overlayText = NULL);

#endif
