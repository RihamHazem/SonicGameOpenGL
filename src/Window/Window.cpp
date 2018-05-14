#include "Window.h"

/* Constructs a new Window with the defined properties */
Window::Window(int width, int height, const char* title) {
	// Init GLFW
	if (!glfwInit()) {
		cout << "Failed to initialize GLFW" << endl;
		return;
	}

	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create a GLFWwindow object that we can use for GLFW's functions
	mWind = glfwCreateWindow(width, height, title, NULL, NULL);
	if (mWind == NULL) {
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(mWind);

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;

	// Initialize GLEW to setup the OpenGL Function pointers
	if (glewInit() != GLEW_OK) {
		cout << "Failed to initialize GLFW" << endl;
		glfwTerminate();
		return;
	}

	// Define viewport's dimensions as Window's size
	glViewport(0, 0, width, height);

	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);

	// Setup OpenGL options
	glEnable(GL_MULTISAMPLE);
	glEnable(GL_DEPTH_TEST);

	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	// Specify the polygon drawing mode: fill, line or point
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

/* Destructs current Window and release any used resources */
Window::~Window() {
	glfwTerminate();	// Terminate GLFW, clearing any resources allocated by GLFW.
}

/* Returns wether the window requested to close or not */
bool Window::CloseRequested() const {
	return glfwWindowShouldClose(this->mWind);
}

/* Swaps the back screen buffer with the front buffer */
void Window::SwapBuffers() {
	glfwSwapBuffers(mWind);
}

/* Processes the recived events by calling the corresponding callbacks */
void Window::PollEvents() {
	glfwPollEvents();
}

/* Clears the screen buffer */
void Window::ClearScreen() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

/* Sets the color used when clearing the screen */
void Window::SetClearColor(double red, double green, double blue, double alpha) {
	glClearColor(red, green, blue, alpha);
}

/* Sets Window's size */
void Window::SetSize(int width, int height) {
	glfwSetWindowSize(this->mWind, width, height);
	glViewport(0, 0, width, height);
}

/* Gets Window's size */
void Window::GetSize(int* width, int* height) const {
	glfwGetWindowSize(this->mWind, width, height);
}

/* Set Window's position */
void Window::SetPosition(int xpox, int ypos) {
	glfwSetWindowPos(this->mWind, xpox, ypos);
}

/* Shows or hides the mouse */
void Window::EnableMouse(bool enable) {
	glfwSetInputMode(this->mWind, GLFW_CURSOR, enable ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED);
}
