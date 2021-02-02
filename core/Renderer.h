#pragma once

#include "Engine/event/Event.h"
#include "SFML/Graphics.hpp"
#include <queue>

namespace VEngine
{
	class Renderer
	{
	private:

		struct drawData
		{
			drawData(sf::Drawable* drawable,sf::RenderStates states,sf::Uint8 layer) : drawable(drawable),states(states),layer(layer) {};
			bool operator<(const drawData& other) const { return (this->layer < other.layer) ;}
			sf::Drawable* drawable;
			sf::RenderStates states;
			sf::Uint8 layer;
		};

	public:
		static Renderer& init() { static Renderer instance; return instance; }

		void handleEvent(Event event);
		void draw();

	private:
		sf::RenderWindow* window;
		std::priority_queue<drawData,std::vector<drawData>> drawables;

		Renderer();
		~Renderer();
	};
}