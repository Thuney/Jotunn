#version 150									//Defines the GLSL version of this shader to be 1.50

uniform vec3 u_Color;

out vec4 outColor;								//Defines an output to the shader which is a 4-dimensional vector

void main()
{
	outColor = vec4(u_Color, 1.0);				//Set the value of the color output
}