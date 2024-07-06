#include <SFML/Graphics.hpp>
using namespace sf;

class SortedUnit :public Drawable
{
public: 
	SortedUnit(float position_x, float position_y, float width ,float height);

	float get_unit_value();	
	void set_unit_value(float x);


	//Vector2f get_position();
	//void set_position(Vector2f);


	void unit_setColor(Color x);

private:
	float unit_value;
	RectangleShape shape;
	void draw(RenderTarget& target, RenderStates state) const override;

};

