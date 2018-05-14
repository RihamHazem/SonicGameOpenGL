#pragma once
#include <iostream>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
using namespace std;

class Window
{
private:
	

public:
	GLFWwindow* mWind;

	/* Constructs a new Window with the defined properties */
	Window(int width, int height, const char* title);

	/* Destructs current Window and release any used resources */
	~Window();

	/* Returns wether the window requested to close or not */
	bool CloseRequested() const;

	/* Swaps the back screen buffer with the front buffer */
	void SwapBuffers();

	/* Processes the recived events by calling the corresponding callbacks */
	void PollEvents();

	/* Clears the screen buffer */
	void ClearScreen();

	/* Sets the color used when clearing the screen */
	void SetClearColor(double red, double green, double blue, double alpha);

	/* Sets Window's size */
	void SetSize(int width, int height);

	/* Gets Window's size */
	void GetSize(int* width, int* height) const;

	/* Sets Window's position */
	void SetPosition(int xpox, int ypos);

	/* Shows or hides the mouse */
	void EnableMouse(bool enable);
};