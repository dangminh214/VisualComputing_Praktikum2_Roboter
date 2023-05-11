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

        if (objectType == 0) // Body object
        {
                gl_Position = bodyTransformMatrix * totalTransformMatrix * vec4(pos, 1.0);
        }
        if (objectType == 1) // Head object
        {
                gl_Position = headTransformMatrix * totalTransformMatrix * vec4(pos, 1.0);
        }
        if (objectType == 2) {
                gl_Position = leftLegTransformMatrix *totalTransformMatrix * vec4(pos, 1.0);
        }
        if (objectType == 3) {
                gl_Position = rightLegTransformMatrix * totalTransformMatrix *  vec4(pos, 1.0);
        }
        if (objectType == 4) {
                gl_Position = upperLeftArmMatrix * totalTransformMatrix * vec4(pos, 1.0);
        }
        if (objectType == 5) {
                gl_Position = upperRightArmMatrix * totalTransformMatrix * vec4(pos, 1.0);
        }
        if (objectType == 6) {
                gl_Position = underLeftArmMatrix * totalTransformMatrix * vec4(pos, 1.0);
        }
        if (objectType == 7) {
                gl_Position = underRightArmMatrix * totalTransformMatrix * vec4(pos, 1.0);
        }

        //gl_Position = transformMatrix * vec4(pos, 1.0);
}
