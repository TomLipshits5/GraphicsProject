
#include "ShapeWrapper.h"


Layer::Layer(bool isVisible, std::string layerName, std::vector<int> layerShapes) : isVisible(isVisible), layerName(layerName), layerShapes(layerShapes) {}

std::string Layer::getLayerName()
{
    return this->layerName;
}


bool Layer::isLayerVisible()
{
    return this->isVisible;
}

void Layer::setVisible(bool toSet)
{
    this->isVisible = toSet;
}

void Layer::addShape(int shapeIndex) {
    this->layerShapes.push_back(shapeIndex);
}

void Layer::removeShape(int shapeIndex) {
    std::vector<int> layerShapes;
    for (int num : this->layerShapes) {
        if (num != shapeIndex)
            layerShapes.push_back(num);
    }
    this->layerShapes = layerShapes;

}
//END LayerClass ------->

ShapeWrapper::ShapeWrapper( igl::opengl::glfw::Viewer::shapes type,
                           Layer* layer, int index, igl::opengl::glfw::Viewer* viewer) :layer(layer),  index(index), currentPosition(Eigen::Vector3f(0, 0, 0)), viewer(viewer)
{
    movement = std::vector<BizieeMovment>();
}

Layer* ShapeWrapper::getShapeLayer()
{
    return layer;
}
void ShapeWrapper::changeShapeLayer(Layer* layer)
{
    this->layer = layer;
}
int ShapeWrapper::getIndex() {
    return index;
}


void ShapeWrapper::addBiz(BizieeMovment biz, float *max_time) {
    this->movement.push_back(biz);
    if (biz.endTime > *max_time)
        *max_time = biz.endTime;
}

void ShapeWrapper::clearBiz() {
    this->movement.clear();
}


Eigen::Vector3f ShapeWrapper::getlastPosition() {
    return lastPosition;
}

void ShapeWrapper::setlastPosition(Eigen::Vector3f pos) {
    lastPosition = pos;
}



Eigen::Vector3f ShapeWrapper::getCurrentPositionAt(float time)
{
    return getPositionAtTime(time);
}

Eigen::Vector3f ShapeWrapper::getCurrentPosition() {
    return currentPosition;
}


Eigen::Vector3f ShapeWrapper::getPositionAtTime(float time) {
    for (std::size_t i = 0; i < this->movement.size(); i++) {
        if (movement[i].startTime <= time && movement[i].endTime >= time) {
            return movement[i].getPosition(time);
        }
    }
    return lastPosition;
}
void ShapeWrapper::reScaleShape(double shiftSize, directions d) {
    switch (d)
    {
    case x:
        viewer->data_list[getIndex()]->MyScale(Eigen::Vector3d(shiftSize, 1, 1));
        break;
    case y:
        viewer->data_list[getIndex()]->MyScale(Eigen::Vector3d(1, shiftSize, 1));
        break;

    case z:
        viewer->data_list[getIndex()]->MyScale(Eigen::Vector3d(1, 1, shiftSize));
        break;

    case w:
        viewer->data_list[getIndex()]->MyScale(Eigen::Vector3d(shiftSize, shiftSize, shiftSize));
        break;
    }
}

void ShapeWrapper::move(double amt, directions d) {
    switch (d) {
        case x:
            viewer->data_list[getIndex()]->MyTranslate(Eigen::Vector3d(amt, 0 , 0) , false);
            currentPosition += Eigen::Vector3f(amt, 0 , 0);
            break;

        case y:
            viewer->data_list[getIndex()]->MyTranslate(Eigen::Vector3d(0, amt, 0), false);
            currentPosition += Eigen::Vector3f(0, amt, 0);
            break;

        case z:
            viewer->data_list[getIndex()]->MyTranslate(Eigen::Vector3d(0 , 0 , amt) , false);
            currentPosition += Eigen::Vector3f(0 , 0 , amt);
            break;
    }
    
}
