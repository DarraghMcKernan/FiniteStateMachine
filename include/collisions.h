#include <iostream>
#include <cmath>

class Circle
{
public:

    Circle(float t_x, float t_y, float t_radius)
    {
        x = t_x;
        y = t_y;
        radius = t_radius;
    };


    static bool checkCircles(Circle * circle1, Circle * circle2)
    {
        double sqDistance = ((circle2->x - circle1->x)*(circle2->x - circle1->x)) + ((circle2->y - circle1->y)*(circle2->y - circle1->y));
        double lengthBetweenCircles = sqrt(sqDistance);
        float radiusLength = circle1->radius + circle2->radius;
        if(lengthBetweenCircles >= radiusLength)
        {
            return false; 
        }
        else 
        {
            return true;
        }
    }

private:
    float radius = 0;
    float x = 0;
    float y = 0;
};

class Rect
{
public:

    Rect(float t_x, float t_y, float t_width, float t_height)
    {
        x = t_x;
        y = t_y;
        width = t_width;
        height = t_height;
    };

    static bool rectangleCollisions(Rect * rect1, Rect * rect2)
    {
        bool xOverlap = valueInRange(rect1->x, rect2->x, rect2->x + rect2->width) || valueInRange(rect2->x, rect1->x, rect1->x + rect1->width);

        bool yOverlap = valueInRange(rect1->y, rect2->y, rect2->y + rect2->height) || valueInRange(rect2->y, rect1->y, rect1->y + rect1->height);

        if(xOverlap == true && yOverlap == true)
        {
            return true;
        }
        else{
            return false;
        }
    }

       static bool valueInRange(int value, int min, int max)
    {
        return (value >= min) && (value <= max); 
    }

private:
    float x;
    float y;
    float width;
    float height;
};