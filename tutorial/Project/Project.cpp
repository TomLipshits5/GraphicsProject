#include "Project.h"
#include <iostream>
#include <chrono>
#include "./igl/file_dialog_open.h"

Layer *layer_1 = new Layer(true, "Layer_1", std::vector<int>());


IGL_INLINE void Project::openDialogLoadMesh()
{
    std::string fname = igl::file_dialog_open();

    if (fname.length() == 0)
        return;

    loadShapeFromFile(fname.c_str());
}

int indxFile = 0;

bool Project::loadShapeFromFile(
    const std::string &meshFile)
{
    std::vector<Eigen::Vector3f> points = {Eigen::Vector3f(4, 4, 0),
                                           Eigen::Vector3f(0, 20, 0),
                                           Eigen::Vector3f(-10, -10, -100),
                                           Eigen::Vector3f(4, 4, 0)};

    int index = loadShapeWrapperFromFile(meshFile, -1, this, 0);
    SetShapeShader(index, 2);
    SetShapeMaterial(index, 2);
    return true;
}

long getCurrentUnixTime()
{
    const auto p1 = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(p1.time_since_epoch()).count();
}

Project::Project() {}

void Project::SetMenu(igl::opengl::glfw::imgui::ImGuiMenu *menu)
{
    this->menu = menu;
}


int Project::loadShapeWrapperFromFile(std::string name, int parent, Viewer *viewer, int viewPort = 0)
{
    int index = AddShapeFromFile(name, parent, TRIANGLES, viewPort);
    if (viewPort == 0)
    {
        SetShapeViewport(index, 1);
    }
    ShapeWrapper shp(MeshCopy, layer_1, index, viewer);
    shp.setlastPosition(Eigen::Vector3f(0, 0, 0));
    shapeWrappers.push_back(shp);
    return index;
}

int Project::addShapeWrapper(igl::opengl::glfw::Viewer::shapes type,
                             Viewer *viewer, int parent, int viewPort = 0)
{
    int index = AddShape(type, parent, TRIANGLES, viewPort);
    if (viewPort == 0)
    {
        SetShapeViewport(index, 1);
    }
    ShapeWrapper shapeWrapper(type, layer_1, index, viewer);
    shapeWrapper.setlastPosition(Eigen::Vector3f(0, 0, 0));
    shapeWrappers.push_back(shapeWrapper);
    return index;
}

void Project::Init(int DISPLAY_WIDTH, int DISPLAY_HEIGHT)
{
    farShapes = std::vector<int>();
    this->DISPLAY_WIDTH = DISPLAY_WIDTH;
    this->DISPLAY_HEIGHT = DISPLAY_HEIGHT;
    layers.push_back(layer_1);
    // Maybe needs -1
    globalTime = 0;
    unsigned int slots[4] = {0, 1, 2, 3};
    int pickingShaderIndx = AddShader("shaders/pickingShader");
    int cubemapShaderIndx = AddShader("shaders/cubemapShader");
    basicShader = AddShader("shaders/basicShader");
    blurShader = AddShader("shaders/blurShader");

    unsigned int grassTexIndx = AddTexture("textures/grass.bmp", 2);
    unsigned int dayLightBoxTexIndx = AddTexture("textures/cubemaps/Daylight Box_", 3);
    unsigned int boxTexIndx = AddTexture("textures/box0.bmp", 2);
    unsigned int planeTexIndx = AddTexture("textures/plane.png", 2);

    int dayLight3DMatIndx = AddMaterial(&dayLightBoxTexIndx, slots + 1, 1);
    int box2DMatIndx = AddMaterial(&boxTexIndx, slots + 2, 1);
    int plane2DMatIndx = AddMaterial(&planeTexIndx, slots + 3, 1);
    

    std::vector<Eigen::Vector3f> points = { Eigen::Vector3f(0, 0, 0),
                                           Eigen::Vector3f(0, 10, 0) };
    std::vector<Eigen::Vector3f> jumpUp = {Eigen::Vector3f(0, 0, 0),
                                           Eigen::Vector3f(0, 10, 0) };
    std::vector<Eigen::Vector3f> jumpDown = {Eigen::Vector3f(0, 0, 0),
                                             Eigen::Vector3f(0, -10, 0) };
    std::vector<Eigen::Vector3f> jumpRight = {Eigen::Vector3f(0, 0, 0),
                                              Eigen::Vector3f(10, 0, 0) };
    std::vector<Eigen::Vector3f> jumpLeft = {Eigen::Vector3f(0, 0, 0),
                                             Eigen::Vector3f(-10, 0, 0) };


    map = addShapeWrapper(Cube, this, -2);
    SetShapeShader(map, cubemapShaderIndx);
    SetShapeMaterial(map, dayLight3DMatIndx);
    selected_data_index = map;
    ShapeTransformation(scaleAll, 150, 0);
    SetShapeStatic(map);

    pickingPlane = addShapeWrapper(Plane, this, -2, 2);
    SetShapeShader(pickingPlane, pickingShaderIndx);
    SetShapeMaterial(pickingPlane, plane2DMatIndx);
    selected_data_index = pickingPlane;
    ShapeTransformation(zTranslate, -1.1, 1);
    SetShapeStatic(pickingPlane);


    int shpIndx;
    shpIndx = addShapeWrapper(Cube, this, -1);
    SetShapeShader(shpIndx, basicShader);
    SetShapeMaterial(shpIndx, box2DMatIndx);
    shapeWrappers[shpIndx].move(2, x);

    shpIndx = addShapeWrapper(Axis, this, -4);
    SetShapeShader(shpIndx, basicShader);
    SetShapeMaterial(shpIndx, plane2DMatIndx);

    shpIndx = addShapeWrapper(zCylinder, this, -3);
    SetShapeShader(shpIndx, basicShader);
    SetShapeMaterial(shpIndx, box2DMatIndx);
    shapeWrappers[selected_data_index].move(-2, x);
}

