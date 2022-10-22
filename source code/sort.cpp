void creatr_arry(int r = 1)
{
    ratio = r * 2;
    width = render_state.width/ratio;
    height = render_state.height-20;
    s_ort = new int[width];
    s_ort[0] = rand();
    for (int i = 0; i < width; i++)
    {
        s_ort[i] = rand() % height + 5;
        draw_element(i);
        d(2);
    }
}

enum ALGO : unsigned int
{
    SELECTION_SORT,
    BUBBLE_SORT,
    MARGE_SORT,
    QUICK_SORT,
    EXIT,
    ALGO_COUNT,
};

ALGO Current_Algorithm;
global_variable bool isALGO_selected = false;

#define Cursor(algo) (algo == Current_Algorithm ? 0x80ff00 : 0xff5500)
void SELECTION_MENU()
{
    clear_screen();
    hlod_duration = clock();

    if (pressed(BUTTON_UP) || is_down(BUTTON_UP) && hlod_duration > (button_pressed + 500)) {
        Current_Algorithm = (ALGO)((Current_Algorithm - 1 + ALGO_COUNT) % ALGO_COUNT);
        button_pressed = clock();
    }
    if (pressed(BUTTON_DOWN) || is_down(BUTTON_DOWN) && hlod_duration > (button_pressed + 500)) {
        Current_Algorithm = (ALGO)((Current_Algorithm + 1) % ALGO_COUNT);
        button_pressed = clock();
    }
    if (!is_down(BUTTON_UP) && !is_down(BUTTON_DOWN))
    {
        button_pressed = clock();
    }

    if (pressed(BUTTON_ENTER)) {
        isALGO_selected = true;
    }

    ANIMATION();

    draw_text("SORTING VISUALIZER", 300, 700, 8, 0xffff00);
    draw_text("SELECTION SORT", 100, 550, 5, Cursor(SELECTION_SORT));
    draw_text("BUBBLE SORT", 100, 450, 5, Cursor(BUBBLE_SORT));
    draw_text("MERGE SORT", 100, 350, 5, Cursor(MARGE_SORT));
    draw_text("QUICK SORT", 100, 250, 5, Cursor(QUICK_SORT));
    draw_text("EXIT", 100, 50, 5, Cursor(EXIT));
    StretchDIBits(hdc, 0, 0, render_state.width, render_state.height, 0, 0, render_state.width, render_state.height, render_state.screen, &render_state.bitmap_info, DIB_RGB_COLORS, SRCCOPY);
}

#include "selection_sort.cpp"
#include "bubble_sort.cpp"
#include "marge_sort.cpp"
#include "quick_sort.cpp"
