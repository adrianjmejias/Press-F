#version 330 core


#define sdot(a,b) min( max(dot(a,b), 0) , 1)
#define v4(a) vec4(a,1)
#define color vec4
#define POINT 0
#define DIRECTIONAL 1
#define SPOT 2

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

uniform struct Material
{
	color kD;
	color kA;
	color kS;
	color kE;
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
	color kD;
	color kA;
	color kS;
} LIGHTS[1];


in struct {
	vec4 m_pos;
	vec4 w_pos;
	vec4 norm;
	vec4 uv;
} obj;

out color fColor;

void main()
{
//    vec3 dir_view = normalize(view.pos - );

	fColor = LIGHTS[0].kD;
}