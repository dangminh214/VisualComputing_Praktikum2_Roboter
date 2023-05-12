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
                0.1, 0.5, -0.1, 1, 1, 0,
                0.1, 0.5, 0.1, 1,0,1,
                -0.1, 0.5, 0.1, 0, 0, 1,
                -0.1, 0.5, -0.1, 1,0,1,

                0.1, 0.8, -0.1, 0, 0, 1,
                0.1, 0.8, 0.1, 1,0,1,
                -0.1, 0.8, 0.1, 0, 0, 1,
                -0.1, 0.8, -0.1, 0.5,0.5,0.5
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
                -0.1, -0.95, -0.06, 1, 0, 0,
                -0.1, -0.95, 0.06, 0, 1, 0,
                -0.2, -0.95, 0.06, 0, 0, 1,
                -0.2, -0.95, -0.06, 1, 1, 0,
                -0.1, -0.45, -0.06, 1, 0, 1,
                -0.1, -0.45, 0.06, 0, 1, 1,
                -0.2, -0.45, 0.06, 1, 1, 1,
                -0.2, -0.45, -0.06, 1, 1, 0
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
                0.2, -0.95, -0.06, 1, 0, 0,
                0.2, -0.95, 0.06, 0, 1, 0,
                0.1, -0.95, 0.06, 0, 0, 1,
                0.1, -0.95, -0.06, 1, 1, 0,
                0.2, -0.45, -0.06, 1, 0, 1,
                0.2, -0.45, 0.06, 0, 1, 1,
                0.1, -0.45, 0.06, 1, 1, 1,
                0.1, -0.45, -0.06, 1, 1, 0
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

                -0.3, 0, -0.06, 1, 1, 0,
                -0.3, 0, 0.06, 1,0,1,
                -0.4, 0, 0.06, 0, 0, 1,
                -0.4, 0, -0.06, 1,0,1,
                -0.3, 0.4, -0.06, 1, 0, 1,
                -0.3, 0.4, 0.06, 0, 1, 1,
                -0.4, 0.4, 0.06, 1, 1, 1,
                -0.4, 0.4, -0.06, 1, 1, 0,
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

                0.4, 0, -0.06, 1, 1, 0,
                0.4, 0, 0.06, 1,0,1,
                0.3, 0, 0.06, 0, 0, 1,
                0.3, 0, -0.06, 1,0,1,
                0.4, 0.4, -0.06, 1, 0, 1,
                0.4, 0.4, 0.06, 0, 1, 1,
                0.3, 0.4, 0.06, 1, 1, 1,
                0.3, 0.4, -0.06, 1, 1, 0,
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
        static const float underLeftArmVertices[] =  {

                -0.3, -0.35, -0.06, 0.5, 1, 0,
                -0.3, -0.35, 0.06, 0.5, 0, 1,
                -0.4, -0.35, 0.06, 0.5, 1, 0,
                -0.4, -0.35, -0.06, 0, 0, 1,
                -0.3, -0.05, -0.06, 0, 0, 1,
                -0.3, -0.05, 0.06, 0.5, 1, 1,
                -0.4, -0.05, 0.06, 0.5, 0, 1,
                -0.4, -0.05, -0.06, 1, 0, 0,
        };

        static const int underLeftArmIndices[] = {
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

        static const float underRightArmVertices[] =  {

                0.4, -0.35, -0.06, 0.5, 1, 1,
                0.4, -0.35, 0.06, 0.5, 0, 1,
                0.3, -0.35, 0.06, 0.5, 1, 0,
                0.3, -0.35, -0.06, 0, 0, 1,
                0.4, -0.05, -0.06, 0, 0, 1,
                0.4, -0.05, 0.06, 0.5, 1, 1,
                0.3, -0.05, 0.06, 0.5, 0, 1,
                0.3, -0.05, -0.06, 1, 0, 1,
        };

        static const int underRightArmIndices[] = {
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

        //Body Setup
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
        glGenBuffers(1, &vboIDrightLeg);
        glBindBuffer(GL_ARRAY_BUFFER, vboIDrightLeg);
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

        //under Left Arm Setup
        glGenBuffers(1, &vboIDunderLeftArm);
        glBindBuffer(GL_ARRAY_BUFFER, vboIDunderLeftArm);
        glBufferData(GL_ARRAY_BUFFER, sizeof(underLeftArmVertices), &underLeftArmVertices, GL_STATIC_DRAW);

        glGenVertexArrays(1, &vaoIDunderLeftArm);
        glBindVertexArray(vaoIDunderLeftArm);

        glVertexAttribPointer(0,3,GL_FLOAT, false, 6*sizeof(float),(void*)0);
        glVertexAttribPointer(1, 3, GL_FLOAT, false, 6*sizeof(float), (void*)(3*sizeof(float)));

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glGenBuffers(1, &iboIDunderLeftArm);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboIDunderLeftArm);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(underLeftArmIndices), underLeftArmIndices, GL_STATIC_DRAW);

        //under Right Arm Setup
        glGenBuffers(1, &vboIDunderRightArm);
        glBindBuffer(GL_ARRAY_BUFFER, vboIDunderRightArm);
        glBufferData(GL_ARRAY_BUFFER, sizeof(underRightArmVertices), &underRightArmVertices, GL_STATIC_DRAW);

        glGenVertexArrays(1, &vaoIDunderRightArm);
        glBindVertexArray(vaoIDunderRightArm);

        glVertexAttribPointer(0,3,GL_FLOAT, false, 6*sizeof(float),(void*)0);
        glVertexAttribPointer(1, 3, GL_FLOAT, false, 6*sizeof(float), (void*)(3*sizeof(float)));

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glGenBuffers(1, &iboIDunderRightArm);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboIDunderRightArm);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(underRightArmIndices), underRightArmIndices, GL_STATIC_DRAW);

        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_GREATER);
        glClearDepth(0.0);

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
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_GREATER);
    glClearDepth(0.0);
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set clear color to dark blue-gray
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    static float time = 0.0f;
    float positiveAngle = sin(time) * (20.0f);
    float negativeAngle = sin(time) * (-20.0f);

    Transform* totalTransform = new Transform();
    totalTransform->rotate(glm::vec3(0.0, glm::radians(30.0f * time ),0));
    m_shader->setUniform("totalTransformMatrix",  totalTransform->getMatrix(), false);

    //render Head
    Transform* headTransform = new Transform();
    m_shader->setUniform("headTransformMatrix", headTransform->getMatrix(), false);
    m_shader->setUniform("objectType", 1);
    glBindVertexArray(vaoIDHead);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

    //render Left Leg
    Transform* leftLegTransform = new Transform();
    float angleLeftLeg = sin(time) * (30.0f);
    glm::quat leftLegDeltaRot = glm::angleAxis(glm::radians(angleLeftLeg), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::vec3 leftLegPivot = glm::vec3(-0.15f, -0.45f, 0.0f);
    leftLegTransform->rotateAroundPoint(leftLegPivot, leftLegDeltaRot);
    m_shader->setUniform("leftLegTransformMatrix", leftLegTransform->getMatrix(), false);
    m_shader->setUniform("objectType", 2 );
    glBindVertexArray(vaoIDleftLeg);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

    //render Right Leg
    Transform* rightLegTransform = new Transform();
    float angleRightLeg = sin(time) * (-30.0f);
    glm::quat deltaRot = glm::angleAxis(glm::radians(angleRightLeg), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::vec3 pivot = glm::vec3(0.15f, -0.45f, 0.0f);
    rightLegTransform->rotateAroundPoint(pivot, deltaRot);
    m_shader->setUniform("rightLegTransformMatrix", rightLegTransform->getMatrix(), false);
    m_shader->setUniform("objectType", 3 );
    glBindVertexArray(vaoIDrightLeg);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

    //render upper Left Arm
    Transform* upperLeftArmTransform = new Transform();
    glm::quat upperLeftArmDeltaRot = glm::angleAxis(glm::radians(negativeAngle), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::vec3 upperLeftArmPivot = glm::vec3(-0.35f, 0.4f, 0.0f);
    upperLeftArmTransform->rotateAroundPoint(upperLeftArmPivot, upperLeftArmDeltaRot);
    m_shader->setUniform("upperLeftArmMatrix", upperLeftArmTransform->getMatrix(), false);
    m_shader->setUniform("objectType", 4 );
    glBindVertexArray(vaoIDupperLeftArm);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

    //render under Left Arm
    Transform* underLeftArmTransform = new Transform();
    glm::quat underLeftArmDeltaRot = glm::angleAxis(glm::radians(negativeAngle*3), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::vec3 underLeftArmPivot = glm::vec3(-0.35f, 0.15f, 0.0f);

    underLeftArmPivot = upperLeftArmTransform->getMatrix() * glm::vec4(underLeftArmPivot, 1.0f);
    underLeftArmTransform->rotateAroundPoint(underLeftArmPivot, underLeftArmDeltaRot);

    m_shader->setUniform("underLeftArmMatrix", underLeftArmTransform->getMatrix(), false);
    m_shader->setUniform("objectType", 6 );
    glBindVertexArray(vaoIDunderLeftArm);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

    //render Body
    Transform* bodyTransform = new Transform();
    m_shader->setUniform("bodyTransformMatrix", bodyTransform->getMatrix(), false);
    m_shader->setUniform("objectType", 0 );
    glBindVertexArray(vaoIDBody);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

    //render upper Right Arm
    Transform* upperRightArmTransform = new Transform();
    glm::quat upperRightArmDeltaRot = glm::angleAxis(glm::radians(positiveAngle), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::vec3 upperRightArmPivot = glm::vec3(0.35f, 0.4f, 0.0f);
    upperRightArmTransform->rotateAroundPoint(upperRightArmPivot, upperRightArmDeltaRot);
    m_shader->setUniform("upperRightArmMatrix", upperRightArmTransform->getMatrix(), false);
    m_shader->setUniform("objectType", 5 );
    glBindVertexArray(vaoIDupperRightArm);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

    //under right arm
    Transform* underRightArmTransform = new Transform();
    glm::quat underRightArmDeltaRot = glm::angleAxis(glm::radians(positiveAngle*3), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::vec3 underRightArmPivot = glm::vec3(3.5f, 0.15f, 0.0f);
    underRightArmPivot = upperRightArmTransform->getMatrix() * glm::vec4(underRightArmPivot, 1.0f);
    underRightArmTransform->rotateAroundPoint(underRightArmPivot, underRightArmDeltaRot);

    m_shader->setUniform("underRightArmMatrix", underRightArmTransform->getMatrix(), false);
    m_shader->setUniform("objectType", 7 );
    glBindVertexArray(vaoIDunderRightArm);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

    glBindVertexArray(0); // unbind VAO

    time+=dt;
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

    glDeleteVertexArrays(1, &vaoIDHead);
    glDeleteBuffers(1, &vboIDHead);

    glDeleteVertexArrays(1, &vaoIDupperLeftArm);
    glDeleteBuffers(1, &vboIDupperLeftArm);

    glDeleteVertexArrays(1, &vaoIDunderLeftArm);
    glDeleteBuffers(1, &vboIDunderLeftArm);

    glDeleteVertexArrays(1, &vaoIDupperRightArm);
    glDeleteBuffers(1, &vboIDupperRightArm);

    glDeleteVertexArrays(1, &vaoIDunderRightArm);
    glDeleteBuffers(1, &vboIDunderRightArm);

    glDeleteVertexArrays(1, &vaoIDleftLeg);
    glDeleteBuffers(1, &vboIDleftLeg);

    glDeleteVertexArrays(1, &vaoIDrightLeg);
    glDeleteBuffers(1, &vboIDrightLeg);

}


