//lab 14 - Write a program to draw a polygon.
// This Program doesnt run. Copy output from file

#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    glBegin(GL_POLYGON);
    glVertex3f(-0.5f, 1.0f, 0.0f); // Top Left
    glVertex3f(-1.0f, 0.0f, 0.0f); // Left
    glVertex3f(-0.5f, -1.0f, 0.0f); // Bottom Left
    glVertex3f(0.5f, -1.0f, 0.0f); // Bottom Right
    glVertex3f(1.0f, 0.0f, 0.0f); // Right
    glVertex3f(0.5f, 1.0f, 0.0f); // Top Right
    glEnd();

    glFlush(); // Render now
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
    glutInitWindowSize(320, 320); // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}

