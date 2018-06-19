#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "..\Includes\Shader.h"
#include <iostream>
#include "..\Includes\Maths/Camera.h"
#include "..\Includes\Maths/Transform.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;

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

	//Shader ourShader("D:/Shagufta/OpenGL_Workspace/BouncingBall/BouncingBall/Shader/VertexShader.vs", "D:/Shagufta/OpenGL_Workspace/BouncingBall/BouncingBall/Shader/FragmentShader.fs");

	Shader ourShader("D:/Shagufta/OpenGL_Workspace/BouncingBall/BouncingBall/Shader/LightVertexShader.vs", "D:/Shagufta/OpenGL_Workspace/BouncingBall/BouncingBall/Shader/LightFragmentShader.fs");

	
	
	//float vertices[] = {
	//	// front
	//	-0.2, -0.2, -0.5, 
	//	 0.2, -0.2, -0.5, 
	//	 0.2,  0.2, -0.5,  
	//	-0.2,  0.2, -0.5,
	//				 
	//	-0.2, -0.2,  0.5 ,  
	//	 0.2, -0.2,  0.5 ,    
	//	 0.2,  0.2,  0.5 ,    
	//	-0.2,  0.2,  0.5    
	//};


												   

	//float vertices[] = {
	//	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,      //(0)
	//	0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,       //(1)
	//	0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,        //(3)
	//	0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,        //(4)
	//	-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,        //(5)
	//	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,        //(6)

	//	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,        //(7)
	//	0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,          //(8)
	//	0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,           //(9)
	//	0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,			   //(10)
	//	-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,		   //(11)
	//	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,		   //(12)

	//	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,		   //(13)
	//	-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,		   //(14)
	//	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,		   //(15)
	//	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,		   //(16)
	//	-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,		   //(17)
	//	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,		   //(18)

	//	0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
	//	0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
	//	0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
	//	0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
	//	0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
	//	0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

	//	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
	//	0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
	//	0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
	//	0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
	//	-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
	//	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

	//	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
	//	0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
	//	0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
	//	0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
	//	-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
	//	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
	//};

	float colorVertices[] = {
		// front
		-0.2, -0.1, -0.5,
		0.1, -0.2, -0.35,
		0.21,  0.23, -0.5,
		-0.2,  0.2, -0.5,

		-0.2, -0.2,  0.5 ,
		0.2, -0.2,  0.5 ,
		0.2,  0.2,  0.5 ,
		-0.2,  0.2,  0.5
	};

	//float vertices[] = {
	//	// front
	//	-0.5 , -0.5,  0.5 , //bottom left
	//	 0.5 , -0.5,  0.5 ,  //bottom right
	//	 0.5 ,  0.5,  0.5 ,  //top right
	//	-0.5 ,  0.5,  0.5 , //top left
	//	
	//	// back
	//	-0.5 , -0.5, -0.5 ,   //bottom left
	//	 0.5 , -0.5, -0.5 ,    //bottom right
	//	 0.5 ,  0.5, -0.5 ,     //top right
	//	-0.5 ,  0.5, -0.5    //top left
	//};


	//unsigned int indices[] = {
	//	//front
	//	0,1,2,
	//	0,3,2,

	//	//right face
	//	1,5,6,
	//	1,2,6,

	//	//bottom face
	//	0,1,5,
	//	0,4,5,

	//	//top face
	//	3,2,6,
	//	3,7,6,

	//	//left face

	//	0,4,7,
	//	0,3,7,

	//	//back face
	//	4,5,6,
	//	4,7,6

	//};


	float vertices[] = {
		// front
		-0.2, -0.2, -0.5,   0.0, 0.0, 1.0f,		   //(0)
		0.2, -0.2, -0.5,   0.0, 0.0, 1.0f,		   //(1)
		0.2,  0.2, -0.5,   0.0, 0.0, 1.0f,		   //(2)
		-0.2,  0.2, -0.5,   0.0, 0.0, 1.0f,		   //(3)


		 //back									   
		 -0.2,  -0.2,  0.5 ,  0.0, 0.0, -1.0f,	   //(4)
		 0.2,  -0.2,  0.5 ,  0.0, 0.0, -1.0f,	   //(5)
		 0.2,   0.2,  0.5 ,  0.0, 0.0, -1.0f,	   //(6)
		 -0.2,   0.2,  0.5,   0.0, 0.0, -1.0f,	   //(7)

		 //left									   
		-0.2, -0.2, -0.5,   1.0, 0.0, 0.0f,		   //(8)
		-0.2,  -0.2, 0.5,   1.0, 0.0, 0.0f,		   //(9)
		-0.2,   0.2, 0.5,	1.0, 0.0, 0.0f,		   //(10)
		-0.2,  0.2, -0.5,	1.0, 0.0, 0.0f,		   //(11)

		 //right								   
		 0.2,  -0.2, -0.5,  -1.0, 0.0, 0.0f,	   //(12)
		 0.2,   0.2, -0.5,  -1.0, 0.0, 0.0f,	   //(13)
		 0.2,   0.2,  0.5,  -1.0, 0.0, 0.0f,	   //(14)
		 0.2,  -0.2,  0.5,  -1.0, 0.0, 0.0f,	   //(15)

		 //top								   
		 -0.2,  0.2, -0.5,  0.0, 1.0, 0.0f,		   //(16)
		 0.2,  0.2, -0.5,  0.0, 1.0, 0.0f,		   //(17)
		 0.2,  0.2,  0.5,  0.0, 1.0, 0.0f,		   //(18)
		 -0.2,  0.2,  0.5,  0.0, 1.0, 0.0f,		   //(19)

		// bottom
		-0.2, -0.2, -0.5,  0.0,-1.0, 0.0f,        //(20)
		-0.2, -0.2,  0.5,  0.0,-1.0, 0.0f,        //(21)
		 0.2, -0.2,  0.5,  0.0,-1.0, 0.0f,        //(22)
		 0.2, -0.2, -0.5,  0.0,-1.0, 0.0f,        //(23)
	};


	unsigned int indices[] = {
		//front
		0,1,2,
		0,2,3,

		//right face
		12,14,13,
		12,15,14,

		//bottom face
		20,21,22,
		20,22,23,

		//top face
		16,17,18,
		16,18,19,

		//left face

		8,10,9,
		8,11,10,

		//back face
		4,6,5,
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

	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof(float),nullptr);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER,0);

	glBindVertexArray(0);

	/*unsigned int lightVAO,lightVBO,lightEBO;
	glGenVertexArrays(1,&lightVAO);
	glGenBuffers(1,&lightVBO);
	glGenBuffers(1, &lightEBO);
	glBindVertexArray(lightVAO);

	glBindBuffer(GL_ARRAY_BUFFER, lightVBO);
	glBufferData(GL_ARRAY_BUFFER,sizeof(colorVertices),colorVertices,GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, lightVBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
	glEnableVertexAttribArray(0);*/

	


	Transform trans;
	Camera camera = Camera(Vector3(2, 2, 2), Vector3(0, 0, 0), 0.01f, 5000.0f, 60);
	/*Camera camera=Camera(Vector3(0,2,-2),Vector3(0,0,1),Vector3(0,1,0),0.01f,5000.0f,60);*/

	//Transform trans=Transform(Vector3(0,0,5));
	//trans.Scale(Vector3(0.1f,0.1f,0.1f));
	//trans.Translation(Vector3(0,0,-1));

	

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		ourShader.use();

		ourShader.setVec3("objectColor", 1.0f, 0.2f, 0.51f);
		ourShader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);

	//	ourShader.setMat4("view", Matrix4::IdentityMat);
		ourShader.setMat4("view", camera.viewMatrix);
		ourShader.setMat4("projection", camera.projectionMatrix);

		//ourShader.setMat4("model",Matrix4::IdentityMat);
		ourShader.setMat4("model", trans.modelMatrix);

		glBindVertexArray(VAO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
		//glDrawArrays(GL_TRIANGLES,0,3);
		glDrawElements(GL_TRIANGLES,36,GL_UNSIGNED_INT,0);
		

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	/*glDeleteVertexArrays(1, &lightVAO);
	glDeleteBuffers(1, &lightVBO);
	glDeleteBuffers(1, &lightEBO);*/
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