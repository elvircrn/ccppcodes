#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
#include <cstring>
#include <queue>

using namespace std;

int dirX [4] = { -1, 0, 1, 0 };
int dirY [4] = { 0, 1, 0, -1 };

class room
{
public:
    int x, y;
    int width, height;

    room() { }
    room(int _x, int _y, int _height, int _width) { x = _x; y = _y; height = _height; width = _width;}
};

class bitmask
{
public:
    short mask;

    bitmask() { mask = 0; }
    bitmask(int _mask) { mask = _mask; }

    void turn_on(int index)
    {
        if (!(mask & (1<<index)))
            mask += (1<<index);
    }

    void turn_off(int index)
    {
        if (mask & (1<<index))
            mask -= (1<<index);
    }

    int bit_at(int index)
    {
        return (mask & (1<<index) > 0);
    }
};


class ROOM
{
public:
    int x, y;
    bitmask wall_mask;

    ROOM() { wall_mask = bitmask(); }
    ROOM(int _x, int _y) { x = _x; y = _y; wall_mask = bitmask(); }

    bool wall_at_index(int direction_index)
    {
        return wall_mask.bit_at(direction_index);
    }
};

ROOM rooms[100] [100];

class level
{
private:
    vector <vector <int> > room_index;
    vector <vector <int> > priority;

    struct edge
    {
        int x, y, px, py, w;

        edge() { }
        edge(int _x, int _y, int _w) { x = _x; y = _y; w = _w; }
        edge(int _px, int _py, int _x, int _y, int _w) { px = _px; py = _py; x = _x; y = _y; w = _w; }

        bool operator< (const edge &B) const
        {
            return w > B.w;
        }
    };

    void generate_priority()
    {
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                priority[i] [j] = rand();
    }

public:

    int width, height;

    level() { }
    level(int _height, int _width)
    {
        init(_height, _width);
    }

    void init(int _height, int _width)
    {
        width = _width;
        height = _height;
        priority.resize(height);
        room_index.resize(height);
        for (int i = 0; i < height; i++)
        {
            room_index[i].resize(width);
            priority[i].resize(width);
        }

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                rooms [i] [j] = ROOM(i, j);
                rooms [i] [j].wall_mask = ((1<<4) - 1);
            }
        }
    }

    bool visited [100] [100];

    void break_wall(int x0, int y0, int x1, int y1)
    {
        //down
        if (x0 - x1 < 0)
        {
            rooms[x0] [y0].wall_mask.turn_off(2);
            rooms[x1] [y1].wall_mask.turn_off(0);
        }
        //up
        else if (x0 - x1 > 0)
        {
            rooms[x0] [y0].wall_mask.turn_off(0);
            rooms[x0] [y0].wall_mask.turn_off(2);
        }
        //desno
        else if (y0 - y1 < 0)
        {
            rooms[x0] [y0].wall_mask.turn_off(1);
            rooms[x1] [y1].wall_mask.turn_off(3);
        }
        else if (y0 - y1 > 0)
        {
            rooms[x0] [y0].wall_mask.turn_off(3);
            rooms[x1] [y1].wall_mask.turn_off(1);
        }
    }

    bool can_go(int x0, int y0, int x1, int y1)
    {
        //down
        if (x0 - x1 < 0)
        {
            return rooms[x0] [y0].wall_mask.bit_at(2);
        }
        //up
        else if (x0 - x1 > 0)
        {
            return rooms[x0] [y0].wall_mask.bit_at(0);
        }
        //desno
        else if (y0 - y1 < 0)
        {
            return rooms[x0] [y0].wall_mask.bit_at(1);
        }
        else if (y0 - y1 > 0)
        {
            return rooms[x0] [y0].wall_mask.bit_at(3);
        }
    }

    void tank_trouble()
    {
        init(width, height);
        printf ("started\n");
        memset (visited, false, sizeof visited);
        priority_queue <edge> Q;

        generate_priority();

        Q.push(edge(0, 0, 0, 0, priority[0] [0]));

        printf ("here\n");

        while (!Q.empty())
        {
            edge help = Q.top();
            Q.pop();

            if (!visited [help.x] [help.y])
            {
                printf ("help.x: %d help.y: %d\n", help.x, help.y);
                visited [help.x] [help.y] = true;

                break_wall(help.x, help.y, help.px, help.py);
                for (int i = 0; i < 4; i++)
                {
                    int X = help.x + dirX [i];
                    int Y = help.y + dirY [i];

                    if (X < 0 || Y < 0 || X >= height || Y >= width || visited [X] [Y])
                        continue;

                    Q.push(edge(help.x, help.y, X, Y, priority[X] [Y]));
                }
            }
        }

        printf ("finished\n");
    }

    void generate_dungeon(int room_count)
    {
        init(height, width);
    }

    void print()
    {
        int counter = 0;
        for (int i = 0; i < height; i++, printf ("\n"))
            for (int j = 0; j < width; j++)
            {
                printf ("%.3d", rooms [i] [j].wall_mask.mask);
                //printf ("%d", visited [i] [j]);
                if (!visited [i] [j])
                    counter++;
                if (j < width - 1 && !can_go(i, j, i, j + 1))
                    printf ("|");
                else
                    printf (" ");
            }
        printf ("counter: %d\n", counter);
    }

    ~level()
    {
        for (int i = 0; i < height; i++)
        {
            priority[i].erase(priority[i].begin(), priority[i].end());
        }

        priority.erase(priority.begin(), priority.end());
        room_index.erase(room_index.begin(), room_index.end());
    }
};

int main()
{
    srand(time(0));
    level l(7, 7);

    while (true)
    {
        //l.generate_dungeon(100);
        //l.print();

        l.tank_trouble();
        l.print();
        system ("pause");
        system("cls");
    }
    return 0;
}
