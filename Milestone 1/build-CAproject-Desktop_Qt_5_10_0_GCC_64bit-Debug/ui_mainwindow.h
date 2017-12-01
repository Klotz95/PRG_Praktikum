/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *mainLayout;
    QVBoxLayout *gameLayout;
    QVBoxLayout *setLayout;
    QHBoxLayout *controlLayout;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *clearButton;
    QLabel *label;
    QSpinBox *cellsControl;
    QLabel *label3;
    QComboBox *modeControl;
    QLabel *label4;
    QComboBox *cellsMode;
    QLabel *label2;
    QSpinBox *iterInterval;
    QLabel *label5;
    QSpinBox *lifeInterval;
    QHBoxLayout *fileLayout;
    QPushButton *loadButton;
    QPushButton *saveButton;
    QPushButton *colorButton;
    QPushButton *randomButton;
    QPushButton *GoButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(700, 500);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        mainLayout = new QHBoxLayout();
        mainLayout->setSpacing(6);
        mainLayout->setObjectName(QStringLiteral("mainLayout"));
        gameLayout = new QVBoxLayout();
        gameLayout->setSpacing(6);
        gameLayout->setObjectName(QStringLiteral("gameLayout"));

        mainLayout->addLayout(gameLayout);

        setLayout = new QVBoxLayout();
        setLayout->setSpacing(6);
        setLayout->setObjectName(QStringLiteral("setLayout"));
        controlLayout = new QHBoxLayout();
        controlLayout->setSpacing(6);
        controlLayout->setObjectName(QStringLiteral("controlLayout"));
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));

        controlLayout->addWidget(startButton);

        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));

        controlLayout->addWidget(stopButton);

        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        controlLayout->addWidget(clearButton);


        setLayout->addLayout(controlLayout);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        setLayout->addWidget(label);

        cellsControl = new QSpinBox(centralWidget);
        cellsControl->setObjectName(QStringLiteral("cellsControl"));
        cellsControl->setMinimum(10);
        cellsControl->setMaximum(400);
        cellsControl->setValue(50);

        setLayout->addWidget(cellsControl);

        label3 = new QLabel(centralWidget);
        label3->setObjectName(QStringLiteral("label3"));

        setLayout->addWidget(label3);

        modeControl = new QComboBox(centralWidget);
        modeControl->setObjectName(QStringLiteral("modeControl"));

        setLayout->addWidget(modeControl);

        label4 = new QLabel(centralWidget);
        label4->setObjectName(QStringLiteral("label4"));

        setLayout->addWidget(label4);

        cellsMode = new QComboBox(centralWidget);
        cellsMode->setObjectName(QStringLiteral("cellsMode"));

        setLayout->addWidget(cellsMode);

        label2 = new QLabel(centralWidget);
        label2->setObjectName(QStringLiteral("label2"));

        setLayout->addWidget(label2);

        iterInterval = new QSpinBox(centralWidget);
        iterInterval->setObjectName(QStringLiteral("iterInterval"));
        iterInterval->setMinimum(50);
        iterInterval->setMaximum(100000);
        iterInterval->setSingleStep(10);
        iterInterval->setValue(100);

        setLayout->addWidget(iterInterval);

        label5 = new QLabel(centralWidget);
        label5->setObjectName(QStringLiteral("label5"));

        setLayout->addWidget(label5);

        lifeInterval = new QSpinBox(centralWidget);
        lifeInterval->setObjectName(QStringLiteral("lifeInterval"));
        lifeInterval->setMinimum(1);
        lifeInterval->setMaximum(1000);
        lifeInterval->setValue(50);

        setLayout->addWidget(lifeInterval);

        fileLayout = new QHBoxLayout();
        fileLayout->setSpacing(6);
        fileLayout->setObjectName(QStringLiteral("fileLayout"));
        loadButton = new QPushButton(centralWidget);
        loadButton->setObjectName(QStringLiteral("loadButton"));

        fileLayout->addWidget(loadButton);

        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        fileLayout->addWidget(saveButton);


        setLayout->addLayout(fileLayout);

        colorButton = new QPushButton(centralWidget);
        colorButton->setObjectName(QStringLiteral("colorButton"));

        setLayout->addWidget(colorButton);

        randomButton = new QPushButton(centralWidget);
        randomButton->setObjectName(QStringLiteral("randomButton"));

        setLayout->addWidget(randomButton);

        GoButton = new QPushButton(centralWidget);
        GoButton->setObjectName(QStringLiteral("GoButton"));

        setLayout->addWidget(GoButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        setLayout->addItem(verticalSpacer);


        mainLayout->addLayout(setLayout);


        horizontalLayout->addLayout(mainLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Cellular Automata", nullptr));
        startButton->setText(QApplication::translate("MainWindow", "Start", nullptr));
        stopButton->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        clearButton->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        label->setText(QApplication::translate("MainWindow", "Universe Size", nullptr));
        cellsControl->setSuffix(QApplication::translate("MainWindow", " cells", nullptr));
        label3->setText(QApplication::translate("MainWindow", "Universe Mode", nullptr));
        label4->setText(QApplication::translate("MainWindow", "Cells Mode", nullptr));
        label2->setText(QApplication::translate("MainWindow", "Generation interval (in msec)", nullptr));
        iterInterval->setSuffix(QApplication::translate("MainWindow", " ms", nullptr));
        label5->setText(QApplication::translate("MainWindow", "Life interval (in step)", nullptr));
        lifeInterval->setSuffix(QApplication::translate("MainWindow", " step", nullptr));
        loadButton->setText(QApplication::translate("MainWindow", "Load", nullptr));
        saveButton->setText(QApplication::translate("MainWindow", "Save", nullptr));
        colorButton->setText(QApplication::translate("MainWindow", "Select color for cells", nullptr));
        randomButton->setText(QApplication::translate("MainWindow", "Random Color", nullptr));
        GoButton->setText(QApplication::translate("MainWindow", "GO!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
