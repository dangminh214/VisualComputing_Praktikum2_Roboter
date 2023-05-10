#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 colorRGB;

uniform mat4 bodyTransformMatrix;
uniform mat4 headTransformMatrix;

out vec3 colorVS;

void main(){
        colorVS = colorRGB;
        // Apply body transformation to body vertices
                gl_Position = headTransformMatrix * bodyTransformMatrix * vec4(pos, 1.0);
        // Apply head transformation to head vertices
}
