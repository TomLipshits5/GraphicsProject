#pragma once
#include "igl/opengl/glfw/Viewer.h"
#include "ShapeWrapper.h"
#include "igl/opengl/glfw/renderer.h"

class Project : public igl::opengl::glfw::Viewer
{

public:
    Project();
    //	Project(float angle,float relationWH,float near, float far);
    void Init(int DISPLAY_WIDTH, int DISPLAY_HEIGHT);
    void Update(const Eigen::Matrix4f &Proj, const Eigen::Matrix4f &View, const Eigen::Matrix4f &Model, unsigned int shaderIndx, unsigned int shapeIndx);
    void WhenRotate();
    void WhenTranslate();
    void Animate() override;
    void UpdateRenderer(Renderer *renderer);
    void SetMenu(igl::opengl::glfw::imgui::ImGuiMenu *menu);
    igl::opengl::glfw::imgui::ImGuiMenu *menu;
    bool loadShapeFromFile(const std::string &meshFile);
    IGL_INLINE void openDialogLoadMesh();
    void playAnimation();
    float time = 0;
    std::vector<ShapeWrapper> shapeWrappers;
    int map = -1;
    int pickingPlane = -1;
    int blurShader = -1;
    int basicShader = -1;
    float mTime = 1;
    ~Project(void);
    void changeCubeMap(std::string file_name);
    void rotateCubeMap();
    long globalTime;
    std::vector<Layer *> layers;
    Renderer *GetRenderer() { return renderer; }
    int DISPLAY_WIDTH;
    int DISPLAY_HEIGHT;
    float bizieeP[3] = {0, 0, 0};
    std::vector<Eigen::Vector3f> bizPoints;
    float animationTimes[2] = {0, mTime };
    std::vector<int> farShapes;
    void calculateFarShapes();
    float calculateCameraDistance(ShapeWrapper shp);
    float blurDist = 20;


private:
    Renderer *renderer = nullptr;
    int loadShapeWrapperFromFile(std::string name, int parent, Viewer *viewer, int viewPort);
    int addShapeWrapper(igl::opengl::glfw::Viewer::shapes type, Viewer *viewer, int parent, int viewPort);

    bool animating;
};
