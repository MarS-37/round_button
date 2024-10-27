#ifndef DEMODIALOG_H
#define DEMODIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>


class ModalDialog : public QDialog
{
    Q_OBJECT

public:
    ModalDialog(QWidget *parent = nullptr);
    ~ModalDialog();

signals:
    void labelButtonClicked(const QString &text);
    void lineEditButtonClicked(const QString &text);

private slots:
    void onLabelButtonClicked();
    void onLineEditButtonClicked();

private:
    QLineEdit *edit;
    QPushButton *labelButton;
    QPushButton *lineEditButton;
    QPushButton *closeButton;
};


#endif // DEMODIALOG_H
