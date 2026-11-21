#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("My Qt App");

    auto *label = new QLabel("Hello from Qt 6!");
    auto *button = new QPushButton("Click me");
    //layout setup
    auto *layout = new QVBoxLayout(&window);
    layout->addWidget(label);
    layout->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, [label]() {
        label->setText("Button clicked!");
    });

    window.show();
    return app.exec();
}
