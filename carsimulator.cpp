#include "carsimulator.h"
#include "analogspeedometerwidget.h"
#include <QTimer>
#include <cstdlib>
#include <QDebug>

// Construtor da classe CarSimulator
CarSimulator::CarSimulator(QWidget *parent) : QWidget(parent), currentSpeed(0), speedometerWidget(nullptr) {
    // Configurar o temporizador para simular a aceleração do carro
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &CarSimulator::accelerate);
    timer->start(1000);  // Inicia o temporizador para acelerar a cada 1000 ms (1 segundo)
}

// Função para configurar o widget do velocímetro analógico
void CarSimulator::setSpeedometerWidget(AnalogSpeedometerWidget *speedometerWidget) {
    this->speedometerWidget = speedometerWidget;
}

// Slot que simula a aceleração do carro
void CarSimulator::accelerate() {
    // Verifica se a velocidade já atingiu o valor máximo (240)
    if (currentSpeed >= 240) {
        qDebug() << "Velocidade máxima atingida: " << currentSpeed;
            return;  // Sai da função se a velocidade máxima foi atingida
    }

    // Define um limite máximo para a aceleração
    int maxAcceleration = 10;

    // Aumenta a velocidade de forma aleatória entre 0 e 10
    int randomAcceleration = std::rand() % (maxAcceleration + 1);
    currentSpeed += randomAcceleration;

    // Garante que a velocidade não ultrapasse 240
    if (currentSpeed > 240) {
        currentSpeed = 240;
    }

    // Emite o sinal de que a velocidade foi alterada
    emit speedChanged(currentSpeed);

    // Atualiza o widget do velocímetro
    if (speedometerWidget) {
        speedometerWidget->setSpeed(currentSpeed);
        speedometerWidget->update();  // Força a atualização do widget
    }

    // Mostra a velocidade no terminal
    qDebug() << "Velocidade atual: " << currentSpeed;

    // Verifica se a velocidade atingiu o valor máximo após a aceleração
    if (currentSpeed >= 240) {
        qDebug() << "Velocidade máxima atingida: " << currentSpeed;

    }
}
