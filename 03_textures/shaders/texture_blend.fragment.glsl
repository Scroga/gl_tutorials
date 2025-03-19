#version 430 core

uniform sampler2D u_textureSampler1;
uniform sampler2D u_textureSampler2;
uniform sampler2D u_mixFactor;

out vec4 out_fragColor;

in vec4 f_normal;
in vec2 f_texCoord;

void main() 
{
	vec4 tex1 = texture(u_textureSampler1, f_texCoord);
	vec4 tex2 = texture(u_textureSampler2, f_texCoord);
	float factor = texture(u_mixFactor, f_texCoord).r;
	out_fragColor = factor*tex1 + (1 - factor)*tex2;
}

