#include "Project.h"

class MenueWrapper
{
public:
    enum CameraSplitMode
    {
        NORMAL,
        BY_X,
        BY_Y
    };

    static void changeSplit(int splitMode, Project *scn)
    {
        switch (splitMode)
        {
        case CameraSplitMode::NORMAL:
            // Set viewport 0 to all screen
            scn->GetRenderer()->SetViewport(0, 0, scn->DISPLAY_WIDTH, scn->DISPLAY_HEIGHT, 0);
            // Set viewport 1 to 0
            scn->GetRenderer()->SetViewport(0, 0, 0, 0, 1);
            // PICKING Viewports:
            // Set viewport 2 to all screen
            scn->GetRenderer()->SetViewport(0, 0, scn->DISPLAY_WIDTH, scn->DISPLAY_HEIGHT, 2);
            // Set viewport 3 to all screen
            scn->GetRenderer()->SetViewport(0, 0, scn->DISPLAY_WIDTH, scn->DISPLAY_HEIGHT, 3);
            // scn->GetRenderer()->SetViewport(0, 0, scn->DISPLAY_WIDTH, scn->DISPLAY_HEIGHT, 4);
            // Set camera relation
            for (size_t i = 0; i < scn->GetRenderer()->GetCameras().size(); i++)
            {
                scn->GetRenderer()->reformatCameras(i, (float) scn->DISPLAY_WIDTH / (float) scn->DISPLAY_HEIGHT);
            }
            break;
        case CameraSplitMode::BY_X:
            // Set viewport 0 to all screen
            scn->GetRenderer()->SetViewport(0, 0, scn->DISPLAY_WIDTH / 2, scn->DISPLAY_HEIGHT, 0);
            // Set viewport 1 to 0
            scn->GetRenderer()->SetViewport(scn->DISPLAY_WIDTH / 2, 0, scn->DISPLAY_WIDTH / 2, scn->DISPLAY_HEIGHT, 1);
            // PICKING Viewports:
            // Set viewport 2 to all screen
            scn->GetRenderer()->SetViewport(0, 0, scn->DISPLAY_WIDTH / 2, scn->DISPLAY_HEIGHT, 2);
            // Set viewport 3 to all screen
            scn->GetRenderer()->SetViewport(0, 0, scn->DISPLAY_WIDTH / 2, scn->DISPLAY_HEIGHT, 3);
            // scn->GetRenderer()->SetViewport(0, 0, scn->DISPLAY_WIDTH / 2, scn->DISPLAY_HEIGHT, 4);
            // Set camera relation
            for (size_t i = 0; i < scn->GetRenderer()->GetCameras().size(); i++)
            {
                scn->GetRenderer()->reformatCameras(i, (float) scn->DISPLAY_WIDTH / (float) scn->DISPLAY_HEIGHT / 2);
            }
            break;
        case CameraSplitMode::BY_Y:
            // Set viewport 1 to 0
            scn->GetRenderer()->SetViewport(0, scn->DISPLAY_HEIGHT / 2, scn->DISPLAY_WIDTH, scn->DISPLAY_HEIGHT / 2, 0);
            // Set viewport 0 to all screen
            scn->GetRenderer()->SetViewport(0, 0, scn->DISPLAY_WIDTH, scn->DISPLAY_HEIGHT / 2, 1);
            // PICKING Viewports:
            // Set viewport 2 to all screen
            scn->GetRenderer()->SetViewport(0, 0, scn->DISPLAY_WIDTH, scn->DISPLAY_HEIGHT, 2);
            // Set viewport 3 to all screen
            scn->GetRenderer()->SetViewport(0, scn->DISPLAY_HEIGHT/2, scn->DISPLAY_WIDTH, scn->DISPLAY_HEIGHT / 2, 3);
            // scn->GetRenderer()->SetViewport(0, scn->DISPLAY_HEIGHT / 2, scn->DISPLAY_WIDTH, scn->DISPLAY_HEIGHT / 2, 4);
            // Set camera relation
            for (size_t i = 0; i < scn->GetRenderer()->GetCameras().size(); i++)
            {
                scn->GetRenderer()->reformatCameras(i, (float) scn->DISPLAY_WIDTH / ((float) scn->DISPLAY_HEIGHT / 2));
            }
            break;
        default:
            // error
            break;
        }
    }

