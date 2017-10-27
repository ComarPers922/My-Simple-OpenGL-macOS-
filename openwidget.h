#ifndef OPENWIDGET_H
#define OPENWIDGET_H

#include<QGLWidget>
#include<QObject>
#include<QWidget>

class openWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit openWidget(QWidget *parent = 0): QGLWidget(parent) {}

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void Rotate();
    void Translate(bool left);
private:
    GLfloat ang = 0.0f;
    GLfloat pos = 0.0f;
};

#endif // OPENWIDGET_H