float Project::calculateCameraDistance(ShapeWrapper shp)
{
    Eigen::Vector3f cameraPos = renderer->cameraPosition;
    Eigen::Vector3f shapePos = shp.getCurrentPosition();
    return (shapePos - cameraPos).norm();
}

void Project::calculateFarShapes()
{
    for (int indx : farShapes)
    {
        SetShapeShader(indx, basicShader);
    }
    farShapes.clear();
    for (ShapeWrapper shp : shapeWrappers)
    {
        if (shp.getIndex() == map || shp.getIndex() == pickingPlane)
        {
            continue;
        }
        float dist = calculateCameraDistance(shp);
        if (dist > blurDist)
        {
            SetShapeShader(shp.getIndex(), blurShader);
            farShapes.push_back(shp.getIndex());
        }
    }
}

void Project::Update(const Eigen::Matrix4f &Proj, const Eigen::Matrix4f &View, const Eigen::Matrix4f &Model, unsigned int shaderIndx, unsigned int shapeIndx)
{
    calculateFarShapes();
    Shader *s = shaders[shaderIndx];
    long ctime;
    if (isActive)
    {
        ++globalTime;
        if (globalTime >= mTime) {
            globalTime = mTime;
            Deactivate();
        }
        ctime = globalTime;
    }
    else
        ctime = time;

    if (shapeIndx != map && shapeIndx != pickingPlane)
    {
        ShapeWrapper scnShape = shapeWrappers[shapeIndx];
        Eigen::Vector3f pos = scnShape.getlastPosition();
        Eigen::Vector3f newPos = scnShape.getPositionAtTime((float) ctime);
        if (newPos != pos)
        {
            Eigen::Vector3f delta = newPos - pos;
            selected_data_index = shapeIndx;
            ShapeTransformation(xTranslate, delta(x), 0);
            ShapeTransformation(yTranslate, delta(y), 0);
            ShapeTransformation(zTranslate, delta(z), 0);
            shapeWrappers[shapeIndx].setlastPosition(newPos);
        }
    }

    s->Bind();
    s->SetUniformMat4f("Proj", Proj);
    s->SetUniformMat4f("View", View);
    s->SetUniformMat4f("Model", Model);
    if (!shapeWrappers[shapeIndx].getShapeLayer()->isLayerVisible())
    {
        s->SetUniform2f("transparency", 0, 0);
    }
    else if (shapeWrappers[shapeIndx].isTransparent)
    {
        s->SetUniform2f("transparency", 0.4, 0);
    }
    else
    {
        s->SetUniform2f("transparency", 1, 0);
    }
    if (data_list[shapeIndx]->GetMaterial() >= 0 && !materials.empty())
    {
        BindMaterial(s, data_list[shapeIndx]->GetMaterial());
    }
    s->Unbind();
}

void Project::WhenRotate()
{
}

void Project::WhenTranslate()
{
}

const int numOfCubeMaps = 3;

std::string cubeMaps[numOfCubeMaps] = {"Daylight Box_", "drak_nature_cubemap_",
                                       "foggy_cubemap_"};

int cubeMapCurrTextIndx = 0;

void Project::rotateCubeMap()
{
    cubeMapCurrTextIndx = (cubeMapCurrTextIndx + 1) % numOfCubeMaps;
    changeCubeMap(cubeMaps[cubeMapCurrTextIndx]);
}

void Project::changeCubeMap(std::string file_name)
{
    unsigned int tex = AddTexture("textures/cubemaps/" + file_name, 3);
    unsigned int numOfMats = materials.size();
    int cubeMat = AddMaterial(&tex, &numOfMats, 1);
    SetShapeMaterial(map, cubeMat);
}

void Project::Animate()
{
    animating = !animating;
}


Project::~Project(void)
{
}

void Project::UpdateRenderer(Renderer *renderer)
{
    if (this->renderer != nullptr)
        throw std::invalid_argument("renderer cannot be set twice");
    this->renderer = renderer;
}



void Project::playAnimation()
{
    animating = !animating;
    globalTime = -1;
}
