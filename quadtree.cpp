#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define OPEN  0
#define CLOSE 1

#define TOP    0
#define BOTTOM 1

class Rectangle
{
public:
    int x, y, width, height;

    Rectangle() { }
    Rectangle(int _x, int _y, int _width, int _height) { x = _x; y = _y; width = _width; height = _height; }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    int getWidth()
    {
        return width;
    }

    int getHeight()
    {
        return width;
    }

    void set(int _x, int _y, int _width, int _height)
    {
        x = _x;
        y = _y;
        width = _width;
        height = _height;
    }

    bool contains (const Rectangle &rectangle) const
    {
		int xmin = rectangle.x;
		int xmax = xmin + rectangle.width;

		int ymin = rectangle.y;
		int ymax = ymin + rectangle.height;

		return ((xmin > x && xmin < x + width) && (xmax > x && xmax < x + width))
			&& ((ymin > y && ymin < y + height) && (ymax > y && ymax < y + height));
	}

	bool operator< (const Rectangle &B) const
	{
	    return x < B.x;
	}

};

class SweepElement
{
public:
    bool type;
    int index, x, y1, y2;

    SweepElement() { }
    SweepElement(int _index, int _x, int _y1, int _y2, bool _type) { index = _index; x = _x; y1 = _y1; y2 = _y2; type = _type; }

    int getTop()
    {
        return max (y1, y2);
    }

    int getBottom()
    {
        return min (y1, y2);
    }

    bool operator< (const SweepElement &B) const
    {
        if (x != B.x)
            return x < B.x;
        else if (y1 != B.y1)
            return y1 < B.y1;
        else if (y2 != B.y2)
            return y2 < B.y2;
        else if (type != B.type)
            return type < B.type;
    }
};

int n;
Rectangle rectangles [50100];
vector <SweepElement> sweepElements;
bool visited [50100];

struct SetObject
{
    int height;
    bool type;

    SetObject() { }
    SetObject(int _height, bool _type) { height = _height; type = _type; }

    bool operator< (const SetObject &B) const
    {
        return height < B.height;
    }
};

multiset <SetObject> S;

int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        rectangles [i].get();

        sweepElements.push_back(SweepElement(i,
                                             rectangles [i].x,
                                             rectangles [i].y,
                                             rectangles [i].y + rectangles [i].height,
                                             OPEN));

        sweepElements.push_back(SweepElement(i,
                                             rectangles [i].x + rectangles [i].width,
                                             rectangles [i].y,
                                             rectangles [i].y + rectangles [i].height,
                                             CLOSE));
    }

    sort (sweepElements.begin(), sweepElements.end());


    int solution = 0;

    for (int i = 0; i < sweepElements.size(); i++)
    {
        SweepElement element = sweepElements [i];

        if (i == 0)
        {
            S.insert(SetObject(element.getTop(), TOP));
            S.insert(SetObject(element.getTop(), BOTTOM));



            continue;
        }

        if (element.type == OPEN)
        {

        }
        else
        {

        }
    }

    return 0;
}





































