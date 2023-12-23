#ifndef ANALOGSPEEDOMETERWIDGET_H
#define ANALOGSPEEDOMETERWIDGET_H

#include <QWidget>
#include <QPainterPath>

class AnalogSpeedometerWidget : public QWidget {
    Q_OBJECT

public:
    // Construtor da classe AnalogSpeedometerWidget
    AnalogSpeedometerWidget(QWidget *parent = nullptr);

    // Função pública para definir a velocidade a ser exibida no velocímetro
    void setSpeed(int speed);

protected:
    // Função protegida chamada sempre que for necessário redesenhar o widget
    void paintEvent(QPaintEvent *event) override;

private:
    int currentSpeed;  // Variável para armazenar a velocidade atual
    void drawSpeedometer(QPainter *painter);  // Função privada para desenhar o corpo do velocímetro
    void drawSpeedIndicator(QPainter *painter);  // Função privada para desenhar o indicador de velocidade
};

#endif // ANALOGSPEEDOMETERWIDGET_H
