#include <cstdlib>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

GLuint createProgram(const char *vsrc, const char *fsrc)
{
  const GLuint program(glCreateProgram());

  if (vsrc != NULL)
  {
    const GLuint vobj(glCreateShader(GL_VERTEX_SHADER));
    glShaderSource(vobj, 1, &vsrc, NULL);
    glCompileShader(vobj);

    glAttachShader(program, vobj);
    glDeleteShader(vobj);
  }

  if (fsrc != NULL)
  {
    const GLuint fobj(glCreateShader(GL_FRAGMENT_SHADER));
    glShaderSource(fobj, 1, &fsrc, NULL);
    glCompileShader(fobj);

    glAttachShader(program, fobj);
    glDeleteShader(fobj);
  }

  // プログラムオブジェクトをリンクする
  glBindAttribLocation(program, 0, "position");
  glBindFragDataLocation(program, 0, "fragment");
  glLinkProgram(program);

  // 作成したプログラムオブジェクトを返す
  return program;
}

int main()
{
  // GLFW を初期化する
  if (glfwInit() == GL_FALSE)
  {
    // 初期化に失敗した
    std::cerr << "Can't initialize GLFW" << std::endl;
    return 1;
  }

  atexit(glfwTerminate);


  GLFWwindow *const window(glfwCreateWindow(640, 480, "Hello!", NULL, NULL));
  if (window == NULL)
  {
    std::cerr << "Can't create GLFW window." << std::endl;
    return 1;
  }

  glfwMakeContextCurrent(window);

  if (glewInit() != GLEW_OK)
  {
    std::cerr << "Can't initialize GLEW" << std::endl;
    return 1;
  }

  glfwSwapInterval(1);

  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

  static constexpr GLchar vsrc[] =
    "#version 150 core\n"
    "in vec4 position;\n"
    "void main(void)\n"
    "{\n"
    "  gl_Position = position;\n"
    "}\n";

  static constexpr GLchar fsrc[] =
    "#version 150 core\n"
    "out vec4 fragment;\n"
    "void main(void)\n"
    "{\n"
    "  fragment = vec4(1.0, 0.0, 0.0, 1.0);\n"
    "}\n";

  const GLuint program(createProgram(vsrc, fsrc));

  while (glfwWindowShouldClose(window) == GL_FALSE)
  {
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(program);

    glfwSwapBuffers(window);

    glfwWaitEvents();
  }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
}