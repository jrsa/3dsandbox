#version 330 core

// texcoords
in vec2 texcoord_v;

out vec4 color;

// samplers
uniform sampler2DRect tex0;
uniform sampler2DRect tex1;

vec4 rgb2luma(vec4 pix)
{
    return vec4(vec3(dot(pix, vec4(0.212, 0.7152, 0.0722, 0.0))), 1.0);
}

// entry point
void main()
{   
    vec4 a = texture(tex0, texcoord_v);
    vec4 b = texture(tex1, texcoord_v);

    color = vec4(rgb2luma(a).r, rgb2luma(b).r, rgb2luma(b).r, 1.0);
}
