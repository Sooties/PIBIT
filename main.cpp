#include "carsimulator.h"
#include "analogspeedometerwidget.h"
#include <QVBoxLayout>
#include <QApplication>
#include <QWidget>
#include <QScreen>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Criar o simulador de carro
    CarSimulator carSimulator;

    // Criar o widget do velocímetro analógico
    AnalogSpeedometerWidget analogSpeedometerWidget;

    // Configurar o widget do velocímetro analógico no simulador de carro
    carSimulator.setSpeedometerWidget(&analogSpeedometerWidget);

    // Criar o layout vertical
    QVBoxLayout layout;
    layout.addWidget(&carSimulator);
    layout.addWidget(&analogSpeedometerWidget); // Adicione o widget do velocímetro

    // Criar o widget principal
    QWidget window;
    window.setLayout(&layout);

    // Definir o tamanho fixo da janela principal
    window.setFixedSize(450, 400);

    // Ajustar diretamente o tamanho do widget do velocímetro
    analogSpeedometerWidget.setFixedSize(400, 400);

    // Centralizar a janela na tela usando QScreen
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int x = (screenGeometry.width() - window.width()) / 2;
    int y = (screenGeometry.height() - window.height()) / 2;
    window.move(x, y);

    window.show();

    return a.exec();
}
