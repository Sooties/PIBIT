// velocimeterwidget.h

#ifndef VELOCIMETERWIDGET_H
#define VELOCIMETERWIDGET_H

#include <QWidget>
#include <QLabel>
#include "carsimulator.h"

class VelocimeterWidget : public QWidget {
    Q_OBJECT

public:
    VelocimeterWidget(QWidget *parent = nullptr);
    void setCarSimulator(CarSimulator *carSimulator);

public slots:
    void updateSpeed(int newSpeed);

private:
    QLabel *speedLabel;
    CarSimulator *carSimulator;
};

#endif // VELOCIMETERWIDGET_H
