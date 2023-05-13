#version 330 core

in vec3 colorVS;

//fragment shader output
out vec4 fragColor;

//uniform variable
uniform vec3 color;
uniform float time;

void main(){
    vec3 finalColor = vec3(colorVS) * color * (sin(time))*3;
    finalColor = max(finalColor, vec3(0.1));
    fragColor = vec4(finalColor, 1.0);
}

