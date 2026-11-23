#include <QApplication>
#include <QLabel>
#include <QObject>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

/* Pass signals from buttons into slots. */
class Counter : public QObject {
Q_OBJECT // enable Meta-Object system
    public : explicit Counter(QObject *parent = nullptr)
    : QObject(parent) {}

  int value() const { return m_value; }

public slots:
  void increment() { setValue(m_value + 1); }
  void decrement() { setValue(m_value - 1); }
  void reset() { setValue(0); }

signals:
  void valueChanged(int newValue);

private:
  void setValue(int newValue) {
    if (m_value == newValue)
      return;
    m_value = newValue;
    emit valueChanged(m_value);
  }
  int m_value = 0;
};

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  QWidget window;
  window.setWindowTitle("Signals & Slots");

  auto *label = new QLabel("Counter: 0");

  auto *incrementButton = new QPushButton("Increment");
  auto *decrementButton = new QPushButton("Decrement");
  auto *resetButton = new QPushButton("Reset");

  auto *layout = new QVBoxLayout(&window);

  layout->addWidget(label);
  layout->addWidget(incrementButton);
  layout->addWidget(decrementButton);
  layout->addWidget(resetButton);

  // Create custom QObject
  Counter counter(&window);

  // Connect custom signal to lambda
  QObject::connect(&counter, &Counter::valueChanged, label, [label](int value) {
    label->setText(QString("Counter: %1").arg(value));
  });

  // Connect buttons to slots
  QObject::connect(incrementButton, &QPushButton::clicked, &counter,
                   &Counter::increment);
  QObject::connect(decrementButton, &QPushButton::clicked, &counter,
                   &Counter::decrement);
  QObject::connect(resetButton, &QPushButton::clicked, &counter,
                   &Counter::reset);

  window.show();
  return app.exec();
}

#include "main.moc"
