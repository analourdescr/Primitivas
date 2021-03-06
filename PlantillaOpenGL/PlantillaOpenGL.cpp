// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

using namespace std;

void dibujar(){
	glBegin(GL_TRIANGLES);

	glColor3f(1, 0, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, 0);
	glVertex3f(1, -1, 0);

	glEnd();
}
void dibujarTriangulos() {
	glBegin(GL_TRIANGLES);
	glColor3f(1, .5, 0);

	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, 0);
	glVertex3f(1, -1, 0);

	glColor3f(138.0f / 255.0f, 43.0f / 255.0f, 226.0f / 255.0f);
	glVertex3f(-1, 1, 0);
	glColor3f(238.0f / 55.0f, 143.0f / 55.0f, 206.0f / 5.0f);
	glVertex3f(-1, 0, 0);
	glColor3f(8.0f / 155.0f, 3.0f / 100.0f, 2.0f / 25.0f);
	glVertex3f(0, 1, 0);

	glColor3f(1, 0, 1);
	glVertex3f(-1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, 0);

	glEnd();
}

void dibujarTrianguloContinuo() {
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1, 1, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(-0.2, -0.2, 0);
	glVertex3f(0.2, -0.2, 0);
	glColor3f(0, 0, 0);
	glVertex3f(0.2, -0.4, 0);
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(0.4, -0.4, 0);

	glEnd();
}

void dibujarPoligono() {
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex3f(-0.8, 0.7, 0);
	glColor3f(.6, 1, 0.2);
	glVertex3f(-0.5, 0.5, 0);
	glVertex3f(-0.5, 0, 0);
	glVertex3f(0.2, 0.8, 0);
	glColor3f(1, 0.9, 0.1);
	glVertex3f(0.5, 0.9, 0);

	glEnd();
}

void dibujarCirculo() {
	glBegin(GL_POLYGON);
	glColor3f(1, .8, 0);
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.2*cos((double)i*3.14159 / 180.0) - 0.7, 0.2* sin((double)i*3.14159 / 180.0) + 0.6, 0.4);
	}
	glEnd();
}

void actualizar() {

}

void dibujar() {
	/*dibujarTriangulos();
	dibujarPuntos();
	dibujarLineas();
	dibujarLineaContinua();*/
	dibujarTrianguloContinuo();
	dibujarPoligono();
	dibujarCirculo();
}


int main()
{
	//Creamos una ventana
	GLFWwindow *window;

	//Si no se puede inicializar glfw
	//Iniciamos ejecucion
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	//Si se pudo iniciar GLFW
	//entonces inicializamosla ventana
	window = glfwCreateWindow(1024, 768, "Ventana", NULL, NULL);
	//Si nopodemos iniciar la ventana
	//Entonces terminamos ejecucion
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//Establecemos el contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido el contexto activamos funciones modernas
	glewExperimental = true;
	GLenum errorGlew = glewInit();
	if (errorGlew != GLEW_OK) {
		cout << glewGetErrorString(errorGlew);
	}

	const GLubyte *versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;

	//ciclode dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Establecer region de dibujo
		glViewport(0, 0, 1024, 768);
		//Establece el color de borrado
		glClearColor(0.3, 1, 0.8, 1);
		//Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();
		dibujarTriangulos();
		actualizar();

		//Cambiar los buffers
		glfwSwapBuffers(window);
		//Reconocer si hay entradas
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
    return 0;
}