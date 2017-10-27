#include "openwidget.h"
#include <QOpenGLWidget>
#include <QtOpenGL>
#include <QFile>
#include <QByteArray>
#include <QDebug>
#include "utils.h"

#ifdef Q_OS_MACOS
#include <OpenGL/glu.h>
#endif

#ifdef Q_OS_WIN
#include<GL/glu>
#endif
GLuint myPicID = 0;
void openWidget::initializeGL()
{
    glMatrixMode(GL_PROJECTION);
    gluPerspective(50, this->width() / this->height(), 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(.7f,.8f,.7f,1.0f);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    float white[] = {1.0f, 1.0f, 1.0f, 1.0f};
    float lightPos[]= {0.0f, 1.0f, 2.0f, 0.0f};
    glLightfv(GL_LIGHT0, GL_AMBIENT, white);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    float ambient[] = {0.1f, 0.1f, 0.1f, 1.0f};
    float diffuse[] = {0.4f, 0.4f, 0.4f, 1.0f};
    float specular[] = {0.9f, 0.9f, 0.9f, 1.0f};
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

    QFile imgFile(":/pic/test.bmp");
    if(imgFile.open(QIODevice::ReadOnly))
    {
         QByteArray bytes = imgFile.readAll();
         int width = 0;
         int height = 0;
         unsigned char* colorContent = utils::imgData(bytes.data(),width,height);

         glGenTextures(1,&myPicID);
         glBindTexture(GL_TEXTURE_2D, myPicID);
         glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
         glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
         glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_CLAMP);
         glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_CLAMP);
         glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,colorContent);
         glBindTexture(GL_TEXTURE_2D, 0);
    }
}

void openWidget::paintGL()
{
    const float myZ = -15.0f;
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myPicID);
    glPushMatrix();
    glRotatef(ang, 0.0f, 0.0f, 1.0f);

    glBegin(GL_TRIANGLES);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, myZ);

        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-4.0f, 0.0f, myZ);

        glTexCoord2f(0.5f, 1.0f);
        glVertex3f(-4.0f, -2.0f, myZ);
    glEnd();

    glRotatef(90,0.0f,0.0f,1.0f);
    glBegin(GL_TRIANGLES);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, myZ);

        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-4.0f, 0.0f, myZ);

        glTexCoord2f(0.5f, 1.0f);
        glVertex3f(-4.0f, -2.0f, myZ);
    glEnd();

    glRotatef(180, 0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, myZ);

        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-4.0f, 0.0f, myZ);

        glTexCoord2f(0.5f, 1.0f);
        glVertex3f(-4.0f, -2.0f, myZ);
    glEnd();

    glRotatef(270, 0.0f, 0.0f, 1.0f);
        glBegin(GL_TRIANGLES);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, myZ);

        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-4.0f, 0.0f, myZ);

        glTexCoord2f(0.5f, 1.0f);
        glVertex3f(-4.0f, -2.0f, myZ);
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(pos,0,0);
        glBegin(GL_TRIANGLES);
        glColor4ub(200, 200, 255, 255);

        glTexCoord2f(0.5f, 0.0f);
        glVertex3f(0.0f,1.0f,myZ);

        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-2.0f,-3.0f,myZ);

        glTexCoord2f(0.0f, 0.5f);
        glVertex3f(2.0f,-3.0f,myZ);

    glEnd();

    glPopMatrix();
    glBindTexture(GL_TEXTURE_2D, 0);
}
void openWidget::resizeGL(int w, int h)
{
}
void openWidget::Rotate()
{
    this->ang += 45;
    this->updateGL();
}
void openWidget::Translate(bool left)
{
    this->pos += left? -1 : 1;
    this->updateGL();
}
