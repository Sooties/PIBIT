#ifndef CARSIMULATOR_H
#define CARSIMULATOR_H

#include <QWidget>

class AnalogSpeedometerWidget;  // Declaração antecipada da classe AnalogSpeedometerWidget

class CarSimulator : public QWidget {
    Q_OBJECT  // Macro que habilita funcionalidades relacionadas a meta-objetos (sinais e slots)

public:
    CarSimulator(QWidget *parent = nullptr);  // Construtor da classe CarSimulator

    void setSpeedometerWidget(AnalogSpeedometerWidget *speedometerWidget);  // Função para configurar o widget do velocímetro analógico

signals:
    void speedChanged(int newSpeed);  // Sinal emitido quando a velocidade é alterada

private slots:
    void accelerate();  // Slot que simula a aceleração do carro

private:
    int currentSpeed;  // Variável que armazena a velocidade atual
    AnalogSpeedometerWidget *speedometerWidget;  // Ponteiro para o widget do velocímetro analógico associado a este simulador
};

#endif // CARSIMULATOR_H
