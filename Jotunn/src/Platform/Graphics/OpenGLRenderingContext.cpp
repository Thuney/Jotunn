#include "OpenGLRenderingContext.h"

#include "../../Core/CoreInclude.h"

namespace Jotunn 
{

	OpenGLRenderingContext::OpenGLRenderingContext(GLFWwindow* windowHandle) : m_WindowHandle(windowHandle)
	{

	}

	//Hardcoded strings for the very simple shaders required for drawing the white triangle

	const GLchar* vertex_shader =
		"#version 150"										//Defines the GLSL version of this shader to be 1.50
		"\n"
		"in vec2 position;"									//Defines an input to the shader which is a 2-dimensional vector
		"\n"
		"void main()"
		"{"
		"	gl_Position = vec4(position, 0.0, 1.0);"		//Set the homogenous coordinates of the vertex given our 2D vector input
		"};";

	const GLchar* fragment_shader =
		"#version 150"										//Defines the GLSL version of this shader to be 1.50
		"\n"
		"out vec4 outColor;"								//Defines an output to the shader which is a 4-dimensional vector
		"\n"
		"void main()"
		"{"
		"	outColor = vec4(1.0, 1.0, 1.0, 1.0);"			//Set the value of the (in this case constant and white) color output
		"}";

	void OpenGLRenderingContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = glewInit();


		//Create and compile our vertex shader from our vertex shader source code
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertex_shader, NULL);
		glCompileShader(vertexShader);

		//Get the status of our shader compilation. If successful, vertStatus == 1
		GLint vertStatus;
		char vertCompLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vertStatus);
		if (!vertStatus)
		{
			//If an error occurs during compilation, we grab the error log
			glGetShaderInfoLog(vertexShader, 512, NULL, vertCompLog);

			JOTUNN_INFO(vertCompLog);
		}

		//Create and compile our fragment shader from our fragement shader source code
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
		glCompileShader(fragmentShader);

		//Get the status of our shader compilation. If successful, fragStatus == 1
		GLint frag_status;
		char frag_CompLog[512];
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &frag_status);
		if (!frag_status)
		{
			//If an error occurs during compilation, we grab the error log
			glGetShaderInfoLog(vertexShader, 512, NULL, frag_CompLog);

			JOTUNN_INFO(frag_CompLog);
		}


		//Create a shader program and add our vertex and fragment shaders to it
		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		//Specify that the outColor is to be output to buffer 0
		glBindFragDataLocation(shaderProgram, 0, "outColor");

		//Link the individual shaders together in the shader program and set the program to be used
		glLinkProgram(shaderProgram);

		//Get the status of our shader program linking. If successful, shaderLinkStatus = 1
		GLint shader_LinkStatus;
		char shader_LinkLog[512];
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &shader_LinkStatus);
		if (!shader_LinkStatus)
		{
			//If an error occurs during compilation, we grab the error log
			glGetProgramInfoLog(shaderProgram, 512, NULL, shader_LinkLog);

			JOTUNN_INFO(shader_LinkLog);
		}

		//Now that we have compiled the shaders into a single program, we can dispose of them
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		//Initialization and binding of a vertex array object for linking our vertex attributes to
		//our vertex buffer object containing the vertex data. The VAO has to be instantiated and bound 
		//before the vertex buffer object and vertex attribute arrays, and those components will be automatically
		//added to the VAO when they are instantiated
		glGenVertexArrays(1, &vao);

		//Initialization of our vertex buffer object, which stores the vertex data for the triangle we're trying to draw
		glGenBuffers(1, &vbo);

		//Create VAO[0] with settings for triangle 1
		glBindVertexArray(vao);

		//Hardcoded array of our triangle vertices in (X, Y) pairs
		//Note that these values are in the range [-1.0, 1.0] to fit in
		//OpenGL's unprojected coordinate system
		triangle_vertices = new float[6]
		{
			//First Triangle
			0.0f, 0.5f,  //Vertex 1 (X, Y), top point
			0.5f, -0.5f,  //Vertex 2 (X, Y), bottom right point
			-0.5f, -0.5f, //Vertex 3 (X, Y), bottom left point
		};

		//Set the vbo as the system's active buffer
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		//Add our vertex data to the vbo
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6, triangle_vertices, GL_STATIC_DRAW);

		//Find the index of the "position" attribute in the vertex shader
		GLint triangle_posAttrib = glGetAttribLocation(shaderProgram, "position");
		//Specify how to interpret the vertex data for our position attribute
		glVertexAttribPointer(triangle_posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(triangle_posAttrib);

		glBindVertexArray(0);

	}

	void OpenGLRenderingContext::SwapBuffers()
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(vao);
		glUseProgram(shaderProgram);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(m_WindowHandle);
	}

}