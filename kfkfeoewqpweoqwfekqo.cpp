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

class room
{
public:
    int x, y;
    int width, height;

    room() { }
    room(int _x, int _y, int _height, int _width) { x = _x; y = _y; height = _height; width = _width;}
};

class level
{
private:
    enum block_type { NONE, ROOM, FLOOR, WALL, DOOR };

    vector <vector <block_type>  > matrix;
    vector <vector <int> > room_index;
    vector <vector <int> > priority;
    vector <int> dirX = { 2, 0, -2, 0 };
    vector <int> dirY = { 0, -2, 0, 2 };
    vector <room> rooms;

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

    bool clean(int px, int py, int x, int y)
    {
        bool state = false;

        for (int i = 0; i < 4; i++)
        {
            int X = x + dirX [i] / 2;
            int Y = y + dirY [i] / 2;

            if (X < 0 || Y < 0 || X >= height || Y >= width || (X == px && Y == py) || matrix [X] [Y] == block_type::WALL || matrix [X] [Y] == block_type::ROOM)
                continue;

            state |= clean(x, y, X, Y);
        }

        if (matrix [x] [y] == block_type::DOOR)
            state = true;
        else if (state == false)
            matrix[x] [y] = block_type::WALL;

        return state;
    }

    void run_prim(int x, int y)
    {
        vector <bool> room_set;
        room_set.resize((int)rooms.size());
        priority_queue<edge> Q;
        generate_priority();

        Q.push(edge(x, y, x, y, priority[x] [y]));

        while (!Q.empty())
        {
            edge help = Q.top();
            Q.pop();

            if (matrix[help.x] [help.y] == block_type::WALL)
            {
                matrix[help.px] [help.py] = block_type::FLOOR;
                matrix[help.x] [help.y] = block_type::FLOOR;

                for (int i = 0; i < 4; i++)
                {
                    int X = help.x + dirX[i];
                    int Y = help.y + dirY[i];

                    if (X < 0 || Y < 0 || X >= height || Y >= width)
                        continue;

                    if (matrix [X] [Y] == block_type::WALL)
                        Q.push(edge(help.x + dirX[i] / 2, help.y + dirY[i] / 2, X, Y, priority[X] [Y]));
                    else if (matrix [X] [Y] == block_type::ROOM && !room_set[room_index[X] [Y]])
                    {
                        room_set[room_index[X] [Y]] = true;
                        matrix[help.x + dirX[i] / 2] [help.y + dirY[i] / 2] = block_type::DOOR;
                    }
                }
            }
        }
    }

    void generate_priority()
    {
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                priority[i] [j] = rand();
    }

    void generate_halls()
    {
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                if (i % 2 == 0 && j % 2 == 0 && matrix[i] [j] == block_type::WALL)
                    run_prim(i, j);
    }

    void set_rooms(int room_count)
    {
        for (int current_room = 1; current_room <= room_count; current_room++)
        {
            bool found(false);
            int ran_height, ran_width, ran_x, ran_y, tries = 0;

            while (!found)
            {
                while ((ran_x = (rand() % height)) % 2 != 0 || ((ran_y = (rand() % width))) % 2 != 0);

                int counter = 0;

                bool can(false);
                while (!can)
                {
                    if (counter++ > 1000)
                        break;

                    can = true;

                    ran_height = rand() % 5 + 2;
                    ran_width  = rand() % 5 + 2;

                    ran_width  += !(ran_width  % 2);
                    ran_height += !(ran_height % 2);

                    if (ran_x + ran_height >= height - 1 || ran_y + ran_width >= width - 1)
                        continue;

                    for (int i = 0; i < ran_height; i++)
                    {
                        for (int j = 0; j < ran_width; j++)
                            if (matrix [ran_x + i] [ran_y + j] != block_type::WALL)
                                can = false;

                        if (!can)
                            break;
                    }
                }

                if (!can)
                    continue;

                if (ran_x + ran_height >= height - 1 || ran_y + ran_width >= width - 1)
                {
                    can = false;
                    continue;
                }

                for (int i = 0; i < ran_height; i++)
                {
                    for (int j = 0; j < ran_width; j++)
                    {
                        matrix[ran_x + i] [ran_y + j] = block_type::ROOM;
                        room_index [ran_x + i] [ran_y + j] = current_room;
                    }
                }

                found = true;

                break;
            }

            if (found)
                rooms.push_back(room(ran_x, ran_y, ran_height, ran_width));
        }
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
        rooms.erase(rooms.begin(), rooms.end());
        matrix.resize(height);
        priority.resize(height);
        room_index.resize(height);
        for (int i = 0; i < height; i++)
        {
            room_index[i].resize(width);
            priority[i].resize(width);
            matrix[i].resize(width);
        }

        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                matrix[i] [j] = block_type::WALL;
    }


    void generate_dungeon(int room_count)
    {
        init(height, width);
        set_rooms(room_count);
        generate_halls();
        clean(0, 0, 0, 0);
    }

    void print()
    {
        for (int i = 0; i < height; i++, printf("\n"))
            for (int j = 0; j < width; j++)
                if (matrix[i] [j] == block_type::ROOM)
                    putchar('R');
                else if (matrix [i] [j] == block_type::DOOR)
                    putchar('D');
                else if (matrix[i] [j] == block_type::FLOOR)
                    putchar(' ');
                else
                    putchar(219);
    }

    ~level()
    {
        for (int i = 0; i < height; i++)
        {
            matrix[i].erase(matrix[i].begin(), matrix[i].end());
            priority[i].erase(priority[i].begin(), priority[i].end());
        }

        matrix.erase(matrix.begin(), matrix.end());
        priority.erase(priority.begin(), priority.end());
        rooms.erase(rooms.begin(), rooms.end());
        room_index.erase(room_index.begin(), room_index.end());
    }
};

int main()
{
    srand(time(0));
    level l(60, 70);

    while (true)
    {
        l.generate_dungeon(20);
        l.print();

        system ("pause");
        system("cls");
    }
    return 0;
}
