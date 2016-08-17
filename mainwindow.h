#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QGlyphRun>
#include <QList>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void finished(QNetworkReply*);

private:
    QNetworkAccessManager m_qnam;
    QList<QGlyphRun> m_runs;
};

#endif // MAINWINDOW_H
