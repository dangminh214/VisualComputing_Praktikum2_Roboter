#pragma once

#include "OpenGLWindow.h"
#include <ShaderProgram.h>
#include <memory>
#include <AssetManager.h>
#include "Transform.h"

class Scene
{
public:
    Scene(OpenGLWindow* window);
    ~Scene();

    bool init();
    void shutdown();
    void render(float dt);
    void update(float dt);
    OpenGLWindow* getWindow();

    void onKey(Key key, Action action, Modifier modifier);
    void onMouseMove(MousePosition mouseposition);
    void onMouseButton(MouseButton button, Action action, Modifier modifier);
    void onMouseScroll(double xscroll, double yscroll);
    void onFrameBufferResize(int width, int height);

private:
    OpenGLWindow* m_window;
    AssetManager m_assets;
    ShaderProgram* m_shader;

    glm::vec3 direction_A;
    glm::vec3 direction_D;
    glm::vec3 direction_W;
    glm::vec3 direction_S;

    glm::vec3 cameraPosition = glm::vec3(0,0,4.0);

    //Attributes to render
    GLuint vaoIDBody, vboIDBody, iboIDBody;

    GLuint vaoIDHead, vboIDHead, iboIDHead;

    GLuint vaoIDleftLeg, vboIDleftLeg, iboIDleftLeg;

    GLuint vaoIDrightLeg, vboIDrightLeg, iboIDrightLeg;

    GLuint vaoIDupperLeftArm, vboIDupperLeftArm, iboIDupperLeftArm;

    GLuint vaoIDupperRightArm, vboIDupperRightArm, iboIDupperRightArm;

    GLuint vaoIDunderLeftArm, vboIDunderLeftArm, iboIDunderLeftArm;

    GLuint vaoIDunderRightArm, vboIDunderRightArm, iboIDunderRightArm;

};

