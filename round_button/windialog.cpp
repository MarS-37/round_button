#include "windialog.h"
#include <QVBoxLayout>


ModalDialog::ModalDialog(QWidget *parent) : QDialog(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    edit = new QLineEdit(this);
    layout->addWidget(edit);

    // кнопка для обновления label на главном окне
    labelButton = new QPushButton("Label", this);

    connect(labelButton, &QPushButton::clicked, this, &ModalDialog::onLabelButtonClicked);
    layout->addWidget(labelButton);

    // кнопка для обновления lineEdit на главном окне
    lineEditButton = new QPushButton("LineEdit", this);

    connect(lineEditButton, &QPushButton::clicked, this, &ModalDialog::onLineEditButtonClicked);
    layout->addWidget(lineEditButton);

    // кнопка для закрытия окна
    closeButton = new QPushButton("Close", this);

    connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);
    layout->addWidget(closeButton);

    setLayout(layout);
    setWindowTitle("Demo Dialog");
}

ModalDialog::~ModalDialog() {}

void ModalDialog::onLabelButtonClicked()
{
    // передаем текст из QLineEdit в слот
    emit labelButtonClicked(edit->text());
}

void ModalDialog::onLineEditButtonClicked()
{
    // передаем текст из QLineEdit в слот
    emit lineEditButtonClicked(edit->text());
}
