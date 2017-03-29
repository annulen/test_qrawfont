#include "mainwindow.h"

#include <QPainter>
#include <QPen>
#include <QRawFont>
#include <QTextLayout>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    QFile f("Ubuntu-R.ttf");
    f.open(QIODevice::ReadOnly);
    QByteArray fontData = f.readAll();
    QRawFont rawFont(fontData, /*pixelSize = */84, QFont::PreferDefaultHinting);

    QTextLayout layout(QChar('H'));
    layout.setRawFont(rawFont);
    layout.beginLayout();
    QTextLine line = layout.createLine();
    line.setLineWidth(INT_MAX/256);
    layout.endLayout();

    m_runs = line.glyphRuns();
    update();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    if (m_runs.isEmpty())
        return;

    QPainter p(this);
    p.setPen(Qt::black);
    p.drawGlyphRun(QPointF(25, 25), m_runs.first());
}
