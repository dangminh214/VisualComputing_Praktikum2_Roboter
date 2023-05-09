#include "Scene.h"
#include <AssetManager.h>

Scene::Scene(OpenGLWindow * window) :
        m_window(window)
{
    assert(window != nullptr);
}

Scene::~Scene()
{

}
bool Scene::init()
{
    try
    {
        //Load shader
        m_assets.addShaderProgram("shader", AssetManager::createShaderProgram("assets/shaders/vertex.glsl", "assets/shaders/fragment.glsl"));
        m_shader = m_assets.getShaderProgram("shader");
        m_shader->use();
        //Body
        static const float bodyVertices[] =  {

                0.2, -0.4, -0.1, 1, 0, 0,
                0.2, -0.4, 0.1, 0, 1, 0,
                -0.2, -0.4, 0.1, 0, 0, 1,
                -0.2, -0.4, -0.1, 1, 1, 0,
                0.2, 0.4, -0.1, 1, 0, 1,
                0.2, 0.4, 0.1, 0, 1, 1,
                -0.2, 0.4, 0.1, 1, 1, 1,
                -0.2, 0.4, -0.1, 0.5, 1, 0.5
        };

        static const int bodyIndices[] = {
                1, 2, 3,
                7, 6, 5,
                4, 5, 1,
                5, 6, 2,
                2, 6, 7,
                0, 3, 7,
                0, 1, 3,
                4, 7, 5,
                0, 4, 1,
                1, 5, 2,
                3, 2, 7,
                4, 0, 7
        };

        //Head
        static const float headVertices[] = {
                0.1, 0.5, -0.1, 1, 0, 1,
                0.1, 0.5, 0.1, 1,0,1,
                -0.1, 0.5, 0.1, 1, 0, 1,
                -0.1, 0.5, -0.1, 1,0,1,

                0.1, 0.8, -0.1, 1, 0, 1,
                0.1, 0.8, 0.1, 1,0,1,
                -0.1, 0.8, 0.1, 1, 0, 1,
                -0.1, 0.8, -0.1, 1,0,1
        };
        static const int headIndices[] = {
                1, 2, 3,
                7, 6, 5,
                4, 5, 1,
                5, 6, 2,
                2, 6, 7,
                0, 3, 7,
                0, 1, 3,
                4, 7, 5,
                0, 4, 1,
                1, 5, 2,
                3, 2, 7,
                4, 0, 7
        };

        static const float leftLegVertices[] = {
                -0.1, -0.8, -0.1, 1, 0, 0,
                -0.1, -0.8, 0.1, 0, 1, 0,
                -0.2, -0.8, 0.1, 0, 0, 1,
                -0.2, -0.8, -0.1, 1, 1, 0,
                -0.1, -0.5, -0.1, 1, 0, 1,
                -0.1, -0.5, 0.1, 0, 1, 1,
                -0.2, -0.5, 0.1, 1, 1, 1,
                -0.2, -0.5, -0.1, 1, 1, 0
        };
        static const int leftLegIndices[] = {
                1, 2, 3,
                7, 6, 5,
                4, 5, 1,
                5, 6, 2,
                2, 6, 7,
                0, 3, 7,
                0, 1, 3,
                4, 7, 5,
                0, 4, 1,
                1, 5, 2,
                3, 2, 7,
                4, 0, 7
        };

        static const float rightLegVertices[] = {
                0.2, -0.8, -0.1, 1, 0, 0,
                0.2, -0.8, 0.1, 0, 1, 0,
                0.1, -0.8, 0.1, 0, 0, 1,
                0.1, -0.8, -0.1, 1, 1, 0,
                0.2, -0.5, -0.1, 1, 0, 1,
                0.2, -0.5, 0.1, 0, 1, 1,
                0.2, -0.5, 0.1, 1, 1, 1,
                0.1, -0.5, -0.1, 1, 1, 0
        };
        static const int rightLegIndices[] = {
                1, 2, 3,
                7, 6, 5,
                4, 5, 1,
                5, 6, 2,
                2, 6, 7,
                0, 3, 7,
                0, 1, 3,
                4, 7, 5,
                0, 4, 1,
                1, 5, 2,
                3, 2, 7,
                4, 0, 7
        };

        static const float upperLeftArmVertices[] =  {

                -0.3, 0, -0.1, 1, 1, 0,
                -0.3, 0, 0.1, 1, 1, 0,
                -0.4, 0, 0.1, 1, 1, 0,
                -0.4, 0, -0.1, 1, 1, 0,
                -0.3, 0.4, -0.1, 1, 1, 0,
                -0.3, 0.4, 0.1, 1, 1, 0,
                -0.4, 0.4, 0.1, 1, 1, 0,
                -0.4, 0.4, -0.1, 1, 1, 0,
        };

        static const int upperLeftArmIndices[] = {
                1, 2, 3,
                7, 6, 5,
                4, 5, 1,
                5, 6, 2,
                2, 6, 7,
                0, 3, 7,
                0, 1, 3,
                4, 7, 5,
                0, 4, 1,
                1, 5, 2,
                3, 2, 7,
                4, 0, 7
        };

        static const float upperRightArmVertices[] =  {

                0.4, 0, -0.1, 0, 0, 1,
                0.4, 0, 0.1, 0, 0, 1,
                0.3, 0, 0.1, 0, 0, 1,
                0.3, 0, -0.1, 0, 0, 1,
                0.4, 0.4, -0.1, 0, 0, 1,
                0.4, 0.4, 0.1, 0, 0, 1,
                0.3, 0.4, 0.1, 0, 0, 1,
                0.3, 0.4, -0.1, 0, 0, 1
        };

        static const int upperRightArmIndices[] = {
                1, 2, 3,
                7, 6, 5,
                4, 5, 1,
                5, 6, 2,
                2, 6, 7,
                0, 3, 7,
                0, 1, 3,
                4, 7, 5,
                0, 4, 1,
                1, 5, 2,
                3, 2, 7,
                4, 0, 7
        };



        //body Setup
        glGenBuffers(1, &vboIDBody);
        glBindBuffer(GL_ARRAY_BUFFER, vboIDBody);
        glBufferData(GL_ARRAY_BUFFER, sizeof(bodyVertices), &bodyVertices, GL_STATIC_DRAW);

        glGenVertexArrays(1, &vaoIDBody);
        glBindVertexArray(vaoIDBody);

        glVertexAttribPointer(0,3,GL_FLOAT, false, 6*sizeof(float),(void*)0);
        glVertexAttribPointer(1, 3, GL_FLOAT, false, 6*sizeof(float), (void*)(3*sizeof(float)));

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glGenBuffers(1, &iboIDBody);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboIDBody);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(bodyIndices), bodyIndices, GL_STATIC_DRAW);

        //Head Setup
        glGenBuffers(1, &vboIDHead);
        glBindBuffer(GL_ARRAY_BUFFER, vboIDHead);
        glBufferData(GL_ARRAY_BUFFER, sizeof(headVertices), &headVertices, GL_STATIC_DRAW);

        glGenVertexArrays(1, &vaoIDHead);
        glBindVertexArray(vaoIDHead);

        glVertexAttribPointer(0,3,GL_FLOAT, false, 6*sizeof(float),(void*)0);
        glVertexAttribPointer(1, 3, GL_FLOAT, false, 6*sizeof(float), (void*)(3*sizeof(float)));

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glGenBuffers(1, &iboIDHead);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboIDHead);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(headIndices), headIndices, GL_STATIC_DRAW);

        //left Leg Setup
        glGenBuffers(1, &vboIDleftLeg);
        glBindBuffer(GL_ARRAY_BUFFER, vboIDleftLeg);
        glBufferData(GL_ARRAY_BUFFER, sizeof(leftLegVertices), &leftLegVertices, GL_STATIC_DRAW);

        glGenVertexArrays(1, &vaoIDleftLeg);
        glBindVertexArray(vaoIDleftLeg);

        glVertexAttribPointer(0,3,GL_FLOAT, false, 6*sizeof(float),(void*)0);
        glVertexAttribPointer(1, 3, GL_FLOAT, false, 6*sizeof(float), (void*)(3*sizeof(float)));

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glGenBuffers(1, &iboIDleftLeg);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboIDleftLeg);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(leftLegIndices), leftLegIndices, GL_STATIC_DRAW);

        //right Leg Setup
        glGenBuffers(1, &vboIDleftLeg);
        glBindBuffer(GL_ARRAY_BUFFER, vboIDleftLeg);
        glBufferData(GL_ARRAY_BUFFER, sizeof(rightLegVertices), &rightLegVertices, GL_STATIC_DRAW);

        glGenVertexArrays(1, &vaoIDrightLeg);
        glBindVertexArray(vaoIDrightLeg);

        glVertexAttribPointer(0,3,GL_FLOAT, false, 6*sizeof(float),(void*)0);
        glVertexAttribPointer(1, 3, GL_FLOAT, false, 6*sizeof(float), (void*)(3*sizeof(float)));

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glGenBuffers(1, &iboIDrightLeg);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboIDrightLeg);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(rightLegIndices), rightLegIndices, GL_STATIC_DRAW);

        //upper Left Arm Setup
        glGenBuffers(1, &vboIDupperLeftArm);
        glBindBuffer(GL_ARRAY_BUFFER, vboIDupperLeftArm);
        glBufferData(GL_ARRAY_BUFFER, sizeof(upperLeftArmVertices), &upperLeftArmVertices, GL_STATIC_DRAW);

        glGenVertexArrays(1, &vaoIDupperLeftArm);
        glBindVertexArray(vaoIDupperLeftArm);

        glVertexAttribPointer(0,3,GL_FLOAT, false, 6*sizeof(float),(void*)0);
        glVertexAttribPointer(1, 3, GL_FLOAT, false, 6*sizeof(float), (void*)(3*sizeof(float)));

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glGenBuffers(1, &iboIDupperLeftArm);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboIDupperLeftArm);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(upperLeftArmIndices), upperLeftArmIndices, GL_STATIC_DRAW);

        //upper Right Arm Setup
        glGenBuffers(1, &vboIDupperRightArm);
        glBindBuffer(GL_ARRAY_BUFFER, vboIDupperRightArm);
        glBufferData(GL_ARRAY_BUFFER, sizeof(upperRightArmVertices), &upperRightArmVertices, GL_STATIC_DRAW);

        glGenVertexArrays(1, &vaoIDupperRightArm);
        glBindVertexArray(vaoIDupperRightArm);

        glVertexAttribPointer(0,3,GL_FLOAT, false, 6*sizeof(float),(void*)0);
        glVertexAttribPointer(1, 3, GL_FLOAT, false, 6*sizeof(float), (void*)(3*sizeof(float)));

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glGenBuffers(1, &iboIDupperRightArm);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboIDupperRightArm);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(upperRightArmIndices), upperRightArmIndices, GL_STATIC_DRAW);

        //unbind all
        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


        //Praktikum1 Aufgabe 4
        glEnable(GL_CULL_FACE);
        glFrontFace(GL_CCW);
        glCullFace(GL_BACK);

        std::cout << "Scene initialization done\n";
        return true;
    }
    catch (std::exception& ex)
    {
        throw std::logic_error("Scene initialization fa, it uses count sequential elements from each enabled array to construct a sequence of geometric primitives, beginning with element first. mode specifies what kind of primitives are constructed and how the array elements construct those primitives.     iled:\n" + std::string(ex.what()) + "\n");
    }
}

void Scene::render(float dt)
{
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set clear color to dark blue-gray
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    //render Body
    glBindVertexArray(vaoIDBody);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

    //render Head
    glBindVertexArray(vaoIDHead);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

    //render Left Leg
    glBindVertexArray(vaoIDleftLeg);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

    //render Right Leg
    glBindVertexArray(vaoIDrightLeg);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

    //render upper Left Arm
    glBindVertexArray(vaoIDupperLeftArm);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

    //render upper Left Arm
    glBindVertexArray(vaoIDupperRightArm);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

    glBindVertexArray(0); // unbind VAO
}
void Scene::update(float dt)
{

}

OpenGLWindow * Scene::getWindow()
{
    return m_window;
}

void Scene::onKey(Key key, Action action, Modifier modifier)
{

}

void Scene::onMouseMove(MousePosition mouseposition)
{

}

void Scene::onMouseButton(MouseButton button, Action action, Modifier modifier)
{

}

void Scene::onMouseScroll(double xscroll, double yscroll)
{

}

void Scene::onFrameBufferResize(int width, int height)
{

}
void Scene::shutdown()
{
    glDeleteVertexArrays(1, &vaoIDBody);
    glDeleteBuffers(1, &vboIDBody);
}

