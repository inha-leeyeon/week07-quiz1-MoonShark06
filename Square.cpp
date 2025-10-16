#include "Square.h"

Square::Square(const string name, int x, int y, unsigned int side):Point(x,y), side(0) {
	this->name = name;
	this->side = side;
}
unsigned int Square::getSide() const{
	return side;
}
unsigned int Square::getArea() const {
	return side * side;
}
string Square::getName() const {
	return name;
}
void Square::setSide(unsigned int side) {
	this->side = side;
}
void Square::setArea(unsigned int side) {
	area = side * side;
}
void Square::setName(string name) {
	this->name = name;
}