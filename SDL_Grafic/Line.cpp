#include "Line.h"

Line::Line() : A(0, 0), B(0, 0), lenght(0) {};

Line::Line(Point A, double lenght) : A(A), lenght(lenght), B(A.x + lenght, A.y) {}

Line::Line(double x, double y, double lenght) : A(x, y), lenght(lenght), B(x + lenght, y) {}

Line::~Line()
{

}

void Line::draw(SDL_Renderer* renderer)
{
	SDL_RenderDrawLine(renderer, A.x, A.y, A.x, A.y);
}

void Line::relocate(double x, double y)
{
	A.x += x;
	A.y += y;
	B.x += x;
	B.y += y;
}

void Line::recalculate()
{
	B.x = A.x + lenght * scale_kef;
	B.y = A.y;
	B.x = B.x * cos(angle) + B.y * sin(angle);

}
