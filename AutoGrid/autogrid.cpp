﻿#include "autogrid.h"

#include <QPainter>
#include <QPen>

AutoGrid::AutoGrid(QWidget *parent) : QWidget(parent)
{
    DrawBK();
    Initial();
}

void AutoGrid::Initial()
{
    m_atomGridHeight = 20;
    m_atomGridHeightMin = 20;
    m_atomGridHeightMax = 30;
}


void AutoGrid::DrawBK()
{
    //默认铺满窗口并设置背景色为黑色
    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Window,QColor("#000000"));
    this->setPalette(palette);
}


void AutoGrid::DrawGrid()
{
    QPainter painter(this);
    QPen     pen;
    pen.setColor(QColor("#FF0000"));
    painter.setPen(pen);

    int xstart = COORDINATE_X1;
    int ystart = COORDINATE_Y1;
    int xend =  m_CurrentWidth - COORDINATE_X2;
    int yend = COORDINATE_Y1;

    for(int i=0;i<hgridNum+1 ;++i)
    {
        if( i == hgridNum/2 || i == 0 || i == hgridNum)
        {
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);
        }
        else
        {
            pen.setStyle(Qt::DashLine);
            painter.setPen(pen);
        }
        painter.drawLine(xstart,ystart+i*m_atomGridHeight,
                         xend,yend+i*m_atomGridHeight);
    }
}


void AutoGrid::paintEvent(QPaintEvent* event)
{
    calGridHeight();
    calGridWidth();
    DrawGrid();
}

void AutoGrid::DrawBorder()
{
    QPainter painter(this);
    QPen     pen;
    pen.setColor(QColor("#FF0000"));
    painter.setPen(pen);


}

void AutoGrid::resizeEvent(QResizeEvent *event)
{
    m_CurrentHeight = this->height();
    m_CurrentWidth = this->width();

    m_GridHeight = m_CurrentHeight - COORDINATE_Y1 - COORDINATE_Y2;
    m_GridWidth = m_CurrentWidth - COORDINATE_X1 - COORDINATE_X2;
}

void AutoGrid::calGridHeight()
{
    hgridNum = 0;
    int height = m_GridHeight;
    while( height - 2 * m_atomGridHeightMin > 2 * m_atomGridHeightMin)
    {
        hgridNum += 2;
        height -= 2 * m_atomGridHeightMin;
    }
    m_atomGridHeight = m_GridHeight / hgridNum;

}


void AutoGrid::calGridWidth()
{

}

















