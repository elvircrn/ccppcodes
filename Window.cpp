#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "Window.h"

Window::Window () {
    for (int i = 0; i <= 50; i++)
        for (int j = 0; j <= 50; j++)
            BitMap [i] [j] = '.', FieldState [i] [j] = 0;
}

Window::Window (int H, int W) {
    Height = H;
    Width = W;
    for (int i = 0; i <= H; i++)
        for (int j = 0; j <= W; j++)
            BitMap [i] [j] = '.', FieldState [i] [j] = 0;
}

void Window::Display() {
    for (int i = 1; i <= Height; i++, printf ("\n"))
        for (int j = 1;  j <= Width; j++)
            printf ("%c", BitMap [i] [j]);
}

void Window::Clear() {
    for (int i = 1; i <= Height; i++)
        for (int j = 1; j <= Width; j++)
            BitMap [i] [j] = '.', FieldState [i] [j] = 0;
}

void Window::ClearState() {    for (int i = 0; i <= Height; i++)
        for (int j = 0; j <= Width; j++)
            if (FieldState [i] [j] == 1)
                FieldState [i] [j] = 0, BitMap [i] [j] = '.';
}

void Window::Display(const TetrisBlock &T) {

    ClearState();

    for (int i = 0; i < T.blocks.size(); i++) {
        if (T.blocks [i].x < 1 || T.blocks [i].y < 1 || T.blocks [i].x > Height || T.blocks [i].y > Width
            || FieldState [int (T.blocks [i].x)] [int (T.blocks [i].y)] == 2)
            return;
    }

    for (int i = 0; i < T.blocks.size(); i++)
        BitMap [int (T.blocks [i].x)] [int (T.blocks [i].y)] = T.color;
}
