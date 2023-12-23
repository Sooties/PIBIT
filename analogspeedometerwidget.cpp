#include "analogspeedometerwidget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <cmath>

// Construtor da classe AnalogSpeedometerWidget
AnalogSpeedometerWidget::AnalogSpeedometerWidget(QWidget *parent) : QWidget(parent), currentSpeed(0) {}

// Função pública para definir a velocidade a ser exibida no velocímetro
void AnalogSpeedometerWidget::setSpeed(int speed) {
    // Atualiza a velocidade e solicita uma atualização do widget
    if (speed != currentSpeed) {
        currentSpeed = speed;
        update();
    }
}

// Função protegida chamada sempre que for necessário redesenhar o widget
void AnalogSpeedometerWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int side = qMin(width(), height());
    painter.setViewport((width() - side) / 2, (height() - side) / 2, side, side);
    painter.setWindow(-50, -50, 100, 100);

    // Desenha o corpo do velocímetro
    drawSpeedometer(&painter);
    // Desenha o indicador de velocidade
    drawSpeedIndicator(&painter);
}

// Função privada para desenhar o corpo do velocímetro
void AnalogSpeedometerWidget::drawSpeedometer(QPainter *painter) {
    // Configurações do velocímetro
    painter->save();
    painter->setPen(QPen(Qt::white, 0.3, Qt::SolidLine)); // Reduz a espessura da linha
    painter->setBrush(QBrush(Qt::black, Qt::SolidPattern));

    // Desenha a meia lua do velocímetro
    QPainterPath path;
    path.moveTo(-48, 0);
    path.arcTo(-50, -50, 100, 100, 0, 180);
    path.lineTo(48, 0);  // Conecta até o ponto inicial para fechar a forma

    painter->drawPath(path);

    // Desenha a escala do velocímetro
    QFont smallFont = painter->font();
    smallFont.setPointSizeF(4.0);  // Define o tamanho da fonte menor

    for (int i = 0; i <= 240; i += 10) {
        painter->save();
        painter->rotate((i-125) * 0.7); // Mapeia de 0 a 240 para 0 a 180 graus

        if (i % 20 == 0) {
            painter->drawLine(0, -42, 0, -38); // Ajusta o comprimento da linha
            QString numberString = QString::number(i);
            painter->setFont(smallFont);
            QRectF boundingRect = painter->fontMetrics().boundingRect(numberString);
            painter->drawText(QPointF(-boundingRect.width() / 2, -45), numberString); // Ajusta a posição dos números
        } else {
            painter->drawLine(0, -42, 0, -40); // Ajusta o comprimento da linha
        }
        painter->restore();
    }

    painter->restore();
}

// Função privada para desenhar o indicador de velocidade
void AnalogSpeedometerWidget::drawSpeedIndicator(QPainter *painter) {
    // Configurações do indicador
    painter->save();
    painter->setPen(QPen(Qt::red, 1, Qt::SolidLine));
    painter->setBrush(QBrush(Qt::red, Qt::SolidPattern));

    // Ajuste para iniciar o ponteiro no zero grau
    painter->rotate((currentSpeed / 240.0) * 180 + 270); // Mapeia de 0 a 240 para 0 a 180 graus

    QPainterPath path;
    path.moveTo(0, 0);
    path.lineTo(0.5, -48);
    path.lineTo(-0.5, -48);
    path.lineTo(0, 0);
    painter->drawPath(path);

    painter->restore();
}
