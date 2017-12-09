#include "circular-overlay.h"

#include <QPaintEvent>
#include <QPainter>
#include <math.h>

using namespace QtInputTools;

CircularOverlay::CircularOverlay(QWidget *parent)
    : Overlay(parent) {}

void CircularOverlay::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QPen pen(QColor("gray"));
    pen.setWidthF(1.5);
    painter.setPen(pen);
    painter.drawEllipse(QRect(2, 2, width()-4, height()-4));

    double angle = atan2(mOffset.x(), -mOffset.y());
    painter.drawArc(QRect(6, 6, width()-12, height()-12), (-20.- angle*180./M_PI)*16., 40.*16.);
    painter.drawArc(QRect(6, 6, width()-12, height()-12), (160.- angle*180./M_PI)*16., 40.*16.);
    event->accept();
}

