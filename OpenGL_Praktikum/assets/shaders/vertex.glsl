#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 colorRGB;

uniform mat4 totalTransformMatrix;
uniform mat4 bodyTransformMatrix;
uniform mat4 headTransformMatrix;
uniform mat4 leftLegTransformMatrix;
uniform mat4 rightLegTransformMatrix;
uniform mat4 upperLeftArmMatrix;
uniform mat4 upperRightArmMatrix;
uniform mat4 underLeftArmMatrix;
uniform mat4 underRightArmMatrix;

uniform int objectType;

out vec3 colorVS;

void main(){
        colorVS = colorRGB;

        if (objectType == 0) {
                gl_Position =  bodyTransformMatrix  * vec4(pos, 1.0) * totalTransformMatrix;
        }
        if (objectType == 1) {
                gl_Position =  headTransformMatrix  * vec4(pos, 1.0) * totalTransformMatrix;
        }
        if (objectType == 2) {
                gl_Position =  leftLegTransformMatrix * vec4(pos, 1.0)* totalTransformMatrix;
        }
        if (objectType == 3) {
                gl_Position =  rightLegTransformMatrix * vec4(pos, 1.0)* totalTransformMatrix;
        }
        if (objectType == 4) {
                gl_Position = upperLeftArmMatrix * vec4(pos, 1.0) * totalTransformMatrix;
        }
        if (objectType == 5) {
                gl_Position = upperRightArmMatrix  * vec4(pos, 1.0) * totalTransformMatrix;
        }
        if (objectType == 6) {
                gl_Position = underLeftArmMatrix * vec4(pos, 1.0) * totalTransformMatrix ;
        }
        if (objectType == 7) {
                gl_Position = underRightArmMatrix * vec4(pos, 1.0) * totalTransformMatrix;
        }
}
