#ifndef GLWINDOW_H
#define GLWINDOW_H

// Just to avoid warnings from glm
//#define GLM_FORCE_RADIANS

#include <QGLWidget>
#include <QGLFunctions>
#include <QGLShader>
#include <glm/glm.hpp>
#include <QOpenGLShaderProgram>



class GLWindow : public QGLWidget, protected QGLFunctions
{
    Q_OBJECT


public:
    GLWindow( QWidget * parent = 0);
    ~GLWindow();
    bool eventFilter(QObject *obj, QEvent *event);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
private:    
    int SIZE_OF_INDICES = 0;
    unsigned int * indices;

    QPoint _lastPoint;
    float _rotation =0;
    glm::vec3 _eye;
    glm::mat4 _modelMatrix;

    GLuint _shaderProgram;
    GLuint _vao;
    GLuint _vBuffer[2];
    int _numberOfPoints;
    QOpenGLShaderProgram _shaderManager;

    enum class ModeType{
        CIEXYZ, CIEXYZ2RGB
    };

    ModeType _modeType;

    void drawDefaultAxis();
    void drawNewBase();
    void drawScene(glm::mat4 modelViewMatrix, glm::mat4 projectionMatrix);
    void generateGamutData();
    void drawCieRGB2CieXYZAxis(glm::mat4 modelViewMatrix, glm::mat4 projection);
    void drawSecondaryAxis();

};

#endif // GLWINDOW_H
