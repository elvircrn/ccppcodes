#include "all.h"
using namespace std;

class point
{
public:

    int x, y;

    point () {}
    point (int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};

class Window
{
public:

    char pixels [100] [100];
    int change [100] [100];

    int width, height;

    Window (int h, int w)
    {
        width = w;
        height = h;
        clear();
    }

    void clear ()
    {
        for (int i = 0; i <= height; i++)
            for (int j = 0; j <= width; j++)
                pixels [i] [j] = '.';
    }

    void clear_change ()
    {
        for (int i = 0; i <= height; i++)
            for (int j = 0; j <= width; j++)
                if (change [i] [j] == 1)
                    change [i] [j] = 0, pixels [i] [j] = '.';
    }

    void display ()
    {
        for (int i = 1; i <= height; i++, printf ("\n"))
            for (int j = 1; j <= width; j++)
                printf ("%c", pixels [i] [j]);
    }

};

class tetris_figure
{
public:

    point cp [10];

    vector <point> blocks;
    int maximum_extent;

    int max_bot ()
    {
        int ret = 0;
        for (int i = 0; i < 4; i++)
            ret = max (blocks [i].x, ret);
        return ret;
    }

    virtual void left (const Window &w)
    {
        for (int i = 0; i < 4; i++)
        {
            if (blocks [i].y == 1)
                return;
        }
        for (int i = 0; i < 4; i++)
        {
            blocks [i].y--;
        }
    }

    virtual void right (const Window &w)
    {
        for (int i = 0; i < 4; i++)
        {
            if (blocks [i].y == w.width)
                return;
        }
        for (int i = 0; i < 4; i++)
        {
            blocks [i].y++;
        }
    }

    virtual void down (const Window &w)
    {
        if (max_bot () == w.height) return;
        for (int i = 0; i < 4; i++)
            blocks [i].x++;
    }

    void display (Window *W)
    {
        W->clear_change();
        for (int i = 0; i < blocks.size(); i++)
            if (blocks [i].x && blocks [i].y)
                W->pixels [blocks [i].x] [blocks [i].y] = color, W->change [blocks [i].x] [blocks [i].y] = true;
    }

    virtual void rotate (const Window &w)
    {
        for (int i = 0; i < blocks.size(); i++)
        {
            Matrix m;
            m.TetrisRotationMatrix ();
            Vector2 current = Vector2 (blocks [i].x, blocks [i].y), solution, oorigin = Vector2 (blocks [0].x, blocks [0].y);
            current -= oorigin;
            Vector2 normalized = current;
            normalized *= m;
            oorigin += normalized;
            if (oorigin.x < 1 || oorigin.y < 1 || oorigin.x > w.height || oorigin.y > w.width)
                return;
            cp [i] = (point (oorigin.x, oorigin.y));
        }
        for (int i = 0; i < blocks.size(); i++)
            blocks [i] = cp [i];
    }

    char color;
};

class I : public tetris_figure
{
public:

    Vector2 origin, a;

    I () { maximum_extent = 4; }
    I (point b)
    {
        maximum_extent = 4;
        color = 'I';
        blocks.push_back (b);
        origin = Vector2 (b.x - 1, b.y);
        origin.x += 0.5f;
        origin.y += 0.5f;
        blocks.push_back (point (b.x - 1, b.y));
        blocks.push_back (point (b.x + 1, b.y));
        blocks.push_back (point (b.x - 2, b.y));
        a = origin;
    }

    void left (const Window &w)
    {
        for (int i = 0; i < 4; i++)
        {
            if (blocks [i].y == 1)
                return;
        }
        for (int i = 0; i < 4; i++)
        {
            blocks [i].y--;
        }
        origin.y--;
    }

    void right (const Window &w)
    {
        for (int i = 0; i < 4; i++)
        {
            if (blocks [i].y == w.width)
                return;
        }
        for (int i = 0; i < 4; i++)
        {
            blocks [i].y++;
        }
        origin.y++;
    }

    void down (const Window &w)
    {
        if (max_bot () == w.height) return;
        for (int i = 0; i < 4; i++)
            blocks [i].x++;
        origin.x++;
    }

    void rotate (const Window &w)
    {
        Vector2 oorigin = origin;
        for (int i = 0; i < blocks.size(); i++)
        {
            oorigin = origin;
            Matrix m;
            m.TetrisRotationMatrix ();
            Vector2 current = Vector2 (blocks [i].x, blocks [i].y);
            current -= oorigin;
            Vector2 normalized = current;
            normalized *= m;
            oorigin += normalized;
            if (oorigin.x < 1 || oorigin.y < 1 || oorigin.x > w.height || oorigin.y > w.width)
                return;
            cp [i] = (point (oorigin.x, oorigin.y));
        }
        for (int i = 0; i < blocks.size(); i++)
            blocks [i] = cp [i];
    }
};

class L : public tetris_figure
{
public:

    L ()
    {
        maximum_extent = 3;
    }
    L (point b)
    {
        color = 'L';
        blocks.push_back (b);
        blocks.push_back (point (b.x - 1, b.y));
        blocks.push_back (point (b.x + 1, b.y));
        blocks.push_back (point (b.x + 1, b.y + 1));
    }

};

class J : public tetris_figure
{
public:
    J ()
    {
        maximum_extent = 3;
    }
    J (point b)
    {
        color = 'J';
        blocks.push_back (b);
        blocks.push_back (point (b.x - 1, b.y));
        blocks.push_back (point (b.x + 1, b.y));
        blocks.push_back (point (b.x + 1, b.y - 1));
    }

};

class O : public tetris_figure
{
public:
    O ()
    {
        maximum_extent = 2;
    }
    O (point b)
    {
        color = 'O';
        blocks.push_back (b);
        blocks.push_back (point (b.x, b.y + 1));
        blocks.push_back (point (b.x + 1, b.y));
        blocks.push_back (point (b.x + 1, b.y + 1));
    }

    void rotate () {}

};

class Z : public tetris_figure
{
    Z ()
    {
        maximum_extent = 3;
    }
    Z (point b)
    {
        color = 'Z';
        blocks.push_back (b);
        blocks.push_back (point (b.x - 1, b.y));
        blocks.push_back (point (b.x, b.y - 1));
        blocks.push_back (point (b.x + 1, b.y - 1));
    }
};

class S : public tetris_figure
{
public:

    S ()
    {
        maximum_extent = 3;
    }
    S (point b)
    {
        color = 'S';
        blocks.push_back (b);
        blocks.push_back (point (b.x - 1, b.y));
        blocks.push_back (point (b.x, b.y + 1));
        blocks.push_back (point (b.x + 1, b.y + 1));
    };
};

class T : public tetris_figure
{
public:

    T ()
    {
        maximum_extent = 3;
    }
    T (point b)
    {
        color = 'T';
        blocks.push_back (b);
        blocks.push_back (point (b.x + 1, b.y));
        blocks.push_back (point (b.x, b.y - 1));
        blocks.push_back (point (b.x - 1, b.y));
    }
};

int main()
{
    Window window = Window (4, 4);

    S s = S (point (3, 2));

    for (;;)
    {
        s.display (&window);
        window.display();
        char input [10];
        scanf ("%s", input);
        if (input [0] == 'L')
        {
            s.left(window);
        }
        else if (input [0] == 'R')
        {
            s.right(window);
        }
        else if (input [0] == 'D')
        {
            s.down (window);
        }
        else if (input [0] == 'T')
        {
            s.rotate(window);
        }
        else {}
        window.clear();
        system ("cls");
    }
    return 0;
}
/*
L335SUPAH4X0R
*/
