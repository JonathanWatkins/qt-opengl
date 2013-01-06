#include "glwidget.h"
#include <QtGui/QImage>

#include <math.h>

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    makeCurrent();
    setWindowTitle(tr("Client Window"));
    number = 1.f;
}

GLWidget::~GLWidget()
{
}

void GLWidget::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glShadeModel(GL_SMOOTH);
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspect = w/(float)(h ? h : 1);
    glFrustum(-aspect, aspect, -1, 1, 10, 100);
    glTranslatef(-0.5f, -0.5f, -0.5f);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawSquare();
}

void GLWidget::drawSquare()
{
    glLoadIdentity();

    glColor3f(number,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-0.5f, -0.5f, 0);
    glVertex3f(-0.5f, 0.5f, 0);
    glVertex3f(0.5f, 0.5f, 0);
    glVertex3f(0.5f, -0.5f, 0);
    glEnd();
}

void GLWidget::keyPressEvent(QKeyEvent *e)
{
    qDebug("Key: %d",  e->key());
    if (e->key() == 90) // Z
    {
        number += 0.1f;
    }
    if (e->key() == 88) // X
    {
        number -= 0.1f;
    }
    qDebug("Number: %f",number);
}
