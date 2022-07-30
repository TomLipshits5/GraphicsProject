#pragma once
#include "igl/opengl/glfw/Display.h"
#include "igl/opengl/glfw/renderer.h"
#include "Project.h"
#include "imgui/imgui.h"
#include "ShapeWrapper.h"
#include <math.h>

bool holdsLeft;
double xStart, yStart;
int ChosenScreen = 0;


Eigen::Vector3f centerOnObjects(Project *scn)
{

    if (scn->pShapes.size() > 0)
    {

        Eigen::Vector3f avgPos = Eigen::Vector3f(0, 0, 0);

        for (int i : scn->pShapes)
        { // chaneg to picked shapes
            avgPos += scn->shapeWrappers[i].getCurrentPosition();
        }
        avgPos /= scn->pShapes.size();
        avgPos -= Eigen::Vector3f(0, 0, 4);

        return avgPos;
    }
    return Eigen::Vector3f(0, 0, 0);
}

void rescaleObjects(double shiftSize, directions d, Project *scn)
{
    for (int i : scn->pShapes)
    {
        scn->shapeWrappers[i].reScaleShape(shiftSize, d);
    }
}



void moveObjects(double amt, directions d, Project *scn)
{
    for (int i : scn->pShapes)
    {
        scn->shapeWrappers[i].move(amt, d);
    }
}

void glfw_mouse_callback(GLFWwindow *window, int button, int action, int mods)
{
    if (action == GLFW_PRESS)
    {

        Renderer *rndr = (Renderer *)glfwGetWindowUserPointer(window);
        Project *scn = (Project *)rndr->GetScene();
        if (button == GLFW_MOUSE_BUTTON_RIGHT)
        {
            rndr->UnPick(3);
            rndr->Pressed();
            glfwGetCursorPos(window, &xStart, &yStart);
            rndr->UnPick(3);
        }
        rndr->UpdatePress(xStart, yStart);
    }
    else
    {
        Renderer *rndr = (Renderer *)glfwGetWindowUserPointer(window);
        Project *scn = (Project *)rndr->GetScene();

        if (button == GLFW_MOUSE_BUTTON_RIGHT)
        {
            
            double xEnd, yEnd;
            glfwGetCursorPos(window, &xEnd, &yEnd);
            rndr->PickMany(3);
            rndr->Pressed();
        }
    }
}

void glfw_scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
    Renderer *rndr = (Renderer *)glfwGetWindowUserPointer(window);
    Project *scn = (Project *)rndr->GetScene();

    int ChosenCamera = scn->GetRenderer()->GetCameraD(ChosenScreen + 1);

    if (rndr->IsPicked())
    {
        rndr->UpdateZpos((int)yoffset);
        rndr->MouseProccessing(GLFW_MOUSE_BUTTON_MIDDLE);
    }
    else
    {
        rndr->MoveCamera(ChosenCamera, rndr->zTranslate, (float)yoffset);
    }
}

void glfw_cursor_position_callback(GLFWwindow *window, double xpos, double ypos)
{
    Renderer *rndr = (Renderer *)glfwGetWindowUserPointer(window);
    Project *scn = (Project *)rndr->GetScene();
    double xStart, yStart;
    glfwGetCursorPos(window, &xStart, &yStart);

    rndr->UpdatePosition((float)xpos, (float)ypos);

    if (rndr->CheckViewport(xpos, ypos, 0))
    {
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
        {
            rndr->UnPick(2);
            glfwGetCursorPos(window, &xStart, &yStart);
            if (!rndr->IsPressed())
            {
                rndr->Pressed();
            }
        }
        else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
        {
            rndr->MouseProccessing(GLFW_MOUSE_BUTTON_LEFT);
        }
        else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE && rndr->IsPressed())
        {
            rndr->PickMany(2);
            rndr->Pressed();
        }
    }
}

void glfw_window_size_callback(GLFWwindow *window, int width, int height)
{
    Renderer *rndr = (Renderer *)glfwGetWindowUserPointer(window);

    rndr->resize(window, width, height);
}

