#version 330 core


#define sdot(a,b) min( max(dot(a,b), 0) , 1)
#define v4(a) vec4(a,1)
#define vec3 vec4
#define POINT 0
#define DIRECTIONAL 1
#define SPOT 2

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

uniform struct Material
{
	vec3 kD;
	vec3 kA;
	vec3 kS;
	vec3 kE;
	float IOR;
	float shiny;
} MAT;

uniform struct Light
{
	int type;
	vec3 position;
	vec3 attenuation;
	float innerAngle;
	float outerAngle;
	vec3 direction;
	bool isOn;
	vec3 kD;
	vec3 kA;
	vec3 kS;
} LIGHTS[1];



in struct {
	vec4 m_pos;
	vec4 w_pos;
	vec4 norm;
	vec4 uv;
} OBJ;

in vec3 n;


out vec3 fvec3;




void main()
{
    fvec3 = vec4(1,0,0,1);
}
