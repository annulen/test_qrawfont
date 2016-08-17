#include "mainwindow.h"

#include <QPainter>
#include <QPen>
#include <QRawFont>
#include <QTextLayout>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    connect(&m_qnam, SIGNAL(finished(QNetworkReply*)), this, SLOT(finished(QNetworkReply*)));

    m_qnam.get(
        QNetworkRequest(
            QUrl("http://code.ionicframework.com/ionicons/2.0.1/fonts/ionicons.ttf?v=2.0.1")
        )
    );
}

void MainWindow::paintEvent(QPaintEvent *)
{
    qDebug() << Q_FUNC_INFO << m_runs.size();

    if (m_runs.isEmpty())
        return;

    QPainter p(this);
    p.setPen(Qt::black);
    p.drawGlyphRun(QPointF(25, 25), m_runs.first());
}

void MainWindow::finished(QNetworkReply *reply)
{
    qDebug() <<Q_FUNC_INFO << reply << reply->errorString();
    QByteArray fontData = reply->readAll();
    QRawFont rawFont(fontData, /*pixelSize = */30, QFont::PreferDefaultHinting);
    qDebug() << Q_FUNC_INFO << rawFont.isValid() << rawFont.familyName() << rawFont.style();

    QTextLayout layout(QChar(0xf10e));
    layout.setRawFont(rawFont);
    layout.beginLayout();
    QTextLine line = layout.createLine();
    line.setLineWidth(INT_MAX/256);
    layout.endLayout();

    m_runs = line.glyphRuns();
    update();
}
