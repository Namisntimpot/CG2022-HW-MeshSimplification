

#include <UGL/UGL>
#include <UGM/UGM>
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION

#include "../tool/Camera.h"
#include "../tool/OGLResources.h"
#include "MeshSimplification.h"

#include <iostream>

using namespace Ubpa;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);

// 屏幕设置
unsigned int scr_width = 800;
unsigned int scr_height = 600;
bool have_shadow = false;

//  摄像机，详见Camera.cpp
Camera camera(pointf3(0.0f, 0.0f, 3.0f));
float lastX = scr_width / 2.0f;
float lastY = scr_height / 2.0f;
bool firstMouse = true;
float base_angle_y = 0.0f;
float angle_x = 0.0f;

//保存不同层次的模型
int current_index = 0;
std::vector<tool::OGLResources*> meshes(1);

//保存模型简化比例
const float simplification_ratio = 0.7f;  //每次简化到当时的70%

// 计时
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;


int main()
{
    // glfw初始化
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // 创建窗口
    // --------------------
    GLFWwindow* window = glfwCreateWindow(scr_width, scr_height, "HW3-MeshSimplification", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    //设定事件发生后的回调函数，类似Qt中的connect
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: 加载OpenGL函数指针
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // 配置Opengl全局状态，可详见UGL实现
    gl::Enable(gl::Capability::DepthTest);

    // 加载顶点着色器
    // ------------------------------------
    gl::Shader vs(gl::ShaderType::VertexShader, "../data/shaders/p3n3.vert");
    // 加载片元着色器
    gl::Shader fs(gl::ShaderType::FragmentShader, "../data/shaders/light.frag");

    gl::Program program(&vs, &fs);



    rgbf ambient{ 0.2f,0.2f,0.2f };
    vecf3 point_light_pos{ 0,5,0 }, point_light_radiance{ 255,255,255 };
    program.SetVecf3("point_light_pos", { 0,10,0 });
    program.SetVecf3("point_light_radiance", point_light_radiance);
    program.SetVecf3("local_color", { 1.0f, 1.0f,1.0f });
    program.SetVecf3("ambient_irradiance", ambient);
    program.SetFloat("roughness", 0.6f);
    program.SetFloat("metalness", 0.1f);

    // 加载模型
    // ------------------------------------------------------------------

    meshes[0] = tool::OGLResources::LoadObj("../data/models/squirrel.obj");
    //meshes[0] = tool::OGLResources::LoadObj("../data/models/spot_triangulated_good.obj");


    //  渲染循环
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // 为每帧计算时间
        // --------------------
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // 输入
        // -----
        processInput(window);

        //  从这里开始是绘制部分
        // ------
        gl::ClearColor({ ambient, 1.0f });
        gl::Clear(gl::BufferSelectBit::ColorBufferBit | gl::BufferSelectBit::DepthBufferBit);

        program.SetVecf3("camera_pos", camera.Position);
        transformf projection = transformf::perspective(to_radian(camera.Zoom), (float)scr_width / (float)scr_height, 0.1f, 100.f);
        program.SetMatf4("projection", projection);
        program.SetMatf4("view", camera.GetViewMatrix());


        // 渲染模型
        pointf3 object_pos{ 0.0f,0.0f,0.0f };
        float angle = base_angle_y/* + 10.f * (float)glfwGetTime()*/;
        quatf rotation = quatf{ vecf3(-1.0f, 0.0f, 0.0f), to_radian(angle_x) } * quatf{ vecf3(0.0, 1.0f, 0.0), to_radian(angle) } ;
        transformf model(object_pos, rotation);
        program.SetMatf4("model", model);
        meshes[current_index]->va->Draw(&program);

        // 在buffer中绘制的内容会在这里展示到屏幕上
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // 如果有自定义的未释放资源的数据可以在这里调用释放
    // ------------------------------------------------------------------------
    for (auto ptr : meshes)
    {
        if (ptr != nullptr)
        {
            delete ptr;
        }
    }

    // 结束程序，释放所有GLFW资源
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// 调用GLFW API，移动视角位置，空格控制阴影显示
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(Camera::Movement::FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(Camera::Movement::BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(Camera::Movement::LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(Camera::Movement::RIGHT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        camera.ProcessKeyboard(Camera::Movement::UP, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        camera.ProcessKeyboard(Camera::Movement::DOWN, deltaTime);

    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        if (current_index > 0)
            current_index -= 1;
        _sleep(100);             //必须要延迟一小会，不然按一下会出现被识别出很多次按键操作！
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        //std::cout << "current_index = " << current_index << "\n";
        //std::cout << "meshes.size() = " << meshes.size() << "\n";
        if (current_index < meshes.size() - 1)
            current_index += 1;
        else
        {
            //std::cout << "here to simplify mesh!" << "\n";
            auto pair = meshSimplification::simplifyMesh(meshes[current_index]->positions, meshes[current_index]->indices, simplification_ratio);
            meshes.push_back(tool::OGLResources::fromMesh(std::move(pair.first), std::move(pair.second)));
            current_index += 1;
        }
        _sleep(100);
    }
}

// glfw: 屏幕大小被改变时调用
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    gl::Viewport({ 0, 0 }, width, height);
    scr_width = width;
    scr_height = height;
}


// glfw: 鼠标移动时调用
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = static_cast<float>(xpos);
        lastY = static_cast<float>(ypos);
        firstMouse = false;
    }

    float xoffset = static_cast<float>(xpos) - lastX;
    float yoffset = lastY - static_cast<float>(ypos); // reversed since y-coordinates go from bottom to top

    lastX = static_cast<float>(xpos);
    lastY = static_cast<float>(ypos);

    base_angle_y += static_cast<float>(xoffset);
    angle_x += static_cast<float>(yoffset);
}

// glfw: 鼠标滚轮移动时调用
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}

