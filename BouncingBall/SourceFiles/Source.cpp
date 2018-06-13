#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "..\Includes\Shader.h"
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	glewInit();

	Shader ourShader("D:/Shagufta/OpenGL_Workspace/BouncingBall/BouncingBall/Shader/VertexShader.vs", "D:/Shagufta/OpenGL_Workspace/BouncingBall/BouncingBall/Shader/FragmentShader.fs");

	float vertices[] = {
		// front
		-0.5, -0.5,  0.5, //bottom left
		0.5, -0.5,  0.5,  //bottom right
		0.5,  0.5,  0.5,  //top right
		-0.5,  0.5,  0.5, //top left
		// back
		-0.5, -0.5, -0.5,   //bottom left
		0.5, -0.5, -0.5,    //bottom right
		0.5,  0.5, 0.5,     //top right
		-0.5,  0.5, -0.5,   //top left
	};

	unsigned int indices[] = {
		//front
		0,1,2,
		0,3,2,

		//right face
		1,5,6,
		1,2,6,

		//bottom face
		0,1,5,
		0,4,5,

		//left face

		0,4,7,
		0,3,7,

		//back face
		4,5,6,
		4,7,6

	};

	unsigned int VBO,VAO,EBO;
	glGenVertexArrays(1,&VAO);
	glGenBuffers(1,&VBO);
	glGenBuffers(1,&EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);

	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),nullptr);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER,0);

	glBindVertexArray(0);

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		ourShader.use();
		glBindVertexArray(VAO);
		//glDrawArrays(GL_TRIANGLES,0,3);
		glDrawElements(GL_TRIANGLES,36,GL_UNSIGNED_INT,0);
		

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}


void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}