#ifndef PATHWAYWIDGET_H
#define PATHWAYWIDGET_H

#include <QWidget>
#include <QLabel>
#include <vector>
#include "MazeCard.h"

namespace Ui {
class PathwayWidget;
}

class PathwayWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PathwayWidget(const labyrinth::model::MazeCard &card, QWidget *parent = 0);

    labyrinth::model::MazeCard getPathway() const { return pathway; }

    ~PathwayWidget();

signals:
    void clicked();

protected:
    void mouseMoveEvent(QMouseEvent *event);

private:
    Ui::PathwayWidget *ui;
    labyrinth::model::MazeCard pathway;
    std::vector<QLabel *> labels_;
};

#endif // PATHWAYWIDGET_H
