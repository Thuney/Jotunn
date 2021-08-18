#version 150										//Defines the GLSL version of this shader to be 1.50

in vec3 position;									//Defines an input to the shader which is a 2-dimensional vector

uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;

void main()
{
	gl_Position = u_ViewProjection * u_Transform * vec4(position, 1.0);		//Set the homogenous coordinates of the vertex given our 2D vector input
}