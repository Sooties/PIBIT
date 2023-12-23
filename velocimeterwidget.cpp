// velocimeterwidget.cpp

#include "velocimeterwidget.h"
#include <QVBoxLayout>

VelocimeterWidget::VelocimeterWidget(QWidget *parent) : QWidget(parent), carSimulator(nullptr) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Label para exibir a velocidade
    speedLabel = new QLabel("0 km/h", this);
    speedLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(speedLabel);

    setLayout(layout);
}

void VelocimeterWidget::setCarSimulator(CarSimulator *carSimulator) {
    this->carSimulator = carSimulator;
    connect(carSimulator, &CarSimulator::speedChanged, this, &VelocimeterWidget::updateSpeed);
}

void VelocimeterWidget::updateSpeed(int newSpeed) {
    speedLabel->setText(QString("%1 km/h").arg(newSpeed));
}
