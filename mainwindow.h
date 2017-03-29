#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGlyphRun>
#include <QList>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *e);

private:
    QList<QGlyphRun> m_runs;
};

#endif // MAINWINDOW_H
