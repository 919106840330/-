#ifndef LZQ_H
#define LZQ_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPushButton>
#include <QMouseEvent>
#include <QTimer>

class lzq : public QMainWindow
{
    Q_OBJECT
public:
    explicit lzq(QWidget *parent = nullptr);
    void myslot();
    void myslot2();
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);

signals:
private:
    int w;
    int h;
    int flag ;
    int sj=0;
    bool f1(int, int);
    bool f2(int, int);
    bool f3(int, int);
    bool f4(int, int);
    QPushButton button;
    QPushButton button2;
    int a[20][20];
    int b,c;
    int tem=0;
    QTimer *time;
    QTimer *t;

public slots:
    void handleTimeout();
};

#endif // LZQ_H
