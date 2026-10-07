#include <raylib.h>
#include <stdio.h>

// Фикс конфликта объявлений Font между Raylib и X11
#define Font X11Font
#include <X11/Xlib.h>
#include <X11/extensions/shape.h>
#undef Font

#define FRAME_COUNT 222
void MakeWindowClickThrough(void); //Без прототипа не компилируется, т.к. функция объявлена ниже мейна
int main(void) {
    // Без рамок, с прозрачным фоном и поверх всех
    SetConfigFlags(FLAG_WINDOW_UNDECORATED | FLAG_WINDOW_TRANSPARENT | FLAG_WINDOW_TOPMOST);

    InitWindow(800, 800, "Hatsune Miku");
    SetExitKey(KEY_NULL);
    SetWindowPosition(1120, 433);
    SetTargetFPS(80);

    // Включаем 100% пролет кликов
    MakeWindowClickThrough();

    Texture2D frames[FRAME_COUNT];
    char fileName[64];

    // Загрузка и хромакей
    for (int i = 0; i < FRAME_COUNT; i++) {
        snprintf(fileName, sizeof(fileName), "assets/frame_%03d.png", i + 1);

        Image img = LoadImage(fileName);

        if (img.data != NULL) {
            ImageFormat(&img, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
            Color *pixels = (Color *)img.data;
            int totalPixels = img.width * img.height;

            for (int j = 0; j < totalPixels; j++) {
                if (pixels[j].r < 35 && pixels[j].g < 35 && pixels[j].b < 35) {
                    pixels[j] = BLANK;
                }
            }

            frames[i] = LoadTextureFromImage(img);
            UnloadImage(img);
        }
    }

    int currentFrame = 0;
    int frameCounter = 0;

    // Главный цикл
    while (!WindowShouldClose()) {
        frameCounter++;
        if (frameCounter >= 3) {
            currentFrame = (currentFrame + 1) % FRAME_COUNT;
            frameCounter = 0;
        }

        BeginDrawing();
            ClearBackground(BLANK);
            DrawTexture(frames[currentFrame], 100, -340, WHITE);
        EndDrawing();
    }

    for (int i = 0; i < FRAME_COUNT; i++) {
        UnloadTexture(frames[i]);
    }

    CloseWindow();
    return 0;
}
// Полное отключение кликов и фокуса мыши по окну
void MakeWindowClickThrough(void) {
    Display *display = XOpenDisplay(NULL);
    if (!display) return;

    void *ptr = GetWindowHandle();
    if (!ptr) {
        XCloseDisplay(display);
        return;
    }

    Window window = *(Window *)ptr;

    // Задаем пустую область ввода — мышь физически "не видит" окно
    XRectangle rect = {0, 0, 0, 0};
    XShapeCombineRectangles(display, window, ShapeInput, 0, 0, &rect, 1, ShapeSet, YXBanded);

    XFlush(display);
    XCloseDisplay(display);
}
