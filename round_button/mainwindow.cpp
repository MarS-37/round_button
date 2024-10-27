#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), dialog(new ModalDialog(this)), isButtonPressed(false)
{
    QWidget *centralWidget = new QWidget(this);

    // основной вертикальный лейаут
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // горизонтальный лейаут для кнопки в правом верхнем углу
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    // кнопка "OD"
    button = new QPushButton("OD", this);

    // устанавливаем фиксированный размер кнопки
    button->setFixedSize(50, 50);
    button->setStyleSheet(
        "QPushButton {"
        "  border-radius: 25px;"        // радиус равен половине ширины/высоты для круглой формы
        "  border: 2px solid #555;"
        "  background-color: #ddd;"     // начальный цвет кнопки
        "  font-size: 16px;"
        "}"
        );

    // добавляем кнопку в правый верхний угол
    buttonLayout->addStretch(); // добавляем растяжение перед кнопкой, чтобы выровнять её вправо
    buttonLayout->addWidget(button, 0, Qt::AlignRight);
    mainLayout->addLayout(buttonLayout); // добавляем горизонтальный лейаут с кнопкой в основной лейаут

    // остальные элементы интерфейса
    label = new QLabel("Label", this);
    mainLayout->addWidget(label);

    lineEdit = new QLineEdit(this);
    mainLayout->addWidget(lineEdit);

    connect(button, &QPushButton::clicked, this, &MainWindow::changeButtonColor);   // сигнал изменения цвета
    connect(button, &QPushButton::clicked, this, &MainWindow::openDialog);          // сигнал открытия диалога

    setCentralWidget(centralWidget);
    setWindowTitle("Main Window");

    // связываем сигналы из диалога с слотами для обновления компонентов
    connect(dialog, &ModalDialog::labelButtonClicked, this, &MainWindow::setLabelText);
    connect(dialog, &ModalDialog::lineEditButtonClicked, this, &MainWindow::setLineEditText);
}

MainWindow::~MainWindow() {}

void MainWindow::openDialog()
{
    // открываем модальное окно
    dialog->exec();
}

void MainWindow::setLabelText(const QString &text)
{
    label->setText(text);
}

void MainWindow::setLineEditText(const QString &text)
{
    lineEdit->setText(text);
}

void MainWindow::changeButtonColor()
{
    if (!isButtonPressed) {
        button->setStyleSheet(
            "QPushButton {"
            "  border-radius: 25px;"
            "  border: 2px solid #555;"
            "  background-color: orange;"  // меняем цвет на оранжевый
            "  font-size: 16px;"
            "}"
            );
        isButtonPressed = true;  // обновляем состояние флага
    }
}
