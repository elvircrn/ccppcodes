#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
#include <cstring>

using namespace std;

class level
{
private:

    enum block_type { NONE, ROOM, FLOOR, WALL };
    vector <vector <block_type>  > matrix;

public:

    vector <vector <char> > dungeon;
    int width, height;

    level() { }
    level(int _height, int _width)
    {
        width = _width;
        height = _height;
        dungeon.resize(height);
        matrix.resize(height);
        for (int i = 0; i < height; i++)
        {
            matrix[i].resize(width);
            dungeon[i].resize(width);
        }
        init();
    }

    void init()
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                dungeon[i] [j] = '#';
                matrix[i] [j] = block_type::WALL;
            }
        }
    }

    void set_rooms(int room_count)
    {
        for (int current_room = 1; current_room <= room_count; current_room++)
        {
            bool found(false);
            int ran_height, ran_width, ran_x, ran_y, tries = 0;

            while (!found)
            {
                while ((ran_x = (rand() % height)) % 2 != 1 && ((ran_y = (rand() % width))) % 2 != 1);

                int counter = 0;

                bool can(false);
                while (!can)
                {
                    can = true;
                    ran_height = rand() % 5 + 2;
                    ran_width  = rand() % 5 + 2;

                    ran_width  += !(ran_width  % 2);
                    ran_height += !(ran_height % 2);

                    if (ran_x + ran_height >= height || ran_y + ran_width >= width)
                        continue;

                    for (int i = 0; i < ran_height; i++)
                    {
                        for (int j = 0; j < ran_width; j++)
                            if (matrix [i] [j] != block_type::WALL)
                                can = false;

                        if (!can)
                            break;
                    }

                    if (counter++ > 1000)
                        break;
                }

                if (!can)
                    continue;

                for (int i = 0; i < ran_height; i++)
                    for (int j = 0; j < ran_width; j++)
                        matrix[ran_x + i] [ran_y + j] = block_type::ROOM;

                if (tries++ > 100)
                    break;
            }
        }
    }

    void generate_dungeon(int room_count)
    {
        set_rooms(room_count);
    }

    void print()
    {
        for (int i = 0; i < height; i++, printf("\n"))
            for (int j = 0; j < width; j++)
                if (matrix[i] [j] == block_type::ROOM || matrix[i] [j] == block_type::FLOOR)
                    putchar('.');
                else
                    putchar('#');
    }

    ~level()
    {
        for (int i = 0; i < height; i++)
        {
            dungeon[i].erase(dungeon[i].begin(), dungeon[i].end());
            matrix[i].erase(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main()
{
    level l(20, 20);

    l.generate_dungeon(5);

    l.print();

    return 0;
}










