    static void changeObjectsTransperancy(bool isTransparent, Project *scn)
    {
        for (size_t i = 0; i < scn->pShapes.size(); i++)
        {
            int shapeIndx = scn->pShapes[i];
            scn->shapeWrappers[shapeIndx].isTransparent = isTransparent;
        }
    }


    static void addCamera(std::string camera_name, Project *scn)
    {
        const float CAMERA_ANGLE = 45.0f;
        const float NEAR = 1.0f;
        const float FAR = 120.0f;
        scn->GetRenderer()->AddCamera(Eigen::Vector3d(0, 0, -10), CAMERA_ANGLE, (float)scn->DISPLAY_WIDTH / (float)scn->DISPLAY_HEIGHT / 2, NEAR, FAR);
    }

    static void setCamera(int screenIndx, int cameraIndx, Project *scn)
    {
        if (screenIndx == 0)
        {
            scn->GetRenderer()->SetCameraD(0, cameraIndx);
            scn->GetRenderer()->SetCameraD(1, cameraIndx);
        }
        else if (screenIndx == 1)
        {
            scn->GetRenderer()->SetCameraD(2, cameraIndx);
        }
    }

    static void addLayer(std::string layer_name, bool is_shown, Project *scn)
    {
        std::vector<int> layerShapes;
        Layer *layer = new Layer(is_shown, layer_name, layerShapes);
        scn->layers.push_back(layer);
    }

    static void changeLayer(std::string layer_name, bool is_visible, Project *scn)
    {
        for (Layer *layer : scn->layers)
        {
            if (layer->getLayerName() == layer_name)
            {
                layer->setVisible(is_visible);
                break;
            }
        }
    }

    static void setLayer(std::string layer_name, Project *scn)
    {
        Layer *changedLayer;
        for (size_t i = 0; i < scn->layers.size(); i++)
        {
            if (scn->layers[i]->getLayerName() == layer_name)
            {
                changedLayer = scn->layers[i];
                break;
            }
        }
        for (int shapeIndex : scn->pShapes)
        {
            scn->shapeWrappers[shapeIndex].getShapeLayer()->removeShape(shapeIndex);
            scn->shapeWrappers[shapeIndex].changeShapeLayer(changedLayer);
            scn->shapeWrappers[shapeIndex].getShapeLayer()->addShape(shapeIndex);
        }
    }
    static void chooseMaterial(int material_inx, Project *scn)
    {
        for (size_t i = 0; i < scn->pShapes.size(); i++)
        {
            int shpIndex = scn->pShapes[i];
            scn->SetShapeMaterial(shpIndex, material_inx);
        }
    }

    static void resetTime(bool play, Project *scn)
    {
        scn->globalTime = 0;
    }
    static void addPoint(float point[3], Project* scn) {
        scn->bizPoints.push_back(Eigen::Vector3f(point[0], point[1], point[2]));
        scn->bizieeP[0] = 0;
        scn->bizieeP[1] = 0;
        scn->bizieeP[2] = 0;
    }
    static void addMovment(float times[2], Project* scn) {
        BizieeMovment movment = BizieeMovment(scn->bizPoints, times[0], times[1]);
        scn->bizPoints.clear();
        for (int i : scn->pShapes) {
            scn->shapeWrappers[i].addBiz(movment, &(scn->mTime));
        }
        scn->animationTimes[0] = 0;
        scn->animationTimes[1] = scn->mTime;
    }
    static void removeMovment(Project* scn) {
        for (int i : scn->pShapes) {
            scn->shapeWrappers[i].clearBiz();
        }
    }
    
};