#pragma once

#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>

class window{
public:
	window();
	window(const std::string& title , const sf::Vector2u& size);
	void begin_draw();
	void end_draw();
	void update_func();
	sf::Vector2u& getwindowsize();
	void draw_func(sf::Drawable& d_element);
	bool is_done();
	private:
	// functions
	void setup(const std::string& title, const sf::Vector2u& size);
	void create_func();
	void destroy();
	// variables 
	sf::RenderWindow m_window;
	sf::Vector2u m_window_size;
	std::string m_window_title;
	bool done;
};



