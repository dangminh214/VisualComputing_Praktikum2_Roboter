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

uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

uniform mat4 transformKeyA_Matrix;
uniform mat4 transformKeyD_Matrix;
uniform mat4 transformKeyW_Matrix;
uniform mat4 transformKeyS_Matrix;

uniform int objectType;

mat4 robotMatrix;
mat4 whenKey_A_D_Press_Matrix;
mat4 whenKey_W_S_Press_Matrix;
mat4 whenKey_Press_Matrix;

out vec3 colorVS;

void main() {
        colorVS = colorRGB;

        robotMatrix = projectionMatrix * viewMatrix * totalTransformMatrix;
        whenKey_Press_Matrix = transformKeyA_Matrix * transformKeyW_Matrix * transformKeyD_Matrix * transformKeyS_Matrix;
        whenKey_A_D_Press_Matrix = transformKeyA_Matrix * transformKeyD_Matrix;
        whenKey_W_S_Press_Matrix = transformKeyW_Matrix * transformKeyS_Matrix;

        if (objectType == 0) {
                gl_Position =   whenKey_A_D_Press_Matrix * robotMatrix * bodyTransformMatrix *  vec4(pos, 1.0) * whenKey_W_S_Press_Matrix;
        }
        if (objectType == 1) {
                gl_Position =   whenKey_A_D_Press_Matrix * robotMatrix *  headTransformMatrix  * vec4(pos, 1.0)* whenKey_W_S_Press_Matrix;
        }
        if (objectType == 2) {
                gl_Position =   whenKey_A_D_Press_Matrix * robotMatrix * leftLegTransformMatrix  * vec4(pos, 1.0)* whenKey_W_S_Press_Matrix;
        }
        if (objectType == 3) {
                gl_Position =  whenKey_A_D_Press_Matrix *robotMatrix * rightLegTransformMatrix  * vec4(pos, 1.0)* whenKey_W_S_Press_Matrix;
        }
        if (objectType == 4) {
                gl_Position = whenKey_A_D_Press_Matrix * robotMatrix * upperLeftArmMatrix   * vec4(pos, 1.0)* whenKey_W_S_Press_Matrix;
        }
        if (objectType == 5) {
                gl_Position = whenKey_A_D_Press_Matrix * robotMatrix *  upperRightArmMatrix  * vec4(pos, 1.0)* whenKey_W_S_Press_Matrix;
        }
        if (objectType == 6) {
                gl_Position = whenKey_A_D_Press_Matrix * robotMatrix  * underLeftArmMatrix * vec4(pos, 1.0)* whenKey_W_S_Press_Matrix ;
        }
        if (objectType == 7) {
                gl_Position = whenKey_A_D_Press_Matrix * robotMatrix * underRightArmMatrix  * vec4(pos, 1.0) * whenKey_W_S_Press_Matrix;
        }
}
