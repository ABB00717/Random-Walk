#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 1920
#define HEIGHT 1080

void change_dir(int *x, int *y, int scale) {
    int dir = rand() % 4;

    switch (dir) {
        case 0:
            *x += scale;
            break;
        case 1:
            *x -= scale;
            break;
        case 2:
            *y += scale;
            break;
        case 3:
            *y -= scale;
            break;
        default:
            fprintf(stderr, "Error: Unknown Dir\n");
            break;
    }
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    if (argc != 2) {
        printf("Usage: %s <walker_number>\n", argv[0]);
        return -1;
    }

    SDL_Window *pwindow = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);
    SDL_Rect rect = (SDL_Rect) {WIDTH/2, HEIGHT/2, 1, 1};

    int scale = 5;
    int app_running = 1;
    while (app_running) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) app_running = 0;
        }

        int dir = rand() % 4;

        // Walk to dest pixel by pixel
        for (int step = 0; step < scale; step++) {
            switch (dir) {
                case 0:
                    rect.x += 1;
                    break;
                case 1:
                    rect.x -= 1;
                    break;
                case 2:
                    rect.y += 1;
                    break;
                case 3:
                    rect.y -= 1;
                    break;
                default:
                    fprintf(stderr, "Error: Unknown Dir\n");
                    break;
            }

            SDL_FillRect(psurface, &rect, 0xffffff);
            SDL_UpdateWindowSurface(pwindow);
        }
    }
}
