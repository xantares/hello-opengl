#include <QGuiApplication>

#include <QSurfaceFormat>
#include <QOpenGLWindow>
#include <iostream>
#include <QOpenGLFunctions_3_2_Core>
#include <QOpenGLFunctions>

class Window:public QOpenGLWindow
{
public:

};

static bool HaveOpenGL32()
{


  QSurfaceFormat requestedFormat;
  
  requestedFormat.setRenderableType(QSurfaceFormat::OpenGL);
  requestedFormat.setProfile(QSurfaceFormat::CoreProfile);
 
  requestedFormat.setVersion(3, 2);
  QOpenGLContext context;
  context.setFormat(requestedFormat);
  if (!context.create())
  {
    std::cout << "no context"<<std::endl;
    return false;
  }
  std::cout << "valid="<<context.isValid()<<std::endl;
  std::cout << "version="<<context.format().majorVersion()<<"."<<context.format().minorVersion() <<std::endl;

  QOpenGLFunctions *functions = context.functions();
      std::cout << "functions="<<functions<<std::endl;

//   std::cout << functions->glGetError() <<std::endl;

  return context.versionFunctions<QOpenGLFunctions_3_2_Core>();
}

int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);


  std::cout << HaveOpenGL32()<<std::endl;
 
  // Set the window up
  Window window;
//   window.setFormat(format);
  window.resize(QSize(800, 600));
  window.show();

    return app.exec();
}


