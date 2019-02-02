#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

QT_BEGIN_NAMESPACE
 class QLabel;
 class QPainter;
QT_END_NAMESPACE

class MainWindow :public QMainWindow
{
	Q_OBJECT
	 public:
      MainWindow();
      int bitsToDec();
     protected:
      void paintEvent (QPaintEvent *event);
      void mousePressEvent(QMouseEvent *event);
     private:
      QLabel *bitLabel[8];
      QLabel *binLabel, *hexLabel, *decLabel;
      QPainter *p;
      int bit[8];
      int rectW, rectH, rectStartW, rectStartH;  
};
#endif