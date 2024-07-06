#include "SortedUnit.h"



SortedUnit::SortedUnit(float position_x, float position_y, float width, float height){
	shape.setOrigin(0, height);
	shape.setPosition(Vector2f(position_x, position_y));
	shape.setSize(Vector2f(width, height));
	shape.setFillColor(Color::White);
	unit_value = height;

}


void SortedUnit::draw(RenderTarget& target, RenderStates state) const {
	target.draw(shape, state);
}



float SortedUnit::get_unit_value() {
	return unit_value;
}

void SortedUnit::set_unit_value(float x){ 
	this->unit_value = x; 
	shape.setSize(Vector2f(shape.getSize().x, x));
	
}

void SortedUnit::unit_setColor(Color x) {
	shape.setFillColor(x);
}



//Vector2f SortedUnit::get_position() {
//	return shape.getPosition();
//}
//
//void SortedUnit::set_position(Vector2f x) {
//	shape.setPosition(x);
//}





