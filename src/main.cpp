/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "core.hpp"

#include "resource_dir.hpp"	// utility header for SearchAndSetResourceDir

int main ()
{
	SWindow window(1280, 800, "Hello Raylib");
	window.get_root()->add_child(new STextNode("Hello World!"));
	// std::cout << "Starting main loop" << std::endl;
	
	return 0;
}
