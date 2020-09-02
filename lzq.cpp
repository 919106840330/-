#include "lzq.h"
#include<QPainter>
#include<QPen>
#include<QMouseEvent>
#include<QBrush>
#include<QMessageBox>
#include<QDebug>
#include<QPushButton>



lzq::lzq(QWidget *parent) : QMainWindow(parent)
{
     setMinimumSize(500,500);
     memset(a, 0, 20 * 20 * sizeof(int));
     flag=0;


}
void lzq::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);

    w=width()/22;
    h=height()/22;
    int i, j;
    p.drawPixmap(0,0,width(),height(),QPixmap("../a"));


    for (i = 0; i < 21; i++)
    {
        p.drawLine(w,h+i*h,w+20*w,h+i*h);
        p.drawLine(w+i*w,h,w+i*w,h+20*h);
    }

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            if (a[i][j] == 1)
            {
                brush.setColor(Qt::black);
                p.setBrush(brush);
                p.drawEllipse(QPoint((i + 1.5) * w, (j + 1.5) * h), w*0.5, h*0.5);
            }
            else if (a[i][j] == 2)
            {
                brush.setColor(Qt::white);
                p.setBrush(brush);
                p.drawEllipse(QPoint((i + 1.5) * w, (j + 1.5) * h), w*0.5, h*0.5);
            }
        }
    }
}

void lzq::mousePressEvent(QMouseEvent *e)
{
    int x, y;
    if(e->x() >= 0.9*w && e->x() < 22*w && e->y() >=h*0.9 && e->y() <22*h)
    {
        x = (e->x() - w) / w;
        y = (e->y() - h) / h;
        if (!a[x][y])
        {


            a[x][y] = flag++ % 2 + 1;}

        if(f1(x,y)||f2(x,y)||f3(x,y)||f4(x,y))
        {
            if(a[x][y]==1){
                update();
                int ret = QMessageBox::question(this, "黑棋获胜", "是否再来一局");
                switch(ret){
                     case QMessageBox::Yes:
                     memset(a, 0, 20 * 20 * sizeof(int));
                         break;
                     case QMessageBox::No:
                         this->close();
                         break;

                }
            }
            if(a[x][y]==2){
              update();
              int ret = QMessageBox::question(this, "白棋获胜", "是否再来一局");
              switch(ret){
                 case QMessageBox::Yes:
                 memset(a, 0, 20 * 20 * sizeof(int));
                     break;
                 case QMessageBox::No:
                     this->close();
                     break;}
        }
    }
    update();
}}
bool lzq::f1(int x, int y)
{
    int i;
    for (i = 0; i < 6; i++)
    {
        if(y-i>=0&&y+5-i<=21&&a[x][y - i] == a[x][y + 1 - i] &&a[x][y - i] == a[x][y + 2 - i] && a[x][y - i] == a[x][y + 3 - i] &&a[x][y - i] == a[x][y + 4 - i]&&a[x][y-i]==a[x][y+5-i])
      return true;

    }
    return false;
}

bool lzq::f2(int x, int y)
{
    int i;
    for (i = 0; i < 6; i++)
    {
        if(x-i>=0&&x+5-i<=21&& a[x - i][y] == a[x + 1 - i][y] &&a[x - i][y] == a[x + 2 - i][y] &&a[x - i][y] == a[x + 3 - i][y] &&a[x - i][y] == a[x + 4 - i][y]&&a[x-i][y]==a[x+5-i][y])
          return true;

    }
    return false;
}

bool lzq::f3(int x, int y)
{
    int i;
    for (i = 0; i < 6; i++)
    {
        if(y-i>=0&&y+5-i<=21&&x-i>=0&&x+5-i<=21&&
           a[x - i][y - i] == a[x + 1 - i][y + 1 - i] &&a[x - i][y - i] == a[x + 2 - i][y + 2 - i] &&
           a[x - i][y - i] == a[x + 3 - i][y + 3 - i] &&a[x - i][y - i] == a[x + 4 - i][y + 4 - i] &&a[x-i][y-i]==a[x+5-i][y+5-i])
          return true;

    }
    return false;
}

bool lzq::f4(int x, int y)
{
    int i;
    for (i = 0; i < 6; i++)
    {
        if(y-i>=0&&y+5-i<=21&&x-i>=0&&x+5-i<=21&&
           a[x + i][y - i] == a[x - 1 + i][y + 1 - i] &&
           a[x + i][y - i] == a[x - 2 + i][y + 2 - i] &&
           a[x + i][y - i] == a[x - 3 + i][y + 3 - i] &&
           a[x + i][y - i] == a[x - 4 + i][y + 4 - i] &&
           a[x + i][y - i] == a[x - 5 + i][y + 5 - i])
           return true;

    }
    return false;
}


