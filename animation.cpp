#include "Animation.h"

void drawLipsShape(UBYTE *image, int centerX, int centerY) {
  Paint_Clear(BLACK);
  
  struct Point { int x; int y; } points[10];
  points[0] = { centerX - 15, centerY };
  points[1] = { centerX - 5,  centerY - 8 };
  points[2] = { centerX,      centerY - 5 };
  points[3] = { centerX + 5,  centerY - 8 };
  points[4] = { centerX + 15, centerY };
  points[5] = { centerX + 15, centerY };
  points[6] = { centerX + 5,  centerY + 6 };
  points[7] = { centerX,      centerY + 8 };
  points[8] = { centerX - 5,  centerY + 6 };
  points[9] = { centerX - 15, centerY };
  
  for (int i = 0; i < 9; i++) {
    Paint_DrawLine(points[i].x, points[i].y,
                   points[i+1].x, points[i+1].y,
                   RED, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
  }
  Paint_DrawString_EN(centerX - 20, centerY + 15, "LIPS", &Font16, WHITE, BLACK);
}

void writeText(UBYTE *image, int x, int y, const char* message, const void* font) {
  Paint_DrawString_EN(x, y, message, font, WHITE, BLACK);
}

void drawFilledRect(int x0, int y0, int x1, int y1, UWORD color) {
  for (int y = y0; y <= y1; y++) {
    Paint_DrawLine(x0, y, x1, y, color, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
  }
}

void drawSpeechBubble(UBYTE *image, int x, int y, int w, int h, const char* text) {
  drawFilledRect(x, y, x + w, y + h, WHITE);
  Paint_DrawRectangle(x, y, x + w, y + h, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
  
  int tailX[3] = { x + 10, x + 18, x + 14 };
  int tailY[3] = { y + h,  y + h,  y + h + 8 };
  for (int i = 0; i < 2; i++) {
    Paint_DrawLine(tailX[i], tailY[i], tailX[i+1], tailY[i+1], BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
  }
  for (int j = y + h + 1; j < y + h + 8; j++) {
    Paint_DrawLine(x + 12, j, x + 16, j, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
  }
  Paint_DrawRectangle(x + 12, y + h + 1, x + 16, y + h + 8, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
  writeText(image, x + 4, y + h/3, text, &Font12);
}

void drawPhoneSymbol(UBYTE *image, int x, int y) {
  int w = 20, h = 30;
  Paint_DrawRectangle(x, y, x + w, y + h, WHITE, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
  Paint_DrawLine(x + 5, y + 3, x + 15, y + 3, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
  Paint_DrawCircle(x + w/2, y + h - 4, 3, WHITE, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
}

void drawShockedGirl(UBYTE *image) {
  Paint_Clear(BLACK);
  for (int i = 5; i < OLED_1in5_RGB_WIDTH; i += 15) {
    for (int j = 5; j < OLED_1in5_RGB_HEIGHT; j += 15) {
      Paint_DrawCircle(i, j, 2, WHITE, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    }
  }
  
  int centerX = OLED_1in5_RGB_WIDTH / 2;
  int centerY = OLED_1in5_RGB_HEIGHT / 2;
  int headRadius = 30;
  Paint_DrawCircle(centerX, centerY, headRadius, YELLOW, DOT_PIXEL_1X1, DRAW_FILL_FULL);
  
  for (float angle = 200.0; angle <= 340.0; angle += 2.0) {
    float rad = angle * (3.14159265 / 180.0);
    int x = centerX + (int)((headRadius + 4) * cos(rad));
    int y = centerY - (int)((headRadius + 4) * sin(rad));
    Paint_DrawPoint(x, y, BROWN, DOT_PIXEL_1X1, DOT_STYLE_DFT);
  }
  
  int eyeOuterRadius = 6, eyeInnerRadius = 3;
  int eyeOffsetX = 12, eyeOffsetY = 10;
  Paint_DrawCircle(centerX - eyeOffsetX, centerY - eyeOffsetY, eyeOuterRadius, WHITE, DOT_PIXEL_1X1, DRAW_FILL_FULL);
  Paint_DrawCircle(centerX - eyeOffsetX, centerY - eyeOffsetY, eyeInnerRadius, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
  Paint_DrawCircle(centerX + eyeOffsetX, centerY - eyeOffsetY, eyeOuterRadius, WHITE, DOT_PIXEL_1X1, DRAW_FILL_FULL);
  Paint_DrawCircle(centerX + eyeOffsetX, centerY - eyeOffsetY, eyeInnerRadius, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
  
  Paint_DrawLine(centerX - eyeOffsetX - 4, centerY - eyeOffsetY - 6,
                 centerX - eyeOffsetX + 4, centerY - eyeOffsetY - 6,
                 BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
  Paint_DrawLine(centerX + eyeOffsetX - 4, centerY - eyeOffsetY - 6,
                 centerX + eyeOffsetX + 4, centerY - eyeOffsetY - 6,
                 BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
  
  int mouthWidth = 20;
  int mouthStartX = centerX - mouthWidth / 2;
  int mouthEndX = centerX + mouthWidth / 2;
  int mouthBaseY = centerY + 12;
  int amplitude = 4;
  for (int x = mouthStartX; x <= mouthEndX; x++) {
    float dx = x - centerX;
    float widthHalf = mouthWidth / 2.0;
    int y = mouthBaseY - (int)(amplitude * (1 - (dx * dx) / (widthHalf * widthHalf)));
    Paint_DrawPoint(x, y, RED, DOT_PIXEL_1X1, DOT_STYLE_DFT);
  }
  
  int pigtailRadius = 18;
  int leftPigtailX = centerX - headRadius - pigtailRadius + 2;
  int leftPigtailY = centerY + 10;
  Paint_DrawCircle(leftPigtailX, leftPigtailY, pigtailRadius, YELLOW, DOT_PIXEL_1X1, DRAW_FILL_FULL);
  int rightPigtailX = centerX + headRadius + pigtailRadius - 2;
  int rightPigtailY = centerY + 10;
  Paint_DrawCircle(rightPigtailX, rightPigtailY, pigtailRadius, YELLOW, DOT_PIXEL_1X1, DRAW_FILL_FULL);
  
  int bowCenterX = leftPigtailX;
  int bowCenterY = leftPigtailY - pigtailRadius - 2;
  Paint_DrawCircle(bowCenterX - 4, bowCenterY, 3, RED, DOT_PIXEL_1X1, DRAW_FILL_FULL);
  Paint_DrawCircle(bowCenterX + 4, bowCenterY, 3, RED, DOT_PIXEL_1X1, DRAW_FILL_FULL);
  Paint_DrawCircle(bowCenterX, bowCenterY, 2, RED, DOT_PIXEL_1X1, DRAW_FILL_FULL);
  
  drawSpeechBubble(image, centerX + headRadius + 5, centerY - headRadius, 40, 20, "Oh no!");
  Paint_DrawString_EN(centerX - 30, centerY + headRadius + 8, "SAD :(", &Font16, WHITE, BLACK);
}

void updateDisplay(UBYTE *image, int &animationState, int positions[][2], int numPositions, const char *overlayText) {
  // If an overlay text is provided (like sensor reading), display it on the bottom.
  if (animationState == 0) {
    drawShockedGirl(image);
    if (overlayText) {
      Paint_DrawString_EN(0, OLED_1in5_RGB_HEIGHT - 20, overlayText, &Font16, WHITE, BLACK);
    }
    OLED_1in5_rgb_Display(image);
    animationState = 1;
  } else {
    drawLipsShape(image, positions[0][0], positions[0][1]);
    drawSpeechBubble(image, positions[0][0] + 5, positions[0][1] - 5, 70, 65, "ring ring");
    drawPhoneSymbol(image, positions[0][0] + 80, positions[0][1] - 5);
    if (overlayText) {
      Paint_DrawString_EN(0, OLED_1in5_RGB_HEIGHT - 20, overlayText, &Font16, WHITE, BLACK);
    }
    OLED_1in5_rgb_Display(image);
    animationState = 0;
  }
}