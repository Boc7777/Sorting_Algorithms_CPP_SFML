#include <vector>
#include <SFML/Graphics.hpp>
#include "SortedUnit.h"
#include <cstdlib>
#include <iostream>

using namespace sf;
using namespace std;
const int display_width = 1200;
const int dispplay_height = 800;


float unit_width = 10;


//function to change 2 rectangle each other 
void Change_Two_Units(int index_a, int index_b, vector<SortedUnit>& vec) {
	
	float value_bufor = vec[index_b].get_unit_value();
	
	vec[index_b].set_unit_value(vec[index_a].get_unit_value());
	vec[index_a].set_unit_value(value_bufor);


	vec[index_b].unit_setColor(Color::Red);
	vec[index_a].unit_setColor(Color::Red);
}


int main() {

	RenderWindow window(VideoMode(display_width, dispplay_height), "sort");
	Event event;
	vector<SortedUnit> SortedUnits;
	srand(time(0));
	/*window.setFramerateLimit(10000);*/
	


	//Create random rectangles
	for (int i = 0; i < display_width / (unit_width + 1);i++) {
		SortedUnits.emplace_back(i * (unit_width + 1), dispplay_height, unit_width, 0);
	}

	for (auto& unit : SortedUnits) {
		unit.set_unit_value( -((rand() % (dispplay_height - 1)) + 1) );
	}

	


	while (window.isOpen()) {
		window.clear(Color::Black);

		while (window.pollEvent(event)) {

			if (event.type == Event::Closed) {
				window.close();
			}

		}

		
		
		int len = SortedUnits.size();

		//bubble sort algorithm
		for (int i = 0;i < len - 1;i++) {

			for (int a = 0; a < len - 1; a++) {

				if (abs(SortedUnits[a].get_unit_value()) > abs(SortedUnits[a + 1].get_unit_value())) {

					for (SortedUnit& elem : SortedUnits) {
						elem.unit_setColor(Color::White);
					}

					Change_Two_Units(a, a+1, SortedUnits);

					window.clear(Color::Black);
				
					

					for (SortedUnit& elem : SortedUnits) {
						window.draw(elem);
					}

					window.display();

				}
			}

		}

		for (SortedUnit& elem : SortedUnits) {
			elem.unit_setColor(Color::White);
		}

		for (SortedUnit& elem : SortedUnits) {
			window.draw(elem);
		}

		window.display();


		
		

		

		
	}


}