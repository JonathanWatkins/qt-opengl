#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QtOpenGL>

class GLWidget : public QGLWidget
{
public:
    GLWidget(QWidget *parent);
    ~GLWidget();
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void timerEvent(QTimerEvent *) { update(); }

    void keyPressEvent(QKeyEvent * e);

    void drawSquare();

private:
    GLfloat number;

};


#endif // GLWIDGET_H
