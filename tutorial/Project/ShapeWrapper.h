
#ifndef ASSIGNMENT1_CPP_SHAPEWRAPPER_H
#define ASSIGNMENT1_CPP_SHAPEWRAPPER_H

#include <Eigen/Core>
#include "igl/opengl/glfw/Viewer.h"

enum directions{
    x,y,z,w
};

class Layer {
public:
    Layer(bool isVisible, std::string layerName, std::vector<int> layerShapes);
    std::string getLayerName();
    bool isLayerVisible();
    void setVisible(bool toSet);
    void addShape(int shapeIndex);
    void removeShape(int shapeIndex);
private:
    bool isVisible;
    std::string layerName;
    std::vector<int> layerShapes;

};

class BizieeMovment {
public:
    BizieeMovment(std::vector<Eigen::Vector3f> movement, float start_time, float end_time) :
            points(movement), startTime(start_time), endTime(end_time) {};
    std::vector<Eigen::Vector3f> points;
    float startTime;
    float endTime;
    Eigen::Vector3f getPosition(float time) {
        if (points.size() == 1)
            return points[0];
        float timeNormal = (time - startTime) / (endTime - startTime);
        Eigen::Vector3f position = Eigen::Vector3f(0, 0, 0);
        for (std::size_t i = 0; i < points.size(); i++) {
            position += BinomialCoefficient(points.size(), i) * pow((1 - timeNormal), points.size() - i) * pow(timeNormal, i) * points[i];
        }
        return position;
    };

private:
    int BinomialCoefficient(const int n, const int reps) {
        if (reps == 0)
            return 1;
        std::vector<int> aSolutions(reps);
        aSolutions[0] = n - reps + 1;

        for (int i = 1; i < reps; ++i) {
            aSolutions[i] = aSolutions[i - 1] * (n - reps + 1 + i) / (i + 1);
        }

        return aSolutions[reps - 1];
    }
};

class ShapeWrapper {
public:
    ShapeWrapper(igl::opengl::glfw::Viewer::shapes type,
                 Layer* layer, int index, igl::opengl::glfw::Viewer* viewer);
    Layer* getShapeLayer();
    void changeShapeLayer(Layer* layer);
    int getIndex();
    void addBiz(BizieeMovment biz, float *max_time);
    void clearBiz();
    Eigen::Vector3f getPositionAtTime(float time);
    Eigen::Vector3f getlastPosition();
    void setlastPosition(Eigen::Vector3f pos);
    void addChild(ShapeWrapper* child);
    Eigen::Vector3f getCurrentPositionAt(float time);
    Eigen::Vector3f getCurrentPosition();
    bool isTransparent = false;
    void reScaleShape(double shiftSize, directions d);
    void move(double amt, directions d);

private:
    igl::opengl::glfw::Viewer::shapes type;
    std::vector<BizieeMovment> movement;
    Eigen::Vector3f currentPosition;
    igl::opengl::glfw::Viewer* viewer;
    Layer* layer;
    int index;
    Eigen::Vector3f lastPosition;



};
#endif