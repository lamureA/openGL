#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glut.h>

void renderScene(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glVertex3f(-0.5,-0.5,0.0);
    glVertex3f(0.5,0.0,0.0);
    glVertex3f(0.0,0.5,0.0);
    glEnd();

    glutSwapBuffers();
}

void init_glut(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitContextVersion(3, 0);
    glutInitContextProfile(GLUT_CORE_PROFILE);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(400,400);
    glutCreateWindow("OpenGL - TP1");
    //glutFullScreen();
}

bool init_glew() {
    GLenum init = glewInit();
    if (init != GLEW_OK)
    {
        std::cerr << "GlewInit fails: " << glewGetErrorString(init) << std::endl;
        return false;
    }
    return true;
}

void init_gl() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glDepthRange(0.0, 1.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
    glClearColor(0, 0, 0, 0);
}


int main(int argc, char **argv) {
    init_glut(argc, argv);
    if (!init_glew())
        return 1;
    init_gl();

    // register callbacks
    glutDisplayFunc(renderScene);

    // enter GLUT event processing cycle
    glutMainLoop();

    return 0;



}

