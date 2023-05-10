#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 colorRGB;

uniform mat4 bodyTransformMatrix;

out vec3 colorVS;

void main(){
        colorVS = colorRGB;
        gl_Position = bodyTransformMatrix * vec4(pos, 1.0);
}
