#version 150									//Defines the GLSL version of this shader to be 1.50

in vec3 f_color;

out vec4 outColor;								//Defines an output to the shader which is a 4-dimensional vector

void main()
{
	outColor = vec4(f_color, 1.0);				//Set the value of the color output
}