void glfw_key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    Renderer *rndr = (Renderer *)glfwGetWindowUserPointer(window);
    Project *scn = (Project *)rndr->GetScene();


    int ChosenCamera = scn->GetRenderer()->GetCameraD(ChosenScreen + 1);


    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {
        switch (key)
        {
        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(window, GLFW_TRUE);
            break;

        case GLFW_KEY_SPACE:
            if (scn->IsActive())
                scn->Deactivate();
            else
                scn->Activate();
            break;

        case GLFW_KEY_UP:
            rndr->MoveCamera(ChosenCamera, scn->xRotate, 0.05f);

            break;
        case GLFW_KEY_DOWN:
            rndr->MoveCamera(ChosenCamera, scn->xRotate, -0.05f);
            break;
        case GLFW_KEY_LEFT:
            rndr->MoveCamera(ChosenCamera, scn->yRotate, 0.05f);
            break;
        case GLFW_KEY_RIGHT:
            rndr->MoveCamera(ChosenCamera, scn->yRotate, -0.05f);
            break;
        case GLFW_KEY_D:
            if (rndr->IsPicked())
                moveObjects(0.05, x, scn);
            else
                rndr->MoveCamera(ChosenCamera, scn->xTranslate, 0.25f);
            break;
        case GLFW_KEY_A:
            if (rndr->IsPicked())
                moveObjects(-0.05, x, scn);
            else
                rndr->MoveCamera(ChosenCamera, scn->xTranslate, -0.25f);
            break;
        case GLFW_KEY_W:
            if (rndr->IsPicked())
                moveObjects(0.05, y, scn);
            else
                rndr->MoveCamera(ChosenCamera, scn->yTranslate, 0.25f);
            break;
        case GLFW_KEY_S:
            if (rndr->IsPicked())
                moveObjects(-0.05, y, scn);
            else
                rndr->MoveCamera(ChosenCamera, scn->yTranslate, -0.25f);
            break;
        case GLFW_KEY_M:
            scn->rotateCubeMap();
            break;
        case GLFW_KEY_R:
        {
            rndr->MoveCamera(ChosenCamera, rndr->resetCamera, 0);
            break;
        }
        case GLFW_KEY_C:
        {
            Eigen::Vector3f center = centerOnObjects(scn);
            rndr->MoveCamera(ChosenCamera, rndr->resetCamera, 0);
            rndr->MoveCamera(ChosenCamera, scn->xTranslate, center.x());
            rndr->MoveCamera(ChosenCamera, scn->yTranslate, center.y());
            rndr->MoveCamera(ChosenCamera, scn->zTranslate, center.z());
            break;
        }
        case GLFW_KEY_0:
            moveObjects(+0.05, z, scn);
            break;
        case GLFW_KEY_9:
            moveObjects(-0.05, z, scn);
            break;
        case GLFW_KEY_X:
            rescaleObjects(1.5, x, scn);
            break;
        case GLFW_KEY_Z:
            rescaleObjects(0.7, x, scn);
            break;
        case GLFW_KEY_Y:
            rescaleObjects(1.5, y, scn);
            break;
        case GLFW_KEY_U:
            rescaleObjects(0.7, y, scn);
            break;
        case GLFW_KEY_I:
            rescaleObjects(1.5, z, scn);
            break;
        case GLFW_KEY_O:
            rescaleObjects(0.7, z, scn);
            break;
        case GLFW_KEY_F:
            rescaleObjects(1.5, w, scn);
            break;
        case GLFW_KEY_G:
            rescaleObjects(0.7, w, scn);
            break;
        case GLFW_KEY_LEFT_SHIFT:
            ChosenScreen = 0;
            break;
        case GLFW_KEY_RIGHT_SHIFT:
            ChosenScreen = 1;
            break;
        default:
            break;
        }
    }
}

void Init(Display &display, igl::opengl::glfw::imgui::ImGuiMenu *menu)
{
    display.AddKeyCallBack(glfw_key_callback);
    display.AddMouseCallBacks(glfw_mouse_callback, glfw_scroll_callback, glfw_cursor_position_callback);
    display.AddResizeCallBack(glfw_window_size_callback);
    menu->init(&display);
}